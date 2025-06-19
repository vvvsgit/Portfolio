#include "../headers/SingleList.hpp"

#include <cassert>


///Node

template <typename T>
SingleList<T>::Node::Node(const T& data, Node* next)
    : data_(data)
    , next_(next)
{
}


///SingleList

template <typename T>
SingleList<T>::SingleList(const size_type size)
    : begin_(NULL)
    , end_(NULL)
{
    resize(size);
}

template <typename T>
SingleList<T>::SingleList(const int size, const T& value)
    : begin_(NULL)
    , end_(NULL)
{
    resize(size, value);
}

template <typename T>
template <typename InputIterator>
SingleList<T>::SingleList(InputIterator first, InputIterator last)
    : begin_(NULL)
    , end_(NULL)
{
    while (first != last) {
        push_back(*first);
        ++first;
    }
}

template <typename T>
SingleList<T>::~SingleList()
{
    clear();
}

template <typename T>
SingleList<T>::SingleList(const SingleList<T>& rhv)
    : begin_(NULL)
    , end_(NULL)
{
    for (const_iterator it = rhv.begin(); it != rhv.end(); ++it) {
        push_back(*it);
    }
}

template <typename T>
const SingleList<T>&
SingleList<T>::operator=(const SingleList<T>& rhv)
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
typename SingleList<T>::const_reference 
SingleList<T>::operator[](const size_type index) const
{
    assert(index < size());
    Node* temp = begin_;
    for (size_type i = 0; i < index; ++i) {
        temp = temp->next_;
    }
    return temp->data_;
}

template <typename T>
typename SingleList<T>::reference 
SingleList<T>::operator[](const size_type index)
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
SingleList<T>::operator==(const SingleList<T>& right) const
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
SingleList<T>::operator!=(const SingleList<T>& right) const
{
    return !(*this == right);
}

template <typename T>
bool
SingleList<T>::operator<(const SingleList<T>& right) const
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
SingleList<T>::operator>(const SingleList<T>& right) const
{
    return right < *this;
}

template <typename T>
bool
SingleList<T>::operator<=(const SingleList<T>& right) const
{
    return !(*this > right);
}

template <typename T>
bool
SingleList<T>::operator>=(const SingleList<T>& right) const
{
    return !(*this < right);
}

template <typename T>
bool
SingleList<T>::empty() const
{
    return end_ == begin_;
}

template <typename T>
typename SingleList<T>::size_type
SingleList<T>::size() const
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
SingleList<T>::clear()
{
    resize(0);
}

template <typename T>
void
SingleList<T>::resize(const size_type newSize, const_reference fill)
{
    size_type oldSize = size();
    if (newSize == oldSize) return; 

    if (empty()) {
        end_ = new Node;
        begin_ = new Node(fill, end_);
        end_->next_ = begin_;
        if (newSize == 1) return;
        ++oldSize;
    }
    for (size_type i = oldSize; i < newSize; ++i) {
        end_->data_ = fill;
        end_->next_ = new Node;
        end_->next_->next_ = end_;
        end_ = end_->next_;
    }
    for (size_type i = newSize; i < oldSize; ++i) {
        Node* toDelete = end_->next_;
        if (end_->next_ == begin_) {
            begin_ = end_ = NULL;
        } else {
            Node* prev = previous(toDelete).getPtr();
            prev->next_ = end_;
            end_->next_ = prev;
        }
        delete toDelete;
    }
}

template <typename T>
void
SingleList<T>::push_back(const_reference value)
{
    resize(size() + 1, value);
}

template <typename T>
void
SingleList<T>::pop_back()
{
    assert(!empty());
    resize(size() - 1);
}

template <typename T>
void
SingleList<T>::push_front(const_reference value)
{
    if (empty()) {
        resize(1, value);
        return;
    }

    Node* temp = new Node(value, begin_);
    begin_ = temp;
}

template <typename T>
void
SingleList<T>::pop_front()
{
    assert(!empty());
    Node* toDelete = begin_;
    begin_ = begin_->next_;
    delete toDelete;
}

template <typename T>
typename SingleList<T>::reference
SingleList<T>::front()
{
    assert(!empty());
    return begin_->data_;
}

template <typename T>
typename SingleList<T>::const_reference
SingleList<T>::front() const
{
    assert(!empty());
    return begin_->data_;
}

template <typename T>
typename SingleList<T>::reference
SingleList<T>::back()
{
    assert(!empty());
    return end_->next_->data_;
}

template <typename T>
typename SingleList<T>::const_reference
SingleList<T>::back() const
{
    assert(!empty());
    return end_->next_->data_;
}

template <typename T>
void 
SingleList<T>::swap(SingleList<T>& rhv)
{
    SingleList<T>::Node* tempBegin = begin_;
    SingleList<T>::Node* tempEnd = end_;

    begin_ = rhv.begin_;
    end_ = rhv.end_;

    rhv.begin_ = tempBegin;
    rhv.end_ = tempEnd;
}

template <typename T>
typename SingleList<T>::iterator 
SingleList<T>::insert(iterator pos, const_reference value)
{
    if (empty()) {
        resize(1, value);
        return end();
    }
    assert(isValidIterator(pos));

    if (pos == begin()) {
        push_front(value);
        return begin_->next_;
    } else if (pos == end()) {
        push_back(value);
        return end();
    }
    const value_type temp = *pos;
    *pos = value;
    return insert_after(pos, temp);
}

template <typename T>
template <typename InputIterator>
void 
SingleList<T>::insert(iterator pos, InputIterator first, InputIterator last)
{
    assert(isValidIterator(pos) || empty());
    while (first != last) {
        pos = insert(pos, *first);
        ++first;
    }
}

template <typename T>
void 
SingleList<T>::insert(iterator pos, int size, const_reference value)
{
    if (empty()) {
        resize(size, value);
        return;
    }
    assert(isValidIterator(pos));
    for (int i = 0; i < size; ++i) {
        pos = insert(pos, value);
    }
}

template <typename T>
typename SingleList<T>::iterator 
SingleList<T>::insert_after(iterator pos, const_reference value)
{
    if (empty()) {
        resize(1, value);
        return begin();
    }
    assert(isValidIterator(pos));
    assert(pos != end());

    if (pos == ++end()) {
        push_back(value);
        return end_->next_;
    }
    return pos.getPtr()->next_ = new Node(value, pos.getPtr()->next_);
}

template <typename T>
template <typename InputIterator>
void 
SingleList<T>::insert_after(iterator pos, InputIterator first, InputIterator last)
{
    assert(isValidIterator(pos) || empty());
    assert(pos != end());
    while (first != last) {
        pos = insert_after(pos, *first);
        ++first;
    }
}

template <typename T>
void 
SingleList<T>::insert_after(iterator pos, int size, const_reference value)
{
    if (empty()) {
        resize(size, value);
        return;
    }
    assert(isValidIterator(pos));
    assert(pos != end());
    for (int i = 0; i < size; ++i) {
        pos = insert_after(pos, value);
    }
}

template <typename T>
typename SingleList<T>::iterator 
SingleList<T>::erase(iterator pos)
{
    assert(!empty());
    assert(isValidIterator(pos));
    assert(pos != end());

    if (pos == begin()) {
        pop_front();
        return begin();
    } else if (pos == end_->next_) {
        pop_back();
        return end_->next_;
    }
    *pos = pos.getPtr()->next_->data_;
    return erase_after(pos);
}

template <typename T>
typename SingleList<T>::iterator 
SingleList<T>::erase(iterator first, iterator last)
{
    while (first != last) { 
        first = erase(first); 
    }
    return first;
}

template <typename T>
typename SingleList<T>::iterator 
SingleList<T>::erase_after(iterator pos)
{
    assert(!empty());
    assert(isValidIterator(pos));
    assert(pos != end() && pos != ++end());
    
    if (pos.getPtr()->next_ == end_->next_) {
        delete pos.getPtr()->next_;
        pos.getPtr()->next_ = end_;
        end_ = pos.getPtr()->next_;
    } else {
        Node* toDelete = pos.getPtr()->next_;
        pos.getPtr()->next_ = toDelete->next_;
        delete toDelete;
    }
    return pos;
}

template <typename T>
typename SingleList<T>::iterator 
SingleList<T>::erase_after(iterator before_first, iterator last)
{
    while (before_first != last) { 
        before_first = erase_after(before_first); 
    }
    return before_first;
}

template <typename T>
void 
SingleList<T>::splice(iterator pos, SingleList<T>& rhv)
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
SingleList<T>::splice(iterator pos, SingleList<T>& rhv, iterator insert)
{
    if (this == &rhv) return;
    assert(isValidIterator(pos));
    assert(rhv.isValidIterator(insert));
    splice(pos, rhv, insert, insert.getPtr()->next_);
}

template <typename T>
void 
SingleList<T>::splice(iterator pos, SingleList<T>& rhv, iterator first, iterator last)
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

    Node* prevLast = (last == rhv.end() ? last.getPtr()->next_ : rhv.previous(last).getPtr());

    if (first == rhv.begin()) {
        rhv.begin_ = last.getPtr();
    } else {
        rhv.previous(first).getPtr()->next_ = last.getPtr();
    }
        
    if (pos == begin()) {
        begin_ = first.getPtr();
    } else if (pos == end()) {
        end_->next_->next_ = first.getPtr();
        end_->next_ = prevLast;
    } else {
        Node* prevPos = previous(pos).getPtr();
        prevPos->next_ = first.getPtr();
    }
    prevLast->next_ = pos.getPtr();
}

template <typename T>
bool 
SingleList<T>::isValidIterator(iterator& pos)
{
    iterator it = begin();
    while (it != end()) {
        if (it == pos) return true;
        ++it;
    }
    if (it == end()) return true;
    return false;
}

template <typename T>
typename SingleList<T>::iterator
SingleList<T>::begin()
{
    return begin_; 
}

template <typename T>
typename SingleList<T>::const_iterator
SingleList<T>::begin() const
{
    return begin_;
}

template <typename T>
typename SingleList<T>::iterator
SingleList<T>::end()
{
    return end_; 
}

template <typename T>
typename SingleList<T>::const_iterator
SingleList<T>::end() const
{
    return end_;
}
template <typename T>
typename SingleList<T>::iterator 
SingleList<T>::previous(iterator pos)
{
    assert(isValidIterator(pos));
    assert(pos != begin());
    iterator prev = begin();
    while (prev.getPtr()->next_ != pos.getPtr()) {
        ++prev;
    }
    return prev;
}

template <typename T>
typename SingleList<T>::const_iterator 
SingleList<T>::previous(const_iterator pos) const
{
    assert(isValidIterator(pos));
    assert(pos != begin());
    const_iterator prev = begin();
    while (prev.getPtr()->next_ != pos.getPtr()) {
        ++prev;
    }
    return prev;
}


///const_iterator

template <typename T>
SingleList<T>::const_iterator::const_iterator()
    : ptr_(NULL)
{
}

template <typename T>
SingleList<T>::const_iterator::const_iterator(const const_iterator& rhv)
    : ptr_(rhv.ptr_)
{
}

template <typename T>
SingleList<T>::const_iterator::const_iterator(Node* valuePtr)
    : ptr_(valuePtr)
{
}

template <typename T>
SingleList<T>::const_iterator::~const_iterator()
{
    ptr_ = NULL;
}

template <typename T>
const typename SingleList<T>::const_iterator&
SingleList<T>::const_iterator::operator=(const const_iterator& right)
{
    if (this == &right) return *this;
    ptr_ = right.ptr_;
    return *this;
}

template <typename T>
typename SingleList<T>::const_reference
SingleList<T>::const_iterator::operator*() const
{
    return ptr_->data_;
}

template <typename T>
const typename SingleList<T>::Node*
SingleList<T>::const_iterator::operator->() const
{
    return ptr_;
}

template <typename T>
const typename SingleList<T>::const_iterator&
SingleList<T>::const_iterator::operator++()
{
    ptr_ = ptr_->next_;
    return *this; 
}

template <typename T>
const typename SingleList<T>::const_iterator
SingleList<T>::const_iterator::operator++(int)
{
    const const_iterator temp = ptr_;
    ptr_ = ptr_->next_;
    return temp; 
}

template <typename T>
const typename SingleList<T>::const_iterator
SingleList<T>::const_iterator::operator+(const size_type i) const
{
    const_iterator temp = ptr_;
    for (size_type j = 0; j < i; ++j) {
        temp = temp->next_;
    }
    return temp;
}

template <typename T>
bool
SingleList<T>::const_iterator::operator==(const const_iterator& right) const
{
    return ptr_ == right.ptr_;
}

template <typename T>
bool
SingleList<T>::const_iterator::operator!=(const const_iterator& right) const
{
    return !(*this == right);
}

template <typename T>
typename SingleList<T>::Node*
SingleList<T>::const_iterator::getPtr() const
{
    return ptr_;
}


///iterator

template <typename T>
SingleList<T>::iterator::iterator()
    : const_iterator()
{
}

template <typename T>
SingleList<T>::iterator::iterator(Node* valuePtr)
    : const_iterator(valuePtr)
{
}

template <typename T>
typename SingleList<T>::reference
SingleList<T>::iterator::operator*()
{
    return const_iterator::getPtr()->data_;
}

template <typename T>
typename SingleList<T>::Node*
SingleList<T>::iterator::operator->()
{
    return const_iterator::getPtr();
}

template <typename T>
typename SingleList<T>::iterator
SingleList<T>::iterator::operator+(const size_type i)
{
    iterator temp = const_iterator::ptr_;
    for (size_type j = 0; j < i; ++j) {
        temp = temp->next_;
    }
    return temp;
}

