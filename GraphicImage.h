#ifndef __GraphicImage__
#define __GraphicImage__

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneWheelEvent>

class GraphiItemCtrl;

class GraphicImage :
	public QGraphicsPixmapItem
{
public:
	GraphicImage(QPixmap oImage,GraphiItemCtrl* pParent);
	virtual void	mousePressEvent ( QGraphicsSceneMouseEvent * pEvent );

	virtual void	mouseReleaseEvent ( QGraphicsSceneMouseEvent * pEvent );
	virtual void	wheelEvent ( QGraphicsSceneWheelEvent * pEvent );

	//virtual void	mouseMoveEvent(QGraphicsSceneMouseEvent * event);

	virtual void	hoverMoveEvent(QGraphicsSceneHoverEvent * event);
	virtual void	hoverLeaveEvent(QGraphicsSceneHoverEvent * event);

	virtual ~GraphicImage(void);

private:
	GraphiItemCtrl* p_Parent;
};

#endif // __GraphicImage__

