namespace XGK {

  namespace DATA {

    // #pragma pack(push, 16)
    //   union Mat4 {

    //     float f32[16];

    //     #ifdef XGK_DATA_MACRO_SSE
    //       __m128 f128[4];
    //     #endif

    //     #ifdef XGK_DATA_MACRO_AVX
    //       __m256 f256[4];
    //     #endif
    //   };
    // #pragma pack(pop)



    namespace MAT4 {

      // column-major 4x4 matrix

      #define F32(item) ((float*) item)
      #define F128(item) ((__m128*) item)
      #define F256(item) ((__m256*) item)

      #define SET32(\
        data,\
        \
        e0, e4, e8 , e12,\
        e1, e5, e9 , e13,\
        e2, e6, e10, e14,\
        e3, e7, e11, e15\
      )\
        data[0]  = e0 ; data[1]  = e1 ; data[2]  = e2 ; data[3]  = e3 ;\
        data[4]  = e4 ; data[5]  = e5 ; data[6]  = e6 ; data[7]  = e7 ;\
        data[8]  = e8 ; data[9]  = e9 ; data[10] = e10; data[11] = e11;\
        data[12] = e12; data[13] = e13; data[14] = e14; data[15] = e15;

      #ifdef XGK_DATA_MACRO_SSE
        #define SET128(\
          data,\
          \
          e0, e4, e8 , e12,\
          e1, e5, e9 , e13,\
          e2, e6, e10, e14,\
          e3, e7, e11, e15\
        )\
          data[0] = _mm_setr_ps(e0,  e1,  e2 , e3 );\
          data[1] = _mm_setr_ps(e4,  e5,  e6 , e7 );\
          data[2] = _mm_setr_ps(e8,  e9,  e10, e11);\
          data[3] = _mm_setr_ps(e12, e13, e14, e15);
      #endif

      #ifdef XGK_DATA_MACRO_AVX
        #define SET256(\
          data,\
          \
          e0, e4, e8 , e12,\
          e1, e5, e9 , e13,\
          e2, e6, e10, e14,\
          e3, e7, e11, e15\
        )\
          data[0] = _mm256_setr_ps(e0, e1, e2 , e3 , e4 , e5 , e6 , e7 );\
          data[1] = _mm256_setr_ps(e8, e9, e10, e11, e12, e13, e14, e15);
      #endif



      const float FLOAT_SIZE_16 = sizeof(float) * 16;
      const float CONST_IDENTITY[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
      };



      void (* premul) (void*, void*) = nullptr;
      void (* postmul) (void*, void*) = nullptr;
      void (* muls) (void*, const float) = nullptr;
      void (* invns) (void*) = nullptr;
      void (* makeProjPersp) (void*, const float, const float, const float, const float, const float, const float) = nullptr;
      void (* makeProjPersp2) (void*, const float, const float, const float, const float, const float) = nullptr;
      void (* makeRot) (void*, void*) = nullptr;
      void (* makeRotX) (void*, const float) = nullptr;
      void (* makeTrans) (void*, void*, const float) = nullptr;



      // COPY
      ///////
      ///////

      inline void copy (void* m0, void* m1) {

        memcpy(m0, m1, FLOAT_SIZE_16);
      };

      ///////
      ///////
      ///////



      // RESET
      ////////
      ////////

      inline void reset (void* m0) {

        memcpy(m0, CONST_IDENTITY, FLOAT_SIZE_16);
      };

      ///////
      ///////
      ///////



      // SET
      //////
      //////

      #define args \
        void* data,\
        \
        const float e0, const float e4, const float e8 , const float e12,\
        const float e1, const float e5, const float e9 , const float e13,\
        const float e2, const float e6, const float e10, const float e14,\
        const float e3, const float e7, const float e11, const float e15

      inline void set32 (args) {

        SET32(
          F32(data),

          e0, e4, e8 , e12,
          e1, e5, e9 , e13,
          e2, e6, e10, e14,
          e3, e7, e11, e15
        )
      };

      #ifdef XGK_DATA_MACRO_SSE
        inline void set128 (args) {

          SET128(
            F128(data),

            e0, e4, e8 , e12,
            e1, e5, e9 , e13,
            e2, e6, e10, e14,
            e3, e7, e11, e15
          )
        };
      #endif

      #ifdef XGK_DATA_MACRO_AVX
        inline void set256 (args) {

          SET256(
            F256(data),

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

      #define a F32(data1)
      #define b F32(data0)

      inline void premul32 (void* data0, void* data1) {

        set32(
          F32(data0),

          (a[0] * b[0]) + (a[4] * b[1]) + (a[8]  * b[2]) + (a[12] * b[3]),  (a[0] * b[4]) + (a[4] * b[5]) + (a[8]  * b[6]) + (a[12] * b[7]),  (a[0] * b[8]) + (a[4] * b[9]) + (a[8]  * b[10]) + (a[12] * b[11]),  (a[0] * b[12]) + (a[4] * b[13]) + (a[8]  * b[14]) + (a[12] * b[15]),
          (a[1] * b[0]) + (a[5] * b[1]) + (a[9]  * b[2]) + (a[13] * b[3]),  (a[1] * b[4]) + (a[5] * b[5]) + (a[9]  * b[6]) + (a[13] * b[7]),  (a[1] * b[8]) + (a[5] * b[9]) + (a[9]  * b[10]) + (a[13] * b[11]),  (a[1] * b[12]) + (a[5] * b[13]) + (a[9]  * b[14]) + (a[13] * b[15]),
          (a[2] * b[0]) + (a[6] * b[1]) + (a[10] * b[2]) + (a[14] * b[3]),  (a[2] * b[4]) + (a[6] * b[5]) + (a[10] * b[6]) + (a[14] * b[7]),  (a[2] * b[8]) + (a[6] * b[9]) + (a[10] * b[10]) + (a[14] * b[11]),  (a[2] * b[12]) + (a[6] * b[13]) + (a[10] * b[14]) + (a[14] * b[15]),
          (a[3] * b[0]) + (a[7] * b[1]) + (a[11] * b[2]) + (a[15] * b[3]),  (a[3] * b[4]) + (a[7] * b[5]) + (a[11] * b[6]) + (a[15] * b[7]),  (a[3] * b[8]) + (a[7] * b[9]) + (a[11] * b[10]) + (a[15] * b[11]),  (a[3] * b[12]) + (a[7] * b[13]) + (a[11] * b[14]) + (a[15] * b[15])
        );
      };

      #undef b
      #undef a

      #ifdef XGK_DATA_MACRO_SSE
        inline void premul128 (void* data0, void* data1) {

          alignas(16) const __m128 a = _mm_load_ps(F32(data0));
          alignas(16) const __m128 b = _mm_load_ps(F32(data0) + 4);
          alignas(16) const __m128 c = _mm_load_ps(F32(data0) + 8);
          alignas(16) const __m128 d = _mm_load_ps(F32(data0) + 12);

          F128(data0)[0] = _mm_mul_ps(a, _mm_set1_ps(F32(data1)[0]));
          F128(data0)[1] = _mm_mul_ps(a, _mm_set1_ps(F32(data1)[4]));
          F128(data0)[2] = _mm_mul_ps(a, _mm_set1_ps(F32(data1)[8]));
          F128(data0)[3] = _mm_mul_ps(a, _mm_set1_ps(F32(data1)[12]));

          F128(data0)[0] = _mm_add_ps(F128(data0)[0], _mm_mul_ps(b, _mm_set1_ps(F32(data1)[1])));
          F128(data0)[1] = _mm_add_ps(F128(data0)[1], _mm_mul_ps(b, _mm_set1_ps(F32(data1)[5])));
          F128(data0)[2] = _mm_add_ps(F128(data0)[2], _mm_mul_ps(b, _mm_set1_ps(F32(data1)[9])));
          F128(data0)[3] = _mm_add_ps(F128(data0)[3], _mm_mul_ps(b, _mm_set1_ps(F32(data1)[13])));

          F128(data0)[0] = _mm_add_ps(F128(data0)[0], _mm_mul_ps(c, _mm_set1_ps(F32(data1)[2])));
          F128(data0)[1] = _mm_add_ps(F128(data0)[1], _mm_mul_ps(c, _mm_set1_ps(F32(data1)[6])));
          F128(data0)[2] = _mm_add_ps(F128(data0)[2], _mm_mul_ps(c, _mm_set1_ps(F32(data1)[10])));
          F128(data0)[3] = _mm_add_ps(F128(data0)[3], _mm_mul_ps(c, _mm_set1_ps(F32(data1)[14])));

          F128(data0)[0] = _mm_add_ps(F128(data0)[0], _mm_mul_ps(d, _mm_set1_ps(F32(data1)[3])));
          F128(data0)[1] = _mm_add_ps(F128(data0)[1], _mm_mul_ps(d, _mm_set1_ps(F32(data1)[7])));
          F128(data0)[2] = _mm_add_ps(F128(data0)[2], _mm_mul_ps(d, _mm_set1_ps(F32(data1)[11])));
          F128(data0)[3] = _mm_add_ps(F128(data0)[3], _mm_mul_ps(d, _mm_set1_ps(F32(data1)[15])));
        };
      #endif

      #ifdef XGK_DATA_MACRO_AVX
        inline void premul256 (void* data0, void* data1) {

          const __m256 a = _mm256_dp_ps(F256(data0)[0], F256(data1)[0], 0xff);
          const __m256 b = _mm256_dp_ps(F256(data0)[0], F256(data1)[1], 0xff);
          const __m256 c = _mm256_dp_ps(F256(data0)[1], F256(data1)[0], 0xff);
          const __m256 d = _mm256_dp_ps(F256(data0)[1], F256(data1)[1], 0xff);

          const __m256 _0 = _mm256_set_m128(F128(data0)[0], F128(data0)[1]);
          const __m256 _1 = _mm256_set_m128(F128(data0)[2], F128(data0)[3]);

          const __m256 e = _mm256_dp_ps(_0, F256(data1)[0], 0xff);
          const __m256 f = _mm256_dp_ps(_0, F256(data1)[1], 0xff);
          const __m256 g = _mm256_dp_ps(_1, F256(data1)[0], 0xff);
          const __m256 h = _mm256_dp_ps(_1, F256(data1)[1], 0xff);

          SET256(
            F256(data0),

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



      // // POSTMULTIPLY
      // ///////////////
      // ///////////////

      // #define a m0->f32
      // #define b m1->f32

      // inline void postmul32 (Mat4* m0, Mat4* m1) {

      //   SET32(
      //     m0,

      //     (a[0] * b[0]) + (a[4] * b[1]) + (a[8]  * b[2]) + (a[12] * b[3]),  (a[0] * b[4]) + (a[4] * b[5]) + (a[8]  * b[6]) + (a[12] * b[7]),  (a[0] * b[8]) + (a[4] * b[9]) + (a[8]  * b[10]) + (a[12] * b[11]),  (a[0] * b[12]) + (a[4] * b[13]) + (a[8]  * b[14]) + (a[12] * b[15]),
      //     (a[1] * b[0]) + (a[5] * b[1]) + (a[9]  * b[2]) + (a[13] * b[3]),  (a[1] * b[4]) + (a[5] * b[5]) + (a[9]  * b[6]) + (a[13] * b[7]),  (a[1] * b[8]) + (a[5] * b[9]) + (a[9]  * b[10]) + (a[13] * b[11]),  (a[1] * b[12]) + (a[5] * b[13]) + (a[9]  * b[14]) + (a[13] * b[15]),
      //     (a[2] * b[0]) + (a[6] * b[1]) + (a[10] * b[2]) + (a[14] * b[3]),  (a[2] * b[4]) + (a[6] * b[5]) + (a[10] * b[6]) + (a[14] * b[7]),  (a[2] * b[8]) + (a[6] * b[9]) + (a[10] * b[10]) + (a[14] * b[11]),  (a[2] * b[12]) + (a[6] * b[13]) + (a[10] * b[14]) + (a[14] * b[15]),
      //     (a[3] * b[0]) + (a[7] * b[1]) + (a[11] * b[2]) + (a[15] * b[3]),  (a[3] * b[4]) + (a[7] * b[5]) + (a[11] * b[6]) + (a[15] * b[7]),  (a[3] * b[8]) + (a[7] * b[9]) + (a[11] * b[10]) + (a[15] * b[11]),  (a[3] * b[12]) + (a[7] * b[13]) + (a[11] * b[14]) + (a[15] * b[15])
      //   )
      // };

      // #undef b
      // #undef a

      // #ifdef XGK_DATA_MACRO_SSE
      //   #define dot(row, col) GET_F32(_mm_dp_ps(rows[row], m0->f128[col], 0xff), 0)

      //   inline void postmul128 (Mat4* m0, Mat4* m1) {

      //     const __m128 rows[4] = {
      //       _mm_setr_ps(m1->f32[0], m1->f32[4], m1->f32[8] , m1->f32[12]),
      //       _mm_setr_ps(m1->f32[1], m1->f32[5], m1->f32[9] , m1->f32[13]),
      //       _mm_setr_ps(m1->f32[2], m1->f32[6], m1->f32[10], m1->f32[14]),
      //       _mm_setr_ps(m1->f32[3], m1->f32[7], m1->f32[11], m1->f32[15])
      //     };

      //     SET128(
      //       m0,

      //       dot(0, 0), dot(1, 0), dot(2, 0), dot(3, 0),
      //       dot(0, 1), dot(1, 1), dot(2, 1), dot(3, 1),
      //       dot(0, 2), dot(1, 2), dot(2, 2), dot(3, 2),
      //       dot(0, 3), dot(1, 3), dot(2, 3), dot(3, 3)
      //     )
      //   };

      //   #undef dot
      // #endif

      // #ifdef XGK_DATA_MACRO_AVX
      //   inline void postmul256 (Mat4* m0, Mat4* m1) {

      //     const __m256 a = _mm256_dp_ps(m1->f256[0], m0->f256[0], 0xff);
      //     const __m256 b = _mm256_dp_ps(m1->f256[0], m0->f256[1], 0xff);
      //     const __m256 c = _mm256_dp_ps(m1->f256[1], m0->f256[0], 0xff);
      //     const __m256 d = _mm256_dp_ps(m1->f256[1], m0->f256[1], 0xff);

      //     const __m256 _0 = _mm256_set_m128(m1->f128[0], m1->f128[1]);
      //     const __m256 _1 = _mm256_set_m128(m1->f128[2], m1->f128[3]);

      //     const __m256 e = _mm256_dp_ps(_0, m0->f256[0], 0xff);
      //     const __m256 f = _mm256_dp_ps(_0, m0->f256[1], 0xff);
      //     const __m256 g = _mm256_dp_ps(_1, m0->f256[0], 0xff);
      //     const __m256 h = _mm256_dp_ps(_1, m0->f256[1], 0xff);

      //     SET256(
      //       m0,

      //       a[0], e[4], b[0], f[4],
      //       e[0], a[4], f[0], b[4],
      //       c[0], g[4], d[0], h[4],
      //       g[0], c[4], h[0], d[4]
      //     )
      //   };
      // #endif

      // ///////
      // ///////
      // ///////



      // // MULTIPLY SCALAR
      // //////////////////
      // //////////////////

      // inline void muls32 (Mat4* m, const float s) {

      //   m->f32[0]  *= s; m->f32[1]  *= s; m->f32[2]  *= s; m->f32[3]  *= s;
      //   m->f32[4]  *= s; m->f32[5]  *= s; m->f32[6]  *= s; m->f32[7]  *= s;
      //   m->f32[8]  *= s; m->f32[9]  *= s; m->f32[10] *= s; m->f32[11] *= s;
      //   m->f32[12] *= s; m->f32[13] *= s; m->f32[14] *= s; m->f32[15] *= s;
      // };

      // #ifdef XGK_DATA_MACRO_SSE
      //   inline void muls128 (Mat4* m, const float s) {

      //     const __m128 s128 = _mm_set1_ps(s);

      //     m->f128[0] = _mm_mul_ps(m->f128[0], s128);
      //     m->f128[1] = _mm_mul_ps(m->f128[1], s128);
      //     m->f128[2] = _mm_mul_ps(m->f128[2], s128);
      //     m->f128[3] = _mm_mul_ps(m->f128[3], s128);
      //   };
      // #endif

      // #ifdef XGK_DATA_MACRO_AVX
      //   inline void muls256 (Mat4* m, const float s) {

      //     const __m256 s256 = _mm256_set1_ps(s);

      //     m->f256[0] = _mm256_mul_ps(m->f256[0], s256);
      //     m->f256[1] = _mm256_mul_ps(m->f256[1], s256);
      //   };
      // #endif

      // ///////
      // ///////
      // ///////



      // // INVERSE TRANSFORM NO SCALE
      // /////////////////////////////
      // /////////////////////////////

      // #define a m0->f32
      // #define b m0->f128

      // inline void invns32 (Mat4* m0) {

      //   SET32(
      //     m0,

      //     a[0], a[1], a[2] , -(a[0] * a[12]) - (a[1] * a[13]) - (a[2]  * a[14]),
      //     a[4], a[5], a[6] , -(a[4] * a[12]) - (a[5] * a[13]) - (a[6]  * a[14]),
      //     a[8], a[9], a[10], -(a[8] * a[12]) - (a[9] * a[13]) - (a[10] * a[14]),
      //     0   , 0   , 0    , 1
      //   )
      // };

      // #ifdef XGK_DATA_MACRO_SSE
      //   inline void invns128 (Mat4* m0) {

      //     SET128(
      //       m0,

      //       a[0], a[1], a[2] , GET_F32(-_mm_dp_ps(b[0], b[3], 0xff), 0),
      //       a[4], a[5], a[6] , GET_F32(-_mm_dp_ps(b[1], b[3], 0xff), 0),
      //       a[8], a[9], a[10], GET_F32(-_mm_dp_ps(b[2], b[3], 0xff), 0),
      //       0   , 0   , 0    , 1
      //     )
      //   };
      // #endif

      // #ifdef XGK_DATA_MACRO_AVX
      //   inline void invns256 (Mat4* m0) {

      //     SET256(
      //       m0,

      //       a[0], a[1], a[2] , GET_F32(-_mm_dp_ps(b[0], b[3], 0xff), 0),
      //       a[4], a[5], a[6] , GET_F32(-_mm_dp_ps(b[1], b[3], 0xff), 0),
      //       a[8], a[9], a[10], GET_F32(-_mm_dp_ps(b[2], b[3], 0xff), 0),
      //       0   , 0   , 0    , 1
      //     )
      //   };
      // #endif

      // #undef b
      // #undef a

      // ///////
      // ///////
      // ///////



      // // MAKE PERSPECTIVE PROJECTION
      // //////////////////////////////
      // //////////////////////////////

      // inline void makeProjPersp32 (
      //   Mat4* m0,

      //   const float left,
      //   const float right,
      //   const float top,
      //   const float bottom,
      //   const float near_,
      //   const float far_
      // ) {

      //   SET32(
      //     m0,

      //     2.0f * near_ / (right - left), 0.0f                         , (right + left) / (right - left)  , 0.0f                                   ,
      //     0.0f                         , 2.0f * near_ / (top - bottom), (top + bottom) / (top - bottom)  , 0.0f                                   ,
      //     0.0f                         , 0.0f                         , -(far_ + near_) / (far_ - near_) , -(2.0f * far_ * near_) / (far_ - near_),
      //     0.0f                         , 0.0f                         , -1.0f                            , 0.0f
      //   )
      // };

      // #ifdef XGK_DATA_MACRO_SSE
      //   inline void makeProjPersp128 (
      //     Mat4* m0,

      //     const float left,
      //     const float right,
      //     const float top,
      //     const float bottom,
      //     const float near_,
      //     const float far_
      //   ) {

      //     SET128(
      //       m0,

      //       2.0f * near_ / (right - left), 0.0f                         , (right + left) / (right - left)  , 0.0f                                   ,
      //       0.0f                         , 2.0f * near_ / (top - bottom), (top + bottom) / (top - bottom)  , 0.0f                                   ,
      //       0.0f                         , 0.0f                         , -(far_ + near_) / (far_ - near_) , -(2.0f * far_ * near_) / (far_ - near_),
      //       0.0f                         , 0.0f                         , -1.0f                            , 0.0f
      //     )
      //   };
      // #endif

      // #ifdef XGK_DATA_MACRO_AVX
      //   inline void makeProjPersp256 (
      //     Mat4* m0,

      //     const float left,
      //     const float right,
      //     const float top,
      //     const float bottom,
      //     const float near_,
      //     const float far_
      //   ) {

      //     SET256(
      //       m0,

      //       2.0f * near_ / (right - left), 0.0f                         , (right + left) / (right - left)  , 0.0f                                   ,
      //       0.0f                         , 2.0f * near_ / (top - bottom), (top + bottom) / (top - bottom)  , 0.0f                                   ,
      //       0.0f                         , 0.0f                         , -(far_ + near_) / (far_ - near_) , -(2.0f * far_ * near_) / (far_ - near_),
      //       0.0f                         , 0.0f                         , -1.0f                            , 0.0f
      //     )
      //   };
      // #endif

      inline void makeProjPersp32 (
        void* m0,

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
          F32(m0),

          2.0f * near_ / (right - left), 0.0f                         , (right + left) / (right - left)  , 0.0f                                   ,
          0.0f                         , 2.0f * near_ / (top - bottom), (top + bottom) / (top - bottom)  , 0.0f                                   ,
          0.0f                         , 0.0f                         , -(far_ + near_) / (far_ - near_) , -(2.0f * far_ * near_) / (far_ - near_),
          0.0f                         , 0.0f                         , -1.0f                            , 0.0f
        )
      };

      #ifdef XGK_DATA_MACRO_SSE
        inline void makeProjPersp128 (
          void* m0,

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
            F128(m0),

            2.0f * near_ / (right - left), 0.0f                         , (right + left) / (right - left)  , 0.0f                                   ,
            0.0f                         , 2.0f * near_ / (top - bottom), (top + bottom) / (top - bottom)  , 0.0f                                   ,
            0.0f                         , 0.0f                         , -(far_ + near_) / (far_ - near_) , -(2.0f * far_ * near_) / (far_ - near_),
            0.0f                         , 0.0f                         , -1.0f                            , 0.0f
          )
        };
      #endif

      #ifdef XGK_DATA_MACRO_AVX
        inline void makeProjPersp256 (
          void* m0,

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
            F256(m0),

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



      // // MAKE ROTATION
      // ////////////////
      // ////////////////

      // inline void makeRot32 (Mat4* m0, float* q0) {

      //   const float xx = 2.0f * q0->f32[0] * q0->f32[0];
      //   const float yy = 2.0f * q0->f32[1] * q0->f32[1];
      //   const float zz = 2.0f * q0->f32[2] * q0->f32[2];
      //   const float xy = 2.0f * q0->f32[0] * q0->f32[1];
      //   const float xz = 2.0f * q0->f32[0] * q0->f32[2];
      //   const float xw = 2.0f * q0->f32[0] * q0->f32[3];
      //   const float yz = 2.0f * q0->f32[1] * q0->f32[2];
      //   const float yw = 2.0f * q0->f32[1] * q0->f32[3];
      //   const float zw = 2.0f * q0->f32[2] * q0->f32[3];

      //   SET32(
      //     m0,

      //     1.0f - yy - zz, xy - zw       , xz + yw       , 0.0f,
      //     xy + zw       , 1.0f - xx - zz, yz - xw       , 0.0f,
      //     xz - yw       , yz + xw       , 1.0f - xx - yy, 0.0f,
      //     0.0f          , 0.0f          , 0.0f          , 1.0f
      //   )
      // };

      // #ifdef XGK_DATA_MACRO_SSE
      //   inline void makeRot128 (Mat4* m0, float* q0) {

      //     const float xx = 2.0f * q0->f32[0] * q0->f32[0];
      //     const float yy = 2.0f * q0->f32[1] * q0->f32[1];
      //     const float zz = 2.0f * q0->f32[2] * q0->f32[2];
      //     const float xy = 2.0f * q0->f32[0] * q0->f32[1];
      //     const float xz = 2.0f * q0->f32[0] * q0->f32[2];
      //     const float xw = 2.0f * q0->f32[0] * q0->f32[3];
      //     const float yz = 2.0f * q0->f32[1] * q0->f32[2];
      //     const float yw = 2.0f * q0->f32[1] * q0->f32[3];
      //     const float zw = 2.0f * q0->f32[2] * q0->f32[3];

      //     SET128(
      //       m0,

      //       1.0f - yy - zz, xy - zw       , xz + yw       , 0.0f,
      //       xy + zw       , 1.0f - xx - zz, yz - xw       , 0.0f,
      //       xz - yw       , yz + xw       , 1.0f - xx - yy, 0.0f,
      //       0.0f          , 0.0f          , 0.0f          , 1.0f
      //     )
      //   };
      // #endif

      // #ifdef XGK_DATA_MACRO_AVX
      //   inline void makeRot256 (Mat4* m0, float* q0) {

      //     const float xx = 2.0f * q0->f32[0] * q0->f32[0];
      //     const float yy = 2.0f * q0->f32[1] * q0->f32[1];
      //     const float zz = 2.0f * q0->f32[2] * q0->f32[2];
      //     const float xy = 2.0f * q0->f32[0] * q0->f32[1];
      //     const float xz = 2.0f * q0->f32[0] * q0->f32[2];
      //     const float xw = 2.0f * q0->f32[0] * q0->f32[3];
      //     const float yz = 2.0f * q0->f32[1] * q0->f32[2];
      //     const float yw = 2.0f * q0->f32[1] * q0->f32[3];
      //     const float zw = 2.0f * q0->f32[2] * q0->f32[3];

      //     SET256(
      //       m0,

      //       1.0f - yy - zz, xy - zw       , xz + yw       , 0.0f,
      //       xy + zw       , 1.0f - xx - zz, yz - xw       , 0.0f,
      //       xz - yw       , yz + xw       , 1.0f - xx - yy, 0.0f,
      //       0.0f          , 0.0f          , 0.0f          , 1.0f
      //     )
      //   };
      // #endif

      // inline void makeRotX32 (Mat4* m0, const float angle) {

      //   const float cos_ = cos(angle);
      //   const float sin_ = sin(angle);

      //   SET32(
      //     m0,

      //     1.0f, 0.0f , 0.0f, 0.0f,
      //     0.0f, cos_ , sin_, 0.0f,
      //     0.0f, -sin_, cos_, 0.0f,
      //     0.0f, 0.0f , 0.0f, 1.0f
      //   )
      // };

      // #ifdef XGK_DATA_MACRO_SSE
      //   inline void makeRotX128 (Mat4* m0, const float angle) {

      //     const float cos_ = cos(angle);
      //     const float sin_ = sin(angle);

      //     SET128(
      //       m0,

      //       1.0f, 0.0f , 0.0f, 0.0f,
      //       0.0f, cos_ , sin_, 0.0f,
      //       0.0f, -sin_, cos_, 0.0f,
      //       0.0f, 0.0f , 0.0f, 1.0f
      //     )
      //   };
      // #endif

      // #ifdef XGK_DATA_MACRO_AVX
      //   inline void makeRotX256 (Mat4* m0, const float angle) {

      //     const float cos_ = cos(angle);
      //     const float sin_ = sin(angle);

      //     SET256(
      //       m0,

      //       1.0f, 0.0f , 0.0f, 0.0f,
      //       0.0f, cos_ , sin_, 0.0f,
      //       0.0f, -sin_, cos_, 0.0f,
      //       0.0f, 0.0f , 0.0f, 1.0f
      //     )
      //   };
      // #endif

      // ///////
      // ///////
      // ///////



      // MAKE TRANSLATION
      ///////////////////
      ///////////////////

      inline void makeTrans32 (void* m0, void* axis, const float value) {

        SET32(
          F32(m0),

          1.0f, 0.0f, 0.0f, F32(axis)[0] * value,
          0.0f, 1.0f, 0.0f, F32(axis)[1] * value,
          0.0f, 0.0f, 1.0f, F32(axis)[2] * value,
          0.0f, 0.0f, 0.0f, 1.0f
        )
      };

      #ifdef XGK_DATA_MACRO_SSE
        inline void makeTrans128 (void* m0, void* axis, const float value) {

          SET128(
            F128(m0),

            1.0f, 0.0f, 0.0f, F32(axis)[0] * value,
            0.0f, 1.0f, 0.0f, F32(axis)[1] * value,
            0.0f, 0.0f, 1.0f, F32(axis)[2] * value,
            0.0f, 0.0f, 0.0f, 1.0f
          )
        };

        inline void makeTrans128_ (void* m0, void* axis, const float value) {

          reset(m0);

          F128(m0)[3] = _mm_mul_ps(*F128(axis), _mm_set1_ps(value));

          F32(m0)[15] = 1.0f;
        };
      #endif

      #ifdef XGK_DATA_MACRO_AVX
        inline void makeTrans256 (void* m0, void* axis, const float value) {
          SET256(
            F256(m0),

            1.0f, 0.0f, 0.0f, F32(axis)[0] * value,
            0.0f, 1.0f, 0.0f, F32(axis)[1] * value,
            0.0f, 0.0f, 1.0f, F32(axis)[2] * value,
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

      // There is no way to have common 'set' function pointer, because each of 'set32', 'set128' and 'set256' is different in the arguments number.
      // So, it's preferable to use 'set32' for portability.

      // inline void simd32 () {

      //   premul = premul32;
      //   postmul = postmul32;
      //   muls = muls32;
      //   invns = invns32;
      //   makeProjPersp = makeProjPersp32;
      //   makeProjPersp2 = makeProjPersp32_2;
      //   makeRot = makeRot32;
      //   makeRotX = makeRotX32;
      //   makeTrans = makeTrans32;
      // };

      // #ifdef XGK_DATA_MACRO_SSE
      //   inline void simd128 () {

      //     premul = premul128;
      //     postmul = postmul128;
      //     muls = muls128;
      //     invns = invns128;
      //     makeProjPersp = makeProjPersp128;
      //     makeProjPersp2 = makeProjPersp128_2;
      //     makeRot = makeRot128;
      //     makeRotX = makeRotX128;
      //     makeTrans = makeTrans128;
      //   };
      // #endif

      // #ifdef XGK_DATA_MACRO_AVX
      //   inline void simd256 () {

      //     premul = premul256;
      //     postmul = postmul256;
      //     muls = muls256;
      //     invns = invns256;
      //     makeProjPersp = makeProjPersp256;
      //     makeProjPersp2 = makeProjPersp256_2;
      //     makeRot = makeRot256;
      //     makeRotX = makeRotX256;
      //     makeTrans = makeTrans256;
      //   };
      // #endif



      #ifdef DEBUG
        void print (void* data) {

          printf("%f %f %f %f\n", F32(data)[0], F32(data)[4], F32(data)[8] , F32(data)[12]);
          printf("%f %f %f %f\n", F32(data)[1], F32(data)[5], F32(data)[9] , F32(data)[13]);
          printf("%f %f %f %f\n", F32(data)[2], F32(data)[6], F32(data)[10], F32(data)[14]);
          printf("%f %f %f %f\n", F32(data)[3], F32(data)[7], F32(data)[11], F32(data)[15]);
        };
      #endif



      #ifdef XGK_DATA_MACRO_AVX
        #undef SET256
      #endif

      #ifdef XGK_DATA_MACRO_SSE
        #undef SET128
      #endif

      #undef SET32
      #undef F256
      #undef F128
      #undef F32

      /////
      /////
      /////
    };
  };
};
