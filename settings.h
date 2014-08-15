#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>

//! data holder between ui and game
typedef struct Settings
{
    int width, height;
    QString player1, player2, ipAddress;
    bool useAI, aiBegins;
} Settings;

#endif // SETTINGS_H
