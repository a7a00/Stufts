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
		songs.push_back(song);
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
	for(int i = 0; i < songs.size(); i++)
	{
		search_lyrics(word, songs[i];)
		//if(songs[i].count > 0) copy(song[i]);
	}
	//We now sort the array of matches with a selection sort
	//We terminate it ater the 10 largest elements have been found.
	if(matches.size() == 0) //If there's nothing in the matches list, we can just leave.
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
		for(int j = i+1; j < matches.size(); j++)
		{
			if(matches[j].count > matches[swap].count)
			{
				swap = j;
			}
		}
		Song tmp = matches[swap];
		matches[swap] = matches[i];
		matches[i] = tmp;
		i++;
		if(matches[i].title != matches[i-1].title || matches[i].artist != matches[i-1].artist)
		{
			count++; //We know there's a different song.
		}
	}
	//Go through and print the songs
	for(int i = 0; i < matches.size(); i++)
	{
		print_song(matches[i]);
	}
	cout << "<END-OF-REPORT>\n";
}

void SongSearch::copy(Song song, int index)
{
	Song newSong;
	newSong.title = song.title;
	newSong.artist = song.artist;
	newSong.lyrics = get_context(song.lyrics, index);
	matches.push_back(newSong);
}

string SongSearch::getcontext(string lyrics, int index)
{
	//bool closeToBeginning = false;
	//bool closeToEnd = false;
	int spaces = 0;
	int from = 0; //Safety values, guaranteed not to segfault
	int len = lyrics.length();
	for(int i = index; i > 0; i--) //Walk backwards through the loop
	//If we see a certain amount of spaces before the loop, we know we can grap with impunity.
	{
		if(lyrics[i] == " ") spaces++;
		if(spaces == 11) //Words = spaces-1
		{
			from = i;
			break;
		}
		//closeToBeginning = true; //We'll only hit this line if there aren't enough spaces
	}
	spaces = 0;
	for(int i = index; i < lyrics.length(); i++) //Same going forwards
	{
		if(lyrics[i] == " ") spaces++;
		if(spaces == 10)
		{
			to = i;
			break;
		}
		//closeToEnd = true;
	}
	return lyrics.substr(from, len);
}

string SongSearch::search_lyrics(string pattern, Song song)
{
	pattern = " " + pattern;
	pattern += " "; //This prevents us from picking up partial searches.
	//TODO: THIS. HERE THERE BE DRAGONS
}

void print_song(Song song)
{
	cout << "Title: " << song.title << "\nArtist: " << song.artist << "\nContext: " << song.lyrics << "\n\n";
}
