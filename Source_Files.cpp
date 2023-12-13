#include<iostream>
#include<fstream>
using namespace std;

class Student {

private:
	string name;//char*
	int age;
	int noGrades;
	int* grades;
public:
	Student() {

		this->name = "Anonim";
		this->age = 0;
		this->grades = nullptr;
		this->noGrades = 0;
	}

	Student(const char* name, int age, int* grades, int nrgrades) {

		this->name = name;
		this->age = age;
		this->grades = grades;
		this->noGrades = nrgrades;
		this->grades = new int[this->noGrades];
		for (int i = 0; i < this->noGrades; i++) {
			this->grades[i] = grades[i];
		}

	}

	Student(const Student& s) {
		this->name = s.name;
		this->age = s.age;
		this->noGrades = s.noGrades;
		this->grades = new int[this->noGrades];
		for (int i = 0; i < this->noGrades; i++) {
			this->grades[i] = s.grades[i];
		}
	}

	Student& operator=(const Student& s) {
		if (this != &s) {
			this->name = s.name;
			this->age = s.age;
			if (this->grades != NULL) {
				delete[] this->grades;
				this->noGrades = 0;
			}
			this->noGrades = s.noGrades;
			this->grades = new int[this->noGrades];
			for (int i = 0; i < this->noGrades; i++) {
				this->grades[i] = s.grades[i];
			}
		}
		return *this;
	}
	~Student() {
		if (this->grades != NULL) {
			delete[]this->grades;
		}
	}
	
	friend ostream& operator<<(ostream& out, Student s);

	//ifstream / ofstream -> fstream f>> f<<
	//istream / ostream -> iostream cout<< cin>>
	friend ofstream& operator<<(ofstream& f, Student& s);
	friend ifstream& operator>>(ifstream& f, Student& s);


	void serialize() {
		//ofstream
		ofstream f("student.bin", ios::binary);
		//this
		// dim name:
		int size = this->name.length();//4 8 
		f.write((char*)&size, sizeof(size));//4
		// name:
		f.write(this->name.c_str(), this->name.length() + 1);
		//age:20
		f.write((char*)&this->age, sizeof(this->age));
		// char* = pointer = adresa = &20
		f.write((char*)&this->noGrades, sizeof(this->noGrades));
		for (int i = 0; i < this->noGrades; i++) {
			f.write((char*)&this->grades[i], sizeof(this->grades[i]));
		}
		f.close();
	}
	void deserialize() {
		ifstream f("student.bin", ios::binary);
		int dimname = 0;
		f.read((char*)&dimname, sizeof(dimname));//4

		char* temp = new char[dimname + 1];//5
		f.read(temp, dimname + 1);//5
		this->name = temp;
		delete[]temp;

		f.read((char*)&this->age, sizeof(this->age));

		if (this->grades != nullptr && this->noGrades > 0) {
			delete[] this->grades;
		}
		f.read((char*)&this->noGrades, sizeof(this->noGrades));
		this->grades = new int[this->noGrades];
		for (int i = 0; i < this->noGrades; i++) {
			f.read((char*)&this->grades[i], sizeof(this->grades[i]));
		}

		f.close();
		//ifstream
	}
};

ostream& operator<<(ostream& out, Student s) {
	out << "\nStudentul " << s.name << " cu age " << s.age << " are urm grades: ";
	for (int i = 0; i < s.noGrades; i++) {
		out << s.grades[i] << ", ";
	}
	return out;
}



//f  >>  <<

ofstream& operator<<(ofstream& f, Student& s) {

	if (!f.is_open()) {
		throw exception("file is not opened");
	}
	int size = s.name.length();
	f << size << endl;
	f << s.name << endl;
	f << s.age << endl;
	f << s.noGrades << endl;
	for (int i = 0; i < s.noGrades; i++) {
		f << s.grades[i] << endl;
	}


	return f;
}
ifstream& operator>>(ifstream& f, Student& s) {

	if (!f.is_open()) {
		throw exception("file is not opened");
	}
	
	int size = s.name.length();
	f >> size;
	f >> s.name;
	f >> s.age;
	f >> s.noGrades;
	if (s.noGrades != 0) {
		s.grades = new int[s.noGrades];
		for (int i = 0; i < s.noGrades; i++) {
			f >> s.grades[i];
		}
	}

	return f;
}
int main() {
	//serializare//deserializare
	int* grades = new int[3];
	grades[0] = 10;
	grades[1] = 10;
	grades[2] = 10;

	Student s("Mada", 21, grades, 3);//1000111100
	//cout << s;
	s.serialize();
	cout << "\nWriting file..." << endl;
	Student s2;
	cout << s2;
	cout << "\nReading file..." << endl;
	s2.deserialize();
	cout << s2;
	//deserializare(s);

	string filename="Students.txt";

	ofstream f(filename, ios::out);
	//f >> s;
	Student s3;

	cout << "\nWriting file..." << endl;
	f << s2;
	f.close();

	ifstream g(filename, ios::in);

	cout << "\nReading file..." << endl;
	g >>s3;
	cout <<s3;
	delete[] grades;
	return 0;
}