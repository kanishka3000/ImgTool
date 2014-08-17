#include "GraphicImageView.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <GraphiItemCtrl.h>
#include <QShortcut>
GraphicImageView::GraphicImageView(QWidget *parent)
	: QGraphicsView(parent)
{
	p_Parent = NULL;
	//setContextMenuPolicy(Qt::CustomContextMenu);

	QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+o"), this);
	QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(OnClick()));
}

GraphicImageView::~GraphicImageView()
{

}

//void GraphicImageView::mousePressEvent( QMouseEvent * pEvent )
//{
//	QString sStrng;
//	sStrng.sprintf("%f x %f",pEvent->localPos().x(),pEvent->localPos().y());
//	//QMessageBox::information(this,sStrng,sStrng);
//	//p_Parent->UpdateCoordinates(sStrng);
//	QGraphicsView::mousePressEvent(pEvent);
//}
//
//void GraphicImageView::mouseReleaseEvent( QMouseEvent * pEvent )
//{
//	QGraphicsView::mouseReleaseEvent(pEvent);
//}



void GraphicImageView::contextMenuEvent( QGraphicsSceneContextMenuEvent * event )
{

}

void GraphicImageView::OnClick()
{

}
