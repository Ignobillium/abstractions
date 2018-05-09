#ifndef _COMPLETE_WRAPPER_
  #define _COMPLETE_WRAPPER_

  #ifndef _CSTDLIB_
    #define _CSTDLIB_
    #include <cstdlib>
  #endif

  #include "prototype.hpp"

  namespace wrapper
  {
    template<typename itemType>
    class complete_wrapper: public prototype<itemType>
    {
    public:
      /// **************
      /// Methods      *
      /// **************
      itemType get() const noexcept;

      void clearForward()  noexcept;
      void clearBackward() noexcept;
      void clearChain()    noexcept;

      complete_wrapper<itemType>& getForwardPart()  noexcept const;
      complete_wrapper<itemType>& getBackwardPart() noexcept const;

      /// **************
      /// Constructors *
      /// **************
       complete_wrapper() noexcept;
      ~complete_wrapper() noexcept;

      complete_wrapper(const itemType& Item) noexcept;
      complete_wrapper(const complete_wrapper<itemType>& Original) noexcept;

      /// ***********************
      /// Operators overloading *
      /// ***********************
      complete_wrapper<itemType>& operator= (const complete_wrapper<itemType>& OtherOne) noexcept;

      complete_wrapper<itemType>& operator= (const itemType& OtherOne) noexcept;

      complete_wrapper<itemType>& operator+= (const itemType& OtherOne) noexcept { return *this +  OtherOne; }
      complete_wrapper<itemType>& operator-= (const itemType& OtherOne) noexcept { return *this -  OtherOne; }
      complete_wrapper<itemType>& operator*= (const itemType& OtherOne) noexcept { return *this *  OtherOne; }
      complete_wrapper<itemType>& operator/= (const itemType& OtherOne) noexcept { return *this /  OtherOne; }
      complete_wrapper<itemType>& operator%= (const itemType& OtherOne) noexcept { return *this %  OtherOne; }
      complete_wrapper<itemType>& operator&= (const itemType& OtherOne) noexcept { return *this &  OtherOne; }
      complete_wrapper<itemType>& operator|= (const itemType& OtherOne) noexcept { return *this |  OtherOne; }
      complete_wrapper<itemType>& operator^= (const itemType& OtherOne) noexcept { return *this ^  OtherOne; }
      complete_wrapper<itemType>& operator<<=(const itemType& OtherOne) noexcept { return *this << OtherOne; }
      complete_wrapper<itemType>& operator>>=(const itemType& OtherOne) noexcept { return *this >> OtherOne; }

      /// ******************************
      /// Unary operators overloading  *
      /// ******************************
      itemType& operator- (const complete_wrapper<itemType>& Object)   noexcept const { return -Object.WrappedItem; }
      itemType& operator+ (const complete_wrapper<itemType>& Object)   noexcept const { return  Object.WrappedItem; }
      itemType& operator~ (const complete_wrapper<itemType>& Object)   noexcept const { return ~Object.WrappedItem; }
      itemType& operator! (const complete_wrapper<itemType>& Object)   noexcept const { return !Object.WrappedItem; }

      itemType& operator++(const complete_wrapper<itemType>& Object)   noexcept const { return ++WrappedItem; }
      itemType& operator--(const complete_wrapper<itemType>& Object)   noexcept const { return ++WrappedItem; }

      itemType& operator++(int) noexcept const{ return ++(*this); }
      itemType& operator--(int) noexcept const{ return --(*this); }

      /// ******************************
      /// Binary operators overloading *
      /// ******************************
      friend itemType& operator+ (const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator- (const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator* (const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator/ (const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator% (const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;

      friend itemType& operator< (const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator> (const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator<=(const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator>=(const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator==(const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator!=(const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;

      friend itemType& operator<<(const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator>>(const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator& (const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator| (const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator^ (const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;

      friend itemType& operator&&(const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;
      friend itemType& operator||(const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;

      friend itemType& operator, (const complete_wrapper<itemType>& Object, const itemType& Item) noexcept;


      friend itemType& operator+ (const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;
      friend itemType& operator- (const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;
      friend itemType& operator* (const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;
      friend itemType& operator/ (const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;
      friend itemType& operator% (const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;

      friend bool operator< (const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;
      friend bool operator> (const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;
      friend bool operator<=(const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;
      friend bool operator>=(const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;
      friend bool operator==(const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;
      friend bool operator!=(const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;

      friend itemType& operator<<(const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;
      friend itemType& operator>>(const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;
      friend itemType& operator& (const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;
      friend itemType& operator| (const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;
      friend itemType& operator^ (const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;

      friend itemType& operator&&(const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;
      friend itemType& operator||(const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;

      friend itemType& operator, (const itemType& Item, const complete_wrapper<itemType>& Object) noexcept;
    };

    template<typename T>
    inline void bind    (complete_wrapper<T> &BoxOne, complete_wrapper<T> &BoxTwo) noexcept;
    template<typename T>
    inline void breakOff(complete_wrapper<T> &BoxOne, complete_wrapper<T> &BoxTwo) noexcept;
  } // end of "wrapper" namespace

  #include "complete_wrapper.cpp"

#endif
