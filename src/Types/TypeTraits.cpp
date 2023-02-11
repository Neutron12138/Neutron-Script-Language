#ifndef __NEUTRONSL_TYPE_TYPETRAITS_CPP__
#define __NEUTRONSL_TYPE_TYPETRAITS_CPP__

#include "TypeTraits.hpp"

namespace nsl
{
    namespace Types
    {
        bool
        TypeTraits::is_memory_size_legal(
            const MemoryPointer &memory,
            const TypeTraits &type_traits)
        {
            return memory.size() >= type_traits.get_type_size();
        }

        template <typename TraitsType>
        typename TraitsType::InternalType &
        TypeTraits::as_internal_type(
            const MemoryPointer &memory)
        {
            typename TraitsType::InternalType *ptr =
                const_cast<typename TraitsType::InternalType *>(
                    reinterpret_cast<const typename TraitsType::InternalType *>(
                        memory.data()));
            return *ptr;
        }

    } // namespace Types

} // namespace nsl

#endif