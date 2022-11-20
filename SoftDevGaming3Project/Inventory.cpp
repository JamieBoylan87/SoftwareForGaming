#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/*
   Random string generator
*/
const int ch_MAX = 26; // total number of letters in the alphabet
string RandomString(int str_length)
{
    char alpha[ch_MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };
    string result = "";
    for (int i = 0; i < str_length; i++)
        result = result + alpha[rand() % ch_MAX];
    return result;
}

/*
    Struct Item holding information about items
*/
struct Item
{
    // name of the item
    std::string name;

    //  value of the item
    int value = 0;
};

class Inventory {
    vector<Item> items; // vector to store items
    vector<Item> playerItems;  // b) vector to store items acquired by the Player
    Item* p_playerItems;       // b) pointer to player items
    int cursedItemChance; // chances of getting a cursed item
public:
    Inventory(int n_gold, int n_healthPotions); // constructor
    ~Inventory();           // b) destructor
    bool removeItem(Item& item);
    bool removeGold(Item& gold);
    bool removeHealthPotion(Item& healthPot);
    bool isEmpty();
private:
    void addGold(Item gold);
    void addHealthPotion(Item healthPot);
    bool calculateCursedItemChance();
};

// class constructor
Inventory::Inventory(int n_gold = 100, int n_healhthPotions = 20) {

    // cursedItemChance = 0; // start with a 0% chance of finding the cursed item

    // add 10 random items to the box
    // 
        // create a new item and assign a random name and a random value

        /*
            item name will be a random string from the RandomString() function
            random number between 0 and 50
        */

        // your code

        Item healthPot;

        healthPot.name = "Health Potion";

        healthPot.value = rand() % 50 + 1;

        // My Item for game

        Item gold;

        gold.name = "Gold";

        gold.value = 1;

        addGold(gold);

        // add a new item to the game

        // your code

        addHealthPotion(healthPot);

    
}

// add a new item to Game
void Inventory::addGold(Item gold) {
    items.push_back(gold);
}

void Inventory::addHealthPotion(Item healthPot) {
    items.push_back(healthPot);
}

// remove gold from inventory 
bool Inventory::removeItem(Item& item) {
    // raise the odds of this being a cursed item
    //if (calculateCursedItemChance()) {
      //  return false;
    //}

    // get a random vector index by using the module operator

    int randomIndex = rand() % items.size();


    // find item by index using the at() method

    // insert your code here

    item = items.at(randomIndex);

    // b) Put item from chest into player inventory

    playerItems.push_back(item);


    // the value of the item increases after each turn based on the odds of getting a cursed item

    item.value *= 1 + cursedItemChance;


    // remove item from vector (the erase() method uses a pointer to the first position of the vector plus the index position of the element we want to find)

    // insert your code here

    items.erase(items.begin() + randomIndex);


    cursedItemChance += 5; //increases the chance of finding a cursed item by 5%

    return true;
}

bool Inventory::isEmpty() {
    return items.empty();
}

//bool Inventory::calculateCursedItemChance() {
//    int randomIndex = rand() % 100;
//    return randomIndex < cursedItemChance;
//}

void printInventory(std::vector<Item> inv) { // b)
    for (auto i : inv)
    {
        std::cout << i.name << " " << i.value << std::endl;         // setfill(' ') << setw(40) <<
    }
}

Inventory::~Inventory() { // b)

    printInventory(playerItems);

    delete[]p_playerItems;

}


/*int main() {
    srand(time(NULL));
    char guess;

    int player_gold = 0;

    Inventory items; // create new object from Chest class

    cout << "You received a mystery chest with 10 items." << endl;
    cout << "Every time you take an item from this chest there is a chance of being cursed and you lose your life!" << endl;
    cout << "How much do you want to risk it? " << endl;


    // open the box...    
    while (!items.isEmpty())
    {
        cout << "\n\nTake a new item? (y/n): ";
        // Take user input 
        cin >> guess;
        if (guess == 'y')
        {
            //get random item from box 
            Item randomItem;
            if (items.removeItem(randomItem))
            {
                // print item details
                cout << randomItem.name << " was found\n";

                player_gold += randomItem.value;

                cout << "Player Networth: " << player_gold << endl;
                continue;
            }
            cout << "You are now cursed!" << endl;
            cout << "You Lost: " << endl; // b)
            break;
        }
        else if (guess == 'n') {
            cout << "Left with: " << player_gold << endl;
            break;
        }
    }
}*/
