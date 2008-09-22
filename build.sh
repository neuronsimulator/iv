#!/bin/sh
# how to build from just the cvs sources

if test -f /usr/bin/glibtoolize ; then
	glibtoolize -c -f
else
	libtoolize -c -f
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

