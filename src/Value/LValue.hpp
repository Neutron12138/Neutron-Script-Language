#ifndef __NEUTRONSL_VALUE_LVALUE_HPP__
#define __NEUTRONSL_VALUE_LVALUE_HPP__

#include "Value.hpp"

namespace nsl
{
    namespace Value
    {
        /// @brief 左值类型
        class LValue : public Value
        {
        public:
            using SelfType = LValue;
            using ParentType = Value;

        protected:
            /// @brief 变量的内存
            MemoryPointer m_memory;

        public:
            LValue() = default;
            explicit LValue(const TypeHolder &type);
            explicit LValue(const SelfType &from) = default;
            ~LValue() override = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 获取内存
            /// @return 内存
            const MemoryPointer &get_memory_pointer() const;

            /// @brief 转换为内部类型
            /// @tparam InternalType 内部类型
            /// @return 内部类型
            template <typename InternalType>
            const InternalType &as_internal_type() const;

            /// @brief 为变量分配内存
            virtual void allocate_memory();

            /// @brief 释放内存
            virtual void free_memory();

            /// @brief 默认构造函数
            virtual void default_construct_self();

            /// @brief 构造函数
            virtual void construct_self(const ArgumentsArray &arguments);

            /// @brief 析构函数
            virtual void destruct_self();

            /// @brief 拷贝赋值函数
            /// @param argument 参数
            virtual void copy_assign_self(const Argument &argument);
        };

    } // namespace Value

} // namespace nsl

#endif