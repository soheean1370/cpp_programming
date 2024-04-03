#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct Rectangle{
    int width;
    int height;
};

enum CommandKind{ADD,SORT,PRINT,CLEAR,EXIT,INVALID};
Rectangle getRectangle(){
    Rectangle rec;
    cin >> rec.width;
    cin >> rec.height;
    return rec;
}
string toUpper(string commandString){
    string s = commandString;
    for(int i = 0; i < s.size(); i++){
        if('a' <= s[i] && s[i] <= 'z'){
            s[i] -= 32;
        }
    }
    return s;
}

CommandKind getCommandKind(string commandString){
    string upperCaseCommand = toUpper(commandString);
    if (upperCaseCommand == "ADD") return ADD;
    else if(upperCaseCommand == "SORT") return SORT;
    else if(upperCaseCommand == "PRINT") return PRINT;
    else if(upperCaseCommand == "CLEAR") return CLEAR;
    else if(upperCaseCommand == "EXIT") return EXIT;
    else return INVALID;
}

void swap(Rectangle& rec1, Rectangle& rec2){
    Rectangle temp = rec1;
    rec1 = rec2;
    rec2 = temp;
}

void sort(vector<Rectangle>& rectangles) {
    for (int i = 0; i < rectangles.size() - 1; i++) {
        for (int j = 0; j < rectangles.size() - i - 1; j++) {
            int left = rectangles[j].width * rectangles[j].height;
            int right = rectangles[j + 1].width * rectangles[j + 1].height;
            if (left > right)
                swap(rectangles[j], rectangles[j + 1]);
        }
    }
}
void print(const vector<Rectangle>& rectangles){
    cout << "Rectangle Count: " << rectangles.size() << endl;
    for (vector<Rectangle>::const_iterator it = rectangles.begin(); it!=rectangles.end(); ++it){
        cout << "\t";
        cout << it->width <<" "<< it->height <<" "<< (it->width)*(it->height) << endl;
    }
}

int main() {
    vector<Rectangle> rectangles ;
    while ( true ) {
        string commandString;
        cin >> commandString;
        const CommandKind command = getCommandKind(commandString);
        switch ( command ) {
            case ADD : {
                const Rectangle& newRectangle = getRectangle();
                rectangles.push_back(newRectangle) ;
                break ;
            }
            case PRINT:
                print(rectangles) ;
                break ;
            case SORT: {
                sort(rectangles) ; // define and call swap in sort()
                print(rectangles) ;
                break ;
            }
            case CLEAR:  rectangles.clear() ; break ;
            case EXIT: break ;
            default:  assert (false) ; break ;
        }
        if ( command == EXIT ) break ;
    }
}
