namespace XGK {

  namespace OPENGL {

    void destroyContext () {

      glfwDestroyWindow(window);
      glfwTerminate();
    };



    void initContext (const uint32_t width, const uint32_t height) {

      glfwInit();

      window = glfwCreateWindow(width, height, "Simple example", nullptr, nullptr);

      glfwMakeContextCurrent(window);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
      glfwSwapInterval(1);

      gladLoadGL();

      glViewport(0, 0, width, height);
      glEnable(GL_DEPTH_TEST);
      glDepthFunc(GL_LESS);
      // glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    };
  };
};
