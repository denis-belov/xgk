#include <cmath>

#include "orbit.h"
#undef XGK_NO_INLINE
#include "data/data.h"
#include "object/object.h"
#include "time/time.h"



namespace XGK {

  namespace ORBIT {

    void init (Orbit* orbit_addr, Object* object_addr, Transition* transition_addr) {

      orbit_addr->speed_x = 0.0f;
      orbit_addr->speed_y = 0.0f;
      orbit_addr->object = object_addr;
      orbit_addr->transition = transition_addr;
      orbit_addr->transition->additional = orbit_addr;

      DATA::MAT4::ident(orbit_addr->view_mat);

      OBJECT::init(orbit_addr->object);
    };



    void update (Orbit* orbit_addr) {

      OBJECT::update2(orbit_addr->object);

      DATA::MAT4::invns(orbit_addr->object);
      DATA::MAT4::copy(orbit_addr, orbit_addr->object);
    };



    void rotate (Orbit* orbit_addr) {

      OBJECT::postRotX(orbit_addr->object, orbit_addr->speed_x);
      // OBJECT::preRotY(orbit_addr->object, orbit_addr->speed_y);
    };



    void test (float interpolation, void* additional) {

      Orbit* orbit_addr = (Orbit*) additional;

      rotate(orbit_addr);
      update(orbit_addr);

      float temp = 0.000001f * pow(1.0f - interpolation, 2.0);

      orbit_addr->speed_x = temp;
      orbit_addr->speed_y = temp;
    };



    void move (Orbit* orbit_addr, Time* time, const float movement_x, const float movement_y) {

      // orbit_addr->speed_x -= movement_y;
      // orbit_addr->speed_y -= movement_x;

      orbit_addr->speed_x = 0.000001f;
      orbit_addr->speed_y = 0.000001f;

      TIME::setTransition2(time, orbit_addr->transition, 1000.0f, test);
    };
  };
};
