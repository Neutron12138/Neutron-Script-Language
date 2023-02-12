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

        protected:
            /// @brief 变量的内存
            MemoryPointer m_memory;

        public:
        };

    } // namespace Value

} // namespace nsl

#endif