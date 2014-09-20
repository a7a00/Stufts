#include "List_linked_list.h"

#include <iostream>
#include <cassert>

using namespace std;

List_linked_list::List_linked_list()
{
	head = NULL;
	// hint: in your constructor, you might want to set the head to NULL
}

List_linked_list::~List_linked_list()
{
	// delete list by looping through and deleting each node
	Card_Node * current = head;
	while (current != NULL)
	{
		Card_Node temp = current->next;
		delete current;
		current = temp;
	}
}

// copy constructor
List_linked_list::List_linked_list(const List_linked_list& source) {
	// explicit copy constructor necessary because of cards array
	if (source.head == NULL) return; // nothing to do

	head = new Card_Node;
	Card_Node *this_current = head;
	Card_Node *source_current = source.head;

	while (source_current != NULL) {
		// deep copy each Card_Node
		if (source_current->next != NULL) {
			Card_Node *new_node = new Card_Node();
			this_current->next = new_node;
			new_node->card = source_current->next->card;
		}
		else {
			this_current->next = NULL; // at tail
		}
		source_current = source_current->next;
		this_current = this_current->next;
	}
}

// operator= overload
List_linked_list List_linked_list::operator =(const List_linked_list&
		source) {
	// explicit operator= overload necessary because of cards array

	// check for self-assignment -- return without doing anything
	if (this == &source) {
		return *this;
	}
	// delete all current cards
	while (head != NULL) {
		Card_Node *next = head->next;
		delete head;
		head = next;
	}
	// copy over all cards from source list
	if (source.head == NULL) return *this; // nothing to do

	head = new Card_Node;
	Card_Node *this_current = head;
	Card_Node *source_current = source.head;

	while (source_current != NULL) {
		// deep copy each Card_Node
		this_current->card = source_current->card;
		if (source_current->next != NULL) {
			Card_Node *new_node = new Card_Node();
			this_current->next = new_node;
		}
		else {
			this_current->next = NULL; // at tail
		}
		source_current = source_current->next;
		this_current = this_current->next;
	}
	return *this;
}

void List_linked_list::print_list()
{
	Card_Node *current = head;
	while (current != NULL) {
		current->card.print_card();
		if (current->next != NULL) {
			cout << ",";
		}
		else {
			cout << "\n";
		}
		current = current->next;
	}
}

void List_linked_list::print_list_int()
{
	Card_Node *current = head;
	while (current != NULL) {
		current->card.print_card_int();
		if (current->next != NULL) {
			cout << ",";
		}
		else {
			cout << "\n";
		}
		current = current->next;
	}
}

int List_linked_list::cards_in_hand()
{
	// returns the number of cards in the hand
	int count = 0;
	Card_Node * current = head;
	while(current != NULL)
	{
		Card_Node *  temp = current->next;
		current = temp; //I was going to put these in one line,
		//but I don't remember C++'s order of precedence
		count++;
	}
	return count;
}

void List_linked_list::make_empty()
{
	// empties the list; head should equal NULL
	Card_Node * current = head;
	while (current != NULL)
        {
                Card_Node temp = current->next;
                delete current;
                current = temp;
        }
	head = NULL;
}

// inserts a card at the head
// Should allow insert into an empty list
void List_linked_list::insert_at_head(Card c) //???
{
	Card_Node * node = new Card_Node();
	node->card = c;
	node->next = head; //If the list is empty and head is NULL,
	//the new head would just point to a NULL as well.
	head = &node;
}

// inserts a card at the tail (final node)
// should allow insert into an empty list
void List_linked_list::insert_at_tail(Card c)
{
	Card_Node * current = head;
	Card_Node * newNode = new Card_Node();
	newNode -> card = c;
	while(current->next != NULL)
	{
		Card_Node * temp = current->next;
		current = temp;
	}
	current->next = newNode;
}

// inserts a card at an index such that
// all cards following the index will be moved farther
// down the list by one.
// The index can be one after the tail of the list
// I.e., you can insert at index 0 into an empty list,
// and you can insert at index 4 in a list with 4 nodes.
// In the first case, the node inserted would become the head
// In the second case, the node inserted would be inserted
// after the current tail.
void List_linked_list::insert_at_index(Card c, int index)
{
	if(index == 0)
		insert_at_head(c);
	else if(index==cards_in_hand())
		insert_at_tail(c);
	else
	{
		Card_Node * prevNode = node_at(index-1);
		Card_Node * nextNode = node_at(index);
		Card_Node newNode = new Card_Node();
		prevNode->next = newNode;
		newNode->next = nextNode;
	}
}

// replaces the card at index
// A card at index must already exist
void List_linked_list::replace_at_index(Card c, int index)
{

}

// returns the card at index.
// allowed to crash if index is not in the list
Card_Node* List_linked_list::node_at(int index)
{
	Card_Node * current = head;
	for(int i = 0; i < index; i++)
	{
		Card_node * temp = current->next;
		current = temp;
	}
	return current;
}

Card List_linked_list::card_at(int index)
{
	Card_Node * temp = node_at(index);
	return temp->card;
}

// returns true if the card is in the list
// returns false if the card is not in the list
bool List_linked_list::has_card(Card c)
{

}

// removes the card from the list
// Returns true if the card was removed
// Returns false if the card was not in the list
bool List_linked_list::remove(Card c)
{

}

// Removes the card from the head, and assigns the head
// to head->next
// Returns the card that was removed
// Allowed to fail if list is empty
Card List_linked_list::remove_from_head()
{

}

// Removes the card from the tail
// Returns the card that was removed
// Allowed to fail if the list is empty
Card List_linked_list::remove_from_tail()
{

}

// Removes the card from index
// Returns the card that was removed
// Allowed to fail if index is beyond the end of the list
Card List_linked_list::remove_from_index(int index)
{

}
