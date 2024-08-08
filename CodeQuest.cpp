#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Forward declaration of Quest class
class Quest;

// Player class to track the player's progress
class Player {
public:
    string name;
    int experience;
    vector<int> completedQuests;

    Player(const string& playerName) : name(playerName), experience(0) {}

    void addExperience(int points) {
        experience += points;
        cout << "You've gained " << points << " experience points!" << endl;
    }

    void completeQuest(int questID) {
        completedQuests.push_back(questID);
    }
};

// Base class for quests
class Quest {
protected:
    string description;
    int difficulty;

public:
    Quest(const string& desc, int diff) : description(desc), difficulty(diff) {}
    virtual void startQuest(Player& player) = 0; // Pure virtual function
    virtual ~Quest() {} // Virtual destructor for proper cleanup
};

// Quest to calculate area
class AreaQuest : public Quest {
public:
    AreaQuest() : Quest("Calculate the area of a garden.", 1) {}

    void startQuest(Player& player) override {
        float length, width, area;
        cout << "Enter the length of the garden: ";
        cin >> length;
        cout << "Enter the width of the garden: ";
        cin >> width;
        area = length * width;
        cout << "The area of the garden is: " << area << endl;
        player.addExperience(difficulty * 10);
        player.completeQuest(1);
    }
};

// Quest to decide a path based on encounters
class ControlStructuresQuest : public Quest {
public:
    ControlStructuresQuest() : Quest("Decide a path based on encounters.", 1) {}

    void startQuest(Player& player) override {
        int monsters;
        cout << "Enter the number of monsters encountered: ";
        cin >> monsters;

        if (monsters > 5) {
            cout << "Take the safe path!" << endl;
        } else {
            cout << "You can fight! Go ahead!" << endl;
        }
        player.addExperience(difficulty * 10);
        player.completeQuest(2);
    }
};

// Game class to manage the overall game flow
class Game {
private:
    Player player;
    vector<Quest*> quests;

public:
    Game(const string& playerName) : player(playerName) {
        quests.push_back(new AreaQuest());
        quests.push_back(new ControlStructuresQuest());
    }

    ~Game() {
        for (Quest* quest : quests) {
            delete quest;
        }
    }

    void displayMainMenu() {
        cout << "\nWelcome to CodeQuest!" << endl;
        cout << "1. Start New Quest" << endl;
        cout << "2. View Achievements" << endl;
        cout << "3. Exit" << endl;
    }

    void start() {
        while (true) {
            displayMainMenu();
            int choice;
            cin >> choice;

            switch (choice) {
                case 1: {
                    int questIndex;
                    cout << "Select quest index (0 for AreaQuest, 1 for ControlStructuresQuest): ";
                    cin >> questIndex;
                    if (questIndex < quests.size()) {
                        quests[questIndex]->startQuest(player);
                    } else {
                        cout << "Invalid quest." << endl;
                    }
                    break;
                }
                case 2:
                    cout << "Achievements:" << endl;
                    cout << "Experience: " << player.experience << endl;
                    cout << "Completed Quests: ";
                    for (int quest : player.completedQuests) {
                        cout << quest << " ";
                    }
                    cout << endl;
                    break;
                case 3:
                    cout << "Exiting the game." << endl;
                    return;
                default:
                    cout << "Invalid choice. Try again." << endl;
            }
        }
    }
};

// Main function to start the game
int main() {
    string playerName;
    cout << "Enter your hero's name: ";
    getline(cin, playerName);
    Game game(playerName);
    game.start();
    return 0;
}

