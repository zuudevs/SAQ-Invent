#pragma once

#include <cstdint>

namespace saq {

enum class State : uint8_t {
	None		= 0,
	Broken		= 1 << 0,
	Good		= 1 << 1,
	Borrowed	= 1 << 2
} ;

[[nodiscard]] inline constexpr State operator|(State a, State b) noexcept {
	return static_cast<State>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}

[[nodiscard]] inline constexpr State operator&(State a, State b) noexcept {
	return static_cast<State>(static_cast<uint8_t>(a) & static_cast<uint8_t>(b));
}

[[nodiscard]] inline constexpr State operator^(State a, State b) noexcept {
	return static_cast<State>(static_cast<uint8_t>(a) ^ static_cast<uint8_t>(b));
}

[[nodiscard]] inline constexpr State operator~(State a) noexcept {
	return static_cast<State>(~static_cast<uint8_t>(a));
}

[[nodiscard]] inline constexpr bool isBorrowed(State state) noexcept {
	return (state & State::Broken) == State::Broken;
}

} // namespace sq::state