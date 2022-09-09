#include <iostream>
#include "World.h"
#include "Organism.h"
using namespace std;

int main()
{
    vector<Organism*> org;
    cout << "GAME MENU" << endl << "Choose option:" << endl;
    cout << "Press 1 if you want to start new game" << endl;
    cout << "Press 2 if you want to start a game form *.txt file" << endl;
    int command;
    cin >> command;

    if (command == 1)
    {
        int width, height;
        World* world = new World();
        cout << "Type width of world: ";
        cin >> width;
        cout << "Type hight of world: ";
        cin >> height;

        if (width > 0 && height > 0)
        {
            cout << "This is new world" << endl;
            World world(width, height, org);
        }
    }

    if (command == 2) {
        World* world = new World();
        world->LoadInfoFromFile();
    }
}
