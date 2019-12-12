extern "C" {

/* All X11 structures, declarations, etc. */
/* Do not know if this is needed here. */
#define XUTIL_DEFINE_FUNCTIONS

/* X11 structures, #define, and pointer definitions corresponding to all extern X globals. */
#include <IV-X11/ivx11_declare.h>
#define IVX11EXTERN /**/
#include <IV-X11/ivx11_define.h>

extern int ivx11_dyload(const char* alt_libname);

}

#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <string>

static void (*p_ivx11_assign)();

/** @brief dlopen libivx11dynam.so and call its ivx11_assign.
 *  The library must be in the same directory as the shared library
 *  that contains the address of ivx11_dyload. I.e, the last basename
 *  is either libinterviews or alt_libname and that gets subsituted by
 *  libivx11dynam
 */
int ivx11_dyload(const char* alt_libname) { // return 0 on success
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
  /* If not, try alt_libname if not NULL */
  Dl_info info;
  int rval = dladdr((void*)ivx11_dyload, &info);
  std::string name;
  if (rval) {
    if (info.dli_fname) {
      name = info.dli_fname;
      if (info.dli_fname[0] == '/') { // likely full path
        // dlopen this with RTLD_GLOBAL to make sure the dlopen of libivx11dynam
        // will get its externs resolved (needed when launch python).
        if (!dlopen(name.c_str(), RTLD_NOW | RTLD_NOLOAD | RTLD_GLOBAL)) {
          printf("%s: RTLD_GLOBAL for %s\n", dlerror(), name.c_str());
          return -1;
        }

        /* working after the last / is robust way to replace libinterviews */
        /* or alt_libname with libivx11dynam */
        size_t last_slash = name.rfind("/");
        size_t n1 = name.find("libinterviews.", last_slash);
        size_t n2 = 0;
        if (n1 != std::string::npos) {
          n2 = 13;
        }else if (alt_libname) {
          n1 = name.find(alt_libname, last_slash);
          if (n1 != std::string::npos) {
            n2 = strlen(alt_libname);
          }else{
            printf("No \"libinterviews.\" or \"%s\"in \"%s\"\n", alt_libname, name.c_str());
            return -1;
          }
        }else{
            printf("No \"libinterviews.\" in \"%s\"\n", name.c_str());
            return -1;
        }
        name.replace(n1, n2, "libivx11dynam"); // keeps the .so or .dylib
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
  if (!handle) {
    printf("%s: for %s\n", dlerror(), name.c_str());
    return -1;
  }
  p_ivx11_assign = (void(*)())dlsym(handle, "ivx11_assign");
  if (p_ivx11_assign) {
    (*p_ivx11_assign)();
  }else{
    return -1;
  }
  return 0;
}
