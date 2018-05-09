namespace box
{
  template<typename T>
  inline void bind(simple_box<T> &BoxOne, simple_box<T> &BoxTwo) noexcept
  {
    if(BoxOne.Next != nullptr)
      BoxOne.Next->Prev = BoxOne.Prev;
    if(BoxOne.Prev != nullptr)
      BoxOne.Prev->Next = BoxOne.Next;

    if(BoxTwo.Next != nullptr)
      BoxTwo.Next->Prev = BoxTwo.Prev;
    if(BoxOne.Prev != nullptr)
      BoxTwo.Prev->Next = BoxTwo.Next;

    BoxOne.Next = &BoxTwo;
    BoxTwo.Prev = &BoxOne;
  }

  template<typename T>
  inline void breakOff(simple_box<T> &BoxOne, simple_box<T> &BoxTwo) noexcept
  {
    if(BoxOne.Next == &BoxTwo)
      BoxOne.Next = nullptr;
    if(BoxTwo.Prev == &BoxOne)
      BoxTwo.Prev = nullptr;
  }
}
