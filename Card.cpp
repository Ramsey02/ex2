#include "Card.h"


Card::Card(CardType type, const CardStats &stats)
{
    m_effect=type;
    m_stats=stats;
}

void Card::applyEncounter(Player &player) const
{
    if(m_effect==CardType::Battle)
    {
        if(player.getAttackStrength()>=m_stats.force)
        {
            player.levelUp();
            player.addCoins((m_stats.loot));
            printBattleResult(true);
        }
        else
        {
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(false);
        }
    }


    if(m_effect==CardType::Heal)
    {
        if(player.pay(m_stats.cost))
            player.heal(m_stats.heal);
    }
    if(m_effect==CardType::Buff)
    {
        if(player.pay(m_stats.cost))
            player.buff(m_stats.buff);
    }
    if(m_effect==CardType::Treasure)
    {
        player.addCoins(m_stats.loot);
    }

}

void Card::printInfo() const
{
    switch (m_effect)
    {
        case CardType::Battle:
        {
            printBattleCardInfo(this->m_stats);
            break;
        }
        case CardType::Treasure:
        {
            printTreasureCardInfo(this->m_stats);
            break;
        }
        case CardType::Heal:
        {
            printHealCardInfo(this->m_stats);
            break;
        }
        case CardType::Buff:
        {
            printBuffCardInfo(this->m_stats);
            break;
        }
    }
}
