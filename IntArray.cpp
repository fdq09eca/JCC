#include <iostream>
#define TEST(EXPR)                                                                  \
    do                                                                              \
    {                                                                               \
        printf("[%s] Line %3d: %s\n", ((EXPR) ? " OK " : "FAIL"), __LINE__, #EXPR); \
    } while (0) //-------------------

#define dump_var(X)                        \
    do                                     \
    {                                      \
        std::cout << #X ": " << X << "\n"; \
    } while (false)
//=====
size_t next_pow_of_two(const size_t v)
{
    size_t i = 1;
    while (i < v)
    {
        i *= 2;
    }
    return i;
}

class IntArray
{
private:
    size_t _size;
    int *_data;
    size_t _cap;

public:
    IntArray() : _size(0), _data(nullptr), _cap(0){};
    IntArray(int *data_, size_t size) : _size(0), _data(nullptr), _cap(0)
    {
        append(data_, size);
    };

    IntArray(const IntArray &arr) : _size(0), _data(nullptr), _cap(0)
    {
        *this = arr;
    }

    void operator=(const IntArray &arr)
    {
        clear();
        append(arr._data, arr._size);
    }

    ~IntArray()
    {
        clear();
    }

    void clear()
    {
        delete[] _data;
        _data = nullptr;
        _size = 0;
        _cap = 0;
    }

    const size_t &size() const { return _size; }
    const int *data() const { return _data; }

    void reserve(const size_t request_len)
    {
        if (request_len < _cap)
            return;
        size_t new_cap = next_pow_of_two(request_len);
        int *new_data = new int[new_cap];
        memcpy(new_data, _data, _size * sizeof(int));
        delete[] _data;
        _data = new_data;
        _cap = new_cap;
    }

    void resize(const size_t new_size)
    {
        reserve(new_size);
        _size = new_size;
    }

    IntArray &append(const int v)
    {
        resize(_size + 1);
        _data[_size] = v;
        return *this;
    }

    IntArray &append(const int *arr, size_t arr_size)
    {
        if (!arr)
            return;
        size_t old_size = _size;
        size_t new_size = arr_size + old_size;
        resize(new_size);
        memcpy(_data + old_size, arr, arr_size * sizeof(int));
        return *this;
    }

    void del_idx(size_t idx)
    {
        if (idx >= _size)
            return;
        int *dst = _data + idx;
        int *src = dst + 1;
        size_t mv_elements = _size - idx - 1;
        memmove(dst, src, mv_elements * sizeof(int));
        resize(_size - 1);
    }

    void del(int v)
    {
        int *p = find(v);
        if (!p)
            return;
        size_t idx = p - _data;
        del_idx(idx);
    }

    size_t min_idx(const size_t from_idx = 0) const
    {
        if (_size == 0)
            throw std::runtime_error("_size == 0\n");
        if (from_idx >= _size)
            throw std::runtime_error("from_idx out of range\n");
        int min = _data[from_idx];
        size_t min_idx = from_idx;
        for (int i = from_idx; i < _size; i++)
        {
            if (_data[i] < min)
            {
                min = _data[i];
                min_idx = i;
            }
        }
        return min_idx;
    }

    int min(const size_t from_idx = 0) const
    {
        return _data[min_idx(from_idx)];
    }

    void swap_position(const size_t idx_i, const size_t idx_j)
    {
        int tmp = _data[idx_i];
        _data[idx_i] = _data[idx_j];
        _data[idx_j] = tmp;
    }

    size_t count(const int v, const size_t from_idx = 0) const
    {
        size_t c = 0;
        for (size_t i = from_idx; i < _size; i++)
        {
            if (_data[i] == v)
            {
                c++;
            }
        }
        return c;
    }

    void sort()
    {
        for (size_t i = 0; i < _size; i++)
        {
            swap_position(i, min_idx(i));
        }
    }

    void reverse()
    {
        size_t i = 0;
        size_t j = _size - 1;
        for (size_t n = 0; n < j / 2; i++, j--)
        {
            swap_position(i, j);
        }
    }

    int *find(int v)
    {
        int *p = _data;
        int *end = p + _size;
        for (; p < end; p++)
        {
            if (*p == v)
            {
                return p;
            }
        }
        return nullptr;
    }

    int *binary_search(int v)
    {
        size_t start = 0;
        size_t end = _size;
        while (start < end)
        {
            size_t middle = (start + end) / 2;
            int m = _data[middle];

            if (v < m)
            {
                end = middle - 1;
                continue;
            }
            if (v > m)
            {
                start = middle + 1;
                continue;
            }
            return _data + middle;
        }
        return nullptr;
    }

    int &operator[](size_t idx)
    {
        if (idx >= _size)
        {
            throw std::runtime_error("out of range.");
        }
        return _data[idx];
    }
};

std::ostream &operator<<(std::ostream &s, IntArray &arr)
{
    size_t len = arr.size();
    size_t max_idx = len - 1;
    s << "[";
    for (size_t i = 0; i < len; i++)
    {
        s << arr[i];
        if (i < max_idx)
        {
            s << ", ";
        }
    }
    s << "]\n";
    return s;
};

int main()
{
    int arr[3] = {1, 2, 3};

    IntArray a(arr, 3);
    dump_var(a);
    TEST(a.size() == 3);

    IntArray arr2 = a;
    dump_var(arr2);
    a.append(arr2.data(), 3);

    dump_var(a);
    TEST(a[3] == 1);
    TEST(a.min() == 1);
    TEST(a.min(1) == 1);
    TEST(a.min(2) == 1);
    TEST(a.min(3) == 1);
    TEST(a.min(4) == 2);
    dump_var(a.min(4));
    TEST(a.min(5) == 3);
    dump_var(a.min(5));
    a.swap_position(0, 1);
    TEST(a[0] == 2);
    TEST(a[1] == 1);
    a.swap_position(0, 1);
    TEST(a[0] == 1);
    TEST(a[1] == 2);
    TEST(a.find(0) == nullptr);
    TEST(a.find(1) == a.data());
    TEST(a.find(2) == a.data() + 1);
    TEST(a.find(3) == a.data() + 2);
    TEST(a.count(1) == 2);
    TEST(a.count(2) == 2);
    TEST(a.count(3) == 2);
    TEST(a.count(4) == 0);
    TEST(a.count(5) == 0);
    TEST(a.count(6) == 0);

    a.sort();
    TEST(a.binary_search(1) != nullptr);
    TEST(a.binary_search(2) != nullptr);
    TEST(a.binary_search(3) != nullptr);
    TEST(a.binary_search(4) == nullptr);
    TEST(a.binary_search(5) == nullptr);
    TEST(a.binary_search(6) == nullptr);
    dump_var(a);
    std::cout << "reverse\n";
    a.reverse();
    dump_var(a);
    a.del(0);
    dump_var(a);
    a.del(1);
    dump_var(a);
    a.del(2);
    dump_var(a);
    a.del(3);
    dump_var(a);
    std::cout << "reverse\n";
    a.reverse();
    dump_var(a);

    a.del(1);
    a.del(2);
    a.del(3);
    dump_var(a);
    a.del(1);
    a.del(2);
    a.del(3);
    dump_var(a.size());

    return 0;
}