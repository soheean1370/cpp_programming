#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Item {
protected:
    string modelName;
    int price;
    string itemId; // “modelName-seqNumber”
    static int seqNumber; // initialValue = 1

public:
    Item(const string& _modelName, const int& _price) : modelName(_modelName), price(_price) {
        itemId = _modelName + "-" + to_string(seqNumber++);
    }
    virtual void print() const = 0 ;
    virtual Item* clone() const = 0;
    virtual string getitemId() const = 0;
};

class Monitor : public Item {
    const int size;
public:
    Monitor(const string& _modelName = "", const int& _price = 0, const int& _size = 0) : Item(_modelName, _price), size(_size) {}

    Item* clone() const override{ // override 명시적 암시
        return new Monitor(*this);
    }

    void print() const override{
        cout << modelName << ", " << itemId << ", " << price << ", " << size << endl;
    }
    string getitemId() const override {
        return itemId;
    }
    ~Monitor() {}
};

class CPU : public Item {
    const int speed;
public :
    CPU(const string& _modelName = "", const int& _price = 0, const int& _speed = 0) : Item(_modelName, _price), speed(_speed) {}

    Item* clone() const override{
        return new CPU(*this);
    }

    void print() const override{
        cout << modelName << ", " << itemId << ", " << price << ", " << speed << endl;
    }
    string getitemId() const override{
        return itemId;
    }
    ~CPU(){}
};

class ItemList {
    vector<Item*> items;
public:
    ItemList(const ItemList& list){ // 복사 생성자
        this->items = list.items;
    }
    ItemList(){}

    void addItem(Item* item) {
        items.push_back(item->clone());
    }

    void print() {
        for (auto &i : items) i->print();
    }

    void removeItem(const string& id) {
        items.erase(remove_if(items.begin(), items.end(), [id] (Item* temp) ->bool {return temp->getitemId() == id;}), items.end());
    }

    ItemList& operator = (const ItemList& other) {
        this->items = other.items;
        return *this;
    }

    ~ItemList(){}
};
int Item::seqNumber = 1;
int main() {
    ItemList list1;
    {
        CPU cpu1("Intel", 200, 5); // modelName, price, speed
        CPU cpu2("Intel", 300, 7);
        list1.addItem(&cpu1); list1.addItem(&cpu2);
        Monitor monitor1("Samsung", 1000, 40); //modelName, price, size
        list1.addItem(&monitor1);
    }
    cout << "Section 1" << endl;
    list1.print(); // item list
    {
        ItemList list2(list1);
        cout << "Section 2" << endl;
        list2.print();
        list2.removeItem("Intel-2");
        cout << "Section 3" << endl;
        list2.print();
    }
    {
        ItemList list3;
        list3 = list1; //assignment
    }
    cout << "Section 4" << endl;
    list1.print();
}