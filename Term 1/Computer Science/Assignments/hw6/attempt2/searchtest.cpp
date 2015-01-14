#include <iostream>

using namespace std;

//This function creates a "Last Position Table". By the end of the method,
//the index corresponding to a given character c will contain the index of
//c's final appearance in the pattern. (temporarily cast as a char)
//The reason I'm storing everything as chars in a string is because I
//spent 4 hours in Halligan wrestling with pointers and this is much
//easier because C++ handles pointers and memory allocation for you if you use
//strings.
//
//If there is no occurence of the character in the pattern, its index will
//contain a NULL character, representing index 0.
string lastPositionTable(string pattern)
{
	string lastPositionTable = "";
	for(int i = 0; i < 128; i++) lastPositionTable += (char)(0);
	for(int i = 0; i < (int)(pattern.length()-1); i++)
	{
		lastPositionTable[(int)(pattern[i])] = (pattern.length())-i-1;
	}
	return lastPositionTable;
}

//This function steps backwards through the pattern, and determines how far
//ahead we can jump based on the position difference between what we've
//already searched and what we're searching now.
int jumpindex(char search, string pattern, string alreadySearched)
{
	for(int i = pattern.length(); i >= 1; i--)
	{
        	bool flag = true;
        	for(int j = 0; j < (int)(alreadySearched.length()); j++)
		{
            		int k = i-alreadySearched.length()-1+j;
            		if(!(k < 0) && alreadySearched[j] != pattern[k])
			{
				flag = false;
			}
		}
		signed int term_index = i-alreadySearched.length()-1;
		if(flag)
		{
			if(term_index <= 0 || pattern[term_index-1] != search)
			{
				return (pattern.length()-i+1);
			}
		}
	}
	return -1; 	//Emergency return statement. If the search is working,
			//this should be called rarely, if at all.
}

//This function builds a "jumping table" that keeps track of how far ahead we
//can jump at every index that we could land on.
//
//Again, I'm storing the jumping table in a string because I'm growing to
//despise pointers.
string jumpingTable(string pattern)
{
	string jumpingTable = "";
	for(int i = 0; i < 128; i++) jumpingTable += (char)(0);
	string alreadySearched = "";
	for(int i = 0; i < (int)(pattern.length()); i++)
	{
		jumpingTable[alreadySearched.length()] = jumpindex(pattern[pattern.length()-1-i], pattern, alreadySearched);
		alreadySearched = pattern[pattern.length()-1-i] + alreadySearched;
	}
	return jumpingTable;
}
    
//The search happens here. We basically go forward through the search string
//and find the last index of a character in the pattern. We then use this
//index to jump forward by the larger amount offered to us, either by the
//"last position" rule or the "jumping rule".
void search(string pattern, string searchString)
{
	string jT = jumpingTable(pattern);
	string lPT = lastPositionTable(pattern);
	int index = 0;
	while(index < (int)(searchString.length()-pattern.length()+1))
	{
		int j = pattern.length();
		while((j > 0) && (pattern[j-1] == searchString[index+j-1]))
		{
			j -= 1;
		}
		if(j <= 0)
		{
			//REMEMBER TO CALL COPY IN THE ACTUAL METHOD
			cout << "Match found at index " << index << "!\n";
			index++;
		}
		else
		{
 			int lastPosition = lPT[(int)(searchString[index+j-1])];
			if(lastPosition == 0) lastPosition = pattern.length();
			int jump = jT[pattern.length()-j];
			if(lastPosition > jump) index += lastPosition;
			else index += jump;
		}
	}
}

int main()
{
	string block = "This is a simple example";
	cout << "This is an example search on the string \"" << block << "\".\n";
	cout << "ple : ";
	search("ple ", block);
	cout << "\nexample: ";
	search("example", block);
	cout << "\nsimple: ";
	search("simple", block);
	cout << "\n imple: ";
	search(" imple", block);
	cout << "\nT: ";
	search("T", block);
	cout << "\ns: ";
	search("s", block);
	return 0;
}
