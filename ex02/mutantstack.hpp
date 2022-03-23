#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__

#include <algorithm>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  // constructor
  MutantStack() : MutantStack<T>::stack(){};
  MutantStack(MutantStack const& other) : MutantStack<T>::stack(other) {}
  // destructor
  ~MutantStack(){};
  // operator
  MutantStack<T>& operator=(MutantStack<T> const& other) {
    if (this != &other)
      MutantStack<T>::stack::operator=(other);
    return (*this);
  }

  // iterators typedef
  typedef typename MutantStack<T>::stack::container_type mutant_container_type;
  typedef typename mutant_container_type::iterator iterator;
  typedef typename mutant_container_type::const_iterator const_iterator;
  typedef typename mutant_container_type::reverse_iterator reverse_iterator;
  typedef typename mutant_container_type::const_reverse_iterator
      const_reverse_iterator;

  // iterator functions
  iterator begin() { return (this->c.begin()); }
  iterator end() { return (this->c.end()); }
  const_iterator begin() const { return (this->c.begin()); }
  const_iterator end() const { return (this->c.end()); }
  reverse_iterator rbegin() { return (this->c.rbegin()); }
  reverse_iterator rend() { return (this->c.rend()); }
  const_reverse_iterator rbegin() const { return (this->c.rbegin()); }
  const_reverse_iterator rend() const { return (this->c.rend()); }
};

#include "mutantstack.cpp"

#endif  // __MUTANTSTACK_H__