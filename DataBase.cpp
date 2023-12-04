#include "DataBase.h"

void DataBase::AddData(PocketPC elToAdd)
{
    this->dataBase.pushBack(elToAdd);
}
DataBase::DataBase()
{
    this->dataBase = new Vector<PocketPC>();
}

DataBase::DataBase(string fileName)
{
    this->dataBase = new Vector<PocketPC>();
    readData(fileName);
}
DataBase::~DataBase()
{
}
void DataBase::print()
{
    for (int i = 0; i < this->dataBase.size(); i++)
    {
        this->dataBase[i].print();
    }
}

void DataBase::MergeBase(DataBase* otherBase)
{
    for (int i = 0; i < otherBase->dataBase.size(); i++)
    {
        PocketPC temp = otherBase->dataBase[i];
        this->dataBase.pushBack(temp);
    }
}
void DataBase::RemoveData(int indx)
{
    this->dataBase.removeElement(indx);
}
void DataBase::EditData(PocketPC el, int id)
{
    this->dataBase[id] = el;
}
void DataBase::ShowData()
{
    this->print();
}

DataBase& DataBase::operator=(const DataBase& other)
{
    if (this != &other)
    {
        this->dataBase = other.dataBase;
    }
    return *this;
}

Vector<PocketPC> DataBase::getData() const
{
    return this->dataBase;
}

void DataBase::Sort(int type)
{
    int n = dataBase.size();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            // Compare the specified fields based on the type parameter
            bool swapNeeded = false;

            switch (type) {
            case 1:
                swapNeeded = dataBase[j].getModel() > dataBase[j + 1].getModel();
                break;
            case 2:
                swapNeeded = dataBase[j].getCompany() > dataBase[j + 1].getCompany();
                break;
            case 3:
                swapNeeded = dataBase[j].getProcessor() > dataBase[j + 1].getProcessor();
                break;
            case 4:
                swapNeeded = dataBase[j].getRAM_ROM() > dataBase[j + 1].getRAM_ROM();
                break;
            case 5:
                swapNeeded = dataBase[j].getScreenResolution() > dataBase[j + 1].getScreenResolution();
                break;
            default:
                cout << "Invalid sorting type" << endl;
                return;
            }

            if (swapNeeded) {
                swap(dataBase[j], dataBase[j + 1]);
            }
        }
    }

}

void DataBase::saveData(string fileName)
{
    ofstream file(fileName);
    for (int i = 0; i < this->dataBase.size(); i++)
    {
        file << this->dataBase[i] << endl;
    }
}
bool DataBase::readData(string fileName)
{
    ifstream file(fileName);
    if (file.is_open())
    {
        this->dataBase.clear();
        PocketPC temp;
        while (file >> temp)
        {
            this->dataBase.pushBack(temp);
        }
        return true;
    }
    return false;
}
