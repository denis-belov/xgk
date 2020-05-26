// try to use __forceinline



namespace XGK {

  namespace DATA {

    namespace VEC4 {

      // Element #3 of translation vector must be 0.

      extern void (* set) (void*, const float, const float, const float, const float);
      extern void (* add) (void*, void*);
      extern void (* adds) (void*, const float);
      extern void (* sub) (void*, void*);
      extern void (* subs) (void*, const float);
      extern void (* mul) (void*, void*);
      extern void (* muls) (void*, const float);
      extern void (* div) (void*, void*);
      extern void (* divs) (void*, const float);



      inline void copy (void*, void*);
      inline void reset (void*);
      inline void print (void*);

      inline void set32 (void*, const float, const float, const float, const float);
      inline void add32 (void*, void*);
      inline void adds32 (void*, const float);
      inline void sub32 (void*, void*);
      inline void subs32 (void*, const float);
      inline void mul32 (void*, void*);
      inline void muls32 (void*, const float);
      inline void div32 (void*, void*);
      inline void divs32 (void*, const float);

      inline void set128 (void*, const float, const float, const float, const float);
      inline void add128 (void*, void*);
      inline void adds128 (void*, const float);
      inline void sub128 (void*, void*);
      inline void subs128 (void*, const float);
      inline void mul128 (void*, void*);
      inline void muls128 (void*, const float);
      inline void div128 (void*, void*);
      inline void divs128 (void*, const float);

      inline void simd32 (void);
      inline void simd128 (void);
    };



    namespace QUAT {

      extern void (* premul) (void*, void*);
      extern void (* postmul) (void*, void*);
      extern void (* makeRot) (void*, void*, const float);
      extern void (* preRot) (void*, void*, const float);
      extern void (* postRot) (void*, void*, const float);
      extern void (* makeRotX) (void*, const float);
      extern void (* preRotX) (void*, const float);
      extern void (* postRotX) (void*, const float);
      extern void (* makeRotY) (void*, const float);
      extern void (* preRotY) (void*, const float);
      extern void (* postRotY) (void*, const float);
      extern void (* makeRotZ) (void*, const float);
      extern void (* preRotZ) (void*, const float);
      extern void (* postRotZ) (void*, const float);


      inline void ident (void*);
      inline float len (void* data);
      inline void norm (void* data);

      inline void premul32 (void*, void*);
      inline void postmul32 (void*, void*);
      inline void makeRot32 (void*, void*, const float);
      inline void preRot32 (void*, void*, const float);
      inline void postRot32 (void*, void*, const float);
      inline void makeRotX32 (void*, const float);
      inline void preRotX32 (void*, const float);
      inline void postRotX32 (void*, const float);
      inline void makeRotY32 (void*, const float);
      inline void preRotY32 (void*, const float);
      inline void postRotY32 (void*, const float);
      inline void makeRotZ32 (void*, const float);
      inline void preRotZ32 (void*, const float);
      inline void postRotZ32 (void*, const float);

      inline void premul128 (void*, void*);
      inline void postmul128 (void*, void*);
      inline void makeRot128 (void*, void*, const float);
      inline void preRot128 (void*, void*, const float);
      inline void postRot128 (void*, void*, const float);
      inline void makeRotX128 (void*, const float);
      inline void preRotX128 (void*, const float);
      inline void postRotX128 (void*, const float);
      inline void makeRotY128 (void*, const float);
      inline void preRotY128 (void*, const float);
      inline void postRotY128 (void*, const float);
      inline void makeRotZ128 (void*, const float);
      inline void preRotZ128 (void*, const float);
      inline void postRotZ128 (void*, const float);

      inline void simd32 (void);
      inline void simd128 (void);
    };



    namespace MAT4 {

      // Elements #3, #7, #11 of transformation matrix must be 0.
      // Element #15 of transformation matrix must be 1.

      extern void (* set) (void*, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float);
      extern void (* premul) (void*, void*);
      extern void (* postmul) (void*, void*);
      extern void (* makeTrans) (void*, void*);
      extern void (* preTrans) (void*, void*);
      extern void (* postTrans) (void*, void*);
      extern void (* makeTransValue) (void*, void*, const float);
      extern void (* preTransValue) (void*, void*, const float);
      extern void (* postTransValue) (void*, void*, const float);
      extern void (* makeRotQuat) (void*, void*);
      extern void (* preRotQuat) (void*, void*);
      extern void (* postRotQuat) (void*, void*);
      extern void (* transp) (void*);
      extern void (* invns) (void*);
      extern void (* makeProjPersp) (void*, const float, const float, const float, const float, const float);



      inline void copy (void*, void*);
      inline void reset (void*);
      inline void ident (void*);
      inline void print (void*);

      inline void set32 (void*, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float);
      inline void premul32 (void*, void*);
      inline void postmul32 (void*, void*);
      inline void makeTrans32 (void*, void*);
      inline void preTrans32 (void*, void*);
      inline void postTrans32 (void*, void*);
      inline void makeTransValue32 (void*, void*, const float);
      inline void preTransValue32 (void*, void*, const float);
      inline void postTransValue32 (void*, void*, const float);
      inline void makeRotQuat32 (void*, void*);
      inline void preRotQuat32 (void*, void*);
      inline void postRotQuat32 (void*, void*);
      inline void transp32 (void*);
      inline void invns32 (void*);
      inline void makeProjPersp32 (void*, const float, const float, const float, const float, const float);

      inline void set128 (void*, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float, const float);
      inline void premul128 (void*, void*);
      inline void postmul128 (void*, void*);
      inline void makeTrans128 (void*, void*);
      inline void preTrans128 (void*, void*);
      inline void postTrans128 (void*, void*);
      inline void makeTransValue128 (void*, void*, const float);
      inline void preTransValue128 (void*, void*, const float);
      inline void postTransValue128 (void*, void*, const float);
      inline void makeRotQuat128 (void*, void*);
      inline void preRotQuat128 (void*, void*);
      inline void postRotQuat128 (void*, void*);
      inline void transp128 (void*);
      inline void invns128 (void*);
      inline void makeProjPersp128 (void*, const float, const float, const float, const float, const float);

      inline void simd32 (void);
      inline void simd128 (void);
    };



    inline void simd32 (void) {

      VEC4::simd32();
      QUAT::simd32();
      MAT4::simd32();
    };

    inline void simd128 (void) {

      VEC4::simd128();
      QUAT::simd128();
      MAT4::simd128();
    };
  };
};
