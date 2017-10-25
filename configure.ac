# Process this file with autoconf to produce a configuration script
# author: Fellipe Adorno C. da Costa <fellipeac2@gmail.com>

AC_PREREQ(2.61)
LT_PREREQ(2.2)
AC_INIT([ic_ag], [0.0.1], [fellipeac2@gmail.com])

AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_MACRO_DIR([m4])

# ----------------------------------------------------

#AM_INIT_AUTOMAKE#([gnu check-news])
AM_INIT_AUTOMAKE([gnu])
#AM_CONFIG_HEADERS([config.h])
AC_LANG([C++])

# ----------------------------------------------------

#LT_INIT([shared disable-static])
LT_PREREQ([2.2])
LT_INIT([static disable-shared])
LT_LANG([C++])
AC_SUBST(LIBTOOL_DEPS)

# ----------------------------------------------------

AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

# ----------------------------------------------------

CPPFLAGS="$CPPFLAGS"
LDFLAGS="$LDFLAGS"

# ----------------------------------------------------

AC_CHECK_HEADER_STDBOOL
AC_CHECK_FUNCS([pow])
AC_CHECK_FUNCS([sqrt])
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T
AC_CONFIG_FILES([Makefile
		gal/Makefile
		gal/binary/Makefile
		src/Makefile])

AC_OUTPUT

