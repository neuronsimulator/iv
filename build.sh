#!/bin/sh
# how to build from just the cvs sources

ltarg="-i"
if test -f "`which glibtoolize`" ; then
	ltver=`glibtoolize --version | sed -n '1s/.* \([0-9]\).*/\1/p'`
	if test "${ltver}" = 1 ; then ltarg="" ; fi
	echo "glibtoolize -c -f $ltarg"
	glibtoolize -c -f $ltarg
else
	ltver=`libtoolize --version | sed -n '1s/.* \([0-9]\).*/\1/p'`
	if test "${ltver}" = 1 ; then ltarg="" ; fi
	echo "libtoolize -c -f $ltarg"
	libtoolize -c -f $ltarg
fi
    
#fix ltmain for cygwin to allow dlls
sed '/undefined on the libtool link/,/allow_undefined/s/allow_undefined=yes/allow_undefined=no/' ltmain.sh > temp
mv temp ltmain.sh
chmod 755 ltmain.sh

aclocal
autoheader
autoconf

#./configure --prefix=`pwd`
# make
# make install

