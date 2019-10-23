struct Mat4C : Mat4CBase {
  Mat4CBase aux_mat;



  inline void preTranslate (Vec4& axis, const float value) {
    aux_mat.makeTranslation(axis, value);

    premul_ptr(this, aux_mat);
  }

  inline void postTranslate (Vec4& axis, const float value) {
    aux_mat.makeTranslation(axis, value);

    postmul_ptr(this, aux_mat);
  }
};
