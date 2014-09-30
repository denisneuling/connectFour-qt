#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>

/*!
 * \brief some design configuration capabilities...
 * \details some design configuration capabilities...
 *
 * \author Roland Luckenhuber
 * \author Denis Neuling
 */
typedef enum Design
{
    Round = 0,
    Squared,
    Triangle
} Design;

/*!
 * \brief defines the strength of the artificial intelligence engine
 * \details defines the strength of the artificial intelligence engine
 *
 * \author Roland Luckenhuber
 * \author Denis Neuling
 */
typedef enum AIStrength
{
    Easy = 0,
    Medium,
    Hard
} AIStrength;

/*!
 * \brief data holder between ui and game
 * \details data holder between ui and game
 *
 * \author Roland Luckenhuber
 * \author Denis Neuling
 */
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
