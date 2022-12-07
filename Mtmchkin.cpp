

#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):m_playerName(playerName),
m_cards(new Card[numOfCards]),m_cardLength(numOfCards)
,m_iteration(0),m_status(GameStatus::MidGame)
{
    for(int i=0;i<numOfCards;i++)
    {
        m_cards[i]=cardsArray[i];
    }



}