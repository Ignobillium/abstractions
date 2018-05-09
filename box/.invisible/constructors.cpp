namespace box
{
  template<typename T>
  simple_box<T>::simple_box() noexcept
  {
    Item = T();
    Prev = nullptr;
    Next = nullptr;
  }

  template<typename T>
  simple_box<T>::simple_box(const simple_box<T>& SB) noexcept
  {
    Item = SB.Item;
    Next = SB.Next;
    Prev = SB.Prev;
  }

  template<typename T>
  simple_box<T>::~simple_box() noexcept
  {
    if(Next != nullptr)
      Next->Prev = Prev;
    if(Prev != nullptr)
      Prev->Next = Next;

    Item.~T();
  }
}
