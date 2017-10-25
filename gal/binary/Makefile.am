# Process this with automake to produce Makefile.in
# @author: Fellipe Adorno C. da Costa <fellipeac2@gmail.com>

lib_LTLIBRARIES = libgal_binary.la

libgal_binary_la_SOURCES =

libgal_binaryincludedir = $(includedir)/gal/binary

libgal_binaryinclude_HEADERS = \
	chrm_binary.hpp \
	pop_binary.hpp

libgal_binary_la_LDFLAGS = -version-info 0:0:0
#libXXXX_la_LDFLAGS = -version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)
#    1. Start with version information of `0:0:0' for each libtool library.
#
#    2. Update the version information only immediately before a public
#       release of your software.  More frequent updates are unnecessary,
#       and only guarantee that the current interface number gets larger
#       faster.
#
#    3. If the library source code has changed at all since the last
#       update, then increment REVISION (`C:R:A' becomes `C:r+1:A').
#
#    4. If any interfaces have been added, removed, or changed since the
#       last update, increment CURRENT, and set REVISION to 0.
#
#    5. If any interfaces have been added since the last public release,
#       then increment AGE.
#
#    6. If any interfaces have been removed since the last public release,
#       then set AGE to 0



AM_CPPFLAGS = -I$(top_srcdir)
AM_CFLAGS = -W -Wall -std=c++0x
AM_CXXFLAGS = -W -Wall -std=c++11
AM_LDFLAGS = #-lboost_system-mt


CLEANFILES = *~

