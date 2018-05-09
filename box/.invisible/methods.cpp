namespace box
{
  template<typename T>
  void simple_box<T>::clearForward()  noexcept
  {
    simple_box<T> *Current = Next, *Temp;

    while(Current != nullptr)
    {
      Temp    = Current;
      Current = Current->Next;

      Temp->Item.~T();
      free(Temp);
    }
  }

  template<typename T>
  void simple_box<T>::clearBackward() noexcept
  {
    simple_box<T> *Current = Prev, *Temp;

    while(Current != nullptr)
    {
      Temp    = Current;
      Current = Current->Prev;

      Temp->Item.~T();
      free(Temp);
    }
  }

  template<typename T>
  void simple_box<T>::clearChain() noexcept
  {
    clearForward();
    clearBackward();
  }
}
