#include "data/data.h"
#include "object.h"



namespace XGK {

  namespace OBJECT {

    void init (Object* object_addr) {

      DATA::MAT4::ident(&object_addr->mat);
      DATA::QUAT::ident(&object_addr->quat);
      DATA::VEC4::reset(&object_addr->trans);
      // DATA::MAT4::ident(&object_addr->parent);
    };



    void setRot(Object* object_addr, void* vector_addr, const float angle) {

      DATA::QUAT::makeRot(&object_addr->quat, vector_addr, angle);
    };

    void preRot(Object* object_addr, void* vector_addr, const float angle) {

      DATA::QUAT::preRot(&object_addr->quat, vector_addr, angle);
    };

    void postRot(Object* object_addr, void* vector_addr, const float angle) {

      DATA::QUAT::postRot(&object_addr->quat, vector_addr, angle);
    };



    void setRotX(Object* object_addr, const float angle) {

      DATA::QUAT::makeRotX(&object_addr->quat, angle);
    };

    void preRotX(Object* object_addr, const float angle) {

      DATA::QUAT::preRotX(&object_addr->quat, angle);
    };

    void postRotX(Object* object_addr, const float angle) {

      DATA::QUAT::postRotX(&object_addr->quat, angle);
    };



    void setRotY(Object* object_addr, const float angle) {

      DATA::QUAT::makeRotY(&object_addr->quat, angle);
    };

    void preRotY(Object* object_addr, const float angle) {

      DATA::QUAT::preRotY(&object_addr->quat, angle);
    };

    void postRotY(Object* object_addr, const float angle) {

      DATA::QUAT::postRotY(&object_addr->quat, angle);
    };



    void setRotZ(Object* object_addr, const float angle) {

      DATA::QUAT::makeRotZ(&object_addr->quat, angle);
    };

    void preRotZ(Object* object_addr, const float angle) {

      DATA::QUAT::preRotZ(&object_addr->quat, angle);
    };

    void postRotZ(Object* object_addr, const float angle) {

      DATA::QUAT::postRotZ(&object_addr->quat, angle);
    };



    void setTrans(Object* object_addr, void* vector_addr) {

      DATA::VEC4::copy(&object_addr->trans, vector_addr);
    };

    void trans(Object* object_addr, void* vector_addr, const float value) {

      DATA::VEC4::copy(&object_addr->aux_vec, vector_addr);
      DATA::VEC4::muls(&object_addr->aux_vec, value);
      DATA::VEC4::add(&object_addr->trans, &object_addr->aux_vec);
    };



    void setTransX(Object* object_addr, const float value) {

      object_addr->trans[0] = value;
    };

    void transX(Object* object_addr, const float value) {

      object_addr->trans[0] += value;
    };



    void setTransY(Object* object_addr, const float value) {

      object_addr->trans[1] = value;
    };

    void transY(Object* object_addr, const float value) {

      object_addr->trans[1] += value;
    };



    void setTransZ(Object* object_addr, const float value) {

      object_addr->trans[2] = value;
    };

    void transZ(Object* object_addr, const float value) {

      object_addr->trans[2] += value;
    };



    void update (Object* object_addr) {

      XGK::DATA::QUAT::norm(&object_addr->quat);
      DATA::MAT4::makeRotQuat(object_addr,  &object_addr->quat);
      DATA::MAT4::preTrans(object_addr, &object_addr->trans);
      // DATA::MAT4::premul(object_addr, &object_addr->parent);
    };

    void update2 (Object* object_addr) {

      XGK::DATA::QUAT::norm(&object_addr->quat);
      DATA::MAT4::makeTrans(object_addr, &object_addr->trans);
      DATA::MAT4::preRotQuat(object_addr,  &object_addr->quat);
      // DATA::MAT4::premul(object_addr, &object_addr->parent);
    };

    void update3 (Object* object_addr) {

      DATA::MAT4::makeTransValue(object_addr, &object_addr->origin, 1.0f);
      DATA::MAT4::preRotQuat(object_addr,  &object_addr->quat);
      DATA::MAT4::preTransValue(object_addr, &object_addr->origin, -1.0f);
      DATA::MAT4::preTrans(object_addr, &object_addr->trans);
      // DATA::MAT4::premul(object_addr, &object_addr->parent);
    };
  };
};



// namespace XGK {

//   namespace OBJECT {

//     void init (void* object_addr) {

//       float* object_addr_float = (float*) object_addr;

//       DATA::MAT4::ident(object_addr_float);
//       DATA::QUAT::ident(object_addr_float + 16);
//       DATA::VEC4::reset(object_addr_float + 20);
//       DATA::VEC4::reset(object_addr_float + 24);
//       // DATA::MAT4::ident(object_addr_float + 28);
//     };



//     void setRot(void* object_addr, void* vector_addr, const float angle) {

//       DATA::QUAT::makeRot((float*) object_addr + 16, vector_addr, angle);
//     };

//     void preRot(void* object_addr, void* vector_addr, const float angle) {

//       DATA::QUAT::preRot((float*) object_addr + 16, vector_addr, angle);
//     };

//     void postRot(void* object_addr, void* vector_addr, const float angle) {

//       DATA::QUAT::postRot((float*) object_addr + 16, vector_addr, angle);
//     };



//     void setRotX(void* object_addr, const float angle) {

//       DATA::QUAT::makeRotX((float*) object_addr + 16, angle);
//     };

//     void preRotX(void* object_addr, const float angle) {

//       DATA::QUAT::preRotX((float*) object_addr + 16, angle);
//     };


//     void postRotX(void* object_addr, const float angle) {

//       DATA::QUAT::postRotX((float*) object_addr + 16, angle);
//     };



//     void setRotY(void* object_addr, const float angle) {

//       DATA::QUAT::makeRotY((float*) object_addr + 16, angle);
//     };

//     void preRotY(void* object_addr, const float angle) {

//       DATA::QUAT::preRotY((float*) object_addr + 16, angle);
//     };

//     void postRotY(void* object_addr, const float angle) {

//       DATA::QUAT::postRotY((float*) object_addr + 16, angle);
//     };



//     void setRotZ(void* object_addr, const float angle) {

//       DATA::QUAT::makeRotZ((float*) object_addr + 16, angle);
//     };

//     void preRotZ(void* object_addr, const float angle) {

//       DATA::QUAT::preRotZ((float*) object_addr + 16, angle);
//     };

//     void postRotZ(void* object_addr, const float angle) {

//       DATA::QUAT::postRotZ((float*) object_addr + 16, angle);
//     };



//     void setTrans(void* object_addr, void* vector_addr) {

//       DATA::VEC4::copy((float*) object_addr + 20, vector_addr);
//     };

//     void trans(void* object_addr, void* vector_addr, const float value) {

//       DATA::VEC4::copy((float*) object_addr + 24, vector_addr);
//       DATA::VEC4::muls((float*) object_addr + 24, value);
//       DATA::VEC4::add((float*) object_addr + 20, (float*) object_addr + 24);
//     };



//     void setTransX(void* object_addr, const float value) {

//       ((float*) object_addr + 20)[0] = value;
//     };

//     void transX(void* object_addr, const float value) {

//      ((float*) object_addr + 20)[0] += value;
//     };



//     void setTransY(void* object_addr, const float value) {

//       ((float*) object_addr + 20)[1] = value;
//     };

//     void transY(void* object_addr, const float value) {

//      ((float*) object_addr + 20)[1] += value;
//     };



//     void setTransZ(void* object_addr, const float value) {

//       ((float*) object_addr + 20)[2] = value;
//     };

//     void transZ(void* object_addr, const float value) {

//      ((float*) object_addr + 20)[2] += value;
//     };



//     void update (void* object_addr) {

//       float* object_addr_float = (float*) object_addr;

//       DATA::MAT4::makeRotQuat(object_addr_float, object_addr_float + 16);
//       DATA::MAT4::preTrans(object_addr_float, object_addr_float + 20);
//       // DATA::MAT4::premul(object_addr_float, object_addr_float + 28);
//     };
//   };
// };
