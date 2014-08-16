#############################################################################
# Makefile for building: connectfour
# Generated by qmake (2.01a) (Qt 4.8.1) on: Sat Aug 16 12:06:26 2014
# Project:  connectfour.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile connectfour.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_SQL_LIB -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4/QtSql -I/usr/include/qt4 -I/usr/X11R6/include -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -L/usr/X11R6/lib64 -lQtSql -lQtOpenGL -lQtGui -lQtNetwork -lQtCore -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

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
		gameboardrenderer.cpp moc_settingswidget.cpp \
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
		moc_aigamemanager.cpp
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
		moc_aigamemanager.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		connectfour.pro
QMAKE_TARGET  = connectfour
DESTDIR       = 
TARGET        = connectfour

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

all: Makefile $(TARGET)

$(TARGET): ui_settingswidget.h ui_gameoverscreen.h ui_mainwindow.h ui_gameresults.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: connectfour.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtSql.prl \
		/usr/lib/x86_64-linux-gnu/libQtOpenGL.prl \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtNetwork.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile connectfour.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/opengl.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtSql.prl:
/usr/lib/x86_64-linux-gnu/libQtOpenGL.prl:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtNetwork.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile connectfour.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/connectfour1.0.0 || $(MKDIR) .tmp/connectfour1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/connectfour1.0.0/ && $(COPY_FILE) --parents coin.h boardcolumn.h settingswidget.h gamerenderer.h gamemanager.h gameoverscreen.h gameboard.h player.h gameboardrenderer.h gamecoinrenderer.h renderobject.h connectfourobject.h connectfourrenderobject.h helper.h animation.h mainwindow.h settings.h gamedatabase.h gameserver.h tcpgamemanager.h gameclient.h networkadapter.h game.h gameresults.h aigamemanager.h minmax.h .tmp/connectfour1.0.0/ && $(COPY_FILE) --parents main.cpp settingswidget.cpp gamerenderer.cpp gamemanager.cpp gameoverscreen.cpp gamecoinrenderer.cpp mainwindow.cpp gameboard.cpp gamedatabase.cpp gameserver.cpp tcpgamemanager.cpp gameclient.cpp networkadapter.cpp gameresults.cpp aigamemanager.cpp gameboardrenderer.cpp .tmp/connectfour1.0.0/ && $(COPY_FILE) --parents settingswidget.ui gameoverscreen.ui mainwindow.ui gameresults.ui .tmp/connectfour1.0.0/ && (cd `dirname .tmp/connectfour1.0.0` && $(TAR) connectfour1.0.0.tar connectfour1.0.0 && $(COMPRESS) connectfour1.0.0.tar) && $(MOVE) `dirname .tmp/connectfour1.0.0`/connectfour1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/connectfour1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_settingswidget.cpp moc_gamerenderer.cpp moc_gamemanager.cpp moc_gameoverscreen.cpp moc_gameboard.cpp moc_mainwindow.cpp moc_gamedatabase.cpp moc_gameserver.cpp moc_tcpgamemanager.cpp moc_gameclient.cpp moc_networkadapter.cpp moc_gameresults.cpp moc_aigamemanager.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_settingswidget.cpp moc_gamerenderer.cpp moc_gamemanager.cpp moc_gameoverscreen.cpp moc_gameboard.cpp moc_mainwindow.cpp moc_gamedatabase.cpp moc_gameserver.cpp moc_tcpgamemanager.cpp moc_gameclient.cpp moc_networkadapter.cpp moc_gameresults.cpp moc_aigamemanager.cpp
moc_settingswidget.cpp: settings.h \
		settingswidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) settingswidget.h -o moc_settingswidget.cpp

moc_gamerenderer.cpp: gameboardrenderer.h \
		connectfourrenderobject.h \
		connectfourobject.h \
		renderobject.h \
		gameboard.h \
		coin.h \
		game.h \
		player.h \
		helper.h \
		boardcolumn.h \
		gamecoinrenderer.h \
		animation.h \
		gamerenderer.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) gamerenderer.h -o moc_gamerenderer.cpp

moc_gamemanager.cpp: game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		settings.h \
		gamemanager.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) gamemanager.h -o moc_gamemanager.cpp

moc_gameoverscreen.cpp: gameoverscreen.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) gameoverscreen.h -o moc_gameoverscreen.cpp

moc_gameboard.cpp: coin.h \
		game.h \
		player.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gameboard.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) gameboard.h -o moc_gameboard.cpp

moc_mainwindow.cpp: gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		settings.h \
		settingswidget.h \
		gameresults.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_gamedatabase.cpp: game.h \
		player.h \
		coin.h \
		gamedatabase.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) gamedatabase.h -o moc_gamedatabase.cpp

moc_gameserver.cpp: networkadapter.h \
		gameserver.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) gameserver.h -o moc_gameserver.cpp

moc_tcpgamemanager.cpp: gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		settings.h \
		networkadapter.h \
		tcpgamemanager.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) tcpgamemanager.h -o moc_tcpgamemanager.cpp

moc_gameclient.cpp: networkadapter.h \
		gameclient.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) gameclient.h -o moc_gameclient.cpp

moc_networkadapter.cpp: networkadapter.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) networkadapter.h -o moc_networkadapter.cpp

moc_gameresults.cpp: gameresults.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) gameresults.h -o moc_gameresults.cpp

moc_aigamemanager.cpp: gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		settings.h \
		aigamemanager.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) aigamemanager.h -o moc_aigamemanager.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_settingswidget.h ui_gameoverscreen.h ui_mainwindow.h ui_gameresults.h
compiler_uic_clean:
	-$(DEL_FILE) ui_settingswidget.h ui_gameoverscreen.h ui_mainwindow.h ui_gameresults.h
ui_settingswidget.h: settingswidget.ui
	/usr/bin/uic-qt4 settingswidget.ui -o ui_settingswidget.h

ui_gameoverscreen.h: gameoverscreen.ui
	/usr/bin/uic-qt4 gameoverscreen.ui -o ui_gameoverscreen.h

ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

ui_gameresults.h: gameresults.ui
	/usr/bin/uic-qt4 gameresults.ui -o ui_gameresults.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		settings.h \
		settingswidget.h \
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
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		settings.h \
		settingswidget.h \
		ui_settingswidget.h \
		gameserver.h \
		networkadapter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o settingswidget.o settingswidget.cpp

gamerenderer.o: gamerenderer.cpp gamerenderer.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		connectfourobject.h \
		renderobject.h \
		gameboard.h \
		coin.h \
		game.h \
		player.h \
		helper.h \
		boardcolumn.h \
		gamecoinrenderer.h \
		animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gamerenderer.o gamerenderer.cpp

gamemanager.o: gamemanager.cpp gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		settings.h \
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
		renderobject.h \
		helper.h \
		game.h \
		player.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gamecoinrenderer.o gamecoinrenderer.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		gamemanager.h \
		game.h \
		player.h \
		coin.h \
		gameboard.h \
		helper.h \
		boardcolumn.h \
		connectfourobject.h \
		gamerenderer.h \
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		settings.h \
		settingswidget.h \
		gameresults.h \
		ui_mainwindow.h \
		tcpgamemanager.h \
		networkadapter.h \
		aigamemanager.h
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
		networkadapter.h
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
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		settings.h \
		networkadapter.h \
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
		gameboardrenderer.h \
		connectfourrenderobject.h \
		renderobject.h \
		gamecoinrenderer.h \
		animation.h \
		gameoverscreen.h \
		settings.h \
		minmax.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o aigamemanager.o aigamemanager.cpp

gameboardrenderer.o: gameboardrenderer.cpp gameboardrenderer.h \
		connectfourrenderobject.h \
		connectfourobject.h \
		renderobject.h \
		gameboard.h \
		coin.h \
		game.h \
		player.h \
		helper.h \
		boardcolumn.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gameboardrenderer.o gameboardrenderer.cpp

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

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/home/ska/uni/connectFour-qt/bin/connectfour/ || $(MKDIR) $(INSTALL_ROOT)/home/ska/uni/connectFour-qt/bin/connectfour/ 
	-$(INSTALL_PROGRAM) "$(QMAKE_TARGET)" "$(INSTALL_ROOT)/home/ska/uni/connectFour-qt/bin/connectfour/$(QMAKE_TARGET)"
	-$(STRIP) "$(INSTALL_ROOT)/home/ska/uni/connectFour-qt/bin/connectfour/$(QMAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/home/ska/uni/connectFour-qt/bin/connectfour/$(QMAKE_TARGET)"
	-$(DEL_DIR) $(INSTALL_ROOT)/home/ska/uni/connectFour-qt/bin/connectfour/ 


install:  install_target  FORCE

uninstall: uninstall_target   FORCE

FORCE:

