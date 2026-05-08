#include "class.h"

#include <utility>

Album::Album(std::string title, std::string artist, int year, int track_count,
             std::string track_duration, double price)
    : title{title},
      artist{artist},
      year{year},
      tracks{std::make_pair(track_count, track_duration)},
      price{price},
      songs{std::set<std::string>()} {}

Album::Album()
    : title{"Unknown"},
      artist{"Unknown"},
      year{1970},
      tracks{std::make_pair(0, "00:00:00")},
      price{0.0},
      songs{std::set<std::string>()} {}

Album::~Album() { songs.clear(); }

std::string Album::GetTitle() const { return title; }

std::string Album::GetArtist() const { return artist; }

int Album::GetYear() const { return year; }

std::pair<int, std::string> Album::GetTracks() const { return tracks; }

double Album::GetPrice() const { return price; }

std::set<std::string> Album::GetSongs() const { return songs; }

void Album::SetTitle(std::string title) { this->title = title; }

void Album::SetArtist(std::string artist) { this->artist = artist; }

void Album::SetYear(int year) { this->year = year; }

void Album::SetTracks(int track_count, std::string track_duration) {
  this->tracks = std::make_pair(track_count, track_duration);
}

void Album::SetPrice(double price) { this->price = price; }

void Album::AddSong(std::string song) { songs.insert(song); }