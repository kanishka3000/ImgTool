#include "ConfigurationWnd.h"
#include <QTableWidgetItem>
#include <QTableWidget>
ConfigurationWnd::ConfigurationWnd(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	b_Adding = false;
}

ConfigurationWnd::~ConfigurationWnd()
{

}

void ConfigurationWnd::OnAllLines( QMap<int,QLineF> mapLines )
{
	b_Adding = true;
	map_Lines = mapLines;
	tbl_Lines->setRowCount(map_Lines.count());
	int i = 0;
	for(QMap<int,QLineF>::Iterator itr = map_Lines.begin(); itr!= map_Lines.end(); itr++)
	{
		int iKey = itr.key();
		QLineF oLine = *itr;
		AddRowToLineTable(iKey, i, oLine);

		i++;
	}
	b_Adding = false;
}

void ConfigurationWnd::OnLineAdded( int iKey,QLineF oLine )
{
	tbl_Lines->setRowCount(tbl_Lines->rowCount() + 1);

}

void ConfigurationWnd::OnLineRemove( int iKey )
{

}

void ConfigurationWnd::OnAllRects( QMap<int,QRectF> mapRects )
{
	map_Rects = mapRects;

}

void ConfigurationWnd::OnRectAdded( int iKey,QRectF oRect )
{

}

void ConfigurationWnd::OnRectRemoved( int iKey )
{

}

void ConfigurationWnd::OnAllElipses( QMap<int,QRectF> mapRects )
{
	map_Elipses = mapRects;
}

void ConfigurationWnd::OnElipseAdded( int iKey, QRectF oRect )
{

}

void ConfigurationWnd::OnElipseRemoved( int iKey )
{

}

void ConfigurationWnd::InsertLineTableRow( QTableWidget* pTable, int iRow,QLineF oLine )
{

}

void ConfigurationWnd::AddRowToLineTable( int iKey, int i, QLineF &oLine )
{
	QTableWidgetItem* pItem = new QTableWidgetItem(QString::number(iKey));
	tbl_Lines->setItem(i,TBL_LINE_NAME,pItem);
	QTableWidgetItem* pItemX1 = new QTableWidgetItem(QString::number(oLine.x1()));
	tbl_Lines->setItem(i,TBL_LINE_X1,pItemX1);
	QTableWidgetItem* pItemY1 = new QTableWidgetItem(QString::number(oLine.y1()));
	tbl_Lines->setItem(i,TBL_LINE_Y1,pItemY1);
	QTableWidgetItem* pItemX2 = new QTableWidgetItem(QString::number(oLine.x2()));
	tbl_Lines->setItem(i,TBL_LINE_X2,pItemX2);
	QTableWidgetItem* pItemY2 = new QTableWidgetItem(QString::number(oLine.y2()));
	tbl_Lines->setItem(i,TBL_LINE_Y2,pItemY2);
}

void ConfigurationWnd::OnLineTableItemChanged( QTableWidgetItem* pItem )
{
	if(b_Adding)
		return;

	int iRow = pItem->row();
	int iKey = tbl_Lines->item(iRow,TBL_LINE_NAME)->data(Qt::DisplayRole).toInt();

	
	double dX1 = tbl_Lines->item(iRow,TBL_LINE_X1)->data(Qt::DisplayRole).toFloat();;
	double dY1 = tbl_Lines->item(iRow,TBL_LINE_Y1)->data(Qt::DisplayRole).toFloat();;
	double dX2 = tbl_Lines->item(iRow,TBL_LINE_X2)->data(Qt::DisplayRole).toFloat();;
	double dY2 = tbl_Lines->item(iRow,TBL_LINE_Y2)->data(Qt::DisplayRole).toFloat();;
	QLineF oLine(dX1,dY1,dX2,dY2);

	emit NotifyLineChanged(iKey, oLine);

}

