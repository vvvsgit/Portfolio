#include "../headers/SortedVector.hpp"
#include "../headers/Sort.hpp"

#include <cassert>

template <typename T>
SortedVector<T>::SortedVector(const size_type size)
    : begin_(NULL)
    , end_(NULL)
    , bufferEnd_(NULL)
{
    privateResize(size);
}

template <typename T>
SortedVector<T>::SortedVector(const int size, const_reference value)
    : begin_(NULL)
    , end_(NULL)
    , bufferEnd_(NULL)
{
    assert(size > 0);
    privateResize(size, value);
}

template <typename T>
SortedVector<T>::~SortedVector()
{
    if (begin_ != NULL) {
        privateResize(0);
        ::operator delete[](reinterpret_cast<void*>(begin_));
        begin_ = end_ = bufferEnd_ = NULL;
    }
}

template <typename T>
template <typename InputIterator>
SortedVector<T>::SortedVector(InputIterator first, InputIterator last)
    : begin_(NULL)
    , end_(NULL)
    , bufferEnd_(NULL)
{
    InputIterator temp = first;
    size_type size = 0;
    while (temp != last) {
        ++temp;
        ++size;
    }
    privateResize(size);
    temp = first;
    for (size_type i = 0; temp != last; ++i) {
        begin_[i] = *temp;
        ++temp;
    }
    quickRecursive(begin(), end());
}

template <typename T>
SortedVector<T>::SortedVector(const SortedVector<T>& rhv)
    : begin_(NULL)
    , end_(NULL)
    , bufferEnd_(NULL)
{
    reserve(rhv.capacity());
    privateResize(rhv.size());

    for (size_type i = 0; i < size(); ++i) {
        begin_[i] = rhv.begin_[i];
    }
}

template <typename T>
const SortedVector<T>&
SortedVector<T>::operator=(const SortedVector<T>& right)
{
    if (this == &right) return *this;

    if ((capacity() != right.capacity() || size() != right.size()) && begin_ != NULL) {
        for (size_type i = 0; i < size(); ++i) {
            begin_[i].~T();
        }
        ::operator delete[](reinterpret_cast<void*>(begin_));
    }
    if (right.begin_ == NULL) {
        begin_ = end_ = bufferEnd_ = NULL;
        return *this;
    }
    reserve(right.capacity());
    privateResize(right.size());
    for (size_type i = 0; i < size(); ++i) {
        begin_[i] = right.begin_[i];
    }
    return *this;
}

template <typename T>
typename SortedVector<T>::const_reference
SortedVector<T>::operator[](const size_type index) const
{
    assert(index < size());
    return begin_[index];
}

template <typename T>
typename SortedVector<T>::const_reference 
SortedVector<T>::front() const
{
    assert(!empty());
    return begin_[0];
}

template <typename T>
typename SortedVector<T>::const_reference 
SortedVector<T>::back() const
{
    assert(!empty());
    return begin_[size() - 1];
}

template <typename T>
bool
SortedVector<T>::operator==(const SortedVector<T>& right) const
{
    if (size() != right.size()) return false;

    for (size_type i = 0; i < size(); ++i) {
        if (begin_[i] != right.begin_[i]) return false;
    } 
    return true;
}

template <typename T>
bool
SortedVector<T>::operator!=(const SortedVector<T>& right) const
{
    return !(*this == right);
}

template <typename T>
bool
SortedVector<T>::operator<(const SortedVector<T>& right) const
{
    if (size() < right.size()) return true;
    if (size() > right.size()) return false;
    
    for (size_type i = 0; i < size(); ++i) {
        if (begin_[i] < right.begin_[i]) return true;
        if (begin_[i] > right.begin_[i]) return false;
    } 
    return false;
}

template <typename T>
bool
SortedVector<T>::operator>(const SortedVector<T>& right) const
{
    return right < *this;
}

template <typename T>
bool
SortedVector<T>::operator<=(const SortedVector<T>& right) const
{
    return !(*this > right);
}

template <typename T>
bool
SortedVector<T>::operator>=(const SortedVector<T>& right) const
{
    return !(*this < right);
}

template <typename T>
bool
SortedVector<T>::empty() const
{
    return end_ == begin_;
}

template <typename T>
typename SortedVector<T>::size_type
SortedVector<T>::size() const
{
    return end_ - begin_;
}

template <typename T>
typename SortedVector<T>::size_type
SortedVector<T>::capacity() const
{
    return bufferEnd_ - begin_;
}

template <typename T>
void
SortedVector<T>::reserve(const size_type newSize)
{
    if (newSize > capacity()) {
        T* temp = reinterpret_cast<T*>(::operator new[](newSize * sizeof(T)));
        for (size_type i = 0; i < size(); ++i) {
            new(temp + i) T(begin_[i]);
        }
        for (size_type i = 0; i < size(); ++i) {
            begin_[i].~T();
        }
        end_ = temp + size();
        ::operator delete[](reinterpret_cast<void*>(begin_));
        begin_ = temp;
        bufferEnd_ = begin_ + newSize;
    }
}

template <typename T>
void
SortedVector<T>::clear()
{
    privateResize(0);
    begin_ = end_ = bufferEnd_ = NULL;
}

template <typename T>
void
SortedVector<T>::resize(const size_type newSize)
{
    const size_type oldSize = size();
    if (newSize == oldSize) return;

    if (newSize > capacity()) reserve(newSize);

    end_ = begin_ + newSize;

    for (size_type i = oldSize; i < newSize; ++i) {
        new(begin_ + i) T();
    }
    for (size_type i = newSize; i < oldSize; ++i) {
        begin_[i].~T();
    }
    quickRecursive(begin(), end());
}

template <typename T>
void
SortedVector<T>::resize(const size_type newSize, const_reference fill)
{
    const size_type oldSize = size();
    if (newSize == oldSize) return;

    if (newSize > capacity()) reserve(newSize);

    end_ = begin_ + newSize;

    for (size_type i = oldSize; i < newSize; ++i) {
        new(begin_ + i) T(fill);
    }
    for (size_type i = newSize; i < oldSize; ++i) {
        begin_[i].~T();
    }
    quickRecursive(begin(), end());
}

template <typename T>
void
SortedVector<T>::privateResize(const size_type newSize)
{
    const size_type oldSize = size();
    if (newSize == oldSize) return;

    if (newSize > capacity()) reserve(newSize);

    end_ = begin_ + newSize;

    for (size_type i = oldSize; i < newSize; ++i) {
        new(begin_ + i) T();
    }
    for (size_type i = newSize; i < oldSize; ++i) {
        begin_[i].~T();
    }
}

template <typename T>
void
SortedVector<T>::privateResize(const size_type newSize, const_reference fill)
{
    const size_type oldSize = size();
    if (newSize == oldSize) return;

    if (newSize > capacity()) reserve(newSize);

    end_ = begin_ + newSize;

    for (size_type i = oldSize; i < newSize; ++i) {
        new(begin_ + i) T(fill);
    }
    for (size_type i = newSize; i < oldSize; ++i) {
        begin_[i].~T();
    }
}

template <typename T>
void
SortedVector<T>::push_back(const_reference value)
{
    const double RESERVE_COEFF = 1.2;
    assert(RESERVE_COEFF > 1.0);

    const size_type oldSize = size();
    if (oldSize == capacity()) {
        const size_type newCapacity = static_cast<size_type>(oldSize * RESERVE_COEFF);
        reserve(oldSize == newCapacity ? oldSize + 1 : newCapacity);
    }

    size_type i;
    for (i = 0; i < oldSize; ++i) {
        if (value < begin_[i]) break;
    }
    value_type temp = value;
    for (; i < oldSize; ++i) {
        std::swap(begin_[i], temp);
    }
    privateResize(oldSize + 1, temp);
}

template <typename T>
void
SortedVector<T>::pop_back()
{
    assert(!empty());
    privateResize(size() - 1);
}

template <typename T>
void
SortedVector<T>::swap(SortedVector<T>& rhv)
{
    SortedVector<T>::pointer tempBegin = begin_;
    SortedVector<T>::pointer tempEnd = end_;
    SortedVector<T>::pointer tempBufferEnd = bufferEnd_;

    begin_ = rhv.begin_;
    end_ = rhv.end_;
    bufferEnd_ = rhv.bufferEnd_;

    rhv.begin_ = tempBegin;
    rhv.end_ = tempEnd;
    rhv.bufferEnd_ = tempBufferEnd;
}

template <typename T>
typename SortedVector<T>::iterator 
SortedVector<T>::insert(iterator pos, const_reference value)
{
    if (empty()) {
        privateResize(1, value);
        return begin();
    }
    assert(pos >= begin() && pos <= end());

    if (!((pos == begin() && value <= *pos) ||
         (pos == end() && value >= *(pos - 1)) ||
         (pos != begin() && pos != end() && *(pos - 1) <= value && value <= *pos))) {
        for (pos = begin(); pos != end(); ++pos) {
            if (value < *pos) {
                break;
            }
        }
    }
    difference_type posSize = pos.ptr_ - begin().ptr_ + 1;
    value_type temp = value;
    for (; pos != end(); ++pos) {
        std::swap(*pos, temp);
    }
    privateResize(size() + 1, temp);
    return begin() + posSize;
}

template <typename T>
void 
SortedVector<T>::insert(iterator pos, int n, const_reference value)
{
    if (empty()) {
        privateResize(size() + n, value);
        return;
    }
    assert(pos >= begin() && pos <= end());

    for (int i = 0; i < n; ++i) {
        pos = insert(pos, value); 
    }
}

template <typename T>
template <typename InputIterator>
void 
SortedVector<T>::insert(iterator pos, InputIterator first, InputIterator last)
{
    assert(pos >= begin() && pos <= end());

    while (first != last) {
        pos = insert(pos, *first);
        ++first;
    }
}

template <typename T>
typename SortedVector<T>::iterator 
SortedVector<T>::erase(iterator pos)
{
    assert(!empty() && pos >= begin() && pos < end());

    iterator temp = pos;
    for (size_type i = 1; temp != end() - 1; ++i) {
        *temp = *(pos + i);
        ++temp;
    }
    const size_type posDiff = pos.ptr_ - begin_;
    privateResize(size() - 1);
    pos = begin_ + posDiff;
    return pos;
}

template <typename T>
typename SortedVector<T>::iterator 
SortedVector<T>::erase(iterator first, iterator last)
{
    assert(!empty() && first >= begin() && first < end() && last >= begin() && last < end() && first < last);

    size_type n = 0;
    while (first + n != last) ++n;

    iterator it = first;
    while (last != end()) {
        *it = *last;
        ++it;
        ++last;
    }

    privateResize(size() - n);

    return first;
}

template <typename T>
typename SortedVector<T>::iterator
SortedVector<T>::begin()
{
    return begin_; 
}

template <typename T>
typename SortedVector<T>::const_iterator
SortedVector<T>::begin() const
{
    return begin_;
}

template <typename T>
typename SortedVector<T>::iterator
SortedVector<T>::end()
{
    return end_; 
}

template <typename T>
typename SortedVector<T>::const_iterator
SortedVector<T>::end() const
{
    return end_;
}

template <typename T>
typename SortedVector<T>::reverse_iterator
SortedVector<T>::rbegin()
{
    return end_ - 1;
}

template <typename T>
typename SortedVector<T>::const_reverse_iterator
SortedVector<T>::rbegin() const
{
    return end_ - 1;
}

template <typename T>
typename SortedVector<T>::reverse_iterator
SortedVector<T>::rend()
{
    return begin_ - 1;
}

template <typename T>
typename SortedVector<T>::const_reverse_iterator
SortedVector<T>::rend() const
{
    return begin_ - 1;
}


///const_iterator

template <typename T>
SortedVector<T>::const_iterator::const_iterator()
    : ptr_(NULL)
{
}

template <typename T>
SortedVector<T>::const_iterator::const_iterator(const const_iterator& rhv)
    : ptr_(rhv.ptr_)
{
}

template <typename T>
SortedVector<T>::const_iterator::const_iterator(pointer valuePtr)
    : ptr_(valuePtr)
{
}

template <typename T>
SortedVector<T>::const_iterator::~const_iterator()
{
    ptr_ = NULL;
}

template <typename T>
const typename SortedVector<T>::const_iterator&
SortedVector<T>::const_iterator::operator=(const const_iterator& right)
{
    if (this == &right) return *this;
    ptr_ = right.ptr_;
    return *this;
}

template <typename T>
typename SortedVector<T>::const_reference
SortedVector<T>::const_iterator::operator*() const
{
    return *ptr_;
}

template <typename T>
typename SortedVector<T>::const_pointer
SortedVector<T>::const_iterator::operator->() const
{
    return ptr_;
}

template <typename T>
const typename SortedVector<T>::const_iterator&
SortedVector<T>::const_iterator::operator++()
{
    ptr_ = ptr_ + 1;
    return *this; 
}

template <typename T>
const typename SortedVector<T>::const_iterator&
SortedVector<T>::const_iterator::operator--()
{
    ptr_ = ptr_ - 1;
    return *this; 
}

template <typename T>
const typename SortedVector<T>::const_iterator
SortedVector<T>::const_iterator::operator++(int)
{
    const const_iterator temp = ptr_;
    ptr_ = ptr_ + 1;
    return temp; 
}

template <typename T>
const typename SortedVector<T>::const_iterator
SortedVector<T>::const_iterator::operator--(int)
{
    const const_iterator temp = ptr_;
    ptr_ = ptr_ - 1;
    return temp; 
}

template <typename T>
typename SortedVector<T>::const_iterator&
SortedVector<T>::const_iterator::operator+=(const size_type i)
{
    ptr_ += i;
    return *this;
}

template <typename T>
typename SortedVector<T>::const_iterator&
SortedVector<T>::const_iterator::operator-=(const size_type i)
{
    ptr_ -= i;
    return *this;
}

template <typename T>
const typename SortedVector<T>::const_iterator
SortedVector<T>::const_iterator::operator+(const size_type i) const
{
    return ptr_ + i;
}

template <typename T>
const typename SortedVector<T>::const_iterator
SortedVector<T>::const_iterator::operator-(const size_type i) const
{
    return ptr_ - i;
}

template <typename T>
bool
SortedVector<T>::const_iterator::operator==(const const_iterator& right) const
{
    return ptr_ == right.ptr_;
}

template <typename T>
bool
SortedVector<T>::const_iterator::operator!=(const const_iterator& right) const
{
    return !(*this == right);
}

template <typename T>
bool
SortedVector<T>::const_iterator::operator<(const const_iterator& right) const
{
    return ptr_ < right.ptr_;
}

template <typename T>
bool
SortedVector<T>::const_iterator::operator>(const const_iterator& right) const
{
    return right < *this;
}

template <typename T>
bool
SortedVector<T>::const_iterator::operator<=(const const_iterator& right) const
{
    return !(*this > right);
}

template <typename T>
bool
SortedVector<T>::const_iterator::operator>=(const const_iterator& right) const
{
    return !(*this < right);
}

template <typename T>
typename SortedVector<T>::const_reference
SortedVector<T>::const_iterator::operator[](const size_type index) const
{
    return ptr_[index];
}

template <typename T>
typename SortedVector<T>::pointer
SortedVector<T>::const_iterator::getPtr() const
{
    return ptr_;
}


///iterator

template <typename T>
SortedVector<T>::iterator::iterator()
    : const_iterator()
{
}

template <typename T>
SortedVector<T>::iterator::iterator(pointer valuePtr)
    : const_iterator(valuePtr)
{
}

template <typename T>
typename SortedVector<T>::reference
SortedVector<T>::iterator::operator*()
{
    return *const_iterator::getPtr();
}

template <typename T>
typename SortedVector<T>::pointer
SortedVector<T>::iterator::operator->()
{
    return const_iterator::getPtr();
}

template <typename T>
typename SortedVector<T>::reference
SortedVector<T>::iterator::operator[](const size_type index)
{
    return const_iterator::getPtr()[index];
}

template <typename T>
typename SortedVector<T>::iterator
SortedVector<T>::iterator::operator+(const size_type i)
{
    return const_iterator::ptr_ + i;
}

template <typename T>
typename SortedVector<T>::iterator
SortedVector<T>::iterator::operator-(const size_type i)
{
    return const_iterator::ptr_ - i;
}


///const_reverse_iterator

template <typename T>
SortedVector<T>::const_reverse_iterator::const_reverse_iterator()
    : ptr_(NULL)
{
}

template <typename T>
SortedVector<T>::const_reverse_iterator::const_reverse_iterator(const const_reverse_iterator& rhv)
    : ptr_(rhv.ptr_)
{
}

template <typename T>
SortedVector<T>::const_reverse_iterator::const_reverse_iterator(pointer valuePtr)
    : ptr_(valuePtr)
{
}

template <typename T>
SortedVector<T>::const_reverse_iterator::~const_reverse_iterator()
{
    ptr_ = NULL;
}

template <typename T>
const typename SortedVector<T>::const_reverse_iterator&
SortedVector<T>::const_reverse_iterator::operator=(const const_reverse_iterator& right)
{
    if (this == &right) return *this;
    ptr_ = right.ptr_;
    return *this;
}

template <typename T>
typename SortedVector<T>::const_reference
SortedVector<T>::const_reverse_iterator::operator*() const
{
    return *ptr_;
}

template <typename T>
typename SortedVector<T>::const_pointer
SortedVector<T>::const_reverse_iterator::operator->() const
{
    return ptr_;
}

template <typename T>
const typename SortedVector<T>::const_reverse_iterator&
SortedVector<T>::const_reverse_iterator::operator++()
{
    ptr_ = ptr_ - 1;
    return *this; 
}

template <typename T>
const typename SortedVector<T>::const_reverse_iterator&
SortedVector<T>::const_reverse_iterator::operator--()
{
    ptr_ = ptr_ + 1;
    return *this; 
}

template <typename T>
const typename SortedVector<T>::const_reverse_iterator
SortedVector<T>::const_reverse_iterator::operator++(int)
{
    const const_reverse_iterator temp = ptr_;
    ptr_ = ptr_ - 1;
    return temp; 
}

template <typename T>
const typename SortedVector<T>::const_reverse_iterator
SortedVector<T>::const_reverse_iterator::operator--(int)
{
    const const_reverse_iterator temp = ptr_;
    ptr_ = ptr_ + 1;
    return temp; 
}

template <typename T>
typename SortedVector<T>::const_reverse_iterator&
SortedVector<T>::const_reverse_iterator::operator+=(const size_type i)
{
    ptr_ -= i;
    return *this;
}

template <typename T>
typename SortedVector<T>::const_reverse_iterator&
SortedVector<T>::const_reverse_iterator::operator-=(const size_type i)
{
    ptr_ += i;
    return *this;
}

template <typename T>
const typename SortedVector<T>::const_reverse_iterator
SortedVector<T>::const_reverse_iterator::operator+(const size_type i) const
{
    return ptr_ - i;
}

template <typename T>
const typename SortedVector<T>::const_reverse_iterator
SortedVector<T>::const_reverse_iterator::operator-(const size_type i) const
{
    return ptr_ + i;
}

template <typename T>
bool
SortedVector<T>::const_reverse_iterator::operator==(const const_reverse_iterator& right) const
{
    return ptr_ == right.ptr_;
}

template <typename T>
bool
SortedVector<T>::const_reverse_iterator::operator!=(const const_reverse_iterator& right) const
{
    return !(*this == right);
}

template <typename T>
bool
SortedVector<T>::const_reverse_iterator::operator<(const const_reverse_iterator& right) const
{
    return ptr_ < right.ptr_;
}

template <typename T>
bool
SortedVector<T>::const_reverse_iterator::operator>(const const_reverse_iterator& right) const
{
    return right < *this;
}

template <typename T>
bool
SortedVector<T>::const_reverse_iterator::operator<=(const const_reverse_iterator& right) const
{
    return !(*this > right);
}

template <typename T>
bool
SortedVector<T>::const_reverse_iterator::operator>=(const const_reverse_iterator& right) const
{
    return !(*this < right);
}

template <typename T>
typename SortedVector<T>::const_reference
SortedVector<T>::const_reverse_iterator::operator[](const size_type index) const
{
    return ptr_[-index];
}

template <typename T>
typename SortedVector<T>::pointer
SortedVector<T>::const_reverse_iterator::getPtr() const
{
    return ptr_;
}


///reverse_iterator

template <typename T>
SortedVector<T>::reverse_iterator::reverse_iterator()
    : const_reverse_iterator()
{
}

template <typename T>
SortedVector<T>::reverse_iterator::reverse_iterator(pointer valuePtr)
    : const_reverse_iterator(valuePtr)
{
}

template <typename T>
typename SortedVector<T>::reference
SortedVector<T>::reverse_iterator::operator*()
{
    return *const_reverse_iterator::getPtr();
}

template <typename T>
typename SortedVector<T>::pointer
SortedVector<T>::reverse_iterator::operator->()
{
    return const_reverse_iterator::getPtr();
}

template <typename T>
typename SortedVector<T>::reference
SortedVector<T>::reverse_iterator::operator[](const size_type index)
{
    return const_reverse_iterator::getPtr()[-index];
}

