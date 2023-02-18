#ifndef __NEUTRONSL_EXECUTION_VIRTUALMACHINE_HPP__
#define __NEUTRONSL_EXECUTION_VIRTUALMACHINE_HPP__

#include <ntl/NTL.hpp>

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

        public:
            VirtualMachine() = default;
            VirtualMachine(const SelfType &from) = default;
            ~VirtualMachine() override = default;

        public:
            SelfType &operator=(const SelfType &from) = default;
        };

    } // namespace Execution

} // namespace nsl

#endif