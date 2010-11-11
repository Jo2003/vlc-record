/*********************** Information *************************\
| $HeadURL: https://vlc-record.googlecode.com/svn/branches/vlc-record-ws/cplayer.h $
|
| Author: Jo2003
|
| Begin: 24.02.2010 / 10:41:34
|
| Last edited by: $Author: Olenka.Joerg $
|
| $Id: cplayer.h 228 2010-06-23 16:22:06Z Olenka.Joerg $
\*************************************************************/
#ifndef __022410__CPLAYER_H
   #define __022410__CPLAYER_H

#include <QtGui/QApplication>
#include <QMessageBox>
#include <QWidget>
#include <QFrame>
#include <QTimer>
#include <QEvent>
#include <QTime>

#include <vlc/vlc.h>

#include "cvlcrecdb.h"
#include "clogfile.h"
#include "playstates.h"
#include "defdef.h"
#include "ctimerex.h"
#include "cshowinfo.h"
#include "csettingsdlg.h"
#include "cwaittrigger.h"
#include "cvideoframe.h"

//===================================================================
// namespace
//===================================================================
namespace Ui
{
   class CPlayer;
   typedef struct _vlcArgs
   {
      char** argArray;
      int    argc;
   } vlcArgs;
}

//===================================================================
// macro to connect player to hardware ...
//===================================================================
#ifdef Q_OS_WIN        // on windows ...
   #define connect_to_wnd(a, b) libvlc_media_player_set_hwnd (a, b)
#elif defined Q_OS_MAC // on MAC OS
   #define connect_to_wnd(a, b) libvlc_media_player_set_agl (a, b)
#else                  // on Linux
   #define connect_to_wnd(a, b) libvlc_media_player_set_xwindow (a, b)
#endif

/********************************************************************\
|  Class: CPlayer
|  Date:  14.02.2010 / 11:42:24
|  Author: Jo2003
|  Description: widget with vlc player (using libvlc)
|
\********************************************************************/
class CPlayer : public QWidget
{
   Q_OBJECT

public:
   CPlayer(QWidget *parent = 0);
   ~CPlayer();
   void cleanExit ();
   int  initPlayer (QStringList &slArgs);
   int  setMedia (const QString &sMrl);
   bool isPlaying ();
   void setPlugInPath(const QString &sPath);
   void setShortCuts (QVector<CShortcutEx *> *pvSc);
   void startPlayTimer ();
   void pausePlayTimer ();
   void stopPlayTimer ();
   void setSettings (CSettingsDlg *pDlg);
   void setTrigger (CWaitTrigger *pTrig);
   static void eventCallback (const libvlc_event_t *ev, void *player);

protected:
   void changeEvent(QEvent *e);
   int  createArgs (const QStringList &lArgs, Ui::vlcArgs& args);
   void freeArgs (Ui::vlcArgs& args);
   int  myToggleFullscreen ();
   void releasePlayer ();

private:
   Ui::CPlayer            *ui;
   QTimer                  poller;
   QTimer                  sliderTimer;
   CTimerEx                timer;
   libvlc_instance_t      *pVlcInstance;
   libvlc_media_player_t  *pMediaPlayer;
   libvlc_media_t         *pMedia;
   libvlc_event_manager_t *pEMPlay;
   libvlc_event_manager_t *pEMMedia;
   libvlc_log_t           *pLibVlcLog;
   uint                    uiVerboseLevel;
   QString                 sPlugInPath;
   bool                    bCtrlStream;
   CSettingsDlg           *pSettings;
   CWaitTrigger           *pTrigger;

private slots:
   void on_posSlider_valueChanged(int value);
   void on_posSlider_sliderReleased();
   void on_btnFullScreen_clicked();
   void on_cbxAspect_currentIndexChanged(QString str);
   void on_cbxCrop_currentIndexChanged(QString str);
   void slotChangeVolume(int newVolume);
   void slotLibVLCLog ();
   void slotUpdateSlider ();

public slots:
   int  playMedia (const QString &sCmdLine, bool bAllowCtrl);
   int  play();
   int  stop();
   int  pause();
   int  slotToggleFullScreen ();
   int  slotToggleAspectRatio ();
   int  slotToggleCropGeometry ();
   int  slotTimeJumpRelative (int iSeconds);
   void slotStoredAspectCrop ();

signals:
   void sigPlayState (int ps);
};

#endif /* __022410__CPLAYER_H */
/************************* History ***************************\
| $Log$
\*************************************************************/