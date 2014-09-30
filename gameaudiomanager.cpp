#include "gameaudiomanager.h"

GameAudioManager::~GameAudioManager()
{
    m_Sounds.clear();
}

void GameAudioManager::addAudio(QString name, std::shared_ptr<QSound> sound)
{
    m_Sounds.insert(std::pair<QString, std::shared_ptr<QSound> >(name, sound));
}

void GameAudioManager::playAudio(QString name)
{
    m_Sounds[name]->play();
}

GameAudioManager &GameAudioManager::getInstance()
{
    static GameAudioManager instance;
    return instance;
}

GameAudioManager::GameAudioManager(QObject *parent) :
    QObject(parent)
{
}
