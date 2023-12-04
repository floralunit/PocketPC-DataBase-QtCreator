#ifndef DATAFIELD_H
#define DATAFIELD_H


#include <string>
#include <iostream>

using namespace std;

class DataField
{
public:
    DataField();
    ~DataField();
    void print();
    void setType(const string& newType);
    void setProductName(const string& newProductName);
    void setCompanyName(const string& newCompanyName);
    void setCountryName(const string& newCountryName);
    string getType() const;
    bool isEmpty();
    string getProductName() const;
    string getCompanyName() const;
    string getCountryName() const;
    DataField operator = (const DataField other);
    friend ostream& operator<<(ostream& os, const DataField& data);
    friend istream& operator>>(istream& is, DataField& data);
    DataField(string type, string productName, string companyName, string countryName);

private:
    string type;
    string productName;
    string companyName;
    string countryName;
};

#endif // DATAFIELD_H
