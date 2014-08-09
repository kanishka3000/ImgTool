#include "stdafx.h"
#include "ImageTool.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ImageTool w;
	w.show();
	return a.exec();
}
