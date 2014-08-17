#ifndef GRAPHICIMAGEVIEW_H
#define GRAPHICIMAGEVIEW_H

#include <QGraphicsView>
class GraphiItemCtrl;
class GraphicImageView : public QGraphicsView
{
	Q_OBJECT

public:
	GraphicImageView(QWidget *parent);
	~GraphicImageView();

	virtual void	mousePressEvent ( QMouseEvent * pEvent );
	virtual void	mouseReleaseEvent ( QMouseEvent * pEvent );
	void SetParent(GraphiItemCtrl* pParent){p_Parent = pParent;};
private:
	GraphiItemCtrl* p_Parent;
};

#endif // GRAPHICIMAGEVIEW_H
