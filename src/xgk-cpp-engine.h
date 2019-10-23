#include <stdint.h>
#include <cstring>
#include <intrin.h>
#include <cmath>

// #define WIN32_LEAN_AND_MEAN
// #include "windows.h"

namespace XGK_CPP_ENGINE {
  // #include "data/options.h"

  #include "data/vec4base.h"
  #include "data/vec4.h"
  #include "data/quatbase.h"
  #include "data/quat.h"
  #include "data/mat4cbase.h"
  #include "data/mat4c.h"

  #include "derivatives/transform-object.h"
  #include "derivatives/first-person-camera.h"

  #include "loop.h"

  // void init () {
  //   TransformObject::X.set(1.0f, 0.0f, 0.0f);
  //   TransformObject::Y.set(0.0f, 1.0f, 0.0f);
  //   TransformObject::Z.set(0.0f, 0.0f, 1.0f);
  // };

  inline void SIMD32 () {
    Vec4Base::SIMD32();
    QuatBase::SIMD32();
    Mat4CBase::SIMD32();
  };

  inline void SIMD128 () {
    Vec4Base::SIMD128();
    QuatBase::SIMD128();
    Mat4CBase::SIMD128();
  };

  inline void SIMD256 () {
    Vec4Base::SIMD128();
    QuatBase::SIMD128();
    Mat4CBase::SIMD256();
  };
};
