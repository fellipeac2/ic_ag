# Process this file with automake to produce Makefile.in
# This aims create a automake file config to use in src directory.
#
# Author: Fellipe Adorno C. da Costa <fellipeac2@gmail.com>

# todas os programas são noinst (nao instalavel)


SAMPLE_GASOURCES = \
    evaluation.cpp \
	sample_ga.cpp 
MAINSOURCES = \
	main.cpp

SAMPLE_GAHEADERS = \
    evaluation.h

MAINHEADERS = 

noinst_PROGRAMS = \
	sample_ga \
	main

noinst_DATA = 

noinst_HEADERS =
	$(SAMPLE_GAHEADERS) \
	$(MAINHEADERS)

sample_ga_SOURCES = \
	$(SAMPLE_GASOURCES)

sample_ga_CXXFLAGS = -W -Wall -std=c++11
sample_ga_LDFLAGS =
sample_ga_LDADD = $(top_srcdir)/gal/libgal.la #$(top_srcdir)/sllc/pool/libsllc_pool.la $(top_srcdir)/sllc/post/libsllc_post.la

main_SOURCES = \
	$(MAINSOURCES)
main_CXXFLAGS = -W -Wall -std=c++11
main_LDFLAGS =
main_cd =

AM_CPPFLAGS = #-I$(top_srcdir)/src  #-I$(top_srcdir)/src/subdirectory
AM_CFLAGS = -W -Wall -std=c++11
AM_CXXFLAGS = -W -Wall
AM_LDLAGS =

CLEANFILES = core *~
DISTCLEANFILES =
EXTRA_DIST = $(noinst_DATA)


