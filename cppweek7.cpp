#include <iostream>
#include <string>
using namespace std;

class MyString {
    char* str ;
    int size ;
public: // 생성자
    MyString(const char* const s="") { //  문자열을 받아서 객체를 초기화합니다. 디폴트 인자로 빈 문자열을 사용하므로, 문자열을 전달하지 않으면 빈 문자열로 초기화됩니다.
        set(s);
    }
    MyString(const MyString& myString) {// 다른 MyString 객체를 받아서 그 객체의 내용을 복사하여 객체를 초기화합니다.
        set(myString.str);
    }
    ~MyString() { // 소멸. 객체가 소멸될 때 호출되는 함수입니다. 동적으로 할당된 메모리를 해제하기 위해 사용됩니다.
        delete [] str;
    }

    void set(const char* const s) { // 문자열을 받아서 객체를 설정
        size = strlen(s);
        str = new char[size+1];
        strcpy(str, s);
    }

    void print()const{
        for(int i = 0; str[i] != '\0'; i++){
            cout << str[i];
        }
        cout << endl;
    }

    bool isEqual(const MyString& target)const  {
        for(int i=0; i<strlen(target.str)+1 ; i++){
            if( target.str[i] != str[i] ){
                return false;
            }
        }
        return true;
    }

} ;

int main() {
    MyString strs[] = {
            MyString("C"),
            MyString(),
            MyString("Java")
    } ;
    strs[1].set("C++") ;

    const int arraySize = sizeof(strs) / sizeof(MyString);

    const MyString target("Java") ;
    for ( int i = 0 ; i < arraySize ; i ++ ) {
        const MyString str(strs[i]) ; // copy constructor
        if ( str.isEqual(target) ) {
            cout << "[" << i << "]: " ;
            str.print() ;
            break ;
        }
    }
    for ( const MyString& str : strs ) {
        str.print() ;
    }
}

