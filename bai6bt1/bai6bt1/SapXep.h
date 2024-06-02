#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class SapXep
{
private:
	vector<int> pt;
	void swap(int& a, int& b);
public:
	void readFromFile(const string& filename);
	void selectionSort();
	void printData() const;
};

