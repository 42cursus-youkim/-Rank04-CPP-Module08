#ifndef __MUTANTSTACK_TPP__
#define __MUTANTSTACK_TPP__

#include "mutantstack.hpp"

#ifndef __MUTANTSTACK_H__
#error __FILE__ should only be included from myclass.hpp.
#endif  // __MUTANTSTACK_H__

// constructor & Destructors
template <typename T>
MutantStack<T>::MutantStack() : MutantStack<T>::stack(){};

template <typename T>
MutantStack<T>::MutantStack(MutantStack const& other)
    : MutantStack<T>::stack(other) {}

template <typename T>
MutantStack<T>::~MutantStack(){};

// Operator
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> const& other) {
  if (this != &other)
    MutantStack<T>::stack::operator=(other);
  return (*this);
}

// Iterator
template <typename T>
typename MutantStack<T>::mutant_container_type::iterator
MutantStack<T>::begin() {
  return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::mutant_container_type::iterator MutantStack<T>::end() {
  return (this->c.end());
}

// Const Iterator
template <typename T>
typename MutantStack<T>::mutant_container_type::const_iterator
MutantStack<T>::begin() const {
  return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::mutant_container_type::const_iterator
MutantStack<T>::end() const {
  return (this->c.end());
}

// Reverse Iterator
template <typename T>
typename MutantStack<T>::mutant_container_type::reverse_iterator
MutantStack<T>::rbegin() {
  return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::mutant_container_type::reverse_iterator
MutantStack<T>::rend() {
  return (this->c.rend());
}

// Const Reverse Iterator`
template <typename T>
typename MutantStack<T>::mutant_container_type::const_reverse_iterator
MutantStack<T>::rbegin() const {
  return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::mutant_container_type::const_reverse_iterator
MutantStack<T>::rend() const {
  return (this->c.rend());
}

#endif  // __MUTANTSTACK_TPP__