#pragma once
#include <cstdint>
#include <algorithm>

namespace jbrush
{
template<class T>
class Vector
{
public:
    using reference = T&;
    using iterator  = T*;
    using const_reference = const T&;
    using const_iterator  = const T*;
    
    /* Constructors */
    Vector();
    Vector(const Vector<T>&);
    Vector(Vector<T>&&);
    explicit Vector(uint32_t);
    
    /* Destructor */
    ~Vector();
    
    /* Capacity */
    uint32_t getSize() const;
    uint32_t getCapacity() const;
    void resize(uint32_t);
    void resize(uint32_t, const T&);
    void reserve(uint32_t);
    
    /* Member Functions */
    void push_back(const T&);
    void pop_back();
    void clear();
    
    /* Operator Overloads */
    Vector<T>& operator=(const Vector&);
    Vector<T>& operator=(Vector&&);
    reference  operator[](uint32_t);
    
    /* Iterators */
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end()   const;
    void erase(uint32_t);
    void insert(uint32_t, const T&);
    
private:
    /* Data */
    T* array;
    uint32_t size;
    uint32_t capacity;
};

/* Constructors */
template <class T>
Vector<T>::Vector()
    : size(0), capacity(16)
{
    array = new T[capacity];
}

template<class T>
Vector<T>::Vector(const Vector<T>& vec)
    : size(vec.size), capacity(vec.capacity)
{
    array = new T[vec.capacity];
    for(uint32_t i = 0; i < vec.size; i++)
    {
        array[i] = vec.array[i];
    }
}

template<class T>
Vector<T>::Vector(Vector<T>&& vec)
    : size(vec.size), capacity(vec.capacity), array(vec.array)
{
    vec.array = nullptr;
}

template<class T>
Vector<T>::Vector(uint32_t cap)
    : size(0), capacity(cap)
{
    array = new T[cap];
}

/* Destructor */
template<class T>
Vector<T>::~Vector()
{
    clear();
}

/* Capacity */
template<class T>
uint32_t Vector<T>::getSize() const
{
    return size;
}

template<class T>
uint32_t Vector<T>::getCapacity() const
{
    return capacity;
}

template<class T>
void Vector<T>::resize(uint32_t size)
{
    //Reallocate the array
    T* newArray = new T[size];
    
    //Copy the values of the existing array to new array
    for(uint32_t i = 0; i < std::min(size, this->size); i++)
    {
        newArray[i] = array[i];
    }
    
    //Change the data of the vector
    delete[]     array;
    array      = newArray;
    capacity   = size;
    this->size = size;
}

template<class T>
void Vector<T>::resize(uint32_t size, const T& fill)
{
    uint32_t oldSize = this->size;
    resize(size);
    for (uint32_t i = oldSize; i < size; i++)
    {
        array[i] = fill;
    }
}

template<class T>
void Vector<T>::reserve(uint32_t newCap)
{
    if(capacity < newCap)
    {
        //Keep multiplying capacity by 2 until it's larger than the new capacity
        while(capacity < newCap)
        {
            capacity *= 2;
        }
        
        //Reallocate the array
        T* newArray = new T[capacity];
        
        //Copy the values of the existing array to new array
        for(uint32_t i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }

        //Delete old array and assign new array to vector
        delete[] array;
        array = newArray;
    }
}

/* Modifiers */
template<class T>
void Vector<T>::push_back(const T& value)
{
    if(capacity == size)
    {
        reserve(capacity * 2);
    }
    array[size] = value;
    size++;
}

template<class T>
void Vector<T>::pop_back()
{
    if(size > 0)
    {
        size--;
    }
}

template<class T>
void Vector<T>::clear()
{
    size = 0;
    delete[] array;
    array = new T[capacity];
}

/* Operator Overloads */
template<class T>
Vector<T>& Vector<T>::operator=(const Vector& vec)
{
    //Delete old array
    delete[] array;
    
    //Resize array to fit new elements
    resize(vec.size);
    
    //Deep copy elements from other vector
    for (uint32_t i = 0; i < size; i++)
    {
        array[i] = vec.array[i];
    }
    
    return *this;
}

template<class T>
Vector<T>& Vector<T>::operator=(Vector&& vec)
{
    size      = vec.size;
    array     = vec.array;
    capacity  = vec.capacity;
    vec.array = nullptr;
    return *this;
}

template <class T>
T& Vector<T>::operator[](uint32_t index)
{
    return array[index];
}

/* Iterators */
template <class T>
T* Vector<T>::begin()
{
    return &array[0];
}

template <class T>
T* Vector<T>::end()
{
    return array + size;
}

template <class T>
const T* Vector<T>::begin() const
{
    return static_cast<const T*>(&array[0]);
}

template <class T>
const T* Vector<T>::end() const
{
    return static_cast<const T*>(array + size);
}

template <class T>
void Vector<T>::erase(uint32_t position)
{
    for(uint32_t i = position; i < size; i++)
    {
        array[i] = array [i + 1];
    }
    size--;
}

template<class T>
void Vector<T>::insert(uint32_t position, const T& value)
{
    if (size == capacity)
    {
        reserve(capacity * 2);
    }
    for (uint32_t i = size; i > position; i--)
    {
        array[i] = array[i - 1];
    }
    size++;
    array[position] = value;
}
}
