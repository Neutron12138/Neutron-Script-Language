#include <iostream>
#include <glm/glm.hpp>
#include "../../src/NSL.hpp"
#include "../../src/NSL.cpp"

int main()
{
    std::cout << "version:" << NEUTRONSL_INFO_VERSION << std::endl;

    std::cout << "----------" << std::endl;

    nsl::Execution::Variable v1;
    nsl::Execution::Variable v2;

    try
    {
        v1.allocate_memory(8);

        v1.as_native_type<int>(0) = 123;
        v1.as_native_type<int>(4) = 456;
        std::cout << v1.as_native_type<int>(0) << std::endl;
        std::cout << v1.as_native_type<int>(4) << std::endl;
        std::cout << v1.as_native_type<long long>(0) << std::endl;

        std::cout << "----------" << std::endl;

        v1.as_native_type<long long>(0) = 1234567890987654321;
        std::cout << v1.as_native_type<int>(0) << std::endl;
        std::cout << v1.as_native_type<int>(4) << std::endl;
        std::cout << v1.as_native_type<long long>(0) << std::endl;

        v1.free_memory();

        // ----------
        std::cout << "----------" << std::endl
                  << "----------" << std::endl;
        // ----------

        v2.allocate_memory(sizeof(glm::vec3));

        v2.as_native_type<glm::vec3>(0) = glm::vec3(1, 2, 3);
        std::cout << v2.as_native_type<float>(0) << std::endl;
        std::cout << v2.as_native_type<float>(4) << std::endl;
        std::cout << v2.as_native_type<float>(8) << std::endl;

        std::cout << "----------" << std::endl;

        v2.as_native_type<glm::vec3>(0).x = 4;
        v2.as_native_type<glm::vec3>(0).y = 5;
        v2.as_native_type<glm::vec3>(0).z = 6;
        std::cout << v2.as_native_type<float>(0) << std::endl;
        std::cout << v2.as_native_type<float>(4) << std::endl;
        std::cout << v2.as_native_type<float>(8) << std::endl;

        v2.free_memory();
    }
    catch (const ntl::CaughtException &exception)
    {
        std::cout << exception << std::endl;
    }
    catch (const ntl::Exception &exception)
    {
        std::cout << exception << std::endl;
    }

    return 0;
}