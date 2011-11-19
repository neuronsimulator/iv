dnl make sure we can use the output and input for a stream

AC_LANG_SAVE
AC_LANG_CPLUSPLUS

AC_CXX_NAMESPACES
AC_CXX_HAVE_SSTREAM

xCXXFLAGS="$CXXFLAGS"

if test "$ac_cv_cxx_have_sstream" != yes; then

AC_CHECK_HEADERS(stream.h,[xstmt="define HAVE_STREAM_H"],[xstmt="undef HAVE_STREAM_H"])

ystmt="undef NO_OUTPUT_OPENMODE"
AC_TRY_COMPILE([
#include "src/include/ivstrm.h"
],[
	filebuf obuf;
	obuf.open("name", IOS_OUT);
],[
echo "ivstream.h works with #${xstmt}"
],[
echo "in ivstream.h, the obuf.open("name", output) does not work with #${xstmt}"
echo " trying the NO_OUTPUT_OPENMODE definition"
ystmt="define NO_OUTPUT_OPENMODE"
CXXFLAGS="$CXXFLAGS -DNO_OUTPUT_OPENMODE"
AC_TRY_COMPILE([
#${ystmt}
#include "src/include/ivstrm.h"
],[
	filebuf obuf;
	obuf.open("name", IOS_OUT);
],[
echo "ivstream.h works with #${xstmt} and #${ystmt}"
AC_DEFINE(NO_OUTPUT_OPENMODE,1,[define if stream.h is isufficient by itself])
],[
echo "in ivstream.h, obuf.open("name", std::ios_base::out) does not work with #${xstmt}"
echo " Fix iv-14/src/include/ivstream.h in such a way that configure"
echo " does not stop here."
exit 1
])
])

fi

AC_TRY_LINK([
#${ystmt}
#include "src/include/ivstrm.h"
#if defined(HAVE_NAMESPACES)
using namespace std;
#endif
],[
	filebuf obuf;
	obuf.open("name", IOS_OUT);
],[
echo "We are able to link a c++ program that uses streams"
],[
echo "The attempt to link a program with the statment"
echo "	obuf.open("name", IOS_OUT);"
echo "failed. (Although it compiled in an earlier test)."
echo 'Perhaps you need to add another library. eg setenv LIBS "-lstdc++".'
echo " Fix LIBS or src/include/ivstream.h.in in such a way that configure"
echo " does not stop here."
exit 1
])

CXXFLAGS="$xCXXFLAGS"

AC_LANG_RESTORE
