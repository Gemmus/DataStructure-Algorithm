/*   Exercise 9 (Binary search tree using STL, 1p)

Implement a phone book application using STL binary tree (e.g. map container). It should be possible to add, remove and
list phone book entries. Entries are stored to the binary tree so that it is efficient to search, add and remove entries
from the container.

Hint: You can use getline() function to read a line from the input, and then create a function split() to split the
line to separate words. Then it is quite easy to check what was the command and (possible) parameters for the command.

Here is an example of the program output:

Phonebook application

add Victor Kulikov 123456
add Madonna 10
list
Content of the phone book:
Madonna: 10
Victor Kulikov: 123456
add Isaskar Keturi 900900
add Heidi Klum 100
erase Madonna
Unrecognized command ERASE
delete Madonnaz
Name Madonnaz does not found
delete Madonna
list
Content of the phone book:
Heidi Klum: 100
Isaskar Keturi: 900900
Victor Kulikov: 123456
exit

Hints:
split() : Use find() function to find the delimiter and then substr() to crab the string between delimiters and push it
          to the result vector.

to separate words: Another option is to first convert a given string to stringstream and then converting that to
istream_iterator<string> which can be given to copy() algorithm which copies it to the vector using back_inserter.
This works because istreambuf_iterator uses whitespace to separate strings (istreambuf_iterator does not do this).
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> words;
    stringstream ss(str);
    string word;
    while (getline(ss, word, delimiter)) {
        words.push_back(word);
    }
    return words;
}

int main() {
    map<string, string> phoneBook;
    cout << "Phone application" << endl;

    while (true) {
        string command;
        getline(cin, command);
        vector<string> words = split(command, ' ');

        if (words.empty()) {
            continue;
        }

        if (words[0] == "exit") {
            break;
        } else if (words[0] == "add" && words.size() == 4) {
            phoneBook[words[1] + " " + words[2]] = words[3];
        } else if (words[0] == "add" && words.size() == 3) {
            phoneBook[words[1]] = words[2];
        } else if (words[0] == "delete") {
            string name;
            if (words.size() == 3) {
                name = words[1] + " " + words[2];
            } else if (words.size() == 1) {
                cout << "No name was given with \"delete\" command." << endl;
            } else {
                name = words[1];
            }
            auto toBeDeleted = phoneBook.find(name);
            if (toBeDeleted != phoneBook.end()) {
                phoneBook.erase(toBeDeleted);
            } else {
                cout << "Name " << name << " does not found" << endl;
            }
        } else if (words[0] == "list") {
            cout << "Content of the phonebook:" << endl;
            if (!phoneBook.empty()) {
                for (const auto& entry : phoneBook) {
                    cout << entry.first << ": " << entry.second << endl;
                }
            } else {
                cout << "No entry." << endl;
            }
        } else {
            transform(words[0].begin(), words[0].end(), words[0].begin(), ::toupper);
            cout << "Unrecognized command " << words[0] << endl;
        }
    }

    return 0;
}
