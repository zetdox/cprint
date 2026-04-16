
#pragma once
#include <iostream>
#include <variant>

using namespace std;

// Custom print | C++
// 16.04.2026

// @param value [string / int / value / double / float / char]
// @param tag [string / int / value / double / float / char]
// @param level [0 - info, 1 - warn, 2 - error]
// 
// example: cprint("cprint out", "[CPRINT]"?, 0)
// out: "[CPRINT] cprint out"

void cprint(variant<int, string, char, double, float> value, variant<int, string, char, double, float> tag = "[CPRINT]", const int& level = 0);