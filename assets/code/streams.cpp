// Streams: a general I/O ~~facility~~ abstraction for C++
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <string>
#include <tuple>


int CheckPath() {
    if (!std::filesystem::exists("assets/code/output")) {
        // standard logging output stream
        std::clog << "Creating output directory..." << std::endl;
        std::filesystem::create_directories("assets/code/output");
        return 0;
    } else {
        std::clog << "Path already exists" << std::endl;
        return 1;
    }
    std::cout << '\n';
}

std::string GetUserInput() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    return input;
}

std::tuple<std::string, std::string, std::string> ConvertToStringStream(std::string input) {
    std::stringstream ss(input);
    std::string first, second;
    std::string rest;
    ss >> first >> second; // only get the first two words
    std::getline(ss, rest); // get the rest of the string until get `\n`
    std::cout << first << " " << second << " " << rest << std::endl;
    std::cout << '\n';
    return std::make_tuple(first, second, rest);
}

void FlushAnyway() {
    // will get a mess output
    std::ios::sync_with_stdio(false);
    for (int i = 0; i < 6; i++) {
        std::cout << i << std::endl;
        std::cout << i << '\n';
    }
    std::cout << '\n';
}

void WriteToFile(const std::string& filename, const std::string& content) {
    if (CheckPath() == 0) {
        std::ofstream ofs("assets/code/output/out.txt"); // create a file stream object
        if (ofs.is_open()) {
            std::clog << "Writing to file..." << std::endl;
            ofs << content << '\n'; // write to the file
            std::clog << "File written successfully" << std::endl;
            ofs.close(); // close the file stream
        } else {
            // standard error output stream
            std::cerr << "Failed to open file" << std::endl;
        }
    }
    std::cout << '\n';
    return;
}

void ReadFromFile(const std::string& filename) {
    std::ifstream ifs(filename);
    std::string line;
    if (ifs.is_open()) {
        std::clog << "Reading from file..." << '\n';
        while (std::getline(ifs, line)) {
            std::cout << line << '\n';
        }
    } else {
        std::cerr << "Failed to open file" << '\n';
    }
    std::cout << '\n';
}

int main() {
    FlushAnyway();

    std::string input = GetUserInput();
    std::tuple<std::string, std::string, std::string> tuple = ConvertToStringStream(input);
    WriteToFile("assets/code/output/out.txt", input);

    ReadFromFile("assets/code/output/out.txt");
    
    return 0;
}
