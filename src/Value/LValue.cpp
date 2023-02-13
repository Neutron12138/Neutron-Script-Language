#ifndef __NEUTRONSL_VALUE_LVALUE_CPP__
#define __NEUTRONSL_VALUE_LAVLUE_CPP__

#include "LValue.hpp"
#include "../Type/TypeID.hpp"
#include "../Type/Type.hpp"
#include "../Type/TypeTraits.hpp"
#include "../Type/Integer.hpp"

namespace nsl
{
    namespace Value
    {
        LValue::LValue(
            const TypeHolder &type)
            : Value(type) {}

        const MemoryPointer &
        LValue::get_memory_pointer() const
        {
            return m_memory;
        }

        template <typename InternalType>
        const InternalType &
        LValue::as_internal_type() const
        {
            const ntl::String name = m_type->get_type_name();

            if (name == Type::TypeID::integer)
            {
                return Type::TypeTraits::as_internal_type<Type::Integer>(*m_memory);
            }
        }

        void
        LValue::allocate_memory()
        {
            const Type::TypeTraits *traits = m_type->get_type_traits().get();
            m_memory = ntl::make_shared<Memory>(traits->get_type_size());
        }

        void
        LValue::free_memory()
        {
            m_memory->clear();
        }

        void
        LValue::default_construct_self()
        {
            const Type::TypeTraits *traits = m_type->get_type_traits().get();
            traits->default_construction(*m_memory);
        }

        void
        LValue::construct_self(
            const ArgumentsArray &arguments)
        {
            const Type::TypeTraits *traits = m_type->get_type_traits().get();
            traits->construction(*m_memory, arguments);
        }

        void
        LValue::destruct_self()
        {
            const Type::TypeTraits *traits = m_type->get_type_traits().get();
            traits->destruction(*m_memory);
        }

        void
        LValue::copy_assign_self(
            const Argument &argument)
        {
            const Type::TypeTraits *traits = m_type->get_type_traits().get();
            traits->copy_assignment(*m_memory, argument);
        }
    } // namespace Value

} // namespace nsl

#endif