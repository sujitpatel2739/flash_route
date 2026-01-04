#ifndef FLASHSEND_FILES_FILEENTRY_H
#define FLASHSEND_FILES_FILEENTRY_H

#include <string>
#include <cstdint>

namespace flashsend
{

// Stable identifier used to reference a shared file
using FileId = std::uint32_t;

// Immutable metadata describing a shared file.
// This class does NOT perform any filesystem or I/O operations.
class FileEntry
{
public:
    explicit FileEntry(FileId id,
                       std::string absolutePath,
                       std::string displayName,
                       std::uint64_t fileSizeBytes);

    // Read-only accessors
    FileId id() const;
    std::string absolutePath() const;
    std::string displayName() const;
    std::uint64_t fileSize() const;

    // Identity comparison (by FileId)
    bool operator==(const FileEntry& other) const;
    bool operator!=(const FileEntry& other) const;

private:
    FileId id_;
    std::string absolutePath_;
    std::string displayName_;
    std::uint64_t fileSizeBytes_;
};

} // namespace flashsend

#endif // FLASHSEND_FILES_FILEENTRY_H
