#ifndef _CONTAINER_
  #define _CONTAINER_

  #include "../box/simple_box.hpp"
  #include "../abstract_iterator/abstract_iterator.hpp"

  #ifndef _CSTDLIB_
    #define _CSTDLIB_
    #include <cstdlib>
  #endif

  namespace manager
  {
    using namespace box;

    template<typename T>
    class box_manager
    {
    protected:
      box::simple_box<T> *Item;
      box::simple_box<T> *LastItem;
      box::simple_box<T> *FirstItem;

      unsigned Size;
      unsigned ItemIndex;
    public:
      T  getItem(const unsigned Index)  noexcept; // must be fixed
      T* getChain()               const noexcept;

      void push(const T item) noexcept;
      T    pop ()             noexcept;

      class iterator;//: public abstract_iterator<T>;
        iterator begin() const noexcept;
        iterator end()   const noexcept;
      /*
      class const_iterator;
        const_iterator begin() const noexcept;
        const_iterator end()   const noexcept;
      */

      box_manager<T> operator= (const box_manager<T>& BM) noexcept;

       box_manager() noexcept;
      ~box_manager() noexcept;

      box_manager(const box_manager<T>& BM);
    };

    template<typename T>
    class box_manager<T>::iterator: public abstract_iterator<T>
    {
    public:
      iterator(const box::simple_box<T>* item, const unsigned index) noexcept: abstract_iterator<T>::abstract_iterator(item, index) {}
      ~iterator() noexcept{ };
    };
  }

  #include "container.cpp"
#endif
