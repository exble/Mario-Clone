#include "BGM.h"

BGM::BGM() {
    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/audio/audio/01. Ground Theme.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player = new QMediaPlayer();
    player->setPlaylist(playlist);
    player->setVolume(50); // Default volume
}

BGM::~BGM() {
    player->stop();
    delete player;
    delete playlist;
}

void BGM::play() {
    if (player->state() == QMediaPlayer::StoppedState) {
        player->play();
    }
}

void BGM::stop() {
    player->stop();
}

void BGM::restart() {
    player->stop();
    player->play();
}
