//***************************************************************************
//
// Karina Torhan
// Z2111032
// CSCI 340 -OPE1 20268
// Assignment 06 Word Scanner
// Due Date: 10/6/26, 5:00 PM
// I certify that this is my own work and where appropriate an extension
// of the starter code provided for the assignment.
//
//***************************************************************************

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

// output layout
const int NO_ITEMS = 4;
const int ITEM_WORD_WIDTH = 14;
const int ITEM_COUNT_WIDTH = 3;

// function declarations
void get_words(map<string, int>&);
void print_words(const map<string, int>&);
void clean_entry(const string&, string&);

int main()
{
    map<string, int> words;

    get_words(words);
    print_words(words);

    return 0;
}

void get_words(map<string, int>& words)
{
    string original_word;
    string cleaned_word;

    // read and count cleaned words
    while (cin >> original_word)
    {
        clean_entry(original_word, cleaned_word);

        if (cleaned_word.length() > 0)
        {
            words[cleaned_word]++;
        }
    }
}

void print_words(const map<string, int>& words)
{
    int item_count = 0;
    int total_words = 0;

    // print words in map order
    for (map<string, int>::const_iterator entry = words.begin();
         entry != words.end(); ++entry)
    {
        cout << left << setw(ITEM_WORD_WIDTH) << entry->first
             << ":" << setw(ITEM_COUNT_WIDTH) << entry->second;

        ++item_count;
        total_words += entry->second;

        if (item_count % NO_ITEMS == 0)
        {
            cout << '\n';
        }
    }

    if (item_count % NO_ITEMS != 0)
    {
        cout << '\n';
    }

    // print stream totals
    cout << "number of words in input stream   :" << total_words << '\n';
    cout << "number of words in output stream  :" << words.size() << '\n';
}

void clean_entry(const string& original_word, string& cleaned_word)
{
    // find the first alphanumeric character
    string::const_iterator first = find_if(
        original_word.begin(),
        original_word.end(),
        [](char character)
        {
            return isalnum(static_cast<unsigned char>(character));
        });

    // stop at the first non-alphanumeric character
    string::const_iterator last = find_if(
        first,
        original_word.end(),
        [](char character)
        {
            return !isalnum(static_cast<unsigned char>(character));
        });

    cleaned_word.assign(first, last);

    // convert the cleaned word to lowercase
    for_each(
        cleaned_word.begin(),
        cleaned_word.end(),
        [](char& character)
        {
            character = static_cast<char>(
                tolower(static_cast<unsigned char>(character)));
        });
}