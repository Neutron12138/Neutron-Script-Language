#ifndef __NEUTRONSL_PARSER_SYNTAX_HPP__
#define __NEUTRONSL_PARSER_SYNTAX_HPP__

#include "../Base/RegexMisc.hpp"
#include "Token.hpp"

namespace nsl
{
    namespace Parser
    {
        /// @brief 语法
        namespace Syntax
        {
            /// @brief 对一个变量赋值
            static const ntl::String assignment =
                RegexMisc::ignore_blank +
                RegexMisc::wildcard + // 变量名（1）
                RegexMisc::ignore_blank +
                Token::assignment + // "="
                RegexMisc::ignore_blank +
                RegexMisc::wildcard + // 值（2）
                RegexMisc::ignore_blank;

            /// @brief 声明变量
            static const ntl::String declare_variable =
                RegexMisc::ignore_blank +
                Token::declare_variable + // 关键字var
                RegexMisc::ignore_blank +
                RegexMisc::wildcard + // 变量名列表（1）
                RegexMisc::ignore_blank;

        } // namespace Syntax

    } // namespace Parser

} // namespace nsl

#endif