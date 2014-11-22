#ifndef SONG_H_
#define SONG_H_

class Song
{
public:
	std::string title;
	std::string artist;
	std::string lyrics;
	int count;

	Song(std::string thistitle, std::string thisartist);
	~Song();
	void addLyrics(int from, int to);
}

#endif
