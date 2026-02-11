#pragma once

#ifndef LE_CORE_CORETYPES_HPP
#define LE_CORE_CORETYPES_HPP

#include <cstdint>

namespace LE {

    // Numerics
    using U8 = std::uint8_t;
    using U16 = std::uint16_t;
    using U32 = std::uint32_t;
    using U64 = std::uint64_t;

    using I8 = std::int8_t;
    using I16 = std::int16_t;
    using I32 = std::int32_t;
    using I64 = std::int64_t;

    using F32 = float;
    using F64 = double;

    // Macro
#ifdef _WIN32
    #define STD_CALL __stdcall 
#else
    #define STD_CALL
#endif
}



#endif // LE_CORE_CORETYPES_HPP
        