/*
 * main.cpp
 *
 */
#include "songsearch.h"

int main(int argc, char *argv[])
{
	string filename;
	SongSearch songsearch;

	if (argc == 2) { // if there is a filename on the command line
		songsearch.read_lyrics(argv[1],true);
	}
	else { // use a pre-defined filename
		filename = "../rick_db.txt";
		//filename = "lyrics_fulldb.txt";
	        songsearch.read_lyrics(filename.c_str(),true);
	}
        songsearch.search();

        return 0;
}
