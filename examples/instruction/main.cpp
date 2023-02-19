#include <iostream>
#include "../../src/NSL.hpp"
#include "../../src/NSL.cpp"

int main()
{
    nsl::Execution::VirtualMachine vm;

    try
    {
        vm.load_instructions({
            nsl::Execution::Instruction(nsl::Execution::Instruction::Operation::LoadVal, "int 10"),
            nsl::Execution::Instruction(nsl::Execution::Instruction::Operation::StoreVar, "a"),
            nsl::Execution::Instruction(nsl::Execution::Instruction::Operation::ResetTemp, ""),
        });

        vm.execute();

        std::cout << vm.get_global_variables()["a"].as_native_type<const int>() << std::endl;

        vm.load_instructions({
            nsl::Execution::Instruction(nsl::Execution::Instruction::Operation::LoadVal, "str str666"),
            nsl::Execution::Instruction(nsl::Execution::Instruction::Operation::StoreVar, "a"),
            nsl::Execution::Instruction(nsl::Execution::Instruction::Operation::ResetTemp, ""),
        });

        vm.execute();

        std::cout << vm.get_global_variables()["a"].as_native_type<const ntl::String>() << std::endl;
    }
    catch (const ntl::Exception &exception)
    {
        std::cerr << exception << std::endl;
    }

    return 0;
}
