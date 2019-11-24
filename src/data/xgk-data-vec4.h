namespace XGK {
  namespace VEC4 {
    // column-major 4x4 matrix

    #if defined(__GNUC__) || defined(__clang__) || defined(__MINGW64__) || defined(__EMSCRIPTEN__)
      #define GET_F32(item, index) item[index]
    #elif defined(_MSC_VER)
      #define GET_F32(item, index) item.m128_f32[index]
    #endif

    #define SET32(m, x, y, z, w)\
      m->f32[0] = x;\
      m->f32[1] = y;\
      m->f32[2] = z;\
      m->f32[3] = w;

    #ifdef MACRO_DATA_WRAPPERS_SSE
      #define SET128(m, x, y, z, w) m->f128 = _mm_setr_ps(x, y, z, w);
    #endif



    static const float CONST_VEC4_NULL[4] = { 0.0f, 0.0f, 0.0f, 0.0f };



    void (* add) (Vec4*, Vec4*) = nullptr;
    void (* adds) (Vec4*, const float) = nullptr;
    void (* sub) (Vec4*, Vec4*) = nullptr;
    void (* subs) (Vec4*, const float) = nullptr;
    void (* mul) (Vec4*, Vec4*) = nullptr;
    void (* muls) (Vec4*, const float) = nullptr;
    void (* div) (Vec4*, Vec4*) = nullptr;
    void (* divs) (Vec4*, const float) = nullptr;



    // COPY
    ///////
    ///////

    static inline void copy (Vec4* m0, Vec4* m1) {
      memcpy(m0, m1, CONST_FLOAT_SIZE_4);
    };

    ///////
    ///////
    ///////



    // RESET
    ////////
    ////////

    static inline void reset (Vec4* m0) {
      memcpy(m0, CONST_VEC4_NULL, CONST_FLOAT_SIZE_4);
    };

    ///////
    ///////
    ///////



    // SET
    //////
    //////

    static inline void set32 (Vec4* v, const float x, const float y, const float z, const float w) {
      SET32(v, x, y, z, w)
    };

    #ifdef MACRO_DATA_WRAPPERS_SSE
      static inline void set128 (Vec4* v, const float x, const float y, const float z, const float w) {
        SET128(v, x, y, z, w)
      };
    #endif

    ///////
    ///////
    ///////



    // ADD
    //////
    //////

    static inline void add32 (Vec4* v0, Vec4* v1) {
      v0->f32[0] += v1->f32[0];
      v0->f32[1] += v1->f32[1];
      v0->f32[2] += v1->f32[2];
      v0->f32[3] += v1->f32[3];
    };

    static inline void add128 (Vec4* v0, Vec4* v1) {
      v0->f128 = _mm_add_ps(v0->f128, v1->f128);
    };

    static inline void adds32 (Vec4* v, const float s) {
      v->f32[0] += s;
      v->f32[1] += s;
      v->f32[2] += s;
      v->f32[3] += s;
    };

    static inline void adds128 (Vec4* v, const float s) {
      v->f128 = _mm_add_ps(v->f128, _mm_set1_ps(s));
    };

    ///////
    ///////
    ///////



    // SUBTRACT
    ///////////
    ///////////

    static inline void sub32 (Vec4* v0, Vec4* v1) {
      v0->f32[0] -= v1->f32[0];
      v0->f32[1] -= v1->f32[1];
      v0->f32[2] -= v1->f32[2];
      v0->f32[3] -= v1->f32[3];
    };

    static inline void sub128 (Vec4* v0, Vec4* v1) {
      v0->f128 = _mm_sub_ps(v0->f128, v1->f128);
    };

    static inline void subs32 (Vec4* v, const float s) {
      v->f32[0] -= s;
      v->f32[1] -= s;
      v->f32[2] -= s;
      v->f32[3] -= s;
    };

    static inline void subs128 (Vec4* v, const float s) {
      v->f128 = _mm_sub_ps(v->f128, _mm_set1_ps(s));
    };

    ///////
    ///////
    ///////



    // MULTIPLY
    ///////////
    ///////////

    static inline void mul32 (Vec4* v0, Vec4* v1) {
      v0->f32[0] *= v1->f32[0];
      v0->f32[1] *= v1->f32[1];
      v0->f32[2] *= v1->f32[2];
      v0->f32[3] *= v1->f32[3];
    };

    static inline void mul128 (Vec4* v0, Vec4* v1) {
      v0->f128 = _mm_mul_ps(v0->f128, v1->f128);
    };

    static inline void muls32 (Vec4* v, const float s) {
      v->f32[0] *= s;
      v->f32[1] *= s;
      v->f32[2] *= s;
      v->f32[3] *= s;
    };

    static inline void muls128 (Vec4* v, const float s) {
      v->f128 = _mm_mul_ps(v->f128, _mm_set1_ps(s));
    };

    ///////
    ///////
    ///////



    // DIVIDE
    /////////
    /////////

    static inline void div32 (Vec4* v0, Vec4* v1) {
      v0->f32[0] /= v1->f32[0];
      v0->f32[1] /= v1->f32[1];
      v0->f32[2] /= v1->f32[2];
      v0->f32[3] /= v1->f32[3];
    };

    static inline void div128 (Vec4* v0, Vec4* v1) {
      v0->f128 = _mm_div_ps(v0->f128, v1->f128);
    };

    static inline void divs32 (Vec4* v, const float s) {
      v->f32[0] /= s;
      v->f32[1] /= s;
      v->f32[2] /= s;
      v->f32[3] /= s;
    };

    static inline void divs128 (Vec4* v, const float s) {
      v->f128 = _mm_div_ps(v->f128, _mm_set1_ps(s));
    };

    ///////
    ///////
    ///////



    // SIMD
    ///////
    ///////

    // There is no way to have common 'set' function pointer, because each of 'set32', 'set128' is different in the arguments number.
    // So, it's preferable to use 'set32' for portability.

    static inline void simd32 () {
      add = add32;
      adds = adds32;
      sub = sub32;
      subs = subs32;
      mul = mul32;
      muls = muls32;
      div = div32;
      divs = divs32;
    };

    #ifdef MACRO_DATA_WRAPPERS_SSE
      static inline void simd128 () {
        add = add128;
        adds = adds128;
        sub = sub128;
        subs = subs128;
        mul = mul128;
        muls = muls128;
        div = div128;
        divs = divs128;
      };
    #endif



    #ifdef DEBUG
      void print (Vec4* v) {
        printf("%f %f %f %f\n", v->f32[0], v->f32[1], v->f32[2], v->f32[3]);
      };
    #endif



    #ifdef MACRO_DATA_WRAPPERS_SSE
      #undef SET128
    #endif

    #undef SET32

    #undef GET_F32

    /////
    /////
    /////
  };
};
