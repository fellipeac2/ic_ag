## Process this file with automake to produce Makefile.in

ACLOCAL_AMFLAGS=-I m4

SUBDIRS = gal src .

LIBTOOL_DEPS = @LIBTOOL_DEPS@
libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status --recheck

doc:
	@DOXYGEN@

clean-doc:
	-rm -rf doc

distclean-local:
	-rm -rf doc

EXTRA_DIST = 

CLEANFILES = \
	*~

