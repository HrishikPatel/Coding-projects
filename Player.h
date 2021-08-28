#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h" 
#include "Card.h"
#include <array>

class Player
{
    using array_type = std::array<Card, 52>;
    using index_type = std::array<Card, 52>::size_type;
private:
    int m_score{ 0 };
    array_type m_playerCards{}; //keeping track of the cards drawn by a player
    index_type m_playerCardIndex{}; //help keep track of the last player card
public:
    Player(); //default constructor

    Card& drawCard(Deck& deck);
    int score();
    bool isBust();
    bool changeAceValue();
};

#endif
