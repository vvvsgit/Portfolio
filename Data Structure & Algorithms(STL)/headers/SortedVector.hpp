#ifndef __SORTED_VECTOR_HPP__
#define __SORTED_VECTOR_HPP__

#include <cstddef>
#include <cstdlib>
#include <iostream>

template <typename T>
class SortedVector
{
public:
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;

public:
    class const_iterator {
    public:
        friend SortedVector<T>;
    public:
        const_iterator();
        ~const_iterator();

        const_iterator(const const_iterator& rhv);
        const const_iterator& operator=(const const_iterator& right);

        const_reference operator*() const;
        const_pointer operator->() const;

        const const_iterator& operator++();
        const const_iterator& operator--();
        const const_iterator operator++(int);
        const const_iterator operator--(int);

        const_iterator& operator+=(const size_type i);
        const_iterator& operator-=(const size_type i);
        const const_iterator operator+(const size_type i) const;
        const const_iterator operator-(const size_type i) const;

        bool operator==(const const_iterator& right) const;
        bool operator!=(const const_iterator& right) const;
        bool operator<(const const_iterator& right) const;
        bool operator>(const const_iterator& right) const;
        bool operator<=(const const_iterator& right) const;
        bool operator>=(const const_iterator& right) const;

        const_reference operator[](const size_type index) const;
    protected:
        const_iterator(pointer valuePtr);
        pointer getPtr() const;
    private:
        pointer ptr_;
    };

    class iterator : public const_iterator {
    public:
        friend SortedVector<T>;
    public:
        iterator();
        reference operator*();
        pointer operator->();
        reference operator[](const size_type index);
        iterator operator+(const size_type i);
        iterator operator-(const size_type i);
    protected:
        iterator(pointer valuePtr);
    };

    class const_reverse_iterator {
    public:
        friend SortedVector<T>;
    public:
        const_reverse_iterator();
        ~const_reverse_iterator();

        const_reverse_iterator(const const_reverse_iterator& rhv);
        const const_reverse_iterator& operator=(const const_reverse_iterator& right);

        const_reference operator*() const;
        const_pointer operator->() const;

        const const_reverse_iterator& operator++();
        const const_reverse_iterator& operator--();
        const const_reverse_iterator operator++(int);
        const const_reverse_iterator operator--(int);

        const_reverse_iterator& operator+=(const size_type i);
        const_reverse_iterator& operator-=(const size_type i);
        const const_reverse_iterator operator+(const size_type i) const;
        const const_reverse_iterator operator-(const size_type i) const;

        bool operator==(const const_reverse_iterator& right) const;
        bool operator!=(const const_reverse_iterator& right) const;
        bool operator<(const const_reverse_iterator& right) const;
        bool operator>(const const_reverse_iterator& right) const;
        bool operator<=(const const_reverse_iterator& right) const;
        bool operator>=(const const_reverse_iterator& right) const;

        const_reference operator[](const size_type index) const;
    protected:
        const_reverse_iterator(pointer valuePtr);
        pointer getPtr() const;
    private:
        pointer ptr_;
    };

    class reverse_iterator : public const_reverse_iterator {
    public:
        friend SortedVector<T>;
    public:
        reverse_iterator();
        reference operator*();
        pointer operator->();
        reference operator[](const size_type index);
    protected:
        reverse_iterator(pointer valuePtr);
    };

public:
    SortedVector(const size_type size = 0);
    SortedVector(const int size, const_reference value);

    template <typename InputIterator>
    SortedVector(InputIterator first, InputIterator last);
    ~SortedVector();

    SortedVector(const SortedVector<T>& rhv);
    const SortedVector<T>& operator=(const SortedVector<T>& right);

    const_reference operator[](const size_type index) const;

    const_reference front() const;
    const_reference back() const;

    bool operator==(const SortedVector<T>& right) const;
    bool operator!=(const SortedVector<T>& right) const;

    bool operator<(const SortedVector<T>& right) const;
    bool operator>(const SortedVector<T>& right) const;
    bool operator<=(const SortedVector<T>& right) const;
    bool operator>=(const SortedVector<T>& right) const;

    bool empty() const;
    size_type size() const;

    size_type capacity() const;
    void reserve(const size_type newSize);

    void clear();
    void resize(const size_type newSize);
    void resize(const size_type newSize, const_reference fill);

    void push_back(const_reference value);
    void pop_back();

    void swap(SortedVector<T>& rhv);

    iterator insert(iterator pos, const_reference value);
    void insert(iterator pos, int n, const_reference value);
    template <typename InputIterator>
    void insert(iterator pos, InputIterator first, InputIterator last);

    iterator erase(iterator pos);
    iterator erase(iterator first, iterator last);

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend();
    const_reverse_iterator rend() const;

private:
    void privateResize(const size_type newSize);
    void privateResize(const size_type newSize, const_reference fill);
private:
    pointer begin_;
    pointer end_;
    pointer bufferEnd_;
};

#include "../templates/SortedVector.cpp"

#endif /// __SORTED_VECTOR_HPP__

