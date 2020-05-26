#include <cstdint>
#include <cmath>



namespace XGK {

  namespace UTIL {

    void makeBezierCurve3Point (
      const float x1,
      const float y1,
      const float x2,
      const float y2,
      const float x3,
      const float y3,
      const float x4,
      const float y4,
      const float t,
      float* result
    ) {

      const float a = 1.0f - t;
      const float b = a * a;
      const float c = t * t;
      const float d = a * b;
      const float e = 3.0f * t * b;
      const float f = 3.0f * c * a;
      const float g = c * t;

      result[0] = (x1 * d) + (x2 * e) + (x3 * f) + (x4 * g);
      result[1] = (y1 * d) + (y2 * e) + (y3 * f) + (y4 * g);
    };



    void makeBezierCurve3Sequence (
      const float x1,
      const float y1,
      const float x2,
      const float y2,
      const float x3,
      const float y3,
      const float x4,
      const float y4,
      const uint64_t segment_count,
      float* result
    ) {

      uint64_t last = 0;

      float point[2];

      for (uint64_t i = 0; i < segment_count; i++) {

        makeBezierCurve3Point(x1, y1, x2, y2, x3, y3, x4, y4, ((float) i) / ((float) segment_count), point);

        result[i] = point[1];
      }

      result[segment_count - 1] = 1.0f;
    };



    void makeBezierCurve3Sequence2 (
      const float x2,
      const float y2,
      const float x3,
      const float y3,
      const uint64_t segment_count,
      float* result
    ) {

      uint64_t last = 0;

      float point[2];

      for (uint64_t i = 0; i < segment_count; i++) {

        makeBezierCurve3Point(0.0f, 0.0f, x2, y2, x3, y3, 1.0f, 1.0f, ((float) i) / ((float) segment_count), point);

        result[i] = point[1];
      }

      result[segment_count - 1] = 1.0f;
    };
  };
};
