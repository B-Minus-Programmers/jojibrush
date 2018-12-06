#pragma once
#include <cstdint>
#include <algorithm>

namespace jbrush
{

/**
 * Templated Vector class
 * 
 * Represents a resizable, dynamic array of elements. Lookups are O(1), inserts are O(n)
 */
template<class T>
class Vector
{
public:
    using reference = T&;
    using iterator  = T*;
    using const_reference = const T&;
    using const_iterator  = const T*;
    
    /* Constructors */

    /**
     * Creates a default vector with space for 16 elements
     */
    Vector();

    /**
     * Copies an existing vector into this vector
     * @param vec Existing vector to copy
     */
    Vector(const Vector<T>& vec);

    /**
     * Moves an existing vector into this vector. Note that the existing vector will be destroyed
     * @param vec Existing vector to move from, then destroy
     */
    Vector(Vector<T>&& vec);

    /**
     * Initializes a Vector with a specific capacity
     * @param capacity Starting capacity of the vector
     */
    explicit Vector(uint32_t capacity);
    
    /* Destructor */
    ~Vector();
    
    /* Capacity */

    /**
     * Returns the number of elements in the vector
     * @returns the number of elements currently in the vector
     */
    uint32_t getSize() const;

    /**
     * Returns the maximum number of elements the vector can hold without needing to be resized
     * @returns the maximum capacity of the vector
     */
    uint32_t getCapacity() const;

    /**
     * Increases or decreases the vector's capacity
     * @param capacity the new vector capacity
     */
    void resize(uint32_t capacity);

    /**
     * Increases or decreases the vector's capacity, adding an element to added spaces
     * @param capacity the new vector capacity
     * @param filler the value to fill new spaces with
     */
    void resize(uint32_t capacity, const T& filler);

    /**
     * Reserves more space for a vector, without adding or removing data
     * @param capacity the new vector capacity
     */
    void reserve(uint32_t capacity);
    
    /* Member Functions */

    /**
     * Adds an element to the end of the vector
     * @param element element to add to the vector
     */
    void push_back(const T& element);

    /**
     * Removes the last element in the vector
     */
    void pop_back();

    /**
     * Removes all elements from the vector
     */
    void clear();
    
    /* Operator Overloads */
    Vector<T>& operator=(const Vector&);
    Vector<T>& operator=(Vector&&);
    reference  operator[](uint32_t);
    
    /* Iterators */

    /**
     * Returns a pointer to the beginning of the vector
     * @returns pointer to the first element
     */
    iterator begin();

    /**
     * Returns a pointer to the end of the vector
     * @returns pointer to the after-last element
     */
    iterator end();

    /**
     * Returns a constant pointer to the beginning of the vector
     * @returns constant pointer to the first element
     */
    const_iterator begin() const;

    /**
     * Returns a constant pointer to the end of the vector
     * @returns constant pointer to the after-last element
     */
    const_iterator end() const;

    /**
     * Removes a single element from the vector, re-organizing subsequent elements to fill the gap
     * @param position position of the element to remove
     */
    void erase(uint32_t position);

    /**
     * Adds a single element at a position, re-organizing subsequent elements so that no data is lost
     * @param position position to insert the new element at
     * @param element element to insert
     */
    void insert(uint32_t position, const T& element);
    
private:
    /* Data */
    uint32_t size;
    uint32_t capacity;
    T* array;
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
    delete[] array;
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

    //Assign members
    array = new T[vec.capacity];
    capacity = vec.capacity;
    size = vec.size;
    
    //Deep copy elements from other vector
    for (uint32_t i = 0; i < vec.size; i++)
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
    if(size != 0)
    {
        for(uint32_t i = position; i < size - 1; i++)
        {
            array[i] = array [i + 1];
        }
        size--;
    }
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
