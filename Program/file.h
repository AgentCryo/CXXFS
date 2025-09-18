//
// Created by Colton on 9/14/2025.
//

#ifndef CXXFS_FILE_H
#define CXXFS_FILE_H
#include <array>
#include <cstdint>
#include <string>

#include "drive.h"

enum class FileType : std::underlying_type_t<std::byte> {
    FOLDER = 0,
    TXT    = 1,
};

struct FileEntry {
    FileType type;                               // 8   bits
    char     name[32]; // File or folder name    // 32  bytes // 256 bits
    uint32_t loc;      // Location in disk image // 32  bits
    uint32_t size;     // Size of the txt       // 32  bits
    uint32_t owner_folder_loc;                   // 32  bits
    uint16_t held_files;                         // 16 bits
};                                               // 376 bits // 47 bytes

struct FileContent {
    FileContent();
    union {
        std::string generic_file_content;
        std::array<uint32_t, 980> folder_file_locs;
    };
    FileContent& operator=(const FileContent& fc)
    {
        generic_file_content = fc.generic_file_content;
        folder_file_locs = fc.folder_file_locs;
        return *this;
    }
    FileContent (const FileContent& fc)
    {
        generic_file_content = fc.generic_file_content;
        folder_file_locs = fc.folder_file_locs;
    }
};

class file
{
private:
    FileEntry file_entry{};
    FileContent file_content;
    
public:
    explicit file(const FileEntry& file, drive drive);  // Creates a folder in ram from hard drive
    [[nodiscard]] FileEntry getFileEntry() const;   // Just incase I need it
    void getFileContent(FileContent& content) const;
    void setFileContent(const FileContent& content);
    [[nodiscard]] uint8_t writeFileContent(file& folder, drive& drive) const;
};

#endif //CXXFS_FILE_H