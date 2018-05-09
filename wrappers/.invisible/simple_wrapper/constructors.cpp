namespace wrapper
{

  template<typename itemType>
  simple_wrapper<itemType>::simple_wrapper() noexcept
  {

  }

  template<typename itemType>
  simple_wrapper<itemType>::~simple_wrapper() noexcept
  {
    WrappedItem.~itemType();

    if(Next != nullptr) Next->Prev = Prev;
    if(Prev != nullptr) Prev->Next = Next;
  }


  template<typename itemType>
  simple_wrapper<itemType>::simple_wrapper(const itemType& Item) noexcept
  {
    WrappedItem = Item;

    Next = nullptr;
    Prev = nullptr;
  }

  template<typename itemType>
  simple_wrapper<itemType>::simple_wrapper(const simple_wrapper<itemType>& Original) noexcept
  {
    WrappedItem = Original.WrappedItem;

    Next = Original.Next;
    Prev = Original.Prev;
  }
}
