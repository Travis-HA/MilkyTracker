#include "Playlist.h"
#include <fstream>
#include <algorithm>

bool Playlist::loadFromFile(const std::string& path) {
    std::ifstream in(path.c_str());
    if (!in.is_open())
        return false;
    entries.clear();
    std::string line;
    while (std::getline(in, line)) {
        if (!line.empty())
            entries.push_back(line);
    }
    currentIndex = 0;
    return true;
}

bool Playlist::saveToFile(const std::string& path) const {
    std::ofstream out(path.c_str());
    if (!out.is_open())
        return false;
    for (const auto& e : entries)
        out << e << "\n";
    return true;
}

void Playlist::add(const std::string& entry) {
    entries.push_back(entry);
}

void Playlist::remove(size_t index) {
    if (index < entries.size()) {
        entries.erase(entries.begin() + index);
        if (currentIndex >= entries.size())
            currentIndex = entries.empty() ? 0 : entries.size() - 1;
    }
}

void Playlist::clear() {
    entries.clear();
    currentIndex = 0;
}

const std::string& Playlist::current() const {
    static const std::string empty;
    if (entries.empty())
        return empty;
    return entries[currentIndex];
}

bool Playlist::next() {
    if (currentIndex + 1 >= entries.size())
        return false;
    ++currentIndex;
    return true;
}

bool Playlist::previous() {
    if (currentIndex == 0)
        return false;
    --currentIndex;
    return true;
}

void Playlist::setIndex(size_t idx) {
    if (idx < entries.size())
        currentIndex = idx;
}
