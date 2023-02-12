#ifndef __NEUTRONSL_VALUE_VALUE_HPP__
#define __NEUTRONSL_VALUE_VALUE_HPP__

#include <ntl/NTL.hpp>
#include "../Base/ScriptMisc.hpp"

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
            /// @brief 类型
            TypeHolder m_type;

        public:
            Value() = default;
            explicit Value(const TypeHolder &type);
            explicit Value(const SelfType &from) = default;
            ~Value() override = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 获取类型
            /// @return 类型
            const TypeHolder &get_type() const;
        };

    } // namespace Value

} // namespace nsl

#endif