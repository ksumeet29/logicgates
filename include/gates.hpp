#ifndef GATES_HPP_
#define GATES_HPP_

#include <iostream>
#include <string>
#include <algorithm>

bool and_gate(bool a, bool b);
bool nand_gate(bool a, bool b);
bool xor_gate(bool a, bool b);
bool not_gate(bool a);
bool or_gate(bool a, bool b);

// Full adder: returns the sum bit and updates carry (carry-in -> carry-out).
bool full_adder(bool a, bool b, bool& carry);

// Adds two MSB-first binary strings of arbitrary length, returns the sum.
std::string add_binary(const std::string& a, const std::string& b);

#endif  // GATES_HPP