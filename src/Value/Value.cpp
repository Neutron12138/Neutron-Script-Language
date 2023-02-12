#ifndef __NEUTRONSL_VALUE_VALUE_CPP__
#define __NEUTRONSL_VALUE_VALUE_CPP__

#include "Value.hpp"

namespace nsl
{
    namespace Value
    {
        Value::Value(
            const TypeHolder &type)
            : m_type(type) {}

        const TypeHolder &
        Value::get_type() const
        {
            return m_type;
        }
    } // namespace Value

} // namespace nsl

#endif