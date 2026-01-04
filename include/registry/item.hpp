#pragma once

#include "state.hpp"
#include <cstddef>
#include <map>
#include <string>
#include <string_view>

namespace saq {

class Item {
public:
	std::string name;
	std::string brand;
	std::string code;
	std::string location;
	std::string detail;
	State state;

	Item() = default;
	~Item() = default;

	Item(std::string_view name, 
		std::string_view brand, 
		std::string_view code, 
		std::string_view location, 
		State state = State::None, std::string_view detail = ""
	) : name(name), brand(brand), 
		code(code), location(location), 
		detail(detail), state(state) {}
} ;

} // namespace saq