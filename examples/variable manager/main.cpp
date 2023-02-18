#include <iostream>
#include <glm/glm.hpp>
#include "../../src/NSL.hpp"
#include "../../src/NSL.cpp"

void test(const nsl::Execution::VariableManager &manager, const std::string &name);

int main()
{
    nsl::Execution::VariableManager manager;

    manager.add_variable("a", nsl::Execution::Variable());

    test(manager, "");
    test(manager, "0a");
    test(manager, "a 2");
    test(manager, "a");

    manager["a"].allocate_memory(4);
    manager["a"].as_native_type<int>() = 666;
    std::cout << "manager[\"a\"].as_native_type<int>():" << manager["a"].as_native_type<int>() << std::endl;
    manager["a"].free_memory();

    return 0;
}

void test(const nsl::Execution::VariableManager &manager, const std::string &name)
{
    std::cout << "\"" << name << "\":" << manager.check_name(name) << std::endl;
}
