#include "base/param/paramcontrol.h"



base::param::ParamControl::ParamControl():
_label(new QLabel()),
_hlayout(new QHBoxLayout())
{

}

base::param::ParamControlTextBox::ParamControlTextBox():
_line_edit(new QLineEdit())
{
    
}

int base::param::ParamControlTextBox::getInt()
{
    return _line_edit->text().toInt();
}

double base::param::ParamControlTextBox::getDouble()
{
    return _line_edit->text().toDouble();
}

std::string base::param::ParamControlTextBox::getString()
{
    return _line_edit->text().toStdString();
}

void base::param::ParamControlTextBox::setInt( const int data )
{
    _line_edit->setText(QString::number(data));
}

void base::param::ParamControlTextBox::setDouble( const double data )
{
    _line_edit->setText(QString::number(data));
}

void base::param::ParamControlTextBox::setString( const std::string& data )
{
    _line_edit->setText(QString(data.c_str()));
}

void base::param::ParamControlTextBox::attachToLayout(const std::string& name, QVBoxLayout* blayout )
{
    _label->setText(QString(name.c_str()));

    _hlayout->addWidget(_line_edit.get());
    _hlayout->addWidget(_label.get());
    blayout->addLayout(_hlayout.get());
}

////////////////////////Scroll Bar///////////////////////////////////


base::param::ParamControlScrollBar::ParamControlScrollBar():
_scroll_bar(new QScrollBar())
{
    _scroll_bar->setOrientation(Qt::Horizontal);
}

int base::param::ParamControlScrollBar::getInt()
{
    return _scroll_bar->value();
}

double base::param::ParamControlScrollBar::getDouble()
{
    BOOST_ASSERT(0);

    return 0;
}

std::string base::param::ParamControlScrollBar::getString()
{
    BOOST_ASSERT(0);
    return std::string();
}

void base::param::ParamControlScrollBar::setInt( const int data )
{
    _scroll_bar->setValue(data);
}

void base::param::ParamControlScrollBar::setDouble( const double data )
{
    BOOST_ASSERT(0);
}

void base::param::ParamControlScrollBar::setString( const std::string& data )
{
    BOOST_ASSERT(0);
}

void base::param::ParamControlScrollBar::attachToLayout(const std::string& name, QVBoxLayout* blayout )
{
    _label->setText(QString(name.c_str()));

    _hlayout->addWidget(_scroll_bar.get());
    _hlayout->addWidget(_label.get());
    blayout->addLayout(_hlayout.get());
}

void base::param::ParamControlScrollBar::setScrollBarProperties( const int min, const int max, const int step )
{
    _scroll_bar->setRange(min, max);
    _scroll_bar->setPageStep(step);
}


/////////////////////////Check Box//////////////////////////////////////////////


base::param::ParamControlCheckBox::ParamControlCheckBox():
_check_box(new QCheckBox())
{
   
}



void base::param::ParamControlCheckBox::attachToLayout(const std::string& name, QVBoxLayout* blayout )
{
    _label->setText(QString(name.c_str()));

    _hlayout->addWidget(_check_box.get());
    _hlayout->addWidget(_label.get());
    blayout->addLayout(_hlayout.get());
}

void base::param::ParamControlCheckBox::setBool( const bool data )
{
    if(data)
        _check_box->setCheckState(Qt::Checked);
    else
        _check_box->setCheckState(Qt::Unchecked);

}

bool base::param::ParamControlCheckBox::getBool()
{
    if(_check_box->checkState() == Qt::Checked)
        return true;
    else
        return false;

}
