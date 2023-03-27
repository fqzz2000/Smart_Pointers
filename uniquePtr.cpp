#include <iostream>
template <typename T>
class UniquePtr
{
public:
    UniquePtr(T *ptr = nullptr) : _ptr(ptr) {}
    // copy constructor
    // move constructor
    UniquePtr(UniquePtr &&rhs) : _ptr(nullptr)
    {
        if (rhs._ptr != nullptr)
        {
            UniquePtr tmp(rhs);
            std::swap(_ptr, tmp._ptr);
        }
    }
    // destructor
    ~UniquePtr()
    {
        std::cout << "destroyed" << std::endl;
        if (_ptr != nullptr)
        {
            delete _ptr;
            _ptr = nullptr;
        }
    }
    // assignment operator

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
    UniquePtr &operator=(const UniquePtr &rhs);
    UniquePtr(const UniquePtr &rhs);

private:
    T *_ptr;
};

int main()
{
    UniquePtr<int> sp1(new int(10));
    UniquePtr<int> sp2(new int(20));
    // UniquePtr<int> sp3(sp1); // 错误
    // sp1 = sp2; // 错误

    return 0;
}