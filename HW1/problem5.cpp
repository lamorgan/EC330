// Laura Morgan collaborated with Alecia Griffin

// Algorithm
// Get input from user
// Error check to see if less than or equal to 7
// create a 10x10 grid of "_"
// insert x's and o's based on algorithm
// for x's: start at (0,0) and goes up to input n
//          follow pattern of (n,n) (n,n+1)
// for o's: the pattern is different for evens and zero vs odds
//          using remainders find if input n is even or odd
//          for even inputs and 0: there is only o
//                                 follows pattern of (n+1,n+1)
//          for odd inputs: there are two o's
//                          follows pattern of (n+2,n) and (n+2,n+2)
// changes only those specific coordinates on the grid to either an x or o
// Prints the grid with the x's and o's in the correct spot        


// start of the code
#include <iostream>
using namespace std;

int main() {
  
  // gets the number from input
  int num;
  cin >> num;
  
  // makes sure input is <=7
  if(num > 7) 
  {
    cout << "not a valid input" << '\n';
  } else {
  cout << '\n';
  
  // creates a 10x10 grid of characters
  char grid [10][10];

  //initializes the grid so that all characters are '_'
  for (int i = 0; i < 10; ++i)
  {
    for(int j = 0; j < 10; ++j)
		{
      grid[j][i] = '_';
		}
  }
  // places the x's into the grid
  for(int n = 0; n <= num; ++n)
  {
    grid[n][n] = 'x';
    grid[n][n+1] = 'x';
  }
  
  // places the o's onto the grid
  // for even numbers and zero...
  if (num % 2 == 0 || num == 0) 
  {
    grid[num+1][num+1] = 'o';
  } else { // for odd numbers
    grid[num+2][num] = 'o';
    grid[num+2][num+2] = 'o';
  }
  
  // prints out the grid of characters
  for (int i = 9; i >= 0; --i)
  {
    for(int j = 0; j < 10; ++j)
		{
      cout << grid[j][i];
      cout << ' ';
		}
		cout << '\n';
  }

  cout << endl;

    return 0;
}
}