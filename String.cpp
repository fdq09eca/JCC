#include <stdio.h>
#include <string.h>
class String{
    char* _data;
    size_t _len;
    size_t cap;

    String(): _data(nullptr), _len(0){}
    
    String(const char* s): _data(nullptr), _len(0){
        _len = strlen(s);
        resize(_len);
        memcpy(_data, s, _len);
    }

    size_t next_pow_of_two(size_t len) {
        size_t i = 1;
        while (i < len) {
            i *= 2;
        }
        return i;
    }

    // void resize(size_t new_len) {
    //     if (new_len < cap) { // ABC cap 4, new_len = 2, len = 3
    //         _len = new_len;
    //         _data[_len] = 0;
    //         return;
    //     }
    //     size_t new_cap = next_pow_of_two(new_len);
    //     char* new_data = new char[new_cap + 1];
    //     memcpy(new_data, _data, sizeof(char)*_len);
    //     delete[] _data;
    //     _data = new_data;
    //     cap = new_cap;
    // }
};

size_t next_pow_of_two(size_t len) {
        size_t i = 1;
        while (i < len) {
            i *= 2;
        }
        return i;
    }

int main(){
    printf("%zu", next_pow_of_two(256));
    return 0;
}