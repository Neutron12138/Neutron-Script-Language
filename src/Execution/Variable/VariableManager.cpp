#ifndef __NEUTRONSL_EXECUTION_VARIABLEMANAGER_CPP__
#define __NEUTRONSL_EXECUTION_VARIABLEMANAGER_CPP__

#include <cctype>
#include "VariableManager.hpp"

namespace nsl
{
    namespace Execution
    {
        Variable &
        VariableManager::operator[](
            const ntl::String &name)
        {
            try
            {
                Variable &result = m_variables.at(name);
                return result;
            }
            catch (const std::out_of_range &exception)
            {
                throw ntl::OutOfRangeException(
                    ntl::StringUtils::to_string(
                        NTL_STRING("Variable \""),
                        name,
                        NTL_STRING("\" not found")),
                    NTL_STRING("Variable &VariableManager::operator[](const ntl::String &name)"));
            }
        }

        const Variable &
        VariableManager::operator[](
            const ntl::String &name) const
        {
            try
            {
                const Variable &result = m_variables.at(name);
                return result;
            }
            catch (const std::out_of_range &exception)
            {
                throw ntl::OutOfRangeException(
                    ntl::StringUtils::to_string(
                        NTL_STRING("Variable \""),
                        name,
                        NTL_STRING("\" not found")),
                    NTL_STRING("const Variable &VariableManager::operator[](const ntl::String &name) const"));
            }
        }

        const std::map<ntl::String, Variable> &
        VariableManager::get_variables() const
        {
            return m_variables;
        }

        void
        VariableManager::add_variable(
            const ntl::String &name,
            const Variable &variable)
        {
            if (!check_name(name))
                throw ntl::InvalidArgumentException(
                    ntl::StringUtils::to_string(
                        NTL_STRING("The variable name \""),
                        name,
                        NTL_STRING("\" is invalid")),
                    NTL_STRING(""));

            m_variables.insert(
                std::map<ntl::String, Variable>::value_type(
                    name,
                    variable));
        }

        bool
        VariableManager::check_name(
            const ntl::String &name) const
        {
            if (name.size() == 0)
                return false;

            if (std::isdigit(name.at(0)))
                return false;

            if (m_variables.find(name) != m_variables.cend())
                return false;

            for (auto iter = name.cbegin(); iter != name.cend(); iter++)
            {
                // 下划线
                if (*iter == NTL_CHAR('_'))
                    ;
                // 字母或数字
                else if (std::isalnum(*iter))
                    ;
                // unicode字符
                else if (static_cast<int>(*iter) < 0)
                    ;
                else
                    return false;
            }

            return true;
        }

    } // namespace Execution

} // namespace nsl

#endif