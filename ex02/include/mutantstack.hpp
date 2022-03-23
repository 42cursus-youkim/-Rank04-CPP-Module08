#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__

#include <algorithm>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  // constructor & Destructors
  MutantStack();
  MutantStack(MutantStack const& other);
  ~MutantStack();
  // operator
  MutantStack<T>& operator=(MutantStack<T> const& other);

  // iterators type definition
  typedef typename MutantStack<T>::stack::container_type mutant_container_type;
  typedef typename mutant_container_type::iterator iterator;
  typedef typename mutant_container_type::const_iterator const_iterator;
  typedef typename mutant_container_type::reverse_iterator reverse_iterator;
  typedef typename mutant_container_type::const_reverse_iterator
      const_reverse_iterator;

  // iterator functions
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
  reverse_iterator rbegin();
  reverse_iterator rend();
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
};

#include "mutantstack.tpp"

#endif  // __MUTANTSTACK_H__
