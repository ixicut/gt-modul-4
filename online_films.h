#ifndef ONLINE_FILMS_H
#define ONLINE_FILMS_H

#include <QWidget>
#include <QList>
#include <QNetworkReply>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>

class Movie;

class OnlineFilms : public QWidget
{
    Q_OBJECT

public:
    explicit OnlineFilms(QWidget *parent = nullptr);
    ~OnlineFilms();

private slots:
    void searchMovies();
    void onNetworkReply(QNetworkReply *reply);
    void fetchMovieDetails(const QString &imdbID, Movie *movie);
    void onDetailsNetworkReply(QNetworkReply *reply, Movie *movie);
    void updateMovieList();

private:
    QList<Movie*> movieList;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QListWidget *movieListWidget;
};

#endif // ONLINE_FILMS_H
