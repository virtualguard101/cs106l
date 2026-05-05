#include <iostream>
#include <map>
#include <tuple>


int TemperatureWaring(double temp) {
    if (temp > 100.0) {
        std::cout << "Emergency: The temperature is too high!" << std::endl;
        return -1;
    } else {
        std::cout << "Temperature normal." << std::endl;
        return 0;
    }
}

void EmergencyCaller(int warning_res) {
    if (warning_res == -1) {
        std::cout << "Calling the emergency cooling system..." << std::endl;
        // __call the emergency cooling system__
    } else {
        std::cout << "Nothing to do." << std::endl;
    }
    std::cout << '\n';
}

// Uniform initialization of a map
const std::map<std::string, int> roman{
    {"I", 1},
    {"V", 5},
    {"X", 10},
    {"L", 50},
    {"C", 100},
    {"D", 500},
    {"M", 1000}
};

// Structured Binding
std::tuple<std::string, std::string, int, int, double> getAlbum(
    std::string t,
    std::string a,
    int y,
    int tr,
    double p
) {
    std::string title = t;
    std::string artist = a;
    int year = y;
    int tracks = tr;
    double price = p;
    return {title, artist, year, tracks, price};
}

int main() {
    double TempReading(100.55);

    // Direct Initialization
    int temp = TempReading; // crirical implicit error: narrowing conversion!!!
    int res1 =  TemperatureWaring(temp);
    EmergencyCaller(res1);

    // Uniform Initialization
    // int temp2 = {TempReading}; // This will cause a compile error: narrowing conversion!!!
    double temp2{TempReading};
    int res2 =  TemperatureWaring(temp2);
    EmergencyCaller(res2);

    // Structured Binding
    auto [title, artist, year, tracks, price] = getAlbum(
        "The Dark Side of the Moon",
        "Pink Floyd",
        1973, 
        0, 
        0.99
    );
    std::cout << "Title: " << title << std::endl;
    std::cout << "Artist: " << artist << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Tracks: " << tracks << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << '\n';

    return 0;
}
