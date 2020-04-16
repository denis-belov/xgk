namespace XGK {

  struct Time;
  struct Transition;
  struct Object;



  // pack ?
  struct Orbit {

    alignas(16) float view_mat[16];

    alignas(16) float proj_mat[16];

    alignas(MEM_ADDR_LENGTH) Time* time;

    alignas(MEM_ADDR_LENGTH) Transition* transition;

    alignas(MEM_ADDR_LENGTH) Object* object;

    alignas(4) float speed_x;

    alignas(4) float speed_y;
  };



  namespace ORBIT {

    inline void init (Orbit*);
    inline void rotate (Orbit*);
    inline void test (Orbit*, const float);
    inline void move (Orbit*, const float, const float);
    inline void update (Orbit*);
  };
};
