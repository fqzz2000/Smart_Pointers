#include <iostream>

template <typename T>
class AutoPtr
{
public:
    // constructor
    AutoPtr(T *ptr = nullptr) : _ptr(ptr) {}
    // destructor
    ~AutoPtr()
    {
        if (_ptr != nullptr)
        {
            delete _ptr;
            _ptr = nullptr;
        }
    }
    // copy constructor
    AutoPtr(AutoPtr &rhs) : _ptr(nullptr)
    {
        std::swap(_ptr, rhs._ptr);
    }
    // assignment operator
    AutoPtr &operator=(AutoPtr &rhs)
    {
        if (_ptr != nullptr)
        {
            delete _ptr;
            _ptr = nullptr;
        }
        std::swap(_ptr, rhs._ptr);
    }
    // move constructor
    AutoPtr(AutoPtr &&rhs) : _ptr(std::move(rhs._ptr))
    {
        rhs._ptr = nullptr;
    }

    // dereference
    T &operator*() const
    {
        return *_ptr;
    }
    T *operator->() const
    {
        return _ptr;
    }

private:
    T *_ptr;
};