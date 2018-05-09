namespace wrapper
{
  template<typename T>
  inline void bind    (simple_wrapper<T> &WrapOne, simple_wrapper<T> &WrapTwo) noexcept
  {
    if(WrapOne.Next != nullptr)
      WrapOne.Next->Prev = WrapOne.Prev;
    if(WrapOne.Prev != nullptr)
      WrapOne.Prev->Next = WrapOne.Next;

    if(WrapTwo.Next != nullptr)
      WrapTwo.Next->Prev = WrapTwo.Prev;
    if(WrapOne.Prev != nullptr)
      WrapTwo.Prev->Next = WrapTwo.Next;

    WrapOne.Next = &WrapTwo;
    WrapTwo.Prev = &WrapOne;
  }
  template<typename T>
  inline void breakOff(simple_wrapper<T> &WrapOne, simple_wrapper<T> &WrapTwo) noexcept
  {
    if(WrapOne.Next == &WrapTwo)
      WrapOne.Next = nullptr;
    if(WrapTwo.Prev == &WrapOne)
      WrapTwo.Prev = nullptr;
  }
}
