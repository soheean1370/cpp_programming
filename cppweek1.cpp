#include <iostream>
using namespace std;
char calculateGrade(const int score);
int main() {
    string name;
    while(true){
        cout << "Enter a name and score: ";
        int score;
        cin >> name >> score;
        const char grade = calculateGrade(score);
        if(grade == -1) break;
        cout<<"Hi "<< name<< "! Your grade is "<< grade << "\n";
    }
    cout <<"Bye " << name;
    return 0;
}

char calculateGrade(const int score) {
    char grade;
    if (score < 0 || score > 100)
        grade = -1;
    else if (score >= 90)
        grade = 'A';
    else if (score >= 80)
        grade = 'B';
    else if (score >= 70)
        grade = 'C';
    else if (score >= 60)
        grade = 'D';
    else grade = 'F';

    return grade;
}
