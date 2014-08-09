#ifndef CONFIGURATIONWND_H
#define CONFIGURATIONWND_H

#include <QWidget>
#include <QLineF>
#include <QRectF>
#include <QMap>
#include "ui_ConfigurationWnd.h"

#define TBL_LINE_NAME	0
#define TBL_LINE_X1		1
#define TBL_LINE_Y1		2
#define TBL_LINE_X2		3
#define TBL_LINE_Y2		4


class ConfigurationWnd : public QWidget, public Ui::ConfigurationWnd
{
	Q_OBJECT

public:
	ConfigurationWnd(QWidget *parent = 0);
	~ConfigurationWnd();

protected:

	void InsertLineTableRow(QTableWidget* pTable, int iRow,QLineF oLine);
	QMap<int,QLineF> map_Lines;
	QMap<int,QRectF> map_Rects;
	QMap<int,QRectF> map_Elipses;
	bool b_Adding;

signals:
	void NotifyLineChanged(int iKey,QLineF oLine);

public slots:
	void OnAllLines(QMap<int,QLineF> mapLines);

	void AddRowToLineTable( int iKey, int i, QLineF &oLine );

	void OnLineAdded(int iKey,QLineF oLine);
	void OnLineRemove(int iKey);

	void OnAllRects(QMap<int,QRectF> mapRects);
	void OnRectAdded(int iKey,QRectF oRect);
	void OnRectRemoved(int iKey);

	void OnAllElipses(QMap<int,QRectF> mapRects);
	void OnElipseAdded(int iKey, QRectF oRect);
	void OnElipseRemoved(int iKey);

	void OnLineTableItemChanged(QTableWidgetItem* pItem);
	

};

#endif // CONFIGURATIONWND_H
