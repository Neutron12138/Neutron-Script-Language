#ifndef __NEUTRONSL_BASE_SCRIPTMISC_HPP__
#define __NEUTRONSL_BASE_SCRIPTMISC_HPP__

#include <any>
#include <vector>
#include <map>
#include <variant>
#include <ntl/NTL.hpp>

namespace nsl
{
    namespace Type
    {
        class TypeTraits;
        class Type;

    } // namespace Types

    /// @brief 变量的内存
    using Memory = std::vector<ntl::Byte>;

    /// @brief 变量内存的指针
    using MemoryPointer = ntl::SharedPointer<Memory>;

    /// @brief 变量内存的引用
    using MemoryReference = ntl::WeakPointer<Memory>;

    /// @brief 本地参数
    using NativeArgument = std::any;

    /// @brief 本地参数数组
    using NativeArgumentsArray = std::vector<NativeArgument>;

    /// @brief 参数类型
    using Argument = std::variant<NativeArgument>;

    /// @brief 参数数组类型
    using ArgumentsArray = std::vector<Argument>;

    /// @brief 类型特点持有者
    using TypeTraitsHolder = ntl::SharedPointer<Type::TypeTraits>;

    /// @brief 类型持有者
    using TypeHolder = ntl::SharedPointer<Type::Type>;

    /// @brief 类型容器
    using TypeContainer = std::map<ntl::String, TypeHolder>;

} // namespace nsl

#endif