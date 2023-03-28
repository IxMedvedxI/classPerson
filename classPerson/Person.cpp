#include "Person.h"

Person::Person()
{
	name = "Ivan";
	surname = "Ivanov";
	patronymic = "Ivanovich";
	age = 18;
	height = 180;
	weight = 80;
	Date.tm_year = 2000;
	Date.tm_mon = 1;
	Date.tm_wday = 1;
}

Person::Person(string name, string surname, string patronymic, int age, int height, int weight, int day, int mon, int year )
{
	this->name = name;
	this->surname = surname;
	this->patronymic = patronymic;
	this->age = age;
	this->height = height;
	this->weight = weight;
	this->Date.tm_year = year;
	this->Date.tm_mon = mon;
	this->Date.tm_wday = day;
}

Person::Person(const Person& Person)
{
	name = Person.name;
	surname = Person.surname;
	patronymic = Person.patronymic;
	age = Person.age;
	height = Person.height;
	weight = Person.weight;
	Date.tm_year = Person.Date.tm_year;
	Date.tm_mon = Person.Date.tm_mon;
	Date.tm_wday = Person.Date.tm_wday;
}

Person::~Person()
{
}

void Person::setName(string name)
{
	this->name = name;
}

void Person::setSurname(string surname)
{
	this->surname = surname;
}

void Person::setPatronymic(string patronymic)
{
	this->patronymic = patronymic;
}

void Person::setAge(int age)
{
	this->age = age;
}

void Person::setHeight(int height)
{
	this->height = height;
}

void Person::setweight(int weight)
{
	this->weight = weight;
}

void Person::setDate(int day, int mon, int year)
{
	this->Date.tm_wday = day;
	this->Date.tm_mon = mon;
	this->Date.tm_year = year;
}

string Person::getName()
{
	return name;
}

string Person::getSurname()
{
	return surname;
}

string Person::getPatronymic()
{
	return patronymic;
}

int Person::getAge()
{
	return age;
}

int Person::getHeight()
{
	return height;
}

int Person::getweight()
{
	return weight;
}

tm Person::getDate()
{
	return Date;
}

Person& Person::operator=(const Person& per)
{
	name = per.name;
	surname = per.surname;
	patronymic = per.patronymic;
	age = per.age;
	height = per.height;
	weight = per.weight;
	Date.tm_year = per.Date.tm_year;
	Date.tm_mon = per.Date.tm_mon;
	Date.tm_wday = per.Date.tm_wday;
	return *this;
}

bool Person::operator<(Person per)
{
	if (age != per.age) {
		return age < per.age;
	}
	else {
		if (height != per.height) {
			return height < per.height;
		}
		else {
			return weight < per.weight;
		}
	}	
}

bool Person::operator<=(Person per)
{
	if (age != per.age) {
		return age <= per.age;
	}
	else {
		if (height != per.height) {
			return height <= per.height;
		}
		else {
			return weight <= per.weight;
		}
	}
}

bool Person::operator>(Person per)
{
	if (age != per.age) {
		return age > per.age;
	}
	else {
		if (height != per.height) {
			return height > per.height;
		}
		else {
			return weight > per.weight;
		}
	}
}

bool Person::operator>=(Person per)
{
	if (age != per.age) {
		return age >= per.age;
	}
	else {
		if (height != per.height) {
			return height >= per.height;
		}
		else {
			return weight >= per.weight;
		}
	}
}

bool Person::operator==(Person per)
{
	if (age != per.age) {
		return age == per.age;
	}
	else {
		if (height != per.height) {
			return height == per.height;
		}
		else {
			return weight == per.weight;
		}
	}
}

ostream& operator<<(ostream& os, const Person& p)
{
	os << "Full name:" << p.name << " " << p.surname << " " << p.patronymic << endl;
	os << "Age:" << p.age << endl;
	os << "Height:" << p.height << endl;
	os << "Weight:" << p.weight << endl;
	os << "Birthday: " << p.Date.tm_wday << "." << p.Date.tm_mon << "." << p.Date.tm_year << endl;
	return os;
}

istream& operator>>(istream& is, Person& p)
{
	cout << "Name: ";
	is >> p.name;
	cout << "Surame: ";
	is >> p.surname;
	cout << "Patronymic: ";
	is >> p.patronymic;
	cout << "Age: ";
	is >> p.age;
	cout << "Height: ";
	is >> p.height;
	cout << "Weight: ";
	is >> p.weight;
	cout << "Birthday" << endl;
	cout << "Day: ";
	is >> p.Date.tm_wday;
	cout << "Mon: ";
	is >> p.Date.tm_mon;
	cout << "Year: ";
	is >> p.Date.tm_year;
	return is;
}

void Person::writeBean(ofstream& os) {
	size_t len = name.length() + 1;       // Длина с нулевым байтом
	os.write((char*)&len, sizeof(len)); // Запись длины
	os.write((char*)name.c_str(), len);	// Запись данных
	len = surname.length() + 1;       
	os.write((char*)&len, sizeof(len)); 
	os.write((char*)surname.c_str(), len);	
	len = patronymic.length() + 1;       
	os.write((char*)&len, sizeof(len)); 
	os.write((char*)patronymic.c_str(), len);	
	os.write((char*)&age, sizeof(age));
	os.write((char*)&height, sizeof(height));
	os.write((char*)&weight, sizeof(weight));
	os.write((char*)&Date.tm_wday, sizeof(Date.tm_wday));
	os.write((char*)&Date.tm_mon, sizeof(Date.tm_mon));
	os.write((char*)&Date.tm_year, sizeof(Date.tm_year));
	
}

void Person::readBean(ifstream& is) {
	size_t len;       // Длина с нулевым байтом
	is.read((char*)&len, sizeof(len)); // Запись длины
	char* buf = new char[len];         // Выделение буфера для чтения
	is.read(buf, len);                   // Чтение (с нулевым байтом)
	name = buf;                         // Присвоение считанной строки члену					
	is.read((char*)&len, sizeof(len));
	buf = new char[len];        
	is.read(buf, len);                   
	surname = buf;                        
	is.read((char*)&len, sizeof(len));
	buf = new char[len];
	is.read(buf, len);
	patronymic = buf;
	delete[]buf;					// Освобождение памяти
	is.read((char*)&age, sizeof(age));
	is.read((char*)&height, sizeof(height));
	is.read((char*)&weight, sizeof(weight));
	is.read((char*)&Date.tm_wday, sizeof(Date.tm_wday));
	is.read((char*)&Date.tm_mon, sizeof(Date.tm_mon));
	is.read((char*)&Date.tm_year, sizeof(Date.tm_year));
}
