#ifndef FLASHSEND_FILES_FILESTREAMER_H
#define FLASHSEND_FILES_FILESTREAMER_H

#include <cstddef>
#include <cstdint>
#include <string>

namespace flashsend
{

// Sequential, RAII-based file reader used for streaming file contents.
// Opens the file on construction and guarantees closure on destruction.
class FileStreamer
{
public:
    // Takes ownership of the file path and prepares for streaming.
    explicit FileStreamer(std::string absolutePath,
                          std::uint64_t expectedSizeBytes);

    // Ensures the underlying file handle is closed.
    ~FileStreamer() noexcept;

    // Non-copyable
    FileStreamer(const FileStreamer&) = delete;
    FileStreamer& operator=(const FileStreamer&) = delete;

    // Reads up to bufferSize bytes into buffer.
    // Returns number of bytes read, or 0 when streaming is complete.
    std::size_t readChunk(char* buffer, std::size_t bufferSize);

    // Returns true when no more bytes can be read.
    bool isComplete() const;

    // Returns total number of bytes successfully read so far.
    std::uint64_t bytesRead() const;

private:
    std::string filePath_;
    std::uint64_t expectedSizeBytes_;
    std::uint64_t bytesRead_;
    void* fileHandle_;
};

} // namespace flashsend

#endif // FLASHSEND_FILES_FILESTREAMER_H
