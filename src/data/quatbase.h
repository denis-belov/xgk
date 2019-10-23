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
