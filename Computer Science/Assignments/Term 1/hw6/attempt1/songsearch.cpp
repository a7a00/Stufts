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
}

SongSearch::~SongSearch()
{
	delete songs;
	delete matches;
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
string SongSearch::alpha_only(string s)
{
        ostringstream ss;
        for (size_t i=0;i<s.length();i++)
	{
                if (isalnum(s[i]))
		{
                        ss << (char)(tolower(s[i]));
                }
        }
        return ss.str();
}

void SongSearch::search()
{
	//read in words
	string word;
	cin >> word;
	word = alpha_only(word);
	//search each song and copy it over if there's a match
	for(int i = 0; i < (int)(songs->size()); i++)
	{
		search_lyrics(word, songs->at(i));
		//if(songs[i].count > 0) copy(song[i]);
	}
	//We now sort the array of matches with a selection sort
	//We terminate it ater the 10 largest elements have been found.
	if(matches->size() == 0) //If there's nothing in the matches list, we can just leave.
	{
		cout << "No results found!";
		return;
	}
	int swap = 0;
	int count = 1; //Starting at 1 because we know there's at lest 1 match
	int i = 0; //Array index we're on
	while(count < 10) //This is a simple selection sort algorithm
	//To save time, we terminate it after we've found the 10 unique songs with the highest counts
	{
		swap = i;
		for(int j = i+1; j < (int)(matches->size()); j++)
		{
			if(matches->at(j).count > matches->at(swap).count)
			{
				swap = j;
			}
		}
		Song tmp = matches->at(swap);
		matches->at(swap) = matches->at(i);
		matches->at(i) = tmp;
		i++;
		if(matches->at(i).title != matches->at(i-1).title || matches->at(i).artist != matches->at(i-1).artist)
		{
			count++; //We know there's a different song.
		}
	}
	//Go through and print the songs
	for(int i = 0; i < (int)(matches->size()); i++)
	{
		print_song(matches->at(i));
	}
	cout << "<END-OF-REPORT>\n";
}

void SongSearch::copy(Song song, int index)
{
	Song newSong;
	newSong.title = song.title;
	newSong.artist = song.artist;
	newSong.lyrics = get_context(song.lyrics, index);
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
		if(spaces == 11) //Words = spaces-1
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
		if(spaces == 10)
		{
			len = i;
			break;
		}
		//closeToEnd = true;
	}
	return lyrics.substr(from, len);
}

int SongSearch::find_match(string s, char c) //Finds the index of the last occurence of a character in a string
{
	for(int i = s.length()-1; i >= 0; i--)
	{
		if(s[i] == c) return i;
	}
	return -1;
}

void SongSearch::search_lyrics(string pattern, Song song)
{
	pattern = " " + pattern;
	pattern += " "; //This prevents us from picking up partial searches.
	//HERE THERE BE DRAGONS
	int patternPointer = pattern.length() - 1;
	int stringPointer = pattern.length() -1;
	int MAX = song.lyrics.length();
	int extra = 0;
	while(stringPointer < MAX)
	{
		if(pattern[patternPointer] != song.lyrics[stringPointer])
		{
			extra = 0; //Reset this because we're at the end of the word.
			if(find_match(pattern, song.lyrics[stringPointer]) == -1) //If the string character isn't in the pattern
			{
				patternPointer = pattern.length() - 1; //Just shift the whole pattern over
				stringPointer += pattern.length();
				if(stringPointer >= MAX) break; //Prevents out of bounds segfaults
			}
			else //Otherwise, move it so the last match in the pattern lines up with the character in the string.
			{
				patternPointer = pattern.length() - 1;
				stringPointer += (pattern.length()-(find_match(pattern, song.lyrics[stringPointer])));
				stringPointer -= 1;
				stringPointer += extra;
				if(stringPointer >= MAX) break; //Prevents out of bounds segfaults
			}
		}
		else //If the characters match, we  just need to shift the  pointer back before checking again.
		{
			extra++; //We'll be able to move forward farther by this amount if it turns out not to be a match.
			if(extra == (int)(pattern.length()/*-1*/)) //If we're all the way back at the beginning of the pattern, it's obviously been found.
			{
				copy(song, (int)((stringPointer+extra-pattern.length())/*+1*/));
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

void SongSearch::print_song(Song song)
{
	cout << "Title: " << song.title << "\nArtist: " << song.artist << "\nContext: " << song.lyrics << "\n\n";
}
