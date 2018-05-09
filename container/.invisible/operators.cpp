namespace manager
{
  template<typename T>
  box_manager<T> box_manager<T>::operator= (const box_manager<T>& BM) noexcept
  {
    if (this != &BM)
    {
      if(Item)
      {
        Item->clearChain();
        free(FirstItem);
        free(LastItem);
      }

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

    return *this;
  }
}
