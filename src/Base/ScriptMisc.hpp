#ifndef __NEUTRONSL_BASE_SCRIPTMISC_HPP__
#define __NEUTRONSL_BASE_SCRIPTMISC_HPP__

#include <any>
#include <vector>
#include <map>
#include <variant>
#include <ntl/NTL.hpp>

namespace nsl
{
    namespace Types
    {
        class TypeTraits;

    } // namespace Types

    /// @brief 变量内存的指针
    using MemoryPointer = std::vector<ntl::Byte>;

    /// @brief 本地参数
    using NativeArgument = std::any;

    /// @brief 本地参数数组
    using NativeArgumentsArray = std::vector<NativeArgument>;

    /// @brief 参数类型
    using Argument = std::variant<NativeArgument, MemoryPointer>;

    /// @brief 参数数组类型
    using ArgumentsArray = std::vector<Argument>;

    /// @brief 类型特点持有者
    using TypeTraitsHolder = ntl::SharedPointer<Types::TypeTraits>;

    /// @brief 类型特点容器
    using TypeTraitsContainer = std::map<ntl::String, TypeTraitsHolder>;

} // namespace nsl

#endif