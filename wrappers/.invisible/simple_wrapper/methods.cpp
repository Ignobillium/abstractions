namespace wrapper
{
  template<typename itemType>
  itemType simple_wrapper<itemType>::get() const noexcept
  {
    return WrappedItem;
  }

  template<typename itemType>
  void simple_wrapper<itemType>::clearForward() noexcept
  {
    simple_wrapper<itemType> *Current = Next, *Temp;

    while(Current != nullptr)
    {
      Temp    = Current;
      Current = Current->Next;

      Temp->WrappedItem.~itemType();
      free(Temp);
    }
  }

  template<typename itemType>
  void simple_wrapper<itemType>::clearBackward() noexcept
  {
    simple_wrapper<itemType> *Current = Prev, *Temp;

    while(Current != nullptr)
    {
      Temp    = Current;
      Current = Current->Prev;

      Temp->WrappedItem.~itemType();
      free(Temp);
    }
  }

  template<typename itemType>
  void simple_wrapper<itemType>::clearChain() noexcept
  {
    clearForward();
    clearBackward();
  }

  template<typename itemType>
  simple_wrapper<itemType>& simple_wrapper<itemType>::copyForwardChain() const noexcept
  {
    simple_wrapper<itemType> *Temp,
                      *Current = this,
                      *NewCurrent = new simple_wrapper<itemType>,
                      *Head = NewCurrent;

    NewCurrent->Prev = nullptr;
    NewCurrent->Next = nullptr;

    NewCurrent->WrappedItem = WrappedItem;

    while(Current->Next != nullptr)
    {
      Current = Current->Next;

      Temp = new simple_wrapper<itemType>;

      Temp->WrappedItem = Current->WrappedItem;
      Temp->Next = nullptr;
      Temp->Prev = NewCurrent;

      NewCurrent->Next = Temp;
      NewCurrent = Temp;
    }
    NewCurrent = Temp = nullptr;

    return *Head;
  }

  template<typename itemType>
  simple_wrapper<itemType>& simple_wrapper<itemType>::copyBackwardChain() const noexcept
  {
    simple_wrapper<itemType> *Temp,
                      *Current = this,
                      *NewCurrent = new simple_wrapper<itemType>,
                      *Head = NewCurrent;

    NewCurrent->Prev = nullptr;
    NewCurrent->Next = nullptr;

    NewCurrent->WrappedItem = WrappedItem;

    while(Current->Prev != nullptr)
    {
      Current = Current->Prev;

      Temp = new simple_wrapper<itemType>;

      Temp->WrappedItem = Current->WrappedItem;
      Temp->Next = NewCurrent;
      Temp->Prev = nullptr;

      NewCurrent->Prev = Temp;
      NewCurrent = Temp;
    }
    NewCurrent = Temp = nullptr;

    return *Head;
  }

  template<typename itemType>
  simple_wrapper<itemType>& simple_wrapper<itemType>::copyChain() const noexcept
  {
    simple_wrapper<itemType> *BackwardPart = copyBackwardChain(),
                             *ForwardPart  = copyForwardChain(),
                             *Res = ForwardPart;

    BackwardPart->Next = Res->Next;
    Res->Next->Prev = BackwardPart;
    Res->~simple_wrapper<itemType>();

    Res = BackwardPart;
    while(Res->Prev != nullptr)
      Res = Res->Prev;

    return Res;
  }
}
