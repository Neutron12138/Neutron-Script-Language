#ifndef __NEUTRONSL_TYPE_TYPEID_HPP__
#define __NEUTRONSL_TYPE_TYPEID_HPP__

#include <ntl/NTL.hpp>

namespace nsl
{
    namespace Types
    {
        namespace TypeID
        {
            /// @brief 整数，对应Int64
            static const ntl::String integer = NTL_STRING("integer");

            /// @brief 浮点数，对应Float64
            static const ntl::String floating = NTL_STRING("floating");

        } // namespace TypeID

    } // namespace Types

} // namespace nsl

#endif