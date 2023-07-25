// Implementation of Hand class
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "hand.h"

Hand::Hand()
{
    cards.reserve(7);
}

void Hand::Add(Card &card)
{
    // add a card to hand
    cards.push_back(card);
}

bool Hand::Wins()
{
    int totalValue = 0;
    bool hasAce = false;

    // Calculate the total value of the cards in the hand
    for (const auto &card : cards)
    {
        totalValue += card->GetValue();
        if (card->GetValue() == 1) // Check if the hand has an Ace
        {
            hasAce = true;
        }
    }

    // If the hand has an Ace and adding 10 to the total value would not bust the hand, then add 10 to the total value
    if (hasAce && totalValue + 10 <= 21)
    {
        totalValue += 10;
    }

    // If the total value is 21, then the hand wins
    return totalValue == 21;
}

string Hand::getFirstCard()
{
    return cards[0].CardName();
}
string Hand::GetCardList()
{
    string list = "";

    // Iterate through all the cards in the hand and add their string representation to the list
    for (const auto &card : cards)
    {
        list += card->ToString() + " ";
    }

    return list;
}

int Hand::tally()
{
    int total = 0;
    int aces = 0;

    // Iterate through all the cards in the hand and add their values to the total
    for (const auto &card : cards)
    {
        total += card->GetValue();
        if (card->GetValue() == 1) // Check if the card is an Ace
        {
            aces++;
        }
    }

    // Choose the best value for each Ace
    while (aces > 0 && total + 10 <= 21)
    {
        total += 10;
        aces--;
    }

    return total;
}

bool Hand::isBusted()
{
    int totalValue = 0;
    bool hasAce = false;

    // Calculate the total value of the cards in the hand
    for (const auto &card : GetCards())
    {
        totalValue += card->GetValue();
        if (card->GetValue() == 1) // Check if the hand has an Ace
        {
            hasAce = true;
        }
    }

    // If the hand has an Ace and adding 10 to the total value would not bust the hand, then add 10 to the total value
    if (hasAce && totalValue + 10 <= 21)
    {
        totalValue += 10;
    }

    // If the total value is greater than 21, then the hand is busted
    return totalValue > 21;
}
