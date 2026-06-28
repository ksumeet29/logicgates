#include "gates.hpp"

namespace {

bool is_binary(const std::string& value) {
  if (value.empty()) {
    return false;
  }
  for (char c : value) {
    if (c != '0' && c != '1') {
      return false;
    }
  }
  return true;
}

std::string read_binary(const std::string& prompt) {
  std::string value;
  while (true) {
    std::cout << prompt << std::endl;
    std::cin >> value;
    if (is_binary(value)) {
      return value;
    }
    std::cout << "Wrong Entry. Use only 0s and 1s." << std::endl;
  }
}

}  // namespace

int main(int argc, char* argv[]) {
  std::cout << "Adder for binary numbers of arbitrary length" << std::endl;

  std::string a;
  std::string b;

  if (argc == 3) {
    a = argv[1];
    b = argv[2];
    if (!is_binary(a) || !is_binary(b)) {
      std::cerr << "Error: both arguments must be binary (only 0s and 1s)."
                << std::endl;
      return 1;
    }
  } else {
    a = read_binary("Enter first binary number");
    b = read_binary("Enter second binary number");
  }

  std::string sum = add_binary(a, b);

  std::cout << "Sum of " << a << " and " << b << " is " << sum << std::endl;
  return 0;
}