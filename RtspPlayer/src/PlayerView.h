#ifndef VLCPlayer_h__
#define VLCPlayer_h__

#include <QtWidgets/QMainWindow>
#include "vlc/vlc.h"
#include "ui_PlayerView.h"

#define SAFE_DELETE(a) if( (a) != NULL ) delete (a); (a) = NULL;

class CPlayerView : public QMainWindow
{
    Q_OBJECT

public:
    CPlayerView(QWidget *parent = Q_NULLPTR);
    ~CPlayerView();

    char* GetVideoBuf() const;
    void OpenVideo(const char* rtsp);

private slots:
    void OnOpenVideoBtnClick();
    void OnPlay();
    void OnPause();

private:
    static void* PreDecode_cb(void *opaque, void **planes);
    static void HandleStream_cb(void *opaque, void *picture, void *const *planes);
    static void Render_cb(void *opaque, void *picture);

private:
    Ui::PlayerView m_ui;

    char * m_videobuf;

    libvlc_instance_t* m_vlcInstance;
    libvlc_media_player_t* m_vlcMediaPlayer;
};
#endif // VLCPlayer_h__
