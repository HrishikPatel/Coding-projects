#include "Deck.h"
#include <ctime> // std::time
#include <random> // std::mt19937
#include <iostream> //std::cout and stream reading
#include <cassert>

Deck::Deck() //takes no parameters and initializes the deck with one of each card
{
    index_type index{ 0 };
    for (int suit{ 0 }; suit < static_cast<int>(Card::max_suits); ++suit)
    {
        for (int rank{ 1 }; rank < static_cast<int>(Card::max_ranks); ++rank) //rank must start at 1 as rank_ace_1 is just another version of rank_ace_11 with less points, not another card per se
        {
            m_deck[index] = { static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit) };
            ++index;
        }
    }
}
void Deck::print()
{
    for (const auto& card : m_deck)
    {
        card.print();
        std::cout << ' ';
    }

    std::cout << '\n';
}
void Deck::shuffle()
{
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    std::shuffle(m_deck.begin(), m_deck.end(), mt);
    m_cardIndex = 0;
}
Card& Deck::dealCard()
{
    assert(m_cardIndex < m_deck.size());
    return m_deck[m_cardIndex++]; //returns m_deck[m_cardIndex] and then replaces m_cardIndex with an incremented copy of itself.
}