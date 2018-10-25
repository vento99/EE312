//
// Created by avento on 10/24/2018.
//

#ifndef LAB5_SONG_H
#define LAB5_SONG_H

#include <string>

using namespace std;

class Song
{
    private:
        string title;
        string artist;
        int size;

    public:
        Song();
        Song(string songArtist, string songTitle, int songSize);
        //Song(string artist)
        string getTitle() const;
        void setTitle(string songTitle);
        string getArtist() const;
        void setArtist(string songArtist);
        int getSize() const;
        void setSize(int songSize);

        bool operator >(Song const &rhs);
        bool operator ==(Song const &rhs);
        bool operator <(Song const &rhs);

        ~Song();
};



#endif //LAB5_SONG_H


