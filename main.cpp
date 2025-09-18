#include <iostream>
#include <fstream>
#include <vector>

#include "Program/drive.h"

int main() {
    std::string path = R"(C:\Users\Colton\CLionProjects\CXXFS\hard_drive\drive.img)";

    drive hard_drive = drive(path);
    hard_drive.write(1024, "Hello Sector 2, Block 128, Offset 1024.");
    std::string read_data;
    hard_drive.read(1024, read_data, 39);
    std::cout << read_data << std::endl;

    return 0;
}
