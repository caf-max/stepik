#include <iostream>
#include <string>


class StringPointer {
private:
    std::string* pointer;
    bool internal;
public:
    std::string* operator->() {
        if (!pointer) {
            internal = true;
            pointer = new std::string();
        }
        return pointer;
    }
    std::string& operator*() {
        if (!pointer) {
            internal = true;
            pointer = new std::string();
        }
        return *pointer;
    }
    StringPointer(std::string *Pointer): pointer(Pointer), internal(false) {}
    ~StringPointer() {
        if (internal) {
            delete pointer;
        }
    }
};


int main(int, char**) {
    std::string s1 = "Hello, world!";

    StringPointer sp1(&s1);
    StringPointer sp2(NULL);

    std::cout << sp1->length() << std::endl;
    std::cout << *sp1 << std::endl;
    std::cout << sp2->length() << std::endl;
    std::cout << *sp2 << std::endl;

    return 0;
}
