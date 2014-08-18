#include "stdafx.h"
#include "GraphicImage.h"
#include <GraphiItemCtrl.h>

GraphicImage::GraphicImage(QPixmap oImage,GraphiItemCtrl* pParent)
	:QGraphicsPixmapItem(oImage),p_Parent(pParent)
{
	setAcceptHoverEvents(true);
}


GraphicImage::~GraphicImage(void)
{
}

void GraphicImage::mousePressEvent( QGraphicsSceneMouseEvent * pEvent )
{
	
	
	p_Parent->OnMouseClickEvent(pEvent->pos());
	pEvent->accept();
	
}



void GraphicImage::mouseReleaseEvent( QGraphicsSceneMouseEvent * pEvent )
{
	
	p_Parent->OnMouseReleaseEvent(pEvent->pos());
	QGraphicsPixmapItem::mouseReleaseEvent(pEvent);
}

void GraphicImage::hoverMoveEvent( QGraphicsSceneHoverEvent * event )
{
	p_Parent->OnMouseMoveEvent(mapToScene(event->pos()));
	QGraphicsPixmapItem::hoverMoveEvent(event);
}










