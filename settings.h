#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>

typedef enum Design
{
    Round = 0,
    Squared,
    Triangle
} Design;

typedef enum AIStrength
{
    Easy = 0,
    Medium,
    Hard
} AIStrength;

//! data holder between ui and game
typedef struct Settings
{
    Settings() :
        width(0), height(0), player1(""), player2(""),
        ipAddress(""), useAI(false), aiBegins(false),
        design(Round), aiStrength(Easy)
    { }
    int width, height;
    QString player1, player2, ipAddress;
    bool useAI, aiBegins;
    Design design;
    AIStrength aiStrength;
} Settings;




#endif // SETTINGS_H
