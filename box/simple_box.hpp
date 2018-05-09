#ifndef _SIMPLE_BOX_
  #define _SIMPLE_BOX_

  #ifndef _CSTDLIB_
    #define _CSTDLIB_
    #include <cstdlib>
  #endif

  namespace box
  {
    template<typename T>
    struct simple_box
    {
      T Item;

      simple_box<T> *Prev;
      simple_box<T> *Next;

      void clearForward()  noexcept;
      void clearBackward() noexcept;
      void clearChain()   noexcept;

      simple_box<T>& operator= (const simple_box& SB) noexcept;

       simple_box() noexcept;
       simple_box(const simple_box<T>& SB) noexcept;
      ~simple_box() noexcept;
    };

    template<typename T>
    inline void bind(simple_box<T> &BoxOne, simple_box<T> &BoxTwo) noexcept;
    template<typename T>
    inline void breakOff(simple_box<T> &BoxOne, simple_box<T> &BoxTwo) noexcept;
  } // end of "box" namespace

  #include "simple_box.cpp"

#endif
