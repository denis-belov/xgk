// #include <math.h>
// #include <Windows.h>

// TODO frame_time int for better performance



#define TIME_GONE_OFFSET 0
#define INTERPOLATION_OFFSET 4
#define DURATION_OFFSET 8
#define ACTIVE_OFFSET 12
#define PROCESS_CALLBACK_OFFSET 20
#define END_CALLBACK_OFFSET 28

#define LAST_FRAME_TIME_OFFSET 0
#define FRAME_TIME_OFFSET 4
#define STACK_LENGTH_OFFSET 8
#define STACK_COUNTER_OFFSET 12
#define STACK_OFFSET 20



#include <stdint.h>



void idle_function (float) {};



// pack
struct Transition {

  float time_gone;
  float interpolation;
  float duration;
  uint8_t active;

  void (* process_callback) (float);
  void (* end_callback) (float);
};



// pack
struct Time {

  ~Time () {

    delete[] stack;
  };

  float last_frame_time;
  float frame_time;
  uint32_t stack_length;
  uint32_t stack_counter;

  Transition** stack;
};



namespace XGK {

  namespace TIME {

    // make cross-platform
    float getWallTime (void) {

      LARGE_INTEGER time;
      LARGE_INTEGER freq;

      if (!QueryPerformanceFrequency(&freq)) {

        return 0;
      }

      if (!QueryPerformanceCounter(&time)) {

        return 0;
      }

      return (float) time.QuadPart / freq.QuadPart;
    };



    void init (void* time_addr, const uint32_t stack_max_size) {

      time_addr->last_frame_time = getWallTime() * 1000.0f;
      time_addr->frame_time = 0.0f;
      time_addr->stack_length = 0;
      time_addr->stack_counter = 0;

      time_addr->stack = new Transition*[stack_max_size];
    };



    // only cancels within stack execution, not for using manually
    void cancelTransition (void* time_addr, void* transition_addr) {

      if (transition->active) {

        transition->active = 0;

        *stack_addr[(*stack_counter_float_addr)--] = *stack_addr[--(*stack_length_uint32_addr)];
        *stack_addr[*stack_length_uint32_addr] = nullptr;
      }
    };



    void setTransition (
      Time* time,
      Transition* transition,
      const float duration,
      void (* process_callback) (float),
      void (* end_callback) (float)
    ) {

      cancelTransition(time, transition);

      transition->interpolation = 0.0f;
      transition->duration = duration;
      transition->process_callback = process_callback;
      transition->end_callback = end_callback;
      transition->time_gone = 0.0f;
      transition->active = 1;

      time->stack[time->stack_length++] = transition;
    };



    void setTransition2 (

      Time* time,
      Transition* transition,
      const float duration,
      void (* process_callback) (float)
    ) {

      cancelTransition(time, transition);

      transition->interpolation = 0.0f;
      transition->duration = duration;
      transition->process_callback = process_callback;
      transition->end_callback = idle_function;
      transition->time_gone = 0.0f;
      transition->active = 1;

      time->stack[time->stack_length++] = transition;
    };



    void updateTransition (Time* time, Transition* transition) {

      transition->interpolation = transition->time_gone / transition->duration;

      if (floor(transition->interpolation)) {

        cancelTransition(time, transition);

        transition->end_callback(transition->interpolation);
      }
      else {

        transition->time_gone += time->frame_time;

        transition->process_callback(transition->interpolation);
      }
    };



    void updateTransitions (Time* time) {

      for (time->stack_counter = 0; time->stack[time->stack_counter]; time->stack_counter++) {

        updateTransition(time, time->stack[time->stack_counter]);
      }
    };



    void getFrameTime (Time* time) {

      float program_time = getWallTime() * 1000.0f;

      time->frame_time = program_time - time->last_frame_time;
      time->last_frame_time = program_time;
    };
  };
};
