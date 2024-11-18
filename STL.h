// Author: Jake Rieger
// Created: 10/13/2024.
//

#pragma once

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

template<typename T>
T Expect(const Option<T>& opt, const std::string& msg) {
    if (!opt.has_value()) {
        std::cerr << "Expect: " << msg << std::endl;
        std::exit(-10);
    }
    return opt.value();
}
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