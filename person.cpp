#include <iostream>
#include <string>
#include "person.h"
using namespace std;

Person::Person() {
	firstName = " ";
	lastName = " ";
	payRate = 0.00;
	hoursWorked = 0.00;
}
void Person::setLastName(string lastName) {
	this->lastName = lastName;
}
string Person::getLastName() {
	return lastName;
}
void Person::setFirstName(string firstName) {
	this->firstName = firstName;
}
string Person::getFirstName() {
	return firstName;
}
void Person::setPayRate(float payRate) {
	this->payRate = payRate;
}
float Person::getPayRate() {
	return payRate;
}
void Person::setHoursWorked(float hoursWorked) {
	this->hoursWorked = hoursWorked;
}
float Person::getHoursWorked() {
	return hoursWorked;
}
float Person::totalPay() {
	return payRate * hoursWorked;
}
string Person::fullName() {
	return firstName + " " + lastName;
}