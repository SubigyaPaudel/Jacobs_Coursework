#include <iostream>
#include <cstdlib>
#include <cstring>

class Book
{
private:
    const char *title;
    int pages;

public:
    Book();
    //Book(const Book&);
    Book(const char *, int);
    void settitle(const char *newtitle) { title = newtitle; }
    void setpages(int newpages) { pages = newpages; }
    const char *gettitle() const { return title; }
    int getpages() const { return pages; }
    void printbook() const;
};

Book::Book()
{
    title = "Unknown";
    pages = 0;
}
/*
Book::Book(const Book &copy)
{
    title = copy.title;
    pages = copy.pages;
}
*/
Book::Book(const char *newtitle, int newpages)
{
    title = newtitle;
    pages = newpages;
}

void Book::printbook() const
{
    printf("Name of the book %s\n", title);
    printf("Number of pages: %d\n", pages);
}

int main()
{
    Book one("Inferno", 600);
    Book two("Angels and demons", 400);
    Book three(one);
    one.printbook();
    two.printbook();
    three.printbook();
    return 0;
}
