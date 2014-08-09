#include "stdafx.h"
#include "GraphicImage.h"
#include <GraphiItemCtrl.h>

GraphicImage::GraphicImage(QPixmap oImage,GraphiItemCtrl* pParent)
	:QGraphicsPixmapItem(oImage),p_Parent(pParent)
{
	//setFlags(QGraphicsItem::ItemIsMovable);
}


GraphicImage::~GraphicImage(void)
{
}

void GraphicImage::mousePressEvent( QGraphicsSceneMouseEvent * pEvent )
{
	
	p_Parent->OnMouseClickEvent(mapToScene(pEvent->pos()));
	//pEvent->accept();
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
	p_Parent->OnMouseReleaseEvent(mapToScene(pEvent->pos()));
	QGraphicsPixmapItem::mouseReleaseEvent(pEvent);
}




