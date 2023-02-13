#include <iostream>
#include "../../src/NSL.hpp"
#include "../../src/NSL.cpp"

int main()
{
    try
    {
        std::cout << "-----start-----" << std::endl;

        nsl::Type::TypeManager manager;

        nsl::Value::LValue var1(manager.get_type("integer"));
        nsl::Value::LValue var2(manager.get_type("integer"));

        var1.allocate_memory();
        var2.allocate_memory();

        var1.default_construct_self();
        var2.default_construct_self();
        std::cout << "var1:" << var1.as_internal_type<ntl::Int64>() << std::endl;
        std::cout << "var2:" << var2.as_internal_type<ntl::Int64>() << std::endl;

        nsl::Argument arg = nsl::NativeArgument(nsl::Type::Integer::InternalType(666));
        nsl::ArgumentsArray args = {arg};
        var1.construct_self(args);
        nsl::Argument arg2 = nsl::NativeArgument(*var1.get_memory_pointer());
        var2.copy_assign_self(arg2);
        std::cout << "var1:" << var1.as_internal_type<ntl::Int64>() << std::endl;
        std::cout << "var2:" << var2.as_internal_type<ntl::Int64>() << std::endl;

        var1.destruct_self();
        var2.destruct_self();

        var1.free_memory();
        var2.free_memory();

        std::cout << "-----clean up-----" << std::endl;
    }
    catch (const ntl::Exception &exception)
    {
        std::cout << exception << std::endl;
    }

    return 0;
}