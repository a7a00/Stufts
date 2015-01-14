#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

string alpha_only(string s){
	ostringstream ss;
	for (size_t i=0;i<s.length();i++) {
		if (isalnum(s[i])){
			ss << (char)(tolower(s[i]));
		}
	}
	return ss.str();
}

int main(int argc, char *argv[])
{
	string word;
        ifstream in(argv[1]);                  // creates an input stream
        while ( ! in.eof() )
        {
                while ( in >> word)
		{
			cout << alpha_only(word) << " ";
                }
        }
}
