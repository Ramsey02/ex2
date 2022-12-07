#include "Player.h"
#include "utilities.h"
using namespace std;


Player::Player(const char* playerName,int max_HP,int playerForce) : name(playerName),maxHP(max_HP),force(playerForce),
                                                                    level(MIN_LEVEL),coins(MIN_COINS),HP(maxHP) {}

void Player::printInfo() const
{
    printPlayerInfo(name.data(),level,force,HP,coins);
}

void Player::levelUp()
{
    if (level<10)
    {
        level++;
    }
}

int Player::getLevel() const
{
    return level;

}

void Player::buff(int addForce)
{
    force+=addForce;
}

void Player::heal(int addHeal)
{
    if (HP+addHeal>maxHP)
    {
        HP=maxHP;
    }
    else
    if(addHeal>0)
    {
        HP+=addHeal;
    }
}

void Player::damage(int damageHeal)
{
    if (damageHeal>HP)
    {
        HP=0;
    }
    else
    if(damageHeal>0)
    {
        HP=HP-damageHeal;
    }
}

bool Player::isKnockedOut() const
{
    if(HP==0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd)
{
    coins+=coinsToAdd;
}


bool Player::pay(int payAmount)
{
    if(payAmount>coins)
    {
        return false;
    }
    coins=coins-payAmount;
    return true;

}

int Player::getAttackStrength() const
{
    return force+level;
}

Player& Player::operator=(const Player& player1)
{
    if(this==&player1){
        return *this;
    }
    name=player1.name;
    level=player1.level;
    force=player1.force;
    maxHP=player1.maxHP;
    HP=player1.HP;
    coins=player1.coins;
    return *this;

}