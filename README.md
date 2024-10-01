**Types** is a single header file for C++20 that provides type aliases for all primitive types, as well as aliases for
STL containers, smart pointers, casting methods (static, dynamic, const, etc), and some custom container types for
common tasks.

Different groups of aliases can be included separately by defining specific macros before including **Types** in your
source. By default, only primitive type aliases are included.

## Why?

Because my ADD brain prefers simple, easy to distinguish type names. Here's a visual example:

**Normal C++:**

```c++
std::optional<std::vector<uint8_t>> ReadAllBytes(const std::filesystem::path& filename) {}
```

**With Aliases:**

```c++
Option<Vector<u8>> ReadAllBytes(const Path& filename) {}
```

### Include Guards

```c++
/// EXAMPLE

// Includes aliases for casting methods
#define CAST_ALIASES

// Includes aliases for smart pointers
#define PTR_ALIASES

// Includes custom container types (Rect, Point, etc)
#define CUSTOM_CONTAINERS

#include "Types.h"
```

If you just want to include everything (except STL containers), you can simply define `ALL_ALIASES`:

```cpp
#define ALL_ALIASES
#define INC_VECTOR // Still need to include STL containers individually
#include "Types.h"
```

### Primitive Aliases

| Type                     | Alias  |
|--------------------------|--------|
| uint8_t                  | `u8`   |
| uint16_t                 | `u16`  |
| uint32_t                 | `u32`  |
| uint64_t                 | `u64`  |
| __uint128_t (if defined) | `u128` |
| int8_t                   | `i8`   |
| int16_t                  | `i16`  |
| int32_t                  | `i32`  |
| int64_t                  | `i64`  |
| __int128_t (if defined)  | `i128` |
| float                    | `f32`  |
| double                   | `f64`  |
| const char*              | `cstr` |
| std::string              | `str`  |
| std::wstring             | `wstr` |

### Cast Aliases (`#define CAST_ALIASES`)

| Method           | Alias   |
|------------------|---------|
| static_cast      | `CAST`  |
| const_cast       | `CCAST` |
| dynamic_cast     | `DCAST` |
| reinterpret_cast | `RCAST` |

### Filesystem Aliases (`#define IO_ALIASES`)

| Type                                | Alias           |
|-------------------------------------|-----------------|
| std::filesystem (_namespace_)       | `FileSystem`    |
| std::filesystem::path               | `Path`          |
| std::filesystem::directory_entry    | `Directory`     |
| std::filesystem::directory_iterator | `DirectoryIter` |

### STL Container Aliases

For STL containers like `std::vector`, `std::unordered_map`, `std::optional`, etc, **Types** provides individual include
guards for each container as to avoid including a couple dozen STL headers all at once. *The STL aliases are not an
exhaustive list*; I really only aliased the ones I use most often.

Here's a list of all the include guards and the types they map to:

| Define           | STL Type           | Alias        |
|------------------|--------------------|--------------|
| `INC_ARRAY`      | std::array         | `Array`      |
| `INC_ATOMIC`     | std::atomic        | `Atomic`     |
| `INC_BTREE`      | std::map           | `BTree`      |
| `INC_DICTIONARY` | std::unordered_map | `Dictionary` |
| `INC_FUNCTION`   | std::function      | `Function`   |
| `INC_FUTURE`     | std::future        | `Future`     |
| `INC_LIST`       | std::list          | `List`       |
| `INC_MUTEX`      | std::mutex         | `Mutex`      |
| `INC_OPTION`     | std::optional      | `Option`     |
| `INC_QUEUE`      | std::queue         | `Queue`      |
| `INC_PAIR`       | std::pair          | `Pair`       |
| `INC_TUPLE`      | std::tuple         | `Tuple`      |
| `INC_VECTOR`     | std::vector        | `Vector`     |

### Smart Pointer Aliases (`#define PTR_ALIASES`)

| Type                              | Alias          |
|-----------------------------------|----------------|
| std::unique_ptr                   | `Unique`       |
| std::unique_ptr<T, CustomDeleter> | `UniqueDelete` |
| std::shared_ptr                   | `Shared`       |
| std::weak_ptr                     | `Weak`         |

## Where is `x`?

Either I forgot it exists or don't use it enough to feel it needed an alias, likely both.