#include "central.h"

class FileSystem
{
public:
    std::string LoadFile(const char *filePath)
    {
        std::ifstream file(filePath);
        if (!file.is_open())
        {
            std::cerr << "Error: Could not open file " << filePath << std::endl;
            return "";
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        file.close();
        return buffer.str();
    }

    // Pass ".png" to fileExtension to load all png files
    // Pass ".txt" to fileExtension to load all txt files
    std::vector<std::string> LoadAllFiles(const char *directoryPath, std::string fileExtension)
    {
        std::vector<std::string> loadedFiles;
        std::string extension = fileExtension;

        try
        {
            for (const auto &entry : std::filesystem::recursive_directory_iterator(directoryPath))
            {
                if (entry.is_regular_file() && entry.path().extension() == fileExtension)
                {
                    std::string filePath = entry.path().string();
                    std::cout << "Loading file: " << filePath << std::endl;

                    std::string fileContent = LoadFile(filePath.c_str());
                    if (!fileContent.empty())
                    {
                        loadedFiles.push_back(filePath);
                    }
                }
            }
        }
        catch (const std::filesystem::filesystem_error &e)
        {
            std::cerr << "Filesystem error: " << e.what() << std::endl;
        }

        return loadedFiles;
    }

    void FileSystem::SaveFile(const char *filePath, const char *data)
    {
        std::ofstream file(filePath);
        if (!file.is_open())
        {
            std::cerr << "Error: Could not open file for writing: " << filePath << std::endl;
            return;
        }

        file << data; // Skriv data till filen
        file.close();

        std::cout << "File saved successfully: " << filePath << std::endl;
    }
    void FileSystem::WriteFile(const char *filePath, const char *data)
    {
        std::ofstream file(filePath);
        if (!file.is_open())
        {
            std::cerr << "Error: Could not open file for writing: " << filePath << std::endl;
            return;
        }

        file << data; // Skriv data till filen
        file.close();

        std::cout << "File saved successfully: " << filePath << std::endl;
    }
};