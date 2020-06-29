// column-major 4x4 matrix

#include <cstdint>
#include <string.h>
#include <cstdio>



namespace XGK {

  namespace DATA {

    namespace MAT4 {

      const uint8_t FLOAT_SIZE_16 = sizeof(float) * 16;

      alignas(16) const float IDENT[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
      };



      void (* set) (void*, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float);
      void (* premul) (void*, void*);
      void (* postmul) (void*, void*);
      void (* makeTrans) (void*, void*);
      void (* preTrans) (void*, void*);
      void (* postTrans) (void*, void*);
      void (* makeTransValue) (void*, void*, const float);
      void (* preTransValue) (void*, void*, const float);
      void (* postTransValue) (void*, void*, const float);
      void (* makeRotQuat) (void*, void*);
      void (* preRotQuat) (void*, void*);
      void (* postRotQuat) (void*, void*);
      void (* transp) (void*);
      void (* invns) (void*);
      void (* makeProjPersp) (void*, const float, const float, const float, const float, const float);



      void set32 (void*, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float);
      void premul32 (void*, void*);
      void postmul32 (void*, void*);
      void makeTrans32 (void*, void*);
      void preTrans32 (void*, void*);
      void postTrans32 (void*, void*);
      void makeTransValue32 (void*, void*, const float);
      void preTransValue32 (void*, void*, const float);
      void postTransValue32 (void*, void*, const float);
      void makeRotQuat32 (void*, void*);
      void preRotQuat32 (void*, void*);
      void postRotQuat32 (void*, void*);
      void transp32 (void*);
      void invns32 (void*);
      void makeProjPersp32 (void*, const float, const float, const float, const float, const float);

      void set128 (void*, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float);
      void premul128 (void*, void*);
      void postmul128 (void*, void*);
      void makeTrans128 (void*, void*);
      void preTrans128 (void*, void*);
      void postTrans128 (void*, void*);
      void makeTransValue128 (void*, void*, const float);
      void preTransValue128 (void*, void*, const float);
      void postTransValue128 (void*, void*, const float);
      void makeRotQuat128 (void*, void*);
      void preRotQuat128 (void*, void*);
      void postRotQuat128 (void*, void*);
      void transp128 (void*);
      void invns128 (void*);
      void makeProjPersp128 (void*, const float, const float, const float, const float, const float);



      void copy (void* data0, void* data1) {

        memcpy(data0, data1, FLOAT_SIZE_16);
      };



      void reset (void* data) {

        memset(data, 0, FLOAT_SIZE_16);
      };



      void ident (void* data) {

        memcpy(data, IDENT, FLOAT_SIZE_16);
      };



      void simd32 (void) {

        set = set32;
        premul = premul32;
        postmul = postmul32;
        makeTrans = makeTrans32;
        preTrans = preTrans32;
        postTrans = postTrans32;
        makeTransValue = makeTransValue32;
        preTransValue = preTransValue32;
        postTransValue = postTransValue32;
        makeRotQuat = makeRotQuat32;
        preRotQuat = preRotQuat32;
        postRotQuat = postRotQuat32;
        transp = transp32;
        invns = invns32;
        makeProjPersp = makeProjPersp32;
      };

      void simd128 (void) {

        set = set128;
        premul = premul128;
        postmul = postmul128;
        makeTrans = makeTrans128;
        preTrans = preTrans128;
        postTrans = postTrans128;
        makeTransValue = makeTransValue128;
        preTransValue = preTransValue128;
        postTransValue = postTransValue128;
        makeRotQuat = makeRotQuat128;
        preRotQuat = preRotQuat128;
        postRotQuat = postRotQuat128;
        transp = transp128;
        invns = invns128;
        makeProjPersp = makeProjPersp128;
      };

      // simd256



      void print (void* data) {

        float* _data = (float*) data;

        printf("%f %f %f %f\n", _data[0], _data[4], _data[8] , _data[12]);
        printf("%f %f %f %f\n", _data[1], _data[5], _data[9] , _data[13]);
        printf("%f %f %f %f\n", _data[2], _data[6], _data[10], _data[14]);
        printf("%f %f %f %f\n", _data[3], _data[7], _data[11], _data[15]);
      };
    };
  };
};
