#ifndef __PARAM_CONTROL_H__
#define __PARAM_CONTROL_H__

#include "global.h"
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>


namespace base
{
    namespace param
    {

        class ParamControl
        {
        
        public:
            ParamControl();

            virtual int getInt()=0;
            virtual double getDouble()=0;
            virtual std::string getString()=0;
            virtual bool getBool(){BOOST_ASSERT(0);}

            virtual void setInt(const int data)=0;
            virtual void setDouble(const double data)=0;
            virtual void setString(const std::string& data)=0;
            virtual void setBool(const bool data){BOOST_ASSERT(0);}

            virtual void attachToLayout(const std::string& name, QVBoxLayout* blayout)=0;

        protected:
            boost::shared_ptr<QLabel> _label;
            boost::shared_ptr<QHBoxLayout> _hlayout;
        };

        typedef boost::shared_ptr<ParamControl> ParamControlPtr;

        class ParamControlTextBox: public ParamControl
        {
        public:
            ParamControlTextBox();

            virtual int getInt();
            virtual double getDouble();
            virtual std::string getString();

            virtual void setInt(const int data);
            virtual void setDouble(const double data);
            virtual void setString(const std::string& data);
            virtual void attachToLayout(const std::string& name, QVBoxLayout* blayout);

        private:
            boost::shared_ptr<QLineEdit> _line_edit;
        };



        class ParamControlScrollBar: public ParamControl
        {
        public:
            ParamControlScrollBar();

            virtual int getInt();
            virtual double getDouble();
            virtual std::string getString();

            virtual void setInt(const int data);
            virtual void setDouble(const double data);
            virtual void setString(const std::string& data);
            virtual void attachToLayout(const std::string& name, QVBoxLayout* blayout);

            void setScrollBarProperties(const int min, const int max, const int step);

        private:
            boost::shared_ptr<QScrollBar> _scroll_bar;
        };


        class ParamControlCheckBox: public ParamControl
        {
        public:
            ParamControlCheckBox();

            virtual int getInt(){BOOST_ASSERT(0);}
            virtual double getDouble(){BOOST_ASSERT(0);}
            virtual std::string getString(){BOOST_ASSERT(0);}

            virtual void setInt(const int data){BOOST_ASSERT(0);}
            virtual void setDouble(const double data){BOOST_ASSERT(0);}
            virtual void setString(const std::string& data){BOOST_ASSERT(0);}

             virtual void setBool(const bool data);
             virtual bool getBool();

            virtual void attachToLayout(const std::string& name, QVBoxLayout* blayout);
           

        private:
            boost::shared_ptr<QCheckBox> _check_box;
        };


    }
}


#endif