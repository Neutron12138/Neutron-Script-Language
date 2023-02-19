#ifndef __NEUTRONSL_EXECUTION_INSTRUCTION_HPP__
#define __NEUTRONSL_EXECUTION_INSTRUCTION_HPP__

#include <ntl/NTL.hpp>

namespace nsl
{
    namespace Execution
    {
        /// @brief 指令
        class Instruction : public ntl::Object
        {
        public:
            using SelfType = Instruction;
            using ParentType = ntl::Object;

            /// @brief 操作
            enum Operation
            {
                /// @brief 没有任何操作
                None = 0,

                /// @brief 重置缓存
                ResetTemp,

                /// @brief 加载值
                LoadVal,

                /// @brief 加载变量
                LoadVar,

                /// @brief 保存变量
                StoreVar,

                /// @brief 移除变量
                RemoveVar,

                /// @brief 总数
                Count,
            };

        protected:
            /// @brief 操作
            Operation m_operation;

            /// @brief 参数
            ntl::String m_argument;

        public:
            Instruction() = default;
            explicit Instruction(Operation operation, const ntl::String &argument);
            explicit Instruction(const SelfType &from) = default;
            ~Instruction() override = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            /// @brief 获取操作
            /// @return 操作
            Operation get_operation() const;

            /// @brief 获取参数
            /// @return 参数
            const ntl::String &get_argument() const;
        };

    } // namespace Execution

} // namespace nsl

#endif