#ifndef MOVIE_H
#define MOVIE_H

#include <QString>

class Movie
{
public:
    Movie();

    QString getTitle() const;
    void setTitle(const QString &title);

    QString getYear() const;
    void setYear(const QString &year);

    QString getDirector() const;
    void setDirector(const QString &director);

    QString getRating() const;
    void setRating(const QString &rating);

private:
    QString title;
    QString year;
    QString director;
    QString rating;
};

#endif // MOVIE_H
