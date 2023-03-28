#pragma once
#include <ostream>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
class Person
{
private:
	string name;
	string surname;
	string patronymic;
	int age;
	int height;
	int weight;
	tm Date;

public:
	Person();
	Person(string name, string surname, string patronymic, int age, int height, int weight, int day, int mon, int year);
	Person(const Person& Person);
	~Person() {};

	void setName(string name);
	void setSurname(string surname);
	void setPatronymic(string patronymic);
	void setAge(int age);
	void setHeight(int height);
	void setweight(int weight);
	void setDate(int day,int mon, int year);

	string getName();
	string getSurname();
	string getPatronymic();
	int getAge();
	int getHeight();
	int getweight();
	tm getDate();


	Person& operator=(const Person& per);
	
	//Сравнения
	bool operator<(Person per);
	bool operator<=(Person per);
	bool operator>(Person per);
	bool operator>=(Person per);
	bool operator==(Person per);

	void writeBean(ofstream& os);

	void readBean(ifstream& is);

	friend ostream& operator<<(ostream& os, const Person& p);
	friend istream& operator>>(istream& is, Person& p);

};

