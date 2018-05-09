#include "abstract_iterator.hpp"

template <typename T>
abstract_iterator<T>& abstract_iterator<T>::operator++() noexcept
{
  if (Current->Next != nullptr)
  {
    Current = Current->Next;
    ++Index;
  }
  else
    exit(-1);
  return *this;
}


template <typename T>
abstract_iterator<T>& abstract_iterator<T>::operator--() noexcept
{
  if (Current->Prev != nullptr)
  {
    Current = Current->Prev;
    --Index;
  }
  else
    exit(-1);
  return *this;
}

template <typename T>
abstract_iterator<T>& abstract_iterator<T>::operator+ (const int n) noexcept
{
  if (n >= 0)
    for(int i = 0; i < n; ++i)
      ++(*this);
  else
    for(int i = 0; i > n; --i)
      --(*this);

  return *this;
}

template <typename T>
abstract_iterator<T>& abstract_iterator<T>::operator- (const int n) noexcept
{
  if (n >= 0)
    for(int i = 0; i < n; ++i)
      --(*this);
  else
    for(int i = 0; i > n; --i)
      ++(*this);

  return *this;
}

template <typename T>
typename abstract_iterator<T>::reference abstract_iterator<T>::operator*() const noexcept
{
  return (Current->Item);
}

template <typename T>
abstract_iterator<T>::abstract_iterator() noexcept
{
  Current = new box::simple_box<T>;
  Index = 0;
}

template <typename T>
abstract_iterator<T>::abstract_iterator(const abstract_iterator<T>& it) noexcept
{
  Current = new box::simple_box<T>;
   *Current = *it.Current;
  Index = it.Index;
}

template <typename T>
abstract_iterator<T>::~abstract_iterator() noexcept
{
 //delete Current;
}

template <typename T>
abstract_iterator<T>::abstract_iterator(const box::simple_box<T>* item, const unsigned index) noexcept
{
  Current = const_cast<box::simple_box<T>*>(item);
  Index = index;
}

template <typename T>
abstract_iterator<T>::abstract_iterator(const box::simple_box<T>* item) noexcept
{
  Current = const_cast<box::simple_box<T>*>(item);
  abstract_iterator<T>* Temp = Current;

  Index = 0;
  while(Temp->Prev != nullptr)
  {
    ++Index;
    Temp = Temp->Prev;
  }
  Temp = nullptr;
}
