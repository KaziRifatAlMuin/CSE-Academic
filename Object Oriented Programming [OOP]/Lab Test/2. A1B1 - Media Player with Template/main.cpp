#include <iostream>
using namespace std;

class MediaPlayer{
public:
    MediaPlayer(){}
    virtual void Play() = 0;
    virtual void Pause() = 0;
    virtual void Stop() = 0;
    virtual void display() = 0;
};

class Magazine : virtual public MediaPlayer{
    string Title;
    string Author;
    int numberOfPages;
public:
    Magazine(string Title, string Author, int numberOfPages)
    {
        this->Title = Title;
        this->Author = Author;
        this->numberOfPages = numberOfPages;
    }
    void Play(){
        cout << "Opening a Magazine\n";
    }
    void Pause(){
        cout << "Pausing a Magazine\n";
    }
    void Stop(){
        cout << "Closing a Magazine\n";
    }
    void display(){
        cout << "It is a Magazine\n";
        cout << "Title : " << Title << "\n";
        cout << "Author : " << Author << "\n";
        cout << "numberOfPages : " << numberOfPages << "\n\n";
    }
};

class Movie : virtual public MediaPlayer{
    string Title;
    string Director;
    int durationinMinutes;
public:
    Movie(string Title, string Director, int durationinMinutes)
    {
        this->Title = Title;
        this->Director = Director;
        this->durationinMinutes = durationinMinutes;
    }
    void Play(){
        cout << "Playing a Movie\n";
    }
    void Pause(){
        cout << "Pausing a Movie\n";
    }
    void Stop(){
        cout << "Stopping a Movie\n";
    }
    void display(){
        cout << "It is a Movie\n";
        cout << "Title : " << Title << "\n";
        cout << "Director : " << Director << "\n";
        cout << "durationinMinutes: " << durationinMinutes << "\n\n";
    }
};

class Music : virtual public MediaPlayer{
    string Title;
    string Artist;
    int durationinSeconds;
public:
    Music(string Title, string Artist, int durationinSeconds)
    {
        this->Title = Title;
        this->Artist = Artist;
        this->durationinSeconds = durationinSeconds;
    }
    void Play(){
        cout << "Playing a Music\n";
    }
    void Pause(){
        cout << "Pausing a Music\n";
    }
    void Stop(){
        cout << "Stopping a Music\n";
    }
    void display(){
        cout << "It is a Music\n";
        cout << "Title : " << Title << "\n";
        cout << "Artist : " << Artist << "\n";
        cout << "durationinSeconds : " << durationinSeconds << "\n\n";
    }
};

class VideoGame : virtual public MediaPlayer{
    string Title;
    int Rating;
    int Prize;
public:
    VideoGame(string Title, int Rating, int Prize)
    {
        this->Title = Title;
        this->Rating = Rating;
        this->Prize = Prize;
    }
    void Play(){
        cout << "Opening a Video Game\n";
    }
    void Pause(){
        cout << "Pausing a Video Game\n";
    }
    void Stop(){
        cout << "Stopping a Video Game\n";
    }
    void display(){
        cout << "It is a Video Game\n";
        cout << "Title : " << Title << "\n";
        cout << "Rating : " << Rating << "\n";
        cout << "Prize : " << Prize << "\n\n";
    }
};

template <typename T>
void showDetails(T &obj)
{
    MediaPlayer *p = &obj;
    p->display();
}

int main()
{
    Magazine ob1("ABC", "Mr. X", 201);
    Movie ob2("Hero", "Mr. Y", 142);
    Music ob3("Love", "Mr. Z", 350);
    VideoGame ob4("FIFA", 2072, 10000);

    showDetails(ob1);
    showDetails(ob2);
    showDetails(ob3);
    showDetails(ob4);

    ob1.Play();
    ob1.Pause();
    ob1.Stop();

    ob2.Play();
    ob2.Pause();
    ob2.Stop();

    ob3.Play();
    ob3.Pause();
    ob3.Stop();

    ob4.Play();
    ob4.Pause();
    ob4.Stop();

    return 0;
}
