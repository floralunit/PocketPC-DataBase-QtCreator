#include <iostream>
#include "Vector.h"
#include <string>
#include <fstream>
class DataBase
{
public:
    void AddData(PocketPC elToAdd);
    void MergeBase(DataBase* otherBase);
    void RemoveData(int indx);
    void EditData(PocketPC el, int id);
    void ShowData();
    void Sort(int type);
    void saveData(string fileName);
    bool readData(string fileName);
    DataBase();
    ~DataBase();
    Vector<PocketPC> getData() const;
    DataBase(string fileName);
    DataBase& operator = (const DataBase& data);
    void print();
private:
    Vector<PocketPC> dataBase;
};
