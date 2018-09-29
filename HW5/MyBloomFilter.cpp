#include "MyBloomFilter.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

MyBloomFilter::MyBloomFilter(int len): BloomFilter(len) {

	int counter = 0;
	while (counter != length) {
		my_filter.push_back(0);
		counter++;
	}
	
}


void MyBloomFilter::insert(string item) {

	int x = hash1(item);
	my_filter[x] = 1;
	int y = hash2(item);
	my_filter[y] = 1;

}

int MyBloomFilter::hash1 (string item) {

	int hashVal = 0;
	for (int i = 0; i < item.length(); i++) {
		hashVal = (hashVal * 131) + item[i];
	}
	return hashVal % length;
}

int MyBloomFilter::hash2(string item) {
	int hashVal = 0;

	for(int i = 0; i < item.length(); i++){
		hashVal = (37*hashVal) +item[i];
	}

	return hashVal % length;

}
bool MyBloomFilter::exists(string item) {

	int x = hash1(item);
	int y = hash2(item);

	if (my_filter[x] == 1 && my_filter[y] == 1) {
		return true;
	} else {
		return false;
	}

}

string MyBloomFilter::output() {

	string s;
	for (int i = 0; i < length; i++) {
		if(my_filter[i] == 0) {
			s += "0";
		} else if (my_filter[i] == 1) {
			s += "1";
		}
		s += " ";
	}

	// has to return string
	return s;

	
}
