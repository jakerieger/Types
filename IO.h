// Author: Jake Rieger
// Created: 10/13/2024.
//

#pragma once

#include <filesystem>

namespace FileSystem = std::filesystem;
using Path           = std::filesystem::path;
using Directory      = std::filesystem::directory_entry;
using DirectoryIter  = std::filesystem::directory_iterator;