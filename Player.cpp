#include "Player.h"
#include "utilities.h"
using namespace std;


Player::Player(const char* playerName,int max_HP,int playerForce) : m_name(playerName),m_maxHP(max_HP),m_force(playerForce),
                                                                    m_level(MIN_LEVEL),m_coins(MIN_COINS),m_HP(m_maxHP) 
{//edit
    if (max_HP<0)
    {
        m_maxHP=DEAFULT_MAX_HP;
    }
    if(playerForce<0)
    {
        m_force=DEAFULT_FORCE;
    }


}

void Player::printInfo() const
{
    printPlayerInfo(m_name.data(),m_level,m_force,m_HP,m_coins);
}
// CHECK
void Player::levelUp()
{
    if (m_level<MAX_LEVEL)
    {
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;

}

void Player::buff(int addForce)
{
    if(addForce>0)//edit
    {
    m_force+=addForce;
    }
}

void Player::heal(int addHeal)
{
    if (m_HP+addHeal>m_maxHP)
    {
        m_HP=m_maxHP;
    }
    else
    if(addHeal>0)
    {
        m_HP+=addHeal;
    }
}

void Player::damage(int damageHeal)
{
    if (damageHeal>m_HP)
    {
        m_HP=0;
    }
    else
    if(damageHeal>0)
    {
        m_HP=m_HP-damageHeal;
    }
}

bool Player::isKnockedOut() const
{
    if(m_HP==0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd)
{
    if(coinsToAdd>0)//edit
    {
    m_coins+=coinsToAdd;
    }
}


bool Player::pay(int payAmount)
{
    if(payAmount>m_coins)
    {
        return false;
    }
    if(payAmount>0)//edit
    {
    m_coins=m_coins-payAmount;
    }
    return true;

}

int Player::getAttackStrength() const
{
    return m_force+m_level;
}

Player& Player::operator=(const Player& player1)
{
    if(this==&player1){
        return *this;
    }
    m_name=player1.m_name;
    m_level=player1.m_level;
    m_force=player1.m_force;
    m_maxHP=player1.m_maxHP;
    m_HP=player1.m_HP;
    m_coins=player1.m_coins;
    return *this;

}