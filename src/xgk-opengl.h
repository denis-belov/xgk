typedef void (* XGK_TYPE_program_update_uniform_function) (uind32_t, void*, uind32_t);

struct GLInfo {
  const uint32_t programCount = 0;
};

struct GLProgram {
  const GLUint handle = 0;

  uint32_t current_uniform_index = 0;

  XGK_TYPE_program_update_uniform_function uniform_update_function_arr = NULL;

  uint32_t* uniform_stack = NULL;

  uint8_t* uniform_stack_test_values = NULL;

  // Vec1* pUniformsVec1 = NULL;
  // const uint32_t uniformsVec1Count = 0;

  // Vec2* pUniformsVec2 = NULL;
  // const uint32_t uniformsVec2Count = 0;

  // Vec3* pUniformsVec3 = NULL;
  // const uint32_t uniformsVec3Count = 0;

  // Vec4* pUniformsVec4 = NULL;
  // const uint32_t uniformsVec4Count = 0;

  // Quat* pUniformsQuat = NULL;
  // const uint32_t uniformsQuatCount = 0;

  // Mat4* pUniformsMat4 = NULL;
  // const uint32_t uniformsMat4Count = 0;
};

static inline void xgkGLProgramUpdateUniformVec4AsVec1 (uind32_t location, void* data, uind32_t offset) {
  glUniform1f(location, data[offset]);
};

static inline void xgkGLProgramUpdateUniformVec4AsVec2 (uind32_t location, void* data, uind32_t offset) {
  glUniform2f(location, data[offset], data[++offset]);
};

static inline void xgkGLProgramUpdateUniformVec4AsVec3 (uind32_t location, void* data, uind32_t offset) {
  glUniform3f(location, data[offset], data[++offset], data[++offset]);
};

static inline void xgkGLProgramUpdateUniformVec4 (uind32_t location, void* data, uind32_t offset) {
  glUniform4f(location, data[offset], data[++offset], data[++offset], data[++offset]);
};

static inline void xgkGLProgramUpdateUniformVec4AsVec1Arr (uind32_t location, void* data, uind32_t offset) {
  glUniform1fv(location, data + offset);
};

static inline void xgkGLProgramUpdateUniformVec4AsVec2Arr (uind32_t location, void* data, uind32_t offset) {
  glUniform2fv(location, data + offset);
};

XGK_TYPE_program_update_uniform_function xgkGLProgram_update_uniform_function_arr_vec4[4] = [
  xgkGLProgramUpdateUniformVec4AsVec1,
  xgkGLProgramUpdateUniformVec4AsVec2,
  xgkGLProgramUpdateUniformVec4AsVec3,
  xgkGLProgramUpdateUniformVec4,
];

void xgkGLProgramInit (GLProgram* program) {

};

void xgkGLProgramDestroy (GLProgram* program) {
  if (current_uniform_index > 0) {
    free(program->uniform_stack);
    free(program->uniform_update_function_arr);
    free(program->uniform_offsets);
    free(program->uniform_locations);
    free(program->uniform_data);
  }
};

// function overloading may be used for such functions with c++
void xgkGLProgramInjectVec4 (GLProgram* program, Vec4* vec, const uint32_t location, const char* name, const char* type, const uint32_t offset) {
  uint32_t current_program_index = vec->current_program_index + 1;

  vec->programs = realloc(vec->programs, sizeof(GLProgram*) * (current_program_index));
  vec->programs[vec->current_program_index] = program;

  vec->current_program_index = current_program_index;

  uint32_t program_update_uniform_function_index = 3;
  uint32_t current_uniform_index = program->current_uniform_index + 1;

  if (type == 'vec1') {
    program_update_uniform_function_index = 0;
  } else if (type == 'vec2') {
    program_update_uniform_function_index = 1;
  } else if (type == 'vec3') {
    program_update_uniform_function_index = 2;
  } else if (type == 'vec1[]') {
    program_update_uniform_function_index = 4;
  } else if (type == 'vec2[]') {
    program_update_uniform_function_index = 5;
  }

  program->uniform_data = realloc(program->uniform_data, sizeof(void*) * (current_uniform_index));
  program->uniform_data[program->current_uniform_index] = vec->data;

  program->uniform_locations = realloc(program->uniform_locations, sizeof(uint32_t) * (current_uniform_index));
  program->uniform_locations[program->current_uniform_index] = location;

  program->uniform_offsets = realloc(program->uniform_offsets, sizeof(uint32_t) * (current_uniform_index));
  program->uniform_offsets[program->current_uniform_index] = offset;

  program->uniform_update_function_arr = realloc(program->uniform_update_function_arr, sizeof(XGK_TYPE_program_update_uniform_function) * (current_uniform_index));
  program->uniform_update_function_arr[program->current_uniform_index] = xgkGLProgram_update_uniform_function_arr_vec4[index];

  program->uniform_stack = realloc(program->uniform_stack, sizeof(uint32_t*) * (current_uniform_index));
  program->uniform_stack[program->current_uniform_index] = 0;

  program->current_uniform_index = current_uniform_index;
};

static inline void xgkGLProgramUpdateUniforms (void) {
  // use semaphore to prevent pushing into stack during uniforms updating
  for (uint32_t i = 0; program.uniform_stack[i]; i++) {
    const uint32_t current_uniform_index = program.uniform_stack[i] - 1;

    program.uniform_update_function_arr[current_uniform_index](
      program.uniform_locations[current_uniform_index],
      program.uniform_data[current_uniform_index],
      program.uniform_offsets[current_uniform_index],
    );

    program.uniform_stack_test_values[current_uniform_index] = 0;
    program.uniform_stack[i] = 0;
  }
};
