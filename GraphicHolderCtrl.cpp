#include "stdafx.h"
#include "GraphicHolderCtrl.h"
#include <GraphiItemCtrl.h>
GraphicHolderCtrl::GraphicHolderCtrl(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);


	QHBoxLayout* pMainLayout = new QHBoxLayout(this);
	setLayout(pMainLayout);

	GraphiItemCtrl* pItemCtrl = new GraphiItemCtrl(this);
	pMainLayout->addWidget(pItemCtrl);

	GraphiItemCtrl* pItemCtrlw = new GraphiItemCtrl(this);
	pMainLayout->addWidget(pItemCtrlw);


}

GraphicHolderCtrl::~GraphicHolderCtrl()
{

}
