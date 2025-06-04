#pragma once

#include <string>
#include <vector>

class Playlist {
public:
    // Load playlist from a text file (one path per line)
    bool loadFromFile(const std::string& path);

    // Save playlist to a text file
    bool saveToFile(const std::string& path) const;

    // Add a new entry
    void add(const std::string& entry);

    // Remove entry at index
    void remove(size_t index);

    // Clear playlist
    void clear();

    // Get current entry
    const std::string& current() const;

    // Move to next entry; returns false if at end
    bool next();

    // Move to previous entry; returns false if at beginning
    bool previous();

    size_t size() const { return entries.size(); }
    size_t index() const { return currentIndex; }
    void setIndex(size_t idx);

    const std::vector<std::string>& getEntries() const { return entries; }

private:
    std::vector<std::string> entries;
    size_t currentIndex = 0;
};
