namespace wrapper
{
  template<typename itemType>
  simple_wrapper<itemType>& simple_wrapper<itemType>::operator= (const simple_wrapper<itemType>& AnotherOne) noexcept
  {
    if (this != &AnotherOne)
    {
      this->~simple_wrapper<itemType>();

      WrappedItem = AnotherOne.WrappedItem;

      Next = AnotherOne.Next;
      Prev = AnotherOne.Prev;
    }

    return *this;
  }

  template<typename itemType>
  simple_wrapper<itemType>& simple_wrapper<itemType>::operator= (const itemType& item) noexcept
  {
    WrappedItem = item;
    return *this;
  }
}
