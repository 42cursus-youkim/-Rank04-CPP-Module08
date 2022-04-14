#include <exception>
#include <iostream>
#include <string>
#include "Span.hpp"
#include "util.hpp"

using std::cout;
using std::string;

void print_spans(const Span& sp) {
  log::val("shortest", sp.shortestSpan());
  log::val("longest ", sp.longestSpan());
}

void test_stress() {
  test::header("Stress test");
  {
    test::subject("random 1,000,000 value");
    std::srand(std::time(NULL));
    Span sp(1000000);

    for (int i = 0; i < 1000000; ++i)
      sp.addNumber(std::rand());

    print_spans(sp);
  }
  {
    test::subject("1 to 1,000,000");
    Span sp(1000000);

    for (int i = 1; i <= 1000000; ++i)
      sp.addNumber(i);

    print_spans(sp);
  }
}

void test_errors() {
  test::header("Errors");
  {
    test::subject("invalid access on empty Span");
    Span sp = Span(5);
    TEST_ASSERT_THROW({ LOG_VAL(sp.longestSpan()); });
    TEST_ASSERT_THROW({ LOG_VAL(sp.shortestSpan()); });
  }
  {
    test::subject("add with single value (size 5)");
    Span sp(5);
    TEST_ASSERT_THROW({
      for (int i = 0; i < 6; ++i) {
        sp.addNumber(i);
        log::val("inserted", i);
      }
    });
  }
  {
    test::subject("add with iterator (size 10)");
    Span sp(10);

    std::vector<int> v(11);
    for (int i = 0; i < 11; ++i)
      v[i] = i;

    TEST_ASSERT_THROW({
      sp.addNumber(v.begin(), v.end());
      print_spans(sp);
    });
  }
  {
    test::subject("size too small (0, { })");
    Span sp(10);
    TEST_ASSERT_THROW({ LOG_VAL(sp.longestSpan()); });
    TEST_ASSERT_THROW({ LOG_VAL(sp.shortestSpan()); });
    sp.addNumber(1);
    test::subject("size too small (1, { 1 })");
    TEST_ASSERT_THROW({ LOG_VAL(sp.longestSpan()); });
    TEST_ASSERT_THROW({ LOG_VAL(sp.shortestSpan()); });
    test::subject("size is OK (2, { 1, 12 })");
    sp.addNumber(12);
    print_spans(sp);
    test::subject("size is OK (3, { 1, 4, 12 })");
    sp.addNumber(4);
    print_spans(sp);
  }
}

void test_general() {
  test::header("General Cases");
  {
    test::subject("add with single value { 5, 3, 17, 9, 11 }");
    Span sp = Span(5);
    int arr[] = {5, 3, 17, 9, 11};
    for (int i = 0; i < 5; i++)
      sp.addNumber(arr[i]);

    print_spans(sp);
  }
  {
    test::subject("add with iterator { 1 .. 10 }");
    Span sp(10);

    std::vector<int> v(10);
    for (int i = 0; i < 10; ++i)
      v[i] = i;

    sp.addNumber(v.begin(), v.end());
    print_spans(sp);
  }
  {
    test::subject("same values { 5, 5, 5, 5, 5 }");
    Span sp = Span(5);
    for (int i = 0; i < 5; i++)
      sp.addNumber(5);
    print_spans(sp);
  }
  {
    test::subject("smol values { 1, 3 }");
    Span sp = Span(2);
    sp.addNumber(1);
    sp.addNumber(3);
    print_spans(sp);
  }
}

int main() {
  test_stress();
  test_errors();
  test_general();
  return 0;
}
