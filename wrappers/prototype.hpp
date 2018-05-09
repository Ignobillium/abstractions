#ifndef _PROTOTYPE_
  #define _PROTOTYPE_

  namespace wrapper
  {
    template<typename itemType>
    class prototype
    {
    protected:
      itemType WrappedItem;

      prototype<itemType> *Next;
      prototype<itemType> *Prev;
    public:
               prototype() noexcept;
      virtual ~prototype() noexcept;
    };
  }

  #include "prototype.cpp"

#endif
