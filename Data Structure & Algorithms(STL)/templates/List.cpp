#include "../headers/List.hpp"

#include <cassert>


///Node

template <typename T>
List<T>::Node::Node(const T& data, Node* next, Node* prev)
    : data_(data)
    , next_(next)
    , prev_(prev) 
{
}


///List

template <typename T>
List<T>::List(const size_type size)
    : begin_(NULL)
    , end_(NULL)
{
    resize(size);
}

template <typename T>
List<T>::List(const int size, const T& value)
    : begin_(NULL)
    , end_(NULL)
{
    resize(size, value);
}

template <typename T>
template <typename InputIterator>
List<T>::List(InputIterator first, InputIterator last)
    : begin_(NULL)
    , end_(NULL)
{
    while (first != last) {
        push_back(*first);
        ++first;
    }
}

template <typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
List<T>::List(const List<T>& rhv)
    : begin_(NULL)
    , end_(NULL)
{
    for (const_iterator it = rhv.begin(); it != rhv.end(); ++it) {
        push_back(*it);
    }
}

template <typename T>
const List<T>&
List<T>::operator=(const List<T>& rhv)
{
    if (this == &rhv) return *this;

    size_type thisSize = size();
    const size_type rhvSize = rhv.size();
    if (thisSize > rhvSize) resize(rhvSize);

    const_iterator rhvIt = rhv.begin();
    for (iterator it = begin(); it != end(); ++it) {
        *it = *rhvIt;
        ++rhvIt;
    }

    while (thisSize < rhvSize) {
        push_back(*rhvIt);
        ++rhvIt;
        ++thisSize;
    }
    return *this;
}

template <typename T>
typename List<T>::const_reference 
List<T>::operator[](const size_type index) const
{
    assert(index < size());
    Node* temp = begin_;
    for (size_type i = 0; i < index; ++i) {
        temp = temp->next_;
    }
    return temp->data_;
}

template <typename T>
typename List<T>::reference 
List<T>::operator[](const size_type index)
{
    assert(index < size());
    Node* temp = begin_;
    for (size_type i = 0; i < index; ++i) {
        temp = temp->next_;
    }
    return temp->data_;
}

template <typename T>
bool
List<T>::operator==(const List<T>& right) const
{
    if (size() != right.size()) return false;

    Node* temp = begin_;
    Node* rightTemp = right.begin_;
    while (temp != end_) {
        if (temp->data_ != rightTemp->data_) return false;
        temp = temp->next_;
        rightTemp = rightTemp->next_;
    }
    return true;
}

template <typename T>
bool
List<T>::operator!=(const List<T>& right) const
{
    return !(*this == right);
}

template <typename T>
bool
List<T>::operator<(const List<T>& right) const
{
    if (size() < right.size()) return true;
    if (size() > right.size()) return false;
    
    Node* temp = begin_;
    Node* rightTemp = right.begin_;
    while (temp != end_) {
        if (temp->data_ < rightTemp->data_) return true;
        if (temp->data_ > rightTemp->data_) return false;
        temp = temp->next_;
        rightTemp = rightTemp->next_;
    }
    return false;
}

template <typename T>
bool
List<T>::operator>(const List<T>& right) const
{
    return right < *this;
}

template <typename T>
bool
List<T>::operator<=(const List<T>& right) const
{
    return !(*this > right);
}

template <typename T>
bool
List<T>::operator>=(const List<T>& right) const
{
    return !(*this < right);
}

template <typename T>
bool
List<T>::empty() const
{
    return end_ == begin_;
}

template <typename T>
typename List<T>::size_type
List<T>::size() const
{
    Node* temp = begin_;
    size_type count = 0;
    while (temp != end_) {
        ++count;
        temp = temp->next_;
    }

    return count;
}

template <typename T>
void
List<T>::clear()
{
    resize(0);
}

template <typename T>
void
List<T>::resize(const size_type newSize, const_reference fill)
{
    size_type oldSize = size();
    if (newSize == oldSize) return; 

    if (empty()) {
        end_ = new Node;
        begin_ = new Node(fill, end_, NULL);
        end_->prev_ = begin_;
        if (newSize == 1) return;
        ++oldSize;
    }
    for (size_type i = oldSize; i < newSize; ++i) {
        end_->data_ = fill;
        end_->next_ = new Node;
        end_->next_->prev_ = end_;
        end_ = end_->next_;
    }
    for (size_type i = newSize; i < oldSize; ++i) {
        Node* toDelete = end_;
        end_ = end_->prev_;
        end_->next_ = NULL;
        delete toDelete;
    }
}

template <typename T>
void
List<T>::push_back(const_reference value)
{
    resize(size() + 1, value);
}

template <typename T>
void
List<T>::pop_back()
{
    assert(!empty());
    resize(size() - 1);
}

template <typename T>
void
List<T>::push_front(const_reference value)
{
    if (empty()) {
        resize(1, value);
        return;
    }

    Node* temp = new Node(value, begin_, NULL);
    begin_->prev_ = temp;
    begin_ = temp;
}

template <typename T>
void
List<T>::pop_front()
{
    assert(!empty());
    Node* toDelete = begin_;
    begin_ = begin_->next_;
    begin_->prev_ = NULL;
    delete toDelete;
}

template <typename T>
typename List<T>::reference
List<T>::front()
{
    assert(!empty());
    return begin_->data_;
}

template <typename T>
typename List<T>::const_reference
List<T>::front() const
{
    assert(!empty());
    return begin_->data_;
}

template <typename T>
typename List<T>::reference
List<T>::back()
{
    assert(!empty());
    return end_->prev_->data_;
}

template <typename T>
typename List<T>::const_reference
List<T>::back() const
{
    assert(!empty());
    return end_->prev_->data_;
}

template <typename T>
void 
List<T>::swap(List<T>& rhv)
{
    List<T>::Node* tempBegin = begin_;
    List<T>::Node* tempEnd = end_;

    begin_ = rhv.begin_;
    end_ = rhv.end_;

    rhv.begin_ = tempBegin;
    rhv.end_ = tempEnd;
}

template <typename T>
typename List<T>::iterator 
List<T>::insert(iterator pos, const_reference value)
{
    if (empty()) {
        resize(1, value);
        return end();
    }
    assert(isValidIterator(pos));

    Node* temp = new Node(value, pos.getPtr(), pos->prev_);

    if (pos == begin()) {
        begin_ = temp;
    } else {
        temp->prev_->next_ = temp;
    }
    temp->next_->prev_ = temp;

    return temp->next_;
}

template <typename T>
template <typename InputIterator>
void 
List<T>::insert(iterator pos, InputIterator first, InputIterator last)
{
    assert(isValidIterator(pos) || empty());
    while (first != last) {
        pos = insert(pos, *first);
        ++first;
    }
}

template <typename T>
void 
List<T>::insert(iterator pos, int size, const_reference value)
{
    if (empty()) {
        resize(size, value);
        return;
    }
    for (int i = 0; i < size; ++i) {
        pos = insert(pos, value);
    }
}

template <typename T>
typename List<T>::iterator 
List<T>::erase(iterator pos)
{
    assert(!empty());
    assert(isValidIterator(pos));

    if (pos == begin()) {
        begin_ = pos->next_;
        begin_->prev_ = NULL;
        delete pos.getPtr();
        return begin();
    }

    pos->prev_->next_ = pos->next_;
    pos->next_->prev_ = pos->prev_;

    Node* toReturn = pos->next_;
    delete pos.getPtr();
    return toReturn;
}

template <typename T>
typename List<T>::iterator 
List<T>::erase(iterator first, iterator last)
{
    while (first != last) { 
        first = erase(first); 
    }
    return first;
}

template <typename T>
void 
List<T>::splice(iterator pos, List<T>& rhv)
{
    if (this == &rhv) return;
    if (rhv.empty()) return;
    if (empty()) {
        swap(rhv);
        return;
    }
    assert(isValidIterator(pos));
    splice(pos, rhv, rhv.begin(), rhv.end());
    rhv.begin_ = rhv.end_ = NULL;
}

template <typename T>
void 
List<T>::splice(iterator pos, List<T>& rhv, iterator insert)
{
    if (this == &rhv) return;
    assert(isValidIterator(pos));
    assert(rhv.isValidIterator(insert));
    splice(pos, rhv, insert, insert.getPtr()->next_);
}

template <typename T>
void 
List<T>::splice(iterator pos, List<T>& rhv, iterator first, iterator last)
{
    if (this == &rhv) return;
    if (rhv.empty()) return;
    if (empty()) {
        swap(rhv);
        return;
    }
    assert(isValidIterator(pos));
    assert(rhv.isValidIterator(first));
    assert(rhv.isValidIterator(last));

    Node* tempLast = last.getPtr()->prev_;
    if (first == rhv.begin()) {
        last.getPtr()->prev_ = NULL;
        rhv.begin_ = last.getPtr();
    } else {
        first.getPtr()->prev_->next_ = last.getPtr();
        last.getPtr()->prev_ = first.getPtr();
    }
        
    if (pos == begin()) {
        begin_ = first.getPtr();
        begin_->prev_ = NULL;
        pos->prev_ = tempLast;
        pos->prev_->next_ = pos.getPtr();
    } else {
        first.getPtr()->prev_ = pos->prev_;
        tempLast->next_ = pos.getPtr();
        pos->prev_->next_ = first.getPtr();
        pos->prev_ = tempLast;
    }
}

template <typename T>
bool 
List<T>::isValidIterator(iterator& pos)
{
    iterator it = begin();
    while (it != NULL) {
        if (it == pos) return true;
        ++it;
    }
    return false;
}

template <typename T>
typename List<T>::iterator
List<T>::begin()
{
    return begin_; 
}

template <typename T>
typename List<T>::const_iterator
List<T>::begin() const
{
    return begin_;
}

template <typename T>
typename List<T>::iterator
List<T>::end()
{
    return end_; 
}

template <typename T>
typename List<T>::const_iterator
List<T>::end() const
{
    return end_;
}

template <typename T>
typename List<T>::reverse_iterator
List<T>::rbegin()
{
    return end_->prev_;
}

template <typename T>
typename List<T>::const_reverse_iterator
List<T>::rbegin() const
{
    return end_->prev_;
}

template <typename T>
typename List<T>::reverse_iterator
List<T>::rend()
{
    return begin_->prev_;
}

template <typename T>
typename List<T>::const_reverse_iterator
List<T>::rend() const
{
    return begin_->prev_;
}


///const_iterator

template <typename T>
List<T>::const_iterator::const_iterator()
    : ptr_(NULL)
{
}

template <typename T>
List<T>::const_iterator::const_iterator(const const_iterator& rhv)
    : ptr_(rhv.ptr_)
{
}

template <typename T>
List<T>::const_iterator::const_iterator(Node* valuePtr)
    : ptr_(valuePtr)
{
}

template <typename T>
List<T>::const_iterator::~const_iterator()
{
    ptr_ = NULL;
}

template <typename T>
const typename List<T>::const_iterator&
List<T>::const_iterator::operator=(const const_iterator& right)
{
    if (this == &right) return *this;
    ptr_ = right.ptr_;
    return *this;
}

template <typename T>
typename List<T>::const_reference
List<T>::const_iterator::operator*() const
{
    return ptr_->data_;
}

template <typename T>
const typename List<T>::Node*
List<T>::const_iterator::operator->() const
{
    return ptr_;
}

template <typename T>
const typename List<T>::const_iterator&
List<T>::const_iterator::operator++()
{
    ptr_ = ptr_->next_;
    return *this; 
}

template <typename T>
const typename List<T>::const_iterator&
List<T>::const_iterator::operator--()
{
    ptr_ = ptr_->prev_;
    return *this; 
}

template <typename T>
const typename List<T>::const_iterator
List<T>::const_iterator::operator++(int)
{
    const const_iterator temp = ptr_;
    ptr_ = ptr_->next_;
    return temp; 
}

template <typename T>
const typename List<T>::const_iterator
List<T>::const_iterator::operator--(int)
{
    const const_iterator temp = ptr_;
    ptr_ = ptr_->prev_;
    return temp; 
}

template <typename T>
const typename List<T>::const_iterator
List<T>::const_iterator::operator+(const size_type i) const
{
    const_iterator temp = ptr_;
    for (size_type j = 0; j < i; ++j) {
        temp = temp->next_;
    }
    return temp;
}

template <typename T>
const typename List<T>::const_iterator
List<T>::const_iterator::operator-(const size_type i) const
{
    const_iterator temp = ptr_;
    for (size_type j = 0; j < i; ++j) {
        temp = temp->prev_;
    }
    return temp;
}

template <typename T>
bool
List<T>::const_iterator::operator==(const const_iterator& right) const
{
    return ptr_ == right.ptr_;
}

template <typename T>
bool
List<T>::const_iterator::operator!=(const const_iterator& right) const
{
    return !(*this == right);
}

template <typename T>
typename List<T>::Node*
List<T>::const_iterator::getPtr() const
{
    return ptr_;
}


///iterator

template <typename T>
List<T>::iterator::iterator()
    : const_iterator()
{
}

template <typename T>
List<T>::iterator::iterator(Node* valuePtr)
    : const_iterator(valuePtr)
{
}

template <typename T>
typename List<T>::reference
List<T>::iterator::operator*()
{
    return const_iterator::getPtr()->data_;
}

template <typename T>
typename List<T>::Node*
List<T>::iterator::operator->()
{
    return const_iterator::getPtr();
}

template <typename T>
typename List<T>::iterator
List<T>::iterator::operator+(const size_type i)
{
    iterator temp = const_iterator::ptr_;
    for (size_type j = 0; j < i; ++j) {
        temp = temp->next_;
    }
    return temp;
}

template <typename T>
typename List<T>::iterator
List<T>::iterator::operator-(const size_type i)
{
    iterator temp = const_iterator::ptr_;
    for (size_type j = 0; j < i; ++j) {
        temp = temp->prev_;
    }
    return temp;
}


///const_reverse_iterator

template <typename T>
List<T>::const_reverse_iterator::const_reverse_iterator()
    : ptr_(NULL)
{
}

template <typename T>
List<T>::const_reverse_iterator::const_reverse_iterator(const const_reverse_iterator& rhv)
    : ptr_(rhv.ptr_)
{
}

template <typename T>
List<T>::const_reverse_iterator::const_reverse_iterator(Node* valuePtr)
    : ptr_(valuePtr)
{
}

template <typename T>
List<T>::const_reverse_iterator::~const_reverse_iterator()
{
    ptr_ = NULL;
}

template <typename T>
const typename List<T>::const_reverse_iterator&
List<T>::const_reverse_iterator::operator=(const const_reverse_iterator& right)
{
    if (this == &right) return *this;
    ptr_ = right.ptr_;
    return *this;
}

template <typename T>
typename List<T>::const_reference
List<T>::const_reverse_iterator::operator*() const
{
    return ptr_->data_;
}

template <typename T>
const typename List<T>::Node*
List<T>::const_reverse_iterator::operator->() const
{
    return ptr_;
}

template <typename T>
const typename List<T>::const_reverse_iterator&
List<T>::const_reverse_iterator::operator++()
{
    ptr_ = ptr_->prev_;
    return *this; 
}

template <typename T>
const typename List<T>::const_reverse_iterator&
List<T>::const_reverse_iterator::operator--()
{
    ptr_ = ptr_->next_;
    return *this; 
}

template <typename T>
const typename List<T>::const_reverse_iterator
List<T>::const_reverse_iterator::operator++(int)
{
    const const_reverse_iterator temp = ptr_;
    ptr_ = ptr_->prev_;
    return temp; 
}

template <typename T>
const typename List<T>::const_reverse_iterator
List<T>::const_reverse_iterator::operator--(int)
{
    const const_reverse_iterator temp = ptr_;
    ptr_ = ptr_->next_;
    return temp; 
}

template <typename T>
bool
List<T>::const_reverse_iterator::operator==(const const_reverse_iterator& right) const
{
    return ptr_ == right.ptr_;
}

template <typename T>
bool
List<T>::const_reverse_iterator::operator!=(const const_reverse_iterator& right) const
{
    return !(*this == right);
}

template <typename T>
typename List<T>::Node*
List<T>::const_reverse_iterator::getPtr() const
{
    return ptr_;
}


///reverse_iterator

template <typename T>
List<T>::reverse_iterator::reverse_iterator()
    : const_reverse_iterator()
{
}

template <typename T>
List<T>::reverse_iterator::reverse_iterator(Node* valuePtr)
    : const_reverse_iterator(valuePtr)
{
}

template <typename T>
typename List<T>::reference
List<T>::reverse_iterator::operator*()
{
    return const_reverse_iterator::getPtr()->data_;
}

template <typename T>
typename List<T>::Node*
List<T>::reverse_iterator::operator->()
{
    return const_reverse_iterator::getPtr();
}

