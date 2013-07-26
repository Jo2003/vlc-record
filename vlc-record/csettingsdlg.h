/*********************** Information *************************\
| $HeadURL$
|
| Author: Jo2003
|
| Begin: 19.01.2010 / 15:41:34
|
| Last edited by: $Author$
|
| $Id$
\*************************************************************/
#ifndef __011910__CSETTINGSDLG_H
   #define __011910__CSETTINGSDLG_H

#include <QtGui/QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QTableWidget>
#include <QTimer>
#include <QSystemTrayIcon>

#include "cvlcrecdb.h"
#include "clogfile.h"
#include "defdef.h"
#include "cdirstuff.h"
#include "cshortcutex.h"
#include "cshortcutgrabber.h"
#include "api_inc.h"

//===================================================================
// namespace
//===================================================================
namespace Ui
{
    class CSettingsDlg;
}

/********************************************************************\
|  Class: CSettingsDlg
|  Date:  19.01.2010 / 15:42:24
|  Author: Jo2003
|  Description: dialog to configure needed settings
|
\********************************************************************/
class CSettingsDlg : public QDialog
{
    Q_OBJECT

public:
    CSettingsDlg(QWidget *parent = 0);
    ~CSettingsDlg();

    QString GetVLCPath ();
    QString GetTargetDir ();
    QString GetUser ();
    QString GetPasswd ();
    QString GetErosPasswd ();
    QString GetProxyHost ();
    QString GetProxyUser ();
    QString GetProxyPasswd ();
    QString GetLanguage ();
    QString GetShutdownCmd ();
    QString GetPlayerModule ();
    QString GetCookie ();
    QString GetAPIServer ();
    QString getDeinlMode ();

    bool UseProxy ();
    bool AllowEros ();
    bool FixTime ();
    bool HideToSystray ();
    bool AskForRecFile ();
    bool TranslitRecFile ();
    bool DetachPlayer ();
    int  getTimeShift();
    bool doubleClickToPlay();
    bool useGpuAcc();
    bool showAds();

    int GetProxyPort ();
    int GetBufferTime ();
    vlclog::eLogLevel GetLogLevel ();

    void  SaveSplitterSizes (const QString &name, const QList<int> &sz);
    QList<int> GetSplitterSizes (const QString &name, bool *ok = NULL);
    int   GetCustFontSize ();
    void  SetCustFontSize (int iSize);
    void  SaveFavourites (const QList<int> &favList);
    QList<int> GetFavourites (bool *ok = NULL);
    void  SetStreamServerCbx (const QVector<cparser::SSrv>& vSrvList, const QString& sActSrv);
    void  SetBitrateCbx (const QVector<int>& vValues, int iActrate);
    void  SaveCookie (const QString &str);
    bool  DisableSplashScreen ();
    int   GetBitRate ();
    void  addShortCut (const QString& descr, const QString& target, const QString& slot, const QString& keys);
    void  delShortCut (const QString& target, const QString& slot);
    void  updateShortcutDescr(const QString& descr, const QString& target, const QString& slot);
    QString shortCut (const QString& target, const QString& slot) const;
    int  shortCutCount();
    void readSettings ();
    void fillTimeShiftCbx(const QVector<int> &vVals, int iAct);
    void saveChannel(int cid);
    int lastChannel();
    void saveEpgDay(const QString &dateString);
    QString lastEpgDay();
    uint libVlcVerboseLevel();
    void setAccountInfo(const cparser::SAccountInfo *pInfo);
    void setGeometry(const QByteArray &ba);
    QByteArray getGeometry();
    int setLanguage (const QString& lng);

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::CSettingsDlg  *m_ui;
    QString            sTempPasswd;
    CShortcutEx       *pShortApiServer;
    CShortcutEx       *pShortVerbLevel;
    QVector<float>     vBuffs;
    QVector<cparser::SChan>      channelVector;
    QVector<cparser::SVodRate>   vodRatesVector;
    const cparser::SAccountInfo *pAccountInfo;

signals:
    void sigReloadLogos ();
    void sigSetServer (QString sIp);
    void sigSetBitRate (int iRate);
    void sigSetBuffer (int iBuffer);
    void sigSetTimeShift (int iShift);

private slots:
    void on_btnResetShortcuts_clicked();
    void on_checkAdvanced_clicked(bool checked);
    void on_pushDelLogos_clicked();
    void on_pushSave_clicked();
    void on_pushDir_clicked();
    void on_pushVLC_clicked();
    void slotEnableApiServer ();
    void slotEnableVlcVerbLine ();
    void on_cbxStreamServer_activated(int index);
    void on_cbxBitRate_activated(int index);
    void on_cbxTimeShift_activated(int index);
    void on_btnSaveExitManager_clicked();
    void on_btnEnterManager_clicked();
    void slotLockParentalManager ();
    void on_btnChgPCode_clicked();
    void on_linePasswd_returnPressed();
    void on_cbxLanguage_currentIndexChanged(const QString &lng);
    void on_cbxLanguage_activated(const QString &lng);

public slots:
    void slotSplashStateChgd (bool bChecked);
    void slotBuildChanManager (const QString &str);
    void slotBuildVodManager (const QString &str);
    void slotNewPCodeSet ();
    void slotEnablePCodeForm ();
};

#endif /* __011910__CSETTINGSDLG_H */
/************************* History ***************************\
| $Log$
\*************************************************************/

