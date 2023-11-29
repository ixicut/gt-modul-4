#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPushButton>
#include "online_films.h"
#include "movie.h"

OnlineFilms::OnlineFilms(QWidget *parent) : QWidget(parent)
{
    searchLineEdit = new QLineEdit(this);
    searchButton = new QPushButton("Search", this);
    movieListWidget = new QListWidget(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(searchLineEdit);
    mainLayout->addWidget(searchButton);
    mainLayout->addWidget(movieListWidget);
    setLayout(mainLayout);

    connect(searchButton, &QPushButton::clicked, this, &OnlineFilms::searchMovies);
}

OnlineFilms::~OnlineFilms()
{
    qDeleteAll(movieList);
}

void OnlineFilms::searchMovies()
{
    QString apiKey = "ac77ec59";
    QString searchText = searchLineEdit->text().trimmed();

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a search query.");
        return;
    }

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, &OnlineFilms::onNetworkReply);

    QNetworkRequest request;
    QString url = "http://www.omdbapi.com/?apikey=" + apiKey + "&s=" + searchText;
    request.setUrl(QUrl(url));

    manager->get(request);
}

void OnlineFilms::onNetworkReply(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        QMessageBox::critical(this, "Error", "Error in network request: " + reply->errorString());
        reply->deleteLater();
        return;
    }

    QByteArray data = reply->readAll();
    reply->deleteLater();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);

    if (jsonDoc.isNull()) {
        QMessageBox::critical(this, "Error", "Error parsing JSON data.");
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();

    if (jsonObj.contains("Error")) {
        QMessageBox::warning(this, "Warning", jsonObj.value("Error").toString());
        return;
    }

    qDeleteAll(movieList);
    movieList.clear();

    QJsonArray moviesArray = jsonObj.value("Search").toArray();
    for (const QJsonValue &movieValue : moviesArray) {
        QJsonObject movieObject = movieValue.toObject();

        Movie *movie = new Movie();
        movie->setTitle(movieObject.value("Title").toString());
        movie->setYear(movieObject.value("Year").toString());

        QString imdbID = movieObject.value("imdbID").toString();
        fetchMovieDetails(imdbID, movie);
    }
}

void OnlineFilms::fetchMovieDetails(const QString &imdbID, Movie *movie)
{
    QString apiKey = "ac77ec59";

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, [=](QNetworkReply *reply) {
        onDetailsNetworkReply(reply, movie);
        manager->deleteLater();
    });

    QNetworkRequest request;
    QString url = "http://www.omdbapi.com/?apikey=" + apiKey + "&i=" + imdbID;
    request.setUrl(QUrl(url));

    manager->get(request);
}

void OnlineFilms::onDetailsNetworkReply(QNetworkReply *reply, Movie *movie)
{
    if (reply->error() != QNetworkReply::NoError) {
        QMessageBox::critical(this, "Error", "Error in network request: " + reply->errorString());
        reply->deleteLater();
        return;
    }

    QByteArray data = reply->readAll();
    reply->deleteLater();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);

    if (jsonDoc.isNull()) {
        QMessageBox::critical(this, "Error", "Error parsing JSON data for movie details.");
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();

    if (jsonObj.contains("Error")) {
        QMessageBox::warning(this, "Warning", jsonObj.value("Error").toString());
        return;
    }

    QString director = jsonObj.value("Director").toString();
    movie->setDirector(director);


    QString rating = jsonObj.value("imdbRating").toString();
    movie->setRating(rating);

    movieList.append(movie);
    updateMovieList();
}

void OnlineFilms::updateMovieList()
{
    movieListWidget->clear();

    for (Movie *movie : movieList) {
        QString itemText = movie->getTitle() + " (" + movie->getYear() + ") - Director: " + movie->getDirector() + "; Rating - " + movie->getRating();
        QListWidgetItem *item = new QListWidgetItem(itemText);
        movieListWidget->addItem(item);
    }
}
