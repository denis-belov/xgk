struct Mat4CBase {
  __declspec(align(32)) union {
    float  _32[16];
    __m128 _128[4];
    __m256 _256[2];
  } data;



  const uint8_t FLOAT_SIZE_4  = sizeof(float) * 4;
  const uint8_t FLOAT_SIZE_16 = sizeof(float) * 16;

  const float IDENTITY[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
  };



  inline static void (* set_ptr) (
    Mat4CBase*,

    const float, const float, const float, const float,
    const float, const float, const float, const float,
    const float, const float, const float, const float,
    const float, const float, const float, const float
  );

  inline static void (* mul_ptr) (
    Mat4CBase*,

    const Mat4CBase&, const Mat4CBase&
  );

  inline static void (* premul_ptr) (
    Mat4CBase*,

    const Mat4CBase&
  );

  inline static void (* postmul_ptr) (
    Mat4CBase*,

    const Mat4CBase&
  );

  inline static void (* mulS_ptr) (
    Mat4CBase*,

    const float
  );

  inline static void (* inv_ptr) (Mat4CBase*);



  Mat4CBase () {
    set32(
      this,

      1.0f, 0.0f, 0.0f, 0.0f,
      0.0f, 1.0f, 0.0f, 0.0f,
      0.0f, 0.0f, 1.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 1.0f
    );
  };



  // SET static
  /////////////
  /////////////

  #define args \
    Mat4CBase* m,\
    \
    const float e0, const float e4, const float e8 , const float e12,\
    const float e1, const float e5, const float e9 , const float e13,\
    const float e2, const float e6, const float e10, const float e14,\
    const float e3, const float e7, const float e11, const float e15

  inline static void set32 (args) {
    m->data._32[0] = e0; m->data._32[4] = e4; m->data._32[8]  = e8 ; m->data._32[12] = e12;
    m->data._32[1] = e1; m->data._32[5] = e5; m->data._32[9]  = e9 ; m->data._32[13] = e13;
    m->data._32[2] = e2; m->data._32[6] = e6; m->data._32[10] = e10; m->data._32[14] = e14;
    m->data._32[3] = e3; m->data._32[7] = e7; m->data._32[11] = e11; m->data._32[15] = e15;
  };

  inline static void set128 (args) {
    m->data._128[0] = _mm_setr_ps(e0,  e1,  e2 , e3 );
    m->data._128[1] = _mm_setr_ps(e4,  e5,  e6 , e7 );
    m->data._128[2] = _mm_setr_ps(e8,  e9,  e10, e11);
    m->data._128[3] = _mm_setr_ps(e12, e13, e14, e15);
  };

  inline static void set256 (args) {
    m->data._256[0] = _mm256_setr_ps(e0, e1, e2 , e3 , e4 , e5 , e6 , e7 );
    m->data._256[1] = _mm256_setr_ps(e8, e9, e10, e11, e12, e13, e14, e15);
  };

  #undef args

  ///////
  ///////
  ///////



  // MULTIPLY static
  //////////////////
  //////////////////

  #define a m1.data._32
  #define b m2.data._32

  inline static void multiply32 (
    Mat4CBase* m,

    const Mat4CBase& m1, const Mat4CBase& m2
  ) {
    set32(
      m,

      (a[0] * b[0]) + (a[4] * b[1]) + (a[8]  * b[2]) + (a[12] * b[3]),  (a[0] * b[4]) + (a[4] * b[5]) + (a[8]  * b[6]) + (a[12] * b[7]),  (a[0] * b[8]) + (a[4] * b[9]) + (a[8]  * b[10]) + (a[12] * b[11]),  (a[0] * b[12]) + (a[4] * b[13]) + (a[8]  * b[14]) + (a[12] * b[15]),
      (a[1] * b[0]) + (a[5] * b[1]) + (a[9]  * b[2]) + (a[13] * b[3]),  (a[1] * b[4]) + (a[5] * b[5]) + (a[9]  * b[6]) + (a[13] * b[7]),  (a[1] * b[8]) + (a[5] * b[9]) + (a[9]  * b[10]) + (a[13] * b[11]),  (a[1] * b[12]) + (a[5] * b[13]) + (a[9]  * b[14]) + (a[13] * b[15]),
      (a[2] * b[0]) + (a[6] * b[1]) + (a[10] * b[2]) + (a[14] * b[3]),  (a[2] * b[4]) + (a[6] * b[5]) + (a[10] * b[6]) + (a[14] * b[7]),  (a[2] * b[8]) + (a[6] * b[9]) + (a[10] * b[10]) + (a[14] * b[11]),  (a[2] * b[12]) + (a[6] * b[13]) + (a[10] * b[14]) + (a[14] * b[15]),
      (a[3] * b[0]) + (a[7] * b[1]) + (a[11] * b[2]) + (a[15] * b[3]),  (a[3] * b[4]) + (a[7] * b[5]) + (a[11] * b[6]) + (a[15] * b[7]),  (a[3] * b[8]) + (a[7] * b[9]) + (a[11] * b[10]) + (a[15] * b[11]),  (a[3] * b[12]) + (a[7] * b[13]) + (a[11] * b[14]) + (a[15] * b[15])
    );
  };

  #undef b
  #undef a

  #define dot(row, col) _mm_dp_ps(rows[##row], m2.data._128[##col], 0xff).m128_f32[0]

  inline static void multiply128 (
    Mat4CBase* m,

    const Mat4CBase& m1, const Mat4CBase& m2
  ) {
    const __m128 rows[4] = {
      _mm_setr_ps(m1.data._32[0], m1.data._32[4], m1.data._32[8] , m1.data._32[12]),
      _mm_setr_ps(m1.data._32[1], m1.data._32[5], m1.data._32[9] , m1.data._32[13]),
      _mm_setr_ps(m1.data._32[2], m1.data._32[6], m1.data._32[10], m1.data._32[14]),
      _mm_setr_ps(m1.data._32[3], m1.data._32[7], m1.data._32[11], m1.data._32[15])
    };

    set128(
      m,

      dot(0, 0), dot(1, 0), dot(2, 0), dot(3, 0),
      dot(0, 1), dot(1, 1), dot(2, 1), dot(3, 1),
      dot(0, 2), dot(1, 2), dot(2, 2), dot(3, 2),
      dot(0, 3), dot(1, 3), dot(2, 3), dot(3, 3)
    );
  };

  #undef dot

  inline static void multiply256 (
    Mat4CBase* m,

    const Mat4CBase& m1, const Mat4CBase& m2
  ) {
    const __m256 a = _mm256_dp_ps(m1.data._256[0], m2.data._256[0], 0xff);
    const __m256 b = _mm256_dp_ps(m1.data._256[0], m2.data._256[1], 0xff);
    const __m256 c = _mm256_dp_ps(m1.data._256[1], m2.data._256[0], 0xff);
    const __m256 d = _mm256_dp_ps(m1.data._256[1], m2.data._256[1], 0xff);

    const __m256 _0 = _mm256_set_m128(m1.data._128[0], m1.data._128[1]);
    const __m256 _1 = _mm256_set_m128(m1.data._128[2], m1.data._128[3]);

    const __m256 e = _mm256_dp_ps(_0, m2.data._256[0], 0xff);
    const __m256 f = _mm256_dp_ps(_0, m2.data._256[1], 0xff);
    const __m256 g = _mm256_dp_ps(_1, m2.data._256[0], 0xff);
    const __m256 h = _mm256_dp_ps(_1, m2.data._256[1], 0xff);

    set256(
      m,

      a.m256_f32[0], e.m256_f32[4], b.m256_f32[0], f.m256_f32[4],
      e.m256_f32[0], a.m256_f32[4], f.m256_f32[0], b.m256_f32[4],
      c.m256_f32[0], g.m256_f32[4], d.m256_f32[0], h.m256_f32[4],
      g.m256_f32[0], c.m256_f32[4], h.m256_f32[0], d.m256_f32[4]
    );
  };

  ///////
  ///////
  ///////



  // PREMULTIPLY static
  /////////////////////
  /////////////////////

  #define a tm->data._32
  #define b m.data._32

  inline static void premultiply32 (
    Mat4CBase* tm,

    const Mat4CBase& m
  ) {
    set32(
      tm,

      (a[0] * b[0]) + (a[4] * b[1]) + (a[8]  * b[2]) + (a[12] * b[3]),  (a[0] * b[4]) + (a[4] * b[5]) + (a[8]  * b[6]) + (a[12] * b[7]),  (a[0] * b[8]) + (a[4] * b[9]) + (a[8]  * b[10]) + (a[12] * b[11]),  (a[0] * b[12]) + (a[4] * b[13]) + (a[8]  * b[14]) + (a[12] * b[15]),
      (a[1] * b[0]) + (a[5] * b[1]) + (a[9]  * b[2]) + (a[13] * b[3]),  (a[1] * b[4]) + (a[5] * b[5]) + (a[9]  * b[6]) + (a[13] * b[7]),  (a[1] * b[8]) + (a[5] * b[9]) + (a[9]  * b[10]) + (a[13] * b[11]),  (a[1] * b[12]) + (a[5] * b[13]) + (a[9]  * b[14]) + (a[13] * b[15]),
      (a[2] * b[0]) + (a[6] * b[1]) + (a[10] * b[2]) + (a[14] * b[3]),  (a[2] * b[4]) + (a[6] * b[5]) + (a[10] * b[6]) + (a[14] * b[7]),  (a[2] * b[8]) + (a[6] * b[9]) + (a[10] * b[10]) + (a[14] * b[11]),  (a[2] * b[12]) + (a[6] * b[13]) + (a[10] * b[14]) + (a[14] * b[15]),
      (a[3] * b[0]) + (a[7] * b[1]) + (a[11] * b[2]) + (a[15] * b[3]),  (a[3] * b[4]) + (a[7] * b[5]) + (a[11] * b[6]) + (a[15] * b[7]),  (a[3] * b[8]) + (a[7] * b[9]) + (a[11] * b[10]) + (a[15] * b[11]),  (a[3] * b[12]) + (a[7] * b[13]) + (a[11] * b[14]) + (a[15] * b[15])
    );
  };

  #undef b
  #undef a

  #define dot(row, col) _mm_dp_ps(rows[##row], m.data._128[##col], 0xff).m128_f32[0]

  inline static void premultiply128 (
    Mat4CBase* tm,

    const Mat4CBase& m
  ) {
    const __m128 rows[4] = {
      _mm_setr_ps(tm->data._32[0], tm->data._32[4], tm->data._32[8] , tm->data._32[12]),
      _mm_setr_ps(tm->data._32[1], tm->data._32[5], tm->data._32[9] , tm->data._32[13]),
      _mm_setr_ps(tm->data._32[2], tm->data._32[6], tm->data._32[10], tm->data._32[14]),
      _mm_setr_ps(tm->data._32[3], tm->data._32[7], tm->data._32[11], tm->data._32[15])
    };

    set128(
      tm,

      dot(0, 0), dot(1, 0), dot(2, 0), dot(3, 0),
      dot(0, 1), dot(1, 1), dot(2, 1), dot(3, 1),
      dot(0, 2), dot(1, 2), dot(2, 2), dot(3, 2),
      dot(0, 3), dot(1, 3), dot(2, 3), dot(3, 3)
    );
  };

  #undef dot

  inline static void premultiply256 (
    Mat4CBase* tm,

    const Mat4CBase& m
  ) {
    const __m256 a = _mm256_dp_ps(tm->data._256[0], m.data._256[0], 0xff);
    const __m256 b = _mm256_dp_ps(tm->data._256[0], m.data._256[1], 0xff);
    const __m256 c = _mm256_dp_ps(tm->data._256[1], m.data._256[0], 0xff);
    const __m256 d = _mm256_dp_ps(tm->data._256[1], m.data._256[1], 0xff);

    const __m256 _0 = _mm256_set_m128(tm->data._128[0], tm->data._128[1]);
    const __m256 _1 = _mm256_set_m128(tm->data._128[2], tm->data._128[3]);

    const __m256 e = _mm256_dp_ps(_0, m.data._256[0], 0xff);
    const __m256 f = _mm256_dp_ps(_0, m.data._256[1], 0xff);
    const __m256 g = _mm256_dp_ps(_1, m.data._256[0], 0xff);
    const __m256 h = _mm256_dp_ps(_1, m.data._256[1], 0xff);

    set256(
      tm,

      a.m256_f32[0], e.m256_f32[4], b.m256_f32[0], f.m256_f32[4],
      e.m256_f32[0], a.m256_f32[4], f.m256_f32[0], b.m256_f32[4],
      c.m256_f32[0], g.m256_f32[4], d.m256_f32[0], h.m256_f32[4],
      g.m256_f32[0], c.m256_f32[4], h.m256_f32[0], d.m256_f32[4]
    );
  };

  ///////
  ///////
  ///////



  // POSTMULTIPLY static
  //////////////////////
  //////////////////////

  #define a m.data._32
  #define b tm->data._32

  inline static void postmultiply32 (
    Mat4CBase* tm,

    const Mat4CBase& m
  ) {
    set32(
      tm,

      (a[0] * b[0]) + (a[4] * b[1]) + (a[8]  * b[2]) + (a[12] * b[3]),  (a[0] * b[4]) + (a[4] * b[5]) + (a[8]  * b[6]) + (a[12] * b[7]),  (a[0] * b[8]) + (a[4] * b[9]) + (a[8]  * b[10]) + (a[12] * b[11]),  (a[0] * b[12]) + (a[4] * b[13]) + (a[8]  * b[14]) + (a[12] * b[15]),
      (a[1] * b[0]) + (a[5] * b[1]) + (a[9]  * b[2]) + (a[13] * b[3]),  (a[1] * b[4]) + (a[5] * b[5]) + (a[9]  * b[6]) + (a[13] * b[7]),  (a[1] * b[8]) + (a[5] * b[9]) + (a[9]  * b[10]) + (a[13] * b[11]),  (a[1] * b[12]) + (a[5] * b[13]) + (a[9]  * b[14]) + (a[13] * b[15]),
      (a[2] * b[0]) + (a[6] * b[1]) + (a[10] * b[2]) + (a[14] * b[3]),  (a[2] * b[4]) + (a[6] * b[5]) + (a[10] * b[6]) + (a[14] * b[7]),  (a[2] * b[8]) + (a[6] * b[9]) + (a[10] * b[10]) + (a[14] * b[11]),  (a[2] * b[12]) + (a[6] * b[13]) + (a[10] * b[14]) + (a[14] * b[15]),
      (a[3] * b[0]) + (a[7] * b[1]) + (a[11] * b[2]) + (a[15] * b[3]),  (a[3] * b[4]) + (a[7] * b[5]) + (a[11] * b[6]) + (a[15] * b[7]),  (a[3] * b[8]) + (a[7] * b[9]) + (a[11] * b[10]) + (a[15] * b[11]),  (a[3] * b[12]) + (a[7] * b[13]) + (a[11] * b[14]) + (a[15] * b[15])
    );
  };

  #undef b
  #undef a

  #define dot(row, col) _mm_dp_ps(rows[##row], tm->data._128[##col], 0xff).m128_f32[0]

  inline static void postmultiply128 (
    Mat4CBase* tm,

    const Mat4CBase& m
  ) {
    const __m128 rows[4] = {
      _mm_setr_ps(m.data._32[0], m.data._32[4], m.data._32[8] , m.data._32[12]),
      _mm_setr_ps(m.data._32[1], m.data._32[5], m.data._32[9] , m.data._32[13]),
      _mm_setr_ps(m.data._32[2], m.data._32[6], m.data._32[10], m.data._32[14]),
      _mm_setr_ps(m.data._32[3], m.data._32[7], m.data._32[11], m.data._32[15])
    };

    set128(
      tm,

      dot(0, 0), dot(1, 0), dot(2, 0), dot(3, 0),
      dot(0, 1), dot(1, 1), dot(2, 1), dot(3, 1),
      dot(0, 2), dot(1, 2), dot(2, 2), dot(3, 2),
      dot(0, 3), dot(1, 3), dot(2, 3), dot(3, 3)
    );
  };

  #undef dot

  inline static void postmultiply256 (
    Mat4CBase* tm,

    const Mat4CBase& m
  ) {
    const __m256 a = _mm256_dp_ps(m.data._256[0], tm->data._256[0], 0xff);
    const __m256 b = _mm256_dp_ps(m.data._256[0], tm->data._256[1], 0xff);
    const __m256 c = _mm256_dp_ps(m.data._256[1], tm->data._256[0], 0xff);
    const __m256 d = _mm256_dp_ps(m.data._256[1], tm->data._256[1], 0xff);

    const __m256 _0 = _mm256_set_m128(m.data._128[0], m.data._128[1]);
    const __m256 _1 = _mm256_set_m128(m.data._128[2], m.data._128[3]);

    const __m256 e = _mm256_dp_ps(_0, tm->data._256[0], 0xff);
    const __m256 f = _mm256_dp_ps(_0, tm->data._256[1], 0xff);
    const __m256 g = _mm256_dp_ps(_1, tm->data._256[0], 0xff);
    const __m256 h = _mm256_dp_ps(_1, tm->data._256[1], 0xff);

    set256(
      tm,

      a.m256_f32[0], e.m256_f32[4], b.m256_f32[0], f.m256_f32[4],
      e.m256_f32[0], a.m256_f32[4], f.m256_f32[0], b.m256_f32[4],
      c.m256_f32[0], g.m256_f32[4], d.m256_f32[0], h.m256_f32[4],
      g.m256_f32[0], c.m256_f32[4], h.m256_f32[0], d.m256_f32[4]
    );
  };

  ///////
  ///////
  ///////



  // MULTIPLY SCALAR static
  /////////////////////////
  /////////////////////////

  inline static void multiplyScalar32 (
    Mat4CBase* m,

    const float s
  ) {
    m->data._32[0] *= s; m->data._32[4] *= s; m->data._32[8]  *= s; m->data._32[12] *= s;
    m->data._32[1] *= s; m->data._32[5] *= s; m->data._32[9]  *= s; m->data._32[13] *= s;
    m->data._32[2] *= s; m->data._32[6] *= s; m->data._32[10] *= s; m->data._32[14] *= s;
    m->data._32[3] *= s; m->data._32[7] *= s; m->data._32[11] *= s; m->data._32[15] *= s;
  };

  inline static void multiplyScalar128 (
    Mat4CBase* m,

    const float s
  ) {
    const __m128 s128 = _mm_set1_ps(s);

    m->data._128[0] = _mm_mul_ps(m->data._128[0], s128);
    m->data._128[1] = _mm_mul_ps(m->data._128[1], s128);
    m->data._128[2] = _mm_mul_ps(m->data._128[2], s128);
    m->data._128[3] = _mm_mul_ps(m->data._128[3], s128);
  };

  inline static void multiplyScalar256 (
    Mat4CBase* m,

    const float s
  ) {
    const __m256 s256 = _mm256_set1_ps(s);

    m->data._256[0] = _mm256_mul_ps(m->data._256[0], s256);
    m->data._256[1] = _mm256_mul_ps(m->data._256[1], s256);
  };

  ///////
  ///////
  ///////



  // INVERSE TRANSFORM NO SCALE static
  ////////////////////////////////////
  ////////////////////////////////////

  #define a tm->data._32

  inline static void inverseTransformNoScale32 (Mat4CBase* tm) {
    set32(
      tm,

      a[0], a[1], a[2] , -(a[0] * a[12]) - (a[1] * a[13]) - (a[2]  * a[14]),
      a[4], a[5], a[6] , -(a[4] * a[12]) - (a[5] * a[13]) - (a[6]  * a[14]),
      a[8], a[9], a[10], -(a[8] * a[12]) - (a[9] * a[13]) - (a[10] * a[14]),
      0   , 0   , 0    , 1
    );
  }

  inline static void inverseTransformNoScale128 (Mat4CBase* tm) {
    set128(
      tm,

      a[0], a[1], a[2] , -_mm_dp_ps(tm->data._128[0], tm->data._128[3], 0xff).m128_f32[0],
      a[4], a[5], a[6] , -_mm_dp_ps(tm->data._128[1], tm->data._128[3], 0xff).m128_f32[0],
      a[8], a[9], a[10], -_mm_dp_ps(tm->data._128[2], tm->data._128[3], 0xff).m128_f32[0],
      0   , 0   , 0    , 1
    );
  }

  #undef a

  ///////
  ///////
  ///////



  // SIMD static
  //////////////
  //////////////

  static void SIMD32 () {
    set_ptr = set32;
    mul_ptr = multiply32;
    premul_ptr = premultiply32;
    postmul_ptr = postmultiply32;
    mulS_ptr = multiplyScalar32;
    inv_ptr = inverseTransformNoScale32;
  };

  static void SIMD128 () {
    set_ptr = set128;
    mul_ptr = multiply128;
    premul_ptr = premultiply128;
    postmul_ptr = postmultiply128;
    mulS_ptr = multiplyScalar128;
    inv_ptr = inverseTransformNoScale128;
  };

  static void SIMD256 () {
    set_ptr = set256;
    mul_ptr = multiply256;
    premul_ptr = premultiply256;
    postmul_ptr = postmultiply256;
    mulS_ptr = multiplyScalar256;
    // inv_ptr = inverseTransformNoScale256;
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


  // SET
  //////
  //////

  inline void set (
    const float e0 = 1.0f, const float e4 = 0.0f, const float e8  = 0.0f, const float e12 = 0.0f,
    const float e1 = 0.0f, const float e5 = 1.0f, const float e9  = 0.0f, const float e13 = 0.0f,
    const float e2 = 0.0f, const float e6 = 0.0f, const float e10 = 1.0f, const float e14 = 0.0f,
    const float e3 = 0.0f, const float e7 = 0.0f, const float e11 = 0.0f, const float e15 = 1.0f
  ) {
    set_ptr(
      this,

      e0, e4, e8 , e12,
      e1, e5, e9 , e13,
      e2, e6, e10, e14,
      e3, e7, e11, e15
    );
  };

  ///////
  ///////
  ///////



  // MULTIPLY
  ///////////
  ///////////

  inline void mul (Mat4CBase& m1, Mat4CBase& m2) {
    mul_ptr(
      this,

      m1, m2
    );
  };

  ///////
  ///////
  ///////



  // PREMULTIPLY
  //////////////
  //////////////

  inline void premul (Mat4CBase& m) {
    premul_ptr(
      this,

      m
    );
  };

  ///////
  ///////
  ///////



  // POSTMULTIPLY
  ///////////////
  ///////////////

  inline void postmul (Mat4CBase& m) {
    postmul_ptr(
      this,

      m
    );
  };

  ///////
  ///////
  ///////



  // MULTIPLY SCALAR
  //////////////////
  //////////////////

  inline void mulS (const float s) {
    mulS_ptr(
      this,

      s
    );
  };

  ///////
  ///////
  ///////



  // INVERSE TRANSFORM NO SCALE
  /////////////////////////////
  /////////////////////////////

  inline void inv () {
    inv_ptr(this);
  }

  ///////
  ///////
  ///////



  // COPY
  ///////
  ///////

  inline void copy (Mat4CBase& m) {
    memcpy(&data, &m, FLOAT_SIZE_16);
  };

  ///////
  ///////
  ///////



  // RESET
  ////////
  ////////

  inline void reset () {
    memcpy(&data, IDENTITY, FLOAT_SIZE_16);
  };

  ///////
  ///////
  ///////



  // MAKE PERSPECTIVE PROJECTION
  //////////////////////////////
  //////////////////////////////

  inline void makePerspectiveProjection (
    const float left_,
    const float right_,
    const float top_,
    const float bottom_,
    const float near_,
    const float far_
  ) {
    set_ptr(
      this,

      2.0f * near_ / (right_ - left_), 0.0f                           , (right_ + left_) / (right_ - left_), 0.0f                                   ,
      0.0f                           , 2.0f * near_ / (top_ - bottom_), (top_ + bottom_) / (top_ - bottom_), 0.0f                                   ,
      0.0f                           , 0.0f                           , -(far_ + near_) / (far_ - near_)   , -(2.0f * far_ * near_) / (far_ - near_),
      0.0f                           , 0.0f                           , -1.0f                              , 0.0f
    );
  };

  inline void makePerspectiveProjection (
    const float fov_,
    const float aspect_,
    const float near_,
    const float far_,
    const float zoom_
  ) {
    const float top_ = near_ * tan(0.017453292f * 0.5f * fov_) / zoom_;
    const float height_ = 2.0f * top_;
    const float width_ = aspect_ * height_;
    const float left_ = -0.5f * width_;

    makePerspectiveProjection(left_, left_ + width_, top_, top_ - height_, near_, far_);
  };

  ///////
  ///////
  ///////



  // MAKE ROTATION
  ////////////////
  ////////////////

  inline void makeRotation (Quat& q) {
    const float xx = 2.0f * q.data._32[0] * q.data._32[0];
    const float yy = 2.0f * q.data._32[1] * q.data._32[1];
    const float zz = 2.0f * q.data._32[2] * q.data._32[2];
    const float xy = 2.0f * q.data._32[0] * q.data._32[1];
    const float xz = 2.0f * q.data._32[0] * q.data._32[2];
    const float xw = 2.0f * q.data._32[0] * q.data._32[3];
    const float yz = 2.0f * q.data._32[1] * q.data._32[2];
    const float yw = 2.0f * q.data._32[1] * q.data._32[3];
    const float zw = 2.0f * q.data._32[2] * q.data._32[3];

    set_ptr(
      this,

      1.0f - yy - zz, xy - zw       , xz + yw       , 0.0f,
      xy + zw       , 1.0f - xx - zz, yz - xw       , 0.0f,
      xz - yw       , yz + xw       , 1.0f - xx - yy, 0.0f,
      0.0f          , 0.0f          , 0.0f          , 1.0f
    );
  }

  inline void makeRotationX (const float angle) {
    const float cos_ = cos(angle);
    const float sin_ = sin(angle);

    set_ptr(
      this,

      1.0f, 0.0f , 0.0f, 0.0f,
      0.0f, cos_ , sin_, 0.0f,
      0.0f, -sin_, cos_, 0.0f,
      0.0f, 0.0f , 0.0f, 1.0f
    );
  };

  ///////
  ///////
  ///////



  // MAKE TRANSLATION
  ///////////////////
  ///////////////////

  inline void makeTranslation (Vec4& axis, const float value) {
    set_ptr(
      this,

      1.0f, 0.0f, 0.0f, axis.data._32[0] * value,
      0.0f, 1.0f, 0.0f, axis.data._32[1] * value,
      0.0f, 0.0f, 1.0f, axis.data._32[2] * value,
      0.0f, 0.0f, 0.0f, 1.0f
    );
  }

  inline void makeTranslation2 (Vec4& axis, const float value) {
    reset();

    data._128[3] = _mm_mul_ps(axis.data._128, _mm_set1_ps(value));

    data._32[15] = 1.0f;
  }

  ///////
  ///////
  ///////



  // INVERSE
  //////////
  //////////

  #define a data._32

  inline void inverse () {
    float a_[4];

    memcpy(a_, a, FLOAT_SIZE_4);

    set_ptr(
      this,

      (a[9]  * a[14] * a[7]) - (a[13] * a[10] * a[7]) + (a[13] * a[6] * a[11]) - (a[5] * a[14] * a[11]) - (a[9] * a[6] * a[15]) + (a[5] * a[10] * a[15]),
      (a[12] * a[10] * a[7]) - (a[8]  * a[14] * a[7]) - (a[12] * a[6] * a[11]) + (a[4] * a[14] * a[11]) + (a[8] * a[6] * a[15]) - (a[4] * a[10] * a[15]),
      (a[8]  * a[13] * a[7]) - (a[12] * a[9]  * a[7]) + (a[12] * a[5] * a[11]) - (a[4] * a[13] * a[11]) - (a[8] * a[5] * a[15]) + (a[4] * a[9]  * a[15]),
      (a[12] * a[9]  * a[6]) - (a[8]  * a[13] * a[6]) - (a[12] * a[5] * a[10]) + (a[4] * a[13] * a[10]) + (a[8] * a[5] * a[14]) - (a[4] * a[9]  * a[14]),
      (a[13] * a[10] * a[3]) - (a[9]  * a[14] * a[3]) - (a[13] * a[2] * a[11]) + (a[1] * a[14] * a[11]) + (a[9] * a[2] * a[15]) - (a[1] * a[10] * a[15]),
      (a[8]  * a[14] * a[3]) - (a[12] * a[10] * a[3]) + (a[12] * a[2] * a[11]) - (a[0] * a[14] * a[11]) - (a[8] * a[2] * a[15]) + (a[0] * a[10] * a[15]),
      (a[12] * a[9]  * a[3]) - (a[8]  * a[13] * a[3]) - (a[12] * a[1] * a[11]) + (a[0] * a[13] * a[11]) + (a[8] * a[1] * a[15]) - (a[0] * a[9]  * a[15]),
      (a[8]  * a[13] * a[2]) - (a[12] * a[9]  * a[2]) + (a[12] * a[1] * a[10]) - (a[0] * a[13] * a[10]) - (a[8] * a[1] * a[14]) + (a[0] * a[9]  * a[14]),
      (a[5]  * a[14] * a[3]) - (a[13] * a[6]  * a[3]) + (a[13] * a[2] * a[7])  - (a[1] * a[14] * a[7])  - (a[5] * a[2] * a[15]) + (a[1] * a[6]  * a[15]),
      (a[12] * a[6]  * a[3]) - (a[4]  * a[14] * a[3]) - (a[12] * a[2] * a[7])  + (a[0] * a[14] * a[7])  + (a[4] * a[2] * a[15]) - (a[0] * a[6]  * a[15]),
      (a[4]  * a[13] * a[3]) - (a[12] * a[5]  * a[3]) + (a[12] * a[1] * a[7])  - (a[0] * a[13] * a[7])  - (a[4] * a[1] * a[15]) + (a[0] * a[5]  * a[15]),
      (a[12] * a[5]  * a[2]) - (a[4]  * a[13] * a[2]) - (a[12] * a[1] * a[6])  + (a[0] * a[13] * a[6])  + (a[4] * a[1] * a[14]) - (a[0] * a[5]  * a[14]),
      (a[9]  * a[6]  * a[3]) - (a[5]  * a[10] * a[3]) - (a[9]  * a[2] * a[7])  + (a[1] * a[10] * a[7])  + (a[5] * a[2] * a[11]) - (a[1] * a[6]  * a[11]),
      (a[4]  * a[10] * a[3]) - (a[8]  * a[6]  * a[3]) + (a[8]  * a[2] * a[7])  - (a[0] * a[10] * a[7])  - (a[4] * a[2] * a[11]) + (a[0] * a[6]  * a[11]),
      (a[8]  * a[5]  * a[3]) - (a[4]  * a[9]  * a[3]) - (a[8]  * a[1] * a[7])  + (a[0] * a[9]  * a[7])  + (a[4] * a[1] * a[11]) - (a[0] * a[5]  * a[11]),
      (a[4]  * a[9]  * a[2]) - (a[8]  * a[5]  * a[2]) + (a[8]  * a[1] * a[6])  - (a[0] * a[9]  * a[6])  - (a[4] * a[1] * a[10]) + (a[0] * a[5]  * a[10])
    );

    mulS_ptr(
      this,

      1 / (a_[0] * a[0] + a_[1] * a[4] + a_[2] * a[8] + a_[3] * a[12])
    );
  }

  #undef a

  ///////
  ///////
  ///////
};
