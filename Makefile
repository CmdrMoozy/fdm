#############################################################################
# Makefile for building: FDM
# Generated by qmake (2.01a) (Qt 4.7.3) on: Mon Jan 16 17:28:53 2012
# Project:  fdm.pro
# Template: app
# Command: c:\src\qt-4.7.3\bin\qmake.exe -o Makefile fdm.pro
#############################################################################

first: release
install: release-install
uninstall: release-uninstall
MAKEFILE      = Makefile
QMAKE         = c:\src\qt-4.7.3\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = move
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
SUBTARGETS    =  \
		release \
		debug

release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: fdm.pro  ..\qt-4.7.3\mkspecs\default\qmake.conf ..\qt-4.7.3\mkspecs\qconfig.pri \
		..\qt-4.7.3\mkspecs\features\qt_functions.prf \
		..\qt-4.7.3\mkspecs\features\qt_config.prf \
		..\qt-4.7.3\mkspecs\win32-msvc2010\qmake.conf \
		..\qt-4.7.3\mkspecs\features\exclusive_builds.prf \
		..\qt-4.7.3\mkspecs\features\default_pre.prf \
		..\qt-4.7.3\mkspecs\features\win32\default_pre.prf \
		..\qt-4.7.3\mkspecs\features\release.prf \
		..\qt-4.7.3\mkspecs\features\debug_and_release.prf \
		..\qt-4.7.3\mkspecs\features\default_post.prf \
		..\qt-4.7.3\mkspecs\features\win32\default_post.prf \
		..\qt-4.7.3\mkspecs\features\win32\console.prf \
		..\qt-4.7.3\mkspecs\features\win32\rtti.prf \
		..\qt-4.7.3\mkspecs\features\win32\exceptions.prf \
		..\qt-4.7.3\mkspecs\features\win32\stl.prf \
		..\qt-4.7.3\mkspecs\features\static.prf \
		..\qt-4.7.3\mkspecs\features\win32\embed_manifest_exe.prf \
		..\qt-4.7.3\mkspecs\features\win32\embed_manifest_dll.prf \
		..\qt-4.7.3\mkspecs\features\warn_on.prf \
		..\qt-4.7.3\mkspecs\features\qt.prf \
		..\qt-4.7.3\mkspecs\features\win32\thread.prf \
		..\qt-4.7.3\mkspecs\features\moc.prf \
		..\qt-4.7.3\mkspecs\features\resources.prf \
		..\qt-4.7.3\mkspecs\features\uic.prf \
		..\qt-4.7.3\mkspecs\features\yacc.prf \
		..\qt-4.7.3\mkspecs\features\lex.prf \
		..\qt-4.7.3\mkspecs\features\include_source_dir.prf \
		c:\src\qt-4.7.3\lib\QtGui.prl \
		c:\src\qt-4.7.3\lib\QtCore.prl
	$(QMAKE) -o Makefile fdm.pro
..\qt-4.7.3\mkspecs\qconfig.pri:
..\qt-4.7.3\mkspecs\features\qt_functions.prf:
..\qt-4.7.3\mkspecs\features\qt_config.prf:
..\qt-4.7.3\mkspecs\win32-msvc2010\qmake.conf:
..\qt-4.7.3\mkspecs\features\exclusive_builds.prf:
..\qt-4.7.3\mkspecs\features\default_pre.prf:
..\qt-4.7.3\mkspecs\features\win32\default_pre.prf:
..\qt-4.7.3\mkspecs\features\release.prf:
..\qt-4.7.3\mkspecs\features\debug_and_release.prf:
..\qt-4.7.3\mkspecs\features\default_post.prf:
..\qt-4.7.3\mkspecs\features\win32\default_post.prf:
..\qt-4.7.3\mkspecs\features\win32\console.prf:
..\qt-4.7.3\mkspecs\features\win32\rtti.prf:
..\qt-4.7.3\mkspecs\features\win32\exceptions.prf:
..\qt-4.7.3\mkspecs\features\win32\stl.prf:
..\qt-4.7.3\mkspecs\features\static.prf:
..\qt-4.7.3\mkspecs\features\win32\embed_manifest_exe.prf:
..\qt-4.7.3\mkspecs\features\win32\embed_manifest_dll.prf:
..\qt-4.7.3\mkspecs\features\warn_on.prf:
..\qt-4.7.3\mkspecs\features\qt.prf:
..\qt-4.7.3\mkspecs\features\win32\thread.prf:
..\qt-4.7.3\mkspecs\features\moc.prf:
..\qt-4.7.3\mkspecs\features\resources.prf:
..\qt-4.7.3\mkspecs\features\uic.prf:
..\qt-4.7.3\mkspecs\features\yacc.prf:
..\qt-4.7.3\mkspecs\features\lex.prf:
..\qt-4.7.3\mkspecs\features\include_source_dir.prf:
c:\src\qt-4.7.3\lib\QtGui.prl:
c:\src\qt-4.7.3\lib\QtCore.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -o Makefile fdm.pro

qmake_all: FORCE

make_default: release-make_default debug-make_default FORCE
make_first: release-make_first debug-make_first FORCE
all: release-all debug-all FORCE
clean: release-clean debug-clean FORCE
	-$(DEL_FILE) ".\FDM.intermediate.manifest"
distclean: release-distclean debug-distclean FORCE
	-$(DEL_FILE) Makefile

check: first

release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile
