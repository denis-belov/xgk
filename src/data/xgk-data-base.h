// todo test wrappers existing on stack

namespace XGK {
  static const uint8_t CONST_FLOAT_SIZE = sizeof(float);
  static const uint8_t CONST_FLOAT_SIZE_4 = sizeof(float) * 4;
  static const uint8_t CONST_FLOAT_SIZE_16 = sizeof(float) * 16;



  static const uint8_t global_render_flag = 1;



  // alignment ?
  struct UniformStack {
    void** arr_data_arr[2]; // array of 2 pointers to arr[0] and arr[1] first elements
    std::vector<void*> arr[2];
    uint32_t index = 0;
  };

  namespace UNIFORM_STACK {
    static uint8_t index0 = 0;
    static uint8_t index1 = 1;

    void expand (UniformStack* stack) {
      stack->arr[0].push_back(nullptr);
      stack->arr[1].push_back(nullptr);

      stack->arr_data_arr[0] = stack->arr[0].data();
      stack->arr_data_arr[1] = stack->arr[1].data();
    };

    static inline void push (UniformStack* stack_ptr, void* uniform_attr_ptr) {
      stack_ptr->arr_data_arr[index0][stack_ptr->index++] = uniform_attr_ptr;
    };

    // maybe later this function need to be rewritten with asm if there will be different types of storages
    static inline void push (void* storage_ptr) {
      
    };
  };



  // alignment ?
  union Vec4 {
    float f32[4];


    #ifdef XGK_MACRO_DATA_WRAPPERS_SSE
      __m128 f128;
    #endif 
  };

  // alignment ?
  struct Vec4Wrapper {
    Vec4 () {};

    Vec4 data;

    std::vector<uint8_t*> storage_uniform_stack_arr; // array of uniform stacks of all entities that use this wrapper
    uint8_t** storage_uniform_stack_arr_data;

    std::vector<uint8_t> storage_uniform_attr_ptr_arr; // array of pointers to uniform attr object corresponding with this wrapper
    uint8_t* storage_uniform_attr_ptr_arr_data;

    std::vector<void*> storage_ptr_arr;
    void** storage_ptr_arr_data;
    uint8_t storage_count;
  };



  // alignment ?
  union Quat {
    float f32[4];


    #ifdef XGK_MACRO_DATA_WRAPPERS_SSE
      __m128 f128;
    #endif 
  };

  // alignment ?
  struct QuatWrapper {
    Quat () {};
  
    Quat data;
  };



  // alignment ?
  union Mat4 {
    float f32[16];

    #ifdef XGK_MACRO_DATA_WRAPPERS_SSE
      __m128 f128[4];
    #endif 

    #ifdef XGK_MACRO_DATA_WRAPPERS_AVX
      __m256 f256[2];
    #endif 
  };

  // alignment ?
  struct Mat4Wrapper {
    Mat4Wrapper () {};

    Mat4 data;
  };



  namespace DATA {
    static inline void updateStorages (Vec4Wrapper* wrapper_ptr) {
      uint32_t storage_count = wrapper_ptr->storage_count;

      for (uint32_t i = 0; i < storage_count; i++) {
        UNIFORM_STACK::push(wrapper_ptr->storage_uniform_stack_arr_data[i], wrapper_ptr->storage_uniform_attr_ptr_arr_data[i]);
      }
    };

    static inline void updateStorages2 (Vec4Wrapper* wrapper_ptr) {
      uint32_t storage_count = wrapper_ptr->storage_count;

      for (uint32_t i = 0; i < storage_count; i++) {
        UNIFORM_STACK::push(wrapper_ptr->storage_uniform_stack_arr_data[i], wrapper_ptr->storage_uniform_attr_ptr_arr_data[i]);
      }
    };

    static inline void updateStorages2_ (Vec4Wrapper* wrapper_ptr) {
      uint32_t storage_count = wrapper_ptr->storage_count;

      for (uint32_t i = 0; i < storage_count; i++) {
        UNIFORM_STACK::push(wrapper_ptr->storage_ptr_arr_data[i]);
      }
    };
  };
};
