#ifndef __List_HPP__
#define __List_HPP__

#include <cstddef>
#include <cstdlib>
#include <iostream>

template <typename T>
class List
{
public:
    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef const value_type* const_pointer;

private:
    struct Node {
        Node(const T& data = T(), Node* next = NULL, Node* prev = NULL);

        T data_;
        Node* next_;
        Node* prev_;
    };

public:
    class const_iterator {
    public:
        friend List<T>;
    public:
        const_iterator();
        ~const_iterator();

        const_iterator(const const_iterator& rhv);
        const const_iterator& operator=(const const_iterator& right);

        const_reference operator*() const;
        const Node* operator->() const;

        const const_iterator& operator++();
        const const_iterator& operator--();
        const const_iterator operator++(int);
        const const_iterator operator--(int);

        const const_iterator operator+(const size_type i) const;
        const const_iterator operator-(const size_type i) const;

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
        friend List<T>;
    public:
        iterator();
        reference operator*();
        Node* operator->();
        iterator operator+(const size_type i);
        iterator operator-(const size_type i);
    protected:
        iterator(Node* valuePtr);
    };

    class const_reverse_iterator {
    public:
        friend List<T>;
    public:
        const_reverse_iterator();
        ~const_reverse_iterator();

        const_reverse_iterator(const const_reverse_iterator& rhv);
        const const_reverse_iterator& operator=(const const_reverse_iterator& right);

        const_reference operator*() const;
        const Node* operator->() const;

        const const_reverse_iterator& operator++();
        const const_reverse_iterator& operator--();
        const const_reverse_iterator operator++(int);
        const const_reverse_iterator operator--(int);

        bool operator==(const const_reverse_iterator& right) const;
        bool operator!=(const const_reverse_iterator& right) const;

    protected:
        const_reverse_iterator(Node* valuePtr);
        Node* getPtr() const;
    private:
        Node* ptr_;
    };

    class reverse_iterator : public const_reverse_iterator {
    public:
        friend List<T>;
    public:
        reverse_iterator();
        reference operator*();
        Node* operator->();
    protected:
        reverse_iterator(Node* valuePtr);
    };

public:
    List(const size_type size = 0);
    List(const int size, const T& value);
    ~List();

    template <typename InputIterator>
    List(InputIterator first, InputIterator last);

    List(const List<T>& rhv);
    const List<T>& operator=(const List<T>& right);

    const_reference operator[](const size_type index) const;
    reference operator[](const size_type index);

    bool operator==(const List<T>& right) const;
    bool operator!=(const List<T>& right) const;

    bool operator<(const List<T>& right) const;
    bool operator>(const List<T>& right) const;
    bool operator<=(const List<T>& right) const;
    bool operator>=(const List<T>& right) const;

    bool empty() const;
    size_type size() const;

    void clear();
    void resize(const size_type newSize, const_reference fill = value_type());

    void push_back(const_reference value);
    void pop_back();
    void push_front(const_reference value);
    void pop_front();

    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;

    void swap(List<T>& rhv);

    iterator insert(iterator pos, const_reference value);
    template <typename InputIterator>
    void insert(iterator pos, InputIterator first, InputIterator last);
    void insert(iterator pos, int size, const_reference value);
    iterator erase(iterator pos);
    iterator erase(iterator first, iterator last);

    void splice(iterator pos, List<T>& rhv);
    void splice(iterator pos, List<T>& rhv, iterator insert);
    void splice(iterator pos, List<T>& rhv, iterator first, iterator last);

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend();
    const_reverse_iterator rend() const;

private:
    bool isValidIterator(List<T>::iterator& pos);
private:
    Node* begin_;
    Node* end_;
};

#include "../templates/List.cpp"

#endif /// __List_HPP__

