#include <string>
using std::string;

class Car
{
friend class Vehicle; //makes vehicle a f riend of car
public:
	Car(string d) : details(d) {};
	~Car() {} ;

private:
	string details;
};
