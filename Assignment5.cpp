/*
 Name: Rohaan Kamaraj
 Email: rkamara1@asu.edu
 Description: This file contains all the user input and user interfacing. I create a hash table
 and manipulate or display it's data in different ways based on what the user types.
 */

/*
 Hash Analysis:
 When I was thinking about how to write my hash function, I knew that I wanted to do something with the
 title of each publication. So, I decided to use the amount of characters in each title. In order to make
 sure that all the publications would fit in the array, I modded the amount of characters per title
 by the size of the array. For example, if a publication with a title containing 48 characters is in a
 size 8 array, it would be stored in index 0, because 48 % 8 = 0. Yes, my hash function worked well, and
 the number of collisions was reasonable and within my expectations. I didn't have to change my function
 to reduce the number of collisions.
 */

#include "HashTable.h"
#include <string>
#include <iostream>

using namespace std;

int main() {

    cout << "Please enter a hash table size: " << endl;
    int size;
    cin >> size;

    // creating the hash table
    HashTable* table = new HashTable(size);

    cout << "How many publications will be inserted? " << endl;
    int numPublications;
    cin >> numPublications;
    // take input, assign values to variables, then insert it at that position.
    for (int i = 0; i < numPublications; i++) {
        string line;
        getline(cin >> ws, line);
        string divider, isbn, title, publisher;
        int count = 0;
        // split the input
        while (line != divider) {
            divider = line.substr(0,line.find_first_of("/"));
            line = line.substr(line.find_first_of("/") + 1);
            if (count == 0) {
                isbn = divider;
            } else if (count == 1) {
                title = divider;
            } else if (count == 2) {
                publisher = divider;
            }
            count++;
        }

        table->insertPublication(isbn,title, publisher, size, "");

    }

    cout << "Please enter a number of commands: " << endl;
    int commands;
    cin >> commands;

    // this for loop will take in and handle the amount of commands as instructed by the user
    for (int i = 0; i < commands; i++) {
        string input;
        getline(cin >> ws, input);

        string line, inside;
        line = input.substr(0, input.find_first_of(","));

        if (input == "hash_display") {
            table->printList(size);
        }
        else if (input == "hash_longest_title") {
            table->searchLongestTitle(size);
        }
        else if (line == "hash_search") {
            // if passed in hash_search, the rest of the input (aka the isbn) is stored and processed
            inside = input.substr(input.find_first_of(",") + 1);
            table->searchPublication(inside, size);
        }
        else if (line == "hash_delete") {
            // if passed in hash_delete, the rest of the input (aka the isbn) is stored and processed
            inside = input.substr(input.find_first_of(",") + 1);
            table->removePublication(inside, size);
        }
        else if (line == "hash_insert") {
            // if passed in hash_insert, then the rest of the input gets split and stored in variables
            string divider, isbn, title, publisher;
            int count = 0;
            inside = input.substr(input.find_first_of(",") + 1);
            while (inside != divider) {
                divider = inside.substr(0, inside.find_first_of(","));
                inside = inside.substr(inside.find_first_of(",") + 1);
                if (count == 0) {
                    isbn = divider;
                } else if (count == 1) {
                    title = divider;
                } else if (count == 2) {
                    publisher = divider;
                }
                count++;
            }
            table->insertPublication(isbn, title, publisher, size);
        }
        cout << endl;
    }

    return 0;

}

