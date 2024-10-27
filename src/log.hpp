#pragma once

#include <format>
#include <iostream>

template <class... Args>
inline void println(std::format_string<Args...> str, Args&&... args) {
	std::cout << std::format(str, std::forward<Args>(args)...) << std::endl;
}
