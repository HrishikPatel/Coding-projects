#include "Card.h"
#include <iostream>
#include <cassert>

Card::Card() = default;
Card::Card(Card::Rank rank, Card::Suit suit) : m_rank{ rank }, m_suit{ suit }
{}
void Card::print() const
{
    switch (m_rank)
    {
    case rank_ace_1:  std::cout << 'A';   break;//still shows as the same card, though their values are different
    case rank_2:      std::cout << '2';   break;
    case rank_3:      std::cout << '3';   break;
    case rank_4:      std::cout << '4';   break;
    case rank_5:      std::cout << '5';   break;
    case rank_6:      std::cout << '6';   break;
    case rank_7:      std::cout << '7';   break;
    case rank_8:      std::cout << '8';   break;
    case rank_9:      std::cout << '9';   break;
    case rank_10:     std::cout << 'T';   break;
    case rank_jack:   std::cout << 'J';   break;
    case rank_queen:  std::cout << 'Q';   break;
    case rank_king:   std::cout << 'K';   break;
    case rank_ace_11:    std::cout << 'A';   break;
    default:
        std::cout << '?';
        break;
    }

    switch (m_suit)
    {
    case suit_club:       std::cout << 'C';   break; //we can access enum objects with the scope resolution operator
    case suit_diamond:    std::cout << 'D';   break;
    case suit_heart:      std::cout << 'H';   break;
    case suit_spade:      std::cout << 'S';   break;
    default:
        std::cout << '?';
        break;
    }
}
int Card::value() const
{
    switch (m_rank)
    {
    case rank_ace_1:    return 1; //an ace is 11 points normally, unless 11 points causes player to bust, in which case it is worth 1 point
    case rank_2:        return 2;
    case rank_3:        return 3;
    case rank_4:        return 4;
    case rank_5:        return 5;
    case rank_6:        return 6;
    case rank_7:        return 7;
    case rank_8:        return 8;
    case rank_9:        return 9;
    case rank_10:       return 10;
    case rank_jack:     return 10;
    case rank_queen:    return 10;
    case rank_king:     return 10;
    case rank_ace_11:   return 11;
    default:
        assert(false && "should never happen");
        return 0;
    }
}
void Card::setValue(Rank rank)
{
    m_rank = rank;
}

    

   