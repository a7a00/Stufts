#include <iostream>
#include <cstdlib>
#include <time.h>

#include "hand.h"


int main(int argc, char **argv)
{
	Hand deck, deck2, hand1, hand2;

	deck.create_deck();
	//deck.read_deck();
	deck.print_hand();

	Card c('3','H');

	//deck.remove_card(c);

	deck.shuffle();
	deck.print_hand_int();

	for (int i=0;i<5;i++) {
		deck.deal_card_from_top(hand1);
		deck.deal_card_from_top(hand2);
	}
	hand1.order_hand_by_suit();
	hand2.order_hand_by_suit();
	deck.print_hand();
	hand1.print_hand();
	hand2.print_hand();

	return 0;
}
