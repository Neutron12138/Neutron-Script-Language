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
            /// @brief 变量
            VariableManager m_variable;

            /// @brief 指令数组
            std::vector<Instruction> m_instructions;

        public:
            VirtualMachine() = default;
            explicit VirtualMachine(const SelfType &from) = default;
            ~VirtualMachine() override = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
        public:
            virtual void operation_none(const ntl::String &argument);
            virtual void operation_load_val(const ntl::String &argument);
            virtual void operation_load_var(const ntl::String &argument);
            virtual void operation_store_var(const ntl::String &argument);
            virtual void operation_alloc_memory(const ntl::String &argument);
            virtual void operation_free_memory(const ntl::String &argument);
        };

    } // namespace Execution

} // namespace nsl

#endif