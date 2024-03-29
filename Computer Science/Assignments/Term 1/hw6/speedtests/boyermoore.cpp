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
	//string searchstring = "Friendship is Magic!";
	//string pattern = "riendship is M";

	string searchstring = "You know I've been so lonely every night since you went away Would you let me down time any night is that the way you're made girl ? I keep telling myself it's alright even though I cry There's no question why how could I be happy when - My arms keep missing you who's been kissing you since you went away ? My arms keep missing you I keep wishing you'd come back today. You said you wouldn't hurt me any way and I believed in you We said we'd trust each other every day we'd never be untrue. But I keep thinking you're telling lies even though I try There's no question why how can I be happy when - My arms keep missing you who's been kissing you since you went away ? . . . You know I've been so lonely every night since you went away . . . My arms keep missing you who's been kissing you since you went away ? . . . My arms keep missing you who's been kissing you since you went away ? . . .";
	string pattern = " time ";

	int patternPointer = pattern.length() - 1;
	int stringPointer = pattern.length() -1;
	int MAX = searchstring.length();
	int extra = 0;
	while(stringPointer < MAX)
	{
		if(stringPointer == 77)
		{
			cout << "765443!";
		}
		if(pattern[patternPointer] != searchstring[stringPointer])
		{
			extra = 0; //Reset this because we're at the end of the word.
			//TODO This causes line 76 to have no effect. I'll bet you anything that's why this thing is breaking.
			if(find_match(pattern, searchstring[stringPointer]) == -1) //If the string character isn't in the pattern
			{
				//extra = 0;
				patternPointer = pattern.length() - 1; //Just shift the whole pattern over
				stringPointer += pattern.length();
				if(stringPointer >= MAX) break; //Prevents out of bounds segfaults
			}
			else //Otherwise, move it so the last match in the pattern lines up with the character in the string.
			{
				patternPointer = pattern.length() - 1;
				stringPointer += (pattern.length()-(find_match(pattern, searchstring[stringPointer])));
				stringPointer -= 1;
				stringPointer += extra;
				//extra = 0;
				if(stringPointer >= MAX) break; //Prevents out of bounds segfaults
			}
		}
		else //If the characters match, we  just need to shift the  pointer back before checking again.
		{
			extra++; //We'll be able to move forward farther by this amount if it turns out not to be a match.
			if(extra == (pattern.length()/*-1*/)) //If we're all the way back at the beginning of the pattern, it's obviously been found.
			{
				//REMEMBER TO CALL COPY IN THE ACTUAL METHOD
				//cout << "Match found at index " << (stringPointer-pattern.length())+1 << "!\n";
				cout << "Match found at index " << (int)((stringPointer+extra-pattern.length())/*+1*/) << "!\n";
				//Since we increment extra every time, we know how many times we moved the pointer back!
				//We can then just add extra to cancel out the backwards moves and jump to the end of the pattern!
				//Alex, yuo of genious!
				patternPointer = pattern.length() - 1;
				stringPointer += pattern.length();
				if(stringPointer >= MAX) break; //Prevents out of bounds segfaults
			}
			else //Otherwise, just shift the pointer.
			{
				patternPointer--;
				stringPointer--;
			}
		}
	}
}
