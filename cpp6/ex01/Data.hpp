#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>

class Data
{
	 public:
		Data();
		~Data();
		Data (const Data &copy);
		Data &operator=(const Data&);
	private:
		std::string name;
};

#endif
