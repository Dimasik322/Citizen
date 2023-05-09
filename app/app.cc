#include <gtest/gtest.h>

#include <citizen/citizen.h>
#include <conio.h>

using namespace CitizenNamespace;
using namespace std;

int get_key() {
	int key = getch();
	//if ((key == 0) || (key == 224)) key = getch();
	return key;
}



int main() {
	setlocale(LC_ALL, "");



	return 0;
}