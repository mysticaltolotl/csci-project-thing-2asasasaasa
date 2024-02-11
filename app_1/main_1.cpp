//main_1.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "../code_1/browserHistory.hpp"

using namespace std;

void displayMenu();

int main(int argc, char* argv[]) {

    // DO NOT MODIFY THIS.
    if (argc > 1)
    {
        freopen(argv[1], "r", stdin);
    }
    // DO NOT MODIFY ABOVE.

    // TODO

    //define common vars
    string newURL, prevURL, owner;
    int id;
    int option;
    WebPage* temp;
    int prevID;

    //displayMenu();
    //cin >> option;

    bool built = false; // there's probably a more elegant way to see if a list has been built, but this works the same
    bool valid = false;
    bool looping = true;

    BrowserHistory history;

    while (looping)
    {
        displayMenu();
        cin >> option;
        if (option == 1)

        {
            history.buildBrowserHistory();
            history.displayHistory();
            built = true;
        }

        else if (option == 2)
        {
            if (built && !(history.isEmpty()))
            {
                history.displayHistory();
            }
            else
            {
                cout << "== CURRENT BROWSER HISTORY ==\nEmpty History\nNULL\n===\n";
            }
        }

        else if (option == 3)
        {
            cout << "Enter the new web page's url:" << endl;
            cin >> newURL;
            cout << "Enter the new web page's id:" << endl;
            cin >> id;
            cout << "Enter the previous page's url (or First):" << endl;
            cin >> prevURL;

            if (history.searchPageByURL(newURL) != NULL)
            {
                break; //return if the URL is already taken
            }

            if (prevURL == "First")
            {
                prevID = 10;
            }
            else
            {
                temp = history.searchPageByURL(prevURL);
                prevID = temp->id;
            }
            cout << "adding: [" << id << "]-" << newURL << " (prev: [" << prevID << "])";

            history.updateViews(newURL);
        }

        else if (option == 4)
        {
            valid = false;
            while (!valid)
            {
                cout << "Enter url of the web page to add the owner:" << endl;
                cin >> newURL;
                cout << "Enter the owner:";
                cin >> owner;

                history.addOwner(newURL, owner);
                temp = history.searchPageByURL(newURL);

                if (temp != NULL)
                {
                    cout << "The owner (" << owner << ") has been added for the ID - " << temp->id << endl;
                    valid = true;
                }

                cout << "Page not found. Try again." << endl;

            }
        }

        else if (option == 5)
        {
            cout << "Enter url of the web page to check the view count: " << endl;
            cin >> newURL;
            temp = history.searchPageByURL(newURL);
            if (temp != NULL)
            {
                cout << "View count for URL - " << newURL << "is " << temp->views << endl;
            }
            else
            {
                cout << "View count for URL - " << newURL << "is 0" << endl;
            }
        }

        else if (option == 6)
        {
            cout << "Quitting...Goodbye!\n";
            looping = false;
        }

        else
        {
            cout << "Invalid selection, please try again" << endl;
        }
    }

    return 0;
}




/************************************************
           Definitions for main_1.cpp
************************************************/
void displayMenu()
{
    // COMPLETE: You DO NOT need to edit this
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build history " << endl;
    cout << " 2. Display history " << endl;
    cout << " 3. Add web page " << endl;
    cout << " 4. Add owner" << endl;
    cout << " 5. View count for a web page" << endl;
    cout << " 6. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}