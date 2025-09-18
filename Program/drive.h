#ifndef CXXFS_DRIVE_H
#define CXXFS_DRIVE_H
#include <cstdint>
#include <string>

class drive {
public:
    explicit drive(std::string hard_drive_path);
    uint8_t write(uint32_t writeLoc, std::string data);
    uint8_t read(uint32_t readLoc, std::string& data,  std::size_t size);

private:
    std::string hard_drive_path;
};


#endif //CXXFS_DRIVE_H