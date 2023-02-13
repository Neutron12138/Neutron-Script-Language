#ifndef __NEUTRONSL_PARSER_TOKEN_HPP__
#define __NEUTRONSL_PARSER_TOKEN_HPP__

#include <ntl/NTL.hpp>

namespace nsl
{
    namespace Parser
    {
        /// @brief 标识符
        namespace Token
        {
            /// @brief 声明变量
            static const ntl::String declare_variable = NTL_STRING("var");

            /// @brief 赋值符
            static const ntl::String assignment = NTL_STRING("=");
        } // namespace Token

    } // namespace Parser

} // namespace nsl

#endif