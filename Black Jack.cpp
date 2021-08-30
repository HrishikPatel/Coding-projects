#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Constants.h"

#include <iostream>

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit or (s) to stand:";
        char playerChoice{};
        std::cin >> playerChoice;
        if (std::cin.fail()) // no extraction took place
        {
            std::cout << "Input is invalid, please try again\n"; //notify player they did something wrong
            std::cin.clear(); // reset the state bits back to goodbit so we can use ignore()
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear out any input from stram to prevent silent fails
        }
        else if (playerChoice == 'h') return true; //the extraction was successful
        else if (playerChoice == 's') return false;
    }
}
bool playerTurn(Player& player, Deck& deck) //returns true if player busts. False otherwise
{
    while (true)
    {
        if (player.isBust() && !player.changeAceValue())//this can occur if they get two aces dealt to them at the start.
            //change ace values and make sure player has no more aces to turn over before they are declared busted
        {
            return true;
        }
        if(!player.isBust()) //the status of player busting may have changed due to changeAceValue() function
        {
            if (playerWantsHit()) //ask them if they want to hit or not and proceed accordingly
            {
                Card CardValue{ player.drawCard(deck) };
                std::cout << "You drew ";
                CardValue.print();
                std::cout << " and now have " << player.score() << '\n';
            }
            else
            {
                return false; //the player doesn't bust
            }
        }
    }
    return false;
}
bool dealerTurn(Player& dealer, Deck& deck) //returns true if dealer went bust, false otherwise
{
    while (dealer.score() < Constants::min_dealerScore)//dealer cannot bust while inside this loop
    {
        Card CardValue{ dealer.drawCard(deck) };
        std::cout << "The dealer drew a ";
        CardValue.print();
        std::cout << " and now has " << dealer.score() << '\n';
        if (dealer.isBust() && !dealer.changeAceValue())//changing ace values if busted. Otherwise continuing
        {
            std::cout << "The dealer busted!\n";
            return true;
        } //dealer stays. If busted, will return true, else will return false
    }
    return false; //means the dealer's score is between 17 and 21
}
bool PlayBlackJack(Deck& deck) //returns true if player wins and false if dealer wins
{
    Player dealer{};

    std::cout << "The dealer is showing ";
    dealer.drawCard(deck).print();
    std::cout << " with the score " << dealer.score() << '\n';

    Player player{};
    std::cout << "Your first card is ";
    player.drawCard(deck).print();
    std::cout << '\n'; //dealing two cards to player
    std::cout << "Your second card is ";
    player.drawCard(deck).print();
    std::cout << '\n';

    std::cout << "You have " << player.score() << '\n';

    if (playerTurn(player, deck))
    {
        return false; //the player has busted, and hence has lost
    }
    else //the player did not bust, now it is dealer's turn to play
    {
        if (dealerTurn(dealer, deck))//check if dealer played and busted or not
        {
            return true; //the player wins 
        }
        else //neither player or dealer busted, higher score wins
        {
            return (player.score() > dealer.score());
        }
    }
}
int main()
{
    Deck deck{};

    deck.shuffle();

    if (PlayBlackJack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lost :(";
    }
    return 0;
}