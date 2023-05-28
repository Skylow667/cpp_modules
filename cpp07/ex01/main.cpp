#include "iter.hpp"
#include <cctype>
#include <exception>
#include <iostream>

template <typename T>
void    increment(T &nu){
    nu++;
}

void    toLowercase(std::string &str){
    for (int i = 0; str[i]; i++){
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
        }
    }
}

int    main(void)
{
    {
		try {
			int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
			std::cout << "initiale : ";
			for (int i = 0; i < 9; i++){
				std::cout << array[i]  << " ; ";
			}
			std::cout << std::endl;
			iter(array, 8, &increment<int>);
			std::cout << "after iter : ";
			for (int i = 0; i < 9; i++){
				std::cout << array[i]  << " ; ";
			}
			std::cout << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
    }
    {
		try {
			std::string strs[7] = {"aBon", "Bon", "Cuit", "Druide" , "etoile", "FOIRE", "glObe"};
			std::cout << "initiale : ";
			for (int i = 0; i < 7; i++){
				std::cout << strs[i]  << " ; ";
			}
			std::cout << std::endl;
			iter(strs, 7, &toLowercase);
			std::cout << "after iter : ";
			for (int i = 0; i < 7; i++){
				std::cout << strs[i]  << " ; ";
			}
			std::cout << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
    }
	{
		try {
			std::string strs[7] = {"aBon", "Bon", "Cuit", "Druide" , "etoile", "FOIRE", "glObe"};
			std::cout << "initiale : ";
			for (int i = 0; i < 7; i++){
				std::cout << strs[i]  << " ; ";
			}
			std::cout << std::endl;
			iter(strs, 10, &toLowercase);
			std::cout << "after iter : ";
			for (int i = 0; i < 7; i++){
				std::cout << strs[i]  << " ; ";
			}
			std::cout << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
    return (0);
}
