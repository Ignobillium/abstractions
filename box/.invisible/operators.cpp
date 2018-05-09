namespace box
{
  template<typename T>
  simple_box<T>& simple_box<T>::operator= (const simple_box<T>& SB) noexcept
  {
    if(this != &SB)
    {
      Item.~T();
      Item = SB.Item;

      if(Next != nullptr)
        Next->Prev = Prev;
      if (Prev != nullptr)
        Prev->Next = Next;

      Prev = SB.Prev;
      Next = SB.Next;
    }

    return *this;
  }
}
