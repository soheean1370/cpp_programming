#include <iostream>
#include <limits>
#include <string>

using namespace std;

string input;
void convertToLower(string& input);
int main(){
    int cnt_char = 0, cnt_int =0, cnt_long =0, cnt_float=0, cnt_double=0;
    while(true){
        cin >> input;
        convertToLower(input);
        if(input == "char"){
            cout << static_cast<int>(numeric_limits<char>::min()) << "\t" << static_cast<int>(numeric_limits<char>::max()) << endl;
            cnt_char++;
        }
        else if(input == "int"){
            cout << numeric_limits<int>::min() << "\t" << numeric_limits<int>::max()<<endl;
            cnt_int++;
        }
        else if(input == "long"){
            cout << numeric_limits<long>::min() << "\t" << numeric_limits<long>::max()<<endl;
            cnt_long++;
        }
        else if(input == "float"){
            cout << numeric_limits<float>::min() << "\t" << numeric_limits<float>::max()<<endl;
            cnt_float++;
        }
        else if(input == "double"){
            cout << numeric_limits<double>::min() << "\t" << numeric_limits<double>::max()<< endl;
            cnt_double++;
        }
        else if(input == "quit"){
            break;
        }

    }
    cout << "=== A List of # of types ===" << endl;
    cout << "int:" << cnt_int << endl;
    cout << "long:" << cnt_long << endl;
    cout << "float:" << cnt_float << endl;
    cout << "double:" << cnt_double << endl;
    cout << "char:" << cnt_char << endl;
}

void convertToLower(string& input){
    for(int i=0;i<input.size();i++) {
        if ('A' <= input[i] && input[i] <= 'Z') {
            input[i] += 32;
        }
    }
}
