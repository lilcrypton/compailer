#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

bool isDesiredExtension(const fs::path &filePath)
{
    std::string extension = filePath.extension().string();
    return (extension == ".cpp" || extension == ".h");
}

void processFilesRecursively(const fs::path &folderPath, std::string &fileconcat)
{
    for (const auto &entry : fs::recursive_directory_iterator(folderPath))
    {
        if (entry.is_regular_file() && isDesiredExtension(entry.path()))
        {
            fileconcat += entry.path().string() + " ";
        }
    }
}

int main()
{
    std::string outputName = "";
    std::cout << "output name :";
    std::cin >> outputName;
    std::string folderPath = "";
    std::cout << "path to folder :";
    std::cin >> folderPath;
    if (folderPath == "")
    {
        return -1;
    }
    else
    {
        std::string toolName = "g++ ";
        std::string fileconcat = "";

        processFilesRecursively(folderPath, fileconcat);

        std::string compileCommand = toolName + fileconcat + "-o " + outputName;
        system(compileCommand.c_str());

        return 0;
    }
}
