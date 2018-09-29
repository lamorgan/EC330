//Alecia Griffin collaborated with Laura Morgan
#include <iostream>
#include <vector>

using namespace std;

void MaxIncSeq (int *nums, int len)
{ //vector stores input array
	vector<int> arrNums;


	for (int i = 0; i < len; i++) //iterate through vector to store input array
	{
		arrNums.push_back(nums[i]);
	}
  
  //makes a vector of vectors to store the different subsequences found in the sequence
  vector < vector<int> > vecNums(arrNums.size());

  // initializes the frist element to be the first element in the vector of vectors
  vecNums[0].push_back(arrNums[0]);
  
  	// iterates through the vector
	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arrNums[i] > arrNums[j] && (vecNums[i].size() < vecNums[j].size()+1)) // compares the values in the integer vector and compares the sizes in the vector of vectors
			{
        int isum = 0;
        int jsum = 0;
        
        for (auto val : vecNums[i]) { // had to sum up the totals for the subsequences that are the same length
          isum = val;
        }
        for (auto val : vecNums[j]) { // summing up the other subsequences that is the same length
          jsum = val;
        }
        if (isum > jsum) { // finds the subsequence that has the greatest total
			    vecNums[j] = vecNums[i];
        }	else {
          vecNums[i] = vecNums[j];
        }		
			}

		}
		vecNums[i].push_back(arrNums[i]); // places that value into the vector of vectos
	}

	// prints out the longest subsequence
  vector<int> m = vecNums[0];
  
  for (vector<int> x : vecNums)
    if(x.size() > m.size())
      m = x;
      
  for (int i : m)
    cout << i << " ";
    
  cout << '\n';
	


}