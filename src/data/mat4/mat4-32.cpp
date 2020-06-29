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



#define MUL(dst_matrix_addr_float, left_matrix_addr_float, right_matrix_addr_float)\
  \
  const float e0 = (left_matrix_addr_float[0] * right_matrix_addr_float[0]) + (left_matrix_addr_float[4] * right_matrix_addr_float[1]) + (left_matrix_addr_float[8]  * right_matrix_addr_float[2]) + (left_matrix_addr_float[12] * right_matrix_addr_float[3]);\
  const float e1 = (left_matrix_addr_float[1] * right_matrix_addr_float[0]) + (left_matrix_addr_float[5] * right_matrix_addr_float[1]) + (left_matrix_addr_float[9]  * right_matrix_addr_float[2]) + (left_matrix_addr_float[13] * right_matrix_addr_float[3]);\
  const float e2 = (left_matrix_addr_float[2] * right_matrix_addr_float[0]) + (left_matrix_addr_float[6] * right_matrix_addr_float[1]) + (left_matrix_addr_float[10] * right_matrix_addr_float[2]) + (left_matrix_addr_float[14] * right_matrix_addr_float[3]);\
  const float e3 = (left_matrix_addr_float[3] * right_matrix_addr_float[0]) + (left_matrix_addr_float[7] * right_matrix_addr_float[1]) + (left_matrix_addr_float[11] * right_matrix_addr_float[2]) + (left_matrix_addr_float[15] * right_matrix_addr_float[3]);\
  \
  const float e4 = (left_matrix_addr_float[0] * right_matrix_addr_float[4]) + (left_matrix_addr_float[4] * right_matrix_addr_float[5]) + (left_matrix_addr_float[8]  * right_matrix_addr_float[6]) + (left_matrix_addr_float[12] * right_matrix_addr_float[7]);\
  const float e5 = (left_matrix_addr_float[1] * right_matrix_addr_float[4]) + (left_matrix_addr_float[5] * right_matrix_addr_float[5]) + (left_matrix_addr_float[9]  * right_matrix_addr_float[6]) + (left_matrix_addr_float[13] * right_matrix_addr_float[7]);\
  const float e6 = (left_matrix_addr_float[2] * right_matrix_addr_float[4]) + (left_matrix_addr_float[6] * right_matrix_addr_float[5]) + (left_matrix_addr_float[10] * right_matrix_addr_float[6]) + (left_matrix_addr_float[14] * right_matrix_addr_float[7]);\
  const float e7 = (left_matrix_addr_float[3] * right_matrix_addr_float[4]) + (left_matrix_addr_float[7] * right_matrix_addr_float[5]) + (left_matrix_addr_float[11] * right_matrix_addr_float[6]) + (left_matrix_addr_float[15] * right_matrix_addr_float[7]);\
  \
  const float e8 = (left_matrix_addr_float[0] * right_matrix_addr_float[8]) + (left_matrix_addr_float[4] * right_matrix_addr_float[9]) + (left_matrix_addr_float[8]  * right_matrix_addr_float[10]) + (left_matrix_addr_float[12] * right_matrix_addr_float[11]);\
  const float e9 = (left_matrix_addr_float[1] * right_matrix_addr_float[8]) + (left_matrix_addr_float[5] * right_matrix_addr_float[9]) + (left_matrix_addr_float[9]  * right_matrix_addr_float[10]) + (left_matrix_addr_float[13] * right_matrix_addr_float[11]);\
  const float e10 = (left_matrix_addr_float[2] * right_matrix_addr_float[8]) + (left_matrix_addr_float[6] * right_matrix_addr_float[9]) + (left_matrix_addr_float[10] * right_matrix_addr_float[10]) + (left_matrix_addr_float[14] * right_matrix_addr_float[11]);\
  const float e11 = (left_matrix_addr_float[3] * right_matrix_addr_float[8]) + (left_matrix_addr_float[7] * right_matrix_addr_float[9]) + (left_matrix_addr_float[11] * right_matrix_addr_float[10]) + (left_matrix_addr_float[15] * right_matrix_addr_float[11]);\
  \
  const float e12 = (left_matrix_addr_float[0] * right_matrix_addr_float[12]) + (left_matrix_addr_float[4] * right_matrix_addr_float[13]) + (left_matrix_addr_float[8]  * right_matrix_addr_float[14]) + (left_matrix_addr_float[12] * right_matrix_addr_float[15]);\
  const float e13 = (left_matrix_addr_float[1] * right_matrix_addr_float[12]) + (left_matrix_addr_float[5] * right_matrix_addr_float[13]) + (left_matrix_addr_float[9]  * right_matrix_addr_float[14]) + (left_matrix_addr_float[13] * right_matrix_addr_float[15]);\
  const float e14 = (left_matrix_addr_float[2] * right_matrix_addr_float[12]) + (left_matrix_addr_float[6] * right_matrix_addr_float[13]) + (left_matrix_addr_float[10] * right_matrix_addr_float[14]) + (left_matrix_addr_float[14] * right_matrix_addr_float[15]);\
  const float e15 = (left_matrix_addr_float[3] * right_matrix_addr_float[12]) + (left_matrix_addr_float[7] * right_matrix_addr_float[13]) + (left_matrix_addr_float[11] * right_matrix_addr_float[14]) + (left_matrix_addr_float[15] * right_matrix_addr_float[15]);\
  \
  dst_matrix_addr_float[0] = e0; dst_matrix_addr_float[4] = e4; dst_matrix_addr_float[8]  = e8 ; dst_matrix_addr_float[12] = e12;\
  dst_matrix_addr_float[1] = e1; dst_matrix_addr_float[5] = e5; dst_matrix_addr_float[9]  = e9 ; dst_matrix_addr_float[13] = e13;\
  dst_matrix_addr_float[2] = e2; dst_matrix_addr_float[6] = e6; dst_matrix_addr_float[10] = e10; dst_matrix_addr_float[14] = e14;\
  dst_matrix_addr_float[3] = e3; dst_matrix_addr_float[7] = e7; dst_matrix_addr_float[11] = e11; dst_matrix_addr_float[15] = e15;



#define MAKE_TRANS(matrix_addr_float, vector_addr)\
  \
  memcpy(matrix_addr_float, IDENT, FLOAT_SIZE_12);\
  memcpy(matrix_addr_float + 12, vector_addr, FLOAT_SIZE_3);



#define MAKE_TRANS_VALUE(matrix_addr_float, vector_addr_float, value)\
  \
  memcpy(matrix_addr_float, IDENT, FLOAT_SIZE_12);\
  \
  matrix_addr_float[12] = vector_addr_float[0] * value;\
  matrix_addr_float[13] = vector_addr_float[1] * value;\
  matrix_addr_float[14] = vector_addr_float[2] * value;\
  matrix_addr_float[15] = 1.0f;



#define MAKE_ROT_QUAT(matrix_addr_float, quaternion_addr_float)\
  \
  const float xy = 2.0f * quaternion_addr_float[0] * quaternion_addr_float[1];\
  const float xz = 2.0f * quaternion_addr_float[0] * quaternion_addr_float[2];\
  const float yz = 2.0f * quaternion_addr_float[1] * quaternion_addr_float[2];\
  \
  const float zw = 2.0f * quaternion_addr_float[2] * quaternion_addr_float[3];\
  const float yw = 2.0f * quaternion_addr_float[1] * quaternion_addr_float[3];\
  const float xw = 2.0f * quaternion_addr_float[0] * quaternion_addr_float[3];\
  \
  const float xx = 2.0f * quaternion_addr_float[0] * quaternion_addr_float[0];\
  const float yy = 2.0f * quaternion_addr_float[1] * quaternion_addr_float[1];\
  const float zz = 2.0f * quaternion_addr_float[2] * quaternion_addr_float[2];\
  \
  matrix_addr_float[0] = 1.0f - yy - zz; matrix_addr_float[4] = xy - zw       ; matrix_addr_float[8]  = xz + yw       ; matrix_addr_float[12] = 0.0f;\
  matrix_addr_float[1] = xy + zw       ; matrix_addr_float[5] = 1.0f - xx - zz; matrix_addr_float[9]  = yz - xw       ; matrix_addr_float[13] = 0.0f;\
  matrix_addr_float[2] = xz - yw       ; matrix_addr_float[6] = yz + xw       ; matrix_addr_float[10] = 1.0f - xx - yy; matrix_addr_float[14] = 0.0f;\
  matrix_addr_float[3] = 0.0f          ; matrix_addr_float[7] = 0.0f          ; matrix_addr_float[11] = 0.0f          ; matrix_addr_float[15] = 1.0f;



#define MAKE_ROT_QUAT2(matrix_addr_float, quaternion_addr_float)\
  \
  const float xy = 2.0f * quaternion_addr_float[0] * quaternion_addr_float[1];\
  const float xz = 2.0f * quaternion_addr_float[0] * quaternion_addr_float[2];\
  const float yz = 2.0f * quaternion_addr_float[1] * quaternion_addr_float[2];\
  \
  const float zw = 2.0f * quaternion_addr_float[2] * quaternion_addr_float[3];\
  const float yw = 2.0f * quaternion_addr_float[1] * quaternion_addr_float[3];\
  const float xw = 2.0f * quaternion_addr_float[0] * quaternion_addr_float[3];\
  \
  const float xx = 2.0f * quaternion_addr_float[0] * quaternion_addr_float[0];\
  const float yy = 2.0f * quaternion_addr_float[1] * quaternion_addr_float[1];\
  const float zz = 2.0f * quaternion_addr_float[2] * quaternion_addr_float[2];\
  \
  matrix_addr_float[0] = 1.0f - yy - zz; matrix_addr_float[4] = xy - zw       ; matrix_addr_float[8]  = xz + yw       ;\
  matrix_addr_float[1] = xy + zw       ; matrix_addr_float[5] = 1.0f - xx - zz; matrix_addr_float[9]  = yz - xw       ;\
  matrix_addr_float[2] = xz - yw       ; matrix_addr_float[6] = yz + xw       ; matrix_addr_float[10] = 1.0f - xx - yy;



#include <cstdint>
#include <string.h>
#include <cmath>



namespace XGK {

  namespace DATA {

    namespace MAT4 {

      const uint8_t FLOAT_SIZE_3 = sizeof(float) * 3;
      const uint8_t FLOAT_SIZE_4 = sizeof(float) * 4;
      const uint8_t FLOAT_SIZE_12 = sizeof(float) * 12;

      alignas(16) const float IDENT[12] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f
      };



      void set32 (
        void* dst,

        const float e0, const float e4, const float e8 , const float e12,
        const float e1, const float e5, const float e9 , const float e13,
        const float e2, const float e6, const float e10, const float e14,
        const float e3, const float e7, const float e11, const float e15
     ) {

        float* dst_32_ptr = (float*) dst;

        SET32(
          dst_32_ptr,

          e0, e4, e8 , e12,
          e1, e5, e9 , e13,
          e2, e6, e10, e14,
          e3, e7, e11, e15
        )
      };



      void premul32 (void* dst_matrix_addr, void* src_matrix_addr) {

        float* dst_matrix_addr_float = (float*) dst_matrix_addr;
        float* src_matrix_addr_float = (float*) src_matrix_addr;

        MUL(dst_matrix_addr_float, src_matrix_addr_float, dst_matrix_addr_float)
      };



      void postmul32 (void* dst_matrix_addr, void* src_matrix_addr) {

        float* dst_matrix_addr_float = (float*) dst_matrix_addr;
        float* src_matrix_addr_float = (float*) src_matrix_addr;

        MUL(dst_matrix_addr_float, dst_matrix_addr_float, src_matrix_addr_float)
      };



      void makeTrans32 (void* dst_matrix_addr, void* vector_addr) {

        float* dst_matrix_addr_float = (float*) dst_matrix_addr;

        MAKE_TRANS(dst_matrix_addr_float, vector_addr)
      };



      void preTrans32 (void* dst_matrix_addr, void* vector_addr) {

        float* dst_matrix_addr_float = (float*) dst_matrix_addr;
        float* vector_addr_float = (float*) vector_addr;

        dst_matrix_addr_float[12] += vector_addr_float[0];
        dst_matrix_addr_float[13] += vector_addr_float[1];
        dst_matrix_addr_float[14] += vector_addr_float[2];
      };



      void postTrans32 (void* dst_matrix_addr, void* vector_addr) {

        float* dst_matrix_addr_float = (float*) dst_matrix_addr;
        float* vector_addr_float = (float*) vector_addr;

        dst_matrix_addr_float[12] += (dst_matrix_addr_float[0] * vector_addr_float[0]) + (dst_matrix_addr_float[4] * vector_addr_float[1]) + (dst_matrix_addr_float[8]  * vector_addr_float[2]);
        dst_matrix_addr_float[13] += (dst_matrix_addr_float[1] * vector_addr_float[0]) + (dst_matrix_addr_float[5] * vector_addr_float[1]) + (dst_matrix_addr_float[9]  * vector_addr_float[2]);
        dst_matrix_addr_float[14] += (dst_matrix_addr_float[2] * vector_addr_float[0]) + (dst_matrix_addr_float[6] * vector_addr_float[1]) + (dst_matrix_addr_float[10] * vector_addr_float[2]);
      };



      void makeTransValue32 (void* dst_matrix_addr, void* vector_addr, const float value) {

        float* dst_matrix_addr_float = (float*) dst_matrix_addr;
        float* vector_addr_float = (float*) vector_addr;

        MAKE_TRANS_VALUE(dst_matrix_addr_float, vector_addr_float, value)
      };



      void preTransValue32 (void* dst_matrix_addr, void* vector_addr, const float value) {

        float* dst_matrix_addr_float = (float*) dst_matrix_addr;
        alignas(16) float src_matrix_addr_float[16];
        float* vector_addr_float = (float*) vector_addr;

        MAKE_TRANS_VALUE(src_matrix_addr_float, vector_addr_float, value)

        MUL(dst_matrix_addr_float, src_matrix_addr_float, dst_matrix_addr_float)
      };



      void postTransValue32 (void* dst_matrix_addr, void* vector_addr, const float value) {

        float* dst_matrix_addr_float = (float*) dst_matrix_addr;
        alignas(16) float src_matrix_addr_float[16];
        float* vector_addr_float = (float*) vector_addr;

        MAKE_TRANS_VALUE(src_matrix_addr_float, vector_addr_float, value)

        MUL(dst_matrix_addr_float, dst_matrix_addr_float, src_matrix_addr_float)
      };



      void makeRotQuat32 (void* dst_matrix_addr, void* quaternion_addr) {

        float* dst_matrix_addr_float = (float*) dst_matrix_addr;
        float* quaternion_addr_float = (float*) quaternion_addr;

        MAKE_ROT_QUAT(dst_matrix_addr_float, quaternion_addr_float)
      };



      void preRotQuat32 (void* dst_matrix_addr, void* quaternion_addr) {

        float* dst_matrix_addr_float = (float*) dst_matrix_addr;
        alignas(16) float left_matrix_addr_float[12];
        float* quaternion_addr_float = (float*) quaternion_addr;

        MAKE_ROT_QUAT2(left_matrix_addr_float, quaternion_addr_float)

        const float e0  = (left_matrix_addr_float[0] * dst_matrix_addr_float[0])  + (left_matrix_addr_float[4] * dst_matrix_addr_float[1])  + (left_matrix_addr_float[8]  * dst_matrix_addr_float[2]);
        const float e1  = (left_matrix_addr_float[1] * dst_matrix_addr_float[0])  + (left_matrix_addr_float[5] * dst_matrix_addr_float[1])  + (left_matrix_addr_float[9]  * dst_matrix_addr_float[2]);
        const float e2  = (left_matrix_addr_float[2] * dst_matrix_addr_float[0])  + (left_matrix_addr_float[6] * dst_matrix_addr_float[1])  + (left_matrix_addr_float[10] * dst_matrix_addr_float[2]);

        const float e4  = (left_matrix_addr_float[0] * dst_matrix_addr_float[4])  + (left_matrix_addr_float[4] * dst_matrix_addr_float[5])  + (left_matrix_addr_float[8]  * dst_matrix_addr_float[6]);
        const float e5  = (left_matrix_addr_float[1] * dst_matrix_addr_float[4])  + (left_matrix_addr_float[5] * dst_matrix_addr_float[5])  + (left_matrix_addr_float[9]  * dst_matrix_addr_float[6]);
        const float e6  = (left_matrix_addr_float[2] * dst_matrix_addr_float[4])  + (left_matrix_addr_float[6] * dst_matrix_addr_float[5])  + (left_matrix_addr_float[10] * dst_matrix_addr_float[6]);

        const float e8  = (left_matrix_addr_float[0] * dst_matrix_addr_float[8])  + (left_matrix_addr_float[4] * dst_matrix_addr_float[9])  + (left_matrix_addr_float[8]  * dst_matrix_addr_float[10]);
        const float e9  = (left_matrix_addr_float[1] * dst_matrix_addr_float[8])  + (left_matrix_addr_float[5] * dst_matrix_addr_float[9])  + (left_matrix_addr_float[9]  * dst_matrix_addr_float[10]);
        const float e10 = (left_matrix_addr_float[2] * dst_matrix_addr_float[8])  + (left_matrix_addr_float[6] * dst_matrix_addr_float[9])  + (left_matrix_addr_float[10] * dst_matrix_addr_float[10]);

        const float e12 = (left_matrix_addr_float[0] * dst_matrix_addr_float[12]) + (left_matrix_addr_float[4] * dst_matrix_addr_float[13]) + (left_matrix_addr_float[8]  * dst_matrix_addr_float[14]);
        const float e13 = (left_matrix_addr_float[1] * dst_matrix_addr_float[12]) + (left_matrix_addr_float[5] * dst_matrix_addr_float[13]) + (left_matrix_addr_float[9]  * dst_matrix_addr_float[14]);
        const float e14 = (left_matrix_addr_float[2] * dst_matrix_addr_float[12]) + (left_matrix_addr_float[6] * dst_matrix_addr_float[13]) + (left_matrix_addr_float[10] * dst_matrix_addr_float[14]);

        dst_matrix_addr_float[0] = e0; dst_matrix_addr_float[4] = e4; dst_matrix_addr_float[8]  = e8 ; dst_matrix_addr_float[12] = e12;
        dst_matrix_addr_float[1] = e1; dst_matrix_addr_float[5] = e5; dst_matrix_addr_float[9]  = e9 ; dst_matrix_addr_float[13] = e13;
        dst_matrix_addr_float[2] = e2; dst_matrix_addr_float[6] = e6; dst_matrix_addr_float[10] = e10; dst_matrix_addr_float[14] = e14;
      };



      void postRotQuat32 (void* dst_matrix_addr, void* quaternion_addr) {

        float* dst_matrix_addr_float = (float*) dst_matrix_addr;
        alignas(16) float right_matrix_addr_float[12];
        float* quaternion_addr_float = (float*) quaternion_addr;

        MAKE_ROT_QUAT2(right_matrix_addr_float, quaternion_addr_float)

        const float e0  = (dst_matrix_addr_float[0] * right_matrix_addr_float[0]) + (dst_matrix_addr_float[4] * right_matrix_addr_float[1]) + (dst_matrix_addr_float[8]  * right_matrix_addr_float[2]);
        const float e1  = (dst_matrix_addr_float[1] * right_matrix_addr_float[0]) + (dst_matrix_addr_float[5] * right_matrix_addr_float[1]) + (dst_matrix_addr_float[9]  * right_matrix_addr_float[2]);
        const float e2  = (dst_matrix_addr_float[2] * right_matrix_addr_float[0]) + (dst_matrix_addr_float[6] * right_matrix_addr_float[1]) + (dst_matrix_addr_float[10] * right_matrix_addr_float[2]);
        // const float e3  = (dst_matrix_addr_float[3] * right_matrix_addr_float[0]) + (dst_matrix_addr_float[7] * right_matrix_addr_float[1]) + (dst_matrix_addr_float[11] * right_matrix_addr_float[2]);

        const float e4  = (dst_matrix_addr_float[0] * right_matrix_addr_float[4]) + (dst_matrix_addr_float[4] * right_matrix_addr_float[5]) + (dst_matrix_addr_float[8]  * right_matrix_addr_float[6]);
        const float e5  = (dst_matrix_addr_float[1] * right_matrix_addr_float[4]) + (dst_matrix_addr_float[5] * right_matrix_addr_float[5]) + (dst_matrix_addr_float[9]  * right_matrix_addr_float[6]);
        const float e6  = (dst_matrix_addr_float[2] * right_matrix_addr_float[4]) + (dst_matrix_addr_float[6] * right_matrix_addr_float[5]) + (dst_matrix_addr_float[10] * right_matrix_addr_float[6]);
        // const float e7  = (dst_matrix_addr_float[3] * right_matrix_addr_float[4]) + (dst_matrix_addr_float[7] * right_matrix_addr_float[5]) + (dst_matrix_addr_float[11] * right_matrix_addr_float[6]);

        const float e8  = (dst_matrix_addr_float[0] * right_matrix_addr_float[8]) + (dst_matrix_addr_float[4] * right_matrix_addr_float[9]) + (dst_matrix_addr_float[8]  * right_matrix_addr_float[10]);
        const float e9  = (dst_matrix_addr_float[1] * right_matrix_addr_float[8]) + (dst_matrix_addr_float[5] * right_matrix_addr_float[9]) + (dst_matrix_addr_float[9]  * right_matrix_addr_float[10]);
        const float e10 = (dst_matrix_addr_float[2] * right_matrix_addr_float[8]) + (dst_matrix_addr_float[6] * right_matrix_addr_float[9]) + (dst_matrix_addr_float[10] * right_matrix_addr_float[10]);
        // const float e11 = (dst_matrix_addr_float[3] * right_matrix_addr_float[8]) + (dst_matrix_addr_float[7] * right_matrix_addr_float[9]) + (dst_matrix_addr_float[11] * right_matrix_addr_float[10]);

        dst_matrix_addr_float[0] = e0; dst_matrix_addr_float[4] = e4; dst_matrix_addr_float[8]  = e8 ;
        dst_matrix_addr_float[1] = e1; dst_matrix_addr_float[5] = e5; dst_matrix_addr_float[9]  = e9 ;
        dst_matrix_addr_float[2] = e2; dst_matrix_addr_float[6] = e6; dst_matrix_addr_float[10] = e10;
        // dst_matrix_addr_float[3] = e3; dst_matrix_addr_float[7] = e7; dst_matrix_addr_float[11] = e11;
      };



      void transp32 (void* dst) {

        float* dst_32_ptr = (float*) dst;

        const float e0 = dst_32_ptr[0] ; const float e4 = dst_32_ptr[1] ; const float e8  = dst_32_ptr[2] ; const float e12 = dst_32_ptr[3] ;
        const float e1 = dst_32_ptr[4] ; const float e5 = dst_32_ptr[5] ; const float e9  = dst_32_ptr[6] ; const float e13 = dst_32_ptr[7] ;
        const float e2 = dst_32_ptr[8] ; const float e6 = dst_32_ptr[9] ; const float e10 = dst_32_ptr[10]; const float e14 = dst_32_ptr[11];
        const float e3 = dst_32_ptr[12]; const float e7 = dst_32_ptr[13]; const float e11 = dst_32_ptr[14]; const float e15 = dst_32_ptr[15];

        SET32(
          dst_32_ptr,

          e0, e4, e8 , e12,
          e1, e5, e9 , e13,
          e2, e6, e10, e14,
          e3, e7, e11, e15
        )
      };



      void invns32 (void* dst) {

        float* dst_32_ptr = (float*) dst;

        const float e0 = dst_32_ptr[0] ; const float e4 = dst_32_ptr[1] ; const float e8  = dst_32_ptr[2] ; const float e12 = -(dst_32_ptr[0] * dst_32_ptr[12]) - (dst_32_ptr[1] * dst_32_ptr[13]) - (dst_32_ptr[2]  * dst_32_ptr[14]);
        const float e1 = dst_32_ptr[4] ; const float e5 = dst_32_ptr[5] ; const float e9  = dst_32_ptr[6] ; const float e13 = -(dst_32_ptr[4] * dst_32_ptr[12]) - (dst_32_ptr[5] * dst_32_ptr[13]) - (dst_32_ptr[6]  * dst_32_ptr[14]);
        const float e2 = dst_32_ptr[8] ; const float e6 = dst_32_ptr[9] ; const float e10 = dst_32_ptr[10]; const float e14 = -(dst_32_ptr[8] * dst_32_ptr[12]) - (dst_32_ptr[9] * dst_32_ptr[13]) - (dst_32_ptr[10] * dst_32_ptr[14]);

        SET32(
          dst_32_ptr,

          e0  , e4  , e8  , e12,
          e1  , e5  , e9  , e13,
          e2  , e6  , e10 , e14,
          0.0f, 0.0f, 0.0f, 1.0f
        )
      };



      void makeProjPersp32 (
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



      // void makeProjPersp32 (
      //   void* m0,

      //   const float left,
      //   const float right,
      //   const float top,
      //   const float bottom,
      //   const float near_,
      //   const float far_
      //) {

      //   SET32(
      //     m0,

      //     2.0f * near_ / (right - left), 0.0f                         , (right + left) / (right - left)  , 0.0f                                   ,
      //     0.0f                         , 2.0f * near_ / (top - bottom), (top + bottom) / (top - bottom)  , 0.0f                                   ,
      //     0.0f                         , 0.0f                         , -(far_ + near_) / (far_ - near_) , -(2.0f * far_ * near_) / (far_ - near_),
      //     0.0f                         , 0.0f                         , -1.0f                            , 0.0f
      //  )
      // };



      // void makeRot32 (void* m0, float* q0) {

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
      //  )
      // };



      // void makeRotX32 (void* m0, const float angle) {

      //   const float cos_ = cos(angle);
      //   const float sin_ = sin(angle);

      //   SET32(
      //     m0,

      //     1.0f, 0.0f , 0.0f, 0.0f,
      //     0.0f, cos_ , sin_, 0.0f,
      //     0.0f, -sin_, cos_, 0.0f,
      //     0.0f, 0.0f , 0.0f, 1.0f
      //  )
      // };
    };
  };
};
