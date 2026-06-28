#include "gates.hpp"

bool not_gate(bool a) {
  return !a;
}

bool and_gate(bool a, bool b) {
  return a && b;
}

bool nand_gate(bool a, bool b) {
  return not_gate(and_gate(a, b));
}

bool xor_gate(bool a, bool b) {
  return (a == b) ? false : true;
}

// OR derived from existing gates: a OR b == NAND(NOT a, NOT b).
bool or_gate(bool a, bool b) {
  return nand_gate(not_gate(a), not_gate(b));
}

bool full_adder(bool a, bool b, bool& carry) {
  bool a_xor_b = xor_gate(a, b);
  bool sum = xor_gate(a_xor_b, carry);
  bool carry_out = or_gate(and_gate(a, b), and_gate(a_xor_b, carry));
  carry = carry_out;
  return sum;
}

std::string add_binary(const std::string& a, const std::string& b) {
  std::string result;
  bool carry = false;
  int i = static_cast<int>(a.size()) - 1;
  int j = static_cast<int>(b.size()) - 1;

  while (i >= 0 || j >= 0) {
    bool bit_a = (i >= 0) ? (a[i] == '1') : false;
    bool bit_b = (j >= 0) ? (b[j] == '1') : false;
    bool sum = full_adder(bit_a, bit_b, carry);
    result.push_back(sum ? '1' : '0');
    --i;
    --j;
  }

  if (carry) {
    result.push_back('1');
  }

  std::reverse(result.begin(), result.end());
  return result;
}