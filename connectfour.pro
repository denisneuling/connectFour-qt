HEADERS       += \
    coin.h \
    boardcolumn.h \
    settingswidget.h \
    gamerenderer.h \
    gamemanager.h \
    gameoverscreen.h \
    gameboard.h \
    player.h \
    gameboardrenderer.h \
    gamecoinrenderer.h \
    renderobject.h \
    connectfourobject.h \
    connectfourrenderobject.h \
    helper.h \
    animation.h \
    mainwindow.h \
    settings.h \
    gamedatabase.h \
    gameserver.h \
    tcpgamemanager.h \
    gameclient.h \
    networkadapter.h \
    game.h \
    gameresults.h \
    aigamemanager.h \
    minmax.h
SOURCES       += \
                main.cpp \
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
    gameboardrenderer.cpp

QT           += opengl widgets network sql

# install
target.path = bin/connectfour
INSTALLS += target

#contains(QT_CONFIG, opengles.) {
#    contains(QT_CONFIG, angle): \
#        warning("Qt was built with ANGLE, which provides only OpenGL ES 2.0 on top of DirectX 9.0c")
#    error("This example requires Qt to be configured with -opengl desktop")
#}

FORMS += \
    settingswidget.ui \
    gameoverscreen.ui \
    mainwindow.ui \
    gameresults.ui

CONFIG += c++11
