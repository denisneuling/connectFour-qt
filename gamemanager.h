#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QWidget>

#include "game.h"
#include "gameboard.h"
#include "gamerenderer.h"
#include "gameoverscreen.h"
#include "settings.h"

#define DELTA_TIME (1000 / 60)

/*!
 * \brief Class that handles game states and instanciates renderer and board
 * \details Class that handles game states and instanciates renderer and board
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
class GameManager : public QWidget
{
    Q_OBJECT
public:
    explicit GameManager(QWidget *parent = 0);
    ~GameManager();

    //! instanciates renderer and gameboard
    virtual void startGame(Settings settings);

    //! used for diffent game managers to handle starting player
    virtual void setStartingPlayer(Settings settings, Coin player = RED);

    void finishGame(Game game);
signals:
    void gameStarted();
public slots:

    void gameEnd();

    //! poll mouse position and update states
    void update();

    //! drop coins and check finish game
    void mousePressEvent(QMouseEvent *event);

    void saveGame();

    //! also handles start game
    void loadGame(QString gameBoard);

    void switchPlayer();

    Player getCurrentActivePlayer();

    Player getCurrentInactivePlayer();

protected:
    QHBoxLayout* m_pMainLayout;
    GameRenderer* m_pRenderer;
    GameBoard* m_pGameBoard;
    GameOverScreen* m_pGameOverScreen;
    QTimer* m_pUpdateTimer;
    Settings m_Settings;


    int m_CurrentColumn;
    Player m_CurrentPlayer, m_Player1, m_Player2;
    bool m_CurrentIsPlayer1;

    bool m_Finished;
    void checkAndHandleWin(int column);
};

#endif // GAMEMANAGER_H
