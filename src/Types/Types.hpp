#ifndef __NEUTRONSL_TYPE_TYPES_HPP__
#define __NEUTRONSL_TYPE_TYPES_HPP__

#include <ntl/NTL.hpp>
#include "../Base/ScriptMisc.hpp"

namespace nsl
{
    namespace Types
    {
        /// @brief 储存类型
        class Types : public ntl::Object
        {
        public:
            using SelfType = Types;
            using ParentType = ntl::Object;

        protected:
            /// @brief 类型特点
            TypeTraitsContainer m_type_traits;

        public:
            Types();
            explicit Types(const SelfType &from) = default;
            ~Types() override = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 增加一个类型
            /// @param type_name 类型名
            /// @param type_traits 类型特点
            void add_type(const ntl::String &type_name, const TypeTraitsHolder &type_traits);

            /// @brief 获取类型
            /// @param type_name 类型名
            /// @return 类型特点
            const TypeTraitsHolder &get_type(const ntl::String &type_name) const;

            /// @brief 获取所有类型
            /// @return 类型特点容器
            const TypeTraitsContainer &get_types() const;
        };

    } // namespace Types

} // namespace nsl

#endif