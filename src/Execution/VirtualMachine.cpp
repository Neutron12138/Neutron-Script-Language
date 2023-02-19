#ifndef __NEUTRONSL_EXECUTION_VIRTUALMACHINE_CPP__
#define __NEUTRONSL_EXECUTION_VIRTUALMACHINE_CPP__

#include "VirtualMachine.hpp"

namespace nsl
{
    namespace Execution
    {
        const VariableManager &
        VirtualMachine::get_global_variables() const
        {
            return m_global_variables;
        }

        const std::vector<Instruction> &
        VirtualMachine::get_instructions() const
        {
            return m_instructions;
        }

        const std::vector<Variable> &
        VirtualMachine::get_temp_variables() const
        {
            return m_temp_variables;
        }

        Variable &
        VirtualMachine::get_temp_top()
        {
            return m_temp_variables.at(m_temp_variables.size() - 1);
        }

        const Variable &
        VirtualMachine::get_temp_top() const
        {
            return m_temp_variables.at(m_temp_variables.size() - 1);
        }

        void
        VirtualMachine::load_instructions(
            const std::vector<Instruction> &instructions)
        {
            m_instructions = instructions;
        }

        void
        VirtualMachine::execute()
        {
            for (auto iter = m_instructions.cbegin(); iter != m_instructions.cend(); iter++)
            {
                const Instruction::Operation &operation = iter->get_operation();
                const ntl::String &argument = iter->get_argument();

                switch (operation)
                {
                case Instruction::Operation::None:
                    operation_none(argument);
                    break;

                case Instruction::Operation::ResetTemp:
                    operation_reset_temp(argument);
                    break;

                case Instruction::Operation::LoadVal:
                    operation_load_val(argument);
                    break;

                case Instruction::Operation::LoadVar:
                    operation_load_var(argument);
                    break;

                case Instruction::Operation::StoreVar:
                    operation_store_var(argument);
                    break;

                case Instruction::Operation::RemoveVar:
                    operation_remove_var(argument);
                    break;

                default:
                    break;
                }
            }
        }

        void
        VirtualMachine::operation_none(
            const ntl::String &argument)
        {
            // 什么也不做
        }

        void
        VirtualMachine::operation_reset_temp(
            const ntl::String &argument)
        {
            m_temp_variables.clear();
        }

        void
        VirtualMachine::operation_load_val(
            const ntl::String &argument)
        {
            Variable v = parse_value(argument);
            m_temp_variables.push_back(v);
        }

        void
        VirtualMachine::operation_load_var(
            const ntl::String &argument)
        {
            m_temp_variables.push_back(m_global_variables[argument]);
        }

        void
        VirtualMachine::operation_store_var(
            const ntl::String &argument)
        {
            Variable &top = get_temp_top();
            if (m_global_variables.is_existed(argument))
                m_global_variables[argument] = top;
            else
                m_global_variables.add_variable(argument, top);
        }

        void
        VirtualMachine::operation_remove_var(
            const ntl::String &argument)
        {
            m_global_variables.remove_variable(argument);
        }

        Variable
        VirtualMachine::parse_value(
            const ntl::String &value)
        {
            const std::vector<ntl::String> args = ntl::StringUtils::split(value, NTL_STRING("[ ]+"));

            if (args.size() == 0)
            {
                throw ntl::InvalidArgumentException(
                    ntl::StringUtils::to_string(
                        NTL_STRING("The value \""),
                        value,
                        NTL_STRING("\" is invalid")),
                    NTL_STRING("Variable VirtualMachine::parse_value(const ntl::String &value)"));
            }
            else if (args.size() == 1)
            {
                if (args.at(0) == NTL_STRING("null"))
                {
                    Variable v;
                    v.set_type(NTL_STRING("null"));
                    v.allocate_memory(sizeof(nullptr));
                    v.as_native_type<std::nullptr_t>() = nullptr;
                    return static_cast<Variable>(v);
                }
                else
                {
                    throw ntl::InvalidArgumentException(
                        ntl::StringUtils::to_string(
                            NTL_STRING("The value \""),
                            value,
                            NTL_STRING("\" is invalid")),
                        NTL_STRING("Variable VirtualMachine::parse_value(const ntl::String &value)"));
                }
            }
            else
            {
                Variable v;
                if (args.size() == 2 && args.at(0) == NTL_STRING("int"))
                {
                    v.set_type(NTL_STRING("int"));
                    v.allocate_memory(sizeof(ntl::Int64));
                    v.as_native_type<ntl::Int64>() = std::stoi(args.at(1));
                }
                else if (args.size() >= 2 && args.at(0) == NTL_STRING("str"))
                {
                    v.set_type(NTL_STRING("str"));
                    v.allocate_memory(sizeof(ntl::String));
                    v.as_native_type<ntl::String>() = ntl::StringUtils::joint_string(args.cbegin() + 1, args.cend(), NTL_STRING(" "));
                }
                return static_cast<Variable>(v);
            }
        }

        void
        VirtualMachine::free_variable(
            Variable &variable)
        {
        }

    } // namespace Execution

} // namespace nsl

#endif