// SET is only scalar-implemented, because there is no way to have a common function prototype with same number of arguments

void (* m4_set) (
  Mat4C*,

  const float, const float, const float, const float,
  const float, const float, const float, const float,
  const float, const float, const float, const float,
  const float, const float, const float, const float
);

void (* m4_mul) (Mat4C*, Mat4C*, Mat4C*);

void (* m4_premul) (Mat4C*, Mat4C*);

void (* m4_postmul) (Mat4C*, Mat4C*);

void (* m4_mulS) (Mat4C*, float);

void (* m4_inv) (Mat4C*);
