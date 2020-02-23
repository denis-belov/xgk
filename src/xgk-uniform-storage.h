// i use additional pointer to vector data to get it's actual address after pushing back or resizing and possible reallocating memory and changing its address
// e.g.
// std::vector<UNIFORM_STORAGE::UniformAttr> uniform_attr_arr;
// UNIFORM_STORAGE::UniformAttr* uniform_attr_arr_data;

// Microsoft CL do more optimized code with structs rather than flat arrays

// todo getAvailableLocation ()
// todo test asm vs c++ uniform update function performance

namespace XGK {
  namespace UNIFORM_STORAGE {
    typedef void (* UniformUpdateFuncPtr) (void*);

    XGK_MACRO_STRUCT_ALIGNMENT(8) UniformAttr {
      // order members for better alignment management
      uint32_t location;

      uint32_t offset;

      GLsizei size;

      void* data_ptr;

      UniformUpdateFuncPtr update_func;

      // glUniform1i for opengl program
      // glBufferSubData for opengl uniform bufer
      // void api_func;
    };

    #define ARGS(type)\
      ((UniformAttr*) uniform_attr)->location,\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[0]

    static inline void _glUniform1i  (void* uniform_attr) { glUniform1i (ARGS(GLint)); };
    static inline void _glUniform1ui (void* uniform_attr) { glUniform1ui(ARGS(GLuint)); };
    static inline void _glUniform1f  (void* uniform_attr) { glUniform1f (ARGS(GLfloat)); };
    #ifndef __EMSCRIPTEN__
      static inline void _glUniform1d  (void* uniform_attr) { glUniform1d (ARGS(GLdouble)); };
    #endif

    #undef ARGS

    #define ARGS(type)\
      ((UniformAttr*) uniform_attr)->location,\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[0],\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[1]

    static inline void _glUniform2i  (void* uniform_attr) { glUniform2i (ARGS(GLint)); };
    static inline void _glUniform2ui (void* uniform_attr) { glUniform2ui(ARGS(GLuint)); };
    static inline void _glUniform2f  (void* uniform_attr) { glUniform2f (ARGS(GLfloat)); };
    #ifndef __EMSCRIPTEN__
      static inline void _glUniform2d  (void* uniform_attr) { glUniform2d (ARGS(GLdouble)); };
    #endif

    #undef ARGS

    #define ARGS(type)\
      ((UniformAttr*) uniform_attr)->location,\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[((UniformAttr*) uniform_attr)->offset],\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[((UniformAttr*) uniform_attr)->offset + 1]

    static inline void _glUniform2io  (void* uniform_attr) { glUniform2i (ARGS(GLint)); };
    static inline void _glUniform2uio (void* uniform_attr) { glUniform2ui(ARGS(GLuint)); };
    static inline void _glUniform2fo  (void* uniform_attr) { glUniform2f (ARGS(GLfloat)); };
    #ifndef __EMSCRIPTEN__
      static inline void _glUniform2do  (void* uniform_attr) { glUniform2d (ARGS(GLdouble)); };
    #endif

    #undef ARGS

    #define ARGS(type)\
      ((UniformAttr*) uniform_attr)->location,\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[0],\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[1],\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[2]

    static inline void _glUniform3i  (void* uniform_attr) { glUniform3i (ARGS(GLint)); };
    static inline void _glUniform3ui (void* uniform_attr) { glUniform3ui(ARGS(GLuint)); };
    static inline void _glUniform3f  (void* uniform_attr) { glUniform3f (ARGS(GLfloat)); };
    #ifndef __EMSCRIPTEN__
      static inline void _glUniform3d  (void* uniform_attr) { glUniform3d (ARGS(GLdouble)); };
    #endif

    #undef ARGS

    #define ARGS(type)\
      ((UniformAttr*) uniform_attr)->location,\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[((UniformAttr*) uniform_attr)->offset],\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[((UniformAttr*) uniform_attr)->offset + 1],\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[((UniformAttr*) uniform_attr)->offset + 2]

    static inline void _glUniform3io  (void* uniform_attr) { glUniform3i (ARGS(GLint)); };
    static inline void _glUniform3uio (void* uniform_attr) { glUniform3ui(ARGS(GLuint)); };
    static inline void _glUniform3fo  (void* uniform_attr) { glUniform3f (ARGS(GLfloat)); };
    #ifndef __EMSCRIPTEN__
      static inline void _glUniform3do  (void* uniform_attr) { glUniform3d (ARGS(GLdouble)); };
    #endif

    #undef ARGS

    #define ARGS(type)\
      ((UniformAttr*) uniform_attr)->location,\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[0],\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[1],\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[2],\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[3]

    static inline void _glUniform4i  (void* uniform_attr) { glUniform4i (ARGS(GLint)); };
    static inline void _glUniform4ui (void* uniform_attr) { glUniform4ui(ARGS(GLuint)); };
    static inline void _glUniform4f  (void* uniform_attr) { glUniform4f (ARGS(GLfloat)); };
    #ifndef __EMSCRIPTEN__
      static inline void _glUniform4d  (void* uniform_attr) { glUniform4d (ARGS(GLdouble)); };
    #endif

    #undef ARGS

    #define ARGS(type)\
      ((UniformAttr*) uniform_attr)->location,\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[((UniformAttr*) uniform_attr)->offset],\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[((UniformAttr*) uniform_attr)->offset + 1],\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[((UniformAttr*) uniform_attr)->offset + 2],\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)[((UniformAttr*) uniform_attr)->offset + 3]

    static inline void _glUniform4io  (void* uniform_attr) { glUniform4i (ARGS(GLint)); };
    static inline void _glUniform4uio (void* uniform_attr) { glUniform4ui(ARGS(GLuint)); };
    static inline void _glUniform4fo  (void* uniform_attr) { glUniform4f (ARGS(GLfloat)); };
    #ifndef __EMSCRIPTEN__
      static inline void _glUniform4do  (void* uniform_attr) { glUniform4d (ARGS(GLdouble)); };
    #endif

    #undef ARGS

    #define ARGS(type)\
      ((UniformAttr*) uniform_attr)->location,\
      ((UniformAttr*) uniform_attr)->size,\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr)

    static inline void _glUniform1iv  (void* uniform_attr) { glUniform1iv (ARGS(GLint)); };
    static inline void _glUniform1uiv (void* uniform_attr) { glUniform1uiv(ARGS(GLuint)); };
    static inline void _glUniform1fv  (void* uniform_attr) { glUniform1fv (ARGS(GLfloat)); };
    #ifndef __EMSCRIPTEN__
      static inline void _glUniform1dv  (void* uniform_attr) { glUniform1dv (ARGS(GLdouble)); };
    #endif

    static inline void _glUniform2iv  (void* uniform_attr) { glUniform2iv (ARGS(GLint)); };
    static inline void _glUniform2uiv (void* uniform_attr) { glUniform2uiv(ARGS(GLuint)); };
    static inline void _glUniform2fv  (void* uniform_attr) { glUniform2fv (ARGS(GLfloat)); };
    #ifndef __EMSCRIPTEN__
      static inline void _glUniform2dv  (void* uniform_attr) { glUniform2dv (ARGS(GLdouble)); };
    #endif

    static inline void _glUniform3iv  (void* uniform_attr) { glUniform3iv (ARGS(GLint)); };
    static inline void _glUniform3uiv (void* uniform_attr) { glUniform3uiv(ARGS(GLuint)); };
    static inline void _glUniform3fv  (void* uniform_attr) { glUniform3fv (ARGS(GLfloat)); };
    #ifndef __EMSCRIPTEN__
      static inline void _glUniform3dv  (void* uniform_attr) { glUniform3dv (ARGS(GLdouble)); };
    #endif

    static inline void _glUniform4iv  (void* uniform_attr) { glUniform4iv (ARGS(GLint)); };
    static inline void _glUniform4uiv (void* uniform_attr) { glUniform4uiv(ARGS(GLuint)); };
    static inline void _glUniform4fv  (void* uniform_attr) { glUniform4fv (ARGS(GLfloat)); };
    #ifndef __EMSCRIPTEN__
      static inline void _glUniform4dv  (void* uniform_attr) { glUniform4dv (ARGS(GLdouble)); };
    #endif

    #undef ARGS

    #define ARGS(type)\
      ((UniformAttr*) uniform_attr)->location,\
      ((UniformAttr*) uniform_attr)->size,\
      ((type*) ((UniformAttr*) uniform_attr)->data_ptr) + ((UniformAttr*) uniform_attr)->offset

    static inline void _glUniform1ivo  (void* uniform_attr) { glUniform1iv (ARGS(GLint)); };
    static inline void _glUniform1uivo (void* uniform_attr) { glUniform1uiv(ARGS(GLuint)); };
    static inline void _glUniform1fvo  (void* uniform_attr) { glUniform1fv (ARGS(GLfloat)); };
    #ifndef __EMSCRIPTEN__
      static inline void _glUniform1dvo  (void* uniform_attr) { glUniform1dv (ARGS(GLdouble)); };
    #endif

    static inline void _glUniform2ivo  (void* uniform_attr) { glUniform2iv (ARGS(GLint)); };
    static inline void _glUniform2uivo (void* uniform_attr) { glUniform2uiv(ARGS(GLuint)); };
    static inline void _glUniform2fvo  (void* uniform_attr) { glUniform2fv (ARGS(GLfloat)); };
    #ifndef __EMSCRIPTEN__
      static inline void _glUniform2dvo  (void* uniform_attr) { glUniform2dv (ARGS(GLdouble)); };
    #endif

    static inline void _glUniform3ivo  (void* uniform_attr) { glUniform3iv (ARGS(GLint)); };
    static inline void _glUniform3uivo (void* uniform_attr) { glUniform3uiv(ARGS(GLuint)); };
    static inline void _glUniform3fvo  (void* uniform_attr) { glUniform3fv (ARGS(GLfloat)); };
    #ifndef __EMSCRIPTEN__
      static inline void _glUniform3dvo  (void* uniform_attr) { glUniform3dv (ARGS(GLdouble)); };
    #endif

    static inline void _glUniform4ivo  (void* uniform_attr) { glUniform4iv (ARGS(GLint)); };
    static inline void _glUniform4uivo (void* uniform_attr) { glUniform4uiv(ARGS(GLuint)); };
    static inline void _glUniform4fvo  (void* uniform_attr) { glUniform4fv (ARGS(GLfloat)); };
    #ifndef __EMSCRIPTEN__
      static inline void _glUniform4dvo  (void* uniform_attr) { glUniform4dv (ARGS(GLdouble)); };
    #endif

    #undef ARGS

    // // asm
    // extern void uniform1 (void*);
    // extern void uniform2 (void*);
    // extern void uniform3 (void*);
    // extern void uniform4 (void*);
    // extern void uniformv (void*);
  }

  XGK_MACRO_STRUCT_ALIGNMENT(8) UniformStorage {
    UniformStorage () {};

    std::vector<UNIFORM_STORAGE::UniformAttr> uniform_attr_arr;
    UNIFORM_STORAGE::UniformAttr* uniform_attr_arr_data;
    std::vector<void*> uniform_attr_ptr_arr;
    void** uniform_attr_ptr_arr_data;

    // std::vector<UNIFORM_STORAGE::UniformUpdateFuncPtr> uniform_update_func_arr;
    // UNIFORM_STORAGE::UniformUpdateFuncPtr* uniform_update_func_arr_data;

    // UniformStack uniform_stack;
  };

  namespace UNIFORM_STORAGE {
    void injectUniform (
      UniformStorage* storage_ptr,
      void* wrapper_ptr,
      const char* storage_type,
      const char* uniform_type,
      const uint32_t location,
      const uint32_t offset,
      const uint32_t size
    ) {
      // wrapper_ptr->storage_uniform_stack_data_arr_arr.push_back(storage_ptr->uniform_stack_data_arr);
      // wrapper_ptr->storage_uniform_stack_data_arr_arr_data = wrapper_ptr->storage_uniform_stack_data_arr_arr.data();


      UniformAttr uniform_attr = { location, offset, (GLsizei) size, wrapper_ptr };

      if (strcmp(global_api, "opengl") == 0) {
        if (strcmp(storage_type, "opengl_program") == 0) {
          if (size == 0) {
            if (strcmp(uniform_type, "bool") == 0 || strcmp(uniform_type, "int") == 0) {
              uniform_attr.update_func = _glUniform1i;
            } else if (strcmp(uniform_type, "uint") == 0) {
              uniform_attr.update_func = _glUniform1ui;
            } else if (strcmp(uniform_type, "float") == 0) {
              uniform_attr.update_func = _glUniform1f;
            } else if (strcmp(uniform_type, "bvec2") == 0 || strcmp(uniform_type, "ivec2") == 0) {
              uniform_attr.update_func = _glUniform2i;
            } else if (strcmp(uniform_type, "uvec2") == 0) {
              uniform_attr.update_func = _glUniform2ui;
            } else if (strcmp(uniform_type, "vec2") == 0) {
              uniform_attr.update_func = _glUniform2f;
            } else if (strcmp(uniform_type, "bvec3") == 0 || strcmp(uniform_type, "ivec3") == 0) {
              uniform_attr.update_func = _glUniform3i;
            } else if (strcmp(uniform_type, "uvec3") == 0) {
              uniform_attr.update_func = _glUniform3ui;
            } else if (strcmp(uniform_type, "vec3") == 0) {
              uniform_attr.update_func = _glUniform3f;
            } else if (strcmp(uniform_type, "bvec4") == 0 || strcmp(uniform_type, "ivec4") == 0) {
              uniform_attr.update_func = _glUniform4i;
            } else if (strcmp(uniform_type, "uvec4") == 0) {
              uniform_attr.update_func = _glUniform4ui;
            } else if (strcmp(uniform_type, "vec4") == 0) {
              uniform_attr.update_func = _glUniform4f;
            }
            #ifndef __EMSCRIPTEN__
              else if (strcmp(uniform_type, "double") == 0) {
                uniform_attr.update_func = _glUniform1d;
              } else if (strcmp(uniform_type, "dvec2") == 0) {
                uniform_attr.update_func = _glUniform2d;
              } else if (strcmp(uniform_type, "dvec3") == 0) {
                uniform_attr.update_func = _glUniform3d;
              } else if (strcmp(uniform_type, "dvec4") == 0) {
                uniform_attr.update_func = _glUniform4d;
              }
            #endif
          } else {
            if (strcmp(uniform_type, "bool[]") == 0 || strcmp(uniform_type, "int[]") == 0) {
              uniform_attr.update_func = _glUniform1iv;
            } else if (strcmp(uniform_type, "uint[]") == 0) {
              uniform_attr.update_func = _glUniform1uiv;
            } else if (strcmp(uniform_type, "float[]") == 0) {
              uniform_attr.update_func = _glUniform1fv;
            } else if (strcmp(uniform_type, "bvec2[]") == 0 || strcmp(uniform_type, "ivec2[]") == 0) {
              uniform_attr.update_func = _glUniform2iv;
            } else if (strcmp(uniform_type, "uvec2[]") == 0) {
              uniform_attr.update_func = _glUniform2uiv;
            } else if (strcmp(uniform_type, "vec2[]") == 0) {
              uniform_attr.update_func = _glUniform2fv;
            } else if (strcmp(uniform_type, "bvec3[]") == 0 || strcmp(uniform_type, "ivec3[]") == 0) {
              uniform_attr.update_func = _glUniform3iv;
            } else if (strcmp(uniform_type, "uvec3[]") == 0) {
              uniform_attr.update_func = _glUniform3uiv;
            } else if (strcmp(uniform_type, "vec3[]") == 0) {
              uniform_attr.update_func = _glUniform3fv;
            } else if (strcmp(uniform_type, "bvec4[]") == 0 || strcmp(uniform_type, "ivec4[]") == 0) {
              uniform_attr.update_func = _glUniform4iv;
            } else if (strcmp(uniform_type, "uvec4[]") == 0) {
              uniform_attr.update_func = _glUniform4uiv;
            } else if (strcmp(uniform_type, "vec4[]") == 0) {
              uniform_attr.update_func = _glUniform4fv;
            }
            #ifndef __EMSCRIPTEN__
              else if (strcmp(uniform_type, "double[]") == 0) {
                uniform_attr.update_func = _glUniform1dv;
              } else if (strcmp(uniform_type, "dvec2[]") == 0) {
                uniform_attr.update_func = _glUniform2dv;
              } else if (strcmp(uniform_type, "dvec3[]") == 0) {
                uniform_attr.update_func = _glUniform3dv;
              } else if (strcmp(uniform_type, "dvec4[]") == 0) {
                uniform_attr.update_func = _glUniform4dv;
              }
            #endif
          }
        } else if (strcmp(storage_type, "uniform_buffer") == 0) {

        }

      }


      storage_ptr->uniform_attr_arr.push_back(uniform_attr);
      storage_ptr->uniform_attr_arr_data = storage_ptr->uniform_attr_arr.data();


      storage_ptr->uniform_attr_ptr_arr.push_back(&storage_ptr->uniform_attr_arr.back());
      storage_ptr->uniform_attr_ptr_arr_data = storage_ptr->uniform_attr_ptr_arr.data();


      uniform_attr.update_func(&storage_ptr->uniform_attr_arr.back());


      UNIFORM_STACK::expand(&storage_ptr->uniform_stack);
    };

    static inline void updateUniforms (UniformStorage* storage_ptr) {
      void* uniform_stack_data = storage_ptr->uniform_stack.arr_data_arr[UNIFORM_STACK::index1];

      for (uint32_t i = 0; uniform_stack_data[i]; i++) {
        void* uniform_attr_ptr = _glUniform_stack_data[i];

        uniform_attr_ptr->update_func(uniform_attr_ptr);

        uniform_stack_data[i] = nullptr;
      }

      storage_ptr->uniform_stack.index = 0;
    };
  }
};
