#ifndef __NEUTRONSL_TYPE_INTEGER_CPP__
#define __NEUTRONSL_TYPE_INTEGER_CPP__

#include "Integer.hpp"

namespace nsl
{
    namespace Types
    {
        ntl::SizeT
        Integer::get_type_size() const
        {
            return sizeof(Integer::InternalType);
        }

        void
        Integer::default_construction(
            MemoryPointer &memory) const
        {
            if (!is_memory_size_legal(memory, *this))
                return;

            as_internal_type<Integer>(memory) = 0L;
        }

        void
        Integer::construction(
            MemoryPointer &memory,
            const ArgumentsArray arguments) const
        {
            if (!is_memory_size_legal(memory, *this))
                return;

            if (arguments.size() == 1)
            {
                const Argument &arg = arguments.at(0);
                const NativeArgument *narg = std::get_if<NativeArgument>(&arg);
                if (narg != nullptr)
                    as_internal_type<Integer>(memory) =
                        std::any_cast<Integer::InternalType>(*narg);
            }
            else
            {
            }
        }

        void
        Integer::destruction(
            MemoryPointer &memory) const
        {
            if (!is_memory_size_legal(memory, *this))
                return;

            memory.clear();
        }

        void
        Integer::copy_assignment(
            MemoryPointer &memory,
            const Argument &argument) const
        {
            if (!is_memory_size_legal(memory, *this))
                return;

            const MemoryPointer *narg = std::get_if<MemoryPointer>(&argument);
            if (narg != nullptr)
                memcpy_s(memory.data(), memory.size(), narg->data(), narg->size());
        }

    } // namespace Types

} // namespace nsl

#endif