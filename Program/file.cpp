#include "file.h"

#include <algorithm>
#include <sstream>

#include "drive.h"

file::file(const FileEntry& file, drive drive)
{
    file_entry = file;
    drive.read(file_entry.loc + 64, file_content, file_entry.size);
}

FileEntry file::getFileEntry() const
{
    return file_entry;
}

void file::getFileContent(FileContent& content) const
{
    content = file_content;
}

void file::setFileContent(const FileContent& content)
{
    file_content = content;
}

uint8_t file::writeFileContent(file& folder, drive& drive) const
{
    if (folder.getFileEntry().type == FileType::FOLDER)
    {
        // Setting Folder Information
        FileContent* folderContent = new FileContent();
        getFileContent(*folderContent);
        folderContent->folder_file_locs[file_entry.held_files+1] = file_entry.loc;
        folder.setFileContent(*folderContent);
        //std::string // Sorry Giving Up
        drive.read(folder.getFileEntry().owner_folder_loc, )
        folder.getFileEntry().owner_folder_loc
        //
    }
    
    /*if (folder.getDirectoryFile().isFolder)
    {
        std::string folderContent = folder.getFileContent();
        folder.setFileContent(folderContent + std::to_string(file_entry.offset));
        std::ostringstream builder;
        builder << file_entry.name;
        builder << file_entry.size;
        builder << file_content;
        return drive.write(file_entry.offset, builder.str());
    } else {
        return 2; // Error: not a folder;
    }*/
}
