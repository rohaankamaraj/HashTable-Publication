/*
 Name: Rohaan Kamaraj
 Email: rkamara1@asu.edu
 Description: This file contains a Hashtable Implementation with chaining: in other words, an array of
 Linked Lists, which I also implemented.
 */
#pragma once
#include <string>
#include "Publication.h"
#include "LinkedList.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class HashTable {

private:
    // private instance data
    LinkedList* hash;

public:
    // public methods & constructor
    HashTable(int userSize);
    int h(string title, int size);
    void insertPublication(string isbn, string title, string publisher, int size);
    void insertPublication(string isbn, string title, string publisher, int size, string x); // arbitrary string used to denote this as the initial populating insertion
    void searchPublication(string isbn, int size);
    void removePublication(string isbn, int size);
    void searchLongestTitle(int size);
    void printList(int size);

};

// HashTable constructor
HashTable:: HashTable(int userSize) {
    hash = new LinkedList[userSize];
}

// h() - calculates the key
int HashTable::h(string title, int size) {
    // length of the title % size
    int length = title.length();
    int placement = length % size;
    return placement;
}

// inserts the new publication in the proper place in hash table
void HashTable::insertPublication(string isbn, string title, string publisher, int size) {
    cout << "command: hash-insert" << endl;
    int placement = h(title, size);
    for (int i = 0; i < size; i++) {
        if (i == placement) {
            hash[i].addPublication(isbn, title, publisher);
            break;
        }
    }

}

// this method is for the initial insertions of publications; it takes out the hash-insert cout line. I used an arbitrary string as an extra parameter. If I don't
// do this, then when I initially create all the publications specified by the user, it'll print out hash-insert each time, which I don't want.
void HashTable::insertPublication(string isbn, string title, string publisher, int size, string x) {
    int placement = h(title, size);
    for (int i = 0; i < size; i++) {
        if (i == placement) {
            hash[i].addPublication(isbn, title, publisher);
            break;
        }
    }
}

// searches hash table for publication with same isbn
void HashTable::searchPublication(string userIsbn, int size) {
    cout << "hash_search" << endl;
    bool isFound = false;
    for (int i = 0; i < size; i++) {
        if (hash[i].searchPublication(userIsbn)) {
            // cout is already in the searchPublication(userIsbn) in Linked List
            isFound = true;
            break;
        }
    }

    if (!isFound) {
        cout << "The Publication with ISBN: " + userIsbn + " is not found" << endl;
    }
}

// removes publication with a certain isbn from the hash table
void HashTable::removePublication(string userIsbn, int size) {
    cout << "command: hash_delete" << endl;
    bool removed = false;
    for (int i = 0; i < size; i++) {
        if (hash[i].searchPublication(userIsbn, "")) {
            removed = true;
            hash[i].removePublication(userIsbn);
            break;
        }
    }

    if (!removed) {
        cout << "The Publication with ISBN: " + userIsbn + " is not removed" << endl;
    }
}

// finds the title with the longest title in the hash table
void HashTable::searchLongestTitle(int size) {
    // loop thru all index of array, get the largest of each
    // loop thru and determine which of the largest is the ultimate largest

    int largest = 0;
    int comparer = 0;
    int largestIndex = 0;

    for (int i = 0; i < size; i++) {
        comparer = hash[i].searchLongestTitle().length();
        if (comparer > largest) {
            largest = comparer;
            largestIndex = i;
        }
    }

    string longestTitle = hash[largestIndex].searchLongestTitle();

    cout << "The publication: " + longestTitle + " has the longest title size " +
            to_string(longestTitle.length()) << endl;

}

// prints out the hash table in a nice way
void HashTable::printList(int size) {
    cout << "command: hash_display" << endl;
    cout << endl;
    cout << "Hash Table Content" << endl;
    cout << "---------------------" << endl;
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << "index: " + to_string(i) + ", linked list size: " +
                to_string(hash[i].getLength()) << endl;
        hash[i].printList();
        cout << endl;
    }

    cout << "---------------------" << endl;
    cout << endl;

}





