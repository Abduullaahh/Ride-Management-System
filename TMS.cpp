
#define DRIVER_SIZE 10
#define CUSTOMER_SIZE 15
#define VEHICLE_SIZE 20
#define SERVICE_SIZE 20



#include <iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int d, int m, int y);
	Date(const Date& date);
	void setDay(int day);
	int getDay();
	void setMonth(int month);
	int getMonth();
	void setYear(int year);
	int getYear();
	friend ostream& operator<<(ostream& out, const Date& date);
};


Date::Date() {
	this->day = 0;
	this->month = 0;
	this->year = 0;
}
Date::Date(int d, int m, int y) {
	this->day = d;
	this->month = m;
	this->year = y;
}
Date::Date(const Date& date) {
	this->day = date.day;
	this->month = date.month;
	this->year = date.year;
}
void Date::setDay(int day) {
	this->day = day;
}
int Date::getDay() {
	return this->day;
}
void Date::setMonth(int month) {
	this->month = month;
}
int Date::getMonth() {
	return this->month;
}
void Date::setYear(int year) {
	this->year = year;
}
int Date::getYear() {
	return this->year;
}
ostream& operator<<(ostream& out, const Date& date) {
	out << date.day << "/" << date.month << "/" << date.year << endl;
	return out;
}



class mTime {
private:
	int hour;
	int min;
	int sec;
public:
	mTime();
	mTime(int d, int m, int y);
	mTime(const mTime& mtime);
	void setHour(int hour);
	int getHour();
	void setMin(int min);
	int getMin();
	void setSec(int sec);
	int getSec();
	friend ostream& operator<<(ostream& out, const mTime& mtime);
};


mTime::mTime() {
	this->hour = 0;
	this->min = 0;
	this->sec = 0;
}
mTime::mTime(int d, int m, int y) {
	this->hour = d;
	this->min = m;
	this->sec = y;
}
mTime::mTime(const mTime& mtime) {
	this->hour = mtime.hour;
	this->min = mtime.min;
	this->sec = mtime.sec;
}
void mTime::setHour(int hour) {
	this->hour = hour;
}
int mTime::getHour() {
	return this->hour;
}
void mTime::setMin(int min) {
	this->min = min;
}
int mTime::getMin() {
	return this->min;
}
void mTime::setSec(int sec) {
	this->sec = sec;
}
int mTime::getSec() {
	return this->sec;
}
ostream& operator<<(ostream& out, const mTime& mtime) {
	out << mtime.hour << "/" << mtime.min << mtime.sec << endl;
	return out;
}



class Name {
private:
	char* fName;
	char* lName;
public:
	Name();
	Name(const char* fN, const char* lN);
	Name(const Name& n);
	void setfName(const char* fN);
	void setlName(const char* lN);
	char* getfName();
	char* getlName();
	friend ostream& operator<<(ostream& out, const Name& n);
	~Name();
};


Name::Name() {
	this->fName = NULL;
	this->lName = NULL;
}
Name::Name(const char* fN, const char* lN) {
	this->fName = new char[strlen(fN) + 1];
	this->lName = new char[strlen(lN) + 1];
	strcpy_s(this->fName, strlen(fN) + 1, fN);
	strcpy_s(this->lName, strlen(lN) + 1, lN);
}
Name::Name(const Name& n) {
	this->fName = new char[strlen(n.fName) + 1];
	this->lName = new char[strlen(n.lName) + 1];
	strcpy_s(this->fName, strlen(n.fName) + 1, n.fName);
	strcpy_s(this->lName, strlen(n.lName) + 1, n.lName);
}
void Name::setfName(const char* fN) {
	this->fName = new char[strlen(fN) + 1];
	strcpy_s(this->fName, strlen(fN) + 1, fN);
}
void Name::setlName(const char* lN) {
	this->lName = new char[strlen(lN) + 1];
	strcpy_s(this->lName, strlen(lN) + 1, lN);
}
char* Name::getfName() {
	return this->fName;
}
char* Name::getlName() {
	return this->lName;
}
ostream& operator<<(ostream& out, const Name& n) {
	out << n.fName << " " << n.lName << endl;
	return out;
}
Name::~Name() {
	delete this->fName;
	delete this->lName;
	this->fName = NULL;
	this->lName = NULL;
}

class Person {
	Name pName;
	Date DOB;
	int Age;
	int Nid;
public:
	Person();
	Person(Name, Date, int, int);
	Person(Person& p);
	friend ostream& operator<<(ostream& out, const Person& p);
	void setpName(Name name);
	void setDOB(Date dob);
	void setAge(int age);
	void setNid(int nid);
	Name getpName();
	Date getDOB();
	int getAge();
	int getNid();
	~Person();
};

Person::Person() {
	Age = 0;
	Nid = 0;
}
Person::Person(Name name, Date dob, int age, int nid) {
	this->pName.setfName(name.getfName());
	this->pName.setlName(name.getlName());
	this->DOB.setDay(dob.getDay());
	this->DOB.setMonth(dob.getMonth());
	this->DOB.setYear(dob.getYear());
	this->Age = age;
	this->Nid = nid;
}
Person::Person(Person& p) {
	this->pName.setfName(p.getpName().getfName());
	this->pName.setlName(p.getpName().getlName());
	this->DOB.setDay(p.DOB.getDay());
	this->DOB.setMonth(p.DOB.getMonth());
	this->DOB.setYear(p.DOB.getYear());
	this->Age = p.Age;
	this->Nid = p.Nid;
}
ostream& operator<<(ostream& out, const Person& p) {
	out << "Person name: " << p.pName;
	out << "Date of birth: " << p.DOB;
	out << "Age: " << p.Age << endl;
	out << "National ID: " << p.Nid << endl;
	return out;
}
void Person::setpName(Name name) {
	this->pName.setfName(name.getfName());
	this->pName.setlName(name.getlName());
}
void Person::setDOB(Date dob) {
	this->DOB.setDay(dob.getDay());
	this->DOB.setMonth(dob.getMonth());
	this->DOB.setYear(dob.getYear());
}
void Person::setAge(int age) {
	this->Age = age;
}
void Person::setNid(int nid) {
	this->Nid = nid;
}
Name Person::getpName() {
	return this->pName;
}
Date Person::getDOB() {
	return this->DOB;
}
int Person::getAge() {
	return this->Age;
}
int Person::getNid() {
	return this->Nid;
}
Person::~Person() {
	delete& (this->pName);
}

class Service {
public:
	char* source;
	char* destination;
	float distance;
	Date bookingDate;
	mTime bookingTime;
	bool status;
	float fuelrate;
	int fare;

	int cId;
	int dId;
	int vId;
	Service();
};

class Ride : public Service {
public:
	int noofPassengers;
	char* rideType;
	float DriverRanking;
	float VehicleRanking;
	Ride();
};

class Delivery : public Service {
public:
	float goodWeight;
	char* goodsType;
	Delivery();
};

Service::Service() {
	this->source = new char[100];
	this->destination = new char[100];
	this->distance = 0.0;
	this->bookingDate.setDay(0);
	this->bookingDate.setMonth(0);
	this->bookingDate.setYear(0);
	this->bookingTime.setHour(0);
	this->bookingTime.setMin(0);
	this->bookingTime.setSec(0);
	this->status = false;
	this->fuelrate = 0.0;
	this->cId = 0;
	this->dId = 0;
	this->vId = 0;
	this->fare = 0;
}

Ride::Ride() : Service() {
	this->noofPassengers = 0;
	this->rideType = new char[100];
	this->DriverRanking = 0.0;
	this->VehicleRanking = 0.0;
}

Delivery::Delivery() : Service() {
	this->goodWeight = 0.0;
	this->goodsType = new char[100];
}

class Driver : public Person {
private:
	int dId;
	char** LicencesList;
	int noofLicences;
	float overallRanking;
	float salary;
	int experience;
	int status;
	Service** serviceHistory;
	int size;
public:
	Driver();
	Driver(Name name, Date dob, int age, int nid, int did, int licenses,
		float rank, float salary, int exp, int status, int size,
		char** LicencesList, Service** servicehistory);
	Driver(Driver& d);
	int getdId();
	char** getLicences();
	int getNoLicences();
	float getRanking();
	float getSalary();
	int getExperience();
	int getStatus();
	Service** getServiceHistory();
	int getSize();
	void setDId(int did);
	void setLicences(char** licenses);
	void setNoLicences(int licences);
	void setRanking(float rank);
	void setSalary(float sal);
	void setExperience(int exp);
	void setStatus(int status);
	void setHistory(Service** history);
	void setSize(int size);
	friend ostream& operator<<(ostream& out, const Driver& d);
	~Driver();
};


Driver::Driver() {
	this->dId = 0;
	this->LicencesList = NULL;
	this->noofLicences = 0;
	this->overallRanking = 0.0;
	this->salary = 0.0;
	this->experience = 0;
	this->status = 0;
	this->serviceHistory = NULL;
	this->size = 0;
}
Driver::Driver(Name name, Date dob, int age, int nid, int did, int licences,
	float rank, float salary, int exp, int status, int size,
	char** LicencesList, Service** servicehistory)
	: Person(name, dob, age, nid) {
	this->dId = did;
	this->noofLicences = licences;
	this->overallRanking = rank;
	this->salary = salary;
	this->experience = exp;
	this->status = status;
	this->size = size;
	this->LicencesList = LicencesList;
	this->serviceHistory = serviceHistory;
}
Driver::Driver(Driver& d) : Person(d) {
	this->dId = d.dId;
	this->noofLicences = d.noofLicences;
	this->overallRanking = d.overallRanking;
	this->salary = d.salary;
	this->experience = d.experience;
	this->status = d.status;
	this->size = d.size;
	this->LicencesList = d.LicencesList;
	this->serviceHistory = d.serviceHistory;
}
int Driver::getdId() {
	return this->dId;
}
char** Driver::getLicences() {
	return this->LicencesList;
}
int Driver::getNoLicences() {
	return this->noofLicences;
}
float Driver::getRanking() {
	return this->overallRanking;
}
float Driver::getSalary() {
	return this->salary;
}
int Driver::getExperience() {
	return this->experience;
}
int Driver::getStatus() {
	return this->status;
}
Service** Driver::getServiceHistory() {
	return this->serviceHistory;
}
int Driver::getSize() {
	return this->size;
}
void Driver::setDId(int did) {
	this->dId = did;
}
void Driver::setLicences(char** licenses) {
	this->LicencesList = licenses;
}
void Driver::setNoLicences(int licences) {
	this->noofLicences = licences;
}
void Driver::setRanking(float rank) {
	this->overallRanking = rank;
}
void Driver::setSalary(float sal) {
	this->salary = sal;
}
void Driver::setExperience(int exp) {
	this->experience = exp;
}
void Driver::setStatus(int status) {
	this->status = status;
}
void Driver::setHistory(Service** history) {
	this->serviceHistory = history;
}
void Driver::setSize(int size) {
	this->size = size;
}
ostream& operator<<(ostream& out, const Driver& d) {
	out << (Person&)d;
	out << "Driver ID: " << d.dId << endl;
	out << "Licences List" << endl;
	for (int i = 0; i < d.noofLicences; i++) {
		out << d.LicencesList[i] << endl;
	}
	out << "Ranking: " << d.overallRanking << endl;
	out << "Salary: " << d.salary << endl;
	out << "Experience: " << d.experience << endl;
	out << "Service History" << endl;
	for (int i = 0; i < d.size; i++) {
		out << "Source: " << d.serviceHistory[i]->source << endl;
		out << "Destination: " << d.serviceHistory[i]->destination << endl;
		out << "Total Distance: " << d.serviceHistory[i]->distance << endl;
		out << "Booking Date: " << d.serviceHistory[i]->bookingDate;
		out << "Booking Time: " << d.serviceHistory[i]->bookingTime;
	}
	return out;
}
Driver::~Driver() {
	for (int i = 0; i < this->noofLicences; i++) {
		delete this->LicencesList[i];
	}
	delete this->LicencesList;
	for (int i = 0; i < this->size; i++) {
		delete this->serviceHistory[i];
	}
	delete this->serviceHistory;
}

class Feature {
	int fId;
	char* description;
	float cost;
};





class Vehicle {
public:
	int vId;
	int registrationNo;
	float avgMileage;
	char* LicenseType;
	bool status;
	char* fuelType;
	float overallRanking;
	Date manufacturerDate;
	Feature* list;
	Service** serviceHistory;
	int size;
	Vehicle(int vid, int reg, float avg, char* type, bool status, int size, char* fuel, float rank, Date date, Feature* list, Service** history);
	Vehicle(Vehicle& v);
	friend ostream& operator<<(ostream& out, const Vehicle& v);
};

Vehicle::Vehicle(int vid, int reg, float avg, char* type, bool status, int size,
	char* fuel, float rank, Date date, Feature* list, Service** history) {
	this->vId = vid;
	this->registrationNo = reg;
	this->avgMileage = avg;
	this->LicenseType = new char[strlen(type) + 1];
	strcpy_s(this->LicenseType, strlen(type) + 1, type);
	this->status = status;
	this->fuelType = new char[strlen(fuel) + 1];
	strcpy_s(this->fuelType, strlen(fuel) + 1, fuel);
	this->overallRanking = rank;
	this->manufacturerDate.setDay(date.getDay());
	this->manufacturerDate.setMonth(date.getMonth());
	this->manufacturerDate.setYear(date.getYear());
	this->list = list;
	this->serviceHistory = history;
	this->size = 0;
}
Vehicle::Vehicle(Vehicle& v) {
	this->vId = v.vId;
	this->registrationNo = v.registrationNo;
	this->avgMileage = v.avgMileage;
	this->LicenseType = new char[strlen(v.LicenseType) + 1];
	strcpy_s(this->LicenseType, strlen(v.LicenseType) + 1, v.LicenseType);
	this->status = v.status;
	this->fuelType = new char[strlen(v.fuelType) + 1];
	strcpy_s(this->fuelType, strlen(v.fuelType) + 1, v.fuelType);
	this->overallRanking = v.overallRanking;
	this->manufacturerDate.setDay(v.manufacturerDate.getDay());
	this->manufacturerDate.setMonth(v.manufacturerDate.getMonth());
	this->manufacturerDate.setYear(v.manufacturerDate.getYear());
	this->list = v.list;
	this->serviceHistory = v.serviceHistory;
	this->size = v.size;
}
ostream& operator<<(ostream& out, const Vehicle& v) {
	out << "Vehicle ID: " << v.vId << endl;
	out << "Registration number: " << v.registrationNo << endl;
	out << "Average mileage: " << v.avgMileage << endl;
	out << "License type: " << v.LicenseType << endl;
	out << "Fuel type: " << v.fuelType << endl;
	out << "Ranking: " << v.overallRanking << endl;
	out << "Manufacturing date: " << v.manufacturerDate;
	return out;
}






class Customer : public Person {
private:
	int CId;
	Service** bookingHistory;
	int size;
public:
	Customer();
	Customer(Name name, Date dob, int age, int nid, int cid, int size, Service** bookinghistory);
	Customer(Customer& c);
	int getCId();
	Service** getBookingHistory();
	int getSize();
	void setCId(int id);
	void setBookingHistory(Service** history);
	void setSize(int size);
	void addHistory(Service* history);
	friend ostream& operator<<(ostream& out, const Customer& c);
	~Customer();
};


Customer::Customer() : Person() {
	this->CId = 0;
	this->bookingHistory = NULL;
	this->size = 0;
}
Customer::Customer(Name name, Date dob, int age, int nid, int cid, int size, Service** bookinghistory)
	: Person(name, dob, age, nid) {
	this->CId = cid;
	this->size = size;
	this->bookingHistory = bookingHistory;
}
Customer::Customer(Customer& c) : Person(c) {
	this->CId = c.CId;
	this->size = c.size;
	for (int i = 0; i < this->size; i++) {
		this->bookingHistory[i] = c.bookingHistory[i];
	}
}
int Customer::getCId() {
	return this->CId;
}
Service** Customer::getBookingHistory() {
	return this->bookingHistory;
}
int Customer::getSize() {
	return this->size;
}
void Customer::setCId(int id) {
	this->CId = id;
}
void Customer::setBookingHistory(Service** history) {
	this->bookingHistory = history;
}
void Customer::setSize(int size) {
	this->size = size;
}
void Customer::addHistory(Service* history) {
	this->bookingHistory[this->size++] = history;
}
ostream& operator<<(ostream& out, const Customer& c) {
	out << (Person&)c;
	out << "Customer ID: " << c.CId << endl;
	out << "Booking History" << endl;
	for (int i = 0; i < c.size; i++) {
		out << "Source: " << c.bookingHistory[i]->source << endl;
		out << "Destination: " << c.bookingHistory[i]->destination << endl;
		out << "Total Distance: " << c.bookingHistory[i]->distance << endl;
		out << "Booking Date: " << c.bookingHistory[i]->bookingDate;
		out << "Booking Time: " << c.bookingHistory[i]->bookingTime;
	}
	return out;
}
Customer::~Customer() {
	for (int i = 0; i < this->size; i++) {
		delete this->bookingHistory[i];
	}
	delete this->bookingHistory;
	this->bookingHistory = NULL;
}
class TMS {
	Driver** drivers;
	Customer** customers;
	Vehicle** vehicles;
	Service** services;
	int dSize;
	int cSize;
	int vSize;
	int sSize;
public:
	TMS();
	void loadData();
	void addCustomer();
	void addDriver();
	void removeDriver();
	void addVehicle();
	void removeVehicle();
	void printDrivers();
	void printCustomers();
	void printVehicles();
	void printServiceHistory();
	void printCustomerHistory(int id);
	void printDriverHistory(int id);
	void printDriverRanking();
	void printDriverLicences();
	void printSalary();
	void serviceRequest(int cid);
	void cancelBooking();
	void printService(int id);
	void printSameCustomers();
	void printSameDrivers();
	void printPending();
	void printPendingDriver();
	void printCancelled();
};


TMS::TMS() {
	this->dSize = 0;
	this->cSize = 0;
	this->vSize = 0;
	this->sSize = 0;
	this->drivers = new Driver * [DRIVER_SIZE];
	this->customers = new Customer * [CUSTOMER_SIZE];
	this->vehicles = new Vehicle * [VEHICLE_SIZE];
	this->services = new Service * [SERVICE_SIZE];
}
void TMS::loadData() {
	char fName[50];
	char lName[50];
	int day;
	int mon;
	int year;
	int age;
	int nid;
	int cid;
	int did;
	int nLicense;
	float rank;
	float salary;
	int exp;
	int vid;
	int reg;
	float avg;
	char type[100];
	char fuel[100];
	ifstream fin("customers.txt");
	cout << "Loading data from files..." << endl;
	char line[100];
	while (!fin.eof()) {
		fin.getline(line, 100);
		char* next;
		char* token = strtok_s(line, " ", &next);
		strcpy_s(fName, strlen(token) + 1, token);
		token = strtok_s(NULL, " ", &next);
		strcpy_s(lName, strlen(token) + 1, token);
		token = strtok_s(NULL, " ", &next);
		day = atoi(token);
		token = strtok_s(NULL, " ", &next);
		mon = atoi(token);
		token = strtok_s(NULL, " ", &next);
		year = atoi(token);
		age = 2022 - year;
		token = strtok_s(NULL, " ", &next);
		nid = atoi(token);
		token = strtok_s(NULL, " ", &next);
		cid = atoi(token);
		this->customers[this->cSize] = new Customer(*(new Name(fName, lName)),
			*(new Date(day, mon, year)), age, nid, cid, 0, NULL);
		this->cSize++;
	}
	fin.close();
	fin.open("drivers.txt");
	while (!fin.eof()) {
		fin.getline(line, 100);
		char* next;
		char* token = strtok_s(line, " ", &next);
		strcpy_s(fName, strlen(token) + 1, token);
		token = strtok_s(NULL, " ", &next);
		strcpy_s(lName, strlen(token) + 1, token);
		token = strtok_s(NULL, " ", &next);
		day = atoi(token);
		token = strtok_s(NULL, " ", &next);
		mon = atoi(token);
		token = strtok_s(NULL, " ", &next);
		year = atoi(token);
		age = 2022 - year;
		token = strtok_s(NULL, " ", &next);
		nid = atoi(token);
		token = strtok_s(NULL, " ", &next);
		did = atoi(token);
		token = strtok_s(NULL, " ", &next);
		nLicense = 0;
		token = strtok_s(NULL, " ", &next);
		rank = atof(token);
		token = strtok_s(NULL, " ", &next);
		salary = atof(token);
		token = strtok_s(NULL, " ", &next);
		exp = atof(token);
		this->drivers[this->dSize] = new Driver(*(new Name(fName, lName)),
			*(new Date(day, mon, year)), age, nid, did, nLicense, rank,
			salary, exp, 1, 0, NULL, NULL);
		this->dSize++;
	}
	fin.close();
	fin.open("vehicles.txt");
	while (!fin.eof()) {
		fin.getline(line, 100);
		char* next;
		char* token = strtok_s(line, " ", &next);
		vid = atoi(token);
		token = strtok_s(NULL, " ", &next);
		reg = atoi(token);
		token = strtok_s(NULL, " ", &next);
		avg = atof(token);
		token = strtok_s(NULL, " ", &next);
		strcpy_s(type, strlen(token) + 1, token);
		token = strtok_s(NULL, " ", &next);
		strcpy_s(fuel, strlen(token) + 1, token);
		token = strtok_s(NULL, " ", &next);
		rank = atof(token);
		token = strtok_s(NULL, " ", &next);
		day = atoi(token);
		token = strtok_s(NULL, " ", &next);
		mon = atoi(token);
		token = strtok_s(NULL, " ", &next);
		year = atoi(token);
		this->vehicles[this->vSize] = new Vehicle(vid, reg, avg, type,
			false, 0, fuel, rank, *(new Date(day, mon, year)), NULL, NULL);
		this->vSize++;
	}
	fin.close();
	cout << "Data loaded successfuly" << endl;
}
void TMS::addCustomer() {
	char fName[50];
	char lName[50];
	int day;
	int mon;
	int year;
	int age;
	int nid;
	int cid;
	cout << "Enter first name: ";
	cin.getline(fName, 50);
	cout << "Enter last name: ";
	cin.getline(lName, 50);
	cout << "Enter day of birth: ";
	cin >> day;
	cout << "Enter month of birth: ";
	cin >> mon;
	cout << "Enter year of birth: ";
	cin >> year;
	age = 2022 - year;
	cout << "Enter national ID: ";
	cin >> nid;
	cout << "Enter customer ID: ";
	cin >> cid;
	this->customers[this->cSize] = new Customer(*(new Name(fName, lName)),
		*(new Date(day, mon, year)), age, nid, cid, 0, NULL);
	cout << *(this->customers[this->cSize]);
	this->cSize++;
}
void TMS::addDriver() {
	char fName[50];
	char lName[50];
	int day;
	int mon;
	int year;
	int age;
	int nid;
	int did;
	int nLicense;
	float rank;
	float salary;
	int exp;
	cout << "Enter first name: ";
	cin.getline(fName, 50);
	cout << "Enter last name: ";
	cin.getline(lName, 50);
	cout << "Enter day of birth: ";
	cin >> day;
	cout << "Enter month of birth: ";
	cin >> mon;
	cout << "Enter year of birth: ";
	cin >> year;
	age = 2022 - year;
	cout << "Enter national ID: ";
	cin >> nid;
	cout << "Enter driver ID: ";
	cin >> did;
	nLicense = 0;
	cout << "Enter ranking: ";
	cin >> rank;
	cout << "Enter salary: ";
	cin >> salary;
	cout << "Enter experience: ";
	cin >> exp;
	this->drivers[this->dSize] = new Driver(*(new Name(fName, lName)),
		*(new Date(day, mon, year)), age, nid, did, nLicense, rank,
		salary, exp, 1, 0, NULL, NULL);
	cout << *(this->drivers[this->dSize]);
	this->dSize++;
}
void TMS::removeDriver() {
	int did;
	int ind = 0;
	bool check = false;
	cout << "Enter driver ID: ";
	cin >> did;
	for (int i = 0; i < this->dSize && !check; i++) {
		if (this->drivers[i]->getdId() == did) {
			ind = i;
			check = true;
		}
	}
	if (check) {
		this->dSize--;
		delete this->drivers[ind];
		this->drivers[ind] = new Driver(*(this->drivers[this->dSize]));
		delete this->drivers[this->dSize];
		this->drivers[this->dSize] = NULL;
	}
}
void TMS::addVehicle() {
	int vid;
	int reg;
	float avg;
	char type[100];
	char fuel[100];
	float rank;
	int day;
	int mon;
	int year;
	cout << "Enter vehicle ID: ";
	cin >> vid;
	cout << "Enter registration number: ";
	cin >> reg;
	cout << "Enter average mileage: ";
	cin >> avg;
	cout << "Enter license type: ";
	cin.getline(type, 100);
	cout << "Enter fuel type: ";
	cin.getline(fuel, 100);
	cout << "Enter rank: ";
	cin >> rank;
	cout << "Enter manufacturing day: ";
	cin >> day;
	cout << "Enter manufacturing month: ";
	cin >> mon;
	cout << "Enter manufacturing year: ";
	cin >> year;
	this->vehicles[this->vSize] = new Vehicle(vid, reg, avg, type,
		false, 0, fuel, rank, *(new Date(day, mon, year)), NULL, NULL);
	cout << *(this->vehicles[this->vSize]);
	this->vSize++;

}
void TMS::removeVehicle() {
	int vid;
	int ind = 0;
	bool check = false;
	cout << "Enter vehicle ID: ";
	cin >> vid;
	for (int i = 0; i < this->vSize && !check; i++) {
		if (this->vehicles[i]->vId == vid) {
			ind = i;
			check = true;
		}
	}
	if (check) {
		this->vSize--;
		delete this->vehicles[ind];
		this->vehicles[ind] = new Vehicle(*(this->vehicles[this->vSize]));
		delete this->vehicles[this->vSize];
		this->vehicles[this->vSize] = NULL;
	}
}
void TMS::printDrivers() {
	cout << "Drivers" << endl;
	for (int i = 0; i < this->dSize; i++) {
		cout << *(this->drivers[i]);
	}
}
void TMS::printCustomers() {
	cout << "Customers" << endl;
	for (int i = 0; i < this->cSize; i++) {
		cout << *(this->customers[i]);
	}
}
void TMS::printVehicles() {
	cout << "Vehicles" << endl;
	for (int i = 0; i < this->vSize; i++) {
		cout << *(this->vehicles[i]);
	}
}
void TMS::printServiceHistory() {
	cout << "Vehicles" << endl;
	for (int i = 0; i < this->vSize; i++) {
		for (int j = 0; j < this->vehicles[i]->size; j++)
		{
			cout << this->vehicles[i]->serviceHistory[j];
		}
	}
}
void TMS::printCustomerHistory(int id) {
	for (int i = 0; i < this->cSize; i++) {
		if (this->customers[i]->getCId() == id) {
			cout << *(this->customers[i]);
		}
	}
}
void TMS::printDriverHistory(int id) {
	for (int i = 0; i < this->dSize; i++) {
		if (this->drivers[i]->getdId() == id) {
			cout << *(this->drivers[i]);
		}
	}
}
void TMS::printDriverRanking() {
	for (int i = 0; i < this->dSize; i++) {
		if (this->drivers[i]->getRanking() > 4.5) {
			cout << *(this->drivers[i]);
		}
	}
}
void TMS::printDriverLicences() {
	for (int i = 0; i < this->dSize; i++) {
		if (this->drivers[i]->getNoLicences() > 1) {
			cout << *(this->drivers[i]);
		}
	}
}
void TMS::printSalary() {
	for (int i = 0; i < this->dSize; i++) {
		if (this->drivers[i]->getRanking() > 4.5) {
			float sal = this->drivers[i]->getSalary();
			cout << (sal + (sal * 0.15)) << endl;
		}
	}
}
void TMS::serviceRequest(int cid) {
	int choice;
	cout << "1. Ride Service\n2. Delivery Service: ";
	cin >> choice;
	if (choice == 1) {
		Ride* ride = new Ride();
		cout << "Enter source: ";
		cin.getline(ride->source, 100);
		cout << "Enter detination: ";
		cin.getline(ride->destination, 100);
		cout << "Enter distance: ";
		cin >> ride->distance;
		cout << "Enter fuel rate: ";
		cin >> ride->fuelrate;
		cout << "Available Drivers" << endl;
		for (int i = 0; i < this->dSize; i++) {
			cout << i + 1 << ". ";
			cout << *(this->drivers[i]);
		}
		cout << "Select driver: ";
		int driv;
		cin >> driv;
		driv--;
		cout << "Available Vehicles" << endl;
		for (int i = 0; i < this->vSize; i++) {
			cout << i + 1 << ". ";
			cout << *(this->vehicles[i]);
		}
		cout << "Select vehicle: ";
		int veh;
		cin >> veh;
		ride->cId = cid;
		ride->dId = this->drivers[driv]->getdId();
		ride->vId = this->vehicles[veh]->vId;
		cout << "Enter number of passengers: ";
		cin >> ride->noofPassengers;
		cout << "Enter ride type(inter, intra): ";
		cin.getline(ride->rideType, 100);
		ride->DriverRanking = this->drivers[driv]->getRanking();
		ride->VehicleRanking = this->drivers[driv]->getRanking();
		ride->fare = (ride->distance * 12) + (ride->fuelrate * 2);
		cout << "Calculated fare is: " << ride->fare << endl;
		this->services[this->sSize] = ride;
		this->sSize++;
	}
	else if (choice == 2) {
		Delivery* del = new Delivery();
		cout << "Enter source: ";
		cin.getline(del->source, 100);
		cout << "Enter detination: ";
		cin.getline(del->destination, 100);
		cout << "Enter distance: ";
		cin >> del->distance;
		cout << "Enter fuel rate: ";
		cin >> del->fuelrate;
		cout << "Available Drivers" << endl;
		for (int i = 0; i < this->dSize; i++) {
			cout << i + 1 << ". ";
			cout << *(this->drivers[i]);
		}
		cout << "Select driver: ";
		int driv;
		cin >> driv;
		driv--;
		cout << "Available Vehicles" << endl;
		for (int i = 0; i < this->vSize; i++) {
			cout << i + 1 << ". ";
			cout << *(this->vehicles[i]);
		}
		cout << "Select vehicle: ";
		int veh;
		cin >> veh;
		del->cId = cid;
		del->dId = this->drivers[driv]->getdId();
		del->vId = this->vehicles[veh]->vId;
		cout << "Enter goods weight: ";
		cin >> del->goodWeight;
		cout << "Enter good type: ";
		cin.getline(del->goodsType, 100);
		del->fare = ((del->distance * 12) + (del->fuelrate * 2) + (del->goodWeight * 5));
		cout << "Calculated fare is: " << del->fare << endl;
		this->services[this->sSize] = del;
		this->sSize++;
	}
}
void TMS::cancelBooking() {
	int cid;
	int did;
	cout << "Enter customer ID: ";
	cin >> cid;
	cout << "Enter driver ID: ";
	cin >> did;
	for (int i = 0; i < this->dSize; i++) {
		if (this->drivers[i]->getdId() == did) {
			this->drivers[i]->setStatus(3);
		}
	}
	for (int i = 0; i < this->sSize; i++) {
		if (this->services[i]->cId == cid &&
			this->services[i]->dId == did) {
			cout << "Cancelation fare: " << this->services[i]->fare * 0.05 << endl;
		}
	}
}
void TMS::printService(int id) {
	cout << "Source: " << this->services[id]->source << endl;
	cout << "Destination: " << this->services[id]->destination << endl;
	cout << "Fuel rate: " << this->services[id]->fuelrate << endl;
	cout << "Distance: " << this->services[id]->distance << endl;
	cout << "Customer ID: " << this->services[id]->cId << endl;
	cout << "Driver ID: " << this->services[id]->dId << endl;
	cout << "Vehicle ID: " << this->services[id]->vId << endl;
}
void TMS::printSameCustomers() {
	for (int i = 0; i < this->cSize; i++) {
		cout << *(this->customers[i]);
	}
}
void TMS::printSameDrivers() {
	for (int i = 0; i < this->dSize; i++) {
		cout << *(this->drivers[i]);
	}
}
void TMS::printPending() {
	for (int i = 0; i < this->sSize; i++) {
		if (!this->services[i]->status) {
			this->printService(i);
		}
	}
}
void TMS::printPendingDriver() {
	int did;
	cout << "Enter driver ID: ";
	cin >> did;
	for (int i = 0; i < this->sSize; i++) {
		if (this->services[i]->status == false && this->services[i]->dId == did) {
			this->printService(i);
		}
	}
}
void TMS::printCancelled() {
	for (int i = 0; i < this->dSize; i++) {
		if (this->drivers[i]->getStatus() == 3) {
			cout << *(this->drivers[i]);
		}
	}
}
int main() {
	TMS* tms = new TMS();
	tms->loadData();
	int choice = -1;
	while (choice != 0) {
		cout << "------------------------------------------------------------------------------------------\n\n\n";
		cout << "                ----------------------------------------------------\n";
		cout << "                |  Welcome to Ride and Transport Management System  |\n";
		cout << "                ----------------------------------------------------\n";
		cout << "                1. Add a new Customer" << endl;
		cout << "                2. Add a Driver" << endl;
		cout << "                3. Remove a driver" << endl;
		cout << "                4. Add a vehicle" << endl;
		cout << "                5. Remove a vehicle" << endl;
		cout << "                6. Print list of customers" << endl;
		cout << "                7. Print list of drivers" << endl;
		cout << "                8. Print list of vehicles" << endl;
		cout << "                9. Print service history of vehicles" << endl;
		cout << "                10. Print history of a customer" << endl;
		cout << "                11. Print history of a driver" << endl;
		cout << "                12. Print list of drivers with ranking > 4.5" << endl;
		cout << "                13. Print drivers with multiple licences" << endl;
		cout << "                14. Print updated salary of drivers" << endl;
		cout << "                15. Add a service request" << endl;
		cout << "                16. Cancel a service request" << endl;
		cout << "                17. Complete service request" << endl;
		cout << "                18. Print customer details with same vehicle" << endl;
		cout << "                19. Print list of drivers with same day delivery" << endl;
		cout << "                20. Print list of pending services" << endl;
		cout << "                21. Print list of pending services of driver" << endl;
		cout << "                22. Print list of cancelled services\n\n" << endl;
		cout << "                0. Exit" << endl;
		cout << "------------------------------------------------------------------------------------------\n";
		cin >> choice;
		cout << "------------------------------------------------------------------------------------------\n";
		system("cls");
		cin.ignore();
		switch (choice) {
		case 0:
			cout << "Exiting program..." << endl;
			break;
		case 1:
			tms->addCustomer();
			break;
		case 2:
			tms->addDriver();
			break;
		case 3:
			tms->removeDriver();
			break;
		case 4:
			tms->addVehicle();
			break;
		case 5:
			tms->removeVehicle();
			break;
		case 6:
			tms->printCustomers();
			break;
		case 7:
			tms->printDrivers();
			break;
		case 8:
			tms->printVehicles();
			break;
		case 9:
			tms->printServiceHistory();
			break;
		case 10:
			int cid;
			cout << "Enter customer ID: ";
			cin >> cid;
			tms->printCustomerHistory(cid);
			break;
		case 11:
			int did;
			cout << "Enter driver ID: ";
			cin >> did;
			tms->printDriverHistory(did);
			break;
		case 12:
			tms->printDriverRanking();
			break;
		case 13:
			tms->printDriverLicences();
			break;
		case 14:
			tms->printSalary();
			break;
		case 15:
			cout << "Enter customer ID: ";
			cin >> cid;
			tms->serviceRequest(cid);
			break;
		case 16:
			tms->cancelBooking();
			break;
		case 17:
			int sid;
			cout << "Enter service ID: ";
			cin >> sid;
			tms->printService(sid);
			break;
		case 18:
			tms->printSameCustomers();
			break;
		case 19:
			tms->printSameDrivers();
			break;
		case 20:
			tms->printPending();
			break;
		case 21:
			tms->printPendingDriver();
			break;
		case 22:
			tms->printCancelled();
			break;
		default:
			cout << "Wrong choice!" << endl;
		}
	}
	system("pause");
	return 0;
}