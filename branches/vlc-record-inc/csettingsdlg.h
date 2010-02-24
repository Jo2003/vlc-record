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

#include "cinifile.h"
#include "clogfile.h"
#include "defdef.h"
#include "customization.h"

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

    bool UseProxy ();
    bool AllowEros ();
    bool FixTime ();
    bool DoRefresh ();
    bool HideToSystray ();
    bool AskForRecFile ();
    bool TranslitRecFile ();
    bool DetachPlayer ();

    int GetRefrInt ();
    int GetProxyPort ();
    int GetBufferTime ();
    vlclog::eLogLevel GetLogLevel ();

    void  SaveWindowRect (const QRect &wnd);
    QRect GetWindowRect (bool *ok = NULL);
    void  SaveSplitterSizes (const QList<int> &sz);
    QList<int> GetSplitterSizes (bool *ok = NULL);
    bool  IsMaximized ();
    void  SetIsMaximized (bool bMax);
    int   GetCustFontSize ();
    void  SetCustFontSize (int iSize);
    int   SaveOtherSettings ();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CSettingsDlg *m_ui;
    CIniFile IniFile;

signals:
    void sigReloadLogos ();
    void sigSetServer (int iSrv);
    void sigSetBuffer (int iBuffer);

private slots:
    void on_btnSaveStreamServer_clicked();
    void on_pushDelLogos_clicked();
    void on_pushSave_clicked();
    void on_pushDir_clicked();
    void on_pushVLC_clicked();
};

#endif /* __011910__CSETTINGSDLG_H */
/************************* History ***************************\
| $Log$
\*************************************************************/

