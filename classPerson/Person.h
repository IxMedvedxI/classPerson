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
	//конструкторы , констрктор копирования и дестркутор
	Person();
	Person(string name, string surname, string patronymic, int age, int height, int weight, int day, int mon, int year);
	Person(const Person& Person);
	~Person();
	//сетеры для взаимодействия с обьектом Person
	void setName(string name);
	void setSurname(string surname);
	void setPatronymic(string patronymic);
	void setAge(int age);
	void setHeight(int height);
	void setweight(int weight);
	void setDate(int day,int mon, int year);

	//гетеры для взаимодействия с обьектом Person
	string getName();
	string getSurname();
	string getPatronymic();
	int getAge();
	int getHeight();
	int getweight();
	tm getDate();

	//переопределение оператора =
	Person& operator=(const Person& per);
	
	//перегрузка операторов сравнения
	bool operator<(Person per);
	bool operator<=(Person per);
	bool operator>(Person per);
	bool operator>=(Person per);
	bool operator==(Person per);

	//методы для записи и чтения из бинарного файла
	void writeBean(ofstream& os);
	void readBean(ifstream& is);

	//перегузка ввода и вывода
	friend ostream& operator<<(ostream& os, const Person& p);
	friend istream& operator>>(istream& is, Person& p);

};

