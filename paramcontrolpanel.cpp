#include "base/param/paramcontrolpanel.h"

base::param::ParamControlPanelWidget::ParamControlPanelWidget():
blayout(new QVBoxLayout())
{


}

void base::param::ParamControlPanelWidget::bind( bool* val, const std::string& name )
{
    ParamPair tuple;
    tuple.parameter = ParameterPtr(new Parameter());
    tuple.parametercontrol = ParamControlPtr(new ParamControlCheckBox());
    tuple.parameter->bind(val);
    tuple.parametercontrol->attachToLayout(name, blayout);
    _parametersandcontrols.insert(std::pair<std::string, ParamPair>(name, tuple));
 
}

void base::param::ParamControlPanelWidget::populate()
{
    setLayout(blayout);
}

void base::param::ParamControlPanelWidget::updateBindedDataStructure()
{
    
    std::map<std::string, ParamPair>::iterator ite;

    for(ite = _parametersandcontrols.begin(); ite!=_parametersandcontrols.end(); ++ite)
    {
        Parameter& param = *ite->second.parameter;
        ParamControl& paramcontrol = *ite->second.parametercontrol;

        switch(param.gettype())
        {
        case Parameter::INT8:
            param.set((int8_t)paramcontrol.getInt());
            break;
        case Parameter::UINT8:
            param.set((uint8_t)paramcontrol.getInt());
            break;

        case Parameter::INT32:
            param.set((int32_t)paramcontrol.getInt());
            break;

        case Parameter::UINT32:
            param.set((uint32_t)paramcontrol.getInt());
            break;

        case Parameter::F32:
            param.set((float)paramcontrol.getDouble());
            break;
        
        case Parameter::D64:
            param.set(paramcontrol.getDouble());
            break;

        case Parameter::STR:
            param.set(paramcontrol.getString());
            break;

        case Parameter::BOOL:
            param.set(paramcontrol.getBool());
            break;
            


        default:
            BOOST_ASSERT(0);

        }

        

    }

}

void base::param::ParamControlPanelWidget::updateGuiFromDataStructure()
{
    std::map<std::string, ParamPair>::iterator ite;

    for(ite = _parametersandcontrols.begin(); ite!=_parametersandcontrols.end(); ++ite)
    {
        Parameter& param = *ite->second.parameter;
        ParamControl& paramcontrol = *ite->second.parametercontrol;

        switch(param.gettype())
        {
        case Parameter::INT8:
            {
                int8_t data;
                param.get(data);
                paramcontrol.setInt((int)data);
            }
           
            break;
        case Parameter::UINT8:
            {
                uint8_t data;
                param.get(data);
                paramcontrol.setInt((int)data);
            }
          
            break;

        case Parameter::INT32:
            {
                int32_t data;
                param.get(data);
                paramcontrol.setInt((int)data);
            }
           
            break;

        case Parameter::UINT32:
            {
                uint32_t data;
                param.get(data);
                paramcontrol.setInt((int)data);
            }
            
            break;

        case Parameter::F32:
            {
                float data;
                param.get(data);
                paramcontrol.setDouble((double)data);
            }
            
            break;

        case Parameter::D64:
            {
                double data;
                param.get(data);
                paramcontrol.setDouble(data);
            }
            
            break;

        case Parameter::STR:
            {
                std::string data;
                param.get(data);
                paramcontrol.setString(data);
            }
            

        case Parameter::BOOL:
            {
                bool data;
                param.get(data);
                paramcontrol.setBool(data);
            }
            
            break;



        default:
            BOOST_ASSERT(0);

        }



    }

}


