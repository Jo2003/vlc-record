/*------------------------------ Information ---------------------------*//**
 *
 *  $HeadURL$
 *
 *  @file     qwaitwidget.cpp
 *
 *  @author   Jo2003
 *
 *  @date     12.05.2014
 *
 *  $Id$
 *
 *///------------------------- (c) 2014 by Jo2003  --------------------------
#include "qwaitwidget.h"
#include "ui_qwaitwidget.h"
#include <QMovie>

//---------------------------------------------------------------------------
//
//! \brief   construct wait splash screen
//
//! \author  Jo2003
//! \date    12.05.2014
//
//! \param   parent (QWidget *) pointer to parent widget
//
//---------------------------------------------------------------------------
QWaitWidget::QWaitWidget(QWidget *parent) :
   QWidget(parent, Qt::SplashScreen),
   ui(new Ui::QWaitWidget)
{
   ui->setupUi(this);
   QMovie *movie = new QMovie(":app/wait");
   ui->labWait->setMovie(movie);
   movie->start();
}

//---------------------------------------------------------------------------
//
//! \brief   destroy wait splash screen
//
//! \author  Jo2003
//! \date    12.05.2014
//
//---------------------------------------------------------------------------
QWaitWidget::~QWaitWidget()
{
   delete ui;
}

//---------------------------------------------------------------------------
//
//! \brief   retranslate UI
//
//! \author  Jo2003
//! \date    12.05.2014
//
//! \param   pEv (QEvent *) pointer to event
//
//---------------------------------------------------------------------------
void QWaitWidget::changeEvent(QEvent *pEv)
{
   if (pEv->type() == QEvent::LanguageChange)
   {
      ui->retranslateUi(this);
   }

   QWidget::changeEvent(pEv);
}
