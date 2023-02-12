#ifndef __NEUTRONSL_TYPE_TYPEMANAGER_CPP__
#define __NEUTRONSL_TYPE_TYPEMANAGER_CPP__

#include <ntl/NTL.hpp>
#include "TypeManager.hpp"
#include "TypeID.hpp"
#include "Integer.hpp"

namespace nsl
{
    namespace Type
    {
        TypeManager::TypeManager()
        {
            add_type(
                TypeID::integer,
                ntl::make_shared<Type>(
                    TypeID::integer,
                    ntl::SharedPointer<TypeTraits>(
                        new Integer())));
        }

        void
        TypeManager::add_type(
            const ntl::String &name,
            const TypeHolder &type)
        {
            m_types.insert(
                TypeContainer::value_type(
                    name,
                    type));
        }

        const TypeHolder &
        TypeManager::get_type(
            const ntl::String &type_name) const
        {
            try
            {
                const TypeHolder &result = m_types.at(type_name);
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
        const TypeContainer &
        TypeManager::get_types() const
        {
            return m_types;
        }

    } // namespace Type

} // namespace nsl

#endif