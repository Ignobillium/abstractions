namespace manager
{
  template<typename T>
  T  box_manager<T>::getItem(const unsigned Index) noexcept
  {
    if((Index < Size)&&(Index>=0))
    {
      int deltaIndex = (ItemIndex < Index)*(Index-ItemIndex) + (ItemIndex > Index)*(ItemIndex-Index);
      box::simple_box<T> *Current;

      if ( (Index > Size - Index) &&
           (Index > deltaIndex)     )
      {
        Current = FirstItem;
        ItemIndex = 0;
        while(Index != ItemIndex)
        {
          Current = Current->Next;
          ++ItemIndex;
        }
        Item = Current;
        return Current->Item;
      }
        else if ( (Size - Index > Index)     &&
                  (Size - Index > deltaIndex)  )
                  {
                    Current = LastItem;
                    ItemIndex = Size - 1;
                    while(Index != ItemIndex)
                    {
                      Current = Current->Prev;
                      --ItemIndex;
                    }
                    Item = Current;
                    return Current->Item;
                  }
                  else if ( (deltaIndex > Index)     &&
                            (deltaIndex > Size-Index)  )
                            {
                              Current = Item;
                              if(ItemIndex > Index)
                                while(Index != ItemIndex)
                                {
                                  Current = Current->Prev;
                                  --ItemIndex;
                                }
                              else
                              {
                                while(Index != ItemIndex)
                                {
                                  Current = Current->Next;
                                  ++ItemIndex;
                                }
                              }
                              Item = Current;
                              return Current->Item;
                            }
    }
    else
    {
      exit(-2);
    }
  }

  template<typename T>
  T* box_manager<T>::getChain()               const noexcept
  {
    T* Res = new T[Size];
    box::simple_box<T>* Current = FirstItem;
    for(unsigned i = 0; i < Size; ++i, Current = Current->Next)
      Res[i] = Current->Item;
    return Res;
  }


  template<typename T>
  void box_manager<T>::push(const T item) noexcept
  {
    LastItem->Prev->Next = new box::simple_box<T>;
     LastItem->Prev->Next->Item = item;
     LastItem->Prev->Next->Prev = LastItem->Prev;
     LastItem->Prev->Next->Next = LastItem;
    LastItem->Prev = LastItem->Prev->Next;

    ++Size;
  }

  template<typename T>
  T box_manager<T>::pop ()       noexcept
  {
    T Res = LastItem->Prev->Item;

    LastItem->Prev->~simple_box<T>();

    --Size;

    return Res;
  }

  template<typename T>
  typename box_manager<T>::iterator box_manager<T>::begin() const noexcept
  {
    return box_manager<T>::iterator(FirstItem->Next, 0);
  }

  template<typename T>
  typename box_manager<T>::iterator box_manager<T>::end() const noexcept
  {
    return box_manager<T>::iterator(LastItem, Size);
  }
}
