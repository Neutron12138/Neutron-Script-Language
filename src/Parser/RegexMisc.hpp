#ifndef __NEUTRONSL_BASE_REGEXMISC_HPP__
#define __NEUTRONSL_BASE_REGEXMISC_HPP__

#include <ntl/NTL.hpp>

namespace nsl
{
    namespace RegexMisc
    {
        /// @brief 忽略空格
        static const ntl::String ignore_spaces = NTL_STRING("(?:[ ]+)?");

        /// @brief 忽略制表符
        static const ntl::String ignore_tabs = NTL_STRING("(?:[\t]+)?");

        /// @brief 需要至少一个空格
        static const ntl::String need_space = NTL_STRING("[ ]+");

        /// @brief 通配符，可以匹配任意字符
        static const ntl::String wildcard = NTL_STRING("(.*)");

        /// @brief 忽略空白
        static const ntl::String ignore_blank = ignore_tabs + ignore_spaces;

    } // namespace RegexMisc

} // namespace nsl

#endif