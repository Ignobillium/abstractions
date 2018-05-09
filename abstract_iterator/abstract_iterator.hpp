#ifndef _ABSTRACT_ITERATOR_
  #define _ABSTRACT_ITERATOR_

  #ifndef _STD_ITERATOR_
    #define _STD_ITERATOR_
    #include <iterator>
  #endif

  #ifndef _IOSTREAM_
    #define _IOSTREAM_
    #include <iostream>
  #endif

  #include "../box/simple_box.hpp"

  template <typename T>
  class abstract_iterator : public std::iterator<std::random_access_iterator_tag, T>
  {
  public:
    box::simple_box<T> *Current;
    unsigned            Index;
  public:
    bool operator!=(abstract_iterator<T> const& it) const noexcept { return Index != it.Index; }
    bool operator==(abstract_iterator<T> const& it) const noexcept { return Index == it.Index; }
    bool operator< (abstract_iterator<T> const& it) const noexcept { return Index <  it.Index; }
    bool operator> (abstract_iterator<T> const& it) const noexcept { return Index >  it.Index; }
    bool operator<=(abstract_iterator<T> const& it) const noexcept { return Index <= it.Index; }
    bool operator>=(abstract_iterator<T> const& it) const noexcept { return Index >= it.Index; }

    abstract_iterator<T>& operator++()    noexcept;
    abstract_iterator<T>& operator++(int) noexcept { return ++(*this); }
    abstract_iterator<T>& operator--()    noexcept;
    abstract_iterator<T>& operator--(int) noexcept { return --(*this); }

    abstract_iterator<T>& operator+ (const int n) noexcept;
    abstract_iterator<T>& operator+=(const int n) noexcept { return (*this + n); }
    abstract_iterator<T>& operator- (const int n) noexcept;
    abstract_iterator<T>& operator-=(const int n) noexcept { return (*this - n); }

    typename abstract_iterator<T>::reference operator*() const noexcept;

     abstract_iterator() noexcept;
     abstract_iterator(const abstract_iterator<T>& it) noexcept;
    ~abstract_iterator() noexcept;
  protected:
     abstract_iterator(const box::simple_box<T>* item, const unsigned index) noexcept;
     abstract_iterator(const box::simple_box<T>* item) noexcept;
  };

  #include "abstract_iterator.cpp"

#endif
