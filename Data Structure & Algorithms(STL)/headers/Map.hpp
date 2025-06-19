#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <cstddef>
#include <iostream>
#include <utility>

template <typename K, typename D>
class Map
{
public:
    typedef D data_type;
    typedef K key_type;
    typedef std::pair<key_type, data_type> value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;

private:
    struct Node {
        Node(const value_type& value = value_type(), Node* parent = NULL, Node* left = NULL, Node* right = NULL);

        value_type data_;
        Node* parent_;
        Node* left_;
        Node* right_;
    };

public:
    template <typename F, typename S>
    struct Pair {
        Pair(const F& first, const S& second);

        F first_;
        S second_;
    };
public:
    class const_iterator {
    public:
        friend Map<K, D>;
    public:
        const_iterator();
        const_iterator(const const_iterator& rhv);
        ~const_iterator();

        const const_iterator& operator=(const const_iterator& rhv);

        const_reference operator*() const;
        const Node* operator->() const;

        const const_iterator& operator++();
        const const_iterator& operator--();
        const const_iterator operator++(int);
        const const_iterator operator--(int);
        const_iterator nextInOrder(const_iterator it);
        const_iterator rightParent(const_iterator it);
        const_iterator prevInOrder(const_iterator it);
        const_iterator leftParent(const_iterator it);

        bool operator==(const const_iterator& rhv) const;
        bool operator!=(const const_iterator& rhv) const;
    protected:
        const_iterator(Node* valuePtr);
        Node* getPtr() const;
    private:
        Node* ptr_;
    };

    class iterator : public const_iterator {
    public:
        friend Map<K, D>;
    public:
        iterator();
        reference operator*();
        Node* operator->();
    protected:
        iterator(Node* valuePtr);
    };

    class const_reverse_iterator {
    public:
        friend Map<K, D>;
    public:
        const_reverse_iterator();
        const_reverse_iterator(const const_reverse_iterator& rhv);
        ~const_reverse_iterator();

        const const_reverse_iterator& operator=(const const_reverse_iterator& rhv);

        const_reference operator*() const;
        const Node* operator->() const;

        const const_reverse_iterator& operator++();
        const const_reverse_iterator& operator--();
        const const_reverse_iterator operator++(int);
        const const_reverse_iterator operator--(int);
        const_reverse_iterator nextInOrder(const_reverse_iterator it);
        const_reverse_iterator prevInOrder(const_reverse_iterator it);

        bool operator==(const const_reverse_iterator& rhv) const;
        bool operator!=(const const_reverse_iterator& rhv) const;

    protected:
        const_reverse_iterator(Node* valuePtr);
        Node* getPtr() const;
    private:
        Node* ptr_;
    };

    class reverse_iterator : public const_reverse_iterator {
    public:
        friend Map<K, D>;
    public:
        reverse_iterator();
        reference operator*();
        Node* operator->();
    protected:
        reverse_iterator(Node* valuePtr);
    };

public:
    Map();
    Map(const Map<K, D>& rhv);
    template <typename InputIterator>
    Map(InputIterator first, InputIterator last);
    ~Map();

    const Map<K, D>& operator=(const Map<K, D>& rhv);

    void swap(Map<K, D>& rhv);
    size_type size() const;
    bool empty() const;
    void clear();

    Pair<iterator, bool> insert(const key_type& key, const data_type& data = data_type());
    iterator insert(iterator pos, const key_type& key, const data_type& data = data_type());
    Pair<iterator, bool> insert(const_reference value);
    iterator insert(iterator pos, const_reference value);
    template <typename InputIterator>
    void insert(iterator pos, InputIterator first, InputIterator last);

    data_type& operator[](const key_type& k);

    iterator erase(iterator pos);
    size_type erase(const key_type& k);
    iterator erase(iterator first, iterator last);

    iterator find(const key_type& k) const;
    size_type count(const key_type& k) const;
    iterator lower_bound(const  key_type& k) const;
    iterator upper_bound(const  key_type& k) const;
    Pair<iterator, iterator> equal_range(const key_type& k) const;

    bool operator==(const Map<K, D>& rhv) const;
    bool operator!=(const Map<K, D>& rhv) const;

    bool operator<(const Map<K, D>& rhv) const;
    bool operator>(const Map<K, D>& rhv) const;
    bool operator<=(const Map<K, D>& rhv) const;
    bool operator>=(const Map<K, D>& rhv) const;

    void print() const;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;

private:
    void copyMap(const Node* ptr);
    void size(const Node* ptr, int& result) const;
    void clear(Node* ptr);
    Node* topLeft(Node* ptr) const;
    Node* topRight(Node* ptr) const;
    void goUp(const_iterator& it, const_reference value) const;
    void goDownInsert(iterator& it, const_reference value);
    void balance(iterator it);
    int getDiff(iterator it) const;
    int depth(const Node* ptr) const;
    void depth(const Node* ptr, int& result, const int counter = 0) const;
    void rotateLeft(iterator& it);
    void rotateRight(iterator& it);
    void print(const Node* ptr, const int spaces = 0) const;

private:
    Node* root_;
};

#include "../templates/Map.cpp"

#endif

