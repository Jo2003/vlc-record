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
#include <QCryptographicHash>
#include <QTableWidget>
#include <QStatusBar>

#include "cvlcrecdb.h"
#include "clogfile.h"
#include "defdef.h"
#include "customization.h"
#include "cdirstuff.h"
#include "ckartinaxmlparser.h"
#include "cshortcutex.h"
#include "cshortcutgrabber.h"

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

    bool UseProxy ();
    bool AllowEros ();
    bool FixTime ();
    bool DoRefresh ();
    bool HideToSystray ();
    bool AskForRecFile ();
    bool TranslitRecFile ();
    bool DetachPlayer ();
    bool regOk();
    bool extChanList();

    int GetRefrInt ();
    int GetProxyPort ();
    int GetBufferTime ();
    vlclog::eLogLevel GetLogLevel ();

    void  SaveWindowRect (const QRect &wnd);
    QRect GetWindowRect (bool *ok = NULL);
    void  SaveSplitterSizes (const QString &name, const QList<int> &sz);
    QList<int> GetSplitterSizes (const QString &name, bool *ok = NULL);
    bool  IsMaximized ();
    void  SetIsMaximized (bool bMax);
    int   GetCustFontSize ();
    void  SetCustFontSize (int iSize);
    int   SaveOtherSettings ();
    void  SaveFavourites (const QList<int> &favList);
    QList<int> GetFavourites (bool *ok = NULL);
    void  SetStreamServerCbx (const QVector<cparser::SSrv>& vSrvList, const QString& sActSrv);
    void  SetBitrateCbx (const QVector<int>& vValues, int iActrate);
    void  SaveCookie (const QString &str);
    bool  DisableSplashScreen ();
    QString hsah (const QString &str);
    QString& reverse (QString &str);
    int   GetBitRate ();
    void  addShortCut (const QString& descr, const QString& target, const QString& slot, const QString& keys);
    void  delShortCut (const QString& target, const QString& slot);
    void  updateShortcutDescr(const QString& descr, const QString& target, const QString& slot);
    QString shortCut (const QString& target, const QString& slot) const;
    int shortCutCount();
    void setStatusBar(QStatusBar *pStBar);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CSettingsDlg *m_ui;
    CShortcutEx *pShortApiServer;
    QStatusBar *pStatusBar;
    QString str;

signals:
    void sigReloadLogos ();
    void sigSetServer (QString sIp);
    void sigSetBitRate (int iRate);
    void sigSetBuffer (int iBuffer);

private slots:
    void on_btnResetShortcuts_clicked();
    void on_pushDoRegister_clicked();
    void on_btnSaveStreamServer_clicked();
    void on_btnSaveBitrate_clicked();
    void on_pushDelLogos_clicked();
    void on_pushSave_clicked();
    void on_pushDir_clicked();
    void on_pushVLC_clicked();
    void slotEnableApiServer ();

 public slots:
    void slotSplashStateChgd (bool bChecked);
};

#endif /* __011910__CSETTINGSDLG_H */
/************************* History ***************************\
| $Log$
\*************************************************************/