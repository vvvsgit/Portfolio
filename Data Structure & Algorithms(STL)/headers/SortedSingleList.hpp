#ifndef __SORTED_SINGLE_LIST_HPP__
#define __SORTED_SINGLE_LIST_HPP__

#include <cstddef>
#include <cstdlib>
#include <iostream>

template <typename T>
class SortedSingleList
{
public:
    typedef T value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

private:
    struct Node {
        Node(const T& data = T(), Node* next = NULL);

        T data_;
        Node* next_;
    };

public:
    class const_iterator {
    public:
        friend SortedSingleList<T>;
    public:
        const_iterator();
        ~const_iterator();

        const_iterator(const const_iterator& rhv);
        const const_iterator& operator=(const const_iterator& right);

        const_reference operator*() const;
        const Node* operator->() const;

        const const_iterator& operator++();
        const const_iterator operator++(int);

        const const_iterator operator+(const size_type i) const;

        bool operator==(const const_iterator& right) const;
        bool operator!=(const const_iterator& right) const;

    protected:
        const_iterator(Node* valuePtr);
        Node* getPtr() const;
    private:
        Node* ptr_;
    };

    class iterator : public const_iterator {
    public:
        friend SortedSingleList<T>;
    public:
        iterator();
        reference operator*();
        Node* operator->();
        iterator operator+(const size_type i);
    protected:
        iterator(Node* valuePtr);
    };

public:
    SortedSingleList(const size_type size = 0);
    SortedSingleList(const int size, const T& value);
    ~SortedSingleList();

    template <typename InputIterator>
    SortedSingleList(InputIterator first, InputIterator last);

    SortedSingleList(const SortedSingleList<T>& rhv);
    const SortedSingleList<T>& operator=(const SortedSingleList<T>& right);

    const_reference operator[](const size_type index) const;

    bool operator==(const SortedSingleList<T>& right) const;
    bool operator!=(const SortedSingleList<T>& right) const;

    bool operator<(const SortedSingleList<T>& right) const;
    bool operator>(const SortedSingleList<T>& right) const;
    bool operator<=(const SortedSingleList<T>& right) const;
    bool operator>=(const SortedSingleList<T>& right) const;

    bool empty() const;
    size_type size() const;

    void clear();
    void resize(const size_type newSize, const_reference fill = value_type());

    void push_back(const_reference value);
    void pop_back();
    void push_front(const_reference value);
    void pop_front();

    const_reference front() const;
    const_reference back() const;

    void swap(SortedSingleList<T>& rhv);

    iterator insert(const_reference value);
    iterator insert(iterator pos, const_reference value);
    template <typename InputIterator>
    void insert(iterator pos, InputIterator first, InputIterator last);
    void insert(iterator pos, int size, const_reference value);
    iterator erase(iterator pos);
    iterator erase(iterator first, iterator last);

    iterator insert_after(iterator pos, const_reference value = value_type());
    template <typename InputIterator>
    void insert_after(iterator pos, InputIterator first, InputIterator last);
    void insert_after(iterator pos, int size, const_reference value);
    iterator erase_after(iterator pos);
    iterator erase_after(iterator before_first, iterator last);

    void splice(iterator pos, SortedSingleList<T>& rhv);
    void splice(iterator pos, SortedSingleList<T>& rhv, iterator insert);
    void splice(iterator pos, SortedSingleList<T>& rhv, iterator first, iterator last);

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    iterator previous(iterator pos);
    const_iterator previous(const_iterator pos) const;

private:
    bool isValidIterator(SortedSingleList<T>::iterator& pos);
private:
    Node* begin_;
    Node* end_;
};

#include "../templates/SortedSingleList.cpp"

#endif /// __SORTED_SINGLE_LIST_HPP__

