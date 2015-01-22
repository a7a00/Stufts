//I WAS TOO BUSY HAVING MY LAPTOP STOLEN TO TEST THIS PROPERLY.
//MANY THANKS TO BEN STEEPHWNSON FOR THIS CODE.

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <assert.h>
#include "hand.h"

using namespace std;

void test_cards_in_hand()
{

	//CASE EMPTY LINKED LIST
	List_linked_list list;
	assert(list.cards_in_hand() == 0);
	//CASE NON-EMPTY
	Card card;
	list.insert_at_head(card);
	assert(list.cards_in_hand() == 1);

	//CASE AFTER REMOVAL
	list.remove(card);
	assert(list.cards_in_hand() == 0);

}

void test_make_empty()
{
	List_linked_list list;
	//CASE EMPTY LINKED LIST
	list.make_empty();
	assert(list.cards_in_hand() == 0);
	//CASE NON-EMPTY
	Card card;
	list.insert_at_head(card);
	list.make_empty();
	assert(list.cards_in_hand() == 0);
	assert(!list.has_card(card));
}

void test_insert_at_head()
{

	List_linked_list list;
	Card c1;
	Card c2('3', 'H');
	//CASE EMPTY LINKED LIST
	list.insert_at_head(c1);
	assert(list.has_card(c1));
	//CASE NON-EMPTY
	list.insert_at_head(c2);
	assert(list.has_card(c2));
}

void test_insert_at_tail()
{
	List_linked_list list;
	Card c1;
	Card c2('3', 'H');
	//CASE EMPTY LINKED LIST
	list.insert_at_tail(c1);
	assert(list.has_card(c1));
	//CASE NON-EMPTY
	list.insert_at_tail(c2);
	assert(list.has_card(c2));
}

void test_insert_at_index()
{
	List_linked_list list;
	Card c1('1', 'S');
	Card c2('2', 'S');
	Card c3('3', 'S');
	Card c4('4', 'S');

	//CASE EMPTY LINKED LIST
	list.insert_at_index(c1, 0);
	assert(list.has_card(c1));

	//CASE INDEX IS HEAD
	list.insert_at_index(c2, 0);
	assert(list.card_at(0).same_card(c2));

	//CASE INDEX IS TAIL
	list.insert_at_index(c3, 2);
	assert(list.card_at(2).same_card(c3));

	//CASE INDEX IS IN THE MIDDLE
	cout << "Old List: ";
	list.print_list();
	cout << "\n";
	list.insert_at_index(c4, 1);
	cout << "New List: ";
	list.print_list();
	cout << "\n";
	list.card_at(1).print_card();
	cout << "\n";
	c4.print_card();
	cout << "\n";
	assert(list.card_at(1).same_card(c4));
}

void test_replace_at_index()
{
	List_linked_list list;
	Card c1('A', 'S');
	Card c2('2', 'S');
	Card c3('3', 'S');
	Card c4('4', 'S');

	list.insert_at_tail(c1);
	list.insert_at_tail(c2);
	list.insert_at_tail(c3);

	//CASE AT HEAD
	list.replace_at_index(c4, 0);
	//CASE AT TAIL
	list.replace_at_index(c2, 2);
	//CASE IN MIDDLE
	list.replace_at_index(c3, 1);

	assert(list.card_at(0).same_card(c4));
	assert(list.card_at(1).same_card(c3));
	assert(list.card_at(2).same_card(c2));
}

void test_card_at()
{
	List_linked_list list;
	Card c1('1', 'S');
	Card c2('2', 'S');
	Card c3('3', 'S');

	list.insert_at_tail(c1);
	list.insert_at_tail(c2);
	list.insert_at_tail(c3);

	assert(list.card_at(0).same_card(c1));
	assert(list.card_at(1).same_card(c2));
	assert(list.card_at(2).same_card(c3));

}

void test_has_card()
{
	List_linked_list list;
	cout << "HC: We have a list.\n";
	Card c1('1', 'S');
	Card c2('2', 'S');
	Card c3('3', 'S');
	cout << "HC: We have cards.\n";
	list.insert_at_tail(c1);
	cout << "HC: C1 inserted OK.\n";
	list.insert_at_tail(c2);
	cout << "HC: C2 inserted OK.";

	assert(list.has_card(c1));
	assert(list.has_card(c2));
	assert(!list.has_card(c3));
}

void test_remove()
{
	List_linked_list list;
	Card c1('1', 'S');
	Card c2('2', 'S');
	Card c3('3', 'S');
	Card c4('4', 'S');
	Card c5('5', 'S');

	//CASE EMPTY LINKED LIST
	assert(!list.remove(c2));
	//CASE HEAD
	list.insert_at_tail(c1);
	list.insert_at_tail(c2);
	list.insert_at_tail(c3);
	list.insert_at_tail(c4);

	assert(list.remove(c1));
	assert(!list.has_card(c1));
	assert(list.cards_in_hand() == 3);

	//CASE MIDDLE
	assert(list.remove(c3));
	assert(!list.has_card(c3));
	assert(list.cards_in_hand() == 2);

	//CASE TAIL
	assert(list.remove(c4));
	assert(!list.has_card(c4));
	assert(list.cards_in_hand() == 1);

	//CASE NOT IN LIST
	assert(!list.remove(c5));
	assert(list.cards_in_hand() == 1);
}

void test_remove_from_head()
{
	List_linked_list list;
	Card c1('1', 'S');
	Card c2('2', 'S');
	Card c3('3', 'S');
	list.insert_at_head(c1);
	//CASE ONLY ONE ELEMENT
	assert(list.remove_from_head().same_card(c1));
	//CASE MULTIPLE ELEMENTS
	list.insert_at_head(c2);
	list.insert_at_head(c3);
	assert(list.remove_from_head().same_card(c3));
}

void test_remove_from_tail()
{
	List_linked_list list;
	Card c1('1', 'S');
	Card c2('2', 'S');
	Card c3('3', 'S');
	list.insert_at_tail(c1);
	//CASE ONLY ONE ELEMENT
	assert(list.remove_from_tail().same_card(c1));
	//CASE MULTIPLE ELEMENTS
	list.insert_at_tail(c2);
	list.insert_at_tail(c3);
	assert(list.remove_from_tail().same_card(c3));
}

void test_remove_from_index()
{
	List_linked_list list;
	Card c1('1', 'S');
	Card c2('2', 'S');
	Card c3('3', 'S');
	Card c4('4', 'S');
	Card c5('5', 'S');
	Card c6('6', 'S');
	
	//CASE ONLY ONE ELEMENT
	list.insert_at_tail(c1);
	assert(list.remove_from_index(0).same_card(c1));
	assert(list.cards_in_hand() == 0);
	
	//CASE HEAD
	list.insert_at_tail(c2);
	list.insert_at_tail(c3);
	assert(list.remove_from_index(0).same_card(c2));
	assert(list.card_at(0).same_card(c3));

	//CASE MIDDLE
	list.insert_at_tail(c4);
	list.insert_at_tail(c5);
	list.insert_at_tail(c6);
	assert(list.remove_from_index(1).same_card(c4));
	assert(list.cards_in_hand() == 3);
	//CASE TAIL
	assert(list.remove_from_index(2).same_card(c6));
	assert(list.cards_in_hand() == 2);
}


int main(int argc, char **argv)
{
	cout << "Testing cards_in_hand\n";
	test_cards_in_hand();
	cout << "Testing make_empty()\n";
	test_make_empty();
	cout << "Testing card_at()\n";
	test_card_at();
	cout << "Testing has_card()\n";
	test_has_card();

	cout << "Testing insert_at_head()\n";
	test_insert_at_head();
	cout << "Testing insert_at_tail()\n";
	test_insert_at_tail();
	cout << "Testing insert_at_index()\n";
	test_insert_at_index();
	cout << "Testing replace_at_index\n";
	test_replace_at_index();

	cout << "Testing remove_from_head()\n";
	test_remove_from_head();
	cout << "Testing remove_from_tail()\n";
	test_remove_from_tail();
	cout << "Testing remove_from_index()\n";
	test_remove_from_index();
	cout << "Testing remove()\n";
	test_remove();
	cout << "No red tape? You're good =)" << endl;
	return 0;
}
