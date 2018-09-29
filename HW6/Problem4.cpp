// Collaborated with Alecia Griffin

using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

int fourA(){
	char c;
	int id_count = 0;
	ifstream openfile ("BigData.txt");
	if(openfile.is_open()) {		// checks if the file is open

	 	while (!openfile.eof()) {	// iterates through the file until it reaches the end
	 		openfile.get(c);	// gets the character
	 		if (c == 'U') {		// checks to see if the character is a U
	 			openfile.get(c);	// gets the next character
	 			int id_num = 0;		// keeps track of the number of digits
	 			int id_sum = 0;		// keeps track of the sum of the digits
	 			while(c >= 48 && c <= 57) {		// 48 is the ascii value for 0 57 is the ascii value for 9
	 				id_num++;		// increments
	 				id_sum = id_sum + (c-48);	// adds to the sum
	 				openfile.get(c);	// gets next character
	 			}
	 			if (id_num == 8) {	// if there are digits
	 				if(id_sum >= 31 && id_sum <= 68) {	// checks the sum
	 					id_count++;	// increments id count
	 				}
	 			}
	 		}
	 	}
	} else {
		cout << "error: file not open" << '\n';
	}
	return id_count; 
}
	// class for our trie
	class Node{
	public:
		Node();
		~Node();
		void setContent(char c) { content = c; }
    	Node* findChild(char c);
    	void addChild(Node* child) { children.push_back(child); }
    	void setEnd() { isEnd = true; }
    	bool checkEnd() { return isEnd; }

	private:
		char content;
		bool isEnd;
		vector<Node*> children;
	};

	class Trie{
	public:
	    Trie();
	    ~Trie();
	    void addWord(string s);
	    bool searchWord(string s);
	    void deleteWord(string s);
	private:
	    Node* root;
	};

	Node::Node()
	{

	}

	Trie::Trie()
	{
		root = new Node();
	}

	Trie::~Trie()
	{

	}

	// function that finds if the node has a child
	Node* Node::findChild(char c)
	{
		for (int i = 0; i < children.size(); i++)
		{
			Node* ptr = children[i];
			if (ptr->content == c)
			{
				return ptr;
			}
		}
	}
	// adds the words to the trie
	void Trie::addWord(string s)
	{
		Node* currNode = root;

		if(s.length() == 0)
    	{
        	currNode->setEnd(); //an empty word
        	return;
   		}

   		for(int i = 0; i < s.length(); i++)
   		{
   			Node* newNode = currNode->findChild(s[i]);

   			if(i == s.length()-1)
	        {
	        	currNode->setEnd();	//at the end of the trie	
	   		}

   			if (newNode != NULL)
   			{
   				currNode = newNode; //adds new node to end to add word to 
   			}
   			else //if currNode has a child, stores the letter from currNode into the child and adds another letter
   			{
            	Node* tmp = new Node();
            	tmp->setContent(s[i]);
            	currNode->addChild(tmp);
            	currNode = tmp;
	        }

	        
	   	}

	}
	
	// searches the trie to see if there is a word
	bool Trie::searchWord(string s)
	{
		Node* currNode = root;

	    while (currNode != NULL)
	    {
	        for ( int i = 0; i < s.length(); i++ )
	        {
	            Node* tmp = currNode->findChild(s[i]);
	            
	            if (tmp == NULL)
	                return 1;

	            currNode = tmp;
	        }

	        if (currNode->checkEnd()) //if it is at the end of the trie
	            return true;
	        else					  //not at the end of the trie
	            return false;
	    }

	    if (currNode == NULL)
	    {
	    	return false;
	    }
	}
	
// function to find substrings in the string
int countWords(string s, Trie dictionary)
{
	string substring;
	int count = 0; 

	for (int i = 1; i < s.length(); i++)
	{
		for (int j = 0; j < s.length()- i +1 ; j++)
		{
			substring = s.substr(j,i);

			if (substring[0]!= 'l')
			{
				count += dictionary.searchWord(substring);
			}

		}
	}

	return count;

}


int fourB()
{
	int count = 0;

  	ifstream data("BigData.txt"); //opens BigData
  	ifstream dict("Dictionary.txt"); //opens Dictionary

  	string myWord; 

  	Trie dictionary; //creates a Trie to store dictionary words in 

  	if(dict.is_open()) //insert dictionary words into Trie
  	{
    	while(getline(dict,myWord)) 
    	{
    	  dictionary.addWord(myWord); //adds each dictionary word into Trie
    	}

    	dict.close();
  	}
    
    string newWord;
  	
 	while (data >> newWord) 
 	{
    	count += countWords(newWord, dictionary);
  	}
  
  	return count;
	
}

string fourC(){
	ifstream openfile ("BigData.txt");
	if(openfile.is_open()) {
	 	string line;
	 	getline(openfile,line);
	 	string s = line;
		signed int i=1;
 		signed int k=0;
 		int ml=0;
 		int mi=0;
 		bool f=0;

		while(i<s.length()) {
    		if(s[i]!=s[i+1]) {
        		for(k=1;;k++) {
               		if(!(s[i-k]==s[i+k] && (i-k)>=0 && (i+k)<s.length())) {               
                    	break;
                	}   
            		else if(ml < k) {
                    ml=k;
                    mi=i;
                    f=1;
                	}
            	}
    		}   
			i++;
		}

		i=0;

		while(i<s.length()) {
    		if(s[i]==s[i+1]) {
         		for(k=1;;k++) {
                	if(!(s[i-k]==s[k+1+i] && (i-k)>=0 && (k+i)<s.length())) {
                    	break;
                	}
                	else if(ml < k){
               			ml=k;
                    	mi=i;
                	}
            	}                       
    		}
    		i++;
		}

		if(f==0) {
			return s.substr(mi-ml,2*ml+2);
		}
		else {
			return s.substr(mi-ml,2*ml+1);
		}
	} else {
		cout << "error: file not open" << '\n';
	}
}


int main() {

	int num = fourA();

	cout << num << '\n';

	int num2 = fourB();
	cout << num2 << '\n';

	string palin = fourC();
	cout << palin << '\n';
	return 0;
}