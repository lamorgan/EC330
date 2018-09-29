// Laura Morgan


#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

// Given two sequences A and B, finds the longest sequence C such that
// C is a subsequence (not necessarily contiguous) of both A and B
string findMaxSubSeq(string str1, string str2)
{
	// the maximum common subsequence
	//string subseq = "TestSubsequence";
	int m = str1.length();
	int n = str2.length();
	int L[m+1][n+1];
	int i, j;
	int length = 0;

	for (i = 0; i <= m; i++) {
		for(j = 0; j <= n; j++) {
			if(i == 0 || j == 0) {
				L[i][j] = 0;
			} else if(str1[i-1] == str2[j-1]) {
				L[i][j] = L[i-1][j-1] + 1;

			} else {
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			}
		}
	}

	int index = L[m][n];

	char lcs[index+1];
	lcs[index] = '\0';

	i = m;
	j = n;

	while (i > 0 && j > 0) {
		if(str1[i-1] == str2[j-1]) {
			lcs[index - 1] = str1[i - 1];
			i--;
			j--;
			index--;
		}
		else if(L[i-1][j] > L[i][j-1])
			i--;
		else
			j--;
	}

	return lcs;

}

int max(int a, int b) 
{
	return (a > b) ? a : b;
}
// (sample) main to test findMaxSubSeq
// The actual test cases may be different, this file is for demonstration of format only
int main(int argc, char const *argv[])
{
	// example sequences A, B
	//string a = "dynamic";
	//string b = "programming";


	string a(argv[1]);
	string b(argv[2]);


	// TODO: add code to read two inputs, a and b, from the command-line, 
        //    and remove the above sample sequences

	// maximum subsequence in example sequences
	//string maxSubSeq = findMaxSubSeq(a, b);
	string maxSubSeq = findMaxSubSeq(a, b);

	cout << "LCS is: " << maxSubSeq << endl;
	//cout << "Maximum common subsequence for " << a << " and " << b << " : " << maxSubSeq << endl;

	return 0;
}