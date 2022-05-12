#include <iostream>
#include <string>
using namespace std;
template <typename T>
class SmartPointer {
private:
    T* a;
public:
    SmartPointer(T* pa)
    {
        a = pa;
    }
    T& operator*(SmartPointer& a)
    {
        T result = *a;
        return result;
    }
    ~SmartPointer()
        {
            delete a;
        }
};
template <typename F,typename S>
class Pair{
    private:
        F first;
        S second;
    public:
        Pair(F a,S b)
        {
            first = a;
            second = b;
        }
    };
