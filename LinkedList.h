/*
 Name: Rohaan Kamaraj
 Email: rkamara1@asu.edu
 Description: This file contains a LinkedList implementation with basic methods, using the Publication
 class as it's nodes.
 */
#pragma once
#include <string>
#include "Publication.h"
#include <iostream>
using namespace std;

class LinkedList {

private:
    // private instance data
    Publication* head;

public:
    // public methods
    LinkedList();
    void addPublication(string isbn, string title, string publisher);
    bool removePublication(string isbn);
    bool searchPublication(string isbn);
    bool searchPublication(string isbn, string x); //overloaded method w/ an arbitrary string x parameter for the removePublication() in HashTable.h
    string searchLongestTitle();
    int getLength();
    void printList();

};

// constructor for LinkedList
LinkedList::LinkedList() {
    head = NULL;
}

// adds publication to the front of the linked list
void LinkedList::addPublication(string isbn, string title, string publisher) {
    if (head == NULL) {
        Publication* publication = new Publication(isbn, title, publisher);
        head = publication;
    } else {
        Publication* publication = new Publication(isbn, title, publisher);
        publication->setNext(head);
        head = publication;
    }
}

// removes the publication with the isbn passed in from the linked list if it's in there
bool LinkedList::removePublication(string newIsbn) {
    Publication* publication = head;
    bool isFound = false;

    // if list is empty
    if (head == NULL) {
        return isFound;
    }

    while (publication != NULL) {
        // if the publication to be removed is the head
        if (head->isbn == newIsbn) {
            publication = head;
            cout << "The Publication: " + publication->title + " with ISBN " +
                    publication->isbn + " is removed" << endl;
            head = head->next;
            delete publication;
            isFound = true;
            break;
        } else if (publication->next->isbn == newIsbn) {
            // if publication to be removed is not the head
            cout << "The Publication: " + publication->next->title + " with ISBN " +
                    publication->next->isbn + " is removed" << endl;
            Publication* newPublication = publication->next;
            publication->next = publication->next->next;
            delete newPublication;
            isFound = true;
            break;
        }
        publication = publication->next;
    }


    return isFound;
}

// searches the list to see if there exists a certain publication
bool LinkedList::searchPublication(string newIsbn) {
    Publication* publication = head;
    bool isFound = false;
    while (publication != NULL) {
        if (publication->isbn == newIsbn) {
            isFound = true;
            cout << "The Publication " + publication->title +
                    " with ISBN " + publication->isbn + " is found" << endl;
            break;
        }
        publication = publication->next;
    }
    return isFound;
}
// overloaded method w/ an arbitrary string x parameter for the removePublication() in HashTable.h:
// i removed the cout statement bc it would output that it was found in the console when the user
// used hash_delete
bool LinkedList::searchPublication(string newIsbn, string x) {
    Publication* publication = head;
    bool isFound = false;
    while (publication != NULL) {
        if (publication->isbn == newIsbn) {
            isFound = true;
            break;
        }
        publication = publication->next;
    }
    return isFound;
}

// this method finds the index and title of the publication with the longest title within the list
string LinkedList::searchLongestTitle() {
    Publication* publication = head;
    if (head == NULL) {
        return "";
    }

    int longest = publication->title.length();
    int currentLength = 0;
    int index = 0;
    int tracker = 0;
    string longestTitle = "";


    // determine the position of the title with the longest title
    while (publication != NULL) {
        currentLength = publication->title.length();
        if (currentLength > longest) {
            longest = currentLength;
            index = tracker;
        }
        publication = publication->next;
        tracker++;
    }

    // get the title from the publication with the longest title
    Publication* publication2 = head;
    int tracker2 = 0;
    while (publication2 != NULL) {
        if (tracker2 == index) {
            longestTitle = publication2->title;
            break;
        }
        tracker2++;
        publication2 = publication2->next;
    }


    return longestTitle;
}

// this method prints out the list in a nice way
void LinkedList::printList() {
    Publication* publication = head;
    if (publication == NULL) {
        cout << "The list is empty" << endl;
    } else {
        while (publication != NULL) {
            cout << "Publication: " + publication->title + ", ISBN: " + publication->isbn +
                    ", Publisher: " + publication->publisher << endl;
            publication = publication->next;
        }
    }
}

// this method calculates the amount of publications in the list and returns it
int LinkedList::getLength() {
    int length = 0;
    Publication* publication = head;

    while (publication != NULL) {
        length++;
        publication = publication->next;
    }

    return length;
}


