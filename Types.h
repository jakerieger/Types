// Author: Jake Rieger
// Created: 9/30/24.
//

#pragma once

#pragma region Primitives
#include <cstdint>
#include <string>

using u8  = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

#if defined(__GNUC__) || defined(__clang__)
using u128 = __uint128_t;
using i128 = __int128_t;
#endif

using f32 = float;
using f64 = double;

using cstr = const char*;
using str  = std::string;
using wstr = std::wstring;
#pragma endregion

#if defined(TYPES_ALL)
    #include "Cast.h"
    #include "IO.h"
    #include "SmartPtr.h"
    #include "STL.h"
#endif