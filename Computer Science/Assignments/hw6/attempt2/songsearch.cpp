//
// songsearch.cpp
//
//   Contains functionality for reading in songs and 
//   Searching them by word.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "songsearch.h"

using namespace std;

SongSearch::SongSearch()
{
	songs = new vector<Song>;
	matches = new vector<Song>;
	sorted_matches = new vector<Song>;
}

SongSearch::~SongSearch()
{
	delete songs;
	delete matches;
	delete sorted_matches;
}

//
// read_lyics 
//   purpose: read in song data from a disk file
//   arguments: the name of the file, bool to ask for progress status
//   returns: nothing
//   does: calls a function each time a word is found
//
void SongSearch::read_lyrics(const char * filename, bool show_progress)
{
	ifstream in(filename);			// creates an input stream
	int song_count = 0;			// for progress indicator
	string artist, title, word;
	// -- While more data to read...
	while ( ! in.eof() ) 
	{
		Song song;
		// -- First line is the artist
		getline(in, artist);
		if (in.fail()) break;
		// -- Second line is the title
		getline(in, title);
		if (in.fail()) break;
		song.title = title;
		song.artist = artist;
		song.lyrics = " "; //A word is only clounted if there are spaces on both sides.
		if ( show_progress )
		{
			song_count++;
			if (song_count % 10000 == 0) {
				cout << "At "       << song_count << 
					" Artist: " << artist     << 
					" Title:"   << title << endl;
			}
			//if(title == "Scotty Doesn't Know") cout << "Scotty Doesn't Know: " << song_count << "\n";
		}
		// -- Then read all words until we hit the 
		// -- special <BREAK> token
		//REMEMBER TO CONVERT TO LOWERCASE
		while ( in >> word && word != "<BREAK>" )
		{
			song.lyrics += word;
			song.lyrics += " ";
		}
		// -- Important: skip the newline left behind
		in.ignore();
		//cout << song.lyrics << "\n" << "----------\n";
		songs->push_back(song);
	}
}

//
// alpha_only
//   purpose: converts a string to lowercase and alphabetic characters
//            only. E.g., "Bang!" becomes "bang"
//   arguments: a string
//   returns: the alpha-only string
//   does: converts the string
//
//Can also convert to all uppercase.
string SongSearch::alpha_only(string s, bool lower)
{
        ostringstream ss;
        for (size_t i=0;i<s.length();i++)
	{
                if (isalnum(s[i]))
		{
                        if(lower) ss << (char)(tolower(s[i]));
			else ss << (char)(toupper(s[i]));
                }
        }
        return ss.str();
}

void SongSearch::search()
{
	while(true)
	{
		//read in words
		string word;
		string word2;
		cin >> word;
		if(word == "<BREAK>") return;
		word = alpha_only(word, true);
		word2 = alpha_only(word, false);
		string word3 = word;
		word3[0] = toupper(word[0]);
		//search each song and copy it over if there's a match
		for(int i = 0; i < (int)(songs->size()); i++)
		{
			search_lyrics(word, songs->at(i));
			search_lyrics(word2, songs->at(i));
			search_lyrics(word3, songs->at(i));
			//if(songs[i].count > 0) copy(song[i]);
		}
		//We now sort the array of matches with a selection sort
		//We terminate it ater the 10 largest elements have been found.
		if(matches->size() == 0) //If there's nothing in the matches list, we can just leave.
		{
			//cout << "No results found!\n";
			cout << "<END OF REPORT>\n";
			continue;
		}
		sortMatches();
		for(int i = 0; i < /*10*/(int)(sorted_matches->size()); i++)
		{
			print_song(sorted_matches->at(i));
		}
		for(int i = 0; i < (int)(songs->size()); i++)
		{
			songs->at(i).count = 0;
		}
		matches->erase(matches->begin(), matches->end());
		sorted_matches->erase(sorted_matches->begin(), sorted_matches->end());
		cout << "<END OF REPORT>\n";
	}
}

void SongSearch::sortMatches()
{
	//cout << "NOW SORTING\n";
	//vector<indexAndFreq>* thisVector = new vector<indexAndFreq>;
	string temp = "";
	//cout << "Building Difference Table\n";
	for(int i = 0; i < 10; i++)
	{
		//cout << i << "\n";
		int max = 0;
		int maxindex = 0;
		//cout << "SIZE OF MATCHES: " << matches->size() << "\n";
		for(int j = (int)(matches->size())-1; j >= 0; j--)
		{
			//cout <<"First Loop\n";
			//cout << "Count: " << matches->at(j).count << "\n";
			if(matches->at(j).count > max)
			{
				//cout << "Max Updated!\n";
				max = matches->at(j).count;
				maxindex = j;
			}
		}
		//cout << "Max: " << max << "\nMax Index: " << maxindex << "\n";
		for(int j = (maxindex-max+1); j <= maxindex; j++)
		{
			//cout << "Second Loop\n";
			sorted_matches->push_back(matches->at(j));
		}
		for(int j = 0; j < max; j++)
		{
			//cout << "Third Loop\n";
			matches->erase(matches->begin()+(maxindex-max+1));
		}
	}
}

void SongSearch::copy(Song song, int index)
{
	Song newSong;
	newSong.title = song.title;
	newSong.artist = song.artist;
	newSong.lyrics = get_context(song.lyrics, index);
	newSong.count = song.count;
	matches->push_back(newSong);
}

string SongSearch::get_context(string lyrics, int index)
{
	//bool closeToBeginning = false;
	//bool closeToEnd = false;
	int spaces = 0;
	int from = 0; //Safety values, guaranteed not to segfault
	int len = lyrics.length();
	for(int i = index; i > 0; i--) //Walk backwards through the string
	//If we see a certain amount of spaces before the loop, we know we can grab with impunity.
	{
		if(lyrics[i] == ' ') spaces++;
		if(spaces == 6) //Words = spaces-1
		{
			from = i;
			break;
		}
		//closeToBeginning = true; //We'll only hit this line if there aren't enough spaces
	}
	spaces = 0;
	for(int i = index; i < (int)(lyrics.length()); i++) //Same going forwards
	{
		if(lyrics[i] == ' ') spaces++;
		if(spaces == 7)
		{
			len = i;
			break;
		}
		//closeToEnd = true;
	}
	return lyrics.substr(from, len-from);
}

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
string SongSearch::lastPositionTable(string pattern)
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
int SongSearch::jumpindex(char search, string pattern, string alreadySearched)
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
string SongSearch::jumpingTable(string pattern)
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

void SongSearch::search_lyrics(string pattern, Song song)
{
	pattern = (char)(17) + pattern; //TODO FIND OUT WHY THIS FIX DOESN'T WORK
	pattern += (char)(17); //This prevents us from picking up partial searches.
	//HERE THERE BE DRAGONS
	string jT = jumpingTable(pattern);
	string lPT = lastPositionTable(pattern);
	int index = 0;
	while(index < (int)(song.lyrics.length()-pattern.length()+1))
	{
		int j = pattern.length();
		//while((j > 0) && (pattern[j-1] == song.lyrics[index+j-1]))
		while((j > 0) && (wildcardmatch(pattern[j-1], song.lyrics[index+j-1])))
		{
			j -= 1;
		}
		if(j <= 0)
		{
			song.count++;
			copy(song, index);
			//cout << index << "\n";
			index++;
		}
		else
		{
 			int lastPosition = lPT[(int)(song.lyrics[index+j-1])];
			if(lastPosition == 0) lastPosition = pattern.length();
			int jump = jT[pattern.length()-j];
			if(lastPosition > jump) index += lastPosition;
			else index += jump;
		}
	}
}

//Allows the wildcard character (ASCII 178) to be matched against punctuation.
bool SongSearch::wildcardmatch(char patternchar, char lyricschar)
{
	//cout << "We're calling this!\n";
	if((int)(patternchar) == 17)
	{
		if((int)(lyricschar) >= 32
			&& (int)(lyricschar) <= 47) //Range for punctuation
		{
			return true;
		}
		else return false;
	}
	else
	{
		return (patternchar == lyricschar);
	}
}

void SongSearch::print_song(Song song)
{
	cout << "Title: " << song.title << "\nArtist: " << song.artist << "\nContext: " << song.lyrics << "\n\n";
}
