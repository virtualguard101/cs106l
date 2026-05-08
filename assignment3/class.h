#pragma once

#include <set>
#include <string>
#include <utility>

class Album {
 private:
  std::string title;
  std::string artist;
  int year;
  std::pair<int, std::string> tracks;
  double price;
  std::set<std::string> songs;
  std::set<std::string> tags;
  void AddSong(std::string song);

 public:
  // Constructor
  Album(std::string title, std::string artist, int year, int track_count,
        std::string track_duration, double price);
  Album();
  // Destructor
  ~Album();

  // Getters
  std::string GetTitle() const;
  std::string GetArtist() const;
  int GetYear() const;
  std::pair<int, std::string> GetTracks() const;
  double GetPrice() const;
  std::set<std::string> GetSongs() const;

  // Setters
  void SetTitle(std::string title);
  void SetArtist(std::string artist);
  void SetYear(int year);
  void SetTracks(int track_count, std::string track_duration);
  void SetPrice(double price);

  // Other functions
  void AddTags(std::string tags);
};
