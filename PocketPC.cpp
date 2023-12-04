#include "PocketPC.h"
#include <QDebug>
using namespace std;
PocketPC::PocketPC()
{
    this->Model = "";
    this->Company = "";
    this->Processor = "";
    this->RAM_ROM = "";
    this->ScreenResolution = "";
}

PocketPC::~PocketPC()
{
    this->Model.clear();
    this->Company.clear();
    this->Processor.clear();
    this->RAM_ROM.clear();
    this->ScreenResolution.clear();
}

bool PocketPC::isEmpty()
{
    qDebug() << Model.length();
    qDebug() << Company.length();
    qDebug() << Processor.length();
    qDebug() << RAM_ROM.length();
    qDebug() << ScreenResolution.length();
    if (this->Model.length() == 0 || this->Company.length() == 0
            || this->Processor.length() == 0 || this->RAM_ROM.length() == 0 || this->ScreenResolution.length() == 0)
    {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const PocketPC& data)
{
    os << data.Model << " " << data.Company << " " << data.Processor
       << " " << data.RAM_ROM << " " << data.ScreenResolution;
    return os;
}

istream& operator>>(istream& is, PocketPC& data)
{
    is >> data.Model >> data.Company >> data.Processor
            >> data.RAM_ROM >> data.ScreenResolution;
    return is;
}

void PocketPC::setModel(const string& newModel)
{
    Model = newModel;
}

void PocketPC::setCompany(const string& newCompany)
{
    Company = newCompany;
}

void PocketPC::setProcessor(const string& newProcessor)
{
    Processor = newProcessor;
}

void PocketPC::setRAM_ROM(const string& newRAM_ROM)
{
    RAM_ROM = newRAM_ROM;
}
void PocketPC::setScreenResolution(const string& newScreenResolution)
{
    ScreenResolution = newScreenResolution;
}
string PocketPC::getModel() const
{
    return Model;
}

string PocketPC::getCompany() const
{
    return Company;
}

string PocketPC::getProcessor() const
{
    return Processor;
}

string PocketPC::getRAM_ROM() const
{
    return RAM_ROM;
}
string PocketPC::getScreenResolution() const
{
    return ScreenResolution;
}

PocketPC PocketPC::operator = (const PocketPC other)
{
    this->Model = other.Model;
    this->Company = other.Company;
    this->Processor = other.Processor;
    this->RAM_ROM = other.RAM_ROM;
    this->ScreenResolution = other.ScreenResolution;
    return *this;
}

PocketPC::PocketPC(string model, string company, string processor, string ram_rom, string screenResolution)
{
    this->Model = model;
    this->Company = company;
    this->Processor = processor;
    this->RAM_ROM = ram_rom;
    this->ScreenResolution = screenResolution;
}



void PocketPC::print()
{
    cout << this->Model << " " << this->Company << " "
    << this->Processor << " " << this->RAM_ROM << " " << this->ScreenResolution << endl;
}
