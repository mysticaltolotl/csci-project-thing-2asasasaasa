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
    DO NOT MODIFY THIS
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
    WebPage* temp = head->next;
  
  	// iteration goes here
    while(temp != NULL)
    {
        cout << "[ID::" << temp->id << "]-(URL::" << temp->url << ") -> ";
      	temp = temp->next;
    }
  	
  	cout << "NULL" << endl;
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
  
  	if(previousPage == nullptr)
    {
      head = newPage;
    }
  	else{
		WebPage* temp = previousPage->next;
  
  		// iteration goes here
        while(temp->id != previousPage->id)
        {
        	temp = temp->next;
        }
	}
    previousPage->next = newPage;
    newPage->next = temp;
}

/*
 * Purpose: populates the BrowserHistory with the predetermined pages
 * @param none
 * @return none
 */
void BrowserHistory::buildBrowserHistory() {
	Website colorado = {10, 0, "https://www.colorado.edu/", "", 11};
	Website wikipedia = {11, 0, "https://www.wikipedia.org/", "", 12};
	Website brilliant = {12, 0, "https://brilliant.org/", "", 13};
	Website khan = {13, 0, "https://www.khanacademy.org/", "", 14};
	Website number = {14, 0, "https://www.numberphile.com/", "", NULL};
  
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
    while(temp != NULL)
    {
        if(temp->id == id)
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
    while(temp != NULL)
    {
        if(temp->url == url)
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
}

void BrowserHistory::updateViews(string url) {
    // TODO
}