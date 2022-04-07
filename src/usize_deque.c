#include "assert.h"
#include "usize_deque.h"

#define RESIZE_FACTOR 2

static void Resize(UsizeDeque* self)
{
    const usize oldCapacity = self->_capacity;
    usize* oldData = self->_data;

    const usize newCapacity = (usize)(self->_capacity * RESIZE_FACTOR);
    usize* newData = (usize*)malloc(sizeof(usize) * newCapacity);

    self->_data = newData;
    self->_capacity = newCapacity;
    self->_headIndex = 0;
    self->_tailIndex = newCapacity - 1;
    self->fullCapacity = false;

    for (usize i = 0; i < oldCapacity; ++i)
    {
        newData[self->_headIndex] = oldData[i];
        self->_headIndex = (self->_headIndex + 1) % self->_capacity;
    }

    free(oldData);
}

UsizeDeque UsizeDequeCreate(const usize initalCapacity)
{
    usize* data = (usize*)malloc(sizeof(usize) * initalCapacity);

    return (UsizeDeque)
    {
        ._data = data,
        ._capacity = initalCapacity,
        ._headIndex = 0,
        ._tailIndex = initalCapacity - 1,
        .fullCapacity = false,
    };
}

void UsizeDequePushFront(UsizeDeque* self, const usize value)
{
    if (self->fullCapacity)
    {
        Resize(self);
    }
    else if (UsizeDequeSize(self) == self->_capacity - 1)
    {
        self->fullCapacity = true;
    }

    self->_data[self->_headIndex] = value;
    self->_headIndex = (self->_headIndex + 1) % self->_capacity;
}

void UsizeDequePushBack(UsizeDeque* self, const usize value)
{
    if (self->fullCapacity)
    {
        Resize(self);
    }
    else if (UsizeDequeSize(self) == self->_capacity - 1)
    {
        self->fullCapacity = true;
    }

    self->_data[self->_tailIndex] = value;

    if (self->_tailIndex == 0)
    {
        self->_tailIndex = self->_capacity - 1;
    }
    else
    {
        self->_tailIndex -= 1;
    }
}

usize UsizeDequePopFront(UsizeDeque* self)
{
    assert(UsizeDequeSize(self) > 0);

    const usize result = UsizeDequePeekFront(self);

    if (self->_headIndex == 0)
    {
        self->_headIndex = self->_capacity - 1;
    }
    else
    {
        self->_headIndex -= 1;
    }

    return result;
}

usize UsizeDequePopBack(UsizeDeque* self)
{
    assert(UsizeDequeSize(self) > 0);

    const usize result = UsizeDequePeekBack(self);
    self->_tailIndex = (self->_tailIndex + 1) % self->_capacity;
    return result;
}

usize UsizeDequePeekFront(const UsizeDeque* self)
{
    assert(UsizeDequeSize(self) > 0);

    if (self->_headIndex == 0)
    {
        return self->_data[self->_capacity - 1];
    }

    return self->_data[self->_headIndex - 1];
}

usize UsizeDequePeekBack(const UsizeDeque* self)
{
    assert(UsizeDequeSize(self) > 0);

    return self->_data[(self->_tailIndex + 1) % self->_capacity];
}

usize UsizeDequeSize(const UsizeDeque* self)
{
    if (self->fullCapacity)
    {
        return self->_capacity;
    }

    if (self->_headIndex == self->_tailIndex)
    {
        return self->_capacity - 1;
    }

    if (self->_headIndex < self->_tailIndex)
    {
        return self->_headIndex + self->_capacity - self->_tailIndex - 1;
    }

    return self->_headIndex - self->_tailIndex - 1;
}

void UsizeDequeDestroy(UsizeDeque* self)
{
    free(self->_data);
}
