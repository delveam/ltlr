#pragma once

#include "common.h"

typedef struct
{
    // A pointer to the Deque's internal data (which acts as a circular buffer).
    void* m_data;
    // The size of a single element in bytes.
    usize m_dataSize;
    // The maximum number of elements that the deque can hold.
    usize m_capacity;
    // The next index to insert into the front of the deque.
    usize m_headIndex;
    // The next index to insert into the back of the deque.
    usize m_tailIndex;
    // True if the Deque's internal array is full.
    bool m_needsResize;
} Deque;

Deque DequeCreate(const usize initialCapacity, const usize dataSize);
void DequePushFront(Deque* self, const void* value);
void DequePushBack(Deque* self, const void* value);
void* DequePopFront(Deque* self);
void* DequePopBack(Deque* self);
void* DequePeekFront(const Deque* self);
void* DequePeekBack(const Deque* self);
void* DequeGetUnchecked(const Deque* self, const usize index);
void DequeSetUnchecked(Deque* self, const usize index, void* value);
usize DequeGetSize(const Deque* self);
void DequeClear(Deque* self);
void DequeDestroy(Deque* self);
