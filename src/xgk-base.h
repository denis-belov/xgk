#ifdef _MSC_VER
  #define XGK_MACRO_STRUCT_ALIGNMENT(n) __declspec (align(n)) struct
#else
  #define XGK_MACRO_STRUCT_ALIGNMENT(n) struct __attribute__((aligned(n)))
#endif



namespace XGK {
  static char* global_api = "opengl";
};
