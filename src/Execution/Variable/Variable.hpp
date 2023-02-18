#ifndef __NEUTRONSL_EXECUTION_VARIABLE_HPP__
#define __NEUTRONSL_EXECUTION_VARIABLE_HPP__

#include <vector>
#include <ntl/NTL.hpp>

namespace nsl
{
    namespace Execution
    {
        /// @brief 内存
        using Memory = std::vector<ntl::Byte>;
        /// @brief 内存指针
        using MemoryPointer = ntl::SharedPointer<Memory>;

        /// @brief 变量
        class Variable : public ntl::Object
        {
        public:
            using SelfType = Variable;
            using ParentType = ntl::Object;

        protected:
            /// @brief 指向变量内存的指针
            MemoryPointer m_memory;

        public:
            Variable() = default;
            Variable(const SelfType &from) = default;
            ~Variable() override = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 获取内存指针
            /// @return 内存指针
            const MemoryPointer &get_memory_pointer() const;

            /// @brief 检查内存是否为空指针或内存大小为0
            /// @return 内存是否为空指针或内存大小为0
            bool is_memory_available() const;

            /// @brief 获取内存
            /// @param offset 偏移值
            /// @return 内存
            ntl::Byte *get_memory(ntl::SizeT offset = 0);

            /// @brief 获取内存
            /// @param offset 偏移值
            /// @return 内存
            const ntl::Byte *get_memory(ntl::SizeT offset = 0) const;

            /// @brief 转换为原生C++类型
            /// @tparam ReturnType 原生C++类型
            /// @param offset 偏移值
            /// @return 原生C++类型
            template <typename ReturnType>
            ReturnType &as_native_type(ntl::SizeT offset = 0);

            /// @brief 转换为const原生C++类型
            /// @tparam ReturnType 原生C++类型
            /// @param offset 偏移值
            /// @return 原生C++类型
            template <typename ReturnType>
            const ReturnType &as_native_type(ntl::SizeT offset = 0) const;

        public:
            /// @brief 分配内存
            /// @param size 内存大小
            virtual void allocate_memory(ntl::SizeT size);

            /// @brief 释放内存
            virtual void free_memory();
        };

    } // namespace Execution

} // namespace nsl

#endif