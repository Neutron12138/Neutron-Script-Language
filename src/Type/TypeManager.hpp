#ifndef __NEUTRONSL_TYPE_TYPEMANAGER_HPP__
#define __NEUTRONSL_TYPE_TYPEMANAGER_HPP__

#include <ntl/NTL.hpp>
#include "../Base/ScriptMisc.hpp"

namespace nsl
{
    namespace Type
    {
        /// @brief 类型管理器
        class TypeManager : public ntl::Object
        {
        public:
            using SelfType = TypeManager;
            using ParentType = ntl::Object;

        protected:
            /// @brief 类型特点
            TypeContainer m_types;

        public:
            TypeManager();
            explicit TypeManager(const SelfType &from) = default;
            ~TypeManager() override = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 增加一个类型
            /// @param name 类型名
            /// @param type 类型
            void add_type(const ntl::String &name, const TypeHolder &type);

            /// @brief 获取类型
            /// @param type_name 类型名
            /// @return 类型
            const TypeHolder &get_type(const ntl::String &type_name) const;

            /// @brief 获取所有类型
            /// @return 类型容器
            const TypeContainer &get_types() const;
        };

    } // namespace Type

} // namespace nsl

#endif