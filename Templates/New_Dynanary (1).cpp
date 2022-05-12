template <typename T>
struct Dynarray
{
private:
    size_t size;
    size_t capacity;
    T* values;

public:
    typedef T* iterator;

    Dynarray(size_t init_cap) 
    {
        if (init_cap < 0)
        {
            std::cout << "Error: initial capacity is negative \n";
            exit(1);
        }
        size = 0;
        capacity = init_cap;
        values = new T[capacity];
    }

    Dynarray() : Dynarray(0)
    {
    }

    Dynarray(std::initializer_list<T> dyn)
    {
        size = dyn.size();
        capacity = size;
        values = new T[capacity];
        std::copy(dyn.begin(), dyn.end(), values);
    }
 
    void push_back(T x) 
    {
        if (size >= capacity)
        {
            if (capacity == 0)
                capacity = 1;
            else
                capacity *= 2;

            T* temp = new T[capacity];
            std::copy_n(values, size, temp);
            delete[] values;
            values = temp;
        }
        values[size] = x;
        size += 1;
    }

    void erase(size_t numb)
    {
        if (numb < 0 || numb >= size)
        {
            std::cout << "Error while erasing element from Dynarray! Index is out of range\n";
            exit(1);
        }
        if (size == 0)
        {
            std::cout << "Error while erasing element from Dynarray! Dynarray is empty\n";
            exit(1);
        }
        for (size_t i = numb; i < size - 1; i++)
            values[i] = values[i + 1];
        size--;
    }

    T& at(size_t numb) 
    {
        if (numb < 0 || numb >= size)
        {
            std::cout << "Error: index has wrong value"
            std::exit(1);
        }
        return values[numb];
    }

    int is_empty() const
    {
        return (size == 0);
    }

    size_t get_size() const
    {
        return size;
    }

    size_t get_capacity() const
    {
        return capacity;
    }
    T& operator[](size_t numb) 
    {
        return values[numb];
    }
    Dynarray& operator=(const Dynarray& a)
    {
        if (&a == this)
            return *this;
        size = a.size;
        capacity = a.capacity;
        delete[] values;
        values = new T[capacity];
        for (size_t i = 0; i < size; i++)
            values[i] =a.values[i];
        return *this;
    }
    iterator begin()
    {
        return &values[0];
    }

    iterator end()
    {
        return &values[size];
    }
    ~Dynarray() 
    {
        delete[] values;
    }
};
