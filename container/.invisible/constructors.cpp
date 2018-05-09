namespace manager
{
  template<typename T>
  box_manager<T>::box_manager() noexcept
  {
    /*
    ItemIndex = 0;
    Size = 0;
    LastItem = new simple_box<T>;
    Item     = new simple_box<T>;

    LastItem->Next = nullptr;
    LastItem->Prev = Item;

    Item->Item = 0;
    Item->Next = LastItem;
    Item->Prev = nullptr;

    FirstItem = Item;
    */
    LastItem = new simple_box<T>;
    LastItem->Prev = new simple_box<T>;
    LastItem->Next = nullptr;

    Item = LastItem->Prev;
    Item->Prev = nullptr;
    Item->Next = LastItem;
    
    FirstItem = Item;
  }

  template<typename T>
  box_manager<T>::~box_manager() noexcept
  {
    if(Item)
    {
      Item->clearChain();
      //free(FirstItem);
      //free(LastItem);
    }
  }

  template<typename T>
  box_manager<T>::box_manager(const box_manager<T>& BM)
  {
    ItemIndex = 0;
    Size = 0;

    Item      = new simple_box<T>;     Item->Prev = nullptr;
    LastItem  = new simple_box<T>; LastItem->Next = nullptr;
    FirstItem = Item;

    simple_box<T> *Current = Item;

    if(BM.FirstItem)
    {
      Item->Item = BM.FirstItem->Item;
      ++Size;

      simple_box<T> *CurrentBM = BM.FirstItem->Next;
      while(CurrentBM != nullptr)
      {
        Current->Next = new simple_box<T>;
          *Current->Next->Item = *CurrentBM->Item;
           Current->Next->Prev = Current;

        CurrentBM = CurrentBM->Next;

        ++Size;
      }
    }
    LastItem->Prev = Current;
    Current->Next = LastItem;
  }
}
