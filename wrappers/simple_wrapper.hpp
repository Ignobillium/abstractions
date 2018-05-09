#ifndef _SIMPLE_WRAPPER_
  #define _SIMPLE_WRAPPER_

  #ifndef _CSTDLIB_
    #define _CSTDLIB_
    #include <cstdlib>
  #endif

  namespace wrapper
  {
    template<typename itemType>
    class simple_wrapper
    {
    protected:
      itemType WrappedItem;

      simple_wrapper<itemType> *Next;
      simple_wrapper<itemType> *Prev;
    public:
      itemType get() const noexcept;

      void clearForward()  noexcept;
      void clearBackward() noexcept;
      void clearChain()    noexcept;

      simple_wrapper<itemType>& copyForwardChain()  const noexcept;
      simple_wrapper<itemType>& copyBackwardChain() const noexcept;

      simple_wrapper<itemType>& copyChain() const noexcept;

       simple_wrapper() noexcept;
      ~simple_wrapper() noexcept;

      simple_wrapper(const itemType& Item) noexcept;
      simple_wrapper(const simple_wrapper<itemType>& Original) noexcept;

      simple_wrapper<itemType>& operator= (const simple_wrapper<itemType>& AnotherOne) noexcept;
      simple_wrapper<itemType>& operator= (const itemType& item) noexcept;

      /*
      simple_wrapper<itemType>& operator+= (const itemType& OtherOne) noexcept { return *this +  OtherOne; }
      simple_wrapper<itemType>& operator-= (const itemType& OtherOne) noexcept { return *this -  OtherOne; }
      simple_wrapper<itemType>& operator*= (const itemType& OtherOne) noexcept { return *this *  OtherOne; }
      simple_wrapper<itemType>& operator/= (const itemType& OtherOne) noexcept { return *this /  OtherOne; }
      simple_wrapper<itemType>& operator%= (const itemType& OtherOne) noexcept { return *this %  OtherOne; }
      simple_wrapper<itemType>& operator&= (const itemType& OtherOne) noexcept { return *this &  OtherOne; }
      simple_wrapper<itemType>& operator|= (const itemType& OtherOne) noexcept { return *this |  OtherOne; }
      simple_wrapper<itemType>& operator^= (const itemType& OtherOne) noexcept { return *this ^  OtherOne; }
      simple_wrapper<itemType>& operator<<=(const itemType& OtherOne) noexcept { return *this << OtherOne; }
      simple_wrapper<itemType>& operator>>=(const itemType& OtherOne) noexcept { return *this >> OtherOne; }

      /// ******************************
      /// Unary operators overloading  *
      /// ******************************
      itemType& operator- (const simple_wrapper<itemType>& Object)   noexcept const { return -Object.WrappedItem; }
      itemType& operator+ (const simple_wrapper<itemType>& Object)   noexcept const { return  Object.WrappedItem; }
      itemType& operator~ (const simple_wrapper<itemType>& Object)   noexcept const { return ~Object.WrappedItem; }
      itemType& operator! (const simple_wrapper<itemType>& Object)   noexcept const { return !Object.WrappedItem; }

      itemType& operator++(const simple_wrapper<itemType>& Object)   noexcept const { return ++WrappedItem; }
      itemType& operator--(const simple_wrapper<itemType>& Object)   noexcept const { return ++WrappedItem; }

      itemType& operator++(int) noexcept const{ return ++(*this); }
      itemType& operator--(int) noexcept const{ return --(*this); }

      /// ******************************
      /// Binary operators overloading *
      /// ******************************
      friend itemType& operator+ (const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator- (const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator* (const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator/ (const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator% (const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;

      friend itemType& operator< (const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator> (const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator<=(const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator>=(const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator==(const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator!=(const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;

      friend itemType& operator<<(const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator>>(const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator& (const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator| (const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator^ (const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;

      friend itemType& operator&&(const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator||(const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;

      friend itemType& operator, (const simple_wrapper<itemType>& Object, const itemType& Item) noexcept;


      friend itemType& operator+ (const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;
      friend itemType& operator- (const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;
      friend itemType& operator* (const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;
      friend itemType& operator/ (const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;
      friend itemType& operator% (const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;

      friend bool operator< (const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;
      friend bool operator> (const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;
      friend bool operator<=(const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;
      friend bool operator>=(const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;
      friend bool operator==(const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;
      friend bool operator!=(const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;

      friend itemType& operator<<(const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;
      friend itemType& operator>>(const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;
      friend itemType& operator& (const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;
      friend itemType& operator| (const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;
      friend itemType& operator^ (const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;

      friend itemType& operator&&(const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;
      friend itemType& operator||(const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;

      friend itemType& operator, (const itemType& Item, const simple_wrapper<itemType>& Object) noexcept;
      */
    };

    template<typename T>
    inline void bind    (simple_wrapper<T> &WrapOne, simple_wrapper<T> &WrapTwo) noexcept;
    template<typename T>
    inline void breakOff(simple_wrapper<T> &WrapOne, simple_wrapper<T> &WrapTwo) noexcept;
  } // end of "wrapper" namespace

  #include "simple_wrapper.cpp"

#endif
