#ifndef BGM_H
#define BGM_H

#include <QMediaPlayer>
#include <QMediaPlaylist>

class BGM {
public:
    BGM();  // Constructor
    ~BGM(); // Destructor

    void play();    // Play or resume music
    void stop();    // Stop music
    void restart(); // Restart music from the beginning

private:
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
};

#endif // BGM_H
