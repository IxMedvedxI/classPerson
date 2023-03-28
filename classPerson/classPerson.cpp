
#include <iostream>
#include "Person.h"
using namespace std;

Person* findPersonByFirstName(Person* perasonArray, int personArraySize, string name) {
	for (int i = 0; i < personArraySize; i++) {
		if (perasonArray[i].getName().compare(name) == 0) {
			return &perasonArray[i];
		}
	}
	return NULL;
}


int main()
{
	Person student1 = Person("Mihail","Bikov","anatolyevich",25,187,79,12,12,2001);
	Person student2 = Person();
	Person student3 = Person();
	const int n = 3;
	//Person student4;
	Person arrayPerson1[n] = {student1,student2,student3};
	Person arrayPerson2[n];
	ofstream file1("file.bin", ios::binary | ios::app);
	
	for (int i = 0; i < n; i++) {
		arrayPerson1[i].writeBean(file1);
		cout << arrayPerson1[i] << endl;
	}
	file1.close();
	ifstream file2("file.bin", ios::binary | ios::app);
	for (int i = 0; i < n; i++) {
		arrayPerson2[i].readBean(file2);
		cout << arrayPerson2[i] << endl;
	}
	file2.close();
	remove("file.bin");//удаление файла 
}

