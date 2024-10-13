// Author: Jake Rieger
// Created: 10/13/2024.
//

#pragma once

#include <memory>

template<typename T>
using Unique = std::unique_ptr<T>;

template<typename T, typename D>
using UniqueDelete = std::unique_ptr<T, D>;

template<typename T>
using Shared = std::shared_ptr<T>;

template<typename T>
using Weak = std::weak_ptr<T>;