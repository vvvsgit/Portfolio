#include "headers/List.hpp"
#include "headers/Queue.hpp"

template <typename QUEUETYPE>
inline void 
Queue<QUEUETYPE>::enqueue(const QUEUETYPE& data)
{
    List<QUEUETYPE>::insertAtBack(data);
}

template <typename QUEUETYPE>
inline bool 
Queue<QUEUETYPE>::dequeue(QUEUETYPE& data)
{
    return List<QUEUETYPE>::removeFromFront(data);
}

template <typename QUEUETYPE>
inline bool 
Queue<QUEUETYPE>::isQueueEmpty() const
{
    return List<QUEUETYPE>::isEmpty();
}

template <typename QUEUETYPE>
inline void 
Queue<QUEUETYPE>::printQueue() const
{
    List<QUEUETYPE>::print();
}

