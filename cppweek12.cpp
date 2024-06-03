#include <string.h>
#include <iostream>

using namespace std;

class Complex {
private:
    float real, imaginary;

public:
    Complex(const float _real = 0.0F, const float _imaginary = 0.0F) : real(_real), imaginary(_imaginary) {}

    bool operator==(const Complex& c) const {
        return (real == c.real) && (imaginary == c.imaginary);
    }

    friend ostream& operator<<(ostream& os, const Complex& c);
};

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real << " + " << c.imaginary << "i";
    return os;
}

class MyString {
private:
    char* str;
public:
    MyString(const char* _str = "") : str(new char[strlen(_str) + 1]) {
        strcpy_s(str, strlen(_str) + 1, _str);
    }
    MyString(const MyString& s) : str(new char[strlen(s.str) + 1]) {
        strcpy_s(str, strlen(s.str) + 1, s.str);
    }
    MyString& operator=(const MyString& s) {
        if (this != &s) {
            delete[] str;
            str = new char[strlen(s.str) + 1];
            strcpy_s(str, strlen(s.str) + 1, s.str);
        }
        return *this;
    }
    ~MyString() {
        delete[] str;
    }
    bool operator==(const MyString& s) const {
        return strcmp(str, s.str) == 0;
    }
    friend ostream& operator<<(ostream& os, const MyString& s);
};

ostream& operator<<(ostream& os, const MyString& s) {
    os << s.str;
    return os;
}

template <class T>
class List {
private:
    T* items;
    int count;
    int size;
public:
    List(const int size) {
        items = new T[size];
        this->size = size;
        this->count = 0;
    }
    List(const List& list) : items(new T[list.size]), size(list.size), count(list.count) {
        for (int i = 0; i < list.count; ++i) {
            items[i] = list.items[i];
        }
    }
    ~List() {
        delete[] items;
    }
    List& operator=(const List& list) {
        if (this != &list) {
            delete[] items;

            items = new T[list.size];
            size = list.size;
            count = list.count;

            for (int i = 0; i < list.count; ++i) {
                items[i] = list.items[i];
            }
        }
        return *this;
    }

    void add(const T& item) {
        if (count < size) {
            items[count] = item;
            count++;
        }
        else {
            std::cerr << "List is full, cannot add more items." << std::endl;
        }
    }
    bool find(const T& item) const {
        for (int i = 0; i < count; ++i) {
            if (items[i] == item) {
                return true;
            }
        }
        return false;
    }
    T* getItems() const { return items; }
    int getCount() const { return count; }
};

template <class T>
ostream& operator<<(ostream& os, const List<T>& list) {
    for (int i = 0; i < list.getCount(); ++i) {
        os << list.getItems()[i] << std::endl;
    }
    return os;
}

int main() {
    List<Complex> cList(100);

    cList.add(Complex(0, 0));
    cList.add(Complex(1, 1));
    cout << cList;


    cout << std::boolalpha;
    cout << cList.find(Complex(1, 1)) << endl;	// true
    cout << cList.find(Complex(1, 0)) << endl;	// false

    List<MyString> sList(200);

    sList.add("abc");
    sList.add("def");
    cout << sList;
    cout << sList.find("def") << endl;	// true
    cout << sList.find("Aef") << endl;	// false

    List<MyString> s2List(sList);
    s2List.add("ghi");
    cout << s2List;

    List<MyString> s3List(10);
    s3List = s2List;
    s3List.add("jkl");
    cout << s3List;
};

