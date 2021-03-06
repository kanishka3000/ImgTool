#include "stdafx.h"
#include "GraphiItemCtrl.h"
#include <QMessageBox>
#include <QString>
#include <ConfigurationWnd.h>
#include <QColorDialog>
#include <QShortcut>
GraphiItemCtrl::GraphiItemCtrl(QWidget *parent)
	:QWidget(parent)
{
	setupUi(this);
	d_Scale = 1;
	i_LastItemKey = -1;
	i_ActivityMode = ACTIVTITY_MODE_SELECT;
	
	QPixmap oImage(":/ImageTool/Resources/Penguins.jpg");
	o_OrigianlRect = oImage.rect();
	p_GraphicView->setSceneRect(oImage.rect());
	p_GraphicView->setMaximumHeight(oImage.height());
	p_GraphicView->setMaximumWidth(oImage.width());
	
	p_Image = new GraphicImage(oImage,this);
	p_GraphicView->setScene(&o_ItemScene);
	
	o_ItemScene.addItem(p_Image);

	o_MainActivity.addButton(rdo_Draw);
	o_MainActivity.addButton(rdo_Erase);
	o_MainActivity.addButton(rdo_Select);
	o_MainActivity.addButton(rdo_Point);

	o_DrawType.addButton(btn_Line);
	o_DrawType.addButton(btn_Rectangle);
	o_DrawType.addButton(btn_Elipse);

	o_Zooming.addButton(btn_ZoomIn);
	o_Zooming.addButton(btn_ZoomOut);

	b_InitDraw = false;
	i_CurrentType = 6;

	lbl_SelColor->setBackgroundRole(QPalette::Background);
	lbl_SelColor->setAutoFillBackground(true);

	QPalette oPlaet;
	oPlaet.setColor(QPalette::Background, Qt::black);
	lbl_SelColor->setPalette(oPlaet);
	i_CurrentWidth = 3;
	e_CurrentColor = Qt::black;
	o_CurrentPen.setColor(e_CurrentColor);
	o_CurrentPen.setWidth(i_CurrentWidth);
	p_ColorDialog = new QColorDialog(this);
	
	p_GraphicView->setInteractive(false);
	p_GraphicView->setDragMode(QGraphicsView::ScrollHandDrag);

	frm_ClrSelection->setEnabled(false);
	frm_ItemSelection->setEnabled(false);
	frm_SizeSelection->setEnabled(false);

	connect(&o_MainActivity, SIGNAL(buttonClicked ( QAbstractButton *  )),
		this, SLOT(OnButtonSelected( QAbstractButton *  )));
	connect(&o_DrawType, SIGNAL(buttonClicked(QAbstractButton*)), 
		this, SLOT(OnDrawTypeChanged(QAbstractButton *)));
	connect(p_ColorDialog, SIGNAL(colorSelected ( const QColor   )),
		this, SLOT(ColorSelected( QColor  )));
	connect(&o_Zooming, SIGNAL(buttonClicked ( QAbstractButton *  )), 
		this, SLOT(OnZoomChanged(QAbstractButton * )));

	
	
}

GraphiItemCtrl::~GraphiItemCtrl()
{
	delete p_Image;
}

int GraphiItemCtrl::GetNextItemKey()
{
	i_LastItemKey++;
	return i_LastItemKey;
}

void GraphiItemCtrl::paintEvent( QPaintEvent * event )
{
	QBrush oBrush(Qt::red);
	QPen oPen(Qt::blue);
	oPen.setWidth(6);
	
	o_ItemScene.addEllipse(10,10,100,100,oPen,oBrush);
	
	QWidget::paintEvent(event);


}

void GraphiItemCtrl::OnMouseClickEvent(QPointF oPoint )
{
	if(i_ActivityMode == ACTIVITY_MODE_POINT)
		return;

	o_PointA = oPoint;
	if(i_ActivityMode == ACTIVTITY_MODE_DRAW)
	{
		setCursor(Qt::CrossCursor);
		
	}
}

void GraphiItemCtrl::OnMouseReleaseEvent( QPointF oPoint  )
{

	if(i_ActivityMode == ACTIVITY_MODE_POINT)
		return;

	o_PointB =  oPoint;

	setCursor(Qt::ArrowCursor);
	if(o_MainActivity.checkedButton() == rdo_Draw)
	{
		OnDrawEvent();
	}
	else if(o_MainActivity.checkedButton() == rdo_Erase)
	{
		OnRemoveEvent();
		
	}

}

void GraphiItemCtrl::OnDrawItemChanged( QString sItemType )
{

	s_CurrentItem = sItemType;

}

void GraphiItemCtrl::OnDrawEvent()
{

	switch(i_CurrentType)
	{
	case ITM_TYPE_LINE:
		{
			QGraphicsLineItem* pLine = o_ItemScene.addLine(o_PointA.x(),o_PointA.y(),
				o_PointB.x(), o_PointB.y(),o_CurrentPen);
			int iKey = GetNextItemKey();
			QLineF oLine = pLine->line();
			map_Lines.insert(iKey,oLine);
			map_LineItems.insert(iKey, pLine);
			pLine->setData(CUSTDATA_KEY,iKey);
			
			emit NotifyLineAdded(iKey,oLine);
			break;
		}
	case ITM_TYPE_RECTANGLE:
		{
			double dWidth = o_PointB.x() - o_PointA.x();
			double dHeight = o_PointB.y() - o_PointA.y();
			QGraphicsRectItem* pRect = o_ItemScene.addRect(o_PointA.x(),o_PointA.y(),
				dWidth ,dHeight,o_CurrentPen);
			int iKey = GetNextItemKey();
			QRectF oRect = pRect->rect();
			map_Rects.insert(iKey, oRect);
			pRect->setData(CUSTDATA_KEY,iKey);
			
			emit NotifyRectAdded(iKey,oRect);
		
			break;
		}
	case ITM_TYPE_ELIPSE:
		{
			double dWidth = o_PointB.x() - o_PointA.x();
			double dHeight = o_PointB.y() - o_PointA.y();
			QGraphicsEllipseItem* pElipse =	o_ItemScene.addEllipse(o_PointA.x(),o_PointA.y(),
				dWidth ,dHeight,o_CurrentPen);
			
			int iKey = GetNextItemKey();
			pElipse->setData(CUSTDATA_KEY, iKey);
			QRectF oRect = pElipse->rect();
			map_Elipses.insert(iKey,oRect);
			
			emit NotifyElipseAdded(iKey,oRect);
			break;
		}
	}



}

void GraphiItemCtrl::OnRemoveEvent()
{
	QGraphicsItem* pItem = o_ItemScene.itemAt(o_PointB,QTransform());

	if(pItem == p_Image)
		return;// should not delete the image

	int iItemKey = pItem->data(CUSTDATA_KEY).toInt();
	int iType = pItem->type();

	switch(iType)
	{

	case ITM_TYPE_LINE:
		{
			emit NotifyLineRemove(iItemKey);
			break;
		}
	case ITM_TYPE_ELIPSE:
		{
			emit NotifyElipseRemoved(iItemKey);
			break;
		}
	case ITM_TYPE_RECTANGLE:
		{
			emit NotifyRectRemoved(iItemKey);
			break;
		}
	}

	o_ItemScene.removeItem(pItem);
}

void GraphiItemCtrl::OpenConfigurationWnd()
{
	ConfigurationWnd* pWnd = new ConfigurationWnd();
	pWnd->show();
	connect(this,SIGNAL(NotifyAllLines(QMap<int,QLineF> )),pWnd,
		SLOT(OnAllLines(QMap<int,QLineF> )));
	connect(this,SIGNAL(NotifyAllRects(QMap<int,QRectF> )),pWnd,
		SLOT(OnAllRects(QMap<int,QRectF> )));
	connect(this,SIGNAL(NotifyAllElipses(QMap<int,QRectF> )),pWnd,
		SLOT(OnAllElipses(QMap<int,QRectF> )));

	emit NotifyAllRects(map_Rects);
	emit NotifyAllLines(map_Lines);
	emit NotifyAllElipses(map_Elipses);
	connect(pWnd, SIGNAL(NotifyLineChanged(int ,QLineF )),
		this, SLOT(OnLineChanged( int , QLineF  )));
}

void GraphiItemCtrl::OnLineChanged( int iKey, QLineF oLine )
{
	QGraphicsLineItem* pItem = map_LineItems.value(iKey);
	
	if(!pItem)
		return;

	pItem->setLine(oLine);
}

void GraphiItemCtrl::OnGraphicsScale( bool bZoomIn )
{

	 double dScaleFactor = 1.1;
	
	if(bZoomIn)
	{
		p_GraphicView->scale(dScaleFactor,dScaleFactor);
		 
		d_Scale += 0.1;
		
	}
	else
	{
		p_GraphicView->scale(1.0/dScaleFactor,1.0/dScaleFactor);
		QRectF imageRect = rect();
		d_Scale -= 0.1;

	}
	spin_Zoom->setValue(d_Scale);
	

	

}

void GraphiItemCtrl::OnButtonSelected( QAbstractButton * button )
{
	if(button == rdo_Select)
	{
		
		i_ActivityMode = ACTIVTITY_MODE_SELECT;
		p_GraphicView->setInteractive(false);
		p_GraphicView->setDragMode(QGraphicsView::ScrollHandDrag);
		frm_ClrSelection->setEnabled(false);
		frm_ItemSelection->setEnabled(false);
		frm_SizeSelection->setEnabled(false);
		lbl_Coordinates->setText("");
		
	}
	else if (button == rdo_Draw)
	{
		i_ActivityMode = ACTIVTITY_MODE_DRAW;
		p_GraphicView->setInteractive(true);
		p_GraphicView->setDragMode(QGraphicsView::NoDrag);
		
		frm_ClrSelection->setEnabled(true);
		frm_ItemSelection->setEnabled(true);
		frm_SizeSelection->setEnabled(true);
		
	}
	else if (button == rdo_Erase)
	{
		i_ActivityMode = ACTIVTITY_MODE_DRAW;
		p_GraphicView->setInteractive(true);
		p_GraphicView->setDragMode(QGraphicsView::NoDrag);
		frm_ClrSelection->setEnabled(false);
		frm_ItemSelection->setEnabled(false);
		frm_SizeSelection->setEnabled(false);
	}
	else if (button == rdo_Point)
	{
		i_ActivityMode = ACTIVITY_MODE_POINT;
		p_GraphicView->setInteractive(true);
		p_GraphicView->setDragMode(QGraphicsView::NoDrag);
		frm_ClrSelection->setEnabled(false);
		frm_ItemSelection->setEnabled(false);
		frm_SizeSelection->setEnabled(false);

	}
	setCursor(Qt::ArrowCursor);
}

void GraphiItemCtrl::OnDrawTypeChanged( QAbstractButton * button )
{
	if(button == btn_Line)
	{
		i_CurrentType = ITM_TYPE_LINE;
	}
	else if (button == btn_Rectangle)
	{
		i_CurrentType = ITM_TYPE_RECTANGLE;
	}
	else if (button == btn_Elipse)
	{
		i_CurrentType = ITM_TYPE_ELIPSE;
	}
}

void GraphiItemCtrl::OpenColorPallet()
{
	
	p_ColorDialog->open();
}

void GraphiItemCtrl::ColorSelected( QColor eColor )
{
	e_CurrentColor = eColor;
	o_CurrentPen.setColor(e_CurrentColor);

	QPalette oPlaet;
	oPlaet.setColor(QPalette::Background, e_CurrentColor);

	
	lbl_SelColor->setPalette(oPlaet);
}

void GraphiItemCtrl::OnLineWidth( int iWidth )
{
	i_CurrentWidth = iWidth;
	o_CurrentPen.setWidth(iWidth);
}

void GraphiItemCtrl::OnZoomChanged( QAbstractButton * button )
{
	if(button == btn_ZoomIn)
	{
		OnGraphicsScale(true);
	}
	else
	{
		OnGraphicsScale(false);
	}
}

void GraphiItemCtrl::OnMouseMoveEvent( QPointF oPoint )
{
	QString sValue;
	sValue.sprintf("%f x %f", oPoint.x(),oPoint.y());
	lbl_Coordinates->setText(sValue);
}

void GraphiItemCtrl::OnZoomValueChanged( double dScale)
{
	QTransform oTransform = QTransform::fromScale(dScale, dScale);
	p_GraphicView->setTransform(oTransform);
}






