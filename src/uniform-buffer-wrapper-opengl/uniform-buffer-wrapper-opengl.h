namespace XGK {

  // namespace OBJECT{

  //   inline void update (void* object_addr);
  // };



  namespace UNIFORM {

    // struct Unit;

    #ifdef __EMSCRIPTEN__
      pthread_mutex_t mutex;
    #else
      std::mutex mutex;
    #endif

    std::vector<uint32_t> storage_stack_next_free_element_VECTOR;
    uint32_t* storage_stack_next_free_element_RANGE = nullptr;
    // replace by size_t ?
    uint32_t storage_stack_next_free_element_SIZE = 0;

    std::vector<uint8_t> uniform_not_pushed_flag_VECTOR;
    uint8_t* uniform_not_pushed_flag_RANGE = nullptr;
    uint32_t uniform_not_pushed_flag_SIZE = 0;

    std::vector<Unit> unit_VECTOR;
    Unit* unit_RANGE = nullptr;

    uint32_t storage_stack_index0 = 0;
    uint32_t storage_stack_index1 = 1;



    #pragma pack(push, 8)
      struct Storage {

        std::vector<Unit*> stack_VECTORS[2];

        Unit** stack_RANGES[2];

        uint32_t stack_next_free_element_OFFSET;
      };
    #pragma pack(pop)



    // #pragma pack(push, 16)

    struct Wrapper {

      // alignas(8) std::vector<Unit*> unit_VECTOR;

      // alignas(8) Unit** unit_RANGE;

      // alignas(4) uint32_t unit_COUNT;

      alignas(4) uint32_t not_pushed_flag_OFFSET;

      alignas(8) void* data;

      Storage* storage;

      uint32_t location;

      uint32_t size; // count

      void (* update) (Unit* unit);
    };

    // #pragma pack(pop)



    // #pragma pack(push, 8)
    //   struct Unit {

    //     // Wrapper* wrapper;

    //     void* data;

    //     Storage* storage;

    //     uint32_t location;

    //     uint32_t size; // count

    //     void (* update) (Unit* unit);
    //   };
    // #pragma pack(pop)



    #define ARGS(type)\
      unit->location,\
      *((type*) unit->data)

    inline void _glUniform1f  (Unit* unit) { glUniform1f (ARGS(float)); };

    #undef ARGS

    #define ARGS(type)\
      unit->location,\
      ((type*) unit->data)[0],\
      ((type*) unit->data)[1],\
      ((type*) unit->data)[2],\
      ((type*) unit->data)[3]

    inline void _glUniform4f  (Unit* unit) { glUniform4f (ARGS(float)); };

    #undef ARGS

    #define ARGS(type)\
      unit->location,\
      unit->size,\
      ((type*) unit->data)

    inline void _glUniform1fv  (Unit* unit) { glUniform1fv (ARGS(float)); };
    inline void _glUniform2fv  (Unit* unit) { glUniform2fv (ARGS(float)); };
    inline void _glUniform3fv  (Unit* unit) { glUniform3fv (ARGS(float)); };
    inline void _glUniform4fv  (Unit* unit) { glUniform4fv (ARGS(float)); };

    #undef ARGS

    #define ARGS(type)\
      unit->location,\
      unit->size,\
      0,\
      ((type*) unit->data)

    inline void _glUniformMatrix4fv (Unit* unit) { glUniformMatrix4fv(ARGS(float)); };

    // inline void _object_mat_update_function_opengl (Unit* unit) {

    //   DATA::OBJECT::update(unit->data);

    //   glUniformMatrix4fv(ARGS(float));
    // };

    #undef ARGS



    namespace STORAGE {

      inline void expand (Storage* storage) {

        storage->stack_VECTORS[0].push_back(nullptr);
        storage->stack_RANGES[0] = storage->stack_VECTORS[0].data();

        storage->stack_VECTORS[1].push_back(nullptr);
        storage->stack_RANGES[1] = storage->stack_VECTORS[1].data();
      };



      void init (Storage* storage) {

        storage_stack_next_free_element_VECTOR.push_back(0);
        storage_stack_next_free_element_RANGE = storage_stack_next_free_element_VECTOR.data();
        storage_stack_next_free_element_SIZE = storage_stack_next_free_element_VECTOR.size() * 4;

        storage->stack_next_free_element_OFFSET = storage_stack_next_free_element_VECTOR.size() - 1;

        expand(storage);
      };



      inline void execute (Storage* storage) {

        Unit** stack = storage->stack_RANGES[storage_stack_index0];

        for (uint32_t i = 0; stack[i]; i++) {

          stack[i]->update(stack[i]);

          stack[i] = nullptr;

          // std::cout << "executed" << std::endl;
        }
      };

      inline void execute2 (Storage* storage) {

        // Unit** stack = storage->stack_RANGES[storage_stack_index0];

        uint8_t* stack_addr = (uint*) storage->stack_RANGES[storage_stack_index0];

        Unit* current_unit;

        uint32_t i = 0;

        while (current_unit = (Unit*) (stack_addr + i)) {

          current_unit->update(current_unit);

          i += MEM_ADDR_LENGTH;
        }

        memset(stack, 0, i);
      };
    };



    namespace WRAPPER {

      inline void init (Wrapper* wrapper_ptr) {

        uniform_not_pushed_flag_VECTOR.push_back(1);
        uniform_not_pushed_flag_RANGE = uniform_not_pushed_flag_VECTOR.data();
        uniform_not_pushed_flag_SIZE = uniform_not_pushed_flag_VECTOR.size() * 4;

        wrapper_ptr->not_pushed_flag_OFFSET = uniform_not_pushed_flag_VECTOR.size() - 1;
      };



      inline Unit* inject (

        Wrapper* wrapper_ptr,
        Storage* storage,
        const uint32_t location,
        const uint32_t size,
        const uint32_t offset, // offset in bytes
        const char* storage_type,
        const char* uniform_type
      ) {

        Unit unit = { ((uint8_t*) wrapper_ptr->data) + offset, storage, location, size };

        if (strcmp(storage_type, "opengl_program") == 0) {

          if (strcmp(uniform_type, "vec4") == 0) {

            if (size == 0) {

              unit.update = _glUniform4f;
            }
            else if (size > 0) {

              unit.update = _glUniform4fv;
            }
          }
          else if (strcmp(uniform_type, "mat4") == 0) {

            unit.update = _glUniformMatrix4fv;
          }
          // else if (strcmp(uniform_type, "object_mat") == 0) {

          //   unit.update = _object_mat_update_function_opengl;
          // }
        }

        unit_VECTOR.push_back(unit);
        unit_RANGE = unit_VECTOR.data();

        uint32_t unit_index = unit_VECTOR.size() - 1;

        wrapper_ptr->unit_VECTOR.push_back(&unit_RANGE[unit_index]);
        wrapper_ptr->unit_RANGE = wrapper_ptr->unit_VECTOR.data();
        wrapper_ptr->unit_COUNT = wrapper_ptr->unit_VECTOR.size();

        unit.update(&unit);

        STORAGE::expand(storage);

        return &unit_RANGE[unit_index];
      };

      inline Unit* inject (

        Wrapper* wrapper_ptr,
        Storage* storage,
        const uint32_t location,
        const uint32_t size,
        const uint32_t offset, // offset in bytes
        void (* update_callback_function) (Unit*)
      ) {

        Unit unit = { ((uint8_t*) wrapper_ptr->data) + offset, storage, location, size };

        unit.update = update_callback_function;

        unit_VECTOR.push_back(unit);
        unit_RANGE = unit_VECTOR.data();

        uint32_t unit_index = unit_VECTOR.size() - 1;

        wrapper_ptr->unit_VECTOR.push_back(&unit_RANGE[unit_index]);
        wrapper_ptr->unit_RANGE = wrapper_ptr->unit_VECTOR.data();
        wrapper_ptr->unit_COUNT = wrapper_ptr->unit_VECTOR.size();

        unit.update(&unit);

        STORAGE::expand(storage);

        return &unit_RANGE[unit_index];
      };



      inline void push (Wrapper* wrapper) {

        #ifdef __EMSCRIPTEN__
          pthread_mutex_lock(&XGK::UNIFORM::mutex);
        #else
          XGK::UNIFORM::mutex.lock();
        #endif

        if (uniform_not_pushed_flag_RANGE[wrapper->not_pushed_flag_OFFSET]) {

          uniform_not_pushed_flag_RANGE[wrapper->not_pushed_flag_OFFSET] = 0;

          for (uint32_t i = 0; i < wrapper->unit_COUNT; i++) {

            const Storage* storage = wrapper->unit_RANGE[i]->storage;

            Unit** stack = storage->stack_RANGES[storage_stack_index1];

            stack[storage_stack_next_free_element_RANGE[storage->stack_next_free_element_OFFSET]] = wrapper->unit_RANGE[i];

            storage_stack_next_free_element_RANGE[storage->stack_next_free_element_OFFSET]++;
          }
        }

        #ifdef __EMSCRIPTEN__
          pthread_mutex_unlock(&XGK::UNIFORM::mutex);
        #else
          XGK::UNIFORM::mutex.unlock();
        #endif
      };



      // inline void push2 (Vec4* wrapper, Storage* storage) {

      //   #ifdef __EMSCRIPTEN__
      //     pthread_mutex_lock(&XGK::UNIFORM::mutex);
      //   #else
      //     XGK::UNIFORM::mutex.lock();
      //   #endif

      //   if (uniform_not_pushed_flag_RANGE[wrapper->not_pushed_flag_OFFSET]) {

      //     uniform_not_pushed_flag_RANGE[wrapper->not_pushed_flag_OFFSET] = 0;

      //     Unit** stack = storage->stack_RANGES[storage_stack_index1];

      //     stack[storage_stack_next_free_element_RANGE[storage->stack_next_free_element_OFFSET]++] = wrapper->unit_RANGE[i];
      //     storage_stack_next_free_element_COUNT = 
      //   }

      //   #ifdef __EMSCRIPTEN__
      //     pthread_mutex_unlock(&XGK::UNIFORM::mutex);
      //   #else
      //     XGK::UNIFORM::mutex.unlock();
      //   #endif
      // };
    };
  };
};



// void render_loop () {
//   // #0
//   #ifdef __EMSCRIPTEN__
//     pthread_mutex_lock(&XGK::UNIFORM::mutex);
//   #else
//     XGK::UNIFORM::mutex.lock();
//   #endif

//   XGK::UNIFORM::storage_stack_index0 = XGK::UNIFORM::storage_stack_index1;
//   XGK::UNIFORM::storage_stack_index1 = !XGK::UNIFORM::storage_stack_index1;

//   memset(XGK::UNIFORM::storage_stack_next_free_element_RANGE, 0, XGK::UNIFORM::storage_stack_next_free_element_COUNT);
//   memset(XGK::UNIFORM::uniform_not_pushed_flag_RANGE, 1, XGK::UNIFORM::uniform_not_pushed_flag_COUNT);

//   #ifdef __EMSCRIPTEN__
//     pthread_mutex_unlock(&XGK::UNIFORM::mutex);
//   #else
//     XGK::UNIFORM::mutex.unlock();
//   #endif
//   // #0~


//   // #1
//   // during running code block #1, uniforms can be properly pushed onto the stacks
//   XGK::UNIFORM::STORAGE::execute(&some_uniform_storage0);
//   XGK::UNIFORM::STORAGE::execute(&some_uniform_storage1);
//   // #1~
// };
