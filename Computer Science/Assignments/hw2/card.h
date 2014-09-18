// card.h

// Overview -- A linked list based card game, 
// based on a traditional 52 card deck

#ifndef __card_h__
#define __card_h__

enum Suit {CLUB,DIAMOND,HEART,SPADE};
enum Rank {TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING,ACE};

#define INITIAL_CAPACITY 10

class Card {
public:
	Card(); // constructor
	Card(char r, char s); // constructor
	~Card(); // destructor
	void print_card();
	void print_card_int();
	
	Suit get_suit() { return suit; }
	void set_suit(Suit s) { suit = s; } 
	
	Rank get_rank() { return rank; }
	void set_rank(Rank r) { rank = r; }
	
	bool same_card(Card c);
	int card_int();
private:
	Suit suit;
	Rank rank;
};

#endif // __card_h__

