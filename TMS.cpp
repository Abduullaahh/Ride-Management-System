#include <iostream>
#include <cstring>
#include <fstream>
#include "TMS.h"
#define DRIVER_SIZE 10
#define CUSTOMER_SIZE 15
#define VEHICLE_SIZE 20
#define SERVICE_SIZE 20
using namespace std;

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