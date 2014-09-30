#############################################################################
# Makefile for building: connectfour.app/Contents/MacOS/connectfour
# Generated by qmake (2.01a) (Qt 4.8.6) on: Tue Sep 30 21:11:53 2014
# Project:  connectfour.pro
# Template: app
# Command: /usr/local/bin/qmake -o Makefile connectfour.pro
#############################################################################

####### Compiler, tools and options

CC            = clang
CXX           = clang++
DEFINES       = -DQT_NO_DEBUG -DQT_MULTIMEDIA_LIB -DQT_SQL_LIB -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -mmacosx-version-min=10.7 -O2 -arch x86_64 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -stdlib=libc++ -mmacosx-version-min=10.7 -O2 -arch x86_64 -Wall -W $(DEFINES)
INCPATH       = -I/usr/local/Cellar/qt/4.8.5/mkspecs/unsupported/macx-clang-libc++ -I. -I/usr/local/Cellar/qt/4.8.5/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtNetwork.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtNetwork.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtOpenGL.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtOpenGL.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtSql.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtSql.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtMultimedia.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtMultimedia.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/include -I/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I/System/Library/Frameworks/AGL.framework/Headers -I. -I. -F/usr/local/Cellar/qt/4.8.5/lib
LINK          = clang++
LFLAGS        = -headerpad_max_install_names -stdlib=libc++ -mmacosx-version-min=10.7 -arch x86_64
LIBS          = $(SUBLIBS) -F/usr/local/Cellar/qt/4.8.5/lib -L/usr/local/Cellar/qt/4.8.5/lib -framework QtMultimedia -L/opt/X11/lib -L/usr/local/Cellar/qt/4.8.5/lib -F/usr/local/Cellar/qt/4.8.5/lib -framework ApplicationServices -framework CoreAudio -framework AudioUnit -framework AudioToolbox -framework QtGui -framework QtCore -framework QtSql -framework QtOpenGL -framework QtNetwork -framework OpenGL -framework AGL 
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /usr/local/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.7

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		settingswidget.cpp \
		gamerenderer.cpp \
		gamemanager.cpp \
		gameoverscreen.cpp \
		gamecoinrenderer.cpp \
		mainwindow.cpp \
		gameboard.cpp \
		gamedatabase.cpp \
		gameserver.cpp \
		tcpgamemanager.cpp \
		gameclient.cpp \
		networkadapter.cpp \
		gameresults.cpp \
		aigamemanager.cpp \
		gameboardrenderer.cpp \
		gameaudiomanager.cpp \
		chatwidget.cpp \
		serversearch.cpp \
		serversearchlistener.cpp moc_settingswidget.cpp \
		moc_gamerenderer.cpp \
		moc_gamemanager.cpp \
		moc_gameoverscreen.cpp \
		moc_gameboard.cpp \
		moc_mainwindow.cpp \
		moc_gamedatabase.cpp \
		moc_gameserver.cpp \
		moc_tcpgamemanager.cpp \
		moc_gameclient.cpp \
		moc_networkadapter.cpp \
		moc_gameresults.cpp \
		moc_aigamemanager.cpp \
		moc_gameaudiomanager.cpp \
		moc_chatwidget.cpp \
		moc_serversearch.cpp \
		moc_serversearchlistener.cpp \
		qrc_sounds.cpp \
		qrc_translations.cpp
OBJECTS       = main.o \
		settingswidget.o \
		gamerenderer.o \
		gamemanager.o \
		gameoverscreen.o \
		gamecoinrenderer.o \
		mainwindow.o \
		gameboard.o \
		gamedatabase.o \
		gameserver.o \
		tcpgamemanager.o \
		gameclient.o \
		networkadapter.o \
		gameresults.o \
		aigamemanager.o \
		gameboardrenderer.o \
		gameaudiomanager.o \
		chatwidget.o \
		serversearch.o \
		serversearchlistener.o \
		moc_settingswidget.o \
		moc_gamerenderer.o \
		moc_gamemanager.o \
		moc_gameoverscreen.o \
		moc_gameboard.o \
		moc_mainwindow.o \
		moc_gamedatabase.o \
		moc_gameserver.o \
		moc_tcpgamemanager.o \
		moc_gameclient.o \
		moc_networkadapter.o \
		moc_gameresults.o \
		moc_aigamemanager.o \
		moc_gameaudiomanager.o \
		moc_chatwidget.o \
		moc_serversearch.o \
		moc_serversearchlistener.o \
		qrc_sounds.o \
		qrc_translations.o
DIST          = /usr/local/Cellar/qt/4.8.5/mkspecs/common/unix.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/mac.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/clang.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/qconfig.pri \
		/usr/local/Cellar/qt/4.8.5/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_functions.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_config.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/exclusive_builds.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_pre.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_pre.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/release.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_post.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_post.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/x86_64.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/objective_c.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/shared.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/warn_on.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/unix/opengl.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/unix/thread.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/moc.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/rez.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/sdk.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/resources.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/uic.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/yacc.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/lex.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/include_source_dir.prf \
		connectfour.pro
QMAKE_TARGET  = connectfour
DESTDIR       = 
TARGET        = connectfour.app/Contents/MacOS/connectfour

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-O2 \
		-arch \
		x86_64 \
		-Wall \
		-W


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile connectfour.app/Contents/PkgInfo connectfour.app/Contents/Resources/empty.lproj connectfour.app/Contents/Info.plist $(TARGET)

$(TARGET): ui_settingswidget.h ui_gameoverscreen.h ui_mainwindow.h ui_gameresults.h ui_chatwidget.h ui_serversearch.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) connectfour.app/Contents/MacOS/ || $(MKDIR) connectfour.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: connectfour.pro  /usr/local/Cellar/qt/4.8.5/mkspecs/unsupported/macx-clang-libc++/qmake.conf /usr/local/Cellar/qt/4.8.5/mkspecs/common/unix.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/mac.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/clang.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/qconfig.pri \
		/usr/local/Cellar/qt/4.8.5/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_functions.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_config.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/exclusive_builds.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_pre.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_pre.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/release.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_post.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_post.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/x86_64.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/objective_c.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/shared.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/warn_on.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/unix/opengl.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/unix/thread.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/moc.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/rez.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/sdk.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/resources.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/uic.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/yacc.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/lex.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/include_source_dir.prf \
		/usr/local/Cellar/qt/4.8.5/lib/QtMultimedia.framework/QtMultimedia.prl \
		/usr/local/Cellar/qt/4.8.5/lib/QtGui.framework/QtGui.prl \
		/usr/local/Cellar/qt/4.8.5/lib/QtCore.framework/QtCore.prl \
		/usr/local/Cellar/qt/4.8.5/lib/QtSql.framework/QtSql.prl \
		/usr/local/Cellar/qt/4.8.5/lib/QtOpenGL.framework/QtOpenGL.prl \
		/usr/local/Cellar/qt/4.8.5/lib/QtNetwork.framework/QtNetwork.prl
	$(QMAKE) -o Makefile connectfour.pro
/usr/local/Cellar/qt/4.8.5/mkspecs/common/unix.conf:
/usr/local/Cellar/qt/4.8.5/mkspecs/common/mac.conf:
/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base.conf:
/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base-macx.conf:
/usr/local/Cellar/qt/4.8.5/mkspecs/common/clang.conf:
/usr/local/Cellar/qt/4.8.5/mkspecs/qconfig.pri:
/usr/local/Cellar/qt/4.8.5/mkspecs/modules/qt_webkit_version.pri:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_functions.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_config.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/exclusive_builds.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_pre.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_pre.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/release.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_post.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_post.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/x86_64.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/objective_c.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/shared.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/warn_on.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/unix/opengl.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/unix/thread.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/moc.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/rez.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/sdk.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/resources.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/uic.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/yacc.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/lex.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/include_source_dir.prf:
/usr/local/Cellar/qt/4.8.5/lib/QtMultimedia.framework/QtMultimedia.prl:
/usr/local/Cellar/qt/4.8.5/lib/QtGui.framework/QtGui.prl:
/usr/local/Cellar/qt/4.8.5/lib/QtCore.framework/QtCore.prl:
/usr/local/Cellar/qt/4.8.5/lib/QtSql.framework/QtSql.prl:
/usr/local/Cellar/qt/4.8.5/lib/QtOpenGL.framework/QtOpenGL.prl:
/usr/local/Cellar/qt/4.8.5/lib/QtNetwork.framework/QtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile connectfour.pro

connectfour.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) connectfour.app/Contents || $(MKDIR) connectfour.app/Contents 
	@$(DEL_FILE) connectfour.app/Contents/PkgInfo
	@echo "APPL????" >connectfour.app/Contents/PkgInfo
connectfour.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) connectfour.app/Contents/Resources || $(MKDIR) connectfour.app/Contents/Resources 
	@touch connectfour.app/Contents/Resources/empty.lproj
	
connectfour.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) connectfour.app/Contents || $(MKDIR) connectfour.app/Contents 
	@$(DEL_FILE) connectfour.app/Contents/Info.plist
	@sed -e "s,@SHORT_VERSION@,1.0,g" -e "s,@TYPEINFO@,????,g" -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,connectfour,g" -e "s,@TYPEINFO@,????,g" /usr/local/Cellar/qt/4.8.5/mkspecs/unsupported/macx-clang-libc++/Info.plist.app >connectfour.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) .tmp/connectfour1.0.0 || $(MKDIR) .tmp/connectfour1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/connectfour1.0.0/ && $(COPY_FILE) --parents coin.h boardcolumn.h settingswidget.h gamerenderer.h gamemanager.h gameoverscreen.h gameboard.h player.h gameboardrenderer.h gamecoinrenderer.h renderobject.h connectfourobject.h connectfourrenderobject.h helper.h animation.h mainwindow.h settings.h gamedatabase.h gameserver.h tcpgamemanager.h gameclient.h networkadapter.h game.h gameresults.h aigamemanager.h minmax.h gameaudiomanager.h chatwidget.h serversearch.h serversearchlistener.h .tmp/connectfour1.0.0/ && $(COPY_FILE) --parents sounds.qrc translations.qrc .tmp/connectfour1.0.0/ && $(COPY_FILE) --parents main.cpp settingswidget.cpp gamerenderer.cpp gamemanager.cpp gameoverscreen.cpp gamecoinrenderer.cpp mainwindow.cpp gameboard.cpp gamedatabase.cpp gameserver.cpp tcpgamemanager.cpp gameclient.cpp networkadapter.cpp gameresults.cpp aigamemanager.cpp gameboardrenderer.cpp gameaudiomanager.cpp chatwidget.cpp serversearch.cpp serversearchlistener.cpp .tmp/connectfour1.0.0/ && $(COPY_FILE) --parents settingswidget.ui gameoverscreen.ui mainwindow.ui gameresults.ui chatwidget.ui serversearch.ui .tmp/connectfour1.0.0/ && $(COPY_FILE) --parents connectfour_de_DE.ts .tmp/connectfour1.0.0/ && (cd `dirname .tmp/connectfour1.0.0` && $(TAR) connectfour1.0.0.tar connectfour1.0.0 && $(COMPRESS) connectfour1.0.0.tar) && $(MOVE) `dirname .tmp/connectfour1.0.0`/connectfour1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/connectfour1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r connectfour.app
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_settingswidget.cpp moc_gamerenderer.cpp moc_gamemanager.cpp moc_gameoverscreen.cpp moc_gameboard.cpp moc_mainwindow.cpp moc_gamedatabase.cpp moc_gameserver.cpp moc_tcpgamemanager.cpp moc_gameclient.cpp moc_networkadapter.cpp moc_gameresults.cpp moc_aigamemanager.cpp moc_gameaudiomanager.cpp moc_chatwidget.cpp moc_serversearch.cpp moc_serversearchlistener.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_settingswidget.cpp moc_gamerenderer.cpp moc_gamemanager.cpp moc_gameoverscreen.cpp moc_gameboard.cpp moc_mainwindow.cpp moc_gamedatabase.cpp moc_gameserver.cpp moc_tcpgamemanager.cpp moc_gameclient.cpp moc_networkadapter.cpp moc_gameresults.cpp moc_aigamemanager.cpp moc_gameaudiomanager.cpp moc_chatwidget.cpp moc_serversearch.cpp moc_serversearchlistener.cpp
moc_settingswidget.cpp: settings.h \
		settingswidget.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ settingswidget.h -o moc_settingswidget.cpp

moc_gamerenderer.cpp: settings.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		connectfourobject.h \
		helper.h \
		coin.h \
		game.h \
		player.h \
		renderobject.h \
		gameboard.h \
		boardcolumn.h \
		gamecoinrenderer.h \
		animation.h \
		gamerenderer.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ gamerenderer.h -o moc_gamerenderer.cpp

moc_gamemanager.cpp: game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		settings.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		gamemanager.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ gamemanager.h -o moc_gamemanager.cpp

moc_gameoverscreen.cpp: gameoverscreen.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ gameoverscreen.h -o moc_gameoverscreen.cpp

moc_gameboard.cpp: coin.h \
		game.h \
		player.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gameboard.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ gameboard.h -o moc_gameboard.cpp

moc_mainwindow.cpp: chatwidget.h \
		tcpgamemanager.h \
		gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		settings.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		networkadapter.h \
		serversearchlistener.h \
		settingswidget.h \
		serversearch.h \
		gameresults.h \
		mainwindow.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ mainwindow.h -o moc_mainwindow.cpp

moc_gamedatabase.cpp: game.h \
		player.h \
		coin.h \
		gamedatabase.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ gamedatabase.h -o moc_gamedatabase.cpp

moc_gameserver.cpp: networkadapter.h \
		gameserver.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ gameserver.h -o moc_gameserver.cpp

moc_tcpgamemanager.cpp: gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		settings.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		networkadapter.h \
		serversearchlistener.h \
		tcpgamemanager.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ tcpgamemanager.h -o moc_tcpgamemanager.cpp

moc_gameclient.cpp: networkadapter.h \
		gameclient.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ gameclient.h -o moc_gameclient.cpp

moc_networkadapter.cpp: networkadapter.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ networkadapter.h -o moc_networkadapter.cpp

moc_gameresults.cpp: gameresults.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ gameresults.h -o moc_gameresults.cpp

moc_aigamemanager.cpp: gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		settings.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		minmax.h \
		aigamemanager.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ aigamemanager.h -o moc_aigamemanager.cpp

moc_gameaudiomanager.cpp: gameaudiomanager.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ gameaudiomanager.h -o moc_gameaudiomanager.cpp

moc_chatwidget.cpp: tcpgamemanager.h \
		gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		settings.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		networkadapter.h \
		serversearchlistener.h \
		chatwidget.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ chatwidget.h -o moc_chatwidget.cpp

moc_serversearch.cpp: serversearch.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ serversearch.h -o moc_serversearch.cpp

moc_serversearchlistener.cpp: serversearchlistener.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ serversearchlistener.h -o moc_serversearchlistener.cpp

compiler_rcc_make_all: qrc_sounds.cpp qrc_translations.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_sounds.cpp qrc_translations.cpp
qrc_sounds.cpp: sounds.qrc \
		win_red.wav \
		coin_drop.wav \
		win_yellow.wav \
		on_connect.wav \
		illegal_move.wav
	/usr/local/Cellar/qt/4.8.5/bin/rcc -name sounds sounds.qrc -o qrc_sounds.cpp

qrc_translations.cpp: translations.qrc \
		connectfour_de_DE.qm
	/usr/local/Cellar/qt/4.8.5/bin/rcc -name translations translations.qrc -o qrc_translations.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all: ui_settingswidget.h ui_gameoverscreen.h ui_mainwindow.h ui_gameresults.h ui_chatwidget.h ui_serversearch.h
compiler_uic_clean:
	-$(DEL_FILE) ui_settingswidget.h ui_gameoverscreen.h ui_mainwindow.h ui_gameresults.h ui_chatwidget.h ui_serversearch.h
ui_settingswidget.h: settingswidget.ui
	/usr/local/Cellar/qt/4.8.5/bin/uic settingswidget.ui -o ui_settingswidget.h

ui_gameoverscreen.h: gameoverscreen.ui
	/usr/local/Cellar/qt/4.8.5/bin/uic gameoverscreen.ui -o ui_gameoverscreen.h

ui_mainwindow.h: mainwindow.ui
	/usr/local/Cellar/qt/4.8.5/bin/uic mainwindow.ui -o ui_mainwindow.h

ui_gameresults.h: gameresults.ui
	/usr/local/Cellar/qt/4.8.5/bin/uic gameresults.ui -o ui_gameresults.h

ui_chatwidget.h: chatwidget.ui
	/usr/local/Cellar/qt/4.8.5/bin/uic chatwidget.ui -o ui_chatwidget.h

ui_serversearch.h: serversearch.ui
	/usr/local/Cellar/qt/4.8.5/bin/uic serversearch.ui -o ui_serversearch.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		chatwidget.h \
		tcpgamemanager.h \
		gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		settings.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		networkadapter.h \
		serversearchlistener.h \
		settingswidget.h \
		serversearch.h \
		gameresults.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

settingswidget.o: settingswidget.cpp gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		settings.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		settingswidget.h \
		ui_settingswidget.h \
		gameserver.h \
		networkadapter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o settingswidget.o settingswidget.cpp

gamerenderer.o: gamerenderer.cpp gamerenderer.h \
		settings.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		connectfourobject.h \
		helper.h \
		coin.h \
		game.h \
		player.h \
		renderobject.h \
		gameboard.h \
		boardcolumn.h \
		gamecoinrenderer.h \
		animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gamerenderer.o gamerenderer.cpp

gamemanager.o: gamemanager.cpp gameaudiomanager.h \
		gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		settings.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		gameclient.h \
		networkadapter.h \
		gamedatabase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gamemanager.o gamemanager.cpp

gameoverscreen.o: gameoverscreen.cpp gameoverscreen.h \
		ui_gameoverscreen.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gameoverscreen.o gameoverscreen.cpp

gamecoinrenderer.o: gamecoinrenderer.cpp gamecoinrenderer.h \
		animation.h \
		coin.h \
		boardcolumn.h \
		connectfourrenderobject.h \
		connectfourobject.h \
		helper.h \
		game.h \
		player.h \
		renderobject.h \
		settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gamecoinrenderer.o gamecoinrenderer.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		chatwidget.h \
		tcpgamemanager.h \
		gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		settings.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		networkadapter.h \
		serversearchlistener.h \
		settingswidget.h \
		serversearch.h \
		gameresults.h \
		ui_mainwindow.h \
		aigamemanager.h \
		minmax.h \
		gamedatabase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

gameboard.o: gameboard.cpp gameboard.h \
		coin.h \
		game.h \
		player.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gameboard.o gameboard.cpp

gamedatabase.o: gamedatabase.cpp game.h \
		player.h \
		coin.h \
		gamedatabase.h \
		helper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gamedatabase.o gamedatabase.cpp

gameserver.o: gameserver.cpp gameserver.h \
		networkadapter.h \
		gameaudiomanager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gameserver.o gameserver.cpp

tcpgamemanager.o: tcpgamemanager.cpp tcpgamemanager.h \
		gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		settings.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		networkadapter.h \
		serversearchlistener.h \
		gameaudiomanager.h \
		gameserver.h \
		gameclient.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tcpgamemanager.o tcpgamemanager.cpp

gameclient.o: gameclient.cpp gameclient.h \
		networkadapter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gameclient.o gameclient.cpp

networkadapter.o: networkadapter.cpp networkadapter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o networkadapter.o networkadapter.cpp

gameresults.o: gameresults.cpp gameresults.h \
		ui_gameresults.h \
		game.h \
		player.h \
		coin.h \
		gamedatabase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gameresults.o gameresults.cpp

aigamemanager.o: aigamemanager.cpp aigamemanager.h \
		gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		settings.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		minmax.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o aigamemanager.o aigamemanager.cpp

gameboardrenderer.o: gameboardrenderer.cpp gameboardrenderer.h \
		connectfourrenderobject.h \
		connectfourobject.h \
		helper.h \
		coin.h \
		game.h \
		player.h \
		renderobject.h \
		settings.h \
		gameboard.h \
		boardcolumn.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gameboardrenderer.o gameboardrenderer.cpp

gameaudiomanager.o: gameaudiomanager.cpp gameaudiomanager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gameaudiomanager.o gameaudiomanager.cpp

chatwidget.o: chatwidget.cpp chatwidget.h \
		tcpgamemanager.h \
		gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		settings.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		networkadapter.h \
		serversearchlistener.h \
		ui_chatwidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o chatwidget.o chatwidget.cpp

serversearch.o: serversearch.cpp serversearch.h \
		ui_serversearch.h \
		helper.h \
		coin.h \
		game.h \
		player.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o serversearch.o serversearch.cpp

serversearchlistener.o: serversearchlistener.cpp serversearchlistener.h \
		helper.h \
		coin.h \
		game.h \
		player.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o serversearchlistener.o serversearchlistener.cpp

moc_settingswidget.o: moc_settingswidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_settingswidget.o moc_settingswidget.cpp

moc_gamerenderer.o: moc_gamerenderer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gamerenderer.o moc_gamerenderer.cpp

moc_gamemanager.o: moc_gamemanager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gamemanager.o moc_gamemanager.cpp

moc_gameoverscreen.o: moc_gameoverscreen.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gameoverscreen.o moc_gameoverscreen.cpp

moc_gameboard.o: moc_gameboard.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gameboard.o moc_gameboard.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_gamedatabase.o: moc_gamedatabase.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gamedatabase.o moc_gamedatabase.cpp

moc_gameserver.o: moc_gameserver.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gameserver.o moc_gameserver.cpp

moc_tcpgamemanager.o: moc_tcpgamemanager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_tcpgamemanager.o moc_tcpgamemanager.cpp

moc_gameclient.o: moc_gameclient.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gameclient.o moc_gameclient.cpp

moc_networkadapter.o: moc_networkadapter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_networkadapter.o moc_networkadapter.cpp

moc_gameresults.o: moc_gameresults.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gameresults.o moc_gameresults.cpp

moc_aigamemanager.o: moc_aigamemanager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_aigamemanager.o moc_aigamemanager.cpp

moc_gameaudiomanager.o: moc_gameaudiomanager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gameaudiomanager.o moc_gameaudiomanager.cpp

moc_chatwidget.o: moc_chatwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_chatwidget.o moc_chatwidget.cpp

moc_serversearch.o: moc_serversearch.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_serversearch.o moc_serversearch.cpp

moc_serversearchlistener.o: moc_serversearchlistener.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_serversearchlistener.o moc_serversearchlistener.cpp

qrc_sounds.o: qrc_sounds.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_sounds.o qrc_sounds.cpp

qrc_translations.o: qrc_translations.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_translations.o qrc_translations.cpp

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/Users/onlyahost/Documents/HTWBerlin/MM\ Entwicklung/Final/connectfour/bin/connectfour/ || $(MKDIR) $(INSTALL_ROOT)/Users/onlyahost/Documents/HTWBerlin/MM\ Entwicklung/Final/connectfour/bin/connectfour/ 
	$(DEL_FILE) -r "$(INSTALL_ROOT)/Users/onlyahost/Documents/HTWBerlin/MM Entwicklung/Final/connectfour/bin/connectfour/connectfour.app"
	
	-$(INSTALL_DIR) "connectfour.app" "$(INSTALL_ROOT)/Users/onlyahost/Documents/HTWBerlin/MM Entwicklung/Final/connectfour/bin/connectfour/connectfour.app"

uninstall_target:  FORCE
	-$(DEL_FILE) -r "$(INSTALL_ROOT)/Users/onlyahost/Documents/HTWBerlin/MM Entwicklung/Final/connectfour/bin/connectfour/connectfour.app"
	-$(DEL_DIR) $(INSTALL_ROOT)/Users/onlyahost/Documents/HTWBerlin/MM\ Entwicklung/Final/connectfour/bin/connectfour/ 


install:  install_target  FORCE

uninstall: uninstall_target   FORCE

####### DOC

doc: FORCE
	doxygen Doxyfile

####### FORCE

FORCE:
