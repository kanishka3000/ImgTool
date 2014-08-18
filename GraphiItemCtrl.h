#ifndef GRAPHIITEMCTRL_H
#define GRAPHIITEMCTRL_H

#define ITM_LINE	"Line"
#define ITM_ELIPSE	"Elipse"
#define ITM_RECTANGLE	"Rectangle"

#define ITM_TYPE_LINE	6
#define ITM_TYPE_ELIPSE	4
#define ITM_TYPE_RECTANGLE	3

#define ACTIVTITY_MODE_DRAW		1
#define ACTIVTITY_MODE_SELECT	2
#define ACTIVITY_MODE_POINT		3

#define CUSTDATA_KEY	1
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <GraphicImage.h>
#include <QButtonGroup>
#include "ui_GraphiItemCtrl.h"
class QColorDialog;
class GraphiItemCtrl :public QWidget, public Ui::GraphiItemCtrl
{
	Q_OBJECT

public:
	
	GraphiItemCtrl( QWidget *parent = 0);
	~GraphiItemCtrl();

	virtual void paintEvent ( QPaintEvent * event );
	virtual void OnMouseClickEvent(QPointF oPoint);
	virtual void OnMouseReleaseEvent(QPointF oPoint);
	virtual void OnMouseMoveEvent(QPointF oPoint);
	virtual void OnGraphicsScale(bool bZoomIn);
	void UpdateCoordinates(QString sMsg){lbl_Coordinates->setText(sMsg);};
	void OnRemoveEvent();
	void OnDrawEvent();

	int GetNextItemKey();
	GraphicImage* p_Image;
	QGraphicsScene o_ItemScene;
	
	QPointF o_PointA;
	QPointF o_PointB;

	bool b_InitDraw;
	QString s_CurrentItem;
	int i_CurrentType;
	QButtonGroup o_MainActivity;
	QButtonGroup o_DrawType;
	QButtonGroup o_Zooming;

private:
	QMap<int,QLineF> map_Lines;
	QMap<int,QRectF> map_Rects;
	QMap<int,QRectF> map_Elipses;

	QMap<int , QGraphicsLineItem*> map_LineItems;
	QGraphicsItemGroup o_Group;
	int i_LastItemKey;
	QColor e_CurrentColor;
	QPen	o_CurrentPen;
	int i_CurrentWidth;
	QColorDialog* p_ColorDialog;
	int i_ActivityMode;
	QRectF o_OrigianlRect;
	qreal d_Scale;
signals:
	//Notifies all lines at an initiation
	void NotifyAllLines(QMap<int,QLineF> mapLines);//Optimization note: if large number should prevent coping
	void NotifyLineAdded(int iKey,QLineF oLine);
	void NotifyLineRemove(int iKey);

	void NotifyAllRects(QMap<int,QRectF> mapRects);
	void NotifyRectAdded(int iKey,QRectF oRect);
	void NotifyRectRemoved(int iKey);

	void NotifyAllElipses(QMap<int,QRectF> mapRects);
	void NotifyElipseAdded(int iKey, QRectF oRect);
	void NotifyElipseRemoved(int iKey);


public slots:
	void OnDrawItemChanged(QString sItemType);
	void OnDrawTypeChanged(QAbstractButton * button);
	void OnLineChanged(int iKey, QLineF oLine);
	void OnButtonSelected(QAbstractButton * button);
	void OnZoomChanged(QAbstractButton * button);
	void OpenConfigurationWnd();
	void OpenColorPallet();
	void ColorSelected(QColor eColor);
	void OnLineWidth(int iWidth);
	void OnZoomValueChanged(double dScale);
};

#endif // GRAPHIITEMCTRL_H
