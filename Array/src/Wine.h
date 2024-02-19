#pragma once
#include "../Arr/Array.h"
#include "stdio.h"
#include "string"

using ARR::Array;
typedef Array<int> ArrInt;

class Wine {
private:
	enum{Months = 2};
	std::string title_wine;
	ArrInt bottles_count = ArrInt(Months);
public:
	Wine(const std::string& str);
	void getBottles();
	void showSum();
};