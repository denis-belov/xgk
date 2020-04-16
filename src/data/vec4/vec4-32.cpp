namespace XGK {

  namespace DATA {

    namespace VEC4 {

      void set32 (void* data, const float x, const float y, const float z, const float w) {

        float* _data = (float*) data;

        _data[0] = x;
        _data[1] = y;
        _data[2] = z;
        _data[3] = w;
      };



      void add32 (void* data0, void* data1) {

        float* _data0 = (float*) data0;
        float* _data1 = (float*) data1;

        _data0[0] += _data1[0];
        _data0[1] += _data1[1];
        _data0[2] += _data1[2];
        _data0[3] += _data1[3];
      };



      void adds32 (void* data, const float s) {

        float* _data = (float*) data;

        _data[0] += s;
        _data[1] += s;
        _data[2] += s;
        _data[3] += s;
      };



      void sub32 (void* data0, void* data1) {

        float* _data0 = (float*) data0;
        float* _data1 = (float*) data1;

        _data0[0] -= _data1[0];
        _data0[1] -= _data1[1];
        _data0[2] -= _data1[2];
        _data0[3] -= _data1[3];
      };



      void subs32 (void* data, const float s) {

        float* _data = (float*) data;

        _data[0] -= s;
        _data[1] -= s;
        _data[2] -= s;
        _data[3] -= s;
      };



      void mul32 (void* data0, void* data1) {

        float* _data0 = (float*) data0;
        float* _data1 = (float*) data1;

        _data0[0] *= _data1[0];
        _data0[1] *= _data1[1];
        _data0[2] *= _data1[2];
        _data0[3] *= _data1[3];
      };



      void muls32 (void* data, const float s) {

        float* _data = (float*) data;

        _data[0] *= s;
        _data[1] *= s;
        _data[2] *= s;
        _data[3] *= s;
      };



      void div32 (void* data0, void* data1) {

        float* _data0 = (float*) data0;
        float* _data1 = (float*) data1;

        _data0[0] /= _data1[0];
        _data0[1] /= _data1[1];
        _data0[2] /= _data1[2];
        _data0[3] /= _data1[3];
      };



      void divs32 (void* data, const float s) {

        float* _data = (float*) data;

        _data[0] /= s;
        _data[1] /= s;
        _data[2] /= s;
        _data[3] /= s;
      };
    };
  };
};
