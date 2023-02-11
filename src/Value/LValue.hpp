#ifndef __NEUTRONSL_VALUE_LVALUE_HPP__
#define __NEUTRONSL_VALUE_LVALUE_HPP__

#include "Value.hpp"

namespace nsl
{
    namespace Value
    {
        class LValue : public Value
        {
        public:
            using SelfType = LValue;
            using ParentType = Value;

        public:
        };

    } // namespace Value

} // namespace nsl

#endif