#include <iostream>
#include "Song.h"

using namespace std;

Song::Song(string thistitle, string thisartist)
{
	title = thistitle;
	artist = thisartist;
	count = 0;
}

Song::~Song()
{
	//Nothing to be done
}

void Song::addLyrics(int from, int to) //This method is an emergency backup in case read_lyrics
//ends up not working
{
	cout << "You are using a deprecated method! Stop!\n";
	//Don't get rid of this method. (I don't trust cin...)
}
