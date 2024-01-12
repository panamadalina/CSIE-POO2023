#include<iostream>
using namespace std;

//ICLonable
//virtual void clone()=0
//implements  | extends  || copil :parinte
// copil extends 1PArinte impl 2Comportamente/Interfete
// {
// void clone(){
// 
// }
// 
// }
//clone() {
//	///
//}

//meth virt pura
//->interfata
//atribute &/ meth normale (cout,cin)
//-> clasa abstracta


/// <summary>
//atrb &/ meth normale
//->cls normala ( NU ABSTRC)


enum TypePerfume {
	MEN=1,
	WOMEN=2,
	CHILDREN=3
};
class IOrderOnline {
	virtual float getFinalPrice() = 0;
};

class Perfume: public IOrderOnline {
	TypePerfume type;
	char* brand;
	float price;
	bool isOrderedOnline;

public:

	Perfume(const char* brand, float price, bool isOrderedOnline, TypePerfume perfume) {
		this->brand = new char[strlen(brand)+1];
		strcpy(this->brand,brand);
		this->price=price;
		this->isOrderedOnline=isOrderedOnline;
		this->type=perfume;
	}
	~Perfume() {
		if (this->brand != NULL) {
			delete[] this->brand;
			this->brand = nullptr;
		}
	}


	//@Override
	float getFinalPrice() {
		//fa ceva
		if (this->isOrderedOnline) {
			return this->price + 200;
		}
		return this->price;
	}
	Perfume() {
		this->brand = NULL;
		this->price = 0;
		this->isOrderedOnline = false;;
		this->type = TypePerfume::MEN;
	}
	Perfume(const Perfume& p) {
		if (p.brand != NULL) {
			this->brand=new char[strlen(brand) + 1];
			strcpy(this->brand, p.brand);
		}
		else {
			this->brand = NULL;

		}
		this->price = p.price;
		this->isOrderedOnline = p.isOrderedOnline;
		this->type = p.type;
	}

	Perfume& operator=(const Perfume&p) {
		if (p.brand != NULL) {
			if (this->brand != NULL) {
				delete[] this->brand;
				this->brand = nullptr;
			}
			this->brand = new char[strlen(brand) + 1];
			strcpy(this->brand, p.brand);
		}
		else {
			this->brand = NULL;

		}
		this->price = p.price;
		this->isOrderedOnline = p.isOrderedOnline;
		this->type = p.type;
		return *this;

	}
	//virtual void doSmth() = 0;//-> ABSTRACTA
};
//class PerfumeSpring :public Perfume {
//
//	int discount = 20;
//	public:
//
//	void doSmth() {
//		cout << "I am for spring";
//	}
//	PerfumeSpring() {
//		this->discount = 20;
//	}
//
//};

class Collection {

	Perfume* listPerfumes;
	int dim;
	char* name;

	//
public:
	Collection() {
		this->listPerfumes=NULL;
		this->dim = 0;
		this->name = NULL;
	}
	Collection(const char* name, Perfume* list, int nr) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->dim = nr;
		this->listPerfumes = new Perfume[nr];//default construct
		for (int i = 0; i < this->dim; i++) {
			this->listPerfumes[i] = list[i];//op =
		}
	}

	~Collection() {
		if (this->name != NULL) {
			delete[] this->name;
			this->name = nullptr;
		}
		if (this->listPerfumes != NULL) {
			delete[] this->listPerfumes;
		}
	}
};
int main() {
	//Perfume* p=new PerfumeSpring();

	//delete[] p;
	Perfume p1("Dior", 5000,true, TypePerfume::MEN);
	Perfume p2("Chanel", 7000, true, TypePerfume::MEN);
	Perfume p3("Zara", 3000, true, TypePerfume::MEN);

	Perfume* list = new Perfume[3];//default constr
	list[0] = p1;
	list[1] = p2;
	list[2] = p3;



	Collection c("Spring",list, 3);
	return 0;
}