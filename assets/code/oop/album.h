#include <string>

class Album {
private:
    std::string title;
    std::string artist;
    int year;
    int tracks;
    double price;
    const int music_count;

public:
    Album(std::string title, std::string artist,
    int year, int tracks,
    double price);

    std::string GetTitle() const;
    std::string GetArtist() const;
    int GetYear() const;
    int GetTracks() const;
    double GetPrice() const;

    void SetTitle(std::string title);
    void SetArtist(std::string artist);
    void SetYear(int year);
    void SetTracks(int tracks);
    void SetPrice(double price);
};
