# Coding-projects
I wanted to create a very basic version of Black Jack, where a single player would be able to play against the computer. Splitting a pair of cards and multiple people being 
able to play with are some of the functionalities I plan to add in the future.
If interested in the code, I've split the functionality into three different classes of Player, Card, Deck and a header file containing all the constants names Constants.h.
Each class has two files associated with it, class.cpp and class.h.

Class Card
  Card class defines the properties of a card and provides the ability to print a card, extract its value (in Black Jack terms), and being able to 
  set a card's value (private member for encapsulation purposes).
  
Class Player
  Defines properties any player playing Black Jack may have, such as the ability to draw a card, their score, knowledge of whether they are busted or not, and the ability 
  to change an Ace's value from 11 to 1 if needed.
  
Class Deck
   Deck is defined as an array of 52 cards(Could also be implemented as a stack). That can be printed to screen, shuffled, or can deal a card from the deck.
   
BlackJack.cpp
  Uses the three classes defines above to play Black Jack. The implementation of a dealer's turn and a player's turn are seperated as the rules differ for each. E.g if a dealer hits
  17 points or goes over (without busting) then they must stay, while a player has no such rule.
