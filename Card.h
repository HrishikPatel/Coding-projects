#ifndef CARD_H
#define CARD_H

class Card
{
public:
    enum Suit
    {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };

    enum Rank
    {
        rank_ace_1,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace_11,

        max_ranks
    };
private:

    Rank m_rank{};
    Suit m_suit{};


public:
    Card();
    Card(Rank rank, Suit suit);
    void print() const;
    int value() const;
    void setValue(Rank rank); //keep this private as you do not want anybody to be changing values as it may cause errors
};
#endif

