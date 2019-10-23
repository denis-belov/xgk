struct Vec4Base {
  __declspec(align(16)) union {
    float  _32[4];
    __m128 _128;
  } data;



  const uint8_t FLOAT_SIZE_4  = sizeof(float) * 4;

  const float IDENTITY[4] = { 0.0f, 0.0f, 0.0f, 0.0f };



  inline static void (* set_ptr) (
    Vec4Base*,

    const float,
    const float,
    const float,
    const float
  );

  inline static void (* add_ptr) (
    Vec4Base*,

    const Vec4Base&
  );

  inline static void (* addS_ptr) (
    Vec4Base*,

    const float
  );

  inline static void (* sub_ptr) (
    Vec4Base*,

    const Vec4Base&
  );

  inline static void (* subS_ptr) (
    Vec4Base*,

    const float
  );

  inline static void (* mul_ptr) (
    Vec4Base*,

    const Vec4Base&
  );

  inline static void (* mulS_ptr) (
    Vec4Base*,

    const float
  );

  inline static void (* div_ptr) (
    Vec4Base*,

    const Vec4Base&
  );

  inline static void (* divS_ptr) (
    Vec4Base*,

    const float
  );



  Vec4Base () {
    set32(
      this,

      0.0f, 0.0f, 0.0f, 0.0f
    );
  };



  // SET static
  /////////////
  /////////////

  inline static void set32 (
    Vec4Base* v,

    const float x,
    const float y,
    const float z,
    const float w
  ) {
    v->data._32[0] = x;
    v->data._32[1] = y;
    v->data._32[2] = z;
    v->data._32[3] = w;
  };

  inline static void set128 (
    Vec4Base* v,

    const float x,
    const float y,
    const float z,
    const float w
  ) {
    v->data._128 = _mm_setr_ps(x, y, z, w);
  };

  ///////
  ///////
  ///////



  // ADD static
  /////////////
  /////////////

  inline static void add32 (
    Vec4Base* v1,

    const Vec4Base& v2
  ) {
    v1->data._32[0] += v2.data._32[0];
    v1->data._32[1] += v2.data._32[1];
    v1->data._32[2] += v2.data._32[2];
    v1->data._32[3] += v2.data._32[3];
  };

  inline static void add128 (
    Vec4Base* v1,

    const Vec4Base& v2
  ) {
    v1->data._128 = _mm_add_ps(v1->data._128, v2.data._128);
  };

  inline static void addScalar32 (
    Vec4Base* v,

    const float s
  ) {
    v->data._32[0] += s;
    v->data._32[1] += s;
    v->data._32[2] += s;
    v->data._32[3] += s;
  };

  inline static void addScalar128 (
    Vec4Base* v,

    const float s
  ) {
    v->data._128 = _mm_add_ps(v->data._128, _mm_set1_ps(s));
  };

  ///////
  ///////
  ///////



  // SUBTRACT static
  //////////////////
  //////////////////

  inline static void subtract32 (
    Vec4Base* v1,

    const Vec4Base& v2
  ) {
    v1->data._32[0] -= v2.data._32[0];
    v1->data._32[1] -= v2.data._32[1];
    v1->data._32[2] -= v2.data._32[2];
    v1->data._32[3] -= v2.data._32[3];
  };

  inline static void subtract128 (
    Vec4Base* v1,

    const Vec4Base& v2
  ) {
    v1->data._128 = _mm_sub_ps(v1->data._128, v2.data._128);
  };

  inline static void subtractScalar32 (
    Vec4Base* v,

    const float s
  ) {
    v->data._32[0] -= s;
    v->data._32[1] -= s;
    v->data._32[2] -= s;
    v->data._32[3] -= s;
  };

  inline static void subtractScalar128 (
    Vec4Base* v,

    const float s
  ) {
    v->data._128 = _mm_sub_ps(v->data._128, _mm_set1_ps(s));
  };

  ///////
  ///////
  ///////



  // MULTIPLY static
  //////////////////
  //////////////////

  inline static void multiply32 (
    Vec4Base* v1,

    const Vec4Base& v2
  ) {
    v1->data._32[0] *= v2.data._32[0];
    v1->data._32[1] *= v2.data._32[1];
    v1->data._32[2] *= v2.data._32[2];
    v1->data._32[3] *= v2.data._32[3];
  };

  inline static void multiply128 (
    Vec4Base* v1,

    const Vec4Base& v2
  ) {
    v1->data._128 = _mm_mul_ps(v1->data._128, v2.data._128);
  };

  inline static void multiplyScalar32 (
    Vec4Base* v,

    const float s
  ) {
    v->data._32[0] *= s;
    v->data._32[1] *= s;
    v->data._32[2] *= s;
    v->data._32[3] *= s;
  };

  inline static void multiplyScalar128 (
    Vec4Base* v,

    const float s
  ) {
    v->data._128 = _mm_mul_ps(v->data._128, _mm_set1_ps(s));
  };

  ///////
  ///////
  ///////



  // DIVIDE static
  ////////////////
  ////////////////

  inline static void divide32 (
    Vec4Base* v1,

    const Vec4Base& v2
  ) {
    v1->data._32[0] /= v2.data._32[0];
    v1->data._32[1] /= v2.data._32[1];
    v1->data._32[2] /= v2.data._32[2];
    v1->data._32[3] /= v2.data._32[3];
  };

  inline static void divide128 (
    Vec4Base* v1,

    const Vec4Base& v2
  ) {
    v1->data._128 = _mm_div_ps(v1->data._128, v2.data._128);
  };

  inline static void divideScalar32 (
    Vec4Base* v,

    const float s
  ) {
    v->data._32[0] /= s;
    v->data._32[1] /= s;
    v->data._32[2] /= s;
    v->data._32[3] /= s;
  };

  inline static void divideScalar128 (
    Vec4Base* v,

    const float s
  ) {
    v->data._128 = _mm_div_ps(v->data._128, _mm_set1_ps(s));
  };

  ///////
  ///////
  ///////



  // SIMD static
  //////////////
  //////////////

  static void SIMD32 () {
    set_ptr = set32;
    add_ptr = add32;
    addS_ptr = addScalar32;
    sub_ptr = subtract32;
    subS_ptr = subtractScalar32;
    mul_ptr = multiply32;
    mulS_ptr = multiplyScalar32;
    div_ptr = divide32;
    divS_ptr = divideScalar32;
  };

  static void SIMD128 () {
    set_ptr = set128;
    add_ptr = add128;
    addS_ptr = addScalar128;
    sub_ptr = subtract128;
    subS_ptr = subtractScalar128;
    mul_ptr = multiply128;
    mulS_ptr = multiplyScalar128;
    div_ptr = divide128;
    divS_ptr = divideScalar128;
  };

  ///////
  ///////
  ///////



  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////


  // SET
  //////
  //////

  inline void set (
    const float x,
    const float y,
    const float z,
    const float w
  ) {
    set_ptr(
      this,

      x, y, z, w
    );
  };

  ///////
  ///////
  ///////



  // ADD
  //////
  //////

  inline void add (const Vec4Base& v) {
    add_ptr(
      this,

      v
    );
  };

  inline void add (const float s) {
    addS_ptr(
      this,

      s
    );
  };

  inline void addX (const float s) {
    data._32[0] += s;
  };

  inline void addY (const float s) {
    data._32[1] += s;
  };

  inline void addZ (const float s) {
    data._32[2] += s;
  };

  inline void addW (const float s) {
    data._32[3] += s;
  };

  ///////
  ///////
  ///////



  // SUBTRACT
  ///////////
  ///////////

  inline void sub (const Vec4Base& v) {
    sub_ptr(
      this,

      v
    );
  };

  inline void sub (const float s) {
    subS_ptr(
      this,

      s
    );
  };

  inline void subX (const float s) {
    data._32[0] -= s;
  };

  inline void subY (const float s) {
    data._32[1] -= s;
  };

  inline void subZ (const float s) {
    data._32[2] -= s;
  };

  inline void subW (const float s) {
    data._32[3] -= s;
  };

  ///////
  ///////
  ///////



  // MULTIPLY
  ///////////
  ///////////

  inline void mul (const Vec4Base& v) {
    mul_ptr(
      this,

      v
    );
  };

  inline void mul (const float s) {
    mulS_ptr(
      this,

      s
    );
  };

  inline void mulX (const float s) {
    data._32[0] *= s;
  };

  inline void mulY (const float s) {
    data._32[1] *= s;
  };

  inline void mulZ (const float s) {
    data._32[2] *= s;
  };

  inline void mulW (const float s) {
    data._32[3] *= s;
  };

  ///////
  ///////
  ///////



  // DIVIDE
  /////////
  /////////

  inline void div (const Vec4Base& v) {
    div_ptr(
      this,

      v
    );
  };

  inline void div (const float s) {
    divS_ptr(
      this,

      s
    );
  };

  inline void divX (const float s) {
    data._32[0] /= s;
  };

  inline void divY (const float s) {
    data._32[1] /= s;
  };

  inline void divZ (const float s) {
    data._32[2] /= s;
  };

  inline void divW (const float s) {
    data._32[3] /= s;
  };

  ///////
  ///////
  ///////



  // COPY
  ///////
  ///////

  inline void copy (const Vec4Base& v) {
    memcpy(&data, &v, FLOAT_SIZE_4);
  };

  ///////
  ///////
  ///////



  // RESET
  ////////
  ////////

  inline void reset () {
    memcpy(&data, IDENTITY, FLOAT_SIZE_4);
  };

  ///////
  ///////
  ///////
};
