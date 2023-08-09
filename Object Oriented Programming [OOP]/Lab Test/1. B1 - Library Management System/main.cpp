#include <iostream>
using namespace std;

class Book{
    int bookID;
    string bookTitle;
    string authorName;
    bool isAvailable;
public:
    Book()
    {
        bookID = 0;
        bookTitle = "";
        authorName = "";
        isAvailable = true;
    }
    Book(int bookID, string bookTitle, string authorName, bool isAvailable)
    {
        this->bookID = bookID;
        this->bookTitle = bookTitle;
        this->authorName = authorName;
        this->isAvailable = isAvailable;
    }
    void display()
    {
        cout << "Book ID : " << bookID << endl;
        cout << "Book Title : " << bookTitle << endl;
        cout << "Author Name : " << authorName << endl;
        cout << "Is Available : " << isAvailable << endl;
    }
};

class LibraryManager{
    Book B[100];
    int availableBooks;
public:
    LibraryManager()
    {
        availableBooks = 0;
    }
    static int CountAvailableBooks(Book * books, int numBooks)
    {
        Book *ptr = books;
        for(int i = 0; i < numBooks; i++)
    }
    static void CopyBooks(Book * source, Book destination, int sumBooks)
    {

    }
};

int main()
{
    int n = 2;
    cout << "OK\n" << endl;
    return 0;
}
