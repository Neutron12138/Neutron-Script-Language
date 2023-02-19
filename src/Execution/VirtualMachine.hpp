#ifndef __NEUTRONSL_EXECUTION_VIRTUALMACHINE_HPP__
#define __NEUTRONSL_EXECUTION_VIRTUALMACHINE_HPP__

#include <vector>
#include <ntl/NTL.hpp>
#include "Instruction.hpp"
#include "Variable/VariableManager.hpp"

namespace nsl
{
    namespace Execution
    {
        /// @brief 虚拟机
        class VirtualMachine : public ntl::Object
        {
        public:
            using SelfType = VirtualMachine;
            using ParentType = ntl::Object;

        protected:
            /// @brief 全局变量
            VariableManager m_global_variables;

            /// @brief 指令数组
            std::vector<Instruction> m_instructions;

            /// @brief 缓存变量
            std::vector<Variable> m_temp_variables;

        public:
            VirtualMachine() = default;
            explicit VirtualMachine(const SelfType &from) = default;
            ~VirtualMachine() override = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 获取全局变量
            /// @return 全局变量
            const VariableManager &get_global_variables() const;

            /// @brief 获取指令
            /// @return 指令
            const std::vector<Instruction> &get_instructions() const;

            /// @brief 获取缓存变量
            /// @return 缓存变量
            const std::vector<Variable> &get_temp_variables() const;

            /// @brief 获取缓存变量顶端
            /// @return 缓存变量顶端
            Variable &get_temp_top();

            /// @brief 获取缓存变量顶端
            /// @return 缓存变量顶端
            const Variable &get_temp_top() const;

        public:
            /// @brief 加载指令
            /// @param instructions 指令
            virtual void load_instructions(const std::vector<Instruction> &instructions);

            /// @brief 运行
            virtual void execute();

        public:
            virtual void operation_none(const ntl::String &argument);
            virtual void operation_reset_temp(const ntl::String &argument);
            virtual void operation_load_val(const ntl::String &argument);
            virtual void operation_load_var(const ntl::String &argument);
            virtual void operation_store_var(const ntl::String &argument);
            virtual void operation_remove_var(const ntl::String &argument);

        public:
            /// @brief 解析一个值
            /// @param value 值
            /// @return 结果
            static Variable parse_value(const ntl::String &value);

            /// @brief 释放一个变量
            /// @param variable 要释放的变量
            static void free_variable(Variable &variable);
        };

    } // namespace Execution

} // namespace nsl

#endif