#include <iostream>
#include "../../src/NSL.hpp"
#include "../../src/NSL.cpp"

int main()
{
    nsl::Type::TypeManager manager;

    nsl::MemoryPointer ptr = ntl::make_shared<nsl::Memory>(manager.get_type("integer")->get_type_traits()->get_type_size());
    nsl::MemoryPointer ptr2 = ntl::make_shared<nsl::Memory>(manager.get_type("integer")->get_type_traits()->get_type_size());

    manager.get_type("integer")->get_type_traits()->default_construction(*ptr);
    manager.get_type("integer")->get_type_traits()->default_construction(*ptr2);
    std::cout << nsl::Type::Integer::as_internal_type<nsl::Type::Integer>(*ptr) << std::endl;
    std::cout << nsl::Type::Integer::as_internal_type<nsl::Type::Integer>(*ptr2) << std::endl;

    nsl::Argument arg = nsl::NativeArgument(nsl::Type::Integer::InternalType(666));
    nsl::ArgumentsArray args = {arg};
    manager.get_type("integer")->get_type_traits()->construction(*ptr, args);
    nsl::Argument arg2 = nsl::NativeArgument(*ptr);
    manager.get_type("integer")->get_type_traits()->copy_assignment(*ptr2, arg2);
    std::cout << nsl::Type::Integer::as_internal_type<nsl::Type::Integer>(*ptr) << std::endl;
    std::cout << nsl::Type::Integer::as_internal_type<nsl::Type::Integer>(*ptr2) << std::endl;

    manager.get_type("integer")->get_type_traits()->destruction(*ptr);
    manager.get_type("integer")->get_type_traits()->destruction(*ptr2);

    return 0;
}