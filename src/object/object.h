namespace XGK {

  // pack ?
  struct Object {

    alignas(16) float mat[16];

    alignas(16) float quat[4];

    alignas(16) float trans[4];

    alignas(16) float origin[4];

    alignas(16) float aux_vec[4];

    // alignas(MEM_ADDR_LENGTH) void* parent;
  };



  #ifndef XGK_NO_INLINE

    namespace OBJECT {

      inline void init (Object*);
      inline void setRot (Object*, void*, const float);
      inline void preRot (Object*, void*, const float);
      inline void postRot (Object*, void*, const float);
      inline void setRotX (Object*, const float);
      inline void preRotX (Object*, const float);
      inline void postRotX (Object*, const float);
      inline void setRotY (Object*, const float);
      inline void preRotY (Object*, const float);
      inline void postRotY (Object*, const float);
      inline void setRotZ (Object*, const float);
      inline void preRotZ (Object*, const float);
      inline void postRotZ (Object*, const float);
      inline void setTrans (Object*, void*);
      inline void trans (Object*, void*, const float);
      inline void setTransX (Object*, const float);
      inline void transX (Object*, const float);
      inline void setTransY (Object*, const float);
      inline void transY (Object*, const float);
      inline void setTransZ  (Object*, const float);
      inline void transZ (Object*, const float);
      inline void update (Object*);
      inline void update2 (Object*);
      inline void update3 (Object*);
    };
  #endif
};
