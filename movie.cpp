#include "movie.h"

Movie::Movie()
{
}

QString Movie::getTitle() const
{
    return title;
}

void Movie::setTitle(const QString &title)
{
    this->title = title;
}

QString Movie::getYear() const
{
    return year;
}

void Movie::setYear(const QString &year)
{
    this->year = year;
}

QString Movie::getDirector() const
{
    return director;
}

void Movie::setDirector(const QString &director)
{
    this->director = director;
}

QString Movie::getRating() const
{
    return rating;
}

void Movie::setRating(const QString &rating)
{
    this->rating = rating;
}
