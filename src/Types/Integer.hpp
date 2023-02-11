#ifndef __NEUTRONSL_TYPE_INTEGER_HPP__
#define __NEUTRONSL_TYPE_INTEGER_HPP__

#include "TypeTraits.hpp"

namespace nsl
{
    namespace Types
    {
        /// @brief 整数类型
        class Integer : public TypeTraits
        {
        public:
            using SelfType = Integer;
            using ParentType = TypeTraits;

            /// @brief 内部类型
            using InternalType = ntl::Int64;

        public:
            constexpr Integer() noexcept = default;
            constexpr explicit Integer(const SelfType &from) noexcept = default;
            ~Integer() override = default;

        public:
            constexpr SelfType &operator=(const SelfType &from) noexcept = default;

        public:
            ntl::SizeT get_type_size() const override;
            void default_construction(MemoryPointer &memory) const override;
            void construction(MemoryPointer &memory, const ArgumentsArray arguments) const override;
            void destruction(MemoryPointer &memory) const override;
            void copy_assignment(MemoryPointer &memory, const Argument &argument) const override;
        };

    } // namespace Types

} // namespace nsl

#endif