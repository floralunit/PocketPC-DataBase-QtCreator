#include <iostream>
#include "Vector.h"
#include <string>
#include <fstream>
class DataBase
{
public:
    void AddData(DataField elToAdd);
    void MergeBase(DataBase* otherBase);
    void RemoveData(int indx);
    void EditData(DataField el, int id);
    void ShowData();
    //DataBase& SearchData(string str);
    void Sort(int type);
    void saveData(string fileName);
    bool readData(string fileName);
    DataBase();
    ~DataBase();
    Vector<DataField> getData() const;
    DataBase(string fileName);
    DataBase& operator = (const DataBase& data);
    void print();
private:
    Vector<DataField> dataBase;
};
