#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student{
private:
    string name;
    float gpa;

public:
    Student(string _name, float _gpa=0){
        name = _name;
        gpa = _gpa;
    }
    void print_student(){
        cout<<"Name "<< name << " GPA: " << gpa << endl;
    }
    void setGPA(float new_gpa){
        gpa = new_gpa;
    }
    void setName(string new_name){
        name = new_name;
    }
    float gpa_value(){
        return gpa;
    }
    string name_value() const{
        return name;
    }
};

class School{
private:
    string schoolName;
    vector<Student> students;
public:
    School(const string& _schoolName){
        schoolName = _schoolName;
    }
    void addStudent(string _name, float _gpa=0){
        Student stu(_name, _gpa);
        students.push_back(stu);
    }
    void print(){
        cout << "School Name: " << schoolName<< " Count: "<< students.size()<<endl;
        for(vector<Student>::iterator it = students.begin(); it != students.end(); ++it){
            (*it).print_student();
        }
        cout<<endl;
    }
    void sort(){
        for(int k=students.size()-1; k>=0; k--){
            for(int i=0;i<k;i++){
                if(students[i].gpa_value() < students[i+1].gpa_value()){
                    Student temp = students[i];
                    students[i] = students[i+1];
                    students[i+1] = temp;
                }
            }
        }
    }
    Student& findStudentWithName(const string name) { //Student& -> 함수 내에서 찾은 학생 객체에 대한 참조를 반환. 학생 객체의 복사본이 아니라 실제 객체에 대한 참조를 반환하여 수정이 가능
        for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it) {
            if (name == (*it).name_value()) {
                return (*it);
            }
        }
    }
};


int main() {
    School pnu("PNU") ;

    pnu.addStudent("Kim", 2.7F) ;
    pnu.addStudent("Hong", 3.5F) ;
    pnu.addStudent("Lee") ;
    pnu.addStudent("Joo", 1.5F) ;

    pnu.print() ;

    pnu.sort() ; // descending
    pnu.print() ;

    School knu("KNU") ;
    knu.addStudent("Seo", 2.5F) ;
    knu.addStudent("Lee", 3.8F) ;
    knu.print() ;


    Student& lee = pnu.findStudentWithName("Lee") ;
    lee.setGPA(3.3F) ;
    lee.setName("Yoon") ;

    pnu.print() ;

    knu.addStudent("Hong", 4.3F) ;
    Student& hong = knu.findStudentWithName("Hong") ;
    hong.setGPA(3.3F) ;
    hong.setName("Joon") ;
    knu.print() ;
}

