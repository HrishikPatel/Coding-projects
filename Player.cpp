#include "Player.h"
#include "Constants.h"
#include <iostream> //std::cout

 Player::Player() = default; //default constructor
 Card& Player::drawCard(Deck& deck)
 {
     m_playerCards[m_playerCardIndex] = deck.dealCard();
     m_score += m_playerCards[m_playerCardIndex].value(); //increment the score everytime a card is drawn to prevent having to loop through array everytime
     return m_playerCards[m_playerCardIndex++]; //return the last card dealt and then increment the index to be ready for the next card to be dealt
 }
 int Player::score()
 {
     return m_score;
 }
 bool Player::isBust()
 {
     return (m_score > Constants::max_Score);
 }
 bool Player::changeAceValue() //takes aces and turns their value to one. Returns true if an ace was changed over, else returns false
 {
     const Card cardAce{Card::rank_ace_11, Card::suit_spade};
     bool aceValueChanged{false};
     for (Card& card : m_playerCards)
     {
         if (card.value() == cardAce.value())
         {
             card.setValue(Card::rank_ace_1); //tag it as changed so it cannot be used again
             m_score -= Constants::changeInAceValue; //change the score according to the changes in ace values
             std::cout << "The card ";
             card.print();
             std::cout << " has had it's value changed to 1\n";
             std::cout << "Your new score is " << m_score << '\n';
             aceValueChanged = true;
         }
     }
     return aceValueChanged; //if its false, means the player has no more aces to change over to value of 1
 }
