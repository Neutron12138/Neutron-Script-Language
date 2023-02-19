#ifndef __NEUTRONSL_EXECUTION_VARIABLEMANAGER_HPP__
#define __NEUTRONSL_EXECUTION_VARIABLEMANAGER_HPP__

#include <map>
#include <ntl/NTL.hpp>
#include "Variable.hpp"

namespace nsl
{
    namespace Execution
    {
        /// @brief 变量管理器
        class VariableManager : public ntl::Object
        {
        public:
            using SelfType = VariableManager;
            using ParentType = ntl::Object;

        protected:
            /// @brief 储存变量的容器
            std::map<ntl::String, Variable> m_variables;

        public:
            VariableManager() = default;
            explicit VariableManager(const SelfType &from) = default;
            ~VariableManager() override = default;

        public:
            SelfType &operator=(const SelfType &from) = default;
            Variable &operator[](const ntl::String &name);
            const Variable &operator[](const ntl::String &name) const;

        public:
            /// @brief 获取所有变量
            /// @return 所有变量
            const std::map<ntl::String, Variable> &get_variables() const;

            /// @brief 获取变量
            /// @param name 变量名
            /// @return 变量
            Variable &get_variable(const ntl::String &name);

            /// @brief 获取变量
            /// @param name 变量名
            /// @return 变量
            const Variable &get_variable(const ntl::String &name) const;

            /// @brief 获取变量是否已经存在
            /// @param name 变量名
            /// @return 变量是否已经存在
            bool is_existed(const ntl::String &name) const;

        public:
            /// @brief 添加一个变量
            /// @param name 变量名
            /// @param variable 变量
            virtual void add_variable(const ntl::String &name, const Variable &variable);

            /// @brief 移除一个变量
            /// @param name 变量名
            virtual void remove_variable(const ntl::String &name);

            /// @brief 检查变量名是否合法
            /// @param name 变量名
            /// @return 变量名是否合法
            virtual bool check_name(const ntl::String &name) const;
        };
    } // namespace Execution

} // namespace nsl

#endif