#include <iostream>

Book::Book(const Book& copy){
    strcpy(this->title,copy.gettitle());
    this->pages = copy.getpages();
}