

#include "Mtmchkin.h"


    Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):m_playerName(playerName),
    m_cards(new Card[numOfCards]),m_cardLength(numOfCards)
    ,m_iteration(0),m_status(GameStatus::MidGame) {
        for (int i = 0; i < numOfCards; i++) {
        m_cards[i] = cardsArray[i];
     }
}
    Mtmchkin::~Mtmchkin(){
        delete[] m_cards;
    }

GameStatus Mtmchkin::getGameStatus() const {
    return m_status;
}

void Mtmchkin::playNextCard() {
    if(getGameStatus()==GameStatus::MidGame)
    {
        m_cards[m_iteration].printInfo();
        m_cards[m_iteration].applyEncounter(m_playerName);
        m_playerName.printInfo();
        if(m_playerName.isKnockedOut())
        {
            m_status=GameStatus::Loss;
        }
        if(m_playerName.getLevel()>=MAXI_LEVEL)
        {
            m_status=GameStatus::Win;
        }
        m_iteration++;
        if(m_iteration>=m_cardLength)
        {
            m_iteration=m_iteration%m_cardLength;
        }
    }
}

bool Mtmchkin::isOver() const {
    if(m_status!=GameStatus::MidGame)
    {
        return true;
    }
    return false;
}
