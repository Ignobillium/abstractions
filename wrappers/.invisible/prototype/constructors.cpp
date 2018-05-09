namespace wrapper
{
  prototype::prototype() noexcept
  {
    WrappedItem = itemType();
    Next = nullptr;
    Prev = nullptr;
  }

  prototype::~prototype() noexcept
  {
    if (Next != nullptr) Next->Prev = Prev;
    if (Prev != nullptr) Prev->Next = Next;

    WrappedItem.~itemType();
  }
}
