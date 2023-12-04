#ifndef POCKETPC_H
#define POCKETPC_H

#include <string>
#include <iostream>

using namespace std;

class PocketPC
{
public:
    PocketPC();
    ~PocketPC();
    void print();
    void setModel(const string& newModel);
    void setCompany(const string& newCompany);
    void setProcessor(const string& newProcessor);
    void setRAM_ROM(const string& newRAM_ROM);
    void setScreenResolution(const string& newScreenResolution);
    bool isEmpty();
    string getModel() const;
    string getCompany() const;
    string getProcessor() const;
    string getRAM_ROM() const;
    string getScreenResolution() const;
    PocketPC operator = (const PocketPC other);
    friend ostream& operator<<(ostream& os, const PocketPC& data);
    friend istream& operator>>(istream& is, PocketPC& data);
    PocketPC(string model, string company, string processor, string ram_rom, string screenResolution);

private:
    string Model;
    string Company;
    string Processor;
    string RAM_ROM;
    string ScreenResolution;
};

#endif // POCKETPC_H
