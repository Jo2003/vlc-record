/*********************** Information *************************\
| $HeadURL$
|
| Author: Jo2003
|
| Begin: 24.02.2010 / 10:41:34
|
| Last edited by: $Author$
|
| $Id$
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
#include <QDesktopWidget>
#include <QMap>

#include <vlc/vlc.h>

#include "cvlcrecdb.h"
#include "clogfile.h"
#include "playstates.h"
#include "defdef.h"
#include "ctimerex.h"
#include "cshowinfo.h"
#include "csettingsdlg.h"
#include "cwaittrigger.h"
#include "qvlcvideowidget.h"

//===================================================================
// namespace
//===================================================================
namespace Ui
{
   class CPlayer;
}

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
   int  initPlayer ();
   bool isPlaying ();
   void setShortCuts (QVector<CShortcutEx *> *pvSc);
   void startPlayTimer ();
   void pausePlayTimer ();
   void stopPlayTimer ();
   void setSettings (CSettingsDlg *pDlg);
   void setTrigger (CWaitTrigger *pTrig);
   static void eventCallback (const libvlc_event_t *ev, void *userdata);
   bool isPositionable();
   void initSlider ();
   uint getSilderPos();
   QVlcVideoWidget* getAndRemoveVideoWidget();
   void addAndEmbedVideoWidget();

   static libvlc_event_type_t _actEvent;

protected:
   virtual void changeEvent(QEvent *e);
   void enableDisablePlayControl (bool bEnable);
   void connectToVideoWidget ();
   int  addAd ();
   int  clearMediaList();

private:
   Ui::CPlayer                 *ui;
   QTimer                       sliderTimer;
   QTimer                       tAspectShot;
   QTimer                       tEventPoll;
   CTimerEx                     timer;
   libvlc_instance_t           *pVlcInstance;
   libvlc_media_player_t       *pMediaPlayer;
   libvlc_event_manager_t      *pEMPlay;
   libvlc_media_list_player_t  *pMedialistPlayer;
   libvlc_media_list_t         *pMediaList;
   libvlc_event_type_t          lastEvent;
   bool                         bCtrlStream;
   CSettingsDlg                *pSettings;
   CWaitTrigger                *pTrigger;
   bool                         bSpoolPending;
   uint                         uiDuration;
   QMap<QString, QString>       mAspect;
   QMap<QString, QString>       mCrop;

private slots:
   void on_posSlider_valueChanged(int value);
   void on_btnFullScreen_clicked();
   void on_cbxAspect_currentIndexChanged(QString str);
   void on_cbxCrop_currentIndexChanged(QString str);
   void slotChangeVolume(int newVolume);
   void slotUpdateSlider ();
   void slotChangeVolumeDelta (const bool up);
   void slotSliderPosChanged();
   void slotToggleFullscreen();
   void slotEventPoll();

public slots:
   int  playMedia (const QString &sCmdLine);
   int  play();
   int  stop();
   int  pause();
   int  slotToggleAspectRatio ();
   int  slotToggleCropGeometry ();
   int  slotTimeJumpRelative (int iSeconds);
   void slotStoredAspectCrop ();
   void slotMoreLoudly();
   void slotMoreQuietly();
   void slotMute();
   void slotShowInfoUpdated();
   void slotFsToggled (int on);

signals:
   void sigPlayState (int ps);
   void sigTriggerAspectChg ();
   void sigCheckArchProg(ulong ulArchGmt);
   void sigToggleFullscreen();
};

#endif /* __022410__CPLAYER_H */
/************************* History ***************************\
| $Log$
\*************************************************************/
