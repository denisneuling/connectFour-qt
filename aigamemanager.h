#ifndef AIGAMEMANAGER_H
#define AIGAMEMANAGER_H

#include "gamemanager.h"

//! ai specific gamemanager
/*! AI specific gamemanger that handles the ai players turn */
class AIGameManager : public GameManager
{
    Q_OBJECT
public:
    explicit AIGameManager(QWidget *parent = 0);

    //! Sets the starting player depending wether ai should start
    void setStartingPlayer(Settings settings);

signals:

public slots:

    void mousePressEvent(QMouseEvent *event);
private slots:
    void makeAiTurn();
};

#endif // AIGAMEMANAGER_H
