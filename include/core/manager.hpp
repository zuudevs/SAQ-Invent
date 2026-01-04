#pragma once

#include "registry/table.hpp"
#include <cstddef>
#include <unordered_map>

namespace saq {

class Manager {
private:
	Table table;
	std::unordered_map<std::string, std::size_t> qty;

public:
	Manager() = default;
	~Manager() = default;

	Manager(const Manager&) = delete;
	Manager(Manager&&) = delete;
	Manager& operator=(const Manager&) = delete;
	Manager& operator=(Manager&&) = delete;

	const Item& getItem(const std::string& code) const noexcept { return table.get(code); }
	Item& getItem(const std::string& code) noexcept { return table.get(code); }

	Manager& addItem(const Item& item) noexcept { table.push(item); return *this; }
	Manager& removeItem(const std::string& code) noexcept { table.pop(code); return *this; }

} ;

} // namespace saq