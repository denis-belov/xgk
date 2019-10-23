// column-major 4x4 matrix

#define SET32(\
  m,\
  \
  e0, e4, e8 , e12,\
  e1, e5, e9 , e13,\
  e2, e6, e10, e14,\
  e3, e7, e11, e15\
)\
  m->_32[0]  = e0 ; m->_32[1]  = e1 ; m->_32[2]  = e2 ; m->_32[3]  = e3 ;\
  m->_32[4]  = e4 ; m->_32[5]  = e5 ; m->_32[6]  = e6 ; m->_32[7]  = e7 ;\
  m->_32[8]  = e8 ; m->_32[9]  = e9 ; m->_32[10] = e10; m->_32[11] = e11;\
  m->_32[12] = e12; m->_32[13] = e13; m->_32[14] = e14; m->_32[15] = e15;

#ifdef XGK_DATA_SSE
  #define SET128(\
    m,\
    \
    e0, e4, e8 , e12,\
    e1, e5, e9 , e13,\
    e2, e6, e10, e14,\
    e3, e7, e11, e15\
  )\
    m->_128[0] = _mm_setr_ps(e0,  e1,  e2 , e3 );\
    m->_128[1] = _mm_setr_ps(e4,  e5,  e6 , e7 );\
    m->_128[2] = _mm_setr_ps(e8,  e9,  e10, e11);\
    m->_128[3] = _mm_setr_ps(e12, e13, e14, e15);
#endif

#ifdef XGK_DATA_AVX
  #define SET256(\
    m,\
    \
    e0, e4, e8 , e12,\
    e1, e5, e9 , e13,\
    e2, e6, e10, e14,\
    e3, e7, e11, e15\
  )\
    m->_256[0] = _mm256_setr_ps(e0, e1, e2 , e3 , e4 , e5 , e6 , e7 );\
    m->_256[1] = _mm256_setr_ps(e8, e9, e10, e11, e12, e13, e14, e15);
#endif



const unsigned short FLOAT_SIZE_4  = sizeof(float) * 4;

const unsigned short FLOAT_SIZE_16 = sizeof(float) * 16;

const float IDENTITY[16] = {
  1.0f, 0.0f, 0.0f, 0.0f,
  0.0f, 1.0f, 0.0f, 0.0f,
  0.0f, 0.0f, 1.0f, 0.0f,
  0.0f, 0.0f, 0.0f, 1.0f
};



void (* m4_mul) (Mat4*, Mat4*, Mat4*);

void (* m4_premul) (Mat4*, Mat4*);

void (* m4_postmul) (Mat4*, Mat4*);

void (* m4_muls) (Mat4*, const float);

void (* m4_invns) (Mat4*);

void (* m4_makeProjPersp) (
  Mat4*,

  const float,
  const float,
  const float,
  const float,
  const float,
  const float
);

void (* m4_makeProjPersp_) (
  Mat4*,

  const float,
  const float,
  const float,
  const float,
  const float
);

void (* m4_makeRot) (Mat4*, Quat*);

void (* m4_makeRotX) (Mat4*, const float);

void (* m4_makeTrans) (Mat4*, Vec4*, const float);



// COPY
///////
///////
static inline void m4_copy (Mat4* m0, Mat4* m1) {
  memcpy(m0, m1, FLOAT_SIZE_16);
};

///////
///////
///////



// RESET
////////
////////

static inline void m4_reset (Mat4* m0) {
  memcpy(m0, IDENTITY, FLOAT_SIZE_16);
};

///////
///////
///////



// SET
//////
//////

#define args \
  Mat4* m,\
  \
  const float e0, const float e4, const float e8 , const float e12,\
  const float e1, const float e5, const float e9 , const float e13,\
  const float e2, const float e6, const float e10, const float e14,\
  const float e3, const float e7, const float e11, const float e15

static inline void m4_set32 (args) {
  SET32(
    m,

    e0, e4, e8 , e12,
    e1, e5, e9 , e13,
    e2, e6, e10, e14,
    e3, e7, e11, e15
  )
};

#ifdef XGK_DATA_SSE
  static inline void m4_set128 (args) {
    SET128(
      m,

      e0, e4, e8 , e12,
      e1, e5, e9 , e13,
      e2, e6, e10, e14,
      e3, e7, e11, e15
    )
  };
#endif

#ifdef XGK_DATA_AVX
  static inline void m4_set256 (args) {
    SET256(
      m,

      e0, e4, e8 , e12,
      e1, e5, e9 , e13,
      e2, e6, e10, e14,
      e3, e7, e11, e15
    )
  };
#endif

#undef args

///////
///////
///////



// PREMULTIPLY
//////////////
//////////////

#define a m1->_32
#define b m0->_32

static inline void __attribute__((optimize("O0"))) m4_premul32 (Mat4* m0, Mat4* m1) {
  m4_set32(
    m0,

    (a[0] * b[0]) + (a[4] * b[1]) + (a[8]  * b[2]) + (a[12] * b[3]),  (a[0] * b[4]) + (a[4] * b[5]) + (a[8]  * b[6]) + (a[12] * b[7]),  (a[0] * b[8]) + (a[4] * b[9]) + (a[8]  * b[10]) + (a[12] * b[11]),  (a[0] * b[12]) + (a[4] * b[13]) + (a[8]  * b[14]) + (a[12] * b[15]),
    (a[1] * b[0]) + (a[5] * b[1]) + (a[9]  * b[2]) + (a[13] * b[3]),  (a[1] * b[4]) + (a[5] * b[5]) + (a[9]  * b[6]) + (a[13] * b[7]),  (a[1] * b[8]) + (a[5] * b[9]) + (a[9]  * b[10]) + (a[13] * b[11]),  (a[1] * b[12]) + (a[5] * b[13]) + (a[9]  * b[14]) + (a[13] * b[15]),
    (a[2] * b[0]) + (a[6] * b[1]) + (a[10] * b[2]) + (a[14] * b[3]),  (a[2] * b[4]) + (a[6] * b[5]) + (a[10] * b[6]) + (a[14] * b[7]),  (a[2] * b[8]) + (a[6] * b[9]) + (a[10] * b[10]) + (a[14] * b[11]),  (a[2] * b[12]) + (a[6] * b[13]) + (a[10] * b[14]) + (a[14] * b[15]),
    (a[3] * b[0]) + (a[7] * b[1]) + (a[11] * b[2]) + (a[15] * b[3]),  (a[3] * b[4]) + (a[7] * b[5]) + (a[11] * b[6]) + (a[15] * b[7]),  (a[3] * b[8]) + (a[7] * b[9]) + (a[11] * b[10]) + (a[15] * b[11]),  (a[3] * b[12]) + (a[7] * b[13]) + (a[11] * b[14]) + (a[15] * b[15])
  );
};

#undef b
#undef a

#ifdef XGK_DATA_SSE
  static inline void m4_premul128 (Mat4* m0, Mat4* m1) {
    register const __m128 a = _mm_load_ps(m0->_32);
    register const __m128 b = _mm_load_ps(m0->_32 + 4);
    register const __m128 c = _mm_load_ps(m0->_32 + 8);
    register const __m128 d = _mm_load_ps(m0->_32 + 12);

    m0->_128[0] = _mm_mul_ps(a, _mm_set1_ps(m1->_32[0]));
    m0->_128[1] = _mm_mul_ps(a, _mm_set1_ps(m1->_32[4]));
    m0->_128[2] = _mm_mul_ps(a, _mm_set1_ps(m1->_32[8]));
    m0->_128[3] = _mm_mul_ps(a, _mm_set1_ps(m1->_32[12]));

    m0->_128[0] = _mm_add_ps(m0->_128[0], _mm_mul_ps(b, _mm_set1_ps(m1->_32[1])));
    m0->_128[1] = _mm_add_ps(m0->_128[1], _mm_mul_ps(b, _mm_set1_ps(m1->_32[5])));
    m0->_128[2] = _mm_add_ps(m0->_128[2], _mm_mul_ps(b, _mm_set1_ps(m1->_32[9])));
    m0->_128[3] = _mm_add_ps(m0->_128[3], _mm_mul_ps(b, _mm_set1_ps(m1->_32[13])));

    m0->_128[0] = _mm_add_ps(m0->_128[0], _mm_mul_ps(c, _mm_set1_ps(m1->_32[2])));
    m0->_128[1] = _mm_add_ps(m0->_128[1], _mm_mul_ps(c, _mm_set1_ps(m1->_32[6])));
    m0->_128[2] = _mm_add_ps(m0->_128[2], _mm_mul_ps(c, _mm_set1_ps(m1->_32[10])));
    m0->_128[3] = _mm_add_ps(m0->_128[3], _mm_mul_ps(c, _mm_set1_ps(m1->_32[14])));

    m0->_128[0] = _mm_add_ps(m0->_128[0], _mm_mul_ps(d, _mm_set1_ps(m1->_32[3])));
    m0->_128[1] = _mm_add_ps(m0->_128[1], _mm_mul_ps(d, _mm_set1_ps(m1->_32[7])));
    m0->_128[2] = _mm_add_ps(m0->_128[2], _mm_mul_ps(d, _mm_set1_ps(m1->_32[11])));
    m0->_128[3] = _mm_add_ps(m0->_128[3], _mm_mul_ps(d, _mm_set1_ps(m1->_32[15])));
  };
#endif

#ifdef XGK_DATA_AVX
  static inline void m4_premul256 (Mat4* m0, Mat4* m1) {
    const __m256 a = _mm256_dp_ps(m0->_256[0], m1->_256[0], 0xff);
    const __m256 b = _mm256_dp_ps(m0->_256[0], m1->_256[1], 0xff);
    const __m256 c = _mm256_dp_ps(m0->_256[1], m1->_256[0], 0xff);
    const __m256 d = _mm256_dp_ps(m0->_256[1], m1->_256[1], 0xff);

    const __m256 _0 = _mm256_set_m128(m0->_128[0], m0->_128[1]);
    const __m256 _1 = _mm256_set_m128(m0->_128[2], m0->_128[3]);

    const __m256 e = _mm256_dp_ps(_0, m1->_256[0], 0xff);
    const __m256 f = _mm256_dp_ps(_0, m1->_256[1], 0xff);
    const __m256 g = _mm256_dp_ps(_1, m1->_256[0], 0xff);
    const __m256 h = _mm256_dp_ps(_1, m1->_256[1], 0xff);

    SET256(
      m0,

      a[0], e[4], b[0], f[4],
      e[0], a[4], f[0], b[4],
      c[0], g[4], d[0], h[4],
      g[0], c[4], h[0], d[4]
    );
  };
#endif

///////
///////
///////



// POSTMULTIPLY
///////////////
///////////////

#define a m0->_32
#define b m1->_32

static inline void m4_postmul32 (Mat4* m0, Mat4* m1) {
  SET32(
    m0,

    (a[0] * b[0]) + (a[4] * b[1]) + (a[8]  * b[2]) + (a[12] * b[3]),  (a[0] * b[4]) + (a[4] * b[5]) + (a[8]  * b[6]) + (a[12] * b[7]),  (a[0] * b[8]) + (a[4] * b[9]) + (a[8]  * b[10]) + (a[12] * b[11]),  (a[0] * b[12]) + (a[4] * b[13]) + (a[8]  * b[14]) + (a[12] * b[15]),
    (a[1] * b[0]) + (a[5] * b[1]) + (a[9]  * b[2]) + (a[13] * b[3]),  (a[1] * b[4]) + (a[5] * b[5]) + (a[9]  * b[6]) + (a[13] * b[7]),  (a[1] * b[8]) + (a[5] * b[9]) + (a[9]  * b[10]) + (a[13] * b[11]),  (a[1] * b[12]) + (a[5] * b[13]) + (a[9]  * b[14]) + (a[13] * b[15]),
    (a[2] * b[0]) + (a[6] * b[1]) + (a[10] * b[2]) + (a[14] * b[3]),  (a[2] * b[4]) + (a[6] * b[5]) + (a[10] * b[6]) + (a[14] * b[7]),  (a[2] * b[8]) + (a[6] * b[9]) + (a[10] * b[10]) + (a[14] * b[11]),  (a[2] * b[12]) + (a[6] * b[13]) + (a[10] * b[14]) + (a[14] * b[15]),
    (a[3] * b[0]) + (a[7] * b[1]) + (a[11] * b[2]) + (a[15] * b[3]),  (a[3] * b[4]) + (a[7] * b[5]) + (a[11] * b[6]) + (a[15] * b[7]),  (a[3] * b[8]) + (a[7] * b[9]) + (a[11] * b[10]) + (a[15] * b[11]),  (a[3] * b[12]) + (a[7] * b[13]) + (a[11] * b[14]) + (a[15] * b[15])
  )
};

#undef b
#undef a

#ifdef XGK_DATA_SSE
  #define dot(row, col) _mm_dp_ps(rows[row], m0->_128[col], 0xff)[0]

  static inline void m4_postmul128 (Mat4* m0, Mat4* m1) {
    const __m128 rows[4] = {
      _mm_setr_ps(m1->_32[0], m1->_32[4], m1->_32[8] , m1->_32[12]),
      _mm_setr_ps(m1->_32[1], m1->_32[5], m1->_32[9] , m1->_32[13]),
      _mm_setr_ps(m1->_32[2], m1->_32[6], m1->_32[10], m1->_32[14]),
      _mm_setr_ps(m1->_32[3], m1->_32[7], m1->_32[11], m1->_32[15])
    };

    SET128(
      m0,

      dot(0, 0), dot(1, 0), dot(2, 0), dot(3, 0),
      dot(0, 1), dot(1, 1), dot(2, 1), dot(3, 1),
      dot(0, 2), dot(1, 2), dot(2, 2), dot(3, 2),
      dot(0, 3), dot(1, 3), dot(2, 3), dot(3, 3)
    )
  };

  #undef dot
#endif

#ifdef XGK_DATA_AVX
  static inline void m4_postmul256 (Mat4* m0, Mat4* m1) {
    const __m256 a = _mm256_dp_ps(m1->_256[0], m0->_256[0], 0xff);
    const __m256 b = _mm256_dp_ps(m1->_256[0], m0->_256[1], 0xff);
    const __m256 c = _mm256_dp_ps(m1->_256[1], m0->_256[0], 0xff);
    const __m256 d = _mm256_dp_ps(m1->_256[1], m0->_256[1], 0xff);

    const __m256 _0 = _mm256_set_m128(m1->_128[0], m1->_128[1]);
    const __m256 _1 = _mm256_set_m128(m1->_128[2], m1->_128[3]);

    const __m256 e = _mm256_dp_ps(_0, m0->_256[0], 0xff);
    const __m256 f = _mm256_dp_ps(_0, m0->_256[1], 0xff);
    const __m256 g = _mm256_dp_ps(_1, m0->_256[0], 0xff);
    const __m256 h = _mm256_dp_ps(_1, m0->_256[1], 0xff);

    SET256(
      m0,

      a[0], e[4], b[0], f[4],
      e[0], a[4], f[0], b[4],
      c[0], g[4], d[0], h[4],
      g[0], c[4], h[0], d[4]
    )
  };
#endif

///////
///////
///////



// MULTIPLY SCALAR
//////////////////
//////////////////

static inline void m4_muls32 (Mat4* m, const float s) {
  m->_32[0]  *= s; m->_32[1]  *= s; m->_32[2]  *= s; m->_32[3]  *= s;
  m->_32[4]  *= s; m->_32[5]  *= s; m->_32[6]  *= s; m->_32[7]  *= s;
  m->_32[8]  *= s; m->_32[9]  *= s; m->_32[10] *= s; m->_32[11] *= s;
  m->_32[12] *= s; m->_32[13] *= s; m->_32[14] *= s; m->_32[15] *= s;
};

#ifdef XGK_DATA_SSE
  static inline void m4_muls128 (Mat4* m, const float s) {
    const __m128 s128 = _mm_set1_ps(s);

    m->_128[0] = _mm_mul_ps(m->_128[0], s128);
    m->_128[1] = _mm_mul_ps(m->_128[1], s128);
    m->_128[2] = _mm_mul_ps(m->_128[2], s128);
    m->_128[3] = _mm_mul_ps(m->_128[3], s128);
  };
#endif

#ifdef XGK_DATA_AVX
  static inline void m4_muls256 (Mat4* m, const float s) {
    const __m256 s256 = _mm256_set1_ps(s);

    m->_256[0] = _mm256_mul_ps(m->_256[0], s256);
    m->_256[1] = _mm256_mul_ps(m->_256[1], s256);
  };
#endif

///////
///////
///////



// INVERSE TRANSFORM NO SCALE
/////////////////////////////
/////////////////////////////

#define a m0->_32
#define b m0->_128

static inline void m4_invns32 (Mat4* m0) {
  SET32(
    m0,

    a[0], a[1], a[2] , -(a[0] * a[12]) - (a[1] * a[13]) - (a[2]  * a[14]),
    a[4], a[5], a[6] , -(a[4] * a[12]) - (a[5] * a[13]) - (a[6]  * a[14]),
    a[8], a[9], a[10], -(a[8] * a[12]) - (a[9] * a[13]) - (a[10] * a[14]),
    0   , 0   , 0    , 1
  )
};

#ifdef XGK_DATA_SSE
  static inline void m4_invns128 (Mat4* m0) {
    SET128(
      m0,

      a[0], a[1], a[2] , -_mm_dp_ps(b[0], b[3], 0xff)[0],
      a[4], a[5], a[6] , -_mm_dp_ps(b[1], b[3], 0xff)[0],
      a[8], a[9], a[10], -_mm_dp_ps(b[2], b[3], 0xff)[0],
      0   , 0   , 0    , 1
    )
  };
#endif

#ifdef XGK_DATA_AVX
  static inline void m4_invns256 (Mat4* m0) {
    SET256(
      m0,

      a[0], a[1], a[2] , -_mm_dp_ps(b[0], b[3], 0xff)[0],
      a[4], a[5], a[6] , -_mm_dp_ps(b[1], b[3], 0xff)[0],
      a[8], a[9], a[10], -_mm_dp_ps(b[2], b[3], 0xff)[0],
      0   , 0   , 0    , 1
    )
  };
#endif

#undef b
#undef a

///////
///////
///////



// MAKE PERSPECTIVE PROJECTION
//////////////////////////////
//////////////////////////////

static inline void m4_makeProjPersp32 (
  Mat4* m0,

  const float left,
  const float right,
  const float top,
  const float bottom,
  const float near_,
  const float far_
) {
  SET32(
    m0,

    2.0f * near_ / (right - left), 0.0f                         , (right + left) / (right - left)  , 0.0f                                   ,
    0.0f                         , 2.0f * near_ / (top - bottom), (top + bottom) / (top - bottom)  , 0.0f                                   ,
    0.0f                         , 0.0f                         , -(far_ + near_) / (far_ - near_) , -(2.0f * far_ * near_) / (far_ - near_),
    0.0f                         , 0.0f                         , -1.0f                            , 0.0f
  )
};

#ifdef XGK_DATA_SSE
  static inline void m4_makeProjPersp128 (
    Mat4* m0,

    const float left,
    const float right,
    const float top,
    const float bottom,
    const float near_,
    const float far_
  ) {
    SET128(
      m0,

      2.0f * near_ / (right - left), 0.0f                         , (right + left) / (right - left)  , 0.0f                                   ,
      0.0f                         , 2.0f * near_ / (top - bottom), (top + bottom) / (top - bottom)  , 0.0f                                   ,
      0.0f                         , 0.0f                         , -(far_ + near_) / (far_ - near_) , -(2.0f * far_ * near_) / (far_ - near_),
      0.0f                         , 0.0f                         , -1.0f                            , 0.0f
    )
  };
#endif

#ifdef XGK_DATA_AVX
  static inline void m4_makeProjPersp256 (
    Mat4* m0,

    const float left,
    const float right,
    const float top,
    const float bottom,
    const float near_,
    const float far_
  ) {
    SET256(
      m0,

      2.0f * near_ / (right - left), 0.0f                         , (right + left) / (right - left)  , 0.0f                                   ,
      0.0f                         , 2.0f * near_ / (top - bottom), (top + bottom) / (top - bottom)  , 0.0f                                   ,
      0.0f                         , 0.0f                         , -(far_ + near_) / (far_ - near_) , -(2.0f * far_ * near_) / (far_ - near_),
      0.0f                         , 0.0f                         , -1.0f                            , 0.0f
    )
  };
#endif

static inline void m4_makeProjPersp32_2 (
  Mat4* m0,

  const float fov,
  const float aspect,
  const float near_,
  const float far_,
  const float zoom
) {
  const float top = near_ * tan(0.017453292f * 0.5f * fov) / zoom;
  const float height = 2.0f * top;
  const float bottom = top - height;
  const float width = aspect * height;
  const float left = -0.5f * width;
  const float right = left + width;

  SET32(
    m0,

    2.0f * near_ / (right - left), 0.0f                         , (right + left) / (right - left)  , 0.0f                                   ,
    0.0f                         , 2.0f * near_ / (top - bottom), (top + bottom) / (top - bottom)  , 0.0f                                   ,
    0.0f                         , 0.0f                         , -(far_ + near_) / (far_ - near_) , -(2.0f * far_ * near_) / (far_ - near_),
    0.0f                         , 0.0f                         , -1.0f                            , 0.0f
  )
};

#ifdef XGK_DATA_SSE
  static inline void m4_makeProjPersp128_2 (
    Mat4* m0,

    const float fov,
    const float aspect,
    const float near_,
    const float far_,
    const float zoom
  ) {
    const float top = near_ * tan(0.017453292f * 0.5f * fov) / zoom;
    const float height = 2.0f * top;
    const float bottom = top - height;
    const float width = aspect * height;
    const float left = -0.5f * width;
    const float right = left + width;

    SET128(
      m0,

      2.0f * near_ / (right - left), 0.0f                         , (right + left) / (right - left)  , 0.0f                                   ,
      0.0f                         , 2.0f * near_ / (top - bottom), (top + bottom) / (top - bottom)  , 0.0f                                   ,
      0.0f                         , 0.0f                         , -(far_ + near_) / (far_ - near_) , -(2.0f * far_ * near_) / (far_ - near_),
      0.0f                         , 0.0f                         , -1.0f                            , 0.0f
    )
  };
#endif

#ifdef XGK_DATA_AVX
  static inline void m4_makeProjPersp256_2 (
    Mat4* m0,

    const float fov,
    const float aspect,
    const float near_,
    const float far_,
    const float zoom
  ) {
    const float top = near_ * tan(0.017453292f * 0.5f * fov) / zoom;
    const float height = 2.0f * top;
    const float bottom = top - height;
    const float width = aspect * height;
    const float left = -0.5f * width;
    const float right = left + width;

    SET256(
      m0,

      2.0f * near_ / (right - left), 0.0f                         , (right + left) / (right - left)  , 0.0f                                   ,
      0.0f                         , 2.0f * near_ / (top - bottom), (top + bottom) / (top - bottom)  , 0.0f                                   ,
      0.0f                         , 0.0f                         , -(far_ + near_) / (far_ - near_) , -(2.0f * far_ * near_) / (far_ - near_),
      0.0f                         , 0.0f                         , -1.0f                            , 0.0f
    )
  };
#endif

///////
///////
///////



// MAKE ROTATION
////////////////
////////////////

static inline void m4_makeRot32 (Mat4* m0, Quat* q0) {
  const float xx = 2.0f * q0->_32[0] * q0->_32[0];
  const float yy = 2.0f * q0->_32[1] * q0->_32[1];
  const float zz = 2.0f * q0->_32[2] * q0->_32[2];
  const float xy = 2.0f * q0->_32[0] * q0->_32[1];
  const float xz = 2.0f * q0->_32[0] * q0->_32[2];
  const float xw = 2.0f * q0->_32[0] * q0->_32[3];
  const float yz = 2.0f * q0->_32[1] * q0->_32[2];
  const float yw = 2.0f * q0->_32[1] * q0->_32[3];
  const float zw = 2.0f * q0->_32[2] * q0->_32[3];

  SET32(
    m0,

    1.0f - yy - zz, xy - zw       , xz + yw       , 0.0f,
    xy + zw       , 1.0f - xx - zz, yz - xw       , 0.0f,
    xz - yw       , yz + xw       , 1.0f - xx - yy, 0.0f,
    0.0f          , 0.0f          , 0.0f          , 1.0f
  )
};

#ifdef XGK_DATA_SSE
  static inline void m4_makeRot128 (Mat4* m0, Quat* q0) {
    const float xx = 2.0f * q0->_32[0] * q0->_32[0];
    const float yy = 2.0f * q0->_32[1] * q0->_32[1];
    const float zz = 2.0f * q0->_32[2] * q0->_32[2];
    const float xy = 2.0f * q0->_32[0] * q0->_32[1];
    const float xz = 2.0f * q0->_32[0] * q0->_32[2];
    const float xw = 2.0f * q0->_32[0] * q0->_32[3];
    const float yz = 2.0f * q0->_32[1] * q0->_32[2];
    const float yw = 2.0f * q0->_32[1] * q0->_32[3];
    const float zw = 2.0f * q0->_32[2] * q0->_32[3];

    SET128(
      m0,

      1.0f - yy - zz, xy - zw       , xz + yw       , 0.0f,
      xy + zw       , 1.0f - xx - zz, yz - xw       , 0.0f,
      xz - yw       , yz + xw       , 1.0f - xx - yy, 0.0f,
      0.0f          , 0.0f          , 0.0f          , 1.0f
    )
  };
#endif

#ifdef XGK_DATA_AVX
  static inline void m4_makeRot256 (Mat4* m0, Quat* q0) {
    const float xx = 2.0f * q0->_32[0] * q0->_32[0];
    const float yy = 2.0f * q0->_32[1] * q0->_32[1];
    const float zz = 2.0f * q0->_32[2] * q0->_32[2];
    const float xy = 2.0f * q0->_32[0] * q0->_32[1];
    const float xz = 2.0f * q0->_32[0] * q0->_32[2];
    const float xw = 2.0f * q0->_32[0] * q0->_32[3];
    const float yz = 2.0f * q0->_32[1] * q0->_32[2];
    const float yw = 2.0f * q0->_32[1] * q0->_32[3];
    const float zw = 2.0f * q0->_32[2] * q0->_32[3];

    SET256(
      m0,

      1.0f - yy - zz, xy - zw       , xz + yw       , 0.0f,
      xy + zw       , 1.0f - xx - zz, yz - xw       , 0.0f,
      xz - yw       , yz + xw       , 1.0f - xx - yy, 0.0f,
      0.0f          , 0.0f          , 0.0f          , 1.0f
    )
  };
#endif

static inline void m4_makeRotX32 (Mat4* m0, const float angle) {
  const float cos_ = cos(angle);
  const float sin_ = sin(angle);

  SET32(
    m0,

    1.0f, 0.0f , 0.0f, 0.0f,
    0.0f, cos_ , sin_, 0.0f,
    0.0f, -sin_, cos_, 0.0f,
    0.0f, 0.0f , 0.0f, 1.0f
  )
};

#ifdef XGK_DATA_SSE
  static inline void m4_makeRotX128 (Mat4* m0, const float angle) {
    const float cos_ = cos(angle);
    const float sin_ = sin(angle);

    SET128(
      m0,

      1.0f, 0.0f , 0.0f, 0.0f,
      0.0f, cos_ , sin_, 0.0f,
      0.0f, -sin_, cos_, 0.0f,
      0.0f, 0.0f , 0.0f, 1.0f
    )
  };
#endif

#ifdef XGK_DATA_AVX
  static inline void m4_makeRotX256 (Mat4* m0, const float angle) {
    const float cos_ = cos(angle);
    const float sin_ = sin(angle);

    SET256(
      m0,

      1.0f, 0.0f , 0.0f, 0.0f,
      0.0f, cos_ , sin_, 0.0f,
      0.0f, -sin_, cos_, 0.0f,
      0.0f, 0.0f , 0.0f, 1.0f
    )
  };
#endif

///////
///////
///////



// MAKE TRANSLATION
///////////////////
///////////////////

static inline void m4_makeTrans32 (Mat4* m0, Vec4* axis, const float value) {
  SET32(
    m0,

    1.0f, 0.0f, 0.0f, axis->_32[0] * value,
    0.0f, 1.0f, 0.0f, axis->_32[1] * value,
    0.0f, 0.0f, 1.0f, axis->_32[2] * value,
    0.0f, 0.0f, 0.0f, 1.0f
  )
};

#ifdef XGK_DATA_SSE
  static inline void m4_makeTrans128 (Mat4* m0, Vec4* axis, const float value) {
    SET128(
      m0,

      1.0f, 0.0f, 0.0f, axis->_32[0] * value,
      0.0f, 1.0f, 0.0f, axis->_32[1] * value,
      0.0f, 0.0f, 1.0f, axis->_32[2] * value,
      0.0f, 0.0f, 0.0f, 1.0f
    )
  };

  static inline void m4_makeTrans128_ (Mat4* m0, Vec4* axis, const float value) {
    m4_reset(m0);

    m0->_128[3] = _mm_mul_ps(axis->_128, _mm_set1_ps(value));

    m0->_32[15] = 1.0f;
  };
#endif

#ifdef XGK_DATA_AVX
  static inline void m4_makeTrans256 (Mat4* m0, Vec4* axis, const float value) {
    SET256(
      m0,

      1.0f, 0.0f, 0.0f, axis->_32[0] * value,
      0.0f, 1.0f, 0.0f, axis->_32[1] * value,
      0.0f, 0.0f, 1.0f, axis->_32[2] * value,
      0.0f, 0.0f, 0.0f, 1.0f
    )
  };
#endif

///////
///////
///////



// SIMD
///////
///////

// There is no way to have common 'm4_set' function pointer, because each of 'm4_set32', 'm4_set128' and 'm4_set256' is different in the arguments number.
// So, it's preferable to use 'm4_set32' for portability.

static inline void m4_simd32 () {
  m4_premul = m4_premul32;
  m4_postmul = m4_postmul32;
  m4_muls = m4_muls32;
  m4_invns = m4_invns32;
  m4_makeProjPersp = m4_makeProjPersp32;
  m4_makeProjPersp_ = m4_makeProjPersp32_2;
  m4_makeRot = m4_makeRot32;
  m4_makeRotX = m4_makeRotX32;
  m4_makeTrans = m4_makeTrans32;
};

#ifdef XGK_DATA_SSE
  static static inline void m4_simd128 () {
    m4_premul = m4_premul128;
    m4_postmul = m4_postmul128;
    m4_muls = m4_muls128;
    m4_invns = m4_invns128;
    m4_makeProjPersp = m4_makeProjPersp128;
    m4_makeProjPersp_ = m4_makeProjPersp128_2;
    m4_makeRot = m4_makeRot128;
    m4_makeRotX = m4_makeRotX128;
    m4_makeTrans = m4_makeTrans128;
  };
#endif

#ifdef XGK_DATA_AVX
  static static inline void m4_simd256 () {
    m4_premul = m4_premul256;
    m4_postmul = m4_postmul256;
    m4_muls = m4_muls256;
    m4_invns = m4_invns256;
    m4_makeProjPersp = m4_makeProjPersp256;
    m4_makeProjPersp_ = m4_makeProjPersp256_2;
    m4_makeRot = m4_makeRot256;
    m4_makeRotX = m4_makeRotX256;
    m4_makeTrans = m4_makeTrans256;
  };
#endif

/////
/////
/////