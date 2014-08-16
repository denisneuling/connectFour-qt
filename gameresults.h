#ifndef GAMERESULTS_H
#define GAMERESULTS_H

#include <QWidget>

namespace Ui {
class GameResults;
}

/*!
 * \brief show previous games
 * \details class that shows previous games
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
class GameResults : public QWidget
{
    Q_OBJECT

public:
    explicit GameResults(QWidget *parent = 0);
    ~GameResults();

private slots:
    void on_backButton_clicked();

private:
    Ui::GameResults *ui;

    // QWidget interface
protected:
    void showEvent(QShowEvent *);
};

#endif // GAMERESULTS_H
