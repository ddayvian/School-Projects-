/*
Author: Dayvian Pena
Course: CSCI-135
Instructor: Enxhi Osmanllari
Project 2 A
PROJECT TIME!!
We will be making a playlist system to keep the order of songs. Similar to Project 1, we will be using global arrays to store song information. 
The difference is, these arrays are going to be dynamically allocated!
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits> 
#include <stdlib.h>
#include <sstream>

using namespace std;

int g_capacity = 2;
int g_size = 0;

class Song {
    public:
        string name;
        string artist;
        int duration;
        string genre;
};

Song *g_songs = new Song[g_capacity];


/*
    @post             :   Replace the old global
                          dynamically allocated arrays
                          with new dynamically allocated
                          arrays of twice the size 
                          ('g_curr_size' * 2). Update
                          'g_curr_size' accordingly.
                          Make sure you copy the contents
                          of the older arrays. Do this
                          for the following global-arrays:
                          'g_song_names', 'g_artist_names', 
                          'g_song_durations', 'g_genres'
*/
void allocateNew(){
    g_capacity *= 2;
    
    Song *songs = new Song[g_capacity];

    for (int i = 0; i < g_size; i++){
        songs[i].name = g_songs[i].name;
        songs[i].artist = g_songs[i].artist;
        songs[i].duration = g_songs[i].duration;
        songs[i].genre = g_songs[i].genre;
    }

    delete[] g_songs;
    g_songs = songs;

};
/*
    @param            :   The string with the 'filename'
    @post             :   Reads the song, artists,
                          song durations and genres into 
                          the global-arrays and set the 
                          value of 'g_number_of_songs'
                          to the number of songs read.
                          Call 'allocateNew()' to allocate 
                          an array of larger size if the 
                          dynamic arrays reach full 
                          capacity.
*/
void readSongs(string filename){
string file_line;
ifstream fin(filename);
if (fin.fail()){
    cerr << "Error, this file cant be accesed" << endl;
    exit(1);
}

while (getline(fin,file_line)){
    if(g_size == g_capacity){
        allocateNew();
    }

int pos = file_line.find(":");
int pos2 = file_line.find("-");
int pos3 = file_line.rfind("-");
int pos4 = file_line.find("mins");

g_songs[g_size].name = file_line.substr(0, pos); //receiving name 
g_songs[g_size].artist = file_line.substr(pos+1, pos2-pos-1); // receiving artist name
g_songs[g_size].genre = file_line.substr(pos2+1, pos3-pos2-1); // receiving genre
g_songs[g_size].duration = stoi(file_line.substr(pos3+1, pos4-pos3-1)); // receiving duration, stoi changes string to int
g_size++;
}

fin.close();
}


Song * getGenreSongs (string genre, int& genreCount)
{
    genreCount = 0;

    Song *genreSongs = new Song[g_size];

    for (int i = 0; i < g_size; i++)
        if (g_songs[i].genre == genre)
        {
            genreSongs[i] = g_songs[i];
            genreCount++;
        }

        return genreSongs;
}

Song * getSongsFromDuration(int duration, int &durationsCount, int filter)
{
    durationsCount = 0;

    Song *durationSongs = new Song[g_size];

    for (int i = 0; i < g_size; i++)
        if ((filter == 0 && g_songs[i].duration > duration) || (filter == 1 && g_songs[i].duration < duration) || (filter == 2 && g_songs[i].duration == duration))
        {
            durationSongs[i] = g_songs[i];
            durationsCount++;
        }

    return durationSongs;
}

string * getUniqueArtists(int &uniqueCount)
{
    uniqueCount = 0;
    string *unique = new string[g_size];

    for (int i = 0; i < g_size; i++)
    {
        int similar = 0;

        for (int j = 0; j < uniqueCount; j++)
            if (g_songs[i].artist == unique[j])
            {
                similar++;
            }
        if (similar == 0)
        {
            unique[i] = g_songs[i].artist;
            uniqueCount++;
        }
    }

    return unique;
}

string getFavoriteArtist()
{
    if (g_size == 0)
        return "NONE";
    int uniqueCount = 0;

    string *unique = getUniqueArtists(uniqueCount);

    //makes array and sets counts for each unique artist to 0
    int counts [uniqueCount];
    for (int i = 0; i < uniqueCount; i ++){
        counts[i] = 0;
    }

    for (int i = 0; i < uniqueCount; i++)
        for (int j = 0; j < g_size; j++)
            if (unique[i] == g_songs[j].artist){

                counts[i]++;
            }
    int maximum = 0;

    for (int i = 0; i < uniqueCount; i++)
        if (counts[i] > maximum)
            maximum = counts[i];
    for (int i = 0; i < uniqueCount; i++)
        if (maximum == counts[i])
            return unique[i];

    return "NONE";

}

int main(){
    
    
    return 0;
}

