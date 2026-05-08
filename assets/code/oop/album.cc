#include "album.h"

Album::Album(std::string title, std::string artist, int year, int tracks,
             double price)
    : title(title),
      artist(artist),
      year(year),
      tracks(tracks),
      price(price),
      music_count(tracks) {}

std::string Album::GetTitle() const { return title; }

std::string Album::GetArtist() const { return artist; }

int Album::GetYear() const { return year; }

int Album::GetTracks() const { return tracks; }

double Album::GetPrice() const { return price; }

void Album::SetTitle(std::string title) { this->title = title; }

void Album::SetArtist(std::string artist) { this->artist = artist; }

void Album::SetYear(int year) { this->year = year; }