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

#pragma region Cast Aliases
#if defined(CAST_ALIASES) || defined(ALL_ALIASES)
    #define CAST static_cast
    #define CCAST const_cast
    #define DCAST dynamic_cast
    #define RCAST reinterpret_cast
#endif
#pragma endregion

#pragma region Filesystem
#if defined(IO_ALIASES) || defined(ALL_ALIASES)

    #include <filesystem>

namespace FileSystem = std::filesystem;
using Path           = std::filesystem::path;
using Directory      = std::filesystem::directory_entry;
using DirectoryIter  = std::filesystem::directory_iterator;

#endif
#pragma endregion

#pragma region STL Containers

#if defined(INC_ARRAY)
    #include <array>
template<typename T, std::size_t N>
using Array = std::array<T, N>;
#endif

#if defined(INC_ATOMIC)
    #include <atomic>
template<typename T>
using Atomic = std::atomic<T>;
#endif

#if defined(INC_BTREE)
    #include <map>
template<typename K, typename V>
using BTree = std::map<K, V>;
#endif

#if defined(INC_DICTIONARY)
    #include <unordered_map>
template<typename K, typename V>
using Dictionary = std::unordered_map<K, V>;
#endif

#if defined(INC_FUNCTION)
    #include <functional>
template<typename Sig>
using Function = std::function<Sig>;
#endif

#if defined(INC_FUTURE)
    #include <future>
template<typename T>
using Future = std::future<T>;
#endif

#if defined(INC_LIST)
    #include <list>
template<typename T>
using List = std::list<T>;
#endif

#if defined(INC_MUTEX)
    #include <mutex>
using Mutex = std::mutex;
#endif

#if defined(INC_OPTION)
    #include <optional>
template<typename T>
using Option = std::optional<T>;
#endif

#if defined(INC_QUEUE)
    #include <queue>
template<typename T>
using Queue = std::queue<T>;
#endif

#if defined(INC_PAIR)
    #include <utility>
template<typename V1, typename V2>
using Pair = std::pair<V1, V2>;
#endif

#if defined(INC_TUPLE)
    #include <tuple>
template<typename... Types>
using Tuple = std::tuple<Types...>;
#endif

#if defined(INC_VECTOR)
    #include <vector>
template<typename T>
using Vector = std::vector<T>;
#endif

#pragma endregion

#pragma region Smart Pointers
#if defined(PTR_ALIASES) || defined(ALL_ALIASES)
    #include <memory>

template<typename T>
using Unique = std::unique_ptr<T>;

template<typename T, typename D>
using UniqueDelete = std::unique_ptr<T, D>;

template<typename T>
using Shared = std::shared_ptr<T>;

template<typename T>
using Weak = std::weak_ptr<T>;
#endif
#pragma endregion

#pragma region Custom Containers
#if defined(CUSTOM_CONTAINERS)
template<typename T>
concept Numeric = std::is_arithmetic_v<T>;

template<Numeric T>
struct Rect {
    T left;
    T top;
    T right;
    T bottom;
};

template<Numeric T>
struct Point {
    T x;
    T y;
};
#endif
#pragma endregion
