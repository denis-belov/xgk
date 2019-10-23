struct TransformObject {
  Quat quaternion;
  Vec4 translation;
  Mat4C matrix;

  Vec4 aux_vec;



  // TRANSFORMATIONS
  //////////////////
  //////////////////

  inline void setRotation (Vec4& axis, const float angle) {
    quaternion.makeRotation(axis, angle);
  }

  inline void setRotationX (const float angle) {
    quaternion.makeRotationX(angle);
  }

  inline void setRotationY (const float angle) {
    quaternion.makeRotationY(angle);
  }

  inline void setRotationZ (const float angle) {
    quaternion.makeRotationZ(angle);
  }

  inline void preRotate (Vec4& axis, const float angle) {
    quaternion.preRotate(axis, angle);
  }

  inline void preRotateX (const float angle) {
    quaternion.preRotateX(angle);
  }

  inline void preRotateY (const float angle) {
    quaternion.preRotateY(angle);
  }

  inline void preRotateZ (const float angle) {
    quaternion.preRotateZ(angle);
  }

  inline void postRotate (Vec4& axis, const float angle) {
    quaternion.postRotate(axis, angle);
  }

  inline void postRotateX (const float angle) {
    quaternion.postRotateX(angle);
  }

  inline void postRotateY (const float angle) {
    quaternion.postRotateY(angle);
  }

  inline void postRotateZ (const float angle) {
    quaternion.postRotateZ(angle);
  }

  inline void setTranslation (Vec4& axis, const float value) {
    translation.copy(axis);
    translation.mul(value);
  }

  inline void setTranslationX (const float value) {
    translation.set(value, 0.0f, 0.0f, 0.0f);
  }

  inline void setTranslationY (const float value) {
    translation.set(0.0f, value, 0.0f, 0.0f);
  }

  inline void setTranslationZ (const float value) {
    translation.set(0.0f, 0.0f, value, 0.0f);
  }

  inline void translate (Vec4& axis, const float value) {
    aux_vec.copy(axis);
    aux_vec.mul(value);

    translation.add(aux_vec);
  }

  inline void translateX (const float value) {
    translation.addX(value);
  }

  inline void translateY (const float value) {
    translation.addY(value);
  }

  inline void translateZ (const float value) {
    translation.addZ(value);
  }

  ///////
  ///////
  ///////



  // UPDATE
  /////////
  /////////

  inline void update () {
    matrix.makeRotation(quaternion);
    matrix.preTranslate(translation, 1.0f);
  };

  ///////
  ///////
  ///////
};
