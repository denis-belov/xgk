// Wrapper is bound with data object (Vec4, Mat4 etc).

// Unit is an object in Storage, associated with Wrapper.
// Storage may have numerous Units for different Wrappers.
// Some Units in Storage may be associated with the same Wrappers,
// but have different attributes (location, size etc).

// Wrapper has signal function, that tells (when calling) all Storages which have Wrapper injected that they need to push Unit, associated with Wrapper, to their stacks.

namespace XGK {

  namespace UNIFORM {

    // needs to #include <mutex>
    std::mutex mutex;

    static std::vector<uint32_t> storage_stack_next_free_element_VECTOR;
    static uint32_t* storage_stack_next_free_element_RANGE;

    static std::vector<uint8_t> wrapper_not_pushed_flag_VECTOR;
    static uint8_t* wrapper_not_pushed_flag_RANGE;



    struct Unit;



    typedef void (* UniformUpdateFuncPtr) (void* unit);



    #pragma pack(push, 8)
      struct Storage {

        std::vector<Unit*> stack_VECTORS[2];

        Unit** stack_RANGES[2];

        uint32_t stack_next_free_element_OFFSET;
      };
    #pragma pack(pop)



    #pragma pack(push, 8)
      struct Unit {

        // Storage* storage;

        uint32_t location;

        uint32_t offset;

        GLsizei size;

        void* data;

        UniformUpdateFuncPtr update_func;
      };
    #pragma pack(pop)



    #pragma pack(push, 8)
      struct Wrapper {

        void* data;

        std::vector<Unit> unit_VECTOR;

        Unit* unit_RANGE;

        uint32_t unit_count;

        uint32_t not_pushed_flag_OFFSET;
      };
    #pragma pack(pop)



    // #define ARGS(type)\
    //   ((Unit*) unit)->location,\
    //   ((type*) ((Unit*) unit)->data)[0]

    // inline void _glUniform1i  (void* unit) { glUniform1i (ARGS(GLint)); };
    // inline void _glUniform1ui (void* unit) { glUniform1ui(ARGS(GLuint)); };
    // inline void _glUniform1f  (void* unit) { glUniform1f (ARGS(GLfloat)); };
    // #ifndef __EMSCRIPTEN__
    //   inline void _glUniform1d  (void* unit) { glUniform1d (ARGS(GLdouble)); };
    // #endif

    // #undef ARGS

    // #define ARGS(type)\
    //   ((Unit*) unit)->location,\
    //   ((type*) ((Unit*) unit)->data)[0],\
    //   ((type*) ((Unit*) unit)->data)[1]

    // inline void _glUniform2i  (void* unit) { glUniform2i (ARGS(GLint)); };
    // inline void _glUniform2ui (void* unit) { glUniform2ui(ARGS(GLuint)); };
    // inline void _glUniform2f  (void* unit) { glUniform2f (ARGS(GLfloat)); };
    // #ifndef __EMSCRIPTEN__
    //   inline void _glUniform2d  (void* unit) { glUniform2d (ARGS(GLdouble)); };
    // #endif

    // #undef ARGS

    // #define ARGS(type)\
    //   ((Unit*) unit)->location,\
    //   ((type*) ((Unit*) unit)->data)[((Unit*) unit)->offset],\
    //   ((type*) ((Unit*) unit)->data)[((Unit*) unit)->offset + 1]

    // inline void _glUniform2io  (void* unit) { glUniform2i (ARGS(GLint)); };
    // inline void _glUniform2uio (void* unit) { glUniform2ui(ARGS(GLuint)); };
    // inline void _glUniform2fo  (void* unit) { glUniform2f (ARGS(GLfloat)); };
    // #ifndef __EMSCRIPTEN__
    //   inline void _glUniform2do  (void* unit) { glUniform2d (ARGS(GLdouble)); };
    // #endif

    // #undef ARGS

    // #define ARGS(type)\
    //   ((Unit*) unit)->location,\
    //   ((type*) ((Unit*) unit)->data)[0],\
    //   ((type*) ((Unit*) unit)->data)[1],\
    //   ((type*) ((Unit*) unit)->data)[2]

    // inline void _glUniform3i  (void* unit) { glUniform3i (ARGS(GLint)); };
    // inline void _glUniform3ui (void* unit) { glUniform3ui(ARGS(GLuint)); };
    // inline void _glUniform3f  (void* unit) { glUniform3f (ARGS(GLfloat)); };
    // #ifndef __EMSCRIPTEN__
    //   inline void _glUniform3d  (void* unit) { glUniform3d (ARGS(GLdouble)); };
    // #endif

    // #undef ARGS

    // #define ARGS(type)\
    //   ((Unit*) unit)->location,\
    //   ((type*) ((Unit*) unit)->data)[((Unit*) unit)->offset],\
    //   ((type*) ((Unit*) unit)->data)[((Unit*) unit)->offset + 1],\
    //   ((type*) ((Unit*) unit)->data)[((Unit*) unit)->offset + 2]

    // inline void _glUniform3io  (void* unit) { glUniform3i (ARGS(GLint)); };
    // inline void _glUniform3uio (void* unit) { glUniform3ui(ARGS(GLuint)); };
    // inline void _glUniform3fo  (void* unit) { glUniform3f (ARGS(GLfloat)); };
    // #ifndef __EMSCRIPTEN__
    //   inline void _glUniform3do  (void* unit) { glUniform3d (ARGS(GLdouble)); };
    // #endif

    // #undef ARGS

    #define ARGS(type)\
      ((Unit*) unit)->location,\
      ((type*) ((Unit*) unit)->data)[0],\
      ((type*) ((Unit*) unit)->data)[1],\
      ((type*) ((Unit*) unit)->data)[2],\
      ((type*) ((Unit*) unit)->data)[3]

    // inline void _glUniform4i  (void* unit) { glUniform4i (ARGS(GLint)); };
    // inline void _glUniform4ui (void* unit) { glUniform4ui(ARGS(GLuint)); };
    inline void _glUniform4f  (void* unit) { glUniform4f (ARGS(GLfloat)); };
    // #ifndef __EMSCRIPTEN__
    //   inline void _glUniform4d  (void* unit) { glUniform4d (ARGS(GLdouble)); };
    // #endif

    #undef ARGS

    // // usage with offset
    // #define ARGS(type)\
    //   ((Unit*) unit)->location,\
    //   ((type*) ((Unit*) unit)->data)[((Unit*) unit)->offset],\
    //   ((type*) ((Unit*) unit)->data)[((Unit*) unit)->offset + 1],\
    //   ((type*) ((Unit*) unit)->data)[((Unit*) unit)->offset + 2],\
    //   ((type*) ((Unit*) unit)->data)[((Unit*) unit)->offset + 3]

    // inline void _glUniform4io  (void* unit) { glUniform4i (ARGS(GLint)); };
    // inline void _glUniform4uio (void* unit) { glUniform4ui(ARGS(GLuint)); };
    // inline void _glUniform4fo  (void* unit) { glUniform4f (ARGS(GLfloat)); };
    // #ifndef __EMSCRIPTEN__
    //   inline void _glUniform4do  (void* unit) { glUniform4d (ARGS(GLdouble)); };
    // #endif

    // #undef ARGS

    #define ARGS(type)\
      ((Unit*) unit)->location,\
      ((Unit*) unit)->size,\
      ((type*) ((Unit*) unit)->data)

    // inline void _glUniform1iv  (void* unit) { glUniform1iv (ARGS(GLint)); };
    // inline void _glUniform1uiv (void* unit) { glUniform1uiv(ARGS(GLuint)); };
    // inline void _glUniform1fv  (void* unit) { glUniform1fv (ARGS(GLfloat)); };
    // #ifndef __EMSCRIPTEN__
    //   inline void _glUniform1dv  (void* unit) { glUniform1dv (ARGS(GLdouble)); };
    // #endif

    // inline void _glUniform2iv  (void* unit) { glUniform2iv (ARGS(GLint)); };
    // inline void _glUniform2uiv (void* unit) { glUniform2uiv(ARGS(GLuint)); };
    // inline void _glUniform2fv  (void* unit) { glUniform2fv (ARGS(GLfloat)); };
    // #ifndef __EMSCRIPTEN__
    //   inline void _glUniform2dv  (void* unit) { glUniform2dv (ARGS(GLdouble)); };
    // #endif

    // inline void _glUniform3iv  (void* unit) { glUniform3iv (ARGS(GLint)); };
    // inline void _glUniform3uiv (void* unit) { glUniform3uiv(ARGS(GLuint)); };
    // inline void _glUniform3fv  (void* unit) { glUniform3fv (ARGS(GLfloat)); };
    // #ifndef __EMSCRIPTEN__
    //   inline void _glUniform3dv  (void* unit) { glUniform3dv (ARGS(GLdouble)); };
    // #endif

    // inline void _glUniform4iv  (void* unit) { glUniform4iv (ARGS(GLint)); };
    // inline void _glUniform4uiv (void* unit) { glUniform4uiv(ARGS(GLuint)); };
    inline void _glUniform4fv  (void* unit) { glUniform4fv (ARGS(GLfloat)); };
    // #ifndef __EMSCRIPTEN__
    //   inline void _glUniform4dv  (void* unit) { glUniform4dv (ARGS(GLdouble)); };
    // #endif

    #undef ARGS

    // #define ARGS(type)\
    //   ((Unit*) unit)->location,\
    //   ((Unit*) unit)->size,\
    //   ((type*) ((Unit*) unit)->data) + ((Unit*) unit)->offset

    // inline void _glUniform1ivo  (void* unit) { glUniform1iv (ARGS(GLint)); };
    // inline void _glUniform1uivo (void* unit) { glUniform1uiv(ARGS(GLuint)); };
    // inline void _glUniform1fvo  (void* unit) { glUniform1fv (ARGS(GLfloat)); };
    // #ifndef __EMSCRIPTEN__
    //   inline void _glUniform1dvo  (void* unit) { glUniform1dv (ARGS(GLdouble)); };
    // #endif

    // inline void _glUniform2ivo  (void* unit) { glUniform2iv (ARGS(GLint)); };
    // inline void _glUniform2uivo (void* unit) { glUniform2uiv(ARGS(GLuint)); };
    // inline void _glUniform2fvo  (void* unit) { glUniform2fv (ARGS(GLfloat)); };
    // #ifndef __EMSCRIPTEN__
    //   inline void _glUniform2dvo  (void* unit) { glUniform2dv (ARGS(GLdouble)); };
    // #endif

    // inline void _glUniform3ivo  (void* unit) { glUniform3iv (ARGS(GLint)); };
    // inline void _glUniform3uivo (void* unit) { glUniform3uiv(ARGS(GLuint)); };
    // inline void _glUniform3fvo  (void* unit) { glUniform3fv (ARGS(GLfloat)); };
    // #ifndef __EMSCRIPTEN__
    //   inline void _glUniform3dvo  (void* unit) { glUniform3dv (ARGS(GLdouble)); };
    // #endif

    // inline void _glUniform4ivo  (void* unit) { glUniform4iv (ARGS(GLint)); };
    // inline void _glUniform4uivo (void* unit) { glUniform4uiv(ARGS(GLuint)); };
    // inline void _glUniform4fvo  (void* unit) { glUniform4fv (ARGS(GLfloat)); };
    // #ifndef __EMSCRIPTEN__
    //   inline void _glUniform4dvo  (void* unit) { glUniform4dv (ARGS(GLdouble)); };
    // #endif

    // #undef ARGS

    #define ARGS(type)\
      ((Unit*) unit)->location,\
      ((Unit*) unit)->size,\
      0,\
      ((type*) ((Unit*) unit)->data)

    inline void _glUniformMatrix4fv (void* unit) { glUniformMatrix4fv(ARGS(GLfloat)); };

    #undef ARGS



    inline void initWrapper (Wrapper* wrapper) {

      wrapper_not_pushed_flag_VECTOR.push_back(1);
      wrapper_not_pushed_flag_RANGE = wrapper_not_pushed_flag_VECTOR.data();

      wrapper->not_pushed_flag_OFFSET = wrapper_not_pushed_flag_VECTOR.size() - 1;
    };



    inline void expandStorageStacks (Storage* storage) {

      storage->stack_VECTORS[0].push_back(nullptr);
      storage->stack_RANGES[0] = storage->stack_VECTORS[0].data();

      storage->stack_VECTORS[1].push_back(nullptr);
      storage->stack_RANGES[1] = storage->stack_VECTORS[1].data();
    };



    inline void injectWrapperIntoStorage (
      Storage* storage,
      Wrapper* wrapper,
      const char* api,
      const char* storage_type,
      const char* uniform_type,
      const uint32_t location,
      const uint32_t offset,
      const uint32_t size
    ) {

      Unit unit = { location, offset, (GLsizei) size, wrapper->data };

      if (strcmp(api, "opengl") == 0) {

        if (strcmp(storage_type, "opengl_program") == 0) {

          if (size == 0) {

            // if (strcmp(uniform_type, "bool") == 0 || strcmp(uniform_type, "int") == 0) {

            //   unit.update_func = _glUniform1i;
            // }
            // else if (strcmp(uniform_type, "uint") == 0) {

            //   unit.update_func = _glUniform1ui;
            // }
            // else if (strcmp(uniform_type, "float") == 0) {

            //   unit.update_func = _glUniform1f;
            // }
            // else if (strcmp(uniform_type, "bvec2") == 0 || strcmp(uniform_type, "ivec2") == 0) {

            //   unit.update_func = _glUniform2i;
            // }
            // else if (strcmp(uniform_type, "uvec2") == 0) {

            //   unit.update_func = _glUniform2ui;
            // }
            // else if (strcmp(uniform_type, "vec2") == 0) {

            //   unit.update_func = _glUniform2f;
            // }
            // else if (strcmp(uniform_type, "bvec3") == 0 || strcmp(uniform_type, "ivec3") == 0) {

            //   unit.update_func = _glUniform3i;
            // }
            // else if (strcmp(uniform_type, "uvec3") == 0) {

            //   unit.update_func = _glUniform3ui;
            // }
            // else if (strcmp(uniform_type, "vec3") == 0) {

            //   unit.update_func = _glUniform3f;
            // }
            // else if (strcmp(uniform_type, "bvec4") == 0 || strcmp(uniform_type, "ivec4") == 0) {

            //   unit.update_func = _glUniform4i;
            // }
            // else if (strcmp(uniform_type, "uvec4") == 0) {

            //   unit.update_func = _glUniform4ui;
            // }
            if (strcmp(uniform_type, "vec4") == 0) {

              unit.update_func = _glUniform4f;
            }
            // #ifndef __EMSCRIPTEN__
            //   else if (strcmp(uniform_type, "double") == 0) {

            //     unit.update_func = _glUniform1d;
            //   }
            //   else if (strcmp(uniform_type, "dvec2") == 0) {

            //     unit.update_func = _glUniform2d;
            //   }
            //   else if (strcmp(uniform_type, "dvec3") == 0) {

            //     unit.update_func = _glUniform3d;
            //   }
            //   else if (strcmp(uniform_type, "dvec4") == 0) {

            //     unit.update_func = _glUniform4d;
            //   }
            // #endif
          }
          else {
            // if (strcmp(uniform_type, "bool[]") == 0 || strcmp(uniform_type, "int[]") == 0) {

            //   unit.update_func = _glUniform1iv;
            // }
            // else if (strcmp(uniform_type, "uint[]") == 0) {

            //   unit.update_func = _glUniform1uiv;
            // }
            // else if (strcmp(uniform_type, "float[]") == 0) {

            //   unit.update_func = _glUniform1fv;
            // }
            // else if (strcmp(uniform_type, "bvec2[]") == 0 || strcmp(uniform_type, "ivec2[]") == 0) {

            //   unit.update_func = _glUniform2iv;
            // }
            // else if (strcmp(uniform_type, "uvec2[]") == 0) {

            //   unit.update_func = _glUniform2uiv;
            // }
            // else if (strcmp(uniform_type, "vec2[]") == 0) {

            //   unit.update_func = _glUniform2fv;
            // }
            // else if (strcmp(uniform_type, "bvec3[]") == 0 || strcmp(uniform_type, "ivec3[]") == 0) {

            //   unit.update_func = _glUniform3iv;
            // }
            // else if (strcmp(uniform_type, "uvec3[]") == 0) {

            //   unit.update_func = _glUniform3uiv;
            // }
            // else if (strcmp(uniform_type, "vec3[]") == 0) {

            //   unit.update_func = _glUniform3fv;
            // }
            // else if (strcmp(uniform_type, "bvec4[]") == 0 || strcmp(uniform_type, "ivec4[]") == 0) {

            //   unit.update_func = _glUniform4iv;
            // }
            // else if (strcmp(uniform_type, "uvec4[]") == 0) {

            //   unit.update_func = _glUniform4uiv;
            // }
            if (strcmp(uniform_type, "vec4[]") == 0) {

              unit.update_func = _glUniform4fv;
            }
            else if (strcmp(uniform_type, "mat4[]") == 0) {

              unit.update_func = _glUniformMatrix4fv;
            }
            // #ifndef __EMSCRIPTEN__
            //   else if (strcmp(uniform_type, "double[]") == 0) {

            //     unit.update_func = _glUniform1dv;
            //   }
            //   else if (strcmp(uniform_type, "dvec2[]") == 0) {

            //     unit.update_func = _glUniform2dv;
            //   }
            //   else if (strcmp(uniform_type, "dvec3[]") == 0) {

            //     unit.update_func = _glUniform3dv;
            //   }
            //   else if (strcmp(uniform_type, "dvec4[]") == 0) {

            //     unit.update_func = _glUniform4dv;
            //   }
            // #endif
          }
        }
        // else if (strcmp(storage_type, "uniform_buffer") == 0) {

        // }
      }

      wrapper->unit_VECTOR.push_back(unit);
      wrapper->unit_RANGE = wrapper->unit_VECTOR.data();

      unit.update_func(&unit);

      expandStorageStacks(storage);
    };



    inline void pushWrapperOntoStacks (Wrapper* wrapper) {

      // wait until uniform storage stack is set relevant
      // if uniform storage stack is relevant, then the data wrapper can be pushed onto this stack
      #ifdef __EMSCRIPTEN__
        pthread_mutex_lock(&XGK::UNIFORM::mutex);
      #else
        XGK::UNIFORM::mutex.lock();
      #endif

      if (uniform_not_pushed_flag_RANGE[wrapper.not_pushed_flag_OFFSET]) {

        uniform_not_pushed_flag_RANGE[wrapper.not_pushed_flag_OFFSET] = 0;

        for (uint32_t i = 0; i < wrapper->unit_count; i++) {

          const Storage* storage = wrapper->units[i].storage;

          const Unit* stack = storage->stack_RANGES[storage_stack_index1];

          stack[storage_stack_next_free_element_RANGE[storage.stack_next_free_element_OFFSET]++] = wrapper->units[i];
        }
      }

      #ifdef __EMSCRIPTEN__
        pthread_mutex_unlock(&XGK::UNIFORM::mutex);
      #else
        XGK::UNIFORM::mutex.unlock();
      #endif
    };



    inline void executeStorageStack (Storage* storage) {

      const Unit* stack = storage->stack_RANGES[storage_stack_index0];

      for (uint32_t i = 0; stack[i]; i++) {

        stack[i]->update_func(stack[i]);

        stack[i] = nullptr;
      }
    };
  };
};



void render_loop () {
  // #0
  #ifdef __EMSCRIPTEN__
    pthread_mutex_lock(&XGK::UNIFORM::mutex);
  #else
    XGK::UNIFORM::mutex.lock();
  #endif

  XGK::UNIFORM::storage_stack_index0 = XGK::UNIFORM::storage_stack_index1;
  XGK::UNIFORM::storage_stack_index1 = !XGK::UNIFORM::storage_stack_index1;

  memset(XGK::UNIFORM::storage_stack_next_free_element_RANGE, 0, XGK::UNIFORM::storage_stack_next_free_element_COUNT);
  memset(XGK::UNIFORM::uniform_not_pushed_flag_RANGE, 1, XGK::UNIFORM::uniform_not_pushed_flag_COUNT);

  #ifdef __EMSCRIPTEN__
    pthread_mutex_unlock(&XGK::UNIFORM::mutex);
  #else
    XGK::UNIFORM::mutex.unlock();
  #endif
  // #0~


  // #1
  // during running code block #1, uniforms can be properly pushed onto the stacks
  XGK::UNIFORM::executeStorageStack(&some_uniform_storage0);
  XGK::UNIFORM::executeStorageStack(&some_uniform_storage1);
  // #1~
};
