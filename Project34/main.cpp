#include <iostream>

using namespace std;

class Transport
{
protected:
	char* model;
	double speed;
	double price;
public:
	Transport();
	Transport(const char* model, double speed, double price);
	void Input();
	void Output();
	~Transport();
};


Transport::Transport()
{
	this->model = nullptr;
	this->speed = 0.0;
	this->price = 0.0;
}

Transport::Transport(const char* model, double speed, double price)
{
	cout << "\nTransport construct\n";
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
	this->speed = speed;
	this->price = price;
}

void Transport::Input()
{
	cout << "\nTransport input\n";
	if (this->model != nullptr)
	{
		delete[]this->model;
	}
	cout << "\nEnter model: ";
	this->model = new char[20];
	cin.getline(this->model, 19);
	cout << "\nEnter speed: ";
	cin >> this->speed;
	cout << "\nEnter price: ";
	cin >> this->price;
	cout << endl;
}

void Transport::Output()
{
	cout << "\nTransport output\n";
	cout << "\nModel: " << this->model;
	cout << "\nSpeed: " << this->speed;
	cout << "\nPrice: " << this->price;
	cout << endl;
}

Transport::~Transport()
{
	cout << "\nTransport destructor\n";
	delete[]this->model;
	this->model = nullptr;
}

class Bicycle : public Transport
{
	int countOfWheels;
	double weight;
public:
	Bicycle() = default;
	Bicycle(const char* model, double speed, double price, int countOfWheels, double weight);
	void Output();
	void Input(double price, int countOfWheels);
	~Bicycle();
};

Bicycle::Bicycle(const char* model, double speed, double price, int countOfWheels, double weight) : Transport(model, speed, price)
{
	cout << "\Bicycle constructor\n";
	this->countOfWheels = countOfWheels;
	this->weight = weight;
}

void Bicycle::Output()
{
	Transport::Output();
	cout << "\nBicycle output\n";
	cout << "Count of wheels: " << this->countOfWheels;
	cout << "\nWeight: " << this->weight;
	cout << endl;
}

void Bicycle::Input(double weight, int countOfWheels)
{
	cout << "\nBicycle input\n";
	Transport::Input();
	this->weight = weight;
	this->countOfWheels = countOfWheels;
}

Bicycle::~Bicycle()
{
	cout << "\nBicycle destructor\n";
}

class Track : public Transport
{
	int countOfWheels;
	double carrying; // грузоподъёмность
public:
	Track() = default;
	Track(const char* model, double speed, double price, int countOfWheels, double carrying);
	void Output();
	void Input(int countOfWheels, double carrying);
	~Track();
};

Track::Track(const char* model, double speed, double price, int countOfWheels, double carrying) : Transport(model, speed, price)
{
	cout << "\nTrack construct\n";
	this->countOfWheels = countOfWheels;
	this->carrying = carrying;
}

void Track::Output()
{
	Transport::Output();
	cout << "\nTrack output\n";
	cout << "Count of wheels: " << this->countOfWheels;
	cout << "\nCarrying: " << this->carrying;
	cout << endl;
}

void Track::Input(int countOfWheels, double carrying)
{
	Transport::Input();
	cout << "\nTrack input\n";
	this->countOfWheels = countOfWheels;
	this->carrying = carrying;
}

Track::~Track()
{
	cout << "\nTrack destructor\n";
}

class Fly : public Transport
{
	bool canFly;
	int countOfPassengers;
public:
	Fly() = default;
	Fly(const char* model, double speed, double price, bool canFly, int countOfPassengers);
	void Output();
	void Input(bool canFly, int countOfPassenger);
	~Fly();
};

Fly::Fly(const char* model, double speed, double price, bool canFly, int countOfPassengers) : Transport(model, speed, price)
{
	cout << "\nFly construct\n";
	this->canFly = canFly;
	this->countOfPassengers = countOfPassengers;
}

void Fly::Output()
{
	Transport::Output();
	cout << "\nFly output\n";
	cout << "Can fly: " << this->canFly;
	cout << "\nCount of passengers: " << this->countOfPassengers;
	cout << endl;
}

void Fly::Input(bool canFly, int countOfPassengers)
{
	Transport::Input();
	cout << "\nFly input\n";
	this->canFly = canFly;
	this->countOfPassengers = countOfPassengers;
}

Fly::~Fly()
{
	cout << "\nFly destructor\n";
}

class Ship : Transport
{
	double carrying;
	char* type;
public:
	Ship() = default;
	Ship(const char* model, double speed, double price, double carrying, const char* type);
	void Output();
	void Input(double carrying, const char* type);
	~Ship();
};

Ship::Ship(const char* model, double speed, double price, double carrying, const char* type) : Transport(model, speed, price)
{
	cout << "\nShip construct\n";
	if (this->type != nullptr)
	{
		delete[]this->type;
	}
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
	this->carrying = carrying;
}

void Ship::Output()
{
	Transport::Output();
	cout << "\nShip output\n";
	cout << "Type: " << this->type;
	cout << "\nCarrying: " << this->carrying;
	cout << endl;
}

void Ship::Input(double carrying, const char* type)
{
	Transport::Input();
	cout << "\nShip input\n";
	this->carrying = carrying;
	if (this->type != nullptr)
	{
		delete[]this->type;
	}
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}

Ship::~Ship()
{
	cout << "\nShip destructor\n";
	delete[]this->type;
	this->type = nullptr;
}

int main()
{
	Bicycle obj1("BMW", 20, 20000, 2, 40);
	obj1.Output();

	Track obj2("Audi", 340, 50000, 4, 25000);
	obj2.Output();

	Fly obj3("Mercedes", 500, 100000, true, 250);
	obj3.Output();

	Ship obj4("Renault", 180, 23450, 10000, "Passenger");
	obj4.Output();
}