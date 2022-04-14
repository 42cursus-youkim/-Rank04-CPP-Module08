#ifndef __SPAN_H__
#define __SPAN_H__

#include <algorithm>
#include <vector>

typedef unsigned int uint;

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

  template <typename T>
  void addNumber(const T& begin, const T& end) {
    const uint size = std::distance(begin, end);
    if (_n < _vec.size() + size)
      throw std::out_of_range("internal storage full");

    _vec.insert(_vec.end(), begin, end);
  }

  size_t shortestSpan() const;
  size_t longestSpan() const;
};

#endif  // __SPAN_H__
