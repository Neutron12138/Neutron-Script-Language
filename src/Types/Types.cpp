#ifndef __NEUTRONSL_TYPE_TYPES_CPP__
#define __NEUTRONSL_TYPE_TYPES_CPP__

#include <ntl/NTL.hpp>
#include "Types.hpp"
#include "TypeID.hpp"
#include "Integer.hpp"

namespace nsl
{
    namespace Types
    {
        Types::Types()
        {
            add_type(TypeID::integer, TypeTraitsHolder(new Integer()));
        }

        void Types::add_type(const ntl::String &type_name, const TypeTraitsHolder &type_traits)
        {
            m_type_traits.insert(TypeTraitsContainer::value_type(type_name, type_traits));
        }

        const TypeTraitsHolder &Types::get_type(const ntl::String &type_name) const
        {
            try
            {
                const TypeTraitsHolder &result = m_type_traits.at(type_name);
                return result;
            }
            catch (const std::out_of_range &exception)
            {
                throw ntl::OutOfRangeException(exception);
            }
            catch (const std::exception &exception)
            {
                throw ntl::Exception(exception);
            }
        }
        const TypeTraitsContainer &Types::get_types() const
        {
            return m_type_traits;
        }

    } // namespace Types

} // namespace nsl

#endif