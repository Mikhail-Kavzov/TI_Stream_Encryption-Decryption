#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
namespace LFSR {
	const int RegLength = 35;
	const int ReadLen = 8;
	const int buf = 4096;

	typedef unsigned long long udlong;
	udlong shift = 255;
	const udlong ReadPosBytes = shift << RegLength;
	const udlong one = 1;
	const int nm = 100;

	
	std::vector<udlong> mcoefs = { RegLength,2 };
	std::vector<wchar_t> onezero = { L'0',L'1' };
	
}