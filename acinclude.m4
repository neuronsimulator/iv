dnl This was shamelessly stolen from the readline distribution.
dnl Check type of signal routines (posix, 4.2bsd, 4.1bsd or v7)
AC_DEFUN([BASH_SIGNAL_CHECK],
[AC_REQUIRE([AC_TYPE_SIGNAL])
AC_MSG_CHECKING(for type of signal functions)
AC_CACHE_VAL(bash_cv_signal_vintage,
[
  AC_TRY_LINK([#include <signal.h>],[
    sigset_t ss;
    struct sigaction sa;
    sigemptyset(&ss); sigsuspend(&ss);
    sigaction(SIGINT, &sa, (struct sigaction *) 0);
    sigprocmask(SIG_BLOCK, &ss, (sigset_t *) 0);
  ], bash_cv_signal_vintage=posix,
  [
    AC_TRY_LINK([#include <signal.h>], [
        int mask = sigmask(SIGINT);
        sigsetmask(mask); sigblock(mask); sigpause(mask);
    ], bash_cv_signal_vintage=4.2bsd,
    [
      AC_TRY_LINK([
        #include <signal.h>
        RETSIGTYPE foo() { }], [
                int mask = sigmask(SIGINT);
                sigset(SIGINT, foo); sigrelse(SIGINT);
                sighold(SIGINT); sigpause(SIGINT);
        ], bash_cv_signal_vintage=svr3, bash_cv_signal_vintage=v7
    )]
  )]
)
])
AC_MSG_RESULT($bash_cv_signal_vintage)
if test "$bash_cv_signal_vintage" = posix; then
AC_DEFINE(HAVE_POSIX_SIGNALS,,use sigprocmask, etc.)
elif test "$bash_cv_signal_vintage" = "4.2bsd"; then
AC_DEFINE(HAVE_BSD_SIGNALS,, use sigsetmask, etc.)
elif test "$bash_cv_signal_vintage" = svr3; then
AC_DEFINE(HAVE_USG_SIGHOLD,, use sigset, sighold, etc.)
fi
])

dnl
dnl This was stolen from readlin-4.0.
dnl
dnl

AC_DEFUN([BASH_CHECK_LIB_TERMCAP],
[
if test "X$bash_cv_termcap_lib" = "X"; then
_bash_needmsg=yes
else
AC_MSG_CHECKING(which library has the termcap functions)
_bash_needmsg=
fi
AC_CACHE_VAL(bash_cv_termcap_lib,
[AC_CHECK_LIB(termcap, tgetent, bash_cv_termcap_lib=libtermcap,
    [AC_CHECK_LIB(curses, tgetent, bash_cv_termcap_lib=libcurses,
	[AC_CHECK_LIB(ncurses, tgetent, bash_cv_termcap_lib=libncurses,
	    bash_cv_termcap_lib=gnutermcap)])])])
if test "X$_bash_needmsg" = "Xyes"; then
AC_MSG_CHECKING(which library has the termcap functions)
fi
AC_MSG_RESULT(using $bash_cv_termcap_lib)
if test $bash_cv_termcap_lib = gnutermcap && test -z "$prefer_curses"; then
LDFLAGS="$LDFLAGS -L./lib/termcap"
TERMCAP_LIB="./lib/termcap/libtermcap.a"
TERMCAP_DEP="./lib/termcap/libtermcap.a"
elif test $bash_cv_termcap_lib = libtermcap && test -z "$prefer_curses"; then
TERMCAP_LIB=-ltermcap
TERMCAP_DEP=
elif test $bash_cv_termcap_lib = libncurses; then
TERMCAP_LIB=-lncurses
TERMCAP_DEP=
else
TERMCAP_LIB=-lcurses
TERMCAP_DEP=
fi
])


dnl Stolen from the autoconf archive
dnl @synopsis AC_CXX_NAMESPACES
dnl
dnl If the compiler can prevent names clashes using namespaces, define
dnl HAVE_NAMESPACES.
dnl
dnl @version $Id: acinclude.m4 1403 2005-08-29 12:57:28Z hines $
dnl @author Luc Maisonobe
dnl
AC_DEFUN([AC_CXX_NAMESPACES],
[AC_CACHE_CHECK(whether the compiler implements namespaces,
ac_cv_cxx_namespaces,
[AC_LANG_SAVE
 AC_LANG_CPLUSPLUS
 AC_TRY_COMPILE([namespace Outer { namespace Inner { int i = 0; }}],
                [using namespace Outer::Inner; return i;],
 ac_cv_cxx_namespaces=yes, ac_cv_cxx_namespaces=no)
 AC_LANG_RESTORE
])
if test "$ac_cv_cxx_namespaces" = yes; then
  AC_DEFINE(HAVE_NAMESPACES,,[define if the compiler implements namespaces])
fi
])


dnl @synopsis AC_CXX_HAVE_STL
dnl
dnl If the compiler supports the Standard Template Library, define HAVE_STL.
dnl
dnl @version $Id: acinclude.m4 1403 2005-08-29 12:57:28Z hines $
dnl @author Luc Maisonobe
dnl
AC_DEFUN([AC_CXX_HAVE_STL],
[AC_CACHE_CHECK(whether the compiler supports Standard Template Library,
ac_cv_cxx_have_stl,
[AC_REQUIRE([AC_CXX_NAMESPACES])
 AC_LANG_SAVE
 AC_LANG_CPLUSPLUS
 AC_TRY_COMPILE([#include <list>
#include <deque>
#ifdef HAVE_NAMESPACES
using namespace std;
#endif],[list<int> x; x.push_back(5);
list<int>::iterator iter = x.begin(); if (iter != x.end()) ++iter; return 0;],
 ac_cv_cxx_have_stl=yes, ac_cv_cxx_have_stl=no)
 AC_LANG_RESTORE
])
if test "$ac_cv_cxx_have_stl" = yes; then
  AC_DEFINE(HAVE_STL,,[define if the compiler supports Standard Template Library])
fi
])

dnl If the C++ library has a working stringstream, define HAVE_SSTREAM
dnl Ben Stanley 
dnl 1.1 (2001/03/16)

AC_DEFUN([AC_CXX_HAVE_SSTREAM],
[AC_CACHE_CHECK(whether the compiler has stringstream,
ac_cv_cxx_have_sstream,
[AC_REQUIRE([AC_CXX_NAMESPACES])
 AC_LANG_SAVE
 AC_LANG_CPLUSPLUS
 AC_TRY_COMPILE([#include <sstream>
#ifdef HAVE_NAMESPACES
using namespace std;
#endif],[stringstream message; message << "Hello"; return 0;],
 ac_cv_cxx_have_sstream=yes, ac_cv_cxx_have_sstream=no)
 AC_LANG_RESTORE
])
if test "$ac_cv_cxx_have_sstream" = yes; then
  AC_DEFINE(HAVE_SSTREAM,,[define if the compiler has stringstream])
fi
])

dnl decide whether to use std::fabs or ::fabs or declare it explicitly
AC_DEFUN([NRN_FABS],[
 AC_LANG_SAVE
 AC_LANG_CPLUSPLUS
 AC_TRY_COMPILE([
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define myfabs ::fabs
 ],[
	double d;
	d = -25.0;
	d = myfabs(d);
	return (d == 25.0)?0:1;
 ],
	ivos_fabs="::fabs" , ivos_fabs=""
 )
 if test "$ivos_fabs" = "" ; then
   AC_TRY_COMPILE([
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define myfabs std::fabs
   ],[
	double d;
	d = -25.0;
	d = myfabs(d);
	return (d == 25.0)?0:1;
   ],
	ivos_fabs="std::fabs" , ivos_fabs=""
   )
 fi
 if test "$ivos_fabs" != "" ; then
	AC_DEFINE_UNQUOTED(IVOS_FABS,$ivos_fabs,[undefined or ::fabs or std::fabs])
 fi
 AC_LANG_RESTORE
])dnl

