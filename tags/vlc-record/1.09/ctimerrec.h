#ifndef CTIMERREC_H
#define CTIMERREC_H

#include <QDialog>
#include <QDateTime>
#include <QString>
#include <QTextStream>
#include <QTimer>
#include <QVector>
#include <QMap>
#include <QFile>
#include <QXmlStreamReader>

#include "defdef.h"
#include "ckartinaxmlparser.h"

namespace Ui
{
    class  CTimerRec;
    struct SChanEntry
    {
       int     cid;
       QString Name;
    };

    struct SRecEntry
    {
       uint id;
       int  cid;
       uint uiStart;
       uint uiEnd;
       QString sName;
    };
}

class CTimerRec : public QDialog
{
    Q_OBJECT

public:
   CTimerRec(QWidget *parent = 0);
   virtual ~CTimerRec();

   void SetTimeShift (int iTs);
   void SetChanList  (const QVector<cparser::SChan> &chanList);
   void SetRecInfo (uint uiStart, uint uiEnd, int cid);
   void SetLogoPath (const QString &str);
   int SaveRecordList ();
   int ReadRecordList ();


protected:
   void changeEvent(QEvent *e);

private:
   Ui::CTimerRec *ui;
   int     iTimeShift;
   QString sLogoPath;
   QMap<uint, Ui::SRecEntry> JobList;
   QMap<int, Ui::SChanEntry> ChanList;
   QString sListFile;

private slots:
    void on_pushOK_clicked();
    void on_btnSet_clicked();
};

#endif // CTIMERREC_H