#ifndef __NEUTRONSL_TYPE_TYPETRAITS_HPP__
#define __NEUTRONSL_TYPE_TYPETRAITS_HPP__

#include <any>
#include <vector>
#include <ntl/NTL.hpp>
#include "../Base/ScriptMisc.hpp"

namespace nsl
{
    namespace Type
    {
        /// @brief 变量类型的特点
        class TypeTraits : public ntl::Object
        {
        public:
            using SelfType = TypeTraits;
            using ParentType = ntl::Object;

        public:
            constexpr TypeTraits() noexcept = default;
            constexpr explicit TypeTraits(const SelfType &from) noexcept = default;
            ~TypeTraits() override { std::cout << "~TypeTraits" << std::endl; } //= default;

        public:
            constexpr SelfType &operator=(const SelfType &from) noexcept = default;

        public:
            /// @brief 获取本类型的内存大小
            /// @return 本类型的内存大小
            virtual ntl::SizeT get_type_size() const = 0;

            /// @brief 默认构造函数
            /// @param memory 变量内存
            virtual void default_construction(Memory &memory) const = 0;

            /// @brief 构造函数
            /// @param memory 变量内存
            /// @param arguments 参数列表
            virtual void construction(Memory &memory, const ArgumentsArray arguments) const = 0;

            /// @brief 析构函数
            /// @param memory 变量内存
            /// @param arguments 参数列表
            virtual void destruction(Memory &memory) const = 0;

            /// @brief 拷贝赋值运算符
            /// @param memory 变量内存
            /// @param arguments 参数列表
            virtual void copy_assignment(Memory &memory, const Argument &argument) const = 0;

        public:
            /// @brief 检查内存大小是否合法
            /// @param memory 要检查的内存
            /// @param type_traits 类型特点
            /// @return 内存大小是否合法
            static bool is_memory_size_legal(const Memory &memory, const TypeTraits &type_traits);

            /// @brief 检查内存大小是否合法，没有则抛出异常
            /// @param memory 要检查的内存
            /// @param type_traits 类型特点
            /// @param where 调用位置
            static void is_memory_size_legal(const Memory &memory, const TypeTraits &type_traits, const ntl::String &where);

            /// @brief 转换为内部类型
            /// @tparam TraitsType 类型特点类型
            /// @param memory 内存
            /// @return 内部类型
            template <typename TraitsType>
            static typename TraitsType::InternalType &as_internal_type(const Memory &memory);
        };

    } // namespace Type

} // namespace nsl

#endif