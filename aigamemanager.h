#ifndef AIGAMEMANAGER_H
#define AIGAMEMANAGER_H

#include <memory>
#include "gamemanager.h"
#include "minmax.h"

/*!
 * \class AIGameManager
 * \brief ai specific gamemanager
 * \details AI specific gamemanger that handles the ai players turn
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
class AIGameManager : public GameManager
{
    Q_OBJECT
public:
    explicit AIGameManager(QWidget *parent = 0);

    virtual void startGame(Settings settings);

	/*!
     * \brief Sets the starting player depending wether ai should start
     */
    virtual void setStartingPlayer(Settings settings);
signals:

public slots:

    void mousePressEvent(QMouseEvent *event);
private slots:
    void makeAiTurn();
private:
    std::shared_ptr<MinMax> m_pAI;
};

#endif // AIGAMEMANAGER_H
