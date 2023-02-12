#ifndef __NEUTRONSL_TYPE_TYPE_CPP__
#define __NEUTRONSL_TYPE_TYPE_CPP__

#include "Type.hpp"

namespace nsl
{
    namespace Type
    {
        Type::Type(
            const ntl::String &name,
            const TypeTraitsHolder &traits)
            : m_type_name(name),
              m_type_traits(traits) {}

        const ntl::String &
        Type::get_type_name() const
        {
            return m_type_name;
        }

        const TypeTraitsHolder &
        Type::get_type_traits() const
        {
            return m_type_traits;
        }
    } // namespace Type

} // namespace nsl

#endif