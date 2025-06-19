#include "../headers/Map.hpp"
#include "../headers/Queue.hpp"

#include <cassert>


///Node

template <typename K, typename D>
Map<K, D>::Node::Node(const value_type& value, Node* parent, Node* left, Node* right)
    : data_(value)
    , parent_(parent)
    , left_(left)
    , right_(right)
{
}


///Pair

template <typename K, typename D>
template <typename F, typename S>
Map<K, D>::Pair<F, S>::Pair(const F& first, const S& second)
    : first_(first)
    , second_(second)
{
}


///Map

template <typename K, typename D>
Map<K, D>::Map()
    : root_(NULL)
{
}

template <typename K, typename D>
Map<K, D>::Map(const Map<K, D>& rhv)
    : root_(NULL)
{
    copyMap(rhv.root_);
}

template <typename K, typename D>
template <typename InputIterator>
Map<K, D>::Map(InputIterator first, InputIterator last)
    : root_(NULL)
{
    while (first != last) {
        insert(*first);
        ++first;
    }
}

template <typename K, typename D>
Map<K, D>::~Map()
{
    clear();
}

template <typename K, typename D>
const Map<K, D>&
Map<K, D>::operator=(const Map<K, D>& rhv)
{
    if (this == &rhv) return *this;
    clear();
    copyMap(rhv.root_);
    return *this;
}

template <typename K, typename D>
void
Map<K, D>::swap(Map<K, D>& rhv)
{
    Map<K, D>::Node* tempRoot = root_;

    root_ = rhv.root_;

    rhv.root_ = tempRoot;
}

template <typename K, typename D>
typename Map<K, D>::size_type
Map<K, D>::size() const
{
    int result = 0;
    size(root_, result);
    return result;
}

template <typename K, typename D>
bool
Map<K, D>::empty() const
{
    return root_ == NULL;
}

template <typename K, typename D>
void
Map<K, D>::clear()
{
    clear(root_);
    root_ = NULL;
}

template <typename K, typename D>
typename Map<K, D>::template Pair<typename Map<K, D>::iterator, bool>
Map<K, D>::insert(const key_type& key, const data_type& data)
{
    return insert(value_type(key, data));
}

template <typename K, typename D>
typename Map<K, D>::iterator 
Map<K, D>::insert(iterator pos, const key_type& key, const data_type& data)
{
    return insert(pos, value_type(key, data));
}

template <typename K, typename D>
typename Map<K, D>::template Pair<typename Map<K, D>::iterator, bool>
Map<K, D>::insert(const_reference value)
{
    Node** ptr = &root_;
    Node* parent = NULL;

    while (*ptr != NULL) {
        parent = *ptr;
        if (value.first < (*ptr)->data_.first) {
            ptr = &((*ptr)->left_);
        } else if (value > (*ptr)->data_) {
            ptr = &((*ptr)->right_);
        } else {
            return Pair<iterator, bool>(*ptr, false);
        }
    }

    *ptr = new Node(value, parent);
    balance(*ptr);

    return Pair<iterator, bool>(*ptr, true);
}

template <typename K, typename D>
typename Map<K, D>::iterator 
Map<K, D>::insert(iterator pos, const_reference value)
{
    if (empty()) return insert(*pos).first_;
    goUp(pos, value);
    goDownInsert(pos, value);
    balance(pos);
    return pos;
}

template <typename K, typename D>
template <typename InputIterator>
void 
Map<K, D>::insert(iterator pos, InputIterator first, InputIterator last)
{
    while (first != last) {
        insert(pos, *first);
        ++first;
    }
}

template <typename K, typename D>
typename Map<K, D>::data_type& 
Map<K, D>::operator[](const key_type& k)
{
    return (*((insert(value_type(k, data_type()))).first_)).second;
}

template <typename K, typename D>
typename Map<K, D>::iterator 
Map<K, D>::erase(iterator pos)
{
    assert(!empty());
    
    iterator replace = pos.getPtr()->parent_;
    if (pos.getPtr()->left_ == NULL && pos.getPtr()->right_ == NULL) {
        if (pos.getPtr() == root_) {
            clear();
            return replace;
        }
        if (replace.getPtr()->left_ == pos.getPtr()) {
            replace.getPtr()->left_ = NULL;
        } else {
            replace.getPtr()->right_ = NULL;
        }
        delete pos.getPtr();
        balance(replace);
        return replace;
    }

    if (pos.getPtr()->left_ == NULL || pos.getPtr()->right_ == NULL) {
        replace = (pos.getPtr()->left_ != NULL ? pos.getPtr()->left_ : pos.getPtr()->right_);
        replace.getPtr()->parent_ = pos.getPtr()->parent_;
        if (pos.getPtr() == root_) {
            delete pos.getPtr();
            root_ = replace.getPtr();
            balance(replace);
            return replace;
        }
        if (replace.getPtr()->parent_->left_ == pos.getPtr()) {
            replace.getPtr()->parent_->left_ = replace.getPtr();
        } else {
            replace.getPtr()->parent_->right_ = replace.getPtr();
        }
        delete pos.getPtr();
        balance(replace);
        return replace;
    }

    const_iterator const_prev = pos.prevInOrder(pos);
    iterator prev(const_prev.getPtr());
    *pos = *prev;
    return erase(prev);
}

template <typename K, typename D>
typename Map<K, D>::size_type 
Map<K, D>::erase(const key_type& value)
{
    size_type count = 0;
    iterator target = find(value);
    if (target == NULL) return count;
    ++count;
    erase(target);
    return count;
}

template <typename K, typename D>
typename Map<K, D>::iterator 
Map<K, D>::erase(iterator first, iterator last)
{
    assert(!empty());

    while (first != last) {
        erase(first++);
    }
    return last;
}

template <typename K, typename D>
typename Map<K, D>::iterator 
Map<K, D>::find(const key_type& k) const
{
    Node* target = root_;
    while (target != NULL && target->data_.first != k) {
        if (k < target->data_.first) {
            target = target->left_;
        } else {
            target = target->right_;
        }
    }
    return target;
}

template <typename K, typename D>
typename Map<K, D>::size_type 
Map<K, D>::count(const key_type& k) const
{
    iterator first = lower_bound(k);
    iterator last = upper_bound(k);
    size_type result = 0;
    while (first != last) {
        ++result;
        ++first;
    }
    return result;
}

template <typename K, typename D>
typename Map<K, D>::iterator 
Map<K, D>::lower_bound(const key_type& k) const
{
    const_iterator first = begin();
    const_iterator last = end();
    while (first != last) {
        if (!((*first).first < k)) return first;
        ++first;
    }
    return last;
}

template <typename K, typename D>
typename Map<K, D>::iterator 
Map<K, D>::upper_bound(const  key_type& k) const
{
    const_iterator first = begin();
    const_iterator last = end();
    while (first != last) {
        if ((*first).first > k) return first;
        ++first;
    }
    return last;
}

template <typename K, typename D>
typename Map<K, D>::template Pair<typename Map<K, D>::iterator, typename Map<K, D>::iterator>
Map<K, D>::equal_range(const key_type& k) const
{
    return Pair<iterator, iterator>(lower_bound(k), upper_bound(k));
}

template <typename K, typename D>
bool
Map<K, D>::operator==(const Map<K, D>& rhv) const
{
    if (size() != rhv.size()) return false;

    const_iterator it = begin();
    const_iterator rhvIt = rhv.begin();
    const_iterator last = end();
    while (it != last) {
        if (*it != *rhvIt) return false;
        ++it;
        ++rhvIt;
    }
    return true;
}

template <typename K, typename D>
bool
Map<K, D>::operator!=(const Map<K, D>& rhv) const
{
    return !(*this == rhv);
}

template <typename K, typename D>
bool
Map<K, D>::operator<(const Map<K, D>& rhv) const
{
    if (size() < rhv.size()) return true;
    if (size() > rhv.size()) return false;

    const_iterator it = begin();
    const_iterator rhvIt = rhv.begin();
    const_iterator last = end();
    while (it != last) {
        if (*it < *rhvIt) return true;
        if (*it > *rhvIt) return false;
        ++it;
        ++rhvIt;
    }
    return false;
}

template <typename K, typename D>
bool
Map<K, D>::operator>(const Map<K, D>& rhv) const
{
    return rhv < *this;
}

template <typename K, typename D>
bool
Map<K, D>::operator<=(const Map<K, D>& rhv) const
{
    return !(*this > rhv);
}

template <typename K, typename D>
bool
Map<K, D>::operator>=(const Map<K, D>& rhv) const
{
    return !(*this < rhv);
}

template <typename K, typename D>
void
Map<K, D>::print() const
{
    print(root_);
}

template <typename K, typename D>
typename Map<K, D>::iterator
Map<K, D>::begin()
{
    return topLeft(root_);
}

template <typename K, typename D>
typename Map<K, D>::iterator
Map<K, D>::end()
{
    return NULL;
}

template <typename K, typename D>
typename Map<K, D>::const_iterator
Map<K, D>::begin() const
{
    return topLeft(root_);
}

template <typename K, typename D>
typename Map<K, D>::const_iterator
Map<K, D>::end() const
{
    return NULL;
}

template <typename K, typename D>
typename Map<K, D>::reverse_iterator
Map<K, D>::rbegin()
{
    return topRight(root_);
}

template <typename K, typename D>
typename Map<K, D>::reverse_iterator
Map<K, D>::rend()
{
    return NULL;
}

template <typename K, typename D>
typename Map<K, D>::const_reverse_iterator
Map<K, D>::rbegin() const
{
    return topRight(root_);
}

template <typename K, typename D>
typename Map<K, D>::const_reverse_iterator
Map<K, D>::rend() const
{
    return NULL;
}


///Map::private functions

template <typename K, typename D> 
void
Map<K, D>::copyMap(const Node* ptr)
{
    if (ptr != NULL) {
        insert(ptr->data_);
        copyMap(ptr->left_);
        copyMap(ptr->right_);
    }
}

template <typename K, typename D> 
void 
Map<K, D>::size(const Node* ptr, int& result) const
{
    if (ptr != NULL) {
        size(ptr->left_, result);
        ++result;
        size(ptr->right_, result);
    }
}

template <typename K, typename D>
void
Map<K, D>::clear(Node* ptr)
{
    if (ptr != NULL) {
        clear(ptr->left_);
        clear(ptr->right_);
        delete ptr;
    }
}

template <typename K, typename D>
typename Map<K, D>::Node* 
Map<K, D>::topLeft(Node* ptr) const
{
    if (ptr == NULL) return ptr;
    while (ptr->left_ != NULL) {
        ptr = ptr->left_;
    }
    return ptr;
}

template <typename K, typename D>
typename Map<K, D>::Node* 
Map<K, D>::topRight(Node* ptr) const
{
    if (ptr == NULL) return ptr;
    while (ptr->right_ != NULL) {
        ptr = ptr->right_;
    }
    return ptr;
}

template <typename K, typename D>
void
Map<K, D>::goUp(const_iterator& pos, const_reference value) const
{
    if ((*pos).first > value.first) {
        const_iterator parent = pos.leftParent(pos); 
        while (parent != NULL && *parent > value) {
            pos = parent;
            parent = pos.leftParent(pos);
        }
    }
    if ((*pos).first < value.first) {
        const_iterator parent = pos.rightParent(pos); 
        while (parent != NULL && *parent < value) {
            pos = parent;
            parent = pos.rightParent(pos);
        }
    }
}

template <typename K, typename D>
void
Map<K, D>::goDownInsert(iterator& pos, const_reference value)
{
    while (pos != NULL) {
        if (*pos > value) {
            if (pos.getPtr()->left_ == NULL) {
                pos.getPtr()->left_ = new Node(value, pos.getPtr());
                pos = pos.getPtr()->left_;
                return;
            }
            pos = pos.getPtr()->left_;
            continue;
        }
        if (*pos < value) {
            if (pos.getPtr()->right_ == NULL) {
                pos.getPtr()->right_ = new Node(value, pos.getPtr());
                pos = pos.getPtr()->right_;
                return;
            }
            pos = pos.getPtr()->right_;
            continue;
        }
    }
}

template <typename K, typename D>
void 
Map<K, D>::balance(iterator it)
{
    while (it != NULL) {
        int balanceFactor = getDiff(it);

        if (balanceFactor > 1) {
            iterator leftIt(it.getPtr()->left_);
            if (getDiff(leftIt) < 0) {
                rotateLeft(leftIt);
            }
            rotateRight(it);
        } else if (balanceFactor < -1) {
            iterator rightIt(it.getPtr()->right_);
            if (getDiff(rightIt) > 0) {
                rotateRight(rightIt);
            }
            rotateLeft(it);
        }
        it = iterator(it.getPtr()->parent_);
    }
}

template <typename K, typename D>
int
Map<K, D>::getDiff(iterator it) const
{
    return depth(it.getPtr()->left_) - depth(it.getPtr()->right_);
}

template <typename K, typename D> 
int 
Map<K, D>::depth(const Node* ptr) const
{
    int result = 0;
    depth(ptr, result);
    return result;
}

template <typename K, typename D> 
void 
Map<K, D>::depth(const Node* ptr, int& result, const int counter) const
{
    if (ptr != NULL) {
        if (result <= counter) result = counter + 1;
        depth(ptr->left_, result, counter + 1);
        depth(ptr->right_, result, counter + 1);
    }
}

template <typename K, typename D>
void 
Map<K, D>::rotateLeft(iterator& it)
{
    Node* parent = it.getPtr()->parent_;
    Node* child = it.getPtr()->right_;
    it.getPtr()->parent_ = it.getPtr()->right_;
    it.getPtr()->right_ = it.getPtr()->right_->left_;
    child->left_ = it.getPtr();
    child->parent_ = parent;
    if (parent != NULL) {
        if (parent->left_ == it.getPtr()) {
            child->parent_->left_ = child;
        } else {
            child->parent_->right_ = child;
        }
    }
    if (root_ == it.getPtr()) root_ = child;

    it = it.getPtr()->parent_;
}

template <typename K, typename D>
void 
Map<K, D>::rotateRight(iterator& it)
{
    Node* parent = it.getPtr()->parent_;
    Node* child = it.getPtr()->left_;
    it.getPtr()->parent_ = it.getPtr()->left_;
    it.getPtr()->left_ = it.getPtr()->left_->right_;
    child->right_ = it.getPtr();
    child->parent_ = parent;
    if (parent != NULL) {
        if (parent->left_ == it.getPtr()) {
            child->parent_->left_ = child;
        } else {
            child->parent_->right_ = child;
        }
    }
    if (root_ == it.getPtr()) root_ = child;

    it = it.getPtr()->parent_;
}

template <typename K, typename D>
void
Map<K, D>::print(const Node* ptr, const int spaces) const
{
    if (ptr != NULL) {
        print(ptr->right_, spaces + 5);
        for (int i = 0; i < spaces; ++i) std::cout << ' ';
        std::cout << ptr->data_.first << '(' << ptr->data_.second << ')';
        print(ptr->left_, spaces + 5);
    }
    std::cout << std::endl;
}


///const_iterator

template <typename K, typename D>
Map<K, D>::const_iterator::const_iterator()
    : ptr_(NULL)
{
}

template <typename K, typename D>
Map<K, D>::const_iterator::const_iterator(const const_iterator& rhv)
    : ptr_(rhv.ptr_)
{
}

template <typename K, typename D>
Map<K, D>::const_iterator::~const_iterator()
{
    ptr_ = NULL;
}

template <typename K, typename D>
const typename Map<K, D>::const_iterator&
Map<K, D>::const_iterator::operator=(const const_iterator& rhv)
{
    if (this == &rhv) return *this;
    ptr_ = rhv.ptr_;
    return *this;
}

template <typename K, typename D>
typename Map<K, D>::const_reference
Map<K, D>::const_iterator::operator*() const
{
    return ptr_->data_;
}

template <typename K, typename D>
const typename Map<K, D>::Node*
Map<K, D>::const_iterator::operator->() const
{
    return ptr_;
}

template <typename K, typename D>
const typename Map<K, D>::const_iterator&
Map<K, D>::const_iterator::operator++()
{
    assert(ptr_ != NULL);

    *this = nextInOrder(*this);
    return *this; 
}

template <typename K, typename D>
const typename Map<K, D>::const_iterator&
Map<K, D>::const_iterator::operator--()
{
    assert(ptr_ != NULL);

    *this = prevInOrder(*this);
    return *this; 
}

template <typename K, typename D>
const typename Map<K, D>::const_iterator
Map<K, D>::const_iterator::operator++(int)
{
    assert(ptr_ != NULL);

    const const_iterator temp = ptr_;
    *this = nextInOrder(*this);
    return temp; 
}

template <typename K, typename D>
const typename Map<K, D>::const_iterator
Map<K, D>::const_iterator::operator--(int)
{
    assert(ptr_ != NULL);

    const const_iterator temp = ptr_;
    *this = prevInOrder(*this);
    return temp; 
}

template <typename K, typename D>
typename Map<K, D>::const_iterator
Map<K, D>::const_iterator::nextInOrder(const_iterator it)
{
    if (it.ptr_->right_ != NULL) {
        it.ptr_ = it.ptr_->right_;
        while (it.ptr_->left_ != NULL) {
            it.ptr_ = it.ptr_->left_;
        }
        return it; 
    }
    return rightParent(it);
}

template <typename K, typename D>
typename Map<K, D>::const_iterator
Map<K, D>::const_iterator::rightParent(const_iterator it)
{
    Node* parent = it.ptr_->parent_;
    while (parent != NULL && parent->right_ == it.ptr_) {
        it.ptr_ = parent;
        parent = parent->parent_;
    }
    return parent;
}

template <typename K, typename D>
typename Map<K, D>::const_iterator
Map<K, D>::const_iterator::prevInOrder(const_iterator it)
{
    if (it.ptr_->left_ != NULL) {
        it.ptr_ = it.ptr_->left_;
        while (it.ptr_->right_ != NULL) {
            it.ptr_ = it.ptr_->right_;
        }
        return it; 
    }
    return leftParent(it);
}

template <typename K, typename D>
typename Map<K, D>::const_iterator
Map<K, D>::const_iterator::leftParent(const_iterator it)
{
    Node* parent = it.ptr_->parent_;
    while (parent != NULL && parent->left_ == it.ptr_) {
        it.ptr_ = parent;
        parent = parent->parent_;
    }
    return parent;
}

template <typename K, typename D>
bool
Map<K, D>::const_iterator::operator==(const const_iterator& rhv) const
{
    return ptr_ == rhv.ptr_;
}

template <typename K, typename D>
bool
Map<K, D>::const_iterator::operator!=(const const_iterator& rhv) const
{
    return !(*this == rhv);
}

template <typename K, typename D>
Map<K, D>::const_iterator::const_iterator(Node* valuePtr)
    : ptr_(valuePtr)
{
}

template <typename K, typename D>
typename Map<K, D>::Node*
Map<K, D>::const_iterator::getPtr() const
{
    return ptr_;
}


///iterator

template <typename K, typename D>
Map<K, D>::iterator::iterator()
    : const_iterator()
{
}

template <typename K, typename D>
typename Map<K, D>::reference
Map<K, D>::iterator::operator*()
{
    return const_iterator::getPtr()->data_;
}

template <typename K, typename D>
typename Map<K, D>::Node*
Map<K, D>::iterator::operator->()
{
    return const_iterator::getPtr();
}

template <typename K, typename D>
Map<K, D>::iterator::iterator(Node* valuePtr)
    : const_iterator(valuePtr)
{
}


///const_reverse_iterator

template <typename K, typename D>
Map<K, D>::const_reverse_iterator::const_reverse_iterator()
    : ptr_(NULL)
{
}

template <typename K, typename D>
Map<K, D>::const_reverse_iterator::const_reverse_iterator(const const_reverse_iterator& rhv)
    : ptr_(rhv.ptr_)
{
}

template <typename K, typename D>
Map<K, D>::const_reverse_iterator::~const_reverse_iterator()
{
    ptr_ = NULL;
}

template <typename K, typename D>
const typename Map<K, D>::const_reverse_iterator&
Map<K, D>::const_reverse_iterator::operator=(const const_reverse_iterator& rhv)
{
    if (this == &rhv) return *this;
    ptr_ = rhv.ptr_;
    return *this;
}

template <typename K, typename D>
typename Map<K, D>::const_reference
Map<K, D>::const_reverse_iterator::operator*() const
{
    return ptr_->data_;
}

template <typename K, typename D>
const typename Map<K, D>::Node*
Map<K, D>::const_reverse_iterator::operator->() const
{
    return ptr_;
}

template <typename K, typename D>
const typename Map<K, D>::const_reverse_iterator&
Map<K, D>::const_reverse_iterator::operator++()
{
    assert(ptr_ != NULL);

    *this = nextInOrder(*this);
    return *this; 
}

template <typename K, typename D>
const typename Map<K, D>::const_reverse_iterator&
Map<K, D>::const_reverse_iterator::operator--()
{
    assert(ptr_ != NULL);

    *this = prevInOrder(*this);
    return *this; 
}

template <typename K, typename D>
const typename Map<K, D>::const_reverse_iterator
Map<K, D>::const_reverse_iterator::operator++(int)
{
    assert(ptr_ != NULL);

    const const_reverse_iterator temp = ptr_;
    *this = nextInOrder(*this);
    return temp; 
}

template <typename K, typename D>
const typename Map<K, D>::const_reverse_iterator
Map<K, D>::const_reverse_iterator::operator--(int)
{
    assert(ptr_ != NULL);

    const const_reverse_iterator temp = ptr_;
    *this = prevInOrder(*this);
    return temp; 
}

template <typename K, typename D>
typename Map<K, D>::const_reverse_iterator
Map<K, D>::const_reverse_iterator::nextInOrder(const_reverse_iterator it)
{
    if (it.ptr_->left_ != NULL) {
        it.ptr_ = it.ptr_->left_;
        while (it.ptr_->right_ != NULL) {
            it.ptr_ = it.ptr_->right_;
        }
        return it; 
    }
    Node* parent = it.ptr_->parent_;
    while (parent != NULL && parent->left_ == it.ptr_) {
        it.ptr_ = parent;
        parent = parent->parent_;
    }
    it.ptr_ = parent;

    return it; 
}

template <typename K, typename D>
typename Map<K, D>::const_reverse_iterator
Map<K, D>::const_reverse_iterator::prevInOrder(const_reverse_iterator it)
{
    if (it.ptr_->right_ != NULL) {
        it.ptr_ = it.ptr_->right_;
        while (it.ptr_->left_ != NULL) {
            it.ptr_ = it.ptr_->left_;
        }
        return it; 
    }
    Node* parent = it.ptr_->parent_;
    while (parent != NULL && parent->right_ == it.ptr_) {
        it.ptr_ = parent;
        parent = parent->parent_;
    }
    it.ptr_ = parent;

    return it; 
}

template <typename K, typename D>
bool
Map<K, D>::const_reverse_iterator::operator==(const const_reverse_iterator& rhv) const
{
    return ptr_ == rhv.ptr_;
}

template <typename K, typename D>
bool
Map<K, D>::const_reverse_iterator::operator!=(const const_reverse_iterator& rhv) const
{
    return !(*this == rhv);
}

template <typename K, typename D>
Map<K, D>::const_reverse_iterator::const_reverse_iterator(Node* valuePtr)
    : ptr_(valuePtr)
{
}

template <typename K, typename D>
typename Map<K, D>::Node*
Map<K, D>::const_reverse_iterator::getPtr() const
{
    return ptr_;
}


///reverse_iterator

template <typename K, typename D>
Map<K, D>::reverse_iterator::reverse_iterator()
    : const_reverse_iterator()
{
}

template <typename K, typename D>
typename Map<K, D>::reference
Map<K, D>::reverse_iterator::operator*()
{
    return const_reverse_iterator::getPtr()->data_;
}

template <typename K, typename D>
typename Map<K, D>::Node*
Map<K, D>::reverse_iterator::operator->()
{
    return const_reverse_iterator::getPtr();
}

template <typename K, typename D>
Map<K, D>::reverse_iterator::reverse_iterator(Node* valuePtr)
    : const_reverse_iterator(valuePtr)
{
}

