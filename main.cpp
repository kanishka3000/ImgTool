#include "stdafx.h"

#include <GraphicHolderCtrl.h>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GraphicHolderCtrl oHolder;
	oHolder.show();
	return a.exec();
}
