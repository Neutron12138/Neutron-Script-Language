#ifndef __NEUTRONSL_TYPE_TYPE_HPP__
#define __NEUTRONSL_TYPE_TYPE_HPP__

#include <ntl/NTL.hpp>
#include "../Base/ScriptMisc.hpp"

namespace nsl
{
    namespace Type
    {
        /// @brief 类型
        class Type : public ntl::Object
        {
        public:
            using SelfType = Type;
            using ParentType = ntl::Object;

        protected:
            /// @brief 类型名
            ntl::String m_type_name;

            /// @brief 类型特点
            TypeTraitsHolder m_type_traits;

        public:
            Type() = default;
            explicit Type(const ntl::String &name, const TypeTraitsHolder &traits);
            explicit Type(const SelfType &from) = default;
            ~Type() override { std::cout << "~Type" << std::endl; } // = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 获取类型名
            /// @return 类型名
            const ntl::String &get_type_name() const;

            /// @brief 获取类型特点
            /// @return 类型特点
            const TypeTraitsHolder &get_type_traits() const;
        };

    } // namespace Type

} // namespace nsl

#endif