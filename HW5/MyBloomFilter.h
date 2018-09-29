#ifndef MyBloomFilter_h
#define MyBloomFilter_h

#include "BloomFilter.h"
#include <string>
#include <vector>

using namespace std;

class MyBloomFilter : public BloomFilter{
public:
	MyBloomFilter (int len);
	void insert(string item);
	bool exists(string item);
	string output();
	int hash1(string item);
	int hash2(string item);
	vector<bool> my_filter;
};

#endif
