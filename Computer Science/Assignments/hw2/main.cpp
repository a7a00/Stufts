#include <iostream>
#include <cstdlib>
#include <time.h>

#include "hand.h"

using namespace std;

int main(int argc, char **argv)
{
	Hand deck, deck2, hand1, hand2;

	cout << "Create a deck:\n";
	deck.create_deck();
	//deck.read_deck();
	deck.print_hand();

	Card c('3','H');

	cout << "Remove the 3 of Hearts:\n";
	deck.remove_card(c); //TODO GODDAMMIT THIS CAUSES A HANG

	cout << "Shuffle the deck:\n";
	deck.shuffle();
	deck.print_hand();
	cout << "Test int printing:\n";
	deck.print_hand_int();

	for (int i=0;i<10;i++) {
		deck.deal_card_from_top(hand1);
		//cout << "Successfully dealt to Hand 1! i is now " << i << ".\n";
		deck.deal_card_from_top(hand2);
		//cout << "Successfully dealt to Hand 2! i is now " << i << ".\n";
	}
	cout << "Dealt cards out!\n";
	cout << "Hand 1:\n";
	hand1.print_hand();
	cout << "Hand 2:\n";
	hand2.print_hand();
	hand1.order_hand_by_suit();
	cout << "Ordered Hand 1 by suit!\n";
	hand2.order_hand_by_suit();
	cout << "Ordered Hand 2 by suit!\n";
	cout << "New Deck:\n";
	deck.print_hand();
	cout << "New Hand 1\n";
	hand1.print_hand();
	cout << "New Hand 2:\n";
	hand2.print_hand();

	return 0;
}
