extern "C" {

/* All X11 structures, declarations, etc. */
/* Do not know if this is needed here. */
#define XUTIL_DEFINE_FUNCTIONS

/* X11 structures, #define, and pointer definitions corresponding to all extern X globals. */
#include <IV-X11/ivx11_declare.h>
#define IVX11EXTERN /**/
#include <IV-X11/ivx11_define.h>

extern int ivx11_dyload();
}

#include <stdio.h>
#include <dlfcn.h>
#include <string>

static void (*p_ivx11_assign)();

int ivx11_dyload() { // return 0 on success
  /* only load once */
  if (p_ivx11_assign) {
    return 0;
  }

  /* see if ivx11_assign already loaded and if so use that */
  p_ivx11_assign = (void(*)())dlsym(RTLD_DEFAULT, "ivx11_assign");
  if (p_ivx11_assign) {
    (*p_ivx11_assign)();
    return 0;
  }

  /* dynamically load libivx11dynam.so and call its ivx11_assign() */

  /* figure out path of libivx11dynam.so*/
  /* Assumes libinterviews is a shared library (that defined ivx11_dyload)*/
  Dl_info info;
  int rval = dladdr((void*)ivx11_dyload, &info);
  std::string name;
  if (rval) {
    if (info.dli_fname) {
      name = info.dli_fname;
      if (info.dli_fname[0] == '/') { // likely full path
        size_t n = name.find("libinterviews");
        if (n != std::string::npos) {
          name.replace(n, 13, "libivx11dynam"); // keeps the .so or .dylib
        }else{
          printf("No \"libinterviews\" in \"%s\"\n", name.c_str());
          return -1;
        }
      }else{
        printf("Not a full path \"%s\"\n", name.c_str());
        return -1;
      }
    }else{
      printf("dladdr no DL_info.dli_fname\n");
      return -1;
    }
  }else{
    printf("%s\n", dlerror());
    return -1;
  }

  int flag = RTLD_NOW | RTLD_GLOBAL;
  void* handle = dlopen(name.c_str(), flag);
  if (!handle) { return -1; }
  p_ivx11_assign = (void(*)())dlsym(handle, "ivx11_assign");
  if (p_ivx11_assign) {
    (*p_ivx11_assign)();
  }else{
    return -1;
  }
  return 0;
}
