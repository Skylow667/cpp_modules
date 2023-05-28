#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdexcept>
#include <iostream>
#include <cstdlib>

template<typename T>
class Array
{
	 private:
		unsigned int _size;
		T *_array;
	 public:
		 Array<T>(){
			_array = new T[0];
			_size = 0;
		 }

		Array<T>(unsigned int n) {
			_array = new T[n];
			_size = n;
		}

		~Array<T>() {
			delete [] _array;
		}

		Array <T>(const Array<T> &copy){
			new(this) Array<T>(copy._size);
			*this = copy;
		}

		Array <T>&operator=(const Array & copy){
			if (&copy != this) {
				this->~Array<T>();
				new(this) Array<T>(copy._size);
			}
			return (*this);
		}

		T & operator[](unsigned int index){
			if (index >= _size)
				throw (std::logic_error("The index send is greater than the length of the array!"));
			return (_array[index]);
		}

		unsigned int size() {
			return (_size);
		}
};

#endif
