#ifndef __PARAMETER_H__
#define __PARAMETER_H__

#include "global.h"


namespace base
{
    namespace param
    {
        class Parameter
        {
        public:
            Parameter();
            enum types{INT8, UINT8, INT32, UINT32, F32, D64, BOOL, STR};

            types gettype();
            void set(const int8_t data);
            void set(const uint8_t data);
            void set(const int32_t data);
            void set(const uint32_t data);
            void set(const float data);
            void set(const double data);
            void set(const bool data);
            void set(const std::string& data);

            void bind(int8_t* data);
            void bind(uint8_t* data);
            void bind(int32_t* data);
            void bind(uint32_t* data);
            void bind(float* data);
            void bind(double* data);
            void bind(bool* data);
            void bind(std::string* data);

            void get(int8_t& data);
            void get(uint8_t& data);
            void get(int32_t& data);
            void get(uint32_t& data);
            void get(float& data);
            void get(double& data);
            void get(bool& data);
            void get(std::string& data);
        private:
            types _data_type;
            
            int8_t* _data_8;
            uint8_t* _data_8u;
            int32_t* _data_32;
            uint32_t* _data_32u;
            float* _dataf;
            double* _datad;
            bool* _datab;
            std::string* _datas;
            

        public:
            


        };

        typedef boost::shared_ptr<Parameter> ParameterPtr;

     


    }
}



#endif