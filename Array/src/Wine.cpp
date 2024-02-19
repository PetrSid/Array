#include "Wine.h"
#include <iostream>

Wine::Wine(const std::string& str) : title_wine(str) {}

void Wine::getBottles()
{
	int bottles = 0;
	printf("Press a count bottles ");
	for (int i = 0; i < bottles_count.size(); i++) {
		try {
			scanf_s("%d", &bottles);
			if (bottles < 0) {
				throw "ERROR: Value is Negative";
			}
		}
		catch (const char* Er) {
			printf("%s", Er);
			continue;
		}
		bottles_count[i] = bottles;
	}
}

void Wine::showSum()
{
	std::cout << "Title Name is " << title_wine << std::endl;
	printf("Bottles is ");
	int sum = bottles_count.sum();
	printf("%d", sum);
}
