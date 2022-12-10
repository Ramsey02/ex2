#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H
#include <iostream>

using namespace std;



class Player
{
    string m_name;//name of the player
    int m_maxHP;//max health of the player
    int m_force;//force of the player
    int m_level;//current level of the player
    int m_coins;// the coins that the player have
    int m_HP;//current health of the player
    static const int DEAFULT_MAX_HP=100;
    static const int DEAFULT_FORCE=5;
    static const int MIN_LEVEL=1;
    static const int MIN_COINS=0;
    static const int MAX_LEVEL=10;



public:
    explicit Player(const char* playerName,int max_HP=DEAFULT_MAX_HP,int playerForce=DEAFULT_FORCE);//constructor
    Player(const Player&)=default;//copy constructor

    void printInfo()const;//printing the player info without changing anything
    void levelUp();// raise the player level
    int getLevel() const;// return the player level
    void buff(int addForce);//add force to the player
    void heal(int addHeal);//add heal to the player
    void damage(int damageHeal);//reduce heal
    bool isKnockedOut() const;//check if the player lose
    void addCoins(int coinsToAdd);//add coins to the player
    bool pay(int payAmount);// reduce the coins amount that the player has
    int getAttackStrength() const;//retutn the attack strenght (level+force)
    Player& operator=(const Player& player1);// operator =




};

#endif