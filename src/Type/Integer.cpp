#ifndef __NEUTRONSL_TYPE_INTEGER_CPP__
#define __NEUTRONSL_TYPE_INTEGER_CPP__

#include "Integer.hpp"

namespace nsl
{
    namespace Type
    {
        ntl::SizeT
        Integer::get_type_size() const
        {
            return sizeof(Integer::InternalType);
        }

        void
        Integer::default_construction(
            Memory &memory) const
        {
            is_memory_size_legal(memory,
                                 *this,
                                 NTL_STRING("void Integer::default_construction(Memory &memory) const"));

            as_internal_type<Integer>(memory) = 0L;
        }

        void
        Integer::construction(
            Memory &memory,
            const ArgumentsArray arguments) const
        {
            is_memory_size_legal(memory,
                                 *this,
                                 NTL_STRING("void Integer::construction(Memory &memory,const ArgumentsArray arguments) const"));

            if (arguments.size() != 1)
                throw ntl::InvalidArgumentException(
                    NTL_STRING("The number of arguments should be 1"),
                    NTL_STRING("void Integer::construction(Memory &memory,const ArgumentsArray arguments) const"));

            const Argument &arg = arguments.at(0);
            const NativeArgument *narg = std::get_if<NativeArgument>(&arg);
            if (narg != nullptr)
                as_internal_type<Integer>(memory) =
                    std::any_cast<Integer::InternalType>(*narg);
            else
                throw ntl::InvalidArgumentException(
                    NTL_STRING("The type of parameter is wrong. It should be:\"nsl::NativeArgument\"and\"nsl::Type::Integer::InternalType\""),
                    NTL_STRING("void Integer::construction(Memory &memory,const ArgumentsArray arguments) const"));
        }

        void
        Integer::destruction(
            Memory &memory) const
        {
            is_memory_size_legal(memory,
                                 *this,
                                 NTL_STRING("void Integer::destruction(Memory &memory) const"));
        }

        void
        Integer::copy_assignment(
            Memory &memory,
            const Argument &argument) const
        {
            is_memory_size_legal(memory,
                                 *this,
                                 NTL_STRING("void Integer::copy_assignment(Memory &memory,const Argument &argument) const"));

            const NativeArgument *narg = std::get_if<NativeArgument>(&argument);
            if (narg == nullptr)
                throw ntl::InvalidArgumentException(
                    NTL_STRING("The type of parameter is wrong. It should be:\"nsl::NativeArgument\"and\"nsl::Memory\""),
                    NTL_STRING("void Integer::copy_assignment(Memory &memory,const Argument &argument) const"));

            const Memory &mem = std::any_cast<Memory>(*narg);
            as_internal_type<Integer>(memory) = as_internal_type<Integer>(mem);
        }

    } // namespace Type

} // namespace nsl

#endif