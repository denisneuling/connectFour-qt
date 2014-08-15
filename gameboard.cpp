#include "gameboard.h"

GameBoard::GameBoard(int rows, int columns, QObject *parent) :
    ConnectFourObject(columns, rows), QObject(parent)
{
    for (int i = 0; i < m_Columns; ++i)
        m_pGameBoard.push_back(std::make_shared<BoardColumn>(m_Rows));
}

GameBoard::GameBoard(const GameBoard &other) : ConnectFourObject(other.m_Columns, other.m_Rows), QObject(other.parent())
{
    this->m_Rows = other.m_Rows;
    this->m_Columns = other.m_Columns;
    this->m_pGameBoard = other.m_pGameBoard;
}

GameBoard::~GameBoard()
{
}

bool GameBoard::addCoin(int column, Coin coin)
{
    return m_pGameBoard[column]->addCoin(coin);
}

void GameBoard::removeCoin(int column)
{
    m_pGameBoard[column]->removeLastCoin();
}

Result GameBoard::checkGameConditions()
{
    if (checkDrawConditions())
        return DRAW;
    Coin result = checkWinConditions();
    if (result != NONE)
    {   if (result == RED)
            return WIN_RED;
        return WIN_YELLOW;
    }
    return NOT_FINISHED;
}

bool GameBoard::checkDrawConditions()
{
    for(auto it = m_pGameBoard.begin(); it != m_pGameBoard.end(); ++it)
    {
        if (!(*it)->isFull())
        {
            return false;
        }
    }

    return true;
}

Coin GameBoard::checkWinConditions()
{
    Coin currentCoin;
    int consecutives = 0;
    // check columns
    for (int i = 0; i < m_Columns; ++i)
    {
        for (int j = 0; j < m_pGameBoard[i]->getCurrentAmountOfCoins() - 3; ++j)
        {
            currentCoin = getCoin(i, j);
            for (consecutives = 0; isCoinValidAt(i, j + consecutives) && currentCoin == getCoin(i, j + consecutives); consecutives++) ;
            if (consecutives > 3)
            {
                return currentCoin;
            }
        }
    }
    // check rows
    for (int i = 0; i < m_Columns - 3; ++i)
    {
        for (int j = 0; j < m_Rows; j++)
        {
            currentCoin = getCoin(i, j);
            for (consecutives = 0; isCoinValidAt(i + consecutives, j) && currentCoin == getCoin(i + consecutives, j); consecutives++) ;
            if (consecutives > 3)
            {
                return currentCoin;
            }
        }
    }

    // up-right diag
    for (int i = 0; i < m_Columns - 3; ++i)
    {
        for (int  j = 0; j < m_Rows - 3; ++j)
        {
            currentCoin = getCoin(i, j);
            for (consecutives = 0; isCoinValidAt(i + consecutives, j + consecutives) && currentCoin == getCoin(i + consecutives, j + consecutives); consecutives++) ;
            if (consecutives > 3)
            {
                return currentCoin;
            }
        }
    }

    // up-right diag
    for (int i = 0; i < m_Columns - 1; ++i)
    {
        for (int  j = 0; j < m_Rows; ++j)
        {
            currentCoin = getCoin(i, j);
            for (consecutives = 0; isCoinValidAt(i - consecutives, j + consecutives) && currentCoin == getCoin(i - consecutives, j + consecutives); consecutives++) ;
            if (consecutives > 3)
            {
                return currentCoin;
            }
        }
    }

    return NONE;
}

std::vector<int> GameBoard::getAvailableMoves()
{
    std::vector<int> moves;
    for (int i = 0; i < m_Columns; ++i)
        if (!m_pGameBoard[i]->isFull())
            moves.push_back(i);
    return moves;
}

std::vector<std::shared_ptr<BoardColumn> > GameBoard::getCurrentBoard()
{
    return m_pGameBoard;
}

QString GameBoard::serialize()
{
    QString string;
    for (int i = 0; i < m_Columns; ++i)
    {
        string.push_back(QString("%1 ").arg(i));
        for(int j = 0; j < m_pGameBoard[i]->getCurrentAmountOfCoins(); ++j)
        {
            string.push_back(QString("%1").arg(getCoin(i, j)));
        }
        string.push_back("\n");
    }
    return string;
}

void GameBoard::deserialize(QString board)
{
    QStringList list = board.split("\n");
    for(int i = 0; i < list.length() - 1; ++i) // forget about the last \n
    {
        QString string = list[i].replace(" ", "");
        int currentColumn = string[0].digitValue();
        QString values = string.remove(0,1);
        m_pGameBoard[currentColumn]->clear();

        for(int j = 0; j < values.length(); j++)
        {
            m_pGameBoard[currentColumn]->addCoin(values[j].digitValue() == 0 ? RED:YELLOW);
        }
    }
}

Coin GameBoard::getCoin(int column, int row)
{
    return m_pGameBoard[column]->getCoin(row);
}

bool GameBoard::isCoinValidAt(int column, int row)
{
    if (column > m_Columns - 1 || column < 0 || row > m_Rows - 1 || row < 0)
        return false;
    return m_pGameBoard[column]->getCurrentAmountOfCoins() > row;
}
