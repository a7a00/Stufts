//
//  songsearch.h
//  Reads in lyrics from a database and searches them for a given word
//

#ifndef __songsearch__
#define __songsearch__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
	};
		
	vector<Song>* songs;
	vector<Song>* matches;
	vector<Song>* sorted_matches;

	SongSearch();
	~SongSearch();

	// read the lyrics from a file
	void read_lyrics(const char * filename, bool show_progress );
	
	// convert a string to lowercase and without punctuation
	string alpha_only(string s, bool lower);
	
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
	
	//Creats a "Last Position Table", for use in searching and skipping
	//innessecary characters
	string lastPositionTable(string pattern);
	
	//This function steps backwards through the pattern, and determines how far
	//ahead we can jump based on the position difference between what we've
	//already searched and what we're searching now.
	int jumpindex(char search, string pattern, string alreadySearched);

	//This function builds a "jumping table" that keeps track of how far ahead we
	//can jump at every index that we could land on.
	string jumpingTable(string pattern);
	
	//searches a string for a given pattern and updates that song's info.
	//This needs to call copy whenever it finds a match
	void search_lyrics(string pattern, Song song);

	//Allows the wildcard character (ASCII 178) to be matched against punctuation.
	bool wildcardmatch(char patternchar, char lyricschar);

	//prints information about the song
	void print_song(Song song);
	
	//Sortes the matches by frequency
	void sortMatches();
	
	//Nukes the program and leaves.
	void fullStop();
};
#endif
