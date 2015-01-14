/*
 * main.cpp
 *
 */
#include "WordList.h"

int main(int argc, char *argv[])
{
	string filename;
	WordList wordlist;

	if (argc == 2) { // if there is a filename on the command line
		wordlist.read_lyrics(argv[1],true);
	}
	else { // use a pre-defined filename
		filename = "rick_db.txt";
		//filename = "lyrics_fulldb.txt";
	        wordlist.read_lyrics(filename.c_str(),true);
	}
        wordlist.search();

        return 0;
}
