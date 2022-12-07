#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H
#define DEAFULT_MAX_HP 100
#define DEAFULT_FORCE 5
#define MIN_LEVEL 1
#define MIN_COINS 0
#include <cstring>
class Player
{
    const char* name;//name of the player
    int maxHP;//max health of the player
    int force;//force of the player
    int level;//current level of the player
    int coins;// the coins that the player have
    int HP;//current health of the player



public:
    Player(const char* playerName,int max_HP=DEAFULT_MAX_HP,int playerForce=DEAFULT_FORCE);//constructor
    Player(const Player&);//copy constructor
    ~Player();//destructor

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
/**
 Allocate new player name
 * @param nameOfPlayer- The player name
 * @param lenght - The lenght of the name
 */
const char* allocate(const char *nameOfPlayer, int lenght);


#endif