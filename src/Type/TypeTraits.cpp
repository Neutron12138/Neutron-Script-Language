#ifndef __NEUTRONSL_TYPE_TYPETRAITS_CPP__
#define __NEUTRONSL_TYPE_TYPETRAITS_CPP__

#include "TypeTraits.hpp"

namespace nsl
{
    namespace Type
    {
        bool
        TypeTraits::is_memory_size_legal(
            const Memory &memory,
            const TypeTraits &type_traits)
        {
            return memory.size() >= type_traits.get_type_size();
        }

        void
        TypeTraits::is_memory_size_legal(
            const Memory &memory,
            const TypeTraits &type_traits,
            const ntl::String &where)
        {
            if (!is_memory_size_legal(memory, type_traits))
                throw ntl::InvalidArgumentException(
                    NTL_STRING("Memory size is too small"),
                    where);
        }

        template <typename TraitsType>
        typename TraitsType::InternalType &
        TypeTraits::as_internal_type(
            const Memory &memory)
        {
            typename TraitsType::InternalType *ptr =
                const_cast<typename TraitsType::InternalType *>(
                    reinterpret_cast<const typename TraitsType::InternalType *>(
                        memory.data()));
            return *ptr;
        }

    } // namespace Type

} // namespace nsl

#endif