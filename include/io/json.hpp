#pragma once

#include "core/manager.hpp"
#include <fstream>

namespace util {

void json_export(const saq::Manager& manager, const std::string& path);

void json_import(saq::Manager& manager, const std::string& path);

} // namespace util