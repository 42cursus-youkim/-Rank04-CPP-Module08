#include <iostream>
#include <string>
#include "Span.hpp"

using std::cout;
using std::string;

void printSpan(const Span& span) {
  cout << "shortest span: " << span.shortestSpan() << '\n';
  cout << "longest span : " << span.longestSpan() << '\n';
}

void testBasic() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  printSpan(sp);
}

void testFail() {
  try {
    Span sp = Span(1);
  } catch (std::exception& e) {
    cout << e.what() << "\n";
  }
  try {
    Span sp = Span(2);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(11);
  } catch (std::exception& e) {
    cout << e.what() << "\n";
  }
}

void testStress() {
  Span sp = Span(10000);
  for (int i = 0; i < 10000; i++)
    sp.addNumber(i);
  printSpan(sp);
}

int main() {
  testBasic();
  testStress();
  testFail();
  return 0;
}