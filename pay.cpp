#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "person.h"
using namespace std;

void readData(string fileName, Person employees[], int & j);
void writeData(string fileName, Person employees[], int &j);

int main() {
	string fileName = "input.txt";
	Person employees[20];
	int j = 0;

	readData(fileName, employees, j);

	fileName = "output.txt";
	writeData(fileName, employees, j);
}

void readData(string fileName, Person employees[], int & j) {
	ifstream inFile;
	inFile.open("input.txt");

	Person employee;
	string fname, lname, full_name;
	float hours, rate;

	while (!inFile.eof()) {
		inFile >> fname >> lname;
		full_name = fname + " " + lname;
		inFile >> hours >> rate;

		employee.setFirstName(fname);
		employee.setLastName(lname);
		employee.setHoursWorked(hours);
		employee.setPayRate(rate);
		employees[j] = employee;
		j++;
	}

	inFile.close();
}

void writeData(string fileName, Person employees[], int &j) {
	ofstream outFile;
	outFile.open(fileName);

	for (int i = 0; i < j; i++) {
		outFile << employees[i].fullName() << "\t";
		outFile << fixed << setprecision(2) << "$" << employees[i].totalPay() << endl;
	}

	outFile.close();
}