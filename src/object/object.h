namespace XGK {

  // pack ?
  struct Object {

    alignas(16) float mat[16];

    alignas(16) float quat[4];

    alignas(16) float trans[4];

    alignas(16) float aux_vec[4];

    // alignas(MEM_ADDR_LENGTH) void* parent;
  };



  namespace OBJECT {

    inline void init(void*);
    inline void setRot(void*, void*, const float);
    inline void preRot(void*, void*, const float);
    inline void postRot(void*, void*, const float);
    inline void setRotX(void*, const float);
    inline void preRotX(void*, const float);
    inline void postRotX(void*, const float);
    inline void setRotY(void*, const float);
    inline void preRotY(void*, const float);
    inline void postRotY(void*, const float);
    inline void setRotZ(void*, const float);
    inline void preRotZ(void*, const float);
    inline void postRotZ(void*, const float);
    inline void setTrans(void*, void*);
    inline void trans(void*, void*, const float);
    inline void setTransX(void*, const float);
    inline void transX(void*, const float);
    inline void setTransY(void*, const float);
    inline void transY(void*, const float);
    inline void setTransZ(void*, const float);
    inline void transZ(void*, const float);
    inline void update (void*);
  };
};
