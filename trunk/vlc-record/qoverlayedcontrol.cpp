/*------------------------------ Information ---------------------------*//**
 *
 *  $HeadURL$
 *
 *  @file     qoverlayedcontrol.cpp
 *
 *  @author   Jo2003
 *
 *  @date     09.11.2012
 *
 *  $Id$
 *
 *///------------------------- (c) 2012 by Jo2003  --------------------------
#include "qoverlayedcontrol.h"
#include "ui_qoverlayedcontrol.h"
#include "qfusioncontrol.h"
#include "defdef.h"

// fusion control ...
extern QFusionControl missionControl;

//---------------------------------------------------------------------------
//
//! \brief   constructs QOverlayedControl object
//
//! \author  Jo2003
//! \date    09.11.2012
//
//! \param   parent pointer to parent widget
//! \param   f window flags
//
//! \return  --
//---------------------------------------------------------------------------
QOverlayedControl::QOverlayedControl(QWidget *parent, Qt::WindowFlags f) :
   QFadeWidget(parent, f),
   ui(new Ui::QOverlayedControl),
   _offset(0, 0),
   _mouseOverMoveHandle(false)
{
   ui->setupUi(this);

   // feed mission control with control items ...
   missionControl.addButton(ui->pushPlay,          QFusionControl::BTN_PLAY);
   missionControl.addButton(ui->pushStop,          QFusionControl::BTN_STOP);
   missionControl.addButton(ui->pushRecord,        QFusionControl::BTN_REC);
   missionControl.addButton(ui->pushFwd,           QFusionControl::BTN_FWD);
   missionControl.addButton(ui->pushBwd,           QFusionControl::BTN_BWD);
   missionControl.addButton(ui->btnFullScreen,     QFusionControl::BTN_FS);
   missionControl.addButton(ui->btnSaveAspectCrop, QFusionControl::BTN_FRMT);
   missionControl.addButton(ui->btnScrShot,        QFusionControl::BTN_SCRSHOT);

   missionControl.addCngSlider(ui->posSlider);
   missionControl.addJumpBox(ui->cbxTimeJumpVal);
   missionControl.addVolSlider(ui->volSlider);
   missionControl.addTimeLab(ui->labTime);
   missionControl.addMuteLab(ui->labSound);
   missionControl.addInfoLab(ui->labMoveHandle);

   missionControl.addVidFormCbx(ui->cbxAspect, QFusionControl::CBX_ASPECT);
   missionControl.addVidFormCbx(ui->cbxCrop, QFusionControl::CBX_CROP);

   connect (ui->labMoveHandle, SIGNAL(mouseEnters()), this, SLOT(slotMouseEntersMoveHandle()));
   connect (ui->labMoveHandle, SIGNAL(mouseLeabes()), this, SLOT(slotMouseLeavesMoveHandle()));
}

//---------------------------------------------------------------------------
//
//! \brief   destroys QOverlayedControl object
//
//! \author  Jo2003
//! \date    09.11.2012
//
//! \param   --
//
//! \return  --
//---------------------------------------------------------------------------
QOverlayedControl::~QOverlayedControl()
{
   delete ui;
}

//---------------------------------------------------------------------------
//
//! \brief   make sure GUI is translated as needed
//
//! \author  Jo2003
//! \date    29.11.2012
//
//! \param   e pointer to event
//
//! \return  --
//---------------------------------------------------------------------------
void QOverlayedControl::changeEvent(QEvent *e)
{
   if (e->type() == QEvent::LanguageChange)
   {
      ui->retranslateUi(this);
   }

   QWidget::changeEvent(e);
}

//---------------------------------------------------------------------------
//
//! \brief   store widget coordinates when mouse is above move handle
//
//! \author  Jo2003
//! \date    29.11.2012
//
//! \param   e pointer to mouse event
//
//! \return  --
//---------------------------------------------------------------------------
void QOverlayedControl::mousePressEvent(QMouseEvent* e)
{
   if (_mouseOverMoveHandle)
   {
      if (isWindow())
      {
         _offset = e->globalPos() - pos();
      }
      else
      {
         _offset = e->pos();
      }
   }

   QWidget::mousePressEvent(e);
}

//---------------------------------------------------------------------------
//
//! \brief   move widget when mouse button is pressed and above move handle
//
//! \author  Jo2003
//! \date    29.11.2012
//
//! \param   e pointer to mouse event
//
//! \return  --
//---------------------------------------------------------------------------
void QOverlayedControl::mouseMoveEvent(QMouseEvent* e)
{
   if (_mouseOverMoveHandle)
   {
      if (isWindow())
      {
         move(e->globalPos() - _offset);
      }
      else
      {
         move(mapToParent(e->pos() - _offset));
      }
   }

   QWidget::mouseMoveEvent(e);
}

//---------------------------------------------------------------------------
//
//! \brief   reset offset value when mouse button released and above move hdl
//
//! \author  Jo2003
//! \date    29.11.2012
//
//! \param   e pointer to mouse event
//
//! \return  --
//---------------------------------------------------------------------------
void QOverlayedControl::mouseReleaseEvent(QMouseEvent* e)
{
   if (_mouseOverMoveHandle)
   {
      _offset = QPoint();
   }
   QWidget::mouseReleaseEvent(e) ;
}

//---------------------------------------------------------------------------
//
//! \brief   override QWidget::wheelEvent()
//
//! \author  Jo2003
//! \date    08.02.2012
//
//! \param   event pointer to wheel event
//
//! \return  --
//---------------------------------------------------------------------------
void QOverlayedControl::wheelEvent(QWheelEvent *event)
{
   event->ignore();

   emit wheel ((event->delta() > 0) ? true : false);
}

//---------------------------------------------------------------------------
//
//! \brief   mouse enters widget -> emit signal
//
//! \author  Jo2003
//! \date    26.11.2012
//
//! \param   e pointer to QEvent
//
//! \return  --
//---------------------------------------------------------------------------
void QOverlayedControl::enterEvent(QEvent *e)
{
   emit sigMouseAboveOverlay();
   QWidget::enterEvent(e);
}

//---------------------------------------------------------------------------
//
//! \brief   mouse leaves widget -> emit signal
//
//! \author  Jo2003
//! \date    26.11.2012
//
//! \param   e pointer to QEvent
//
//! \return  --
//---------------------------------------------------------------------------
void QOverlayedControl::leaveEvent(QEvent *e)
{
   emit sigMouseLeavesOverlay();
   QWidget::leaveEvent(e);
}

//---------------------------------------------------------------------------
//
//! \brief   mouse entered move handle, change mouse cursor
//
//! \author  Jo2003
//! \date    29.11.2012
//
//! \param   --
//
//! \return  --
//---------------------------------------------------------------------------
void QOverlayedControl::slotMouseEntersMoveHandle()
{
   QApplication::setOverrideCursor(Qt::OpenHandCursor);
   _mouseOverMoveHandle = true;
}

//---------------------------------------------------------------------------
//
//! \brief   mouse leave move handle, change mouse cursor
//
//! \author  Jo2003
//! \date    29.11.2012
//
//! \param   --
//
//! \return  --
//---------------------------------------------------------------------------
void QOverlayedControl::slotMouseLeavesMoveHandle()
{
   QApplication::restoreOverrideCursor();
   _mouseOverMoveHandle = false;
}

//---------------------------------------------------------------------------
//
//! \brief   force fade out
//
//! \author  Jo2003
//! \date    03.12.2012
//
//! \param   --
//
//! \return  --
//---------------------------------------------------------------------------
void QOverlayedControl::on_pushHide_clicked()
{
   fadeOut();
}
