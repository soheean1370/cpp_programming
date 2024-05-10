#include <iostream>
#include <vector>
using namespace std;

enum EmployeeLevel {sawon, daeri, gwajang, chajang, bujang} ;
class Employee {
    string name ;
    const EmployeeLevel level ;
public:
    Employee(const string s, const EmployeeLevel lv): name(s), level(lv){
    }
    friend ostream& operator << (ostream& os, const Employee& e);
    string getName() const{
        return name;
    }
    EmployeeLevel getLevel() const{
        return level;
    }
    ~Employee(){
    }
} ;

ostream& operator <<(ostream& os, const Employee& e){
    os << e.level << "\t" << e.name <<endl;
    return os;
}

class Manager : public Employee {
    vector<Employee*> group ;
public:
    Manager(const string s, const EmployeeLevel lv): Employee(s,lv){
    }
    void addEmployee(Employee* emp){
        group.push_back(emp);
    }
    friend ostream& operator << (ostream& os, const Manager& m){
        os << m.getLevel() << "\t" << m.getName()<< endl;
        os << "List of employees managed by me"<<endl;
        for(auto it : m.group){
            os << (*it);
        }
        return os;
    }
    ~Manager(){

    }
} ;


int main() {
    Employee e1("hong", sawon), e2("kim", daeri), e3("cha", sawon) ;
    cout << e1 << e2 << e3 ;

    Manager m1("Tom", chajang) ;
    m1.addEmployee(&e1) ;
    m1.addEmployee(&e2) ;
    m1.addEmployee(&e3) ;
    cout << endl << "Information for Manager" << endl ;
    cout << m1 ;
}
