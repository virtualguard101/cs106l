#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <utility>


struct Album {
    std::string title;
    std::string artist;
    int year;
    int tracks;
    double price;
};

Album issueAlbum() {
    Album album;
    album.title = "The Dark Side of the Moon";
    album.artist = "Pink Floyd";
    album.year = 1973;
    album.tracks = 10;
    album.price = 10.99;
    return album;
}

const std::map<std::string, int> roman = {
    {"I", 1},
    {"V", 5},
    {"X", 10},
    {"L", 50},
    {"C", 100},
    {"D", 500},
    {"M", 1000}
};

// `using` is used to create an alias for a type.
using QuadradicSolution = std::pair<bool, std::pair<double, double>>;

QuadradicSolution solveQuadratic(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return {false, {NAN, NAN}};
    }
    double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
    double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
    return {true, {root1, root2}};
}

int main() {
    // `auto` is used to automatically deduce the type of the variable.
    auto result = solveQuadratic(1, 0, -1);
    if (result.first) {
        std::cout << "Root 1: " << result.second.first << std::endl;
        std::cout << "Root 2: " << result.second.second << std::endl;
    } else {
        std::cout << "No real roots" << std::endl;
    }
    return 0;
}
