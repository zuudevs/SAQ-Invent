#pragma once

#include "item.hpp"
#include <map>

namespace saq {

class Table {
private:
	static inline std::map<std::string, Item> items;

public:
	Table() = default;
	~Table() = default;

	Table& push(const Item& item) noexcept {
		items[item.code] = item;
		return *this;
	}

	Table& pop(const std::string& code) noexcept {
		items.erase(code);
		return *this;
	}

	const Item& get(const std::string& code) const noexcept { return items.at(code); }
	Item& get(const std::string& code) noexcept { return items.at(code); }
} ;

} // namespace saq