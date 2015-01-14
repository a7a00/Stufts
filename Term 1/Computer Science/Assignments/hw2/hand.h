#ifndef __hand_h__
#define __hand_h__

#include "card.h"
#include "List_linked_list.h"

class Hand {
public:
	enum poker_hands {HIGH,PAIR,TWO_PAIR,THREE_KIND,STRAIGHT,FLUSH,
		FULL_HOUSE,FOUR_KIND,STRAIGHT_FLUSH};

	Hand(); // constructor
	~Hand(); // desctructor
	void order_hand_by_suit();
	void order_hand_by_rank();
	void print_hand(){ hand.print_list(); }
	void print_hand_int() { hand.print_list_int(); }
	void add_card(Card c);

	bool remove_card(Card c); // returns true if the card was successfully
				// removed, false otherwise
	void shuffle();
	Card deal_card_from_top(Hand &h);
	Card deal_card_from_bottom(Hand &h);

	bool has_card(Card c);
	void create_deck();
	void read_deck();
	int cards_in_hand() { return hand.cards_in_hand(); }

	bool four_of_a_kind();
	bool flush();
	bool straight();
	bool full_house();
	bool three_of_a_kind();
	bool two_pair();
	bool pair();
	poker_hands poker_hand();
	std::string poker_hand_str();

private:
	void bucket_cards(int *buckets);
	List_linked_list hand;
};

#endif // __hand_h__
