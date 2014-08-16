#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <QWidget>

namespace Ui {

class GameOverScreen;
}

/*!
 * \class GameOverScreen
 * \brief Class that handles game over screen
 * \details Class that handles game over screen
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
class GameOverScreen : public QWidget
{
    Q_OBJECT

public:
    explicit GameOverScreen(QWidget *parent = 0);
    ~GameOverScreen();

    void setWinner(QString winner);
private:
    Ui::GameOverScreen *ui;
};

#endif // GAMEOVERSCREEN_H
