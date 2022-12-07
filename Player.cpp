#include "player.h"
#include <iostream>
#include "utilities.h"
using namespace std;

const char* allocate(const char *nameOfPlayer, int lenght)
{
    return strcpy(new char[lenght + 1], nameOfPlayer);
}
Player::Player(const char* playerName,int max_HP,int playerForce) : name(allocate(playerName,strlen(playerName))),maxHP(max_HP),force(playerForce),
                                                                    level(MIN_LEVEL),coins(MIN_COINS),HP(maxHP) {}

Player::Player(const Player& player2): name(allocate(player2.name,strlen(player2.name))),maxHP(player2.maxHP),force(player2.force),
                                       level(player2.level),coins(player2.coins),HP(player2.HP){}

Player::~Player()
{
    delete []name;
}

void Player::printInfo() const
{
    printPlayerInfo(name,level,force,HP,coins);
}

void Player::levelUp()
{
    if (level<10)
    {
        level++;
    }
}

int Player::getLevel()
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

bool Player::isKnockedOut()
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

int Player::getAttackStrength()
{
    return force+level;
}

Player& Player::operator=(const Player& player1)
{
    if(this==&player1){
        return *this;
    }
    delete []name;
    name=allocate(player1.name,strlen(player1.name));
    level=player1.level;
    force=player1.force;
    maxHP=player1.maxHP;
    HP=player1.HP;
    coins=player1.coins;
    return *this;

}