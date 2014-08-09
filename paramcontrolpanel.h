#ifndef __PARAM_CONTROL_PANEL_H__
#define __PARAM_CONTROL_PANEL_H__


#include "base/param/parameter.h"
#include "base/param/paramcontrol.h"


namespace base
{
    namespace param
    {
        struct ParamPair
        {
            ParameterPtr parameter;
            ParamControlPtr parametercontrol;
        };
        
        class ParamControlPanelWidget : public QWidget
        {

         
        public:
            ParamControlPanelWidget();

            void updateBindedDataStructure();
            void updateGuiFromDataStructure();

            template<class T>
            void bind(T* val, const std::string& name);

            template<class T>
            void bind(T* val, T min, T max, T step, const std::string& name);

            void bind(bool* val, const std::string& name);

            void populate();

        private:

            QVBoxLayout* blayout;
            std::map<std::string, ParamPair> _parametersandcontrols;

        };

        template<class T>
        void base::param::ParamControlPanelWidget::bind( T* val, T min, T max, T step, const std::string& name )
        {
            ParamPair tuple;
            tuple.parameter = ParameterPtr(new Parameter());
            ParamControlScrollBar* scrollbar(new ParamControlScrollBar());
            tuple.parametercontrol = ParamControlPtr(scrollbar);
            tuple.parameter->bind(val);
            scrollbar->setScrollBarProperties(min, max, step);
            tuple.parametercontrol->attachToLayout(name, blayout);
            _parametersandcontrols.insert(std::pair<std::string, ParamPair>(name, tuple));
        }

        template<class T>
        void base::param::ParamControlPanelWidget::bind( T* val, const std::string& name )
        {
            ParamPair tuple;
            tuple.parameter = ParameterPtr(new Parameter());
            tuple.parametercontrol = ParamControlPtr(new ParamControlTextBox());
            tuple.parameter->bind(val);
            tuple.parametercontrol->attachToLayout(name, blayout);
            _parametersandcontrols.insert(std::pair<std::string, ParamPair>(name, tuple));
        }

    }
}


#endif