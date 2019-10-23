struct FirstPersonCamera {
  Mat4C projection_matrix;
  Mat4C view_matrix;
  TransformObject object;



  // UPDATE
  /////////
  /////////

  inline void update () {
    object.update();

    view_matrix.copy(object.matrix);
    view_matrix.inv();
  };

  ///////
  ///////
  ///////
};
