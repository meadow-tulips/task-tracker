#include "task.hpp"
#include <iostream>
#include <fstream>

namespace TaskCLI
{
    class TaskReader
    {
        std::filesystem::path filepath = std::filesystem::current_path() / "example.json";

    public:
        void addTask(std::string description);
        void updateTask(const std::string taskId, const std::string description);
        void updateStatus(const std::string taskId, const std::string nextStatus);
        void deleteTask(const std::string taskId);
        void displayTasks(const std::string & = "");
        TaskReader();
        ~TaskReader();
    };
};