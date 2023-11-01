#include<iostream>
#include<crtdbg.h>
using namespace std;


//data vs information
// 30 31 32 (data)
//+context
//->info 


//int number;
//Student student;
//Class -> constains data-> datatype made by user -> user defined data

class Person {
	//4 -> principles 
	//private: incapsulation
	//abstractization
	//polymorphism (type A & B)
	//inheritance
	int cnp;
	int salary;
	char* name;

public:

	Person() {//default
		this->cnp = 12345;
		this->salary=1000;
		this->name = new char[5];//heap memo allocated
		strcpy(this->name, "Mada");
	}

	//GETTERS
	int getCnp() {
		return this->cnp;
	}

	char* getName() {

	
	//	return this->name; //shallow copy


		//deep copy:

		//1.create new space
		//2.copy value -> put my original name
		//3.return the new space created

		char* copyName = new char[strlen(this->name) + 1];
		strcpy(copyName, this->name);
		return copyName;

	}


	//SETTERS
	void setSalary(int salary, int password) {
		if (password == 1234) {
			this->salary = salary;//this=current object
		}
	}

	//auth vs authorization



//protected:
//	bool hasBenefits;

	//destructor
	~Person() {
		//delete name space if we have smth allocated
		if (this->name != NULL) {
			delete[] this->name;
		}
	}
};

class Student:Person {
	//attrib - characteristics 
private:
	int finalGrade;
	int* grades;
	int noGrades;

	//methods - behavior
	int getFinalGrade() {
		
		return this->finalGrade;
	}
	int* getGrades() {
		return this->grades;//SHALLOW copy


		//deep-copy
	}

	//public 


	//protected

	//private
};



int main() {


	Person p;
	cout<<p.getCnp();
	char* namePerson = p.getName();
	cout << endl<< p.getName();
	
	//namePerson = "Dana";
	strcpy(namePerson, "Dana");
	cout << endl << namePerson;


	cout << endl<<p.getName();///not saving the address
	//delete???
	//cannot delete the space

	//namePerson = "Maria";

	//delete -> Dana
	//create new space for "maria"
	//copy "maria"

	delete[] namePerson;
	//delete[] p.name->doesnt work
	p.setSalary(2000,1234);
	

	//_CrtDumpMemoryLeaks();
	return 0;
	//
}