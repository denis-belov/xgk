#include <stdint.h>
#include <string>



namespace XGK {

  namespace DATA {

    namespace QUAT {

      const uint8_t FLOAT_SIZE_4 = sizeof(float) * 4;
      alignas(16) const float CONST_IDENT[4] = { 0.0f, 0.0f, 0.0f, 1.0f };



      void (* premul) (void*, void*);
      void (* postmul) (void*, void*);
      void (* makeRot) (void*, void*, const float);
      void (* preRot) (void*, void*, const float);
      void (* postRot) (void*, void*, const float);
      void (* makeRotX) (void*, const float);
      void (* preRotX) (void*, const float);
      void (* postRotX) (void*, const float);
      void (* makeRotY) (void*, const float);
      void (* preRotY) (void*, const float);
      void (* postRotY) (void*, const float);
      void (* makeRotZ) (void*, const float);
      void (* preRotZ) (void*, const float);
      void (* postRotZ) (void*, const float);



      void premul32 (void*, void*);
      void postmul32 (void*, void*);
      void makeRot32 (void*, void*, const float);
      void preRot32 (void*, void*, const float);
      void postRot32 (void*, void*, const float);
      void makeRotX32 (void*, const float);
      void preRotX32 (void*, const float);
      void postRotX32 (void*, const float);
      void makeRotY32 (void*, const float);
      void preRotY32 (void*, const float);
      void postRotY32 (void*, const float);
      void makeRotZ32 (void*, const float);
      void preRotZ32 (void*, const float);
      void postRotZ32 (void*, const float);

      void premul128 (void*, void*);
      void postmul128 (void*, void*);
      void makeRot128 (void*, void*, const float);
      void preRot128 (void*, void*, const float);
      void postRot128 (void*, void*, const float);
      void makeRotX128 (void*, const float);
      void preRotX128 (void*, const float);
      void postRotX128 (void*, const float);
      void makeRotY128 (void*, const float);
      void preRotY128 (void*, const float);
      void postRotY128 (void*, const float);
      void makeRotZ128 (void*, const float);
      void preRotZ128 (void*, const float);
      void postRotZ128 (void*, const float);



      void ident (void* data) {

        memcpy(data, CONST_IDENT, FLOAT_SIZE_4);
      };



      void simd32 (void) {

        premul = premul32;
        postmul = postmul32;
        makeRot = makeRot32;
        preRot = preRot32;
        postRot = postRot32;
        makeRotX = makeRotX32;
        preRotX = preRotX32;
        postRotX = postRotX32;
        makeRotY = makeRotY32;
        preRotY = preRotY32;
        postRotY = postRotY32;
        makeRotZ = makeRotZ32;
        preRotZ = preRotZ32;
        postRotZ = postRotZ32;
      };

      void simd128 (void) {

        premul = premul128;
        postmul = postmul128;
        makeRot = makeRot128;
        preRot = preRot128;
        postRot = postRot128;
        makeRotX = makeRotX128;
        preRotX = preRotX128;
        postRotX = postRotX128;
        makeRotY = makeRotY128;
        preRotY = preRotY128;
        postRotY = postRotY128;
        makeRotZ = makeRotZ128;
        preRotZ = preRotZ128;
        postRotZ = postRotZ128;
      };
    };
  };
};
