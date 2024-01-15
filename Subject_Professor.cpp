#include <iostream>
#include <string>


using namespace std;

class Professor {
	const int id;
	char* name = nullptr;
	char department[5] = "none";
	int salary = 0;
	int age = 0;
	static int noProfessor;
public:
	Professor() :id(++Professor::noProfessor) {}

	Professor(const char* name, const char* dept, int salary, int age) :id(++Professor::noProfessor) {
		if (name != nullptr && strlen(name) >= 3) {
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
		else {
			throw exception("Invalid name, at least 3 characters long!");
		}

		if (strlen(dept) > 0 && strlen(dept) < 5) {
			strcpy_s(this->department, strlen(dept)+1, dept);
		}
		else {
			throw exception("Dept should have 4 letters max");
		}

		if (salary >= 1500 && salary <= 20000) {
			this->salary = salary;
		}
		else {
			throw exception("Salary range is 1500 - 20000. Try again!");
		}

		if (age >= 18 && age <= 65) {
			this->age = age;
		}
		else {
			throw exception("Age range is 18 - 65. Try again!");
		}
	}

	char* getName() {
		if (this->name != nullptr && strlen(this->name)>=3) {
			char* copy = new char[strlen(this->name) + 1];
			strcpy_s(copy, strlen(this->name) + 1, this->name);
			return copy;
		}
		else {
			throw exception("There's no name yet for this professor");
		}
	}

	void setSalary(int value) {
		if (value >= 1500 && value <= 20000) {
			this->salary = value;
		}
		else {
			throw exception("Invalid value for new salary! Range is between 1500 - 20000");
		}
	}

	Professor(const Professor& p):id(++Professor::noProfessor) {
		if (p.name != nullptr && strlen(p.name) >= 3) {
			this->name = new char[strlen(p.name) + 1];
			strcpy_s(this->name, strlen(p.name) + 1, p.name);
		}
		else {
			throw exception("Invalid name, at least 3 characters long!");
		}

		if (strlen(p.department) > 0 && strlen(p.department) < 5) {
			strcpy_s(this->department, strlen(p.department) + 1, p.department);
		}
		else {
			throw exception("Department should have 4 letters max");
		}

		if (p.salary >= 1500 && p.salary <= 20000) {
			this->salary = p.salary;
		}
		else {
			throw exception("Salary range is 1500 - 20000. Try again!");
		}

		if (p.age >= 18 && p.age <= 65) {
			this->age = p.age;
		}
		else {
			throw exception("Age range is 18 - 65. Try again!");
		}
	}

	Professor& operator=(const Professor& p) {
		if (p.name != nullptr && strlen(p.name) >= 3) {
			if (this->name != nullptr) {
				delete[] this->name;
				this->name = nullptr;
			}
			this->name = new char[strlen(p.name) + 1];
			strcpy_s(this->name, strlen(p.name) + 1, p.name);
		}
		else {
			throw exception("Invalid name, at least 3 characters long!");
		}

		if (strlen(p.department) > 0 && strlen(p.department) < 5) {
			strcpy_s(this->department, strlen(p.department) + 1, p.department);
		}else {
			throw exception("Dept should have 4 letters max");
		}

		if (p.salary >= 1500 && p.salary <= 20000) {
			this->salary = p.salary;
		}else {
			throw exception("Salary range is 1500 - 20000. Try again!");
		}

		if (p.age >= 18 && p.age <= 65) {
			this->age = p.age;
		}else {
			throw exception("Age range is 18 - 65. Try again!");
		}
		return *this;
	}

	Professor operator++() {
		++this->age;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Professor& p) {
		cout << endl << "Professor Id is: " << p.id;
		if (p.name != nullptr && strlen(p.name) >= 3) {
			cout << endl << "Professor name is: " << p.name;
		}
		if (strlen(p.department) > 0 && strlen(p.department) < 5) {
			cout << endl << "Professor department is: " << p.department;
		}
		if (p.salary >= 1500 && p.salary <= 20000) {
			cout << endl << "Professor salary is: " << p.salary;
		}
		if (p.age >= 18 && p.age <= 65) {
			cout << endl << "Professor age is: " << p.age;
		}
		cout << endl;
		return out;
	}
	char operator[](int index) {
		if (index >= 0 && index < strlen(this->name)) {
			return name[index];
		}
		else {
			throw exception("Invalid index");
		}
	}

	Professor operator+=(int value) {
		if (value > 0 && this->salary + value <= 20000 && this->salary + value >= 1500) {
			this->salary += value;
		}
		return *this;
	}

	~Professor() {
		delete[] this->name;
	}
};

int Professor::noProfessor = 0;

int main() {
	Professor p0;
	Professor p1("Popescu Andrei", "CSIE", 3500, 30);
	try {
		Professor p2("Popa Ioana", "MRKT", 7500, 16);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	Professor p3("Popa Ioana", "MNGT", 7500, 19);
	p1.getName();
	try {
		p1.setSalary(1000);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	Professor p4("Stuparu Maria", "CSIE", 6500, 25);
	Professor p5 = p4;
	p4 = p1;

	p3 = ++p1;
	cout << p3;
	cout << p4[0];
	p3 += 2000;

	return 0;
}