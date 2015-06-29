#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void show(string &s)
{
    cout << s << endl;
}
int main()
{
    ifstream fin("test.txt");
    vector<string> wordlist;
    string s;
    int size;

    while(fin >> s)
        wordlist.push_back(s);
    size = wordlist.size();

    char play;
    cout << "Will you play a word game? <y/n>";
    cin >> play;
    play = tolower(play);

    while(play == 'y')
    {
        string target = wordlist[rand() % size];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length
             << " letters, and you guess \n"
             << "one letter at a time. You get " << guesses << " wrong guesses.\n";

        cout << "You word: " << attempt << endl;

        while(guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess one letter: ";
            cin >> letter;

            if(badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
            {
                cout << "You already guess it, Try again.\n";
                continue;
            }

            int loc = target.find(letter);

            if(loc == string::npos)
            {
                guesses--;
                cout << "bad guess!\n";
                badchars += letter;
            }
            else
            {
                attempt[loc] = letter;
                loc = target.find(letter, loc + 1);
                while(loc != string::npos){
                        attempt[loc] = letter;
                        loc = target.find(letter, loc + 1);
                }
            }

            cout << "You word: " << attempt << endl;
            if(attempt != target){
                if(badchars.length() != 0)
                        cout << "Bad choices: " << badchars << endl;
                cout << guesses << " guesses left\n";
            }
        }

        if(guesses > 0)
                cout << "That's right! \n";
        else
                cout << "Sorry, the word is " << target << ".\n";
        cout << "Will you play again? <y/n>";
        cin >> play;
        play = tolower(play);

    }
    return 0;
}
