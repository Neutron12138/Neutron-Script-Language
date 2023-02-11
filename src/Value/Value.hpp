#ifndef __NEUTRONSL_VALUE_VALUE_HPP__
#define __NEUTRONSL_VALUE_VALUE_HPP__

#include <ntl/NTL.hpp>
#include "../Types/TypeTraits.hpp"

namespace nsl
{
    namespace Value
    {
        /// @brief 值类型
        class Value : public ntl::Object
        {
        public:
            using SelfType = Value;
            using ParentType = ntl::Object;

        protected:
            /// @brief 类型特点
            ntl::SharedPointer<Types::TypeTraits> m_type_traits;

        public:
            Value() = default;
            explicit Value(const SelfType &from) = default;
            ~Value() override = default;
        };

    } // namespace Value

} // namespace nsl

#endif