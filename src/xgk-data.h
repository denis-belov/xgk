#include <string.h>
#include <math.h>

#if defined(GCC) || defined(MSVC)
  #include <intrin.h>
#elif defined(EMCC)
  #include <wasm_simd128.h>
#endif

typedef union {
  float  _32[4];

  #ifdef XGK_DATA_SSE
    __m128 _128;
  #endif
} Vec4;

typedef union {
  float  _32[4];

  #ifdef XGK_DATA_SSE
    __m128 _128;
  #endif
} Quat;

typedef union {
  float _32[16];

  #ifdef XGK_DATA_SSE
    __m128 _128[4];
  #endif

  #ifdef XGK_DATA_AVX
    __m256 _256[2];
  #endif
} Mat4;

typedef struct {
  Mat4 projection_matrix;
  Mat4 view_matrix;
} Camera;

#include "data/mat4.h"
