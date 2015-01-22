#include<iostream>
#include "songsearch.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "Starting Testing\n";
	SongSearch test;
	cout << "Testing read_lyrics()...";
	//string filename = "rick_db.txt";
	if(argc == 1)
	{
		cout << "Give me a file to work with!";
		return 0;
	}
	test.read_lyrics(argv[1], true);
	cout << "Done.\nAttempting printing:\n";
	for (int i=0; i < (int)(test.songs->size()); i++)
	{
    		test.print_song(test.songs->at(i));
	}
	cout << "Testing alpha_only(). String \"AaBbCcDd1234!,?\"\'.\" should become \"aabbccdd1234\"\n";
	cout << "Output: " << test.alpha_only("AaBbCcDd1234!,?\"\'.") << "\n";
	cout << "Testing copy() by copying the first song in the array over. Test index is 20.\n";
	test.copy(test.songs->at(0), 20);
	test.print_song(test.songs->at(0));
	test.print_song(test.matches->at(0));
	cout << "Problems with the preceding test may have come from either copy() or get_context()\n";
	cout << "Testing search_lyrics():\n";
	cout << "Search String: " << test.songs->at(2).lyrics << "\n" << "Pattern: missing\n";
	test.search_lyrics("missing", test.songs->at(2));
	cout << "Done with testing!\n";
	return 0;
}
