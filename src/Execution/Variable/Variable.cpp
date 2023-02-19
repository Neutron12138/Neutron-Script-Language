#ifndef __NEUTRONSL_EXECUTION_VARIABLE_CPP__
#define __NEUTRONSL_EXECUTION_VARIABLE_CPP__

#include "Variable.hpp"

namespace nsl
{
    namespace Execution
    {
        const MemoryPointer &
        Variable::get_memory_pointer() const
        {
            return m_memory;
        }

        bool
        Variable::is_memory_available() const
        {
            return (!m_memory.is_nullptr()) &&
                   (m_memory->size() > 0) &&
                   (m_memory->data() != nullptr);
        }

        ntl::Byte *
        Variable::get_memory(ntl::SizeT offset)
        {
            if (!is_memory_available())
                throw ntl::NullPointerException(
                    NTL_STRING(
                        "ntl::Byte *Variable::get_memory(ntl::SizeT offset)F"));

            return m_memory->data() + offset;
        }

        const ntl::Byte *
        Variable::get_memory(ntl::SizeT offset) const
        {
            if (!is_memory_available())
                throw ntl::NullPointerException(
                    NTL_STRING(
                        "const ntl::Byte *Variable::get_memory(ntl::SizeT offset) const"));

            return m_memory->data() + offset;
        }

        template <typename ReturnType>
        ReturnType &
        Variable::as_native_type(ntl::SizeT offset)
        {
            if (!is_memory_available())
                throw ntl::NullPointerException(
                    NTL_STRING(
                        "template <typename ReturnType> ReturnType &Variable::as_native_type()"));

            ntl::SizeT end = offset + sizeof(ReturnType);
            if (end > m_memory->size())
                throw ntl::OutOfRangeException(
                    ntl::StringUtils::to_string(NTL_STRING("The memory end is "), end, NTL_STRING(", but the memory size is only "), m_memory->size()),
                    NTL_STRING("template <typename ReturnType> ReturnType &Variable::as_native_type(ntl::SizeT offset)"));

            return *reinterpret_cast<ReturnType *>(get_memory(offset));
        }

        template <typename ReturnType>
        const ReturnType &
        Variable::as_native_type(ntl::SizeT offset) const
        {
            if (!is_memory_available())
                throw ntl::NullPointerException(
                    NTL_STRING(
                        "template <typename ReturnType> const ReturnType &Variable::as_native_type(ntl::SizeT offset) const"));

            ntl::SizeT end = offset + sizeof(ReturnType);
            if (end > m_memory->size())
                throw ntl::OutOfRangeException(
                    ntl::StringUtils::to_string(NTL_STRING("The memory end is "), end, NTL_STRING(", but the memory size is only "), m_memory->size()),
                    NTL_STRING("template <typename ReturnType> const ReturnType &Variable::as_native_type(ntl::SizeT offset) const"));

            return *reinterpret_cast<ReturnType *>(get_memory(offset));
        }

        const ntl::String &
        Variable::get_type() const
        {
            return m_type;
        }

        void
        Variable::allocate_memory(
            ntl::SizeT size)
        {
            if (m_memory.is_nullptr())
                m_memory = ntl::make_shared<Memory>();

            m_memory->resize(size);
        }

        void
        Variable::free_memory()
        {
            try
            {
                Memory &result = *m_memory;
                result.clear();
            }
            catch (const ntl::NullPointerException &exception)
            {
                throw ntl::CaughtException(
                    exception,
                    NTL_STRING("void Variable::free_memory()"));
            }
        }

        void
        Variable::set_type(
            const ntl::String &type)
        {
            m_type = type;
        }

    } // namespace Execution

} // namespace nsl

#endif