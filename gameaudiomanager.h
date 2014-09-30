#ifndef GAMEAUDIOMANAGER_H
#define GAMEAUDIOMANAGER_H

#include <QObject>
#include <QSound>
#include <map>
#include <memory>

/*!
 * \class GameAudioManager
 * \brief Class that is responsible for playing audio sequences
 * \details Class that is responsible for playing audio sequences 
 *
 * \author Roland Luckenthuber
 * \author Denis Neuling
 */
class GameAudioManager : public QObject
{
    Q_OBJECT
public:
    ~GameAudioManager();
    //! adds audio
    /*!
     * \brief addAudio  to the manager. sounds were released after execution
     * \param name the identifier of the sound
     * \param sound the audio file itself
     */
    void addAudio(QString name, std::shared_ptr<QSound> sound);
    //! plays the audio file
    void playAudio(QString name);
    static GameAudioManager &getInstance();
private:
    explicit GameAudioManager(QObject *parent = 0);
    GameAudioManager(GameAudioManager const&);
    void operator =(GameAudioManager const&);

    std::map<QString, std::shared_ptr<QSound> > m_Sounds;
signals:

public slots:

};

#endif // GAMEAUDIOMANAGER_H
