#include "../headers/Vector.hpp"

#include <cassert>

template <typename T>
Vector<T>::Vector(const size_type size)
    : begin_(NULL)
    , end_(NULL)
    , bufferEnd_(NULL)
{
    resize(size);
}

template <typename T>
Vector<T>::Vector(const int size, const_reference value)
    : begin_(NULL)
    , end_(NULL)
    , bufferEnd_(NULL)
{
    assert(size > 0);
    resize(size, value);
}

template <typename T>
Vector<T>::~Vector()
{
    if (begin_ != NULL) {
        resize(0);
        ::operator delete[](reinterpret_cast<void*>(begin_));
        begin_ = end_ = bufferEnd_ = NULL;
    }
}

template <typename T>
template <typename InputIterator>
Vector<T>::Vector(InputIterator first, InputIterator last)
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
    resize(size);
    temp = first;
    for (size_type i = 0; temp != last; ++i) {
        begin_[i] = *temp;
        ++temp;
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T>& rhv)
    : begin_(NULL)
    , end_(NULL)
    , bufferEnd_(NULL)
{
    reserve(rhv.capacity());
    resize(rhv.size());

    for (size_type i = 0; i < size(); ++i) {
        begin_[i] = rhv.begin_[i];
    }
}

template <typename T>
const Vector<T>&
Vector<T>::operator=(const Vector<T>& right)
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
    resize(right.size());
    for (size_type i = 0; i < size(); ++i) {
        begin_[i] = right.begin_[i];
    }
    return *this;
}

template <typename T>
typename Vector<T>::const_reference
Vector<T>::operator[](const size_type index) const
{
    assert(index < size());
    return begin_[index];
}

template <typename T>
typename Vector<T>::reference
Vector<T>::operator[](const size_type index)
{
    assert(index < size());
    return begin_[index];
}

template <typename T>
typename Vector<T>::reference 
Vector<T>::front()
{
    assert(!empty());
    return begin_[0];
}

template <typename T>
typename Vector<T>::const_reference 
Vector<T>::front() const
{
    assert(!empty());
    return begin_[0];
}

template <typename T>
typename Vector<T>::reference 
Vector<T>::back()
{
    assert(!empty());
    return begin_[size() - 1];
}

template <typename T>
typename Vector<T>::const_reference 
Vector<T>::back() const
{
    assert(!empty());
    return begin_[size() - 1];
}

template <typename T>
bool
Vector<T>::operator==(const Vector<T>& right) const
{
    if (size() != right.size()) return false;

    for (size_type i = 0; i < size(); ++i) {
        if (begin_[i] != right.begin_[i]) return false;
    } 
    return true;
}

template <typename T>
bool
Vector<T>::operator!=(const Vector<T>& right) const
{
    return !(*this == right);
}

template <typename T>
bool
Vector<T>::operator<(const Vector<T>& right) const
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
Vector<T>::operator>(const Vector<T>& right) const
{
    return right < *this;
}

template <typename T>
bool
Vector<T>::operator<=(const Vector<T>& right) const
{
    return !(*this > right);
}

template <typename T>
bool
Vector<T>::operator>=(const Vector<T>& right) const
{
    return !(*this < right);
}

template <typename T>
bool
Vector<T>::empty() const
{
    return end_ == begin_;
}

template <typename T>
typename Vector<T>::size_type
Vector<T>::size() const
{
    return end_ - begin_;
}

template <typename T>
typename Vector<T>::size_type
Vector<T>::capacity() const
{
    return bufferEnd_ - begin_;
}

template <typename T>
void
Vector<T>::reserve(const size_type newSize)
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
Vector<T>::clear()
{
    resize(0);
    begin_ = end_ = bufferEnd_ = NULL;
}

template <typename T>
void
Vector<T>::resize(const size_type newSize)
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
Vector<T>::resize(const size_type newSize, const_reference fill)
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
Vector<T>::push_back(const_reference value)
{
    assert(RESERVE_COEFF > 1.0);

    const size_type oldSize = size();
    if (oldSize == capacity()) {
        const size_t newCapacity = static_cast<size_type>(oldSize * RESERVE_COEFF);
        reserve(oldSize == newCapacity ? oldSize + 1 : newCapacity);
    }
    resize(oldSize + 1, value);
}

template <typename T>
void
Vector<T>::pop_back()
{
    assert(!empty());
    resize(size() - 1);
}

template <typename T>
void
Vector<T>::swap(Vector<T>& rhv)
{
    Vector<T>::pointer tempBegin = begin_;
    Vector<T>::pointer tempEnd = end_;
    Vector<T>::pointer tempBufferEnd = bufferEnd_;

    begin_ = rhv.begin_;
    end_ = rhv.end_;
    bufferEnd_ = rhv.bufferEnd_;

    rhv.begin_ = tempBegin;
    rhv.end_ = tempEnd;
    rhv.bufferEnd_ = tempBufferEnd;
}

template <typename T>
typename Vector<T>::iterator 
Vector<T>::insert(iterator pos, const_reference value)
{
    if (empty()) {
        resize(1, value);
        return begin();
    }
    assert(pos >= begin() && pos <= end());

    const size_type posDiff = pos.ptr_ - begin_;
    resize(size() + 1);
    pos = begin_ + posDiff;
    iterator it = end();
    --it;
    while (it != pos) {
        *it = *(it - 1);
        --it;
    }
    *it = value;
    ++it;
    return it;
}

template <typename T>
void 
Vector<T>::insert(iterator pos, int n, const_reference value)
{
    if (empty()) {
        resize(size() + n, value);
        return;
    }
    assert(pos >= begin() && pos <= end());

    const size_type posDiff = pos.ptr_ - begin_;
    resize(size() + n);
    pos = begin_ + posDiff;

    iterator it = end();
    --it;
    while (it != pos) {
        *it = *(it - posDiff);
        --it;
    }
    while (it != pos + n) {
        *it = value;
        ++it;
    }
}

template <typename T>
template <typename InputIterator>
void 
Vector<T>::insert(iterator pos, InputIterator first, InputIterator last)
{
    if (!empty()) assert(pos >= begin() && pos <= end());

    size_type n = 0;
    for (InputIterator temp = first; temp != last; ++temp) ++n;
    const size_type posDiff = pos.ptr_ - begin_;
    resize(size() + n);
    pos = begin_ + posDiff;

    iterator it = end();
    --it;
    while (it != pos) {
        *it = *(it - posDiff);
        --it;
    }
    for (InputIterator temp = first; it != pos + n; ++temp, ++it) *it = *temp;
}

template <typename T>
typename Vector<T>::iterator 
Vector<T>::erase(iterator pos)
{
    assert(!empty() && pos >= begin() && pos < end());

    iterator temp = pos;
    for (size_type i = 1; temp != end() - 1; ++i) {
        *temp = *(pos + i);
        ++temp;
    }
    const size_type posDiff = pos.ptr_ - begin_;
    resize(size() - 1);
    pos = begin_ + posDiff;
    return pos;
}

template <typename T>
typename Vector<T>::iterator 
Vector<T>::erase(iterator first, iterator last)
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

    resize(size() - n);

    return first;
}

template <typename T>
typename Vector<T>::iterator
Vector<T>::begin()
{
    return begin_; 
}

template <typename T>
typename Vector<T>::const_iterator
Vector<T>::begin() const
{
    return begin_;
}

template <typename T>
typename Vector<T>::iterator
Vector<T>::end()
{
    return end_; 
}

template <typename T>
typename Vector<T>::const_iterator
Vector<T>::end() const
{
    return end_;
}

template <typename T>
typename Vector<T>::reverse_iterator
Vector<T>::rbegin()
{
    return end_ - 1;
}

template <typename T>
typename Vector<T>::const_reverse_iterator
Vector<T>::rbegin() const
{
    return end_ - 1;
}

template <typename T>
typename Vector<T>::reverse_iterator
Vector<T>::rend()
{
    return begin_ - 1;
}

template <typename T>
typename Vector<T>::const_reverse_iterator
Vector<T>::rend() const
{
    return begin_ - 1;
}


///const_iterator

template <typename T>
Vector<T>::const_iterator::const_iterator()
    : ptr_(NULL)
{
}

template <typename T>
Vector<T>::const_iterator::const_iterator(const const_iterator& rhv)
    : ptr_(rhv.ptr_)
{
}

template <typename T>
Vector<T>::const_iterator::const_iterator(pointer valuePtr)
    : ptr_(valuePtr)
{
}

template <typename T>
Vector<T>::const_iterator::~const_iterator()
{
    ptr_ = NULL;
}

template <typename T>
const typename Vector<T>::const_iterator&
Vector<T>::const_iterator::operator=(const const_iterator& right)
{
    if (this == &right) return *this;
    ptr_ = right.ptr_;
    return *this;
}

template <typename T>
typename Vector<T>::const_reference
Vector<T>::const_iterator::operator*() const
{
    return *ptr_;
}

template <typename T>
typename Vector<T>::const_pointer
Vector<T>::const_iterator::operator->() const
{
    return ptr_;
}

template <typename T>
const typename Vector<T>::const_iterator&
Vector<T>::const_iterator::operator++()
{
    ptr_ = ptr_ + 1;
    return *this; 
}

template <typename T>
const typename Vector<T>::const_iterator&
Vector<T>::const_iterator::operator--()
{
    ptr_ = ptr_ - 1;
    return *this; 
}

template <typename T>
const typename Vector<T>::const_iterator
Vector<T>::const_iterator::operator++(int)
{
    const const_iterator temp = ptr_;
    ptr_ = ptr_ + 1;
    return temp; 
}

template <typename T>
const typename Vector<T>::const_iterator
Vector<T>::const_iterator::operator--(int)
{
    const const_iterator temp = ptr_;
    ptr_ = ptr_ - 1;
    return temp; 
}

template <typename T>
typename Vector<T>::const_iterator&
Vector<T>::const_iterator::operator+=(const size_type i)
{
    ptr_ += i;
    return *this;
}

template <typename T>
typename Vector<T>::const_iterator&
Vector<T>::const_iterator::operator-=(const size_type i)
{
    ptr_ -= i;
    return *this;
}

template <typename T>
const typename Vector<T>::const_iterator
Vector<T>::const_iterator::operator+(const size_type i) const
{
    return ptr_ + i;
}

template <typename T>
const typename Vector<T>::const_iterator
Vector<T>::const_iterator::operator-(const size_type i) const
{
    return ptr_ - i;
}

template <typename T>
bool
Vector<T>::const_iterator::operator==(const const_iterator& right) const
{
    return ptr_ == right.ptr_;
}

template <typename T>
bool
Vector<T>::const_iterator::operator!=(const const_iterator& right) const
{
    return !(*this == right);
}

template <typename T>
bool
Vector<T>::const_iterator::operator<(const const_iterator& right) const
{
    return ptr_ < right.ptr_;
}

template <typename T>
bool
Vector<T>::const_iterator::operator>(const const_iterator& right) const
{
    return right < *this;
}

template <typename T>
bool
Vector<T>::const_iterator::operator<=(const const_iterator& right) const
{
    return !(*this > right);
}

template <typename T>
bool
Vector<T>::const_iterator::operator>=(const const_iterator& right) const
{
    return !(*this < right);
}

template <typename T>
typename Vector<T>::const_reference
Vector<T>::const_iterator::operator[](const size_type index) const
{
    return ptr_[index];
}

template <typename T>
typename Vector<T>::pointer
Vector<T>::const_iterator::getPtr() const
{
    return ptr_;
}


///iterator

template <typename T>
Vector<T>::iterator::iterator()
    : const_iterator()
{
}

template <typename T>
Vector<T>::iterator::iterator(pointer valuePtr)
    : const_iterator(valuePtr)
{
}

template <typename T>
typename Vector<T>::reference
Vector<T>::iterator::operator*()
{
    return *const_iterator::getPtr();
}

template <typename T>
typename Vector<T>::pointer
Vector<T>::iterator::operator->()
{
    return const_iterator::getPtr();
}

template <typename T>
typename Vector<T>::reference
Vector<T>::iterator::operator[](const size_type index)
{
    return const_iterator::getPtr()[index];
}

template <typename T>
typename Vector<T>::iterator
Vector<T>::iterator::operator+(const size_type i)
{
    return const_iterator::ptr_ + i;
}

template <typename T>
typename Vector<T>::iterator
Vector<T>::iterator::operator-(const size_type i)
{
    return const_iterator::ptr_ - i;
}


///const_reverse_iterator

template <typename T>
Vector<T>::const_reverse_iterator::const_reverse_iterator()
    : ptr_(NULL)
{
}

template <typename T>
Vector<T>::const_reverse_iterator::const_reverse_iterator(const const_reverse_iterator& rhv)
    : ptr_(rhv.ptr_)
{
}

template <typename T>
Vector<T>::const_reverse_iterator::const_reverse_iterator(pointer valuePtr)
    : ptr_(valuePtr)
{
}

template <typename T>
Vector<T>::const_reverse_iterator::~const_reverse_iterator()
{
    ptr_ = NULL;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator&
Vector<T>::const_reverse_iterator::operator=(const const_reverse_iterator& right)
{
    if (this == &right) return *this;
    ptr_ = right.ptr_;
    return *this;
}

template <typename T>
typename Vector<T>::const_reference
Vector<T>::const_reverse_iterator::operator*() const
{
    return *ptr_;
}

template <typename T>
typename Vector<T>::const_pointer
Vector<T>::const_reverse_iterator::operator->() const
{
    return ptr_;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator&
Vector<T>::const_reverse_iterator::operator++()
{
    ptr_ = ptr_ - 1;
    return *this; 
}

template <typename T>
const typename Vector<T>::const_reverse_iterator&
Vector<T>::const_reverse_iterator::operator--()
{
    ptr_ = ptr_ + 1;
    return *this; 
}

template <typename T>
const typename Vector<T>::const_reverse_iterator
Vector<T>::const_reverse_iterator::operator++(int)
{
    const const_reverse_iterator temp = ptr_;
    ptr_ = ptr_ - 1;
    return temp; 
}

template <typename T>
const typename Vector<T>::const_reverse_iterator
Vector<T>::const_reverse_iterator::operator--(int)
{
    const const_reverse_iterator temp = ptr_;
    ptr_ = ptr_ + 1;
    return temp; 
}

template <typename T>
typename Vector<T>::const_reverse_iterator&
Vector<T>::const_reverse_iterator::operator+=(const size_type i)
{
    ptr_ -= i;
    return *this;
}

template <typename T>
typename Vector<T>::const_reverse_iterator&
Vector<T>::const_reverse_iterator::operator-=(const size_type i)
{
    ptr_ += i;
    return *this;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator
Vector<T>::const_reverse_iterator::operator+(const size_type i) const
{
    return ptr_ - i;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator
Vector<T>::const_reverse_iterator::operator-(const size_type i) const
{
    return ptr_ + i;
}

template <typename T>
bool
Vector<T>::const_reverse_iterator::operator==(const const_reverse_iterator& right) const
{
    return ptr_ == right.ptr_;
}

template <typename T>
bool
Vector<T>::const_reverse_iterator::operator!=(const const_reverse_iterator& right) const
{
    return !(*this == right);
}

template <typename T>
bool
Vector<T>::const_reverse_iterator::operator<(const const_reverse_iterator& right) const
{
    return ptr_ < right.ptr_;
}

template <typename T>
bool
Vector<T>::const_reverse_iterator::operator>(const const_reverse_iterator& right) const
{
    return right < *this;
}

template <typename T>
bool
Vector<T>::const_reverse_iterator::operator<=(const const_reverse_iterator& right) const
{
    return !(*this > right);
}

template <typename T>
bool
Vector<T>::const_reverse_iterator::operator>=(const const_reverse_iterator& right) const
{
    return !(*this < right);
}

template <typename T>
typename Vector<T>::const_reference
Vector<T>::const_reverse_iterator::operator[](const size_type index) const
{
    return ptr_[-index];
}

template <typename T>
typename Vector<T>::pointer
Vector<T>::const_reverse_iterator::getPtr() const
{
    return ptr_;
}


///reverse_iterator

template <typename T>
Vector<T>::reverse_iterator::reverse_iterator()
    : const_reverse_iterator()
{
}

template <typename T>
Vector<T>::reverse_iterator::reverse_iterator(pointer valuePtr)
    : const_reverse_iterator(valuePtr)
{
}

template <typename T>
typename Vector<T>::reference
Vector<T>::reverse_iterator::operator*()
{
    return *const_reverse_iterator::getPtr();
}

template <typename T>
typename Vector<T>::pointer
Vector<T>::reverse_iterator::operator->()
{
    return const_reverse_iterator::getPtr();
}

template <typename T>
typename Vector<T>::reference
Vector<T>::reverse_iterator::operator[](const size_type index)
{
    return const_reverse_iterator::getPtr()[-index];
}

