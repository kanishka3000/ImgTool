#include "base/param/parameter.h"

base::param::Parameter::Parameter():
_data_8(NULL),
_data_8u(NULL),
_data_32(NULL),
_data_32u(NULL),
_dataf(NULL),
_datad(NULL),
_datab(NULL),
_datas(NULL)
{

}

base::param::Parameter::types base::param::Parameter::gettype()
{
    return _data_type;
}



void base::param::Parameter::set(const int8_t data)
{
    BOOST_ASSERT(_data_type == INT8);
    *_data_8 = data;

}


void base::param::Parameter::set(const uint8_t data)
{
    BOOST_ASSERT(_data_type == UINT8);
    *_data_8u = data;

}


void base::param::Parameter::set(const int32_t data)
{
    BOOST_ASSERT(_data_type == INT32);
    *_data_32 = data;

}


void base::param::Parameter::set(const uint32_t data)
{
    BOOST_ASSERT(_data_type == UINT32);
    *_data_32u = data;

}


void base::param::Parameter::set(const float data)
{
    BOOST_ASSERT(_data_type == F32);
    *_dataf = data;

}


void base::param::Parameter::set(const double data)
{
    BOOST_ASSERT(_data_type == D64);
    *_datad = data;

}


void base::param::Parameter::set(const bool data)
{
    BOOST_ASSERT(_data_type == BOOL);
    *_datab = data;

}


void base::param::Parameter::set(const std::string& data)
{
    BOOST_ASSERT(_data_type == STR);
    *_datas = data;

}

////////////////Get methods//////////////////////////////////
void base::param::Parameter::get(int8_t& data)
{
    BOOST_ASSERT(_data_type == INT8);
    data = *_data_8;

}


void base::param::Parameter::get(uint8_t& data)
{
    BOOST_ASSERT(_data_type == UINT8);
    data = *_data_8u;

}


void base::param::Parameter::get(int32_t& data)
{
    BOOST_ASSERT(_data_type == INT32);
    data = *_data_32;

}


void base::param::Parameter::get(uint32_t& data)
{
    BOOST_ASSERT(_data_type == UINT32);
    data = *_data_32u;

}


void base::param::Parameter::get(float& data)
{
    BOOST_ASSERT(_data_type == F32);
    data = *_dataf;

}


void base::param::Parameter::get(double& data)
{
    BOOST_ASSERT(_data_type == D64);
    data = *_datad;

}


void base::param::Parameter::get(bool& data)
{
    BOOST_ASSERT(_data_type == BOOL);
    data = *_datab;

}


void base::param::Parameter::get(std::string& data)
{
    BOOST_ASSERT(_data_type == STR);
    data = *_datas;

}


////////////////////////////////////////////////////////////


void base::param::Parameter::bind(int8_t* data)
{
    _data_type = INT8;
    _data_8 = data;

}


void base::param::Parameter::bind(uint8_t* data)
{
    _data_type = UINT8;
    _data_8u = data;

}


void base::param::Parameter::bind(int32_t* data)
{
    _data_type = INT32;
    _data_32 = data;

}


void base::param::Parameter::bind(uint32_t* data)
{
    _data_type = UINT32;
    _data_32u = data;

}


void base::param::Parameter::bind(float* data)
{
    _data_type = F32;
    _dataf = data;

}


void base::param::Parameter::bind(double* data)
{
    _data_type = D64;
    _datad = data;

}


void base::param::Parameter::bind(bool* data)
{
    _data_type = BOOL;
    _datab = data;

}


void base::param::Parameter::bind(std::string* data)
{
    _data_type = STR;
    _datas = data;

}
