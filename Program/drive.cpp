#include "drive.h"

#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

drive::drive(std::string hard_drive_path) {
    this->hard_drive_path = std::move(hard_drive_path);
}

uint8_t drive::write(uint32_t writeLoc, std::string data)
{
    std::ofstream out(hard_drive_path, std::ios::binary | std::ios::in | std::ios::out);
    if (!out) {
        std::cerr << "Failed to open disk image for writing.\n";
        return 1;
    }

    out.seekp(writeLoc);
    out.write(data.data(), data.size());

    out.close();
    //std::cout << "Data written successfully.\n";
    return 0;
}

uint8_t drive::read(uint32_t readLoc, std::string& data,  std::size_t size)
{
    std::ifstream in(hard_drive_path, std::ios::binary);
    if (!in) {
        std::cerr << "Failed to open disk image for reading.\n";
        return 1;
    }

    in.seekg(readLoc);
    data.resize(size);
    in.read(&data[0], size);

    in.close();

    //std::cout << "Read data: " << data << '\n';
    return 0;
}
