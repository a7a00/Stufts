//
//  read_lyrics.h
//  Reads in lyrics from a database, given the filename
//

#ifndef __read_lyrics__
#define __read_lyrics__

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// read the lyrics from a file
void read_lyrics(char * filename, bool show_progress );

// convert a string to lowercase and without punctuation
string alpha_only(string s);

#endif
