#include <stdio.h>
#include <string.h>
#include <iostream>

const size_t next_pow_of_two(size_t &v)
{
    size_t i = 1;
    while (i < v)
    {
        i *= 2;
    }
    return i;
}

class String
{
private:
    size_t _len;
    size_t _cap;

public:
    char *_data;

    String() : _len(0), _cap(0), _data(nullptr) {}
    String(const char *s) : _len(0), _cap(0), _data(nullptr)
    {
        size_t new_len = strlen(s);
        resize(new_len);
        memcpy(_data, s, new_len * sizeof(char));
    }

    void resize(size_t new_len)
    {
        if (new_len < _cap)
        {
            _len = new_len;
            return;
        }
        size_t new_cap = next_pow_of_two(new_len);
        char *new_data = new char[new_cap + 1];
        memcpy(new_data, _data, _len);
        new_data[new_len] = 0;
        delete _data;
        _data = new_data;
        _cap = new_cap;
        _len = new_len;
    }
};

std::ostream &operator<<(std::ostream &s, String &str)
{
    s << str._data;
    return s;
}

int main()
{
    String s("HELLO!");
    std::cout << s;

    // printf("HELLO");
    // return 0;
}