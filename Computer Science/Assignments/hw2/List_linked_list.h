#ifndef List_linked_list_h
#define List_linked_list_h

#include <iostream> // for NULL
#include "card.h"

struct Card_Node {
	Card card;
	Card_Node *next;
};

class List_linked_list
{
public:
	List_linked_list(); // constructor
	~List_linked_list();
	// copy constructor
	List_linked_list(const List_linked_list& source);
	// operator= overload
	List_linked_list operator =(const List_linked_list& source);
	
	void print_list();
	void print_list_int();
	bool is_empty() { return head==NULL; }

	// students must write the following functions in the .cpp file
	int cards_in_hand(); // returns the number of cards in the hand
	void make_empty(); // empties the list; head should equal NULL
	
	// inserts a card at the head
	// Should allow insert into an empty list
	void insert_at_head(Card c);

	// inserts a card at the tail (final node)
	// should allow insert into an empty list
	void insert_at_tail(Card c);

	// inserts a card at an index such that
	// all cards following the index will be moved farther
	// down the list by one.
	// The index can be one after the tail of the list
	// I.e., you can insert at index 0 into an empty list,
	// and you can insert at index 4 in a list with 4 nodes.
	// In the first case, the node inserted would become the head
	// In the second case, the node inserted would be inserted
	// after the current tail.
	void insert_at_index(Card c, int index);

	// replaces the card at index
	// A card at index must already exist
	void replace_at_index(Card c, int index);
	
	// returns the card at index.
	// allowed to crash if index is not in the list
	Card card_at(int index);
	
	// returns true if the card is in the list
	// returns false if the card is not in the list
	bool has_card(Card c);
	
	// removes the card from the list
	// Returns true if the card was removed
	// Returns false if the card was not in the list
	bool remove(Card c);

	// Removes the card from the head, and assigns the head
	// to head->next
	// Returns the card that was removed
	// Allowed to fail if list is empty
	Card remove_from_head();

	// Removes the card from the tail
	// Returns the card that was removed
	// Allowed to fail if the list is empty
	Card remove_from_tail();

	// Removes the card from index
	// Returns the card that was removed
	// Allowed to fail if index is beyond the end of the list
	Card remove_from_index(int index);

private:
	Card_Node *head; // the head of the list
};

#endif // List_linked_list_h
