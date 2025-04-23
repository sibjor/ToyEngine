#include "central.h"

class Profiler
{
public:
    void StartProfiling(const char *name)
    {
        CPUProfiler();
        MemoryProfiler();
        FrameRates();
    }

    void StopProfiling()
    {
        // Stop profiling logic
    }

    void SaveProfile(const char *filePath)
    {
        // Save profile data to file
    }

private:
    std::string dataPath = "data/";
    std::string profileName;
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;
    std::vector<std::pair<std::string, double>> profileData; // Store profiling data
    void CPUProfiler()
    {
        std::ifstream stat_file("/proc/stat");
        if (!stat_file.is_open())
        {
            std::cerr << "Failed to open /proc/stat" << std::endl;
            return;
        }

        std::string line;
        std::getline(stat_file, line);
        std::istringstream iss(line);

        std::string cpu;
        long user, nice, system, idle;
        iss >> cpu >> user >> nice >> system >> idle;

        long total = user + nice + system + idle;
        long usage = total - idle;

        std::cout << "CPU Usage: " << (usage * 100 / total) << "%" << std::endl;
        stat_file.close();

    };
    void MemoryProfiler(){
        std::ifstream meminfo_file("/proc/meminfo");
        if (!meminfo_file.is_open())
        {
            std::cerr << "Failed to open /proc/meminfo" << std::endl;
            return;
        }

        std::string line;
        long total_memory = 0;
        long free_memory = 0;

        while (std::getline(meminfo_file, line))
        {
            if (line.find("MemTotal:") == 0)
            {
                std::istringstream iss(line);
                std::string key;
                iss >> key >> total_memory;
            }
            else if (line.find("MemFree:") == 0)
            {
                std::istringstream iss(line);
                std::string key;
                iss >> key >> free_memory;
            }
        }

        meminfo_file.close();

        long used_memory = total_memory - free_memory;
        std::cout << "Memory Usage: " << (used_memory * 100 / total_memory) << "%" << std::endl;
        std::cout << "Total Memory: " << total_memory / 1024 << " MB" << std::endl;
    };
    void FrameRates()
    {
        static int frameCount = 0;
        static auto lastTime = std::chrono::high_resolution_clock::now();

        frameCount++;
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedTime = currentTime - lastTime;

        if (elapsedTime.count() >= 1.0)
        {
            std::cout << "Frame Rate: " << frameCount / elapsedTime.count() << " FPS" << std::endl;
            frameCount = 0;
            lastTime = currentTime;
        }
    };
};