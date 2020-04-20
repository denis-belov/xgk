#include <cstdint>
#include <cmath>



namespace XGK {

  namespace DATA {

    namespace QUAT {

      void premul32 (void* data0, void* data1) {

        float* _data0 = (float*) data0;
        const float* _data1 = (float*) data1;

        const float x0 = _data0[0];
        const float y0 = _data0[1];
        const float z0 = _data0[2];
        const float w0 = _data0[3];

        _data0[0] = (_data1[0] * w0) + (_data1[3] * x0) + (_data1[1] * z0) - (_data1[2] * y0);
        _data0[1] = (_data1[1] * w0) + (_data1[3] * y0) + (_data1[2] * x0) - (_data1[0] * z0);
        _data0[2] = (_data1[2] * w0) + (_data1[3] * z0) + (_data1[0] * y0) - (_data1[1] * x0);
        _data0[3] = (_data1[3] * w0) - (_data1[0] * x0) - (_data1[1] * y0) - (_data1[2] * z0);
      };



      void postmul32 (void* data0, void* data1) {

        float* _data0 = (float*) data0;
        const float* _data1 = (float*) data1;

        const float x0 = _data0[0];
        const float y0 = _data0[1];
        const float z0 = _data0[2];
        const float w0 = _data0[3];

        _data0[0] = (x0 * _data1[3]) + (w0 * _data1[0]) + (y0 * _data1[2]) - (z0 * _data1[1]);
        _data0[1] = (y0 * _data1[3]) + (w0 * _data1[1]) + (z0 * _data1[0]) - (x0 * _data1[2]);
        _data0[2] = (z0 * _data1[3]) + (w0 * _data1[2]) + (x0 * _data1[1]) - (y0 * _data1[0]);
        _data0[3] = (w0 * _data1[3]) - (x0 * _data1[0]) - (y0 * _data1[1]) - (z0 * _data1[2]);
      };



      void makeRot32 (void* data, void* axis, const float angle) {

        float* _data = (float*) data;
        float* _axis = (float*) axis;

        const float angle_half = angle * 0.5f;
        const float _sin = sin(angle_half);

        _data[0] = _axis[0] * _sin;
        _data[1] = _axis[1] * _sin;
        _data[2] = _axis[2] * _sin;
        _data[3] = cos(angle_half);
      };



      void preRot32 (void* dst_quaternion_addr, void* axis_addr, const float angle) {

        float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;
        float* axis_addr_float = (float*) axis_addr;

        const float angle_half = angle * 0.5f;
        const float _sin = sin(angle_half);

        const float x0 = dst_quaternion_addr_float[0];
        const float y0 = dst_quaternion_addr_float[1];
        const float z0 = dst_quaternion_addr_float[2];
        const float w0 = dst_quaternion_addr_float[3];

        const float x1 = axis_addr_float[0] * _sin;
        const float y1 = axis_addr_float[1] * _sin;
        const float z1 = axis_addr_float[2] * _sin;
        const float w1 = cos(angle_half);

        dst_quaternion_addr_float[0] = (x1 * w0) + (w1 * x0) + (y1 * z0) - (z1 * y0);
        dst_quaternion_addr_float[1] = (y1 * w0) + (w1 * y0) + (z1 * x0) - (x1 * z0);
        dst_quaternion_addr_float[2] = (z1 * w0) + (w1 * z0) + (x1 * y0) - (y1 * x0);
        dst_quaternion_addr_float[3] = (w1 * w0) - (x1 * x0) - (y1 * y0) - (z1 * z0);
      };



      void postRot32 (void* dst_quaternion_addr, void* axis_addr, const float angle) {

        float* dst_quaternion_addr_float = (float*) dst_quaternion_addr;
        float* axis_addr_float = (float*) axis_addr;

        const float angle_half = angle * 0.5f;
        const float _sin = sin(angle_half);

        const float x0 = dst_quaternion_addr_float[0];
        const float y0 = dst_quaternion_addr_float[1];
        const float z0 = dst_quaternion_addr_float[2];
        const float w0 = dst_quaternion_addr_float[3];

        const float x1 = axis_addr_float[0] * _sin;
        const float y1 = axis_addr_float[1] * _sin;
        const float z1 = axis_addr_float[2] * _sin;
        const float w1 = cos(angle_half);

        dst_quaternion_addr_float[0] = (x0 * w1) + (w0 * x1) + (y0 * z1) - (z0 * y1);
        dst_quaternion_addr_float[1] = (y0 * w1) + (w0 * y1) + (z0 * x1) - (x0 * z1);
        dst_quaternion_addr_float[2] = (z0 * w1) + (w0 * z1) + (x0 * y1) - (y0 * x1);
        dst_quaternion_addr_float[3] = (w0 * w1) - (x0 * x1) - (y0 * y1) - (z0 * z1);
      };



      void makeRotX32 (void* data, const float angle) {

        float* _data = (float*) data;

        const float angle_half = angle * 0.5f;

        _data[0] = sin(angle_half);
        _data[1] = 0.0f;
        _data[2] = 0.0f;
        _data[3] = cos(angle_half);
      };



      void preRotX32 (void* data, const float angle) {

        float* _data = (float*) data;

        const float angle_half = angle * 0.5f;

        const float x0 = _data[0];
        const float y0 = _data[1];
        const float z0 = _data[2];
        const float w0 = _data[3];

        const float x1 = sin(angle_half);
        const float w1 = cos(angle_half);

        // _data[0] = (x1 * w0) + (w1 * x0);
        _data[0] = (w1 * x0) + (x1 * w0);
        _data[1] = (w1 * y0) - (x1 * z0);
        _data[2] = (w1 * z0) + (x1 * y0);
        _data[3] = (w1 * w0) - (x1 * x0);
      };



      void postRotX32 (void* data, const float angle) {

        float* _data = (float*) data;

        const float angle_half = angle * 0.5f;

        const float x0 = _data[0];
        const float y0 = _data[1];
        const float z0 = _data[2];
        const float w0 = _data[3];

        const float x1 = sin(angle_half);
        const float w1 = cos(angle_half);

        _data[0] = (x0 * w1) + (w0 * x1);
        _data[1] = (y0 * w1) + (z0 * x1);
        _data[2] = (z0 * w1) - (y0 * x1);
        _data[3] = (w0 * w1) - (x0 * x1);
      };



      void makeRotY32 (void* data, const float angle) {

        float* _data = (float*) data;

        const float angle_half = angle * 0.5f;

        _data[0] = 0.0f;
        _data[1] = sin(angle_half);
        _data[2] = 0.0f;
        _data[3] = cos(angle_half);
      };



      void preRotY32 (void* data, const float angle) {

        float* _data = (float*) data;

        const float angle_half = angle * 0.5f;

        const float x0 = _data[0];
        const float y0 = _data[1];
        const float z0 = _data[2];
        const float w0 = _data[3];

        const float y1 = sin(angle_half);
        const float w1 = cos(angle_half);

        _data[0] = (w1 * x0) + (y1 * z0);
        _data[1] = (w1 * y0) + (y1 * w0);
        _data[2] = (w1 * z0) - (y1 * x0);
        _data[3] = (w1 * w0) - (y1 * y0);
      };



      void postRotY32 (void* data, const float angle) {

        float* _data = (float*) data;

        const float angle_half = angle * 0.5f;

        const float x0 = _data[0];
        const float y0 = _data[1];
        const float z0 = _data[2];
        const float w0 = _data[3];

        const float y1 = sin(angle_half);
        const float w1 = cos(angle_half);

        _data[0] = (x0 * w1) - (z0 * y1);
        _data[1] = (y0 * w1) + (w0 * y1);
        _data[2] = (z0 * w1) + (x0 * y1);
        _data[3] = (w0 * w1) - (y0 * y1);
      };



      void makeRotZ32 (void* data, const float angle) {

        float* _data = (float*) data;

        const float angle_half = angle * 0.5f;

        _data[0] = 0.0f;
        _data[1] = 0.0f;
        _data[2] = sin(angle_half);
        _data[3] = cos(angle_half);
      };



      void preRotZ32 (void* data, const float angle) {

        float* _data = (float*) data;

        const float angle_half = angle * 0.5f;

        const float x0 = _data[0];
        const float y0 = _data[1];
        const float z0 = _data[2];
        const float w0 = _data[3];

        const float z1 = sin(angle_half);
        const float w1 = cos(angle_half);

        _data[0] = (w1 * x0) - (z1 * y0);
        _data[1] = (w1 * y0) + (z1 * x0);
        _data[2] = (w1 * z0) + (z1 * w0);
        _data[3] = (w1 * w0) - (z1 * z0);
      };



      void postRotZ32 (void* data, const float angle) {

        float* _data = (float*) data;

        const float angle_half = angle * 0.5f;

        const float x0 = _data[0];
        const float y0 = _data[1];
        const float z0 = _data[2];
        const float w0 = _data[3];

        const float z1 = sin(angle_half);
        const float w1 = cos(angle_half);

        _data[0] = (x0 * w1) + (y0 * z1);
        _data[1] = (y0 * w1) - (x0 * z1);
        _data[2] = (z0 * w1) + (w0 * z1);
        _data[3] = (w0 * w1) - (z0 * z1);
      };
    };
  };
};
