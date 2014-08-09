#ifndef GRAPHICHOLDERCTRL_H
#define GRAPHICHOLDERCTRL_H

#include <QWidget>
#include "ui_GraphicHolderCtrl.h"

class GraphicHolderCtrl : public QWidget, public Ui::GraphicHolderCtrl
{
	Q_OBJECT

public:
	GraphicHolderCtrl(QWidget *parent = 0);
	~GraphicHolderCtrl();
};

#endif // GRAPHICHOLDERCTRL_H
