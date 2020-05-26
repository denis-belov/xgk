namespace XGK {

  namespace VULKAN {

    struct Instance {

      std::vector<const char*> layers;
      std::vector<const char*> extensions;
    };



    Instance::addLayers (const char**, const uint64_t);

    Instance::addExtensions (const char**, const uint64_t);



    struct Device {

    };



    void loadSharedLibrary (void);

    void freeSharedLibrary (void);
  };
};
