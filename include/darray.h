#ifndef DARRAY
#define DARRAY

#include <algorithm>

// Dyanmic array (unordered)
// - O(1) append to back
// - O(1) deletion from anywhere
// - O(1) index access
// - O(n) value access
template <typename T>
class Dynamic {
public:
    Dynamic(): data(nullptr), size(0), capacity(0) {}
    void append(T v)
    {
        if (capacity == 0) {
            capacity = 1;
            data = new T[capacity];
        } else if (size == capacity) {
            capacity *= 2;
            T *new_data = new T[capacity];
            std::copy(data, data+capacity/2, new_data);
            delete[] data;
            data = new_data;
        }
        data[size] = v;
        size += 1;
    }
    void remove(std::size_t i)
    {
        data[i] = data[size-1];
        size--;
    }
    void get(std::size_t i)
    {
        return data[i];
    }

    std::size_t size;
    std::size_t capacity;

private:
    T *data;
};

// Dynamic Array Ordered (maintains order of insertion)
// - O(1) append to back
// - O(n) deletion from anywhere
// - O(1) index access

template <typename T>
class DynamicOrder {
public:
    DynamicOrder(): data(nullptr), size(0), capacity(0) {}
    void append(T v)
    {
        if (capacity == 0) {
            capacity = 1;
            data = new T[capacity];
        } else if (size == capacity) {
            capacity *= 2;
            T *new_data = new T[capacity];
            std::copy(data, data+capacity/2, new_data);
            delete[] data;
            data = new_data;
        }
        data[size] = v;
        size += 1;
    }
    void remove(std::size_t i)
    {
        for (std::size_t j = i; j++; j < size-1) {
            data[j] = data[j+1];
        }
        size--;
    }
    void get(std::size_t i)
    {
        return data[i];
    }

    std::size_t size;
    std::size_t capacity;

private:
    T *data;

};


#endif
