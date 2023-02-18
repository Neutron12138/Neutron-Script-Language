#ifndef __NEUTRONSL_EXECUTION_INSTRUCTION_CPP__
#define __NEUTRONSL_EXECUTION_INSTRUCTION_CPP__

#include "Instruction.hpp"

namespace nsl
{
    namespace Execution
    {
        Instruction::Instruction(
            Instruction::Operation operation,
            const ntl::String &argument)
            : m_operation(operation),
              m_argument(argument) {}

        Instruction::Operation
        Instruction::get_operation() const
        {
            return m_operation;
        }

        const ntl::String &
        Instruction::get_argument() const
        {
            return m_argument;
        }

    } // namespace Execution

} // namespace nsl

#endif