#include "../headers/Set.hpp"
#include "../headers/Queue.hpp"
#include "../headers/Stack.hpp"

#include <cassert>


///Node

template <typename T>
Set<T>::Node::Node(const T& data, Node* parent, Node* left, Node* right)
    : data_(data)
    , parent_(parent)
    , left_(left)
    , right_(right)
{
}


///Pair

template <typename T>
template <typename F, typename S>
Set<T>::Pair<F, S>::Pair(const F& first, const S& second)
    : first_(first)
    , second_(second)
{
}


///Set

template <typename T>
Set<T>::Set()
    : root_(NULL)
{
}

template <typename T>
Set<T>::Set(const Set<T>& rhv)
    : root_(NULL)
{
    copySet(rhv.root_);
}

template <typename T>
template <typename InputIterator>
Set<T>::Set(InputIterator first, InputIterator last)
    : root_(NULL)
{
    while (first != last) {
        insert(*first);
        ++first;
    }
}

template <typename T>
Set<T>::~Set()
{
    clear();
}

template <typename T>
const Set<T>&
Set<T>::operator=(const Set<T>& rhv)
{
    if (this == &rhv) return *this;
    clear();
    copySet(rhv.root_);
    return *this;
}

template <typename T>
void
Set<T>::swap(Set<T>& rhv)
{
    Set<T>::Node* tempRoot = root_;

    root_ = rhv.root_;

    rhv.root_ = tempRoot;
}

template <typename T>
typename Set<T>::size_type
Set<T>::size() const
{
    int result = 0;
    size(root_, result);
    return result;
}

template <typename T>
bool
Set<T>::empty() const
{
    return root_ == NULL;
}

template <typename T>
void
Set<T>::clear()
{
    clear(root_);
    root_ = NULL;
}

template <typename T>
typename Set<T>::template Pair<typename Set<T>::iterator, bool>
Set<T>::insert(const_reference value)
{
    Node** ptr = &root_;
    Node* parent = NULL;

    while (*ptr != NULL) {
        parent = *ptr;
        if (value < (*ptr)->data_) {
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

template <typename T>
typename Set<T>::iterator 
Set<T>::insert(iterator pos, const_reference value)
{
    if (empty()) return insert(*pos).first_;
    goUp(pos, value);
    goDownInsert(pos, value);
    balance(pos);
    return pos;
}

template <typename T>
template <typename InputIterator>
void 
Set<T>::insert(iterator pos, InputIterator first, InputIterator last)
{
    while (first != last) {
        insert(pos, *first);
        ++first;
    }
}

template <typename T>
typename Set<T>::iterator 
Set<T>::erase(iterator pos)
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

template <typename T>
typename Set<T>::size_type 
Set<T>::erase(const key_type& value)
{
    size_type count = 0;
    iterator target = find(value);
    if (target == NULL) return count;
    ++count;
    erase(target);
    return count;
}

template <typename T>
typename Set<T>::iterator 
Set<T>::erase(iterator first, iterator last)
{
    assert(!empty());

    while (first != last) {
        erase(first++);
    }
    return last;
}

template <typename T>
typename Set<T>::iterator 
Set<T>::find(const key_type& k) const
{
    Node* target = root_;
    while (target != NULL && target->data_ != k) {
        if (k < target->data_) {
            target = target->left_;
        } else {
            target = target->right_;
        }
    }
    return target;
}

template <typename T>
typename Set<T>::size_type 
Set<T>::count(const key_type& k) const
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

template <typename T>
typename Set<T>::iterator 
Set<T>::lower_bound(const key_type& k) const
{
    const_iterator first = begin();
    const_iterator last = end();
    while (first != last) {
        if (!(*first < k)) return first;
        ++first;
    }
    return last;
}

template <typename T>
typename Set<T>::iterator 
Set<T>::upper_bound(const  key_type& k) const
{
    const_iterator first = begin();
    const_iterator last = end();
    while (first != last) {
        if (*first > k) return first;
        ++first;
    }
    return last;
}

template <typename T>
typename Set<T>::template Pair<typename Set<T>::iterator, typename Set<T>::iterator>
Set<T>::equal_range(const key_type& k) const
{
    return Pair<iterator, iterator>(lower_bound(k), upper_bound(k));
}

template <typename T>
bool
Set<T>::operator==(const Set<T>& rhv) const
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

template <typename T>
bool
Set<T>::operator!=(const Set<T>& rhv) const
{
    return !(*this == rhv);
}

template <typename T>
bool
Set<T>::operator<(const Set<T>& rhv) const
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

template <typename T>
bool
Set<T>::operator>(const Set<T>& rhv) const
{
    return rhv < *this;
}

template <typename T>
bool
Set<T>::operator<=(const Set<T>& rhv) const
{
    return !(*this > rhv);
}

template <typename T>
bool
Set<T>::operator>=(const Set<T>& rhv) const
{
    return !(*this < rhv);
}

template <typename T>
void
Set<T>::print() const
{
    print(root_);
}

template <typename T>
typename Set<T>::iterator
Set<T>::begin()
{
    return topLeft(root_);
}

template <typename T>
typename Set<T>::iterator
Set<T>::end()
{
    return NULL;
}

template <typename T>
typename Set<T>::const_iterator
Set<T>::begin() const
{
    return topLeft(root_);
}

template <typename T>
typename Set<T>::const_iterator
Set<T>::end() const
{
    return NULL;
}

template <typename T>
typename Set<T>::reverse_iterator
Set<T>::rbegin()
{
    return topRight(root_);
}

template <typename T>
typename Set<T>::reverse_iterator
Set<T>::rend()
{
    return NULL;
}

template <typename T>
typename Set<T>::const_reverse_iterator
Set<T>::rbegin() const
{
    return topRight(root_);
}

template <typename T>
typename Set<T>::const_reverse_iterator
Set<T>::rend() const
{
    return NULL;
}


///Set::private functions

template <typename T> 
void
Set<T>::copySet(const Node* ptr)
{
    if (ptr != NULL) {
        insert(ptr->data_);
        copySet(ptr->left_);
        copySet(ptr->right_);
    }
}

template <typename T> 
void 
Set<T>::size(const Node* ptr, int& result) const
{
    if (ptr != NULL) {
        size(ptr->left_, result);
        ++result;
        size(ptr->right_, result);
    }
}

template <typename T>
void
Set<T>::clear(Node* ptr)
{
    if (ptr != NULL) {
        clear(ptr->left_);
        clear(ptr->right_);
        delete ptr;
    }
}

template <typename T>
typename Set<T>::Node* 
Set<T>::topLeft(Node* ptr) const
{
    if (ptr == NULL) return ptr;
    while (ptr->left_ != NULL) {
        ptr = ptr->left_;
    }
    return ptr;
}

template <typename T>
typename Set<T>::Node* 
Set<T>::topRight(Node* ptr) const
{
    if (ptr == NULL) return ptr;
    while (ptr->right_ != NULL) {
        ptr = ptr->right_;
    }
    return ptr;
}

template <typename T>
void
Set<T>::goUp(const_iterator& pos, const_reference value) const
{
    if (*pos > value) {
        const_iterator parent = pos.leftParent(pos); 
        while (parent != NULL && *parent > value) {
            pos = parent;
            parent = pos.leftParent(pos);
        }
    }
    if (*pos < value) {
        const_iterator parent = pos.rightParent(pos); 
        while (parent != NULL && *parent < value) {
            pos = parent;
            parent = pos.rightParent(pos);
        }
    }
}

template <typename T>
void
Set<T>::goDownInsert(iterator& pos, const_reference value)
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

template <typename T>
void 
Set<T>::balance(iterator it)
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

template <typename T>
int
Set<T>::getDiff(iterator it) const
{
    return depth(it.getPtr()->left_) - depth(it.getPtr()->right_);
}

template <typename T> 
int 
Set<T>::depth(const Node* ptr) const
{
    int result = 0;
    depth(ptr, result);
    return result;
}

template <typename T> 
void 
Set<T>::depth(const Node* ptr, int& result, const int counter) const
{
    if (ptr != NULL) {
        if (result <= counter) result = counter + 1;
        depth(ptr->left_, result, counter + 1);
        depth(ptr->right_, result, counter + 1);
    }
}

template <typename T>
void 
Set<T>::rotateLeft(iterator& it)
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

template <typename T>
void 
Set<T>::rotateRight(iterator& it)
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

template <typename T>
void
Set<T>::print(const Node* ptr, const int spaces) const
{
    if (ptr != NULL) {
        print(ptr->right_, spaces + 5);
        for (int i = 0; i < spaces; ++i) std::cout << ' ';
        std::cout << ptr->data_ << ' ';
        print(ptr->left_, spaces + 5);
    }
    std::cout << std::endl;
}


///const_iterator

template <typename T>
Set<T>::const_iterator::const_iterator()
    : ptr_(NULL)
{
}

template <typename T>
Set<T>::const_iterator::const_iterator(const const_iterator& rhv)
    : ptr_(rhv.ptr_)
{
}

template <typename T>
Set<T>::const_iterator::~const_iterator()
{
    ptr_ = NULL;
}

template <typename T>
const typename Set<T>::const_iterator&
Set<T>::const_iterator::operator=(const const_iterator& rhv)
{
    if (this == &rhv) return *this;
    ptr_ = rhv.ptr_;
    return *this;
}

template <typename T>
typename Set<T>::const_reference
Set<T>::const_iterator::operator*() const
{
    return ptr_->data_;
}

template <typename T>
const typename Set<T>::Node*
Set<T>::const_iterator::operator->() const
{
    return ptr_;
}

template <typename T>
const typename Set<T>::const_iterator&
Set<T>::const_iterator::operator++()
{
    assert(ptr_ != NULL);

    *this = nextInOrder(*this);
    return *this; 
}

template <typename T>
const typename Set<T>::const_iterator&
Set<T>::const_iterator::operator--()
{
    assert(ptr_ != NULL);

    *this = prevInOrder(*this);
    return *this; 
}

template <typename T>
const typename Set<T>::const_iterator
Set<T>::const_iterator::operator++(int)
{
    assert(ptr_ != NULL);

    const const_iterator temp = ptr_;
    *this = nextInOrder(*this);
    return temp; 
}

template <typename T>
const typename Set<T>::const_iterator
Set<T>::const_iterator::operator--(int)
{
    assert(ptr_ != NULL);

    const const_iterator temp = ptr_;
    *this = prevInOrder(*this);
    return temp; 
}

template <typename T>
typename Set<T>::const_iterator
Set<T>::const_iterator::nextInOrder(const_iterator it)
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

template <typename T>
typename Set<T>::const_iterator
Set<T>::const_iterator::rightParent(const_iterator it)
{
    Node* parent = it.ptr_->parent_;
    while (parent != NULL && parent->right_ == it.ptr_) {
        it.ptr_ = parent;
        parent = parent->parent_;
    }
    return parent;
}

template <typename T>
typename Set<T>::const_iterator
Set<T>::const_iterator::prevInOrder(const_iterator it)
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

template <typename T>
typename Set<T>::const_iterator
Set<T>::const_iterator::leftParent(const_iterator it)
{
    Node* parent = it.ptr_->parent_;
    while (parent != NULL && parent->left_ == it.ptr_) {
        it.ptr_ = parent;
        parent = parent->parent_;
    }
    return parent;
}

template <typename T>
bool
Set<T>::const_iterator::operator==(const const_iterator& rhv) const
{
    return ptr_ == rhv.ptr_;
}

template <typename T>
bool
Set<T>::const_iterator::operator!=(const const_iterator& rhv) const
{
    return !(*this == rhv);
}

template <typename T>
Set<T>::const_iterator::const_iterator(Node* valuePtr)
    : ptr_(valuePtr)
{
}

template <typename T>
typename Set<T>::Node*
Set<T>::const_iterator::getPtr() const
{
    return ptr_;
}


///iterator

template <typename T>
Set<T>::iterator::iterator()
    : const_iterator()
{
}

template <typename T>
typename Set<T>::reference
Set<T>::iterator::operator*()
{
    return const_iterator::getPtr()->data_;
}

template <typename T>
typename Set<T>::Node*
Set<T>::iterator::operator->()
{
    return const_iterator::getPtr();
}

template <typename T>
Set<T>::iterator::iterator(Node* valuePtr)
    : const_iterator(valuePtr)
{
}


///const_reverse_iterator

template <typename T>
Set<T>::const_reverse_iterator::const_reverse_iterator()
    : ptr_(NULL)
{
}

template <typename T>
Set<T>::const_reverse_iterator::const_reverse_iterator(const const_reverse_iterator& rhv)
    : ptr_(rhv.ptr_)
{
}

template <typename T>
Set<T>::const_reverse_iterator::~const_reverse_iterator()
{
    ptr_ = NULL;
}

template <typename T>
const typename Set<T>::const_reverse_iterator&
Set<T>::const_reverse_iterator::operator=(const const_reverse_iterator& rhv)
{
    if (this == &rhv) return *this;
    ptr_ = rhv.ptr_;
    return *this;
}

template <typename T>
typename Set<T>::const_reference
Set<T>::const_reverse_iterator::operator*() const
{
    return ptr_->data_;
}

template <typename T>
const typename Set<T>::Node*
Set<T>::const_reverse_iterator::operator->() const
{
    return ptr_;
}

template <typename T>
const typename Set<T>::const_reverse_iterator&
Set<T>::const_reverse_iterator::operator++()
{
    assert(ptr_ != NULL);

    *this = nextInOrder(*this);
    return *this; 
}

template <typename T>
const typename Set<T>::const_reverse_iterator&
Set<T>::const_reverse_iterator::operator--()
{
    assert(ptr_ != NULL);

    *this = prevInOrder(*this);
    return *this; 
}

template <typename T>
const typename Set<T>::const_reverse_iterator
Set<T>::const_reverse_iterator::operator++(int)
{
    assert(ptr_ != NULL);

    const const_reverse_iterator temp = ptr_;
    *this = nextInOrder(*this);
    return temp; 
}

template <typename T>
const typename Set<T>::const_reverse_iterator
Set<T>::const_reverse_iterator::operator--(int)
{
    assert(ptr_ != NULL);

    const const_reverse_iterator temp = ptr_;
    *this = prevInOrder(*this);
    return temp; 
}

template <typename T>
typename Set<T>::const_reverse_iterator
Set<T>::const_reverse_iterator::nextInOrder(const_reverse_iterator it)
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

template <typename T>
typename Set<T>::const_reverse_iterator
Set<T>::const_reverse_iterator::prevInOrder(const_reverse_iterator it)
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

template <typename T>
bool
Set<T>::const_reverse_iterator::operator==(const const_reverse_iterator& rhv) const
{
    return ptr_ == rhv.ptr_;
}

template <typename T>
bool
Set<T>::const_reverse_iterator::operator!=(const const_reverse_iterator& rhv) const
{
    return !(*this == rhv);
}

template <typename T>
Set<T>::const_reverse_iterator::const_reverse_iterator(Node* valuePtr)
    : ptr_(valuePtr)
{
}

template <typename T>
typename Set<T>::Node*
Set<T>::const_reverse_iterator::getPtr() const
{
    return ptr_;
}


///reverse_iterator

template <typename T>
Set<T>::reverse_iterator::reverse_iterator()
    : const_reverse_iterator()
{
}

template <typename T>
typename Set<T>::reference
Set<T>::reverse_iterator::operator*()
{
    return const_reverse_iterator::getPtr()->data_;
}

template <typename T>
typename Set<T>::Node*
Set<T>::reverse_iterator::operator->()
{
    return const_reverse_iterator::getPtr();
}

template <typename T>
Set<T>::reverse_iterator::reverse_iterator(Node* valuePtr)
    : const_reverse_iterator(valuePtr)
{
}


///traversals

template <typename T>
void 
Set<T>::preOrder() const
{
    preOrder(root_);
    std::cout << std::endl;
}

template <typename T>
void 
Set<T>::preOrder(const Node* ptr) const
{
    if (ptr != NULL) {
        std::cout << ptr->data_ << ' ';
        preOrder(ptr->left_);
        preOrder(ptr->right_);
    }
}

template <typename T>
void 
Set<T>::inOrder() const
{
    inOrder(root_);
    std::cout << std::endl;
}

template <typename T>
void 
Set<T>::inOrder(const Node* ptr) const
{
    if (ptr != NULL) {
        inOrder(ptr->left_);
        std::cout << ptr->data_ << ' ';
        inOrder(ptr->right_);
    }
}

template <typename T>
void 
Set<T>::postOrder() const
{
    postOrder(root_);
    std::cout << std::endl;
}

template <typename T>
void 
Set<T>::postOrder(const Node* ptr) const
{
    if (ptr != NULL) {
        postOrder(ptr->left_);
        postOrder(ptr->right_);
        std::cout << ptr->data_ << ' ';
    }
}

template <typename T>
void 
Set<T>::preOrderIterative() const
{
    if (empty()) return;

    const Node* pre = root_;
    const Node* prev = NULL;
    const Node* next = NULL;

    while (pre != NULL) {
        if (prev == pre->parent_) {
            std::cout << pre->data_ << ' ';
            if (pre->left_ != NULL) {
                next = pre->left_;
            } else if (pre->right_ != NULL) {
                next = pre->right_;
            } else {
                next = pre->parent_;
            }
        } else if (prev == pre->left_) {
            next = (pre->right_ != NULL) ? pre->right_ : pre->parent_;
        } else if (prev == pre->right_) {
            next = pre->parent_;
        }

        prev = pre;
        pre = next;
    }
    std::cout << std::endl;
}

template <typename T>
void 
Set<T>::inOrderIterative() const
{
    if (empty()) return;

    const Node* in = root_;

    while (in->left_ != NULL) {
        in = in->left_;
    }
    while (in != NULL) {
    std::cout << in->data_ << ' ';
        if (in->right_ != NULL) {
            in = in->right_;
            while (in->left_ != NULL) {
                in = in->left_;
            }
        } else {
            const Node* parent = in->parent_;
            while (parent != NULL && parent->right_ == in) {
                in = parent;
                parent = parent->parent_;
            }
            in = parent;
        }
    }
    std::cout << std::endl;
}

template <typename T>
void 
Set<T>::postOrderIterative() const
{
    if (empty()) return;

    const Node* post = root_;
    const Node* prev = NULL;

    while (post->left_ != NULL) {
        post = post->left_;
    }
    while (post != NULL) {
        if (post->right_ != NULL && prev != post->right_) {
            post = post->right_;
            while (post->left_ != NULL) {
                post = post->left_;
            }
            continue;
        } 
        std::cout << post->data_ << ' ';
        prev = post;
        post = post->parent_;
    }
    std::cout << std::endl;
}

