#include "DataField.h"
#include <QDebug>
using namespace std;

DataField::DataField()
{
    this->companyName = "";
    this->type = "";
    this->countryName = "";
    this->productName = "";
}

DataField::~DataField()
{
    this->companyName.clear();
    this->type.clear();
    this->countryName.clear();
    this->productName.clear();
}

bool DataField::isEmpty()
{
    qDebug() << companyName.length();
    qDebug() << productName.length();
    qDebug() << countryName.length();
    qDebug() << type.length();
    if (this->companyName.length() == 0 || this->productName.length() == 0 || this->countryName.length() == 0 || this->type.length() == 0)
    {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const DataField& data)
{
    os << data.type << " " << data.productName << " " << data.companyName << " " << data.countryName;
    return os;
}

istream& operator>>(istream& is, DataField& data)
{
    is >> data.type >> data.productName >> data.companyName >> data.countryName;
    return is;
}

void DataField::setType(const string& newType)
{
    type = newType;
}

void DataField::setProductName(const string& newProductName)
{
    productName = newProductName;
}

void DataField::setCompanyName(const string& newCompanyName)
{
    companyName = newCompanyName;
}

void DataField::setCountryName(const string& newCountryName)
{
    countryName = newCountryName;
}
string DataField::getType() const
{
    return type;
}

string DataField::getProductName() const
{
    return productName;
}

string DataField::getCompanyName() const
{
    return companyName;
}

string DataField::getCountryName() const
{
    return countryName;
}

DataField DataField::operator = (const DataField other)
{
    this->companyName = other.companyName;
    this->type = other.type;
    this->countryName = other.countryName;
    this->productName = other.productName;
    return *this;
}

DataField::DataField(string type, string productName, string companyName, string countryName)
{
    this->companyName = companyName;
    this->type = type;
    this->countryName = countryName;
    this->productName = productName;
}



void DataField::print()
{
    cout << this->type << " " << this->productName << " " << this->companyName << " " << this->countryName << endl;
}
