#include <iostream>
#include <vector>

using namespace std;

const int SUBJECT_NO = 3;
struct StudentInfo {
    string name;
    int scores[SUBJECT_NO];
    int sum;
    float average;
};
int sumscores(int scores[] ){
    int ans =0;
    for(int i= 0;i<3;i++){
        ans += scores[i];
    }
    return ans;
}
float aver(int sum){
    float ans;
    ans = static_cast<float>(sum)/SUBJECT_NO;
    return ans;
}

vector<int> total_score(vector<StudentInfo> data){
    vector<int> arr(4);
    for (vector<StudentInfo>::iterator it = data.begin() ; it != data.end(); ++it){
        for(int i = 0; i<SUBJECT_NO ; i++){
            arr[i] += it-> scores[i];
        }
        arr[3] += it-> sum;
    }
    return arr;
}

void print_Info(vector<StudentInfo>:: iterator it, int n){
    cout<<n<<"\t";
    cout<< it -> name<< "\t";
    for(int i =0; i<SUBJECT_NO;i++){
        cout<<it -> scores[i]<<"\t";
    }
    cout << it->sum <<"\t";
    cout << it->average <<endl;
}

void print_Info_v(vector<StudentInfo> data){
    int n =1;
    for(vector <StudentInfo>::iterator it = data.begin(); it!=data.end();++it){
            print_Info(it,n);
            n++;
    }
}

int main() {
    int cnt;
    vector<int> total(4);
    StudentInfo stud;
    vector<StudentInfo> students;
    cin >> cnt;
    for(int i=0; i< cnt;i++){
        cin >> stud.name;
        for(int i=0; i<SUBJECT_NO;i++){
            cin >> stud.scores[i];
        }
        stud.sum = sumscores(stud.scores);
        stud.average = aver(stud.sum);
        students.push_back(stud);
    }
    total = total_score(students);
    print_Info_v(students);
    cout<<"Total "<<"\t";
    for(vector<int>::iterator it = total.begin(); it != total.end(); it++){
        cout << *it << "\t";
    }
}
