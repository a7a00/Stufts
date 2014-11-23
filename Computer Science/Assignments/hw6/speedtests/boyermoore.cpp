//ALGORITHM
/*if(mismatch)
{
	if(element in string is not in pattern)
	{
		set pointer to end of pattern
		advance by the number of characters in the pattern
	}
	else
	{
		set pointer to end of pattern
		advance (length-index of match) spaces
		advance (extra) spaces
	}
}
else
{
	extra++
	if extra = (patternlength-1)
	{
		it's a match!
		set pointer to end of pattern
		advance by the number of characters in the pattern
	}
	move pointer back one space
}
*/

#include <iostream>

using namespace std;

int find_match(string s, char c) //Finds the index of the last occurence of a caracter in a string
{
	for(int i = s.length()-1; i >= 0; i--)
	{
		if(s[i] == c) return i;
	}
	return -1;
}

int main()
{
	string searchstring = "Friendship is Magic!";
	string pattern = "riendship is M";

	int patternPointer = pattern.length() - 1;
	int stringPointer = pattern.length() -1;
	int MAX = searchstring.length() -1;
	int extra = 0;
	if(pattern[patternPointer] != searchstring[stringPointer])
	{
		extra = 0;
		if(find_match(pattern, searchstring[stringPointer] == -1))
		{
			patternPointer = pattern.length() - 1;
			stringPointer += pattern.length();
			if(stringPointer >= searchstring.length()) return 0; //Prevents out of bounds segfaults
		}
		else
		{
			patternPointer = pattern.length() - 1;
			stringPointer += (pattern.length()-(find_match(pattern, searchstring[stringPointer])));
			stringPointer += extra;
			if(stringPointer >= searchstring.length()) return 0; //Prevents out of bounds segfaults
		}
	}
	else
	{
		extra++;
		if(extra = (pattern.length()-1))
		{
			//REMEMBER TO CALL COPY IN TE ACTUAL METHOD
			cout << "Match found at index " << stringPointer << "!";
			patternPointer = pattern.length() - 1;
			stringPointer += pattern.length();
			if(stringPointer >= searchstring.length()) return 0; //Prevents out of bounds segfaults
		}
		else
		{
			patternPointer--;
			stringPointer--;
		}
	}
}
