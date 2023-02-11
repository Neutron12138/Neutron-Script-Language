#include <iostream>
#include "../../src/NSL.hpp"
#include "../../src/NSL.cpp"

int main()
{
    nsl::Types::Types types;
    nsl::MemoryPointer ptr(types.get_type("integer")->get_type_size());
    nsl::MemoryPointer ptr2(types.get_type("integer")->get_type_size());

    types.get_type("integer")->default_construction(ptr);
    types.get_type("integer")->default_construction(ptr2);
    std::cout << nsl::Types::Integer::as_internal_type<nsl::Types::Integer>(ptr) << std::endl;
    std::cout << nsl::Types::Integer::as_internal_type<nsl::Types::Integer>(ptr2) << std::endl;

    nsl::Argument arg = nsl::NativeArgument(nsl::Types::Integer::InternalType(666));
    nsl::ArgumentsArray args = {arg};
    nsl::Argument arg2 = nsl::MemoryPointer(ptr);
    types.get_type("integer")->construction(ptr, args);
    types.get_type("integer")->copy_assignment(ptr2, arg2);
    std::cout << nsl::Types::Integer::as_internal_type<nsl::Types::Integer>(ptr) << std::endl;
    std::cout << nsl::Types::Integer::as_internal_type<nsl::Types::Integer>(ptr2) << std::endl;

    types.get_type("integer")->destruction(ptr);
    types.get_type("integer")->destruction(ptr2);
    std::cout << (void *)ptr.data() << std::endl;
    std::cout << (void *)ptr2.data() << std::endl;

    return 0;
}