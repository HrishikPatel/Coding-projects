#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants
{
	constexpr int max_Score{ 21 };//In blackjack if a player goes over 21 then they lose
	constexpr int min_dealerScore{ 17 }; //the dealer has to hit until they hit 17, then they must stay
	constexpr int changeInAceValue{ 10 }; //the ace changes from 1 points to 11 or vice versa. A point difference of 10 points
}
#endif
