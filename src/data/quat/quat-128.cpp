//   + AwBx + AxBw + AyBz (*  1) + AzBy (* -1)
//   + AwBy - AxBz + AyBw (*  1) + AzBx (*  1)
//   + AwBz + AxBy + AyBx (* -1) + AzBw (*  1)
//   + AwBw - AxBx + AyBy (* -1) + AzBz (* -1)

#define MUL(dst_quaternion_addr_float, left_quaternion_addr_float, right_quaternion_addr_float)\
  \
  alignas(16) const __m128 right_quaternion_m128 = _mm_load_ps(right_quaternion_addr_float);\
  \
  alignas(16) const __m128 a = _mm_shuffle_ps(right_quaternion_m128, right_quaternion_m128, _MM_SHUFFLE(0, 1, 2, 3));\
  alignas(16) const __m128 b = _mm_shuffle_ps(right_quaternion_m128, right_quaternion_m128, _MM_SHUFFLE(1, 0, 3, 2));\
  alignas(16) const __m128 c = _mm_shuffle_ps(right_quaternion_m128, right_quaternion_m128, _MM_SHUFFLE(2, 3, 0, 1));\
  \
  alignas(16) const __m128 d = _mm_mul_ps(a, _mm_load_ps1(&left_quaternion_addr_float[3]));\
  alignas(16) const __m128 e = _mm_mul_ps(right_quaternion_m128, _mm_load_ps1(&left_quaternion_addr_float[0]));\
  alignas(16) const __m128 f = _mm_mul_ps(b, _mm_load_ps1(&left_quaternion_addr_float[1]));\
  alignas(16) const __m128 g = _mm_mul_ps(c, _mm_load_ps1(&left_quaternion_addr_float[2]));\
  \
  alignas(16) __m128 h = _mm_addsub_ps(d, e);\
  h = _mm_shuffle_ps(h, h, _MM_SHUFFLE(0, 1, 2, 3));\
  alignas(16) const __m128 i = _mm_mul_ps(_mm_addsub_ps(f, g), CONST_MUL);\
  alignas(16) const __m128 j = _mm_add_ps(h, i);\
  \
  _mm_store_ps(dst_quaternion_addr_float, j);



#define MAKE_ROT(quaternion_addr_float, vector_addr_float)\
  \
  const float angle_half = angle * 0.5f;\
  alignas(16) const __m128 data_128 = _mm_mul_ps(_mm_loadr_ps(vector_addr_float), _mm_set1_ps(sin(angle_half)));\
  \
  _mm_storer_ps(quaternion_addr_float, data_128);\
  \
  quaternion_addr_float[3] = cos(angle_half);



#include <cstdint>
#include <cmath>
#include <immintrin.h>



namespace XGK {

  namespace DATA {

    namespace QUAT {

      alignas(16) const __m128 CONST_MUL = { 1.0f, 1.0f, -1.0f, -1.0f };
      alignas(16) const __m128 CONST_MUL2 = { 1.0f, -1.0f, 1.0f, -1.0f };



      // void premul128 (void* data0, void* data1) {

      //   alignas(16) const __m128 data0_128 = _mm_load_ps((float*) data0);
      //   const float* _data1 = (const float*) data1;

      //   alignas(16) const __m128 a = _mm_shuffle_ps(data0_128, data0_128, _MM_SHUFFLE(0, 1, 2, 3));
      //   alignas(16) const __m128 b = _mm_shuffle_ps(data0_128, data0_128, _MM_SHUFFLE(2, 3, 0, 1));
      //   alignas(16) const __m128 c = _mm_shuffle_ps(data0_128, data0_128, _MM_SHUFFLE(1, 0, 3, 2));

      //   alignas(16) const __m128 d = _mm_mul_ps(a, _mm_load_ps1(&_data1[3]));
      //   alignas(16) const __m128 e = _mm_mul_ps(data0_128, _mm_load_ps1(&_data1[0]));
      //   alignas(16) const __m128 f = _mm_mul_ps(_mm_mul_ps(b, _mm_load_ps1(&_data1[1])), signs0.f128);
      //   alignas(16) const __m128 g = _mm_mul_ps(_mm_mul_ps(c, _mm_load_ps1(&_data1[2])), signs1.f128);

      //   alignas(16) __m128 h = _mm_addsub_ps(d, e);
      //   alignas(16) __m128 i = _mm_add_ps(h, f);
      //   alignas(16) const __m128 j = _mm_add_ps(i, g);

      //   _mm_storer_ps((float*) data0, j);
      // };

      // void postmul128 (void* data0, void* data1) {

      //   alignas(16) const __m128 data1_128 = _mm_load_ps((float*) data1);
      //   float* _data0 = (float*) data0;

      //   alignas(16) const __m128 a = _mm_shuffle_ps(data1_128, data1_128, _MM_SHUFFLE(0, 1, 2, 3));
      //   alignas(16) const __m128 b = _mm_shuffle_ps(data1_128, data1_128, _MM_SHUFFLE(2, 3, 0, 1));
      //   alignas(16) const __m128 c = _mm_shuffle_ps(data1_128, data1_128, _MM_SHUFFLE(1, 0, 3, 2));

      //   alignas(16) const __m128 d = _mm_mul_ps(a, _mm_load_ps1(&_data0[3]));
      //   alignas(16) const __m128 e = _mm_mul_ps(data1_128, _mm_load_ps1(&_data0[0]));
      //   alignas(16) const __m128 f = _mm_mul_ps(_mm_mul_ps(b, _mm_load_ps1(&_data0[1])), signs0.f128);
      //   alignas(16) const __m128 g = _mm_mul_ps(_mm_mul_ps(c, _mm_load_ps1(&_data0[2])), signs1.f128);

      //   alignas(16) __m128 h = _mm_addsub_ps(d, e);
      //   alignas(16) __m128 i = _mm_add_ps(h, f);
      //   alignas(16) const __m128 j = _mm_add_ps(i, g);

      //   _mm_storer_ps(_data0, j);
      // };



      void premul128 (void* dst_quaternion_addr, void* src_quaternion_addr) {

        float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;
        float* src_quaternion_addr_float = (float*) src_quaternion_addr;

        MUL(dst_quaternion_addr_float, src_quaternion_addr_float, dst_quaternion_addr_float)
      };



      void postmul128 (void* dst_quaternion_addr, void* src_quaternion_addr) {

        float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;
        float* src_quaternion_addr_float = (float*) src_quaternion_addr;

        MUL(dst_quaternion_addr_float, dst_quaternion_addr_float, src_quaternion_addr_float)
      };



      void makeRot128 (void* dst_quaternion_addr, void* dst_vector_addr, const float angle) {

        float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;
        float* dst_vector_addr_float = (float*) dst_vector_addr;

        MAKE_ROT(dst_quaternion_addr_float, dst_vector_addr_float)
      };



      void preRot128 (void* dst_quaternion_addr, void* dst_vector_addr, const float angle) {

        float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;
        float* dst_vector_addr_float = (float*) dst_vector_addr;
        alignas(16) float src_quaternion_addr_float[4];

        MAKE_ROT(src_quaternion_addr_float, dst_vector_addr_float)

        MUL(dst_quaternion_addr_float, src_quaternion_addr_float, dst_quaternion_addr_float)
      };



      void postRot128 (void* dst_quaternion_addr, void* dst_vector_addr, const float angle) {

        float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;
        float* dst_vector_addr_float = (float*) dst_vector_addr;
        alignas(16) float src_quaternion_addr_float[4];

        MAKE_ROT(src_quaternion_addr_float, dst_vector_addr_float)

        MUL(dst_quaternion_addr_float, dst_quaternion_addr_float, src_quaternion_addr_float)
      };



      // void preRot128 (void* dst_quaternion_addr, void* dst_vector_addr, const float angle) {

      //   float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;
      //   alignas(16) float src_quaternion_addr_float[4];
      //   float* dst_vector_addr_float = (float*) dst_vector_addr;

      //   MAKE_ROT(src_quaternion_addr_float, dst_vector_addr_float)
      //   MUL(dst_quaternion_addr_float, src_quaternion_addr_float, dst_quaternion_addr_float)
      // };



      // void postRot128 (void* dst_quaternion_addr, void* dst_vector_addr, const float angle) {

      //   float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;
      //   alignas(16) float src_quaternion_addr_float[4];
      //   float* dst_vector_addr_float = (float*) dst_vector_addr;

      //   MAKE_ROT(src_quaternion_addr_float, dst_vector_addr_float)
      //   MUL(dst_quaternion_addr_float, dst_quaternion_addr_float, src_quaternion_addr_float)
      // };



      void makeRotX128 (void* dst_quaternion_addr, const float angle) {

        float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;

        const float angle_half = angle * 0.5f;

        dst_quaternion_addr_float[0] = sin(angle_half);
        dst_quaternion_addr_float[1] = 0.0f;
        dst_quaternion_addr_float[2] = 0.0f;
        dst_quaternion_addr_float[3] = cos(angle_half);
      };



      void preRotX128 (void* dst_quaternion_addr, const float angle) {

        float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;

        const float angle_half = angle * 0.5f;
        const float x = sin(angle_half);
        const float w = cos(angle_half);

        alignas(16) const __m128 x_x_x_x = { x, -x, x, -x };
        alignas(16) const __m128 w_w_w_w = { w, w, w, w };

        alignas(16) const __m128 a = _mm_mul_ps(w_w_w_w, _mm_load_ps(dst_quaternion_addr_float));
        alignas(16) const __m128 b = _mm_mul_ps(x_x_x_x, _mm_loadr_ps(dst_quaternion_addr_float));
        alignas(16) const __m128 c = _mm_add_ps(a, b);

        _mm_store_ps(dst_quaternion_addr_float, c);
      };



      void postRotX128 (void* dst_quaternion_addr, const float angle) {

        float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;

        const float angle_half = angle * 0.5f;
        const float x = sin(angle_half);
        const float w = cos(angle_half);

        alignas(16) const __m128 x_x_x_x = { x, x, -x, -x };
        alignas(16) const __m128 w_w_w_w = { w, w, w, w };

        alignas(16) const __m128 a = _mm_mul_ps(w_w_w_w, _mm_load_ps(dst_quaternion_addr_float));
        alignas(16) const __m128 b = _mm_mul_ps(x_x_x_x, _mm_loadr_ps(dst_quaternion_addr_float));
        alignas(16) const __m128 c = _mm_add_ps(a, b);

        _mm_store_ps(dst_quaternion_addr_float, c);
      };



      void makeRotY128 (void* data, const float angle) {

        float* _data = (float*) data;

        const float angle_half = angle * 0.5f;

        _data[0] = 0.0f;
        _data[1] = sin(angle_half);
        _data[2] = 0.0f;
        _data[3] = cos(angle_half);
      };



      void preRotY128 (void* dst_quaternion_addr, const float angle) {

        float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;

        alignas(16) const __m128 dst_quaternion_m128 = _mm_load_ps(dst_quaternion_addr_float);

        const float angle_half = angle * 0.5f;
        const float y = sin(angle_half);
        const float w = cos(angle_half);

        alignas(16) const __m128 y_y_y_y = { y, y, -y, -y };
        alignas(16) const __m128 w_w_w_w = { w, w, w, w };

        alignas(16) const __m128 a = _mm_mul_ps(w_w_w_w, _mm_load_ps(dst_quaternion_addr_float));
        alignas(16) const __m128 b = _mm_mul_ps(y_y_y_y, _mm_shuffle_ps(dst_quaternion_m128, dst_quaternion_m128, _MM_SHUFFLE(1, 0, 3, 2)));
        alignas(16) const __m128 c = _mm_add_ps(a, b);

        _mm_store_ps(dst_quaternion_addr_float, c);
      };



      void postRotY128 (void* dst_quaternion_addr, const float angle) {

        float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;

        alignas(16) const __m128 dst_quaternion_m128 = _mm_load_ps(dst_quaternion_addr_float);

        const float angle_half = angle * 0.5f;
        const float y = sin(angle_half);
        const float w = cos(angle_half);

        alignas(16) const __m128 y_y_y_y = { -y, y, y, -y };
        alignas(16) const __m128 w_w_w_w = { w, w, w, w };

        alignas(16) const __m128 a = _mm_mul_ps(w_w_w_w, _mm_load_ps(dst_quaternion_addr_float));
        alignas(16) const __m128 b = _mm_mul_ps(y_y_y_y, _mm_shuffle_ps(dst_quaternion_m128, dst_quaternion_m128, _MM_SHUFFLE(1, 0, 3, 2)));
        alignas(16) const __m128 c = _mm_add_ps(a, b);

        _mm_store_ps(dst_quaternion_addr_float, c);
      };



      void makeRotZ128 (void* data, const float angle) {

        float* _data = (float*) data;

        const float angle_half = angle * 0.5f;

        _data[0] = 0.0f;
        _data[1] = 0.0f;
        _data[2] = sin(angle_half);
        _data[3] = cos(angle_half);
      };



      void preRotZ128 (void* dst_quaternion_addr, const float angle) {

        float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;

        alignas(16) const __m128 dst_quaternion_m128 = _mm_load_ps(dst_quaternion_addr_float);

        const float angle_half = angle * 0.5f;
        const float z = sin(angle_half);
        const float w = cos(angle_half);

        alignas(16) const __m128 z_z_z_z = { -z, z, z, -z };
        alignas(16) const __m128 w_w_w_w = { w, w, w, w };

        alignas(16) const __m128 a = _mm_mul_ps(w_w_w_w, _mm_load_ps(dst_quaternion_addr_float));
        alignas(16) const __m128 b = _mm_mul_ps(z_z_z_z, _mm_shuffle_ps(dst_quaternion_m128, dst_quaternion_m128, _MM_SHUFFLE(2, 3, 0, 1)));
        alignas(16) const __m128 c = _mm_add_ps(a, b);

        _mm_store_ps(dst_quaternion_addr_float, c);
      };



      void postRotZ128 (void* dst_quaternion_addr, const float angle) {

        float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;

        alignas(16) const __m128 dst_quaternion_m128 = _mm_load_ps(dst_quaternion_addr_float);

        const float angle_half = angle * 0.5f;
        const float z = sin(angle_half);
        const float w = cos(angle_half);

        alignas(16) const __m128 z_z_z_z = { z, -z, z, -z };
        alignas(16) const __m128 w_w_w_w = { w, w, w, w };

        alignas(16) const __m128 a = _mm_mul_ps(w_w_w_w, _mm_load_ps(dst_quaternion_addr_float));
        alignas(16) const __m128 b = _mm_mul_ps(z_z_z_z, _mm_shuffle_ps(dst_quaternion_m128, dst_quaternion_m128, _MM_SHUFFLE(2, 3, 0, 1)));
        alignas(16) const __m128 c = _mm_add_ps(a, b);

        _mm_store_ps(dst_quaternion_addr_float, c);
      };



      // void mul0 (void* data0, void* data1) {

      //   alignas(16) const __m128 data0_128 = _mm_load_ps((float*) data0);
      //   alignas(16) const __m128 data1_128 = _mm_load_ps((float*) data1);

      //   alignas(16) const __m128 a = _mm_shuffle_ps(data1_128, data1_128, _MM_SHUFFLE(3, 2, 1, 0));
      //   alignas(16) const __m128 b = _mm_shuffle_ps(data1_128, data1_128, _MM_SHUFFLE(2, 3, 0, 1));
      //   alignas(16) const __m128 c = _mm_shuffle_ps(data1_128, data1_128, _MM_SHUFFLE(1, 0, 3, 2));

      //   alignas(16) const __m128 a_ = _mm_mul_ps(data0_128, a);
      //   alignas(16) const __m128 b_ = _mm_mul_ps(data0_128, b);
      //   alignas(16) const __m128 c_ = _mm_mul_ps(data0_128, c);
      //   alignas(16) const __m128 d = _mm_mul_ps(data0_128, data1_128);

      //   alignas(16) const __m128 e = _mm_hadd_ps(a_, b_);
      //   alignas(16) const __m128 f = _mm_hadd_ps(c_, d);
      //   alignas(16) const __m128 g = _mm_hadd_ps(e, f);

      //   _mm_store_ps((float*) data0, g);
      // };
    };
  };
};
