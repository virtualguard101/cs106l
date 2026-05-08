/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include "class.h"
#include <iostream>

void sandbox() {
  Album album("Lunar Calendar - EP", "r-906", 2023, 6, "00:22:00", 7.74);
  Album album2;

  std::cout << album.GetTitle() << std::endl;
  std::cout << album.GetArtist() << std::endl;
  std::cout << album.GetYear() << std::endl;
  auto album_tracks = album.GetTracks();
  std::cout << album_tracks.first << " tracks, " << album_tracks.second
            << std::endl;
  std::cout << album.GetPrice() << std::endl;

  std::cout << album2.GetTitle() << std::endl;
  std::cout << album2.GetArtist() << std::endl;
  std::cout << album2.GetYear() << std::endl;
  auto album2_tracks = album2.GetTracks();
  std::cout << album2_tracks.first << " tracks, " << album2_tracks.second
            << std::endl;
  std::cout << album2.GetPrice() << std::endl;

  album2.SetTitle("diaLOG");
  album2.SetArtist("r-906");
  album2.SetYear(2024);
  album2.SetTracks(9, "00:28:46");
  album2.SetPrice(21.99);

  std::cout << album2.GetTitle() << std::endl;
  std::cout << album2.GetArtist() << std::endl;
  std::cout << album2.GetYear() << std::endl;
  album2_tracks = album2.GetTracks();
  std::cout << album2_tracks.first << " tracks, " << album2_tracks.second
            << std::endl;
  std::cout << album2.GetPrice() << std::endl;
}