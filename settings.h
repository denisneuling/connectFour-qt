#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>

/*!
 * \brief data holder between ui and game
 * \details data holder between ui and game
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
typedef struct Settings
{
    int width, height;
    QString player1, player2, ipAddress;
    bool useAI, aiBegins;
} Settings;

#endif // SETTINGS_H
