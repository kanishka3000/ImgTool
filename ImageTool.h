#ifndef IMAGETOOL_H
#define IMAGETOOL_H

#include <QtWidgets/QMainWindow>
#include "ui_ImageTool.h"

class ImageTool : public QMainWindow
{
	Q_OBJECT

public:
	ImageTool(QWidget *parent = 0);
	~ImageTool();

private:
	Ui::ImageToolClass ui;
};

#endif // IMAGETOOL_H
