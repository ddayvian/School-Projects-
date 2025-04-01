/*
Author: Dayvian Pena
Course: CSCI-135
Instructor: Enxhi Osmanllari
Project 1C
Languages evolve constantly. 
Hundreds of new English words are added to the English dictionary each year. 
Definitions of words change. Thus, we should be able to modify, add and remove words in our dictionary.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits> 
#include <stdlib.h>

using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];
/*
    @param            :   The string with the `filename`
    @post             :   Reads the words, definitions
                          pos into the global-arrays 
                          and set the value of `g_word_count`
                          to the number of words read
*/
void readWords(string filename){
ifstream fin(filename);
if (fin.fail()){
    cerr <<" File cannot be open for reading." <<endl;
    exit(1);
}
string word,pos,semicolon,def,space_holder,new_def;

while(fin >> word >> pos >> semicolon){
    getline(fin,def);
    for(int j = 1; j < def.length(); j++){
        new_def = new_def + def[j];
    }
    g_words[g_word_count] = word;
    g_pos[g_word_count] = pos;
    g_definitions[g_word_count] = new_def;
    new_def= "";
    g_word_count ++;
}
fin.close();
}
/*
int main()
{
 readWords("filename.txt");
for (int i = 0; i < g_word_count; i++){
    cout<<g_words[i]<<endl;
    cout<<g_pos[i]<<endl;
    cout<<g_definitions[i]<<endl;
}
return 0;

}
*/

/*
    @param            :   The string with a query word
    @return           :   Integer index of the word in
                          `g_words` global-array. Returns
                          -1 if the word is not found
    @post             :   Find the index of given `word`
                          in the `g_words` array. Return -1
                          if word is not in the array
*/

int getIndex(string word){
    for (int i = 0; i < g_word_count; i++){
        if(g_words[i] == word)
        return i;
    }
return -1;
}
/*
    @param            :   The string with a query word
    @return           :   Return the string definition of
                          the word from  `g_definitions`
                          global-array. Return "NOT_FOUND" if
                          word doesn't exist in the dictionary
    @post             :   Find the definition of the given `word`
                          Return "NOT_FOUND" otherwise
*/
string getDefinition(string word){
    for(int i=0; i<g_word_count; i++){
        if (g_words[i]==word)
        return g_definitions[i];
    }
return "NOT_FOUND";
}
/*
    @param            :   The string with a query word
    @return           :   Return the string definition of
                          the word from  `g_definitions`
                          global-array. Return "NOT_FOUND" if
                          word doesn't exist in the dictionary
    @post             :   Find the definition of the given `word`
                          Return "NOT_FOUND" otherwise
*/
string getPOS(string word){
    for(int i = 0;i<g_word_count;i++){
        if(g_words[i]==word)
        return g_pos[i];
    }
return "NOT_FOUND";
}
/*
    @param            :   The string with a query word
    @return           :   Return the string definition of
                          the word from  `g_definitions`
                          global-array. Return "NOT_FOUND" if
                          word doesn't exist in the dictionary
    @post             :   Find the definition of the given `word`
                          Return "NOT_FOUND" otherwise
*/
int countPrefix(string prefix){
    int count = 0;
    for(int i=0; i<g_word_count;i++){
        if(prefix == g_words[i].substr(0,prefix.length()))
        count ++;
    }
    return count;
}

/*
    @param word       :   The string with a new word
    @param definition :   The string with the definition of the
                          new `word`
    @param pos        :   The string with the pos of the new `word`
    @return           :   return `true` if the word is
                          successfully added to the dictionary
                          return `false` if failed (word already
                          exists or dictionary is full)
    @post             :   Add the given `word`, `definition`, `pos`
                          to the end of the respective
                          global-arrays.
                          The word should not be added to the
                          global-arrays if it already exists 
                          or if the array reached maximum 
                          capacity(`g_MAX_WORDS`).
                          Update `g_word_count` if the word is
                          successfully added
*/
bool addWord(string word, string definition, string pos)
{
    if (g_word_count == 1000 || getIndex(word) != -1)
    {
        return false;
    }
    g_words[g_word_count] = word;
    g_definitions[g_word_count] = definition;
    g_pos[g_word_count] = pos;
    g_word_count++;
    return true;

}
/*
    @param word       :   The string with the word that is to
                          be edited
    @param definition :   The string with the new definition of 
                          the `word`
    @param pos        :   The string with the new pos of the `word`
    @return           :   return `true` if the word is successfully
                          edited, return `false` if the `word`
                          doesn't exist in the dictionary
    @post             :   Replace the given `word`'s  definition
                          and pos with the given `definition` and
                          `pos` (by modifying global-arrays
                          `g_definitions` and `g_pos`).
                          The modification will fail if the word
                          doesn't exist in the dictionary
*/
bool editWord(string word, string definition, string pos)
{
   
    if (getIndex(word)==-1)
    {
        return false;
    }
    int index = getIndex(word);
    
    g_definitions[index] = definition;
    g_pos[index] = pos;
    
}
/*
    @param            :   The string with the word that is to
                          be removed
    @return           :   return `true` if the word is successfully
                          removed from the dictionary return `false`
                          if the word doesn't exist in the dictionary
    @post             :   Remove the given `word`, `word`'s
                          definition and `word`'s pos from the
                          respective global-arrays if the word
                          exists.  
                          Update `g_word_count` if the word is
                          successfully removed
*/
bool removeWord(string word)
{
    if (getIndex(word)==-1)
    {
        return false;
    }
    int index = getIndex(word);
    for (int i = index; i< g_word_count; i++)
    {
        g_words[i]=g_words[i+1];
        g_definitions[i]=g_definitions[i+1];
        g_pos[i]=g_pos[i+1];
    } g_word_count--;
    return true;
}

string getRandomWord()
{
    srand((unsigned) time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}
/*
    @param            :   The string with a word from the dictionary 
    @return           :   string of "_" based on the number of
                          characters in the given `word` 
    @post             :   Return string of "_" based on the length
                          of the given `word`.
                          For example, if the word is "game", then
                          the function would return "____". In other
                          words, a string of four "_"s.
*/
string maskWord(string word)
{
    string makenew = "";
 for (int i = 0; i < word.length(); i++){
    makenew += "_";
 }
 return makenew;
}
/*
    @param            :   The integer for the difficulty of the game
                          (0 for easy, 1 for normal, and 2 for hard) 
    @return           :   The number of tries given the `difficulty`
                          (9 for easy, 7 for normal, and 5 for hard)
    @post             :   Return the number of tries based on given
                          difficulty (0-easy: 9 tries, 1-normal: 7
                          tries, 2-Hard: 5 tries) 
*/
int getTries(int difficulty)
{
    if ( difficulty == 0){
        return 9;
    }
    else if (difficulty == 1){
        return 7;
    }
    else if (difficulty == 2){

        return 5;
    }
    return -1;
}
/*
    @param tries      :   The integer for remaining tries 
    @param difficulty :   The integer for the difficulty of the game 
                          (0 for easy, 1 for normal, and 2 for hard) 
    @post             :   prints the number of lives left and number
                          of lives used using "O" and "X". DO NOT
                          PRINT AN ENDLINE

    For example : calling `printAttemps(2, 1)` would print "OOXXXXX". 
                  Based on given `difficulty`, we know the total tries
                  is 7 (from `getTries(1)`). Also, the player has 2
                  `tries` remaining based on the given parameter.
                  Therefore, the function prints two "O"s to indicate
                  the remaining tries and 5 "X"s to indicate the tries
                  that have been used (7-2=5)          
*/
void printAttempts(int tries, int difficulty)
{
    for (int i = 0; i < tries; i++){
        
        cout<<"O";
    }
    for (int j = 0; j < getTries(difficulty) - tries; j++)
    {
        cout<<"X";
    }
}
/*
    @param word       :   The string word from the dictionary
    @param letter     :   The char letter that that will be revealed
    @param(&) current :   The string representing a masked word
    @return           :   `true` if the `letter` exists in `word`,
                          otherwise return `false`  
    @post             :   If the given `letter` exists in `word`
                          reveal the `letter` in `current` masked word
                          and return `true`. Otherwise, return `false`

    For example : Let's say we have the following main function:
                  int main(){
                      string w = "g___";
                      cout << revealLetter("good", 'o', "g___") << endl;
                      cout <<  w << endl;
                  }
                  The first `cout` will print 1 because the letter 'o'
                  exists in "good". Thus, the function returned `true`.
                  The second `cout` will print "goo_". The variable `w`
                  has been modified by the function to reveal all the
                  `o`s in "good" resulting in "goo_"           
*/
bool revealLetter(string word, char letter, string &current)
{
    bool found = false;
    for (int i = 0; i <word.length(); i++){
        if (word[i]==letter){

            current[i]=letter;
            found = true; 
        }
    }
}

// game-loop for Hangman
void gameLoop() {
    int difficulty, tries;
    string word, current;
    char letter;
    while (true) {
        cout << "Welcome to Hangman!" << endl;
        cout <<  "0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
        cin >> difficulty;
        while (difficulty < 0 || difficulty > 3) {
            cout <<  "Enough horseplay >_< !\n0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
            cin >> difficulty;
        }
        if (difficulty == 3) {
            cout << "If you're hangry, go grab a bite! See what I did there?" << endl;
            break;
        }
        word = getRandomWord();
        current = maskWord(word);
        tries = getTries(difficulty);
        while (tries != 0) {
            cout << "Life: ";
            printAttempts(tries, difficulty);
            cout << endl << "Word: "<< current << endl;
            cout << "Enter a letter: ";
            cin >> letter;
            
            if (!revealLetter(word, letter, current)) {
                tries--;
            }
            if (current == word) {
                break;
            }
            if (tries == 2) {
                cout << "The part of speech of the word is "<< getPOS(word) << endl;
            }
            if (tries == 1) {
                cout << "Definition of the word: " << getDefinition(word) << endl;
            }
        }
        if (tries == 0) {
            cout << "The word is \"" << word << "\". Better luck next time! You're getting the ..ahem.. hang of it." << endl;
        }
        else {
            cout << "Congrats!!!" << endl;
        }
    }
}
