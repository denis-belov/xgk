// #include "object/object.h"
// #include "orbit.h"



// namespace XGK {

//   namespace ORBIT {

//     void init (Orbit* orbit_addr) {

//       orbit_addr->speed_x = 0.0f;
//       orbit_addr->speed_y = 0.0f;

//       OBJECT::init(orbit_addr);
//     };



//     void rotate (Orbit* orbit_addr) {

//       OBJECT::postRotX(&orbit_addr->object, orbit_addr->speed_x);
//       OBJECT::preRotY(&orbit_addr->object, orbit_addr->speed_y);
//     };



//     void test (Orbit* orbit_addr, float interpolation) {

//       rotate(orbit_addr);

//       orbit_addr->speed_x *= interpolation;
//       orbit_addr->speed_y *= interpolation;
//     };



//     void move (void* orbit_addr, const float movement_x, const float movement_y) {

//       orbit_addr->speed_x -= movement_y;
//       orbit_addr->speed_y -= movement_x;

//       TIME::setTransition2(orbit_addr->time, &orbit_addr->transition, 1000, test);
//     };



//     void update (void* orbit_addr) {

//       OBJECT::update(&orbit_addr->object);

//       DATA::MAT4::copy(orbit_addr, &orbit_addr->object);
//       DATA::MAT4::invns(orbit_addr);
//     };
//   };
// };
