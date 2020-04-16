// // #include <math.h>
// // #include <Windows.h>

// // TODO frame_time int for better performance

// namespace XGK {

//   void idle_function (float) {};



//   // pack ?
//   struct Transition {

//     uint8_t active;
//     float time_gone;
//     float interpolation;
//     float duration;

//     void (* process_callback) (float);
//     void (* end_callback) (float);
//   };



//   // pack ?
//   struct Time {

//     ~Time () {

//       delete[] stack;
//     };

//     float last_frame_time;
//     float frame_time;
//     uint32_t stack_length;
//     uint32_t stack_counter;

//     Transition** stack;
//   };



//   namespace TIME {

//     // make cross-platform
//     float getWallTime (void) {

//       LARGE_INTEGER time;
//       LARGE_INTEGER freq;

//       if (!QueryPerformanceFrequency(&freq)) {

//         return 0;
//       }

//       if (!QueryPerformanceCounter(&time)) {

//         return 0;
//       }

//       return (float) time.QuadPart / freq.QuadPart;
//     };



//     inline void init (Time* time, const uint32_t stack_max_size) {

//       time->last_frame_time = getWallTime() * 1000.0f;
//       time->frame_time = 0.0f;
//       time->stack_length = 0;
//       time->stack_counter = 0;

//       time->stack_VECTOR.resize(stack_max_size);
//       time->stack_RANGE = time->stack_VECTOR.data();
//     };



//     // only cancels within stack execution, not for using manually
//     inline void cancelTransition (Time* time, Transition* transition) {

//       if (transition->active) {

//         transition->active = 0;

//         time->stack_RANGE[time->stack_counter--] = time->stack_RANGE[--time->stack_length];
//         time->stack_RANGE[time->stack_length] = nullptr;
//       }
//     };



//     inline void setTransition (
//       Time* time,
//       Transition* transition,
//       const float duration,
//       void (* process_callback) (float),
//       void (* end_callback) (float)
//     ) {

//       cancelTransition(time, transition);

//       transition->interpolation = 0.0f;
//       transition->duration = duration;
//       transition->process_callback = process_callback;
//       transition->end_callback = end_callback;
//       transition->time_gone = 0.0f;
//       transition->active = 1;

//       time->stack_RANGE[time->stack_length++] = transition;
//     };



//     inline void setTransition2 (

//       Time* time,
//       Transition* transition,
//       const float duration,
//       void (* process_callback) (float)
//     ) {

//       cancelTransition(time, transition);

//       transition->interpolation = 0.0f;
//       transition->duration = duration;
//       transition->process_callback = process_callback;
//       transition->end_callback = idle_function;
//       transition->time_gone = 0.0f;
//       transition->active = 1;

//       time->stack_RANGE[time->stack_length++] = transition;
//     };



//     // inline void setTransition3 (

//     //   Time* time,
//     //   Transition* transition,
//     //   void (* process_callback) (float)
//     // ) {

//     //   cancelTransition(time, transition);

//     //   transition->interpolation = 0.0f;
//     //   transition->duration = duration;
//     //   transition->process_callback = process_callback;
//     //   transition->end_callback = idle_function;
//     //   transition->time_gone = 0.0f;
//     //   transition->active = 1;

//     //   time->stack_RANGE[time->stack_length++] = transition;
//     // };



//     inline void updateTransition (Time* time, Transition* transition) {

//       transition->interpolation = transition->time_gone / transition->duration;

//       if (floor(transition->interpolation)) {

//         cancelTransition(time, transition);

//         transition->end_callback(transition->interpolation);
//       }
//       else {

//         transition->time_gone += time->frame_time;

//         // std::cout << transition->time_gone << std::endl;

//         transition->process_callback(transition->interpolation);
//       }
//     };



//     inline void updateTransitions (Time* time) {

//       for (time->stack_counter = 0; time->stack_RANGE[time->stack_counter]; time->stack_counter++) {

//         updateTransition(time, time->stack_RANGE[time->stack_counter]);
//       }
//     };



//     inline void getFrameTime (Time* time) {

//       float program_time = getWallTime() * 1000.0f;

//       time->frame_time = program_time - time->last_frame_time;
//       time->last_frame_time = program_time;
//     };
//   };
// };
