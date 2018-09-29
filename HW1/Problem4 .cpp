//Alecia Griffin collaborated with Laura Morgan

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {

	int i = 0;
	int longestline = 0;
	string line;
	string longLine;

	ifstream myfile ("TextFile.txt"); //opens TextFile
	if (myfile.is_open()) //checks that file has opened correctly 
  	{
	    while (getline(myfile,line)) //reads in the file line by line
	    {
	    	i = line.length(); // sets variable i to the length of the line
	    	if (longestline < line.length()) //if variable longestLine is shorter than the length of the
	    									 //current line, sets longestLine to length of current line
	    	{
	    		longestline = line.length();
	    		longLine = line; //stores the line to be printed later
	    	}
   		}	
   		cout << longLine; //prints out the longest line
   		
    myfile.close(); //closes file
  }

  else cout << "File reading unsucessful"; //if file does not open correctly, gives an error message

  return 0;
}

