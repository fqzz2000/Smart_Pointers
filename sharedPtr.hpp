#ifndef SHARED_PTR_HPP
#define SHARED_PTR_HPP
#include <iostream>
#include <weakPtr.hpp>
template <typename T>
class SharedPtr
{
public:
    // constructor
    SharedPtr(T *ptr = nullptr) : _count(nullptr), _ptr(ptr)
    {
        if (_ptr != nullptr)
        {
            std::cout << "created" << std::endl;
            _count = new int(1);
        }
        return;
    }
    // copy constructor
    SharedPtr(const SharedPtr &rhs) : _count(rhs._count), _ptr(rhs._ptr)
    {
        if (_count != nullptr)
        {
            ++(*_count);
        }
    }
    // assignment constructor
    SharedPtr &operator=(const SharedPtr &rhs)
    {
        if (&rhs != this)
        {
            SharedPtr tmp(rhs);
            std::swap(_count, tmp._count);
            std::swap(_ptr, tmp._ptr);
        }
        return *this;
    }

    // destructor
    ~SharedPtr()
    {
        if (_count != nullptr && --(*_count) == 0)
        {
            std::cout << "destoryed" << std::endl;
            delete _count;
            delete _ptr;
            _count = nullptr;
            _ptr = nullptr;
        }
        else
        {
            std::cout << "count--" << std::endl;
        }
    }
    // overload dereference
    T &operator*() const
    {
        return *_ptr;
    }
    T *operator->() const
    {
        return _ptr;
    }

private:
    int *_count;
    T *_ptr;
    friend class WeakPtr;
};

int main(int argc, char **argv)
{
    SharedPtr<int> sp1(new int(10));
    SharedPtr<int> sp2(new int(20));
    SharedPtr<int> sp3(new int(30));
    SharedPtr<int> sp4(sp1);
    sp2 = sp1;
    sp3 = sp1;

    return 0;
}

#endif