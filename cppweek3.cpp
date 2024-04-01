#include <iostream>
using namespace std;

string low(string c){
    string temp = c;
    for(int i=0; i<temp.size(); i++){
        if('A'<=temp[i] && temp[i]<= 'Z'){
            temp[i]+= 32;
        }
    }
    return temp;
}

int sum(int arr[], int t){
    int temp =0;
   for(int i=0; i<t; i++){
        temp+=arr[i];
    }
    return temp;
}

void printAverage(int arr[],int t){
    float temp =0;
    for(int i =0; i<t; i++){
        temp += arr[i];
    }
    if(t !=0) {
        temp = temp / t;
        cout << "\t" << "Average: " << temp << endl;
    } else {
        cout << "1개 이상의 점수가 입력되어야 한다" << endl;
    }
}
void printList(int arr[],int t){
    if (t>1){
        for(int i=0;i<t-1 ;i++){
            cout <<"\t" << arr[i] << ",";
        }
        cout << arr[t-1] << endl;
    }
    else if(t==1){
        cout << arr[t-1] << endl;
    }
    else{
        cout << endl;
    }
}

int main() {
    cout<< "Enter the score count: ";
    int maxSize, score, k=0;
    float avg;
    string command;
    cin >> maxSize;
    int* const scores = new int[maxSize];
    cout << "Enter command: (add, sum,average, list, quit) ";
    cin >> command;
    command = low(command);
    while(command != "quit"){
        if(command == "add"){
            if(k<maxSize){
                cout<< "Enter score: ";
                cin >> score;
                if(score >=0 && score <= 100){
                    cout<<"\t" << score << " added"<<endl;
                    scores[k] = score;
                    k++;
                }
                else{
                    cout << "\t" << "Score should be between 0 and 100"<< endl;
                }
            }
            else{
                cout<< "Too many scores"<<endl;
            }
        }
        else if(command == "sum"){
            cout<<"\t" <<"Sum: "<< sum(scores,k) << endl;
        }
        else if(command == "average"){
            printAverage(scores,k);
        }
        else if(command == "list"){
            printList(scores,k);
        }
        cout << "Enter command: (add, sum,average, list, quit) ";
        cin >> command;
        command = low(command);
    }
    cout<<"Bye";
    delete [] scores;
}
