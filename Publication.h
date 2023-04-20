/*
 Name: Rohaan Kamaraj
 Email: rkamara1@asu.edu
 Description: This file contains the Publication class, which is a node for the LinkedList I created
 */
#pragma once
#include <string>

using namespace std;

class Publication {

private:
    // private instance data
    string isbn;
    string title;
    string publisher;
    Publication* next;

public:
    // public methods
    Publication(string userIsbn, string userTitle, string userPublisher);
    void setNext(Publication* userNext);

    // this class is a friend for LinkedList
    friend class LinkedList;

};
// constructor
Publication::Publication(string userIsbn, string userTitle, string userPublisher) {
    isbn = userIsbn;
    title = userTitle;
    publisher = userPublisher;
}
// setNext to point to next Publication in a list
void Publication::setNext(Publication* userNext) {
    next = userNext;
}





