#ifndef DECK_H
#define DECK_H

#include <deque>
#include <stdlib.h>
#include <iostream>
template<class Tipo>
class Deck {
	public:
		Deck();
		Deck ( Tipo*, int total );
		~Deck();

		void add ( Tipo );
		void add ( Tipo*, int total );
		void removePerm ( Tipo );
		void remove ( Tipo );
		void reshuffle();

		Tipo drawBottom();
		Tipo seeBottom();
		Tipo seeTop();
		Tipo drawTop();

		bool contain ( Tipo );
		bool discard_Contain ( Tipo );

		int getAmount();
		int getTotal();

		std::deque<Tipo> getDeck();
		std::deque<Tipo> getDiscard();


	protected:

	private:
		int amount;
		int total;
		std::deque<Tipo> cards;
		std::deque<Tipo> discards;
};
template <typename T>
Deck<T>::Deck() : amount ( 0 ), total ( 0 ) {

	cards = std::deque<T>();
	discards = std::deque<T>();

}

template <typename T>
Deck<T>::Deck ( T* card, int total ) {
	this->total = 0;
	amount = 0;
	cards = std::list<T>();
	discards = std::list<T>();

	add ( card, total );

}
template <typename T>
void Deck< T>::add ( T* card, int total ) {
	for ( int i = 0; i < total; i++ ) {
		this->add ( card[i] );
	}
}

template <typename T>
Deck< T>::~Deck() {

}
template <typename T>
void Deck< T>::add ( T card ) {
	cards.push_front ( card );
	amount++;
	total++;
}
template <typename T>
void Deck< T>::remove ( T card ) {
	if ( this->contain ( card ) ) {
		cards.remove ( card );
		discards.add ( card );
		amount--;
	}
}
template <typename T>
bool Deck< T>::contain ( T card ) {
	if ( amount <= 0 ) return false;

for ( T t: cards ) {
		if ( t == card ) return true;
	}
	return false;
}

template <typename T>
bool Deck< T>::discard_Contain ( T card ) {
for ( T t: discards ) {
		if ( t == card ) return true;
	}
	return false;
}

template <typename T>
void Deck< T>::removePerm ( T card ) {
	if ( this->contain ( card ) ) {
		cards.remove ( card );
		amount--;
		total--;
	} else {
		if ( this->discardContain ( card ) ) {
			discards.remove ( card );
			total--;
		}
	}
}
template <typename T>
T Deck< T>::drawBottom() {

	T temp = cards.back();
	if ( amount > 0 ) {
		cards.pop_back();
		amount--;
		discards.push_back ( temp );
	}

	return temp;

}
template <typename T>
T Deck< T>::seeBottom() {
	return cards.back();
}
template <typename T>
T Deck< T>::seeTop() {
	return cards.front();
}
template <typename T>
T Deck< T>::drawTop() {
	T temp = cards.front();
	if ( amount > 0 ) {
		cards.pop_front();
		amount--;
		discards.push_back ( temp );
	}
	return temp;
}
template <typename T>
void Deck< T>::reshuffle() {
	T randomed[total];
	int i = 0;
for ( T t: cards ) {
		if ( i >= total ) {
			std::cout << "reshuffle overflow";
			break;
		}
		randomed[i] = t;
		i++;

	}
for ( T t: discards ) {
		if ( i >= total ) {
			std::cout << "reshuffle overflow";
			break;
		}
		randomed[i] = t;
		i++;

	}
	discards.clear();
	cards.clear();

	for ( int i = 0; i < total; i++ ) {
		int x = rand() % total;
		int y = rand() % total;
		T temp = randomed[x];
		randomed[x] = randomed[y];
		randomed[y] = temp;
	}
	int sizeTemp = total;
	total = 0;
	amount = 0;
	this->add ( randomed, sizeTemp );


}

template <typename T>
int Deck< T>::getAmount() {
	return amount;

}

template <typename T>
int Deck<T>::getTotal() {
	return total;;
}
/*
template <typename T>
std::list<T> Deck< T>::getDeck() {
	return cards;
}
template <typename T>
std::list<T> Deck< T>::getDiscard() {
	return discards;
}
*/
#endif // DECK_H
