# $Id: GNUmakefile,v 1.2 2008-12-03 07:43:41 kmura Exp $
# $Name: geant4-09-04-patch-02 $
# ===========================================================
#   Makefile for building Geant4Py
# ===========================================================
include  ./config/config.gmk

SUBDIR := source site-modules

.PHONY: all install clean uninstall

all:
	@for dir in $(SUBDIR); do (cd $$dir && $(MAKE)); done;:

install:
	@for dir in $(SUBDIR); do (cd $$dir && $(MAKE) install); done;:

clean:
	@for dir in $(SUBDIR); do (cd $$dir && $(MAKE) clean); done;:

uninstall:
	@-\rm -f -r $(Q_LIBDIR)

