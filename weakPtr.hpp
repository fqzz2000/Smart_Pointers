#ifndef WEAK_PTR_HPP
#define WEAK_PTR_HPP
#include <iostream>
#include <sharedPtr.hpp>
template <typename T>
class WeakPtr
{
public:
    WeakPtr(SharedPtr<T> &ptr) : _ptr(rhs._ptr) {}
    ~WeakPtr() {}
    WeakPtr(const WeakPtr &rhs) : _ptr(rhs._ptr) {}
    WeakPtr &operator=(const WeakPtr &rhs)
    {
        if (&rhs != this)
        {
            _ptr = rhs._ptr;
        }
        return *this;
    }
    WeakPtr(WeakPtr &&rhs) : _ptr(std::move(rhs._ptr)) {}

private:
    WeakPtr();
    friend class SharedPtr;

private:
    T *_ptr;
};
#endif