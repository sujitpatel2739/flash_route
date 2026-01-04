#ifndef FLASHSEND_FILES_FILEINDEX_H
#define FLASHSEND_FILES_FILEINDEX_H

#include <vector>
#include <unordered_map>
#include <cstdint>
#include <string>

#include "FileEntry.h"

namespace flashsend
{

// Manages and owns metadata for all shared files.
// Responsible for ID assignment, limits enforcement, and lookup.
class FileIndex
{
public:
    explicit FileIndex(std::size_t maxFiles,
                       std::uint64_t maxFileSizeBytes);

    // Adds a single file entry.
    // Returns false if limits are exceeded.
    bool addFile(const std::string& absolutePath,
                 const std::string& displayName,
                 std::uint64_t fileSizeBytes);

    // Adds multiple files atomically.
    // Returns false if any file violates constraints.
    bool addFiles(const std::vector<std::string>& absolutePaths,
                  const std::vector<std::string>& displayNames,
                  const std::vector<std::uint64_t>& fileSizesBytes);

    // Lookup file metadata by ID.
    // Returns nullptr if not found.
    const FileEntry* findFile(FileId id) const;

    // Read-only queries
    std::size_t fileCount() const;

    // Clears all tracked files and resets ID counter.
    void clear();

private:
    std::size_t maxFiles_;
    std::uint64_t maxFileSizeBytes_;

    FileId nextFileId_;

    std::vector<FileEntry> files_;
    std::unordered_map<FileId, std::size_t> idToIndex_;
};

} // namespace flashsend

#endif // FLASHSEND_FILES_FILEINDEX_H
