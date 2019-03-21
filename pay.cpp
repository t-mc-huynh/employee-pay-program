#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include "person.cpp"
using namespace std;

void readData(string fileName, vector<Person> &employees);
void writeData(string fileName, vector<Person> &employees);

int main() {
	string fileName = "input.txt";
	vector<Person> employees;

	readData(fileName, employees);

	fileName = "output.txt";
	writeData(fileName, employees);
}

void readData(string fileName, vector<Person> &employees) {
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
		employees.push_back(employee);
	}

	inFile.close();
}

void writeData(string fileName, vector<Person> &employees) {
	ofstream outFile;
	outFile.open(fileName);

	for (int i = 0; i < employees.size(); i++)
	{
		outFile << employees.at(i).fullName() << "\t";
		outFile << fixed << setprecision(2) << "$" << employees.at(i).totalPay() << endl;
	}

	cout << "File updated..." << endl;

	outFile.close();
}