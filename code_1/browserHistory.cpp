//browserHistory.cpp
//browserHistory.cpp

/*************************************************************/
/*                BrowserHistory Definition                  */
/*************************************************************/
/* TODO: Implement the member functions of BrowserHistory    */
/*     This class uses a linked-list of WebPage structs to   */
/*     represent the schedule of web pages                   */
/*************************************************************/

#include "browserHistory.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
BrowserHistory::BrowserHistory() {
	/*
	This constructor is already complete.
	*/
	head = nullptr;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool BrowserHistory::isEmpty() {
	/* finished. do not touch. */
	return (head == NULL);
}

/*
 * Purpose: prints the current list of pages
 * in the given format.
 * [ID::1]-(URL::url1) -> ... -> NULL
 * @param none
 * @return none
 */
void BrowserHistory::displayHistory() {
	WebPage* temp = head;

    int counter = 0;

	cout << "== CURRENT BROWSER HISTORY ==" << endl;
  
	// iteration goes here
	while (temp != nullptr)
	{
        
		cout << "[ID:: " << temp->id << "]-(URL::" << temp->url << ") -> ";
        //cout << "|" << temp->id << "| ";
		temp = temp->next;
      
     	counter++;
	}

    if(counter == 0)
    {
        cout << "Empty History" << endl;
    }

	cout << "NULL" << endl << "===" << endl;
}

/*
 * Purpose: Add a new webpage to the browser history LL
 *   between the previous and the page that follows it in the list.
 * @param previousPage, the show that comes before the new page
 * @param newPage, the webpage to be added.
 * @return none
 */
void BrowserHistory::addWebPage(WebPage* previousPage, WebPage* newPage) {
	// TODO
	// WebPage* temp = previousPage->next;

	if (newPage == nullptr) {
        cout << "No page provided to add\n";
        return;
    }
	if (previousPage == nullptr)
	{
		if (head == nullptr)
		{
			head = newPage;
			head->next = nullptr;
		}
		else
		{
			newPage->next = head;
			head = newPage;
		}

		// If you are adding at the beginning, use this: 
		cout << "adding: " << "[" << newPage->id << "]-" << newPage->url << " (HEAD)\n";
	}
	else {

/*		WebPage* temp = head;

		// iteration goes here
		while (temp->id != previousPage->id)
		{
			temp = temp->next;
		}

		if (temp != NULL)
		{
			newPage->next = temp->next;
			temp->next = newPage;
		}
		else {
			// Otherwise use this: 
			previousPage->next = newPage;
			newPage->next = temp;
		}
 */
        newPage->next = previousPage->next;
        previousPage->next = newPage;
		cout << "adding: " << "[" << newPage->id << "]-" << newPage->url << " (prev: " << "[" << previousPage->id << "])\n";
	}
}

/*
 * Purpose: populates the BrowserHistory with the predetermined pages
 * @param none
 * @return none
 */
void BrowserHistory::buildBrowserHistory() {
	WebPage* number = new WebPage{14, 0, "https://www.numberphile.com/", "", NULL};
	WebPage* khan = new WebPage{13, 0, "https://www.khanacademy.org/", "", number};
	WebPage* brilliant = new WebPage{12, 0, "https://brilliant.org/", "", khan};
	WebPage* wikipedia = new WebPage{11, 0, "https://www.wikipedia.org/", "", brilliant};
	WebPage* colorado = new WebPage{10, 0, "https://www.colorado.edu/", "", wikipedia};

	addWebPage(nullptr, colorado);
	addWebPage(colorado, wikipedia);
	addWebPage(wikipedia, brilliant);
	addWebPage(brilliant, khan);
	addWebPage(khan, number);
}


/*
 * Purpose: Search the BrowserHistory for the specified
 * web page by ID and return a pointer to that node.
 * @param int id - ID of the web page to look for in LL.
 * @return pointer to node of page, or NULL if not found
 *
 */
WebPage* BrowserHistory::searchPageByID(int id) {
	// TODO
	WebPage* temp = head;

	// iteration goes here
	while (temp != NULL)
	{
		if (temp->id == id)
		{
			return(temp);
		}
		temp = temp->next;
	}

	return NULL;
}


/*
 * Purpose: Search the BrowserHistory for the specified
 * web page by the URL and return a pointer to that node.
 * @param string url - url of the web page to look for in LL.
 * @return pointer to node of page, or NULL if not found
 *
 */
WebPage* BrowserHistory::searchPageByURL(std::string url) {
	// TODO
	WebPage* temp = head;

	// iteration goes here
	while (temp != NULL)
	{
		//cout << "Searching " << temp->url << "   for   " << url << endl;
		if (temp->url == url)
		{
			return(temp);
		}
		temp = temp->next;
	}

	return NULL;
}

/*
 * Purpose: Give an owner to a web page.
 * @param receiver - name of the show that is receiving the rating
 * @param rating - the rating that is being given to a show
 * @return none
 */
void BrowserHistory::addOwner(std::string url, string owner) {
	// TODO

	WebPage* temp = searchPageByURL(url);
  
  	if(temp == nullptr)
    {
    	cout << "Page not found\n";
      	return;
    }

	temp->owner = owner;

	/*
	while (temp != NULL)
	{
		cout << "The owner (" << temp->owner << ") has been added for the ID - " << temp->id << "\n";

		WebPage* temp = searchPageByURL(url);

		temp->owner = owner;
	}
	*/
	cout << "The owner (" << temp->owner << ") has been added for the ID - " << temp->id << "\n"; //it's a bit hacky, but it should work

}

void BrowserHistory::updateViews(string url) {
	WebPage* temp = searchPageByURL(url);
	if (temp != NULL) {
		temp->views++;
/*
		while (temp != NULL)
		{
			WebPage* temp = searchPageByURL(url);

			temp->views++;
		}
*/
	}
}