#ifndef DECK_H
#define DECK_H

#include <array>
#include "Card.h"

class Deck
{
    using index_type = std::array<Card, 52>::size_type;
    using array_type = std::array<Card, 52>;
private:
    array_type m_deck{};
    index_type m_cardIndex{ 0 };
public:
    Deck(); //takes no parameters and initializes the deck with one of each card
    void print();
    void shuffle();
    Card& dealCard();
};

#endif