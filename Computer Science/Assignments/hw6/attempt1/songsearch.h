//
//  songsearch.h
//  Reads in lyrics from a database and searches them for a given word
//

#ifndef __read_lyrics__
#define __read_lyrics__

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SongSearch
{
public:
	struct Song
	{
		string title;
		string artist;
		string lyrics;
		int count = 0;
	}
	
	vector<Song> songs;
	vector<Song> matches;

	SongSearch();
	~SongSearch();

	// read the lyrics from a file
	void read_lyrics(char * filename, bool show_progress );
	
	// convert a string to lowercase and without punctuation
	string alpha_only(string s);
	
	//Searches the entire database for a prompted word
	void search();
private:
	//copies a song from the main list to the list of matches
	//should call get_context
	void copy(Song song, int index);

	//returns the words surrowunding the selected index by looking for spaces.
	//VALUE PASSED IS THE BEGINNING OF THE WORD
	//ACCOUNT FOR WORDS AT THE BEGINNING AND END
	string get_context(string lyrics, int index);
	
	//Finds the index of the last occurence of a character in a string
	//Used by search_lyrics.
	int SongSearch::find_match(string s, char c)

	//searches a string for a given pattern and updates that song's info.
	//This needs to call copy whenever it finds a match
	void search_lyrics(string pattern, Song song);

	//prints information about the song
	void print_song(Song song);
}
#endif
