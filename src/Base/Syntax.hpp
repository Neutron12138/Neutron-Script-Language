#ifndef __NEUTRONSL_BASE_SYNTAX_HPP__
#define __NEUTRONSL_BASE_SYNTAX_HPP__

#include "Token.hpp"

namespace nsl
{
    /// @brief 语法
    namespace Syntax
    {
        /// @brief 对一个变量赋值
        static const ntl::String assignment =
            Token::ignore_blank +
            Token::wildcard + // 变量名（1）
            Token::ignore_blank +
            Token::assignment + // "="
            Token::ignore_blank +
            Token::wildcard + // 值（2）
            Token::ignore_blank;

        /// @brief 声明变量
        static const ntl::String declare_variable =
            Token::ignore_blank +
            Token::declare_variable + // 关键字var
            Token::ignore_blank +
            Token::wildcard + // 变量名列表（1）
            Token::ignore_blank;

    } // namespace Syntax

} // namespace nsl

#endif