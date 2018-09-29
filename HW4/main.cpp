// Laura Morgan

// my function works because it goes through and places all of the bits (either a 0 or 1) that findBit gives into an array that I then convert into
// a decimal number. After the decimal number is found then i add that number to the sum variable to find the total sum of all the elements in the array
// that was given to us. After finding the sum of the given array I compare that to the sum that the array should be based on the length of the array.
// For example if the length of the array given is 5 then the sum should be 5+4+3+2+1=15. 
// When I subtract the sum of the given array from what the sum should be it gives the value of the missing number in the array.
//
// I think my function has a runtime of O(n) because it iterates through the lenght of n which gives O(n) in the first for loop but in the rest of
// the for loop it only iterates up to a constant number so the runtime would be a constant so in the end the only value that I care about would by 
// O(n).


#include <iostream>
#include <math.h>

#include "InputArray.h"

using namespace std;


int main() {

  InputArray my_num;
  int length = my_num.n;    // gets the length of the array

  int my_array[32];         // initializes the array that the biary value will be placed in
  int num = 0;
  int exp = 0;
  int sum = 0;              // sum of what the array should be based on the length
  int array_sum = 0;        // sum of the array that we are given
  int missing_num;

  for (int z=0; z<length; z++) {          // iterates through the length of the given array so this is O(n)
    for(int i=31; i>=0; i--){             // iterates through 31 times to get all of the 32 bits of one element of the array so -- O(constant)
      my_array[i] = my_num.findBit(z,i);  // calls the findBit function to get if the bit is 0 or 1 and puts that into my_array
    }
    for(int j = 0; j < 32; j++) {         // iterates through the 32 bits to convert binary value to decimal so -- O(constant)
      exp = 0;          
      int k = j;
      if(my_array[j] % 10 == 1) {         // determines if the bit is a zero or a one
          exp = 1;
          for(k; k > 0; k--){             // if the bit is a one it multiplies the index to the power of two
            exp = exp * 2; 
          }
      }
      num = num + exp;                    // keeps adding up the individual power of two values to get the decimal number
    }
    array_sum = array_sum + num;          // the conversion is complete here and the sum of the array that was given can be calculated
    num = 0;                              // by adding the decimal numbers together
  }

  for (int j=1; j<=length; j++ ) {        // this loop goes through n times to find what the sum of the array should be based on the given length
    sum = sum + j;
  }

  missing_num = sum - array_sum;          // when the array_sum is subtracted from sum it gives the value that is missing from the array

  cout << missing_num << '\n';


}