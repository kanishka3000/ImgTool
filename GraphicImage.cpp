#include "stdafx.h"
#include "GraphicImage.h"
#include <GraphiItemCtrl.h>

GraphicImage::GraphicImage(QPixmap oImage,GraphiItemCtrl* pParent)
	:QGraphicsPixmapItem(oImage),p_Parent(pParent)
{
	//setFlags(QGraphicsItem::ItemIsMovable);
	setAcceptHoverEvents(true);
}


GraphicImage::~GraphicImage(void)
{
}

void GraphicImage::mousePressEvent( QGraphicsSceneMouseEvent * pEvent )
{
	
	//p_Parent->OnMouseClickEvent(mapToScene(pEvent->pos()));
	p_Parent->OnMouseClickEvent(pEvent->pos());
	pEvent->accept();
	//QGraphicsPixmapItem::mousePressEvent(pEvent);
}

void GraphicImage::wheelEvent( QGraphicsSceneWheelEvent * pEvent )
{
	
	double dCurrentScale = scale();

	if(pEvent->delta() > 0)
	{
		//p_Parent->OnGraphicsScale(true);
		//setScale(dCurrentScale + 0.1);
	}
	else
	{
		//p_Parent->OnGraphicsScale(false);
		//setScale(dCurrentScale - 0.1);
	}
	//QGraphicsPixmapItem::wheelEvent(pEvent);
}

void GraphicImage::mouseReleaseEvent( QGraphicsSceneMouseEvent * pEvent )
{
	//p_Parent->OnMouseReleaseEvent(mapToScene(pEvent->pos()));
	p_Parent->OnMouseReleaseEvent(pEvent->pos());
	QGraphicsPixmapItem::mouseReleaseEvent(pEvent);
}

//void GraphicImage::mouseMoveEvent( QGraphicsSceneMouseEvent * event )
//{
//
//}

void GraphicImage::hoverMoveEvent( QGraphicsSceneHoverEvent * event )
{
	p_Parent->OnMouseMoveEvent(mapToScene(event->pos()));
	QGraphicsPixmapItem::hoverMoveEvent(event);
}

void GraphicImage::hoverLeaveEvent( QGraphicsSceneHoverEvent * event )
{

}






