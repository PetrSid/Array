#pragma once
#ifndef Array_H_
#define Array_H_

#include <stdio.h>
#include <cstdlib>

namespace ARR
{
	template<class Type>
	class Array
	{
	private:
		Type* arr;
		int size_array;
	public:
		Array() : size_array(0) {};
		Array(int s, int n = 0);
		Array(const Array& ar);
		~Array();

		// metodes funcion;
		void show();
		void ressize(int n);
		void clear_el(int el);
		void bubble_sort();

		int max();
		int min();
		int sum();

		int size();
		int& begin();
		int& back();

		bool isempty();

		void test();

		Array& operator=(const Array& ar);

		virtual Type& operator[](int index);
		virtual Type& operator[](int index) const;
	};

	//****************************************************************

	template<class Type>
	Array<Type>::Array(int s, int n) {
		size_array = s;
		try {
			arr = new Type[size_array];
			for (int i = 0; i < size_array; i++)
				arr[i] = n;
		}
		catch (class std::bad_alloc& ba) {
			printf("%s ", ba.what());
		}
	}
	template<class Type>
	Array<Type>::~Array() {
		for (int i = 0; i < size_array; i++)
			delete[] arr;
	}

	template<class Type>
	Array<Type>::Array(const Array& ar)
	{
		size_array = ar.size_array;
		try {
			arr = new Type[size_array];
			for (int i = 0; i < size_array; i++)
				arr[i] = ar.arr[i];
		}
		catch (class std::bad_alloc& ba) {
			printf("%s ", ba.what());
		}
	}
	template<class Type>
	Array<Type>& Array<Type>::operator=(const Array& ar)
	{
		if (this == &ar)
			return *this;
		delete[] arr;
		size_array = ar.size_array;
		try {
			arr = new Type[size_array];
			for (int i = 0; i < size_array; i++)
				arr[i] = ar.arr[i];
			return *this;
		}
		catch (class std::bad_alloc& ba) {
			printf("%s ", ba.what());
		}
	}
	template<class Type>
	Type& Array<Type>::operator[](int index) {
		if (index >= 0 && index < size_array)
			return arr[index];
		exit(EXIT_FAILURE);
	}

	template<class Type>
	Type& Array<Type>::operator[](int index) const {
		if (index >= 0 && index < size_array)
			return arr[index];
		exit(EXIT_FAILURE);
	}

	template<class Type>
	int Array<Type>::size() { return size_array; }

	template<class Type>
	void Array<Type>::show()
	{
		try {
			if (size_array <= 0)
				throw "Array is Empty";
			else {
				for (int i = 0; i < size_array; i++)
					printf("%d ", arr[i]);
				printf("%\n");
			}
		}
		catch (const char* error) {
			printf("%s", error);
		}
	}
	template<class Type>
	void Array<Type>::ressize(int n) {
		size_array = n;
	}
	template<class Type>
	int Array<Type>::max()
	{
		int max = arr[0];
		for (size_t i = 0; i < size_array; i++) {
			if (max < arr[i])
				max = arr[i];
		}
		return max;
	}
	template<class Type>
	int Array<Type>::min()
	{
		int min = arr[0];
		for (size_t i = 0; i < size_array; i++) {
			if (min > arr[i])
				min = arr[i];
		}
		return min;
	}
	template<class Type>
	int Array<Type>::sum()
	{
		int sum = 0;
		for (size_t i = 0; i < size_array; i++)
			sum += arr[i];
		return sum;
	}
	template<class Type>
	bool Array<Type>::isempty()
	{
		if (size_array <= 0)
			return true;
		else
			return false;
	}
	template<class Type>
	void Array<Type>::clear_el(int el)
	{
		if (size_array > el) {
			for (int i = el; i < size_array - 1; i++)
				arr[i] = arr[i + 1];
			--size_array;
		}
		else
			return;
	}
	template<class Type>
	void Array<Type>::bubble_sort()
	{
		for (int i = 0; i < size_array; i++) {
			for (int j = 0; j < size_array - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	template<class Type>
	int& Array<Type>::begin() { return arr[0]; }

	template<class Type>
	int& Array<Type>::back() { return arr[size_array - 1]; }
}
#endif //!Array_H_