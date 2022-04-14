#ifndef __UTIL_H__
#define __UTIL_H__

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include "color.hpp"

using std::cerr;
using std::cout;
using std::string;

// Logger

#define LOG_VAL(x) log::val(#x, x)

#define LOG_CLASS_COPY log::val(__func__, GRN "is copy constructed")
#define LOG_CLASS                                    \
  do {                                               \
    const string specialMethod = __func__;           \
    if (specialMethod.at(0) == '~')                  \
      log::val(specialMethod, RED "is destructed");  \
    else if (specialMethod == "operator=")           \
      log::val(specialMethod, YEL "is assigned");    \
    else                                             \
      log::val(specialMethod, GRN "is constructed"); \
  } while (0)

namespace log {

template <typename T>
void val(const string& str, T value) {
  cout << BBLU << str << HYEL ": " MAG << value << END "\n";
}

}  // namespace log

// Test
#define TEST_ASSERT_EQ(left, right)                            \
  do {                                                         \
    assert(left == right);                                     \
    cout << HWHT "{ assert " BBLU << #left << " == " << #right \
         << HWHT " } " BGRN " OK!\n" END;                      \
  } while (0);

#define TEST_ASSERT_THROW(block)                                       \
  try {                                                                \
    block;                                                             \
    cout << BRED "TEST_ASSERT_THROW failed: expected exception!\n" END \
         << #block << " should throw exception but did not.";          \
    exit(1);                                                           \
  } catch (const std::exception& e) {                                  \
    cout << #block << CYN "\n    throws " BMAG "-> " RED << e.what()   \
         << BGRN " OK !\n" END;                                        \
  }

namespace test {

template <typename T>
void header(T const& t) {
  cout << BHYEL << string(40, '-') << "\n";
  cout << "[[[ Testing " BBLU << t << BHYEL " ]]]\n" END;
}

template <typename T>
void subject(T const& t) {
  cout << MAG "\n[ case " BCYN << t << MAG " ]\n" END;
}

}  // namespace test

#endif  // __UTIL_H__
