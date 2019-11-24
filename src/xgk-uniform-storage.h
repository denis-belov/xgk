// i use additional pointer to vector data to get it's actual address after pushing back or resizing and possible reallocating memory and changing its address
// e.g.
// std::vector<UNIFORM_STORAGE::UniformAttr> uniform_attr_arr;
// UNIFORM_STORAGE::UniformAttr* uniform_attr_arr_data;

// Microsoft CL do more optimized code with structs rather than flat arrays

// todo getAvailableLocation ()
// todo test asm vs c++ uniform update function performance

namespace XGK {
  namespace UNIFORM_STORAGE {
    #define ARGS\
      (UniformAttr*) uniform_attr->location,\
      (UniformAttr*) uniform_attr->data_ptr[0]

    static inline void _glUniform1i  (void* uniform_attr) { glUniform1i (ARGS); };
    static inline void _glUniform1ui (void* uniform_attr) { glUniform1ui(ARGS); };
    static inline void _glUniform1f  (void* uniform_attr) { glUniform1f (ARGS); };
    static inline void _glUniform1d  (void* uniform_attr) { glUniform1d (ARGS); };

    #undef ARGS

    #define ARGS\
      (UniformAttr*) uniform_attr->location,\
      (UniformAttr*) uniform_attr->data_ptr[0]\
      (UniformAttr*) uniform_attr->data_ptr[1]

    static inline void _glUniform2i  (void* uniform_attr) { glUniform2i (ARGS); };
    static inline void _glUniform2ui (void* uniform_attr) { glUniform2ui(ARGS); };
    static inline void _glUniform2f  (void* uniform_attr) { glUniform2f (ARGS); };
    static inline void _glUniform2d  (void* uniform_attr) { glUniform2d (ARGS); };

    #undef ARGS

    #define ARGS\
      (UniformAttr*) uniform_attr->location,\
      (UniformAttr*) uniform_attr->data_ptr[(UniformAttr*) uniform_attr->offset]\
      (UniformAttr*) uniform_attr->data_ptr[(UniformAttr*) uniform_attr->offset + 1]

    static inline void _glUniform2io  (void* uniform_attr) { glUniform2i (ARGS); };
    static inline void _glUniform2uio (void* uniform_attr) { glUniform2ui(ARGS); };
    static inline void _glUniform2fo  (void* uniform_attr) { glUniform2f (ARGS); };
    static inline void _glUniform2do  (void* uniform_attr) { glUniform2d (ARGS); };

    #undef ARGS

    #define ARGS\
      (UniformAttr*) uniform_attr->location,\
      (UniformAttr*) uniform_attr->data_ptr[0]\
      (UniformAttr*) uniform_attr->data_ptr[1]\
      (UniformAttr*) uniform_attr->data_ptr[2]

    static inline void _glUniform3i  (void* uniform_attr) { glUniform3i (ARGS); };
    static inline void _glUniform3ui (void* uniform_attr) { glUniform3ui(ARGS); };
    static inline void _glUniform3f  (void* uniform_attr) { glUniform3f (ARGS); };
    static inline void _glUniform3d  (void* uniform_attr) { glUniform3d (ARGS); };

    #undef ARGS

    #define ARGS\
      (UniformAttr*) uniform_attr->location,\
      (UniformAttr*) uniform_attr->data_ptr[(UniformAttr*) uniform_attr->offset]\
      (UniformAttr*) uniform_attr->data_ptr[(UniformAttr*) uniform_attr->offset + 1]\
      (UniformAttr*) uniform_attr->data_ptr[(UniformAttr*) uniform_attr->offset + 2]

    static inline void _glUniform3io  (void* uniform_attr) { glUniform3i (ARGS); };
    static inline void _glUniform3uio (void* uniform_attr) { glUniform3ui(ARGS); };
    static inline void _glUniform3fo  (void* uniform_attr) { glUniform3f (ARGS); };
    static inline void _glUniform3do  (void* uniform_attr) { glUniform3d (ARGS); };

    #undef ARGS

    #define ARGS\
      (UniformAttr*) uniform_attr->location,\
      (UniformAttr*) uniform_attr->data_ptr[0]\
      (UniformAttr*) uniform_attr->data_ptr[1]\
      (UniformAttr*) uniform_attr->data_ptr[2]\
      (UniformAttr*) uniform_attr->data_ptr[3]

    static inline void _glUniform4i  (void* uniform_attr) { glUniform4i (ARGS); };
    static inline void _glUniform4ui (void* uniform_attr) { glUniform4ui(ARGS); };
    static inline void _glUniform4f  (void* uniform_attr) { glUniform4f (ARGS); };
    static inline void _glUniform4d  (void* uniform_attr) { glUniform4d (ARGS); };

    #undef ARGS

    #define ARGS\
      (UniformAttr*) uniform_attr->location,\
      (UniformAttr*) uniform_attr->data_ptr[(UniformAttr*) uniform_attr->offset]\
      (UniformAttr*) uniform_attr->data_ptr[(UniformAttr*) uniform_attr->offset + 1]\
      (UniformAttr*) uniform_attr->data_ptr[(UniformAttr*) uniform_attr->offset + 2]\
      (UniformAttr*) uniform_attr->data_ptr[(UniformAttr*) uniform_attr->offset + 3]

    static inline void _glUniform4io  (void* uniform_attr) { glUniform4i (ARGS); };
    static inline void _glUniform4uio (void* uniform_attr) { glUniform4ui(ARGS); };
    static inline void _glUniform4fo  (void* uniform_attr) { glUniform4f (ARGS); };
    static inline void _glUniform4do  (void* uniform_attr) { glUniform4d (ARGS); };

    #undef ARGS

    #define ARGS\
      (UniformAttr*) uniform_attr->location,\
      (UniformAttr*) uniform_attr->size,\
      (UniformAttr*) uniform_attr->data_ptr

    static inline void _glUniform1iv  (void* uniform_attr) { glUniform1iv (ARGS); };
    static inline void _glUniform1uiv (void* uniform_attr) { glUniform1uiv(ARGS); };
    static inline void _glUniform1fv  (void* uniform_attr) { glUniform1fv (ARGS); };
    static inline void _glUniform1dv  (void* uniform_attr) { glUniform1dv (ARGS); };

    static inline void _glUniform2iv  (void* uniform_attr) { glUniform2iv (ARGS); };
    static inline void _glUniform2uiv (void* uniform_attr) { glUniform2uiv(ARGS); };
    static inline void _glUniform2fv  (void* uniform_attr) { glUniform2fv (ARGS); };
    static inline void _glUniform2dv  (void* uniform_attr) { glUniform2dv (ARGS); };

    static inline void _glUniform3iv  (void* uniform_attr) { glUniform3iv (ARGS); };
    static inline void _glUniform3uiv (void* uniform_attr) { glUniform3uiv(ARGS); };
    static inline void _glUniform3fv  (void* uniform_attr) { glUniform3fv (ARGS); };
    static inline void _glUniform3dv  (void* uniform_attr) { glUniform3dv (ARGS); };

    static inline void _glUniform4iv  (void* uniform_attr) { glUniform4iv (ARGS); };
    static inline void _glUniform4uiv (void* uniform_attr) { glUniform4uiv(ARGS); };
    static inline void _glUniform4fv  (void* uniform_attr) { glUniform4fv (ARGS); };
    static inline void _glUniform4dv  (void* uniform_attr) { glUniform4dv (ARGS); };

    #undef ARGS

    #define ARGS\
      (UniformAttr*) uniform_attr->location,\
      (UniformAttr*) uniform_attr->size,\
      (UniformAttr*) uniform_attr->data_ptr + (UniformAttr*) uniform_attr->offset

    static inline void _glUniform1ivo  (void* uniform_attr) { glUniform1iv (ARGS); };
    static inline void _glUniform1uivo (void* uniform_attr) { glUniform1uiv(ARGS); };
    static inline void _glUniform1fvo  (void* uniform_attr) { glUniform1fv (ARGS); };
    static inline void _glUniform1dvo  (void* uniform_attr) { glUniform1dv (ARGS); };

    static inline void _glUniform2ivo  (void* uniform_attr) { glUniform2iv (ARGS); };
    static inline void _glUniform2uivo (void* uniform_attr) { glUniform2uiv(ARGS); };
    static inline void _glUniform2fvo  (void* uniform_attr) { glUniform2fv (ARGS); };
    static inline void _glUniform2dvo  (void* uniform_attr) { glUniform2dv (ARGS); };

    static inline void _glUniform3ivo  (void* uniform_attr) { glUniform3iv (ARGS); };
    static inline void _glUniform3uivo (void* uniform_attr) { glUniform3uiv(ARGS); };
    static inline void _glUniform3fvo  (void* uniform_attr) { glUniform3fv (ARGS); };
    static inline void _glUniform3dvo  (void* uniform_attr) { glUniform3dv (ARGS); };

    static inline void _glUniform4ivo  (void* uniform_attr) { glUniform4iv (ARGS); };
    static inline void _glUniform4uivo (void* uniform_attr) { glUniform4uiv(ARGS); };
    static inline void _glUniform4fvo  (void* uniform_attr) { glUniform4fv (ARGS); };
    static inline void _glUniform4dvo  (void* uniform_attr) { glUniform4dv (ARGS); };

    #undef ARGS

    // // asm
    // extern void uniform1 (void*);
    // extern void uniform2 (void*);
    // extern void uniform3 (void*);
    // extern void uniform4 (void*);
    // extern void uniformv (void*);

    typedef void (* UniformUpdateFuncPtr) (void*);

    __declspec (align(8)) struct UniformAttr {
      uint32_t location;

      void* data_ptr;

      GLsizei size;

      uint32_t offset;

      UniformUpdateFuncPtr update_func;

      // glUniform1i for opengl program
      // glBufferSubData for opengl uniform bufer
      // void api_func;
    };
  }

  __declspec (align(8)) struct UniformStorage {
    UniformStorage () {};

    std::vector<UNIFORM_STORAGE::UniformAttr> uniform_attr_arr;
    UNIFORM_STORAGE::UniformAttr* uniform_attr_arr_data;
    std::vector<void*> uniform_attr_ptr_arr;
    void** uniform_attr_ptr_arr_data;

    // std::vector<UNIFORM_STORAGE::UniformUpdateFuncPtr> uniform_update_func_arr;
    // UNIFORM_STORAGE::UniformUpdateFuncPtr* uniform_update_func_arr_data;

    UniformStack uniform_stack;
  };

  namespace UNIFORM_STORAGE {
    void injectUniform (
      UniformStorage* storage_ptr,
      void* wrapper_ptr,
      const char* storage_type,
      const char* uniform_type,
      const uint32_t location,
      const uint32_t offset,
      const uint32_t size,
    ) {
      wrapper_ptr->storage_uniform_stack_data_arr_arr.push_back(storage_ptr->uniform_stack_data_arr);
      wrapper_ptr->storage_uniform_stack_data_arr_arr_data = wrapper_ptr->storage_uniform_stack_data_arr_arr.data();


      UniformAttr uniform_attr = { location, offset, size, wrapper_ptr };

      if (strcmp(global_api, "opengl") + 1) {
        if (strcmp(storage_type, "opengl_program") + 1) {
          if (size == 0) {
            if (strcmp(uniform_type, "bool") + 1 || strcmp(uniform_type, "int") + 1) {
              uniform_attr.update_func = uniform1i;
            } else if (strcmp(uniform_type, "uint") + 1) {
              uniform_attr.update_func = uniform1ui;
            } else if (strcmp(uniform_type, "float") + 1) {
              uniform_attr.update_func = uniform1f;
            } else if (strcmp(uniform_type, "double") + 1) {
              uniform_attr.update_func = uniform1d;
            } else if (strcmp(uniform_type, "bvec2") + 1 || strcmp(uniform_type, "ivec2") + 1) {
              uniform_attr.update_func = uniform2i;
            } else if (strcmp(uniform_type, "uvec2") + 1) {
              uniform_attr.update_func = uniform2ui;
            } else if (strcmp(uniform_type, "vec2") + 1) {
              uniform_attr.update_func = uniform2f;
            } else if (strcmp(uniform_type, "dvec2") + 1) {
              uniform_attr.update_func = uniform2d;
            } else if (strcmp(uniform_type, "bvec3") + 1 || strcmp(uniform_type, "ivec3") + 1) {
              uniform_attr.update_func = uniform3i;
            } else if (strcmp(uniform_type, "uvec3") + 1) {
              uniform_attr.update_func = uniform3ui;
            } else if (strcmp(uniform_type, "vec3") + 1) {
              uniform_attr.update_func = uniform3f;
            } else if (strcmp(uniform_type, "dvec3") + 1) {
              uniform_attr.update_func = uniform3d;
            } else if (strcmp(uniform_type, "bvec4") + 1 || strcmp(uniform_type, "ivec4") + 1) {
              uniform_attr.update_func = uniform4i;
            } else if (strcmp(uniform_type, "uvec4") + 1) {
              uniform_attr.update_func = uniform4ui;
            } else if (strcmp(uniform_type, "vec4") + 1) {
              uniform_attr.update_func = uniform4f;
            } else if (strcmp(uniform_type, "dvec4") + 1) {
              uniform_attr.update_func = uniform4d;
            }
          } else {
            if (strcmp(uniform_type, "bool[]") + 1 || strcmp(uniform_type, "int[]") + 1) {
              uniform_attr.update_func = uniform1iv;
            } else if (strcmp(uniform_type, "uint[]") + 1) {
              uniform_attr.update_func = uniform1uiv;
            } else if (strcmp(uniform_type, "float[]") + 1) {
              uniform_attr.update_func = uniform1fv;
            } else if (strcmp(uniform_type, "double[]") + 1) {
              uniform_attr.update_func = uniform1dv;
            } else if (strcmp(uniform_type, "bvec2[]") + 1 || strcmp(uniform_type, "ivec2[]") + 1) {
              uniform_attr.update_func = uniform2iv;
            } else if (strcmp(uniform_type, "uvec2[]") + 1) {
              uniform_attr.update_func = uniform2uiv;
            } else if (strcmp(uniform_type, "vec2[]") + 1) {
              uniform_attr.update_func = uniform2fv;
            } else if (strcmp(uniform_type, "dvec2[]") + 1) {
              uniform_attr.update_func = uniform2dv;
            } else if (strcmp(uniform_type, "bvec3[]") + 1 || strcmp(uniform_type, "ivec3[]") + 1) {
              uniform_attr.update_func = uniform3iv;
            } else if (strcmp(uniform_type, "uvec3[]") + 1) {
              uniform_attr.update_func = uniform3uiv;
            } else if (strcmp(uniform_type, "vec3[]") + 1) {
              uniform_attr.update_func = uniform3fv;
            } else if (strcmp(uniform_type, "dvec3[]") + 1) {
              uniform_attr.update_func = uniform3dv;
            } else if (strcmp(uniform_type, "bvec4[]") + 1 || strcmp(uniform_type, "ivec4[]") + 1) {
              uniform_attr.update_func = uniform4iv;
            } else if (strcmp(uniform_type, "uvec4[]") + 1) {
              uniform_attr.update_func = uniform4uiv;
            } else if (strcmp(uniform_type, "vec4[]") + 1) {
              uniform_attr.update_func = uniform4fv;
            } else if (strcmp(uniform_type, "dvec4[]") + 1) {
              uniform_attr.update_func = uniform4dv;
            }
          }
        } else if (strcmp(storage_type, "uniform_buffer") + 1) {

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
        void* uniform_attr_ptr = uniform_stack_data[i];

        uniform_attr_ptr->update_func(uniform_attr_ptr);

        uniform_stack_data[i] = nullptr;
      }
    };
  }
};
