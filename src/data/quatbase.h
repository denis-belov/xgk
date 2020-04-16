namespace XGK {

  namespace DATA {

    // #pragma pack(push, 16)
    //   union Vec4 {

    //     float f32[4];

    //     #ifdef XGK_DATA_MACRO_SSE
    //       __m128 f128;
    //     #endif
    //   };
    // #pragma pack(pop)



    namespace VEC4 {

      #define F32(item) ((float*) item)
      #define F128(item) ((__m128*) item)

      #if defined(__GNUC__) || defined(__clang__) || defined(__MINGW64__) || defined(__EMSCRIPTEN__)
        #define GET_F32(item, index) item[index]
      #elif defined(_MSC_VER)
        #define GET_F32(item, index) item.m128_f32[index]
      #endif

      #define SET32(data, x, y, z, w)\
        data[0] = x;\
        data[1] = y;\
        data[2] = z;\
        data[3] = w;

      #ifdef XGK_DATA_MACRO_SSE
        #define SET128(data, x, y, z, w) *data = _mm_setr_ps(x, y, z, w);
      #endif



      const float FLOAT_SIZE_4 = sizeof(float) * 4;



      void (* add) (void*, void*) = nullptr;
      void (* adds) (void*, const float) = nullptr;
      void (* sub) (void*, void*) = nullptr;
      void (* subs) (void*, const float) = nullptr;
      void (* mul) (void*, void*) = nullptr;
      void (* muls) (void*, const float) = nullptr;
      void (* div) (void*, void*) = nullptr;
      void (* divs) (void*, const float) = nullptr;



      // COPY
      ///////
      ///////

      inline void copy (void* data0, void* data1) {

        memcpy(data0, data1, FLOAT_SIZE_4);
      };

      ///////
      ///////
      ///////



      // RESET
      ////////
      ////////

      inline void reset (void* data) {

        memset(data, 0, FLOAT_SIZE_4);
      };

      ///////
      ///////
      ///////



      // SET
      //////
      //////

      inline void set32 (void* data, const float x, const float y, const float z, const float w) {

        SET32(F32(data), x, y, z, w)
      };

      #ifdef XGK_DATA_MACRO_SSE
        inline void set128 (void* data, const float x, const float y, const float z, const float w) {

          SET128(F128(data), x, y, z, w)
        };
      #endif

      ///////
      ///////
      ///////



      // ADD
      //////
      //////

      inline void add32 (void* data0, void* data1) {

        F32(data0)[0] += F32(data1)[0];
        F32(data0)[1] += F32(data1)[1];
        F32(data0)[2] += F32(data1)[2];
        F32(data0)[3] += F32(data1)[3];
      };

      #ifdef XGK_DATA_MACRO_SSE
        inline void add128 (void* data0, void* data1) {

          *F128(data0) = _mm_add_ps(*F128(data0), *F128(data1));
        };
      #endif

      inline void adds32 (void* data, const float s) {

        F32(data)[0] += s;
        F32(data)[1] += s;
        F32(data)[2] += s;
        F32(data)[3] += s;
      };

      #ifdef XGK_DATA_MACRO_SSE
        inline void adds128 (void* data, const float s) {

          *F128(data) = _mm_add_ps(*F128(data), _mm_set1_ps(s));
        };
      #endif

      ///////
      ///////
      ///////



      // SUBTRACT
      ///////////
      ///////////

      inline void sub32 (void* data0, void* data1) {

        F32(data0)[0] -= F32(data1)[0];
        F32(data0)[1] -= F32(data1)[1];
        F32(data0)[2] -= F32(data1)[2];
        F32(data0)[3] -= F32(data1)[3];
      };

      #ifdef XGK_DATA_MACRO_SSE
        inline void sub128 (void* data0, void* data1) {

          *F128(data0) = _mm_sub_ps(*F128(data0), *F128(data1));
        };
      #endif

      inline void subs32 (void* data, const float s) {

        F32(data)[0] -= s;
        F32(data)[1] -= s;
        F32(data)[2] -= s;
        F32(data)[3] -= s;
      };

      #ifdef XGK_DATA_MACRO_SSE
        inline void subs128 (void* data, const float s) {

          *F128(data) = _mm_sub_ps(*F128(data), _mm_set1_ps(s));
        };
      #endif

      ///////
      ///////
      ///////



      // MULTIPLY
      ///////////
      ///////////

      inline void mul32 (void* data0, void* data1) {

        F32(data0)[0] *= F32(data1)[0];
        F32(data0)[1] *= F32(data1)[1];
        F32(data0)[2] *= F32(data1)[2];
        F32(data0)[3] *= F32(data1)[3];
      };

      #ifdef XGK_DATA_MACRO_SSE
        inline void mul128 (void* data0, void* data1) {

          *F128(data0) = _mm_mul_ps(*F128(data0), *F128(data1));
        };
      #endif

      inline void muls32 (void* data, const float s) {

        F32(data)[0] *= s;
        F32(data)[1] *= s;
        F32(data)[2] *= s;
        F32(data)[3] *= s;
      };

      #ifdef XGK_DATA_MACRO_SSE
        inline void muls128 (void* data, const float s) {

          *F128(data) = _mm_mul_ps(*F128(data), _mm_set1_ps(s));
        };
      #endif

      ///////
      ///////
      ///////



      // DIVIDE
      /////////
      /////////

      inline void div32 (void* data0, void* data1) {

        F32(data0)[0] /= F32(data1)[0];
        F32(data0)[1] /= F32(data1)[1];
        F32(data0)[2] /= F32(data1)[2];
        F32(data0)[3] /= F32(data1)[3];
      };

      #ifdef XGK_DATA_MACRO_SSE
        inline void div128 (void* data0, void* data1) {

          *F128(data0) = _mm_div_ps(*F128(data0), *F128(data1));
        };
      #endif

      inline void divs32 (void* data, const float s) {

        F32(data)[0] /= s;
        F32(data)[1] /= s;
        F32(data)[2] /= s;
        F32(data)[3] /= s;
      };

      #ifdef XGK_DATA_MACRO_SSE
        inline void divs128 (void* data, const float s) {

          *F128(data) = _mm_div_ps(*F128(data), _mm_set1_ps(s));
        };
      #endif

      ///////
      ///////
      ///////



      // SIMD
      ///////
      ///////

      // There is no way to have common 'set' function pointer, because each of 'set32', 'set128' is different in the arguments number.
      // So, it's preferable to use 'set32' for portability.

      inline void simd32 () {

        add = add32;
        adds = adds32;
        sub = sub32;
        subs = subs32;
        mul = mul32;
        muls = muls32;
        div = div32;
        divs = divs32;
      };

      #ifdef XGK_DATA_MACRO_SSE
        inline void simd128 () {

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
        void print (void* data) {

          printf("%f %f %f %f\n", F32(data)[0], F32(data)[1], F32(data)[2], F32(data)[3]);
        };
      #endif



      #ifdef XGK_DATA_MACRO_SSE
        #undef SET128
      #endif

      #undef SET32
      #undef GET_F32
      #undef F128
      #undef F32

      /////
      /////
      /////
    };
  };
};




struct QuatBase : Vec4Base {
  inline static void (* mulQ_ptr) (
    QuatBase*,

    const QuatBase&, const QuatBase&
  );

  inline static void (* premul_ptr) (
    QuatBase*,

    const QuatBase&
  );

  inline static void (* postmul_ptr) (
    QuatBase*,

    const QuatBase&
  );



  QuatBase () {
    set_ptr(
      this,

      0.0f, 0.0f, 0.0f, 1.0f
    );
  };



  // MULIPLY QUATERNIONS static
  /////////////////////////////
  /////////////////////////////

  #define a q1.data._32
  #define b q2.data._32

  inline static void multiplyQuaternions32 (
    QuatBase* q,

    const QuatBase& q1, const QuatBase& q2
  ) {
    set32(
      q,

      (a[0] * b[3]) + (a[3] * b[0]) + (a[1] * b[2]) - (a[2] * b[1]),
      (a[1] * b[3]) + (a[3] * b[1]) + (a[2] * b[0]) - (a[0] * b[2]),
      (a[2] * b[3]) + (a[3] * b[2]) + (a[0] * b[1]) - (a[1] * b[0]),
      (a[3] * b[3]) - (a[0] * b[0]) - (a[1] * b[1]) - (a[2] * b[2])
    );
  };

  #undef b
  #undef a

  #define a q1.data._128
  #define b q2.data._128.m128_f32

  inline static void multiplyQuaternions128 (
    QuatBase* q,

    const QuatBase& q1, const QuatBase& q2
  ) {
    q->data._128 = _mm_setr_ps(
      _mm_dp_ps(a, _mm_setr_ps(b[3], b[2], -b[1], b[0]), 0xff).m128_f32[0],
      _mm_dp_ps(a, _mm_setr_ps(-b[2], b[3], b[0], b[1]), 0xff).m128_f32[0],
      _mm_dp_ps(a, _mm_setr_ps(b[1], -b[0], b[3], b[2]), 0xff).m128_f32[0],
      _mm_dp_ps(a, _mm_setr_ps(-b[0], -b[1], -b[2], b[3]), 0xff).m128_f32[0]
    );
  };

  #undef b
  #undef a

  ///////
  ///////
  ///////



  // PREMULTIPLY static
  /////////////////////
  /////////////////////

  #define a tq->data._32
  #define b q.data._32

  inline static void premultiply32 (
    QuatBase* tq,

    const QuatBase& q
  ) {
    set32(
      tq,

      (a[0] * b[3]) + (a[3] * b[0]) + (a[1] * b[2]) - (a[2] * b[1]),
      (a[1] * b[3]) + (a[3] * b[1]) + (a[2] * b[0]) - (a[0] * b[2]),
      (a[2] * b[3]) + (a[3] * b[2]) + (a[0] * b[1]) - (a[1] * b[0]),
      (a[3] * b[3]) - (a[0] * b[0]) - (a[1] * b[1]) - (a[2] * b[2])
    );
  };

  #undef b
  #undef a

  #define a tq->data._128
  #define b q.data._128.m128_f32

  inline static void premultiply128 (
    QuatBase* tq,

    const QuatBase& q
  ) {
    const float x = _mm_dp_ps(a, _mm_setr_ps(b[3], b[2], -b[1], b[0]), 0xff).m128_f32[0];
    const float y = _mm_dp_ps(a, _mm_setr_ps(-b[2], b[3], b[0], b[1]), 0xff).m128_f32[0];
    const float z = _mm_dp_ps(a, _mm_setr_ps(b[1], -b[0], b[3], b[2]), 0xff).m128_f32[0];
    const float w = _mm_dp_ps(a, _mm_setr_ps(-b[0], -b[1], -b[2], b[3]), 0xff).m128_f32[0];

    tq->data._128 = _mm_setr_ps(x, y, z, w);
  };

  #undef b
  #undef a

  ///////
  ///////
  ///////



  // POSTMULTIPLY static
  //////////////////////
  //////////////////////

  #define a q.data._32
  #define b tq->data._32

  inline static void postmultiply32 (
    QuatBase* tq,

    const QuatBase& q
  ) {
    set32(
      tq,

      (a[0] * b[3]) + (a[3] * b[0]) + (a[1] * b[2]) - (a[2] * b[1]),
      (a[1] * b[3]) + (a[3] * b[1]) + (a[2] * b[0]) - (a[0] * b[2]),
      (a[2] * b[3]) + (a[3] * b[2]) + (a[0] * b[1]) - (a[1] * b[0]),
      (a[3] * b[3]) - (a[0] * b[0]) - (a[1] * b[1]) - (a[2] * b[2])
    );
  };

  #undef b
  #undef a

  #define a q.data._128
  #define b tq->data._128.m128_f32

  inline static void postmultiply128 (
    QuatBase* tq,

    const QuatBase& q
  ) {
    const float x = _mm_dp_ps(a, _mm_setr_ps(b[3], b[2], -b[1], b[0]), 0xff).m128_f32[0];
    const float y = _mm_dp_ps(a, _mm_setr_ps(-b[2], b[3], b[0], b[1]), 0xff).m128_f32[0];
    const float z = _mm_dp_ps(a, _mm_setr_ps(b[1], -b[0], b[3], b[2]), 0xff).m128_f32[0];
    const float w = _mm_dp_ps(a, _mm_setr_ps(-b[0], -b[1], -b[2], b[3]), 0xff).m128_f32[0];

    tq->data._128 = _mm_setr_ps(x, y, z, w);
  };

  #undef b
  #undef a

  ///////
  ///////
  ///////



  // SIMD static
  //////////////
  //////////////

  static void SIMD32 () {
    set_ptr = set32;
    add_ptr = add32;
    addS_ptr = addScalar32;
    sub_ptr = subtract32;
    subS_ptr = subtractScalar32;
    mul_ptr = multiply32;
    mulS_ptr = multiplyScalar32;
    div_ptr = divide32;
    divS_ptr = divideScalar32;
    mulQ_ptr = multiplyQuaternions32;
    premul_ptr = premultiply32;
    postmul_ptr = postmultiply32;
  };

  static void SIMD128 () {
    set_ptr = set128;
    add_ptr = add128;
    addS_ptr = addScalar128;
    sub_ptr = subtract128;
    subS_ptr = subtractScalar128;
    mul_ptr = multiply128;
    mulS_ptr = multiplyScalar128;
    div_ptr = divide128;
    divS_ptr = divideScalar128;
    mulQ_ptr = multiplyQuaternions128;
    premul_ptr = premultiply128;
    postmul_ptr = postmultiply128;
  };

  ///////
  ///////
  ///////



  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////


  // MULTIPLY
  ///////////
  ///////////

  inline void mulQ (QuatBase& q1, QuatBase& q2) {
    mulQ_ptr(
      this,

      q1, q2
    );
  };

  ///////
  ///////
  ///////



  // PREMULTIPLY
  //////////////
  //////////////

  inline void premul (QuatBase& q) {
    premul_ptr(
      this,

      q
    );
  };

  ///////
  ///////
  ///////



  // POSTMULTIPLY
  ///////////////
  ///////////////

  inline void postmul (QuatBase& q) {
    postmul_ptr(
      this,

      q
    );
  };

  ///////
  ///////
  ///////



  /////// MAKE ROTATION
  /////////////////////
  /////////////////////

  inline void makeRotation (Vec4& axis, const float angle) {
    const float ang = angle * 0.5f;
    const float sin_ = sin(ang);

    set_ptr(this, axis.data._32[0] * sin_, axis.data._32[1] * sin_, axis.data._32[2] * sin_, cos(ang));
  }

  inline void makeRotationX (const float angle) {
    const float ang = angle * 0.5f;

    set_ptr(this, sin(ang), 0.0f, 0.0f, cos(ang));
  }

  inline void makeRotationY (const float angle) {
    const float ang = angle * 0.5;

    set_ptr(this, 0.0f, sin(ang), 0.0f, cos(ang));
  }

  inline void makeRotationZ (const float angle) {
    const float ang = angle * 0.5;

    set_ptr(this, 0.0f, 0.0f, sin(ang), cos(ang));
  }

  ///////
  ///////
  ///////
};
