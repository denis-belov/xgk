#define SET32(\
  matrix_addr_float,\
  \
  e0, e4, e8 , e12,\
  e1, e5, e9 , e13,\
  e2, e6, e10, e14,\
  e3, e7, e11, e15\
)\
  \
  matrix_addr_float[0] = e0; matrix_addr_float[4] = e4; matrix_addr_float[8]  = e8 ; matrix_addr_float[12] = e12;\
  matrix_addr_float[1] = e1; matrix_addr_float[5] = e5; matrix_addr_float[9]  = e9 ; matrix_addr_float[13] = e13;\
  matrix_addr_float[2] = e2; matrix_addr_float[6] = e6; matrix_addr_float[10] = e10; matrix_addr_float[14] = e14;\
  matrix_addr_float[3] = e3; matrix_addr_float[7] = e7; matrix_addr_float[11] = e11; matrix_addr_float[15] = e15;



#define MUL(dst_matrix_addr_m128, left_matrix_addr_float, right_matrix_addr_float)\
  \
  alignas(16) const __m128 a = _mm_load_ps(left_matrix_addr_float);\
  alignas(16) const __m128 b = _mm_load_ps(&left_matrix_addr_float[4]);\
  alignas(16) const __m128 c = _mm_load_ps(&left_matrix_addr_float[8]);\
  alignas(16) const __m128 d = _mm_load_ps(&left_matrix_addr_float[12]);\
  \
  dst_matrix_addr_m128[0] = _mm_mul_ps(a, _mm_set1_ps(right_matrix_addr_float[0]));\
  dst_matrix_addr_m128[1] = _mm_mul_ps(a, _mm_set1_ps(right_matrix_addr_float[4]));\
  dst_matrix_addr_m128[2] = _mm_mul_ps(a, _mm_set1_ps(right_matrix_addr_float[8]));\
  dst_matrix_addr_m128[3] = _mm_mul_ps(a, _mm_set1_ps(right_matrix_addr_float[12]));\
  \
  dst_matrix_addr_m128[0] = _mm_add_ps(dst_matrix_addr_m128[0], _mm_mul_ps(b, _mm_set1_ps(right_matrix_addr_float[1])));\
  dst_matrix_addr_m128[1] = _mm_add_ps(dst_matrix_addr_m128[1], _mm_mul_ps(b, _mm_set1_ps(right_matrix_addr_float[5])));\
  dst_matrix_addr_m128[2] = _mm_add_ps(dst_matrix_addr_m128[2], _mm_mul_ps(b, _mm_set1_ps(right_matrix_addr_float[9])));\
  dst_matrix_addr_m128[3] = _mm_add_ps(dst_matrix_addr_m128[3], _mm_mul_ps(b, _mm_set1_ps(right_matrix_addr_float[13])));\
  \
  dst_matrix_addr_m128[0] = _mm_add_ps(dst_matrix_addr_m128[0], _mm_mul_ps(c, _mm_set1_ps(right_matrix_addr_float[2])));\
  dst_matrix_addr_m128[1] = _mm_add_ps(dst_matrix_addr_m128[1], _mm_mul_ps(c, _mm_set1_ps(right_matrix_addr_float[6])));\
  dst_matrix_addr_m128[2] = _mm_add_ps(dst_matrix_addr_m128[2], _mm_mul_ps(c, _mm_set1_ps(right_matrix_addr_float[10])));\
  dst_matrix_addr_m128[3] = _mm_add_ps(dst_matrix_addr_m128[3], _mm_mul_ps(c, _mm_set1_ps(right_matrix_addr_float[14])));\
  \
  dst_matrix_addr_m128[0] = _mm_add_ps(dst_matrix_addr_m128[0], _mm_mul_ps(d, _mm_set1_ps(right_matrix_addr_float[3])));\
  dst_matrix_addr_m128[1] = _mm_add_ps(dst_matrix_addr_m128[1], _mm_mul_ps(d, _mm_set1_ps(right_matrix_addr_float[7])));\
  dst_matrix_addr_m128[2] = _mm_add_ps(dst_matrix_addr_m128[2], _mm_mul_ps(d, _mm_set1_ps(right_matrix_addr_float[11])));\
  dst_matrix_addr_m128[3] = _mm_add_ps(dst_matrix_addr_m128[3], _mm_mul_ps(d, _mm_set1_ps(right_matrix_addr_float[15])));



#define PREMUL_ROT_QUAT(dst_matrix_addr_m128, left_matrix_addr_float, right_matrix_addr_float)\
  \
  memcpy(dst_matrix_addr_m128, right_matrix_addr_float, FLOAT_SIZE_16);\
  \
  alignas(16) const __m128 a = _mm_load_ps(left_matrix_addr_float);\
  alignas(16) const __m128 b = _mm_load_ps(&left_matrix_addr_float[4]);\
  alignas(16) const __m128 c = _mm_load_ps(&left_matrix_addr_float[8]);\
  \
  dst_matrix_addr_m128[0] = _mm_mul_ps(a, _mm_set1_ps(right_matrix_addr_float[0]));\
  dst_matrix_addr_m128[1] = _mm_mul_ps(a, _mm_set1_ps(right_matrix_addr_float[4]));\
  dst_matrix_addr_m128[2] = _mm_mul_ps(a, _mm_set1_ps(right_matrix_addr_float[8]));\
  dst_matrix_addr_m128[3] += _mm_mul_ps(a, _mm_set1_ps(right_matrix_addr_float[12]));\
  \
  dst_matrix_addr_m128[0] = _mm_add_ps(dst_matrix_addr_m128[0], _mm_mul_ps(b, _mm_set1_ps(right_matrix_addr_float[1])));\
  dst_matrix_addr_m128[1] = _mm_add_ps(dst_matrix_addr_m128[1], _mm_mul_ps(b, _mm_set1_ps(right_matrix_addr_float[5])));\
  dst_matrix_addr_m128[2] = _mm_add_ps(dst_matrix_addr_m128[2], _mm_mul_ps(b, _mm_set1_ps(right_matrix_addr_float[9])));\
  dst_matrix_addr_m128[3] += _mm_add_ps(dst_matrix_addr_m128[3], _mm_mul_ps(b, _mm_set1_ps(right_matrix_addr_float[13])));\
  \
  dst_matrix_addr_m128[0] = _mm_add_ps(dst_matrix_addr_m128[0], _mm_mul_ps(c, _mm_set1_ps(right_matrix_addr_float[2])));\
  dst_matrix_addr_m128[1] = _mm_add_ps(dst_matrix_addr_m128[1], _mm_mul_ps(c, _mm_set1_ps(right_matrix_addr_float[6])));\
  dst_matrix_addr_m128[2] = _mm_add_ps(dst_matrix_addr_m128[2], _mm_mul_ps(c, _mm_set1_ps(right_matrix_addr_float[10])));\
  dst_matrix_addr_m128[3] += _mm_add_ps(dst_matrix_addr_m128[3], _mm_mul_ps(c, _mm_set1_ps(right_matrix_addr_float[14])));



#define POSTMUL_ROT_QUAT(dst_matrix_addr_m128, left_matrix_addr_float, right_matrix_addr_float)\
  \
  memcpy(dst_matrix_addr_m128, left_matrix_addr_float, FLOAT_SIZE_16);\
  \
  alignas(16) const __m128 a = _mm_load_ps(left_matrix_addr_float);\
  alignas(16) const __m128 b = _mm_load_ps(&left_matrix_addr_float[4]);\
  alignas(16) const __m128 c = _mm_load_ps(&left_matrix_addr_float[8]);\
  \
  dst_matrix_addr_m128[0] = _mm_mul_ps(a, _mm_set1_ps(right_matrix_addr_float[0]));\
  dst_matrix_addr_m128[1] = _mm_mul_ps(a, _mm_set1_ps(right_matrix_addr_float[4]));\
  dst_matrix_addr_m128[2] = _mm_mul_ps(a, _mm_set1_ps(right_matrix_addr_float[8]));\
  dst_matrix_addr_m128[3] += _mm_mul_ps(a, _mm_set1_ps(right_matrix_addr_float[12]));\
  \
  dst_matrix_addr_m128[0] = _mm_add_ps(dst_matrix_addr_m128[0], _mm_mul_ps(b, _mm_set1_ps(right_matrix_addr_float[1])));\
  dst_matrix_addr_m128[1] = _mm_add_ps(dst_matrix_addr_m128[1], _mm_mul_ps(b, _mm_set1_ps(right_matrix_addr_float[5])));\
  dst_matrix_addr_m128[2] = _mm_add_ps(dst_matrix_addr_m128[2], _mm_mul_ps(b, _mm_set1_ps(right_matrix_addr_float[9])));\
  dst_matrix_addr_m128[3] += _mm_add_ps(dst_matrix_addr_m128[3], _mm_mul_ps(b, _mm_set1_ps(right_matrix_addr_float[13])));\
  \
  dst_matrix_addr_m128[0] = _mm_add_ps(dst_matrix_addr_m128[0], _mm_mul_ps(c, _mm_set1_ps(right_matrix_addr_float[2])));\
  dst_matrix_addr_m128[1] = _mm_add_ps(dst_matrix_addr_m128[1], _mm_mul_ps(c, _mm_set1_ps(right_matrix_addr_float[6])));\
  dst_matrix_addr_m128[2] = _mm_add_ps(dst_matrix_addr_m128[2], _mm_mul_ps(c, _mm_set1_ps(right_matrix_addr_float[10])));\
  dst_matrix_addr_m128[3] += _mm_add_ps(dst_matrix_addr_m128[3], _mm_mul_ps(c, _mm_set1_ps(right_matrix_addr_float[14])));



#define PRETRANS(dst_matrix_addr_m128, vector_addr_float, right_matrix_addr_float)\
  \
  memcpy(dst_matrix_addr_m128, right_matrix_addr_float, FLOAT_SIZE_16);\
  \
  alignas(16) const __m128 vector_m128 = _mm_load_ps(&vector_addr_float[12]);\
  \
  alignas(16) const __m128 b = _mm_set1_ps(right_matrix_addr_float[3]);\
  alignas(16) const __m128 c = _mm_set1_ps(right_matrix_addr_float[7]);\
  alignas(16) const __m128 d = _mm_set1_ps(right_matrix_addr_float[11]);\
  alignas(16) const __m128 e = _mm_set1_ps(right_matrix_addr_float[15]);\
  \
  alignas(16) const __m128 f = _mm_load_ps(right_matrix_addr_float[0]);\
  alignas(16) const __m128 g = _mm_load_ps(right_matrix_addr_float[4]);\
  alignas(16) const __m128 h = _mm_load_ps(right_matrix_addr_float[8]);\
  alignas(16) const __m128 i = _mm_load_ps(right_matrix_addr_float[12]);\
  \
  dst_matrix_addr_m128[0] = _mm_add_ps(f, _mm_mul_ps(vector_m128, b));\
  dst_matrix_addr_m128[1] = _mm_add_ps(g, _mm_mul_ps(vector_m128, c));\
  dst_matrix_addr_m128[2] = _mm_add_ps(h, _mm_mul_ps(vector_m128, d));\
  dst_matrix_addr_m128[3] = _mm_add_ps(i, _mm_mul_ps(vector_m128, e));



#define MAKE_TRANS(matrix_addr_float, vector_addr)\
  \
  memcpy(matrix_addr_float, IDENT, FLOAT_SIZE_12);\
  memcpy(matrix_addr_float + 12, vector_addr, FLOAT_SIZE_3);



#define MAKE_TRANS_VALUE(matrix_addr_float, vector_addr_float, value)\
  \
  memcpy(matrix_addr_float, IDENT, FLOAT_SIZE_12);\
  \
  _mm_store_ps(matrix_addr_float + 12, _mm_mul_ps(_mm_load_ps(vector_addr_float), _mm_set1_ps(value)));\
  \
  matrix_addr_float[15] = 1.0f;



// 1 - (yy + zz), xy - zw      , xz + yw      , 0,
// xy + zw      , 1 - (xx + zz), yz - xw      , 0,
// xz - yw      , yz + xw      , 1 - (xx + yy), 0,
// 0            , 0            , 0            , 1

// xy = 2 * quat[0] * quat[1]
// xz = 2 * quat[0] * quat[2]
// yz = 2 * quat[1] * quat[2]

// xy_xz_yz = { 2, 2, 2, 0 } * shuffle(quat, quat, (0, 0, 1, 0)) * shuffle(quat, quat, (1, 2, 2, 0)) = { xy, xz, yz, 0 }

// zw = 2 * quat[2] * quat[3]
// yw = 2 * quat[1] * quat[3]
// xw = 2 * quat[0] * quat[3]

// zw_yw_xw = { 2, 2, 2, 0 } * shuffle(quat, quat, (2, 1, 0, 0)) * shuffle(quat, quat, (3, 3, 3, 0)) = { zw, yw, xw, 0 }

// sum = xy_xz_yz + zw_yw_xw
// dif = xy_xz_yz - zw_yw_xw

// yy = 2 * quat[1] * quat[1]
// xx = 2 * quat[0] * quat[0]
// xx = 2 * quat[0] * quat[0]

// zz = 2 * quat[2] * quat[2]
// zz = 2 * quat[2] * quat[2]
// yy = 2 * quat[1] * quat[1]

// pow = { 1, 1, 1, 0 } - { yy + zz, xx + zz, xx + yy, 0 } = { 1 - (yy + zz), 1 - (xx + zz), 1 - (xx + yy), 0 }

// pow[0], dif[0], sum[1],
// sum[0], pow[1], dif[2],
// dif[1], sum[2], pow[2],
// 0     , 0     , 0

// aa = shuffle(pow, dif, (0, 1, 1, 0)) = { pow[0], pow[1], dif[1], dif[0] }
// bb = shuffle(dif, sum, (0, 2, 2, 1)) = { dif[0], dif[2], sum[2], sum[1] }
// cc = shuffle(sum, pow, (1, 0, 2, 0)) = { sum[1], sum[0], pow[2], pow[0] }

// col0 = shuffle(cc, dif, (3, 1, 1, 3)) = { pow[0], sum[0], dif[1], dif[3] }
// col1 = shuffle(aa, sum, (3, 1, 2, 3)) = { dif[0], pow[1], sum[2], sum[3] }
// col2 = shuffle(bb, pow, (3, 1, 2, 3)) = { sum[1], dif[2], pow[2], pow[3] }

#define MAKE_ROT_QUAT(matrix_addr_m128, quat_addr)\
  \
  alignas(16) const __m128 quat_m128 = _mm_load_ps((float*) quat_addr);\
  \
  alignas(16) const __m128 x_x_y = _mm_shuffle_ps(quat_m128, quat_m128, _MM_SHUFFLE(0, 1, 0, 0));\
  alignas(16) const __m128 y_z_z = _mm_shuffle_ps(quat_m128, quat_m128, _MM_SHUFFLE(0, 2, 2, 1));\
  alignas(16) const __m128 z_y_x = _mm_shuffle_ps(quat_m128, quat_m128, _MM_SHUFFLE(0, 0, 1, 2));\
  alignas(16) const __m128 w_w_w = _mm_shuffle_ps(quat_m128, quat_m128, _MM_SHUFFLE(0, 3, 3, 3));\
  \
  alignas(16) const __m128 xy_xz_yz = _mm_mul_ps(CONST_MUL, _mm_mul_ps(x_x_y, y_z_z));\
  alignas(16) const __m128 zw_yw_xw = _mm_mul_ps(CONST_MUL, _mm_mul_ps(z_y_x, w_w_w));\
  alignas(16) const __m128 sum = _mm_add_ps(xy_xz_yz, zw_yw_xw);\
  alignas(16) const __m128 dif = _mm_sub_ps(xy_xz_yz, zw_yw_xw);\
  \
  alignas(16) const __m128 xx_yy_zz = _mm_mul_ps(CONST_MUL, _mm_mul_ps(quat_m128, quat_m128));\
  alignas(16) const __m128 yy_xx_xx = _mm_shuffle_ps(xx_yy_zz, xx_yy_zz, _MM_SHUFFLE(3, 0, 0, 1));\
  alignas(16) const __m128 zz_zz_yy = _mm_shuffle_ps(xx_yy_zz, xx_yy_zz, _MM_SHUFFLE(3, 1, 2, 2));\
  alignas(16) const __m128 pow = _mm_sub_ps(CONST_ONE, _mm_add_ps(yy_xx_xx, zz_zz_yy));\
  \
  alignas(16) const __m128 sum_pow = _mm_shuffle_ps(sum, pow, _MM_SHUFFLE(0, 2, 0, 1));\
  alignas(16) const __m128 pow_dif = _mm_shuffle_ps(pow, dif, _MM_SHUFFLE(0, 1, 1, 0));\
  alignas(16) const __m128 dif_sum = _mm_shuffle_ps(dif, sum, _MM_SHUFFLE(1, 2, 2, 0));\
  \
  matrix_addr_m128[0] = _mm_shuffle_ps(sum_pow, dif, _MM_SHUFFLE(3, 1, 1, 3));\
  matrix_addr_m128[1] = _mm_shuffle_ps(pow_dif, sum, _MM_SHUFFLE(3, 2, 1, 3));\
  matrix_addr_m128[2] = _mm_shuffle_ps(dif_sum, pow, _MM_SHUFFLE(3, 2, 1, 3));\
  matrix_addr_m128[3] = IDENT_COL3;



#define MAKE_ROT_QUAT2(matrix_addr_m128, quat_addr)\
  \
  alignas(16) const __m128 quat_m128 = _mm_load_ps((float*) quat_addr);\
  \
  alignas(16) const __m128 x_x_y = _mm_shuffle_ps(quat_m128, quat_m128, _MM_SHUFFLE(0, 1, 0, 0));\
  alignas(16) const __m128 y_z_z = _mm_shuffle_ps(quat_m128, quat_m128, _MM_SHUFFLE(0, 2, 2, 1));\
  alignas(16) const __m128 z_y_x = _mm_shuffle_ps(quat_m128, quat_m128, _MM_SHUFFLE(0, 0, 1, 2));\
  alignas(16) const __m128 w_w_w = _mm_shuffle_ps(quat_m128, quat_m128, _MM_SHUFFLE(0, 3, 3, 3));\
  \
  alignas(16) const __m128 xy_xz_yz = _mm_mul_ps(CONST_MUL, _mm_mul_ps(x_x_y, y_z_z));\
  alignas(16) const __m128 zw_yw_xw = _mm_mul_ps(CONST_MUL, _mm_mul_ps(z_y_x, w_w_w));\
  alignas(16) const __m128 sum = _mm_add_ps(xy_xz_yz, zw_yw_xw);\
  alignas(16) const __m128 dif = _mm_sub_ps(xy_xz_yz, zw_yw_xw);\
  \
  alignas(16) const __m128 xx_yy_zz = _mm_mul_ps(CONST_MUL, _mm_mul_ps(quat_m128, quat_m128));\
  alignas(16) const __m128 yy_xx_xx = _mm_shuffle_ps(xx_yy_zz, xx_yy_zz, _MM_SHUFFLE(3, 0, 0, 1));\
  alignas(16) const __m128 zz_zz_yy = _mm_shuffle_ps(xx_yy_zz, xx_yy_zz, _MM_SHUFFLE(3, 1, 2, 2));\
  alignas(16) const __m128 pow = _mm_sub_ps(CONST_ONE, _mm_add_ps(yy_xx_xx, zz_zz_yy));\
  \
  alignas(16) const __m128 sum_pow = _mm_shuffle_ps(sum, pow, _MM_SHUFFLE(0, 2, 0, 1));\
  alignas(16) const __m128 pow_dif = _mm_shuffle_ps(pow, dif, _MM_SHUFFLE(0, 1, 1, 0));\
  alignas(16) const __m128 dif_sum = _mm_shuffle_ps(dif, sum, _MM_SHUFFLE(1, 2, 2, 0));\
  \
  matrix_addr_m128[0] = _mm_shuffle_ps(sum_pow, dif, _MM_SHUFFLE(3, 1, 1, 3));\
  matrix_addr_m128[1] = _mm_shuffle_ps(pow_dif, sum, _MM_SHUFFLE(3, 2, 1, 3));\
  matrix_addr_m128[2] = _mm_shuffle_ps(dif_sum, pow, _MM_SHUFFLE(3, 2, 1, 3));\



#include <cstdint>
#include <string.h>
#include <cmath>
#include <immintrin.h>



namespace XGK {

  namespace DATA {

    namespace MAT4 {

      const uint8_t FLOAT_SIZE_3 = sizeof(float) * 3;
      const uint8_t FLOAT_SIZE_4 = sizeof(float) * 4;
      const uint8_t FLOAT_SIZE_12 = sizeof(float) * 12;
      const uint8_t FLOAT_SIZE_16 = sizeof(float) * 16;

      alignas(16) const __m128 IDENT_COL3 = { 0.0f, 0.0f, 0.0f, 1.0f };
      alignas(16) const __m128 CONST_MUL = { 2.0f, 2.0f, 2.0f, 0.0f };
      alignas(16) const __m128 CONST_ONE = { 1.0f, 1.0f, 1.0f, 0.0f };

      alignas(16) const float IDENT[12] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f
      };



      void set128 (
        void* dst,

        const float e0, const float e4, const float e8 , const float e12,
        const float e1, const float e5, const float e9 , const float e13,
        const float e2, const float e6, const float e10, const float e14,
        const float e3, const float e7, const float e11, const float e15
      ) {

        __m128* dst_128_ptr = (__m128*) dst;

        dst_128_ptr[0] = _mm_setr_ps(e0, e1, e2, e3);
        dst_128_ptr[1] = _mm_setr_ps(e4, e5, e6, e7);
        dst_128_ptr[2] = _mm_setr_ps(e8, e9, e10, e11);
        dst_128_ptr[3] = _mm_setr_ps(e12, e13, e14, e15);
      };



      void premul128 (void* dst_matrix_addr, void* src_matrix_addr) {

        __m128* dst_matrix_addr_m128 = (__m128*) dst_matrix_addr;
        alignas(16) float dst_matrix_addr_float[16];
        float* src_matrix_addr_float = (float*) src_matrix_addr;

        memcpy(dst_matrix_addr_float, dst_matrix_addr, FLOAT_SIZE_16);

        MUL(dst_matrix_addr_m128, src_matrix_addr_float, dst_matrix_addr_float)
      };




      void postmul128 (void* dst_matrix_addr, void* src_matrix_addr) {

        __m128* dst_matrix_addr_m128 = (__m128*) dst_matrix_addr;
        float* dst_matrix_addr_float = (float*) dst_matrix_addr;
        float* src_matrix_addr_float = (float*) src_matrix_addr;

        MUL(dst_matrix_addr_m128, dst_matrix_addr_float, src_matrix_addr_float)
      };



      void makeTrans128 (void* dst_matrix_addr, void* vector_addr) {

        float* dst_matrix_addr_float = (float*) dst_matrix_addr;

        MAKE_TRANS(dst_matrix_addr_float, vector_addr)
      };



      void preTrans128 (void* dst_matrix_addr, void* vector_addr) {

        __m128* dst_matrix_addr_m128 = (__m128*) dst_matrix_addr;
        __m128* vector_addr_128 = (__m128*) vector_addr;

        dst_matrix_addr_m128[3] = _mm_add_ps(dst_matrix_addr_m128[3], vector_addr_128[0]);
      };



      void postTrans128 (void* dst_matrix_addr, void* vector_addr) {

        // __m128* dst_matrix_addr_m128 = (__m128*) dst_matrix_addr;
        // float* dst_matrix_addr_float = (float*) dst_matrix_addr;
        // alignas(16) float src_matrix_addr_float[16];

        // MAKE_TRANS(src_matrix_addr_float, vector_addr)
        // MUL(dst_matrix_addr_m128, dst_matrix_addr_float, src_matrix_addr_float)

        __m128* dst_matrix_addr_m128 = (__m128*) dst_matrix_addr;
        __m128* vector_addr_128 = (__m128*) vector_addr;

        dst_matrix_addr_m128[3] = _mm_add_ps(dst_matrix_addr_m128[3], _mm_mul_ps(dst_matrix_addr_m128[0], _mm_shuffle_ps(vector_addr_128[0], vector_addr_128[0], _MM_SHUFFLE(0, 0, 0, 0))));
        dst_matrix_addr_m128[3] = _mm_add_ps(dst_matrix_addr_m128[3], _mm_mul_ps(dst_matrix_addr_m128[1], _mm_shuffle_ps(vector_addr_128[0], vector_addr_128[0], _MM_SHUFFLE(1, 1, 1, 1))));
        dst_matrix_addr_m128[3] = _mm_add_ps(dst_matrix_addr_m128[3], _mm_mul_ps(dst_matrix_addr_m128[2], _mm_shuffle_ps(vector_addr_128[0], vector_addr_128[0], _MM_SHUFFLE(2, 2, 2, 2))));
      };



      void makeTransValue128 (void* dst_matrix_addr, void* vector_addr, const float value) {

        float* dst_matrix_addr_float = (float*) dst_matrix_addr;
        float* vector_addr_float = (float*) vector_addr;

        MAKE_TRANS_VALUE(dst_matrix_addr_float, vector_addr_float, value)
      };



      void preTransValue128 (void* dst_matrix_addr, void* vector_addr, const float value) {

        __m128* dst_matrix_addr_m128 = (__m128*) dst_matrix_addr;
        alignas(16) float dst_matrix_addr_float[16];
        alignas(16) float src_matrix_addr_float[16];
        float* vector_addr_float = (float*) vector_addr;

        memcpy(dst_matrix_addr_float, dst_matrix_addr, FLOAT_SIZE_16);

        MAKE_TRANS_VALUE(src_matrix_addr_float, vector_addr_float, value)
        MUL(dst_matrix_addr_m128, src_matrix_addr_float, dst_matrix_addr_float)
      };



      void postTransValue128 (void* dst_matrix_addr, void* vector_addr, const float value) {

        __m128* dst_matrix_addr_m128 = (__m128*) dst_matrix_addr;
        float* dst_matrix_addr_float = (float*) dst_matrix_addr;
        alignas(16) float src_matrix_addr_float[16];
        float* vector_addr_float = (float*) vector_addr;

        MAKE_TRANS_VALUE(src_matrix_addr_float, vector_addr_float, value)
        MUL(dst_matrix_addr_m128, dst_matrix_addr_float, src_matrix_addr_float)
      };



      void makeRotQuat128 (void* dst_matrix_addr, void* quaternion_addr) {

        __m128* dst_matrix_addr_m128 = (__m128*) dst_matrix_addr;

        MAKE_ROT_QUAT(dst_matrix_addr_m128, quaternion_addr)
      };



      void preRotQuat128 (void* dst_matrix_addr, void* quaternion_addr) {

        __m128* dst_matrix_addr_m128 = (__m128*) dst_matrix_addr;
        float* dst_matrix_addr_float = (float*) dst_matrix_addr;
        alignas(16) __m128 right_matrix_addr_m128[4];
        alignas(16) __m128 left_matrix_addr_m128[3];

        memcpy(right_matrix_addr_m128, dst_matrix_addr, FLOAT_SIZE_16);

        MAKE_ROT_QUAT2(left_matrix_addr_m128, quaternion_addr)

        alignas(16) const __m128 a = left_matrix_addr_m128[0];
        alignas(16) const __m128 b = left_matrix_addr_m128[1];
        alignas(16) const __m128 c = left_matrix_addr_m128[2];

        dst_matrix_addr_m128[0] = _mm_mul_ps(a, _mm_shuffle_ps(right_matrix_addr_m128[0], right_matrix_addr_m128[0], _MM_SHUFFLE(0, 0, 0, 0)));
        dst_matrix_addr_m128[1] = _mm_mul_ps(a, _mm_shuffle_ps(right_matrix_addr_m128[1], right_matrix_addr_m128[1], _MM_SHUFFLE(0, 0, 0, 0)));
        dst_matrix_addr_m128[2] = _mm_mul_ps(a, _mm_shuffle_ps(right_matrix_addr_m128[2], right_matrix_addr_m128[2], _MM_SHUFFLE(0, 0, 0, 0)));
        dst_matrix_addr_m128[3] = _mm_mul_ps(a, _mm_shuffle_ps(right_matrix_addr_m128[3], right_matrix_addr_m128[3], _MM_SHUFFLE(0, 0, 0, 0)));

        dst_matrix_addr_m128[0] = _mm_add_ps(dst_matrix_addr_m128[0], _mm_mul_ps(b, _mm_shuffle_ps(right_matrix_addr_m128[0], right_matrix_addr_m128[0], _MM_SHUFFLE(1, 1, 1, 1))));
        dst_matrix_addr_m128[1] = _mm_add_ps(dst_matrix_addr_m128[1], _mm_mul_ps(b, _mm_shuffle_ps(right_matrix_addr_m128[1], right_matrix_addr_m128[1], _MM_SHUFFLE(1, 1, 1, 1))));
        dst_matrix_addr_m128[2] = _mm_add_ps(dst_matrix_addr_m128[2], _mm_mul_ps(b, _mm_shuffle_ps(right_matrix_addr_m128[2], right_matrix_addr_m128[2], _MM_SHUFFLE(1, 1, 1, 1))));
        dst_matrix_addr_m128[3] = _mm_add_ps(dst_matrix_addr_m128[3], _mm_mul_ps(b, _mm_shuffle_ps(right_matrix_addr_m128[3], right_matrix_addr_m128[3], _MM_SHUFFLE(1, 1, 1, 1))));

        dst_matrix_addr_m128[0] = _mm_add_ps(dst_matrix_addr_m128[0], _mm_mul_ps(c, _mm_shuffle_ps(right_matrix_addr_m128[0], right_matrix_addr_m128[0], _MM_SHUFFLE(2, 2, 2, 2))));
        dst_matrix_addr_m128[1] = _mm_add_ps(dst_matrix_addr_m128[1], _mm_mul_ps(c, _mm_shuffle_ps(right_matrix_addr_m128[1], right_matrix_addr_m128[1], _MM_SHUFFLE(2, 2, 2, 2))));
        dst_matrix_addr_m128[2] = _mm_add_ps(dst_matrix_addr_m128[2], _mm_mul_ps(c, _mm_shuffle_ps(right_matrix_addr_m128[2], right_matrix_addr_m128[2], _MM_SHUFFLE(2, 2, 2, 2))));
        dst_matrix_addr_m128[3] = _mm_add_ps(dst_matrix_addr_m128[3], _mm_mul_ps(c, _mm_shuffle_ps(right_matrix_addr_m128[3], right_matrix_addr_m128[3], _MM_SHUFFLE(2, 2, 2, 2))));

        dst_matrix_addr_float[15] = 1.0f;
      };



      void postRotQuat128 (void* dst_matrix_addr, void* quaternion_addr) {

        __m128* dst_matrix_addr_m128 = (__m128*) dst_matrix_addr;
        alignas(16) __m128 right_matrix_addr_m128[3];

        MAKE_ROT_QUAT2(right_matrix_addr_m128, quaternion_addr)

        alignas(16) const __m128 a = dst_matrix_addr_m128[0];
        alignas(16) const __m128 b = dst_matrix_addr_m128[1];
        alignas(16) const __m128 c = dst_matrix_addr_m128[2];

        dst_matrix_addr_m128[0] = _mm_mul_ps(a, _mm_shuffle_ps(right_matrix_addr_m128[0], right_matrix_addr_m128[0], _MM_SHUFFLE(0, 0, 0, 0)));
        dst_matrix_addr_m128[1] = _mm_mul_ps(a, _mm_shuffle_ps(right_matrix_addr_m128[1], right_matrix_addr_m128[1], _MM_SHUFFLE(0, 0, 0, 0)));
        dst_matrix_addr_m128[2] = _mm_mul_ps(a, _mm_shuffle_ps(right_matrix_addr_m128[2], right_matrix_addr_m128[2], _MM_SHUFFLE(0, 0, 0, 0)));

        dst_matrix_addr_m128[0] = _mm_add_ps(dst_matrix_addr_m128[0], _mm_mul_ps(b, _mm_shuffle_ps(right_matrix_addr_m128[0], right_matrix_addr_m128[0], _MM_SHUFFLE(1, 1, 1, 1))));
        dst_matrix_addr_m128[1] = _mm_add_ps(dst_matrix_addr_m128[1], _mm_mul_ps(b, _mm_shuffle_ps(right_matrix_addr_m128[1], right_matrix_addr_m128[1], _MM_SHUFFLE(1, 1, 1, 1))));
        dst_matrix_addr_m128[2] = _mm_add_ps(dst_matrix_addr_m128[2], _mm_mul_ps(b, _mm_shuffle_ps(right_matrix_addr_m128[2], right_matrix_addr_m128[2], _MM_SHUFFLE(1, 1, 1, 1))));

        dst_matrix_addr_m128[0] = _mm_add_ps(dst_matrix_addr_m128[0], _mm_mul_ps(c, _mm_shuffle_ps(right_matrix_addr_m128[0], right_matrix_addr_m128[0], _MM_SHUFFLE(2, 2, 2, 2))));
        dst_matrix_addr_m128[1] = _mm_add_ps(dst_matrix_addr_m128[1], _mm_mul_ps(c, _mm_shuffle_ps(right_matrix_addr_m128[1], right_matrix_addr_m128[1], _MM_SHUFFLE(2, 2, 2, 2))));
        dst_matrix_addr_m128[2] = _mm_add_ps(dst_matrix_addr_m128[2], _mm_mul_ps(c, _mm_shuffle_ps(right_matrix_addr_m128[2], right_matrix_addr_m128[2], _MM_SHUFFLE(2, 2, 2, 2))));
      };



      void transp128 (void* dst) {

        __m128* dst_128_ptr = (__m128*) dst;

        alignas(16) const __m128 a = _mm_shuffle_ps(dst_128_ptr[0], dst_128_ptr[1], _MM_SHUFFLE(1, 0, 1, 0));
        alignas(16) const __m128 b = _mm_shuffle_ps(dst_128_ptr[2], dst_128_ptr[3], _MM_SHUFFLE(1, 0, 1, 0));
        alignas(16) const __m128 c = _mm_shuffle_ps(dst_128_ptr[0], dst_128_ptr[1], _MM_SHUFFLE(3, 2, 3, 2));
        alignas(16) const __m128 d = _mm_shuffle_ps(dst_128_ptr[2], dst_128_ptr[3], _MM_SHUFFLE(3, 2, 3, 2));

        dst_128_ptr[0] = _mm_shuffle_ps(a, b, _MM_SHUFFLE(2, 0, 2, 0));
        dst_128_ptr[1] = _mm_shuffle_ps(a, b, _MM_SHUFFLE(3, 1, 3, 1));
        dst_128_ptr[2] = _mm_shuffle_ps(c, d, _MM_SHUFFLE(2, 0, 2, 0));
        dst_128_ptr[3] = _mm_shuffle_ps(c, d, _MM_SHUFFLE(3, 1, 3, 1));
      };



      void invns128 (void* dst) {

        __m128* dst_128_ptr = (__m128*) dst;

        alignas(16) const __m128 a = dst_128_ptr[3];

        alignas(16) const __m128 e = _mm_shuffle_ps(dst_128_ptr[0], dst_128_ptr[1], _MM_SHUFFLE(1, 0, 1, 0));
        alignas(16) const __m128 f = _mm_shuffle_ps(dst_128_ptr[2], IDENT_COL3, _MM_SHUFFLE(1, 0, 1, 0));
        alignas(16) const __m128 i = _mm_shuffle_ps(dst_128_ptr[0], dst_128_ptr[1], _MM_SHUFFLE(3, 2, 3, 2));
        alignas(16) const __m128 j = _mm_shuffle_ps(dst_128_ptr[2], IDENT_COL3, _MM_SHUFFLE(3, 2, 3, 2));

        alignas(16) const __m128 b = _mm_shuffle_ps(a, a, _MM_SHUFFLE(0, 0, 0, 0));
        alignas(16) const __m128 c = _mm_shuffle_ps(a, a, _MM_SHUFFLE(1, 1, 1, 1));
        alignas(16) const __m128 d = _mm_shuffle_ps(a, a, _MM_SHUFFLE(2, 2, 2, 2));

        dst_128_ptr[0] = _mm_shuffle_ps(e, f, _MM_SHUFFLE(2, 0, 2, 0));
        dst_128_ptr[1] = _mm_shuffle_ps(e, f, _MM_SHUFFLE(3, 1, 3, 1));
        dst_128_ptr[2] = _mm_shuffle_ps(i, j, _MM_SHUFFLE(2, 0, 2, 0));
        dst_128_ptr[3] = _mm_sub_ps(_mm_sub_ps(_mm_sub_ps(IDENT_COL3, _mm_mul_ps(dst_128_ptr[0], b)), _mm_mul_ps(dst_128_ptr[1], c)), _mm_mul_ps(dst_128_ptr[2], d));
      };



      void makeProjPersp128 (
        void* dst,

        const float fov,
        const float aspect,
        const float near_,
        const float far_,
        const float zoom
      ) {

        float* dst_32_ptr = (float*) dst;

        const float top = near_ * tan(0.017453292f * 0.5f * fov) / zoom;
        const float height = 2.0f * top;
        const float bottom = top - height;
        const float width = aspect * height;
        const float left = -0.5f * width;
        const float right = left + width;

        SET32(
          dst_32_ptr,

          2.0f * near_ / (right - left), 0.0f                         , (right + left) / (right - left)  , 0.0f                                   ,
          0.0f                         , 2.0f * near_ / (top - bottom), (top + bottom) / (top - bottom)  , 0.0f                                   ,
          0.0f                         , 0.0f                         , -(far_ + near_) / (far_ - near_) , -(2.0f * far_ * near_) / (far_ - near_),
          0.0f                         , 0.0f                         , -1.0f                            , 0.0f
        )
      };



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


      // #undef b
      // #undef a

      // ///////
      // ///////
      // ///////



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



      // // // MAKE ROTATION
      // // ////////////////
      // // ////////////////

      // // inline void makeRot32 (Mat4* m0, float* q0) {

      // //   const float xx = 2.0f * q0->f32[0] * q0->f32[0];
      // //   const float yy = 2.0f * q0->f32[1] * q0->f32[1];
      // //   const float zz = 2.0f * q0->f32[2] * q0->f32[2];
      // //   const float xy = 2.0f * q0->f32[0] * q0->f32[1];
      // //   const float xz = 2.0f * q0->f32[0] * q0->f32[2];
      // //   const float xw = 2.0f * q0->f32[0] * q0->f32[3];
      // //   const float yz = 2.0f * q0->f32[1] * q0->f32[2];
      // //   const float yw = 2.0f * q0->f32[1] * q0->f32[3];
      // //   const float zw = 2.0f * q0->f32[2] * q0->f32[3];

      // //   SET32(
      // //     m0,

      // //     1.0f - yy - zz, xy - zw       , xz + yw       , 0.0f,
      // //     xy + zw       , 1.0f - xx - zz, yz - xw       , 0.0f,
      // //     xz - yw       , yz + xw       , 1.0f - xx - yy, 0.0f,
      // //     0.0f          , 0.0f          , 0.0f          , 1.0f
      // //   )
      // // };

      // // #ifdef XGK_DATA_MACRO_SSE
      // //   inline void makeRot128 (Mat4* m0, float* q0) {

      // //     const float xx = 2.0f * q0->f32[0] * q0->f32[0];
      // //     const float yy = 2.0f * q0->f32[1] * q0->f32[1];
      // //     const float zz = 2.0f * q0->f32[2] * q0->f32[2];
      // //     const float xy = 2.0f * q0->f32[0] * q0->f32[1];
      // //     const float xz = 2.0f * q0->f32[0] * q0->f32[2];
      // //     const float xw = 2.0f * q0->f32[0] * q0->f32[3];
      // //     const float yz = 2.0f * q0->f32[1] * q0->f32[2];
      // //     const float yw = 2.0f * q0->f32[1] * q0->f32[3];
      // //     const float zw = 2.0f * q0->f32[2] * q0->f32[3];

      // //     SET128(
      // //       m0,

      // //       1.0f - yy - zz, xy - zw       , xz + yw       , 0.0f,
      // //       xy + zw       , 1.0f - xx - zz, yz - xw       , 0.0f,
      // //       xz - yw       , yz + xw       , 1.0f - xx - yy, 0.0f,
      // //       0.0f          , 0.0f          , 0.0f          , 1.0f
      // //     )
      // //   };
      // // #endif

      // // #ifdef XGK_DATA_MACRO_AVX
      // //   inline void makeRot256 (Mat4* m0, float* q0) {

      // //     const float xx = 2.0f * q0->f32[0] * q0->f32[0];
      // //     const float yy = 2.0f * q0->f32[1] * q0->f32[1];
      // //     const float zz = 2.0f * q0->f32[2] * q0->f32[2];
      // //     const float xy = 2.0f * q0->f32[0] * q0->f32[1];
      // //     const float xz = 2.0f * q0->f32[0] * q0->f32[2];
      // //     const float xw = 2.0f * q0->f32[0] * q0->f32[3];
      // //     const float yz = 2.0f * q0->f32[1] * q0->f32[2];
      // //     const float yw = 2.0f * q0->f32[1] * q0->f32[3];
      // //     const float zw = 2.0f * q0->f32[2] * q0->f32[3];

      // //     SET256(
      // //       m0,

      // //       1.0f - yy - zz, xy - zw       , xz + yw       , 0.0f,
      // //       xy + zw       , 1.0f - xx - zz, yz - xw       , 0.0f,
      // //       xz - yw       , yz + xw       , 1.0f - xx - yy, 0.0f,
      // //       0.0f          , 0.0f          , 0.0f          , 1.0f
      // //     )
      // //   };
      // // #endif

      // // inline void makeRotX32 (Mat4* m0, const float angle) {

      // //   const float cos_ = cos(angle);
      // //   const float sin_ = sin(angle);

      // //   SET32(
      // //     m0,

      // //     1.0f, 0.0f , 0.0f, 0.0f,
      // //     0.0f, cos_ , sin_, 0.0f,
      // //     0.0f, -sin_, cos_, 0.0f,
      // //     0.0f, 0.0f , 0.0f, 1.0f
      // //   )
      // // };

      // // #ifdef XGK_DATA_MACRO_SSE
      // //   inline void makeRotX128 (Mat4* m0, const float angle) {

      // //     const float cos_ = cos(angle);
      // //     const float sin_ = sin(angle);

      // //     SET128(
      // //       m0,

      // //       1.0f, 0.0f , 0.0f, 0.0f,
      // //       0.0f, cos_ , sin_, 0.0f,
      // //       0.0f, -sin_, cos_, 0.0f,
      // //       0.0f, 0.0f , 0.0f, 1.0f
      // //     )
      // //   };
      // // #endif

      // // #ifdef XGK_DATA_MACRO_AVX
      // //   inline void makeRotX256 (Mat4* m0, const float angle) {

      // //     const float cos_ = cos(angle);
      // //     const float sin_ = sin(angle);

      // //     SET256(
      // //       m0,

      // //       1.0f, 0.0f , 0.0f, 0.0f,
      // //       0.0f, cos_ , sin_, 0.0f,
      // //       0.0f, -sin_, cos_, 0.0f,
      // //       0.0f, 0.0f , 0.0f, 1.0f
      // //     )
      // //   };
      // // #endif

      // // ///////
      // // ///////
      // // ///////
    };
  };
};
