#include "Data.hpp"

Data::Data(){
}

Data::~Data(){
}

Data::Data(const Data &copy){
	*this = copy;
}

Data & Data::operator=(const Data &copy){
	if (&copy != this)
	{
		this->~Data();
		new (this)Data();
	}
	return (*this);
}
