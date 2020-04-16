#include <immintrin.h>

namespace XGK {

  namespace DATA {

    namespace VEC4 {

      void set128 (void* data, const float x, const float y, const float z, const float w) {

        _mm_store_ps((float*) data, _mm_setr_ps(x, y, z, w));
      };



      void add128 (void* data0, void* data1) {

        alignas(16) __m128 _data0 = *((__m128*) data0);
        alignas(16) __m128 _data1 = *((__m128*) data1);

        _mm_store_ps((float*) data0, _mm_add_ps(_data0, _data1));
      };



      void adds128 (void* data, const float s) {

        alignas(16) __m128 _data = *((__m128*) data);

        _mm_store_ps((float*) data, _mm_add_ps(_data, _mm_set1_ps(s)));
      };



      void sub128 (void* data0, void* data1) {

        alignas(16) __m128 _data0 = *((__m128*) data0);
        alignas(16) __m128 _data1 = *((__m128*) data1);

        _mm_store_ps((float*) data0, _mm_sub_ps(_data0, _data1));
      };



      void subs128 (void* data, const float s) {

        alignas(16) __m128 _data = *((__m128*) data);

        _mm_store_ps((float*) data, _mm_sub_ps(_data, _mm_set1_ps(s)));
      };



      void mul128 (void* data0, void* data1) {

        alignas(16) __m128 _data0 = *((__m128*) data0);
        alignas(16) __m128 _data1 = *((__m128*) data1);

        _mm_store_ps((float*) data0, _mm_mul_ps(_data0, _data1));
      };



      void muls128 (void* data, const float s) {

        alignas(16) __m128 _data = *((__m128*) data);

        _mm_store_ps((float*) data, _mm_mul_ps(_data, _mm_set1_ps(s)));
      };



      void div128 (void* data0, void* data1) {

        alignas(16) __m128 _data0 = *((__m128*) data0);
        alignas(16) __m128 _data1 = *((__m128*) data1);

        _mm_store_ps((float*) data0, _mm_div_ps(_data0, _data1));
      };



      void divs128 (void* data, const float s) {

        alignas(16) __m128 _data = *((__m128*) data);

        _mm_store_ps((float*) data, _mm_div_ps(_data, _mm_set1_ps(s)));
      };
    };
  };
};
