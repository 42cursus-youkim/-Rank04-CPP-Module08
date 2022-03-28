#ifndef __SPAN_H__
#define __SPAN_H__

#include <algorithm>
#include <vector>

class Span {
 private:
  uint _n;
  std::vector<int> _vec;

  // Disabled Constructor
  Span();

 public:
  // Constructors & Destructor
  Span(uint n);
  Span(const Span& other);
  ~Span();

  // Operators
  Span& operator=(const Span& other);

  // Methods
  typedef std::vector<int>::iterator vec_it;
  void addNumber(int n);
  void addNumber(const vec_it& begin, const vec_it& end);

  size_t shortestSpan() const;
  size_t longestSpan() const;
};

#endif  // __SPAN_H__
