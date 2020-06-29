// These functions can be used with float[4] and __m128 data storages (4-dim vectors, quaternions).
// Data should be aligned with 16-byte alignment for better performance.

#include <cstdint>
#include <string.h>
#include <cstdio>



namespace XGK {

  namespace DATA {

    namespace VEC4 {

      const uint8_t FLOAT_SIZE_4 = sizeof(float) * 4;



      void (* set) (void*, const float, const float, const float, const float);
      void (* add) (void*, void*);
      void (* adds) (void*, const float);
      void (* sub) (void*, void*);
      void (* subs) (void*, const float);
      void (* mul) (void*, void*);
      void (* muls) (void*, const float);
      void (* div) (void*, void*);
      void (* divs) (void*, const float);



      void set32 (void*, const float, const float, const float, const float);
      void add32 (void*, void*);
      void adds32 (void*, const float);
      void sub32 (void*, void*);
      void subs32 (void*, const float);
      void mul32 (void*, void*);
      void muls32 (void*, const float);
      void div32 (void*, void*);
      void divs32 (void*, const float);

      void set128 (void*, const float, const float, const float, const float);
      void add128 (void*, void*);
      void adds128 (void*, const float);
      void sub128 (void*, void*);
      void subs128 (void*, const float);
      void mul128 (void*, void*);
      void muls128 (void*, const float);
      void div128 (void*, void*);
      void divs128 (void*, const float);



      void copy (void* data0, void* data1) {

        memcpy(data0, data1, FLOAT_SIZE_4);
      };



      void reset (void* data) {

        memset(data, 0, FLOAT_SIZE_4);
      };



      void simd32 (void) {

        set = set32;
        add = add32;
        adds = adds32;
        sub = sub32;
        subs = subs32;
        mul = mul32;
        muls = muls32;
        div = div32;
        divs = divs32;
      };

      void simd128 (void) {

        set = set128;
        add = add128;
        adds = adds128;
        sub = sub128;
        subs = subs128;
        mul = mul128;
        muls = muls128;
        div = div128;
        divs = divs128;
      };



      void print (void* data) {

        float* _data = (float*) data;

        printf("%f %f %f %f\n", _data[0], _data[1], _data[2], _data[3]);
      };
    };
  };
};
