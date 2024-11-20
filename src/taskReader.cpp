#include "../lib/nlohmann/json.hpp"
#include <filesystem>
#include "taskReader.hpp"

void TaskCLI::TaskReader::addTask(std::string description)
{

    std::ifstream ifs = std::ifstream(filepath, std::ios_base::in);
    Task task(description);

    nlohmann::json data = task.generateJson();
    nlohmann::json existingData;
    ifs >> existingData;
    ifs.close();
    existingData.update(data);

    std::ofstream ofs = std::ofstream(filepath, std::ios_base::out);
    ofs << std::setw(4) << existingData << std::endl;
    ofs.close();

    std::cout << "Task added successfully (ID: " << task.getTaskId() << ")" << std::endl;
}

void TaskCLI::TaskReader::updateTask(const std::string taskId, const std::string description)
{
    std::ifstream ifs = std::ifstream(filepath, std::ios_base::in);

    nlohmann::json existingData;
    ifs >> existingData;
    ifs.close();

    if (existingData.contains(taskId))
    {
        existingData[taskId]["description"] = description;
        existingData[taskId]["updatedAt"] = time(0);

        std::ofstream ofs = std::ofstream(filepath, std::ios_base::out);
        ofs << std::setw(4) << existingData << std::endl;
        ofs.close();
    }
}

void TaskCLI::TaskReader::updateStatus(const std::string taskId, const std::string nextStatus)
{
    std::ifstream ifs = std::ifstream(filepath, std::ios_base::in);

    nlohmann::json existingData;
    ifs >> existingData;
    ifs.close();
    if (existingData.contains(taskId))
    {
        if (nextStatus == "mark-in-progress")
        {
            existingData[taskId]["status"] = TaskCLI::Taskstatus::IN_PROGRESS;
            existingData[taskId]["updatedAt"] = time(0);
        }
        else if (nextStatus == "mark-todo")
        {
            existingData[taskId]["status"] = TaskCLI::Taskstatus::TO_DO;
            existingData[taskId]["updatedAt"] = time(0);
        }
        else if (nextStatus == "mark-done")
        {
            existingData[taskId]["status"] = TaskCLI::Taskstatus::DONE;
            existingData[taskId]["updatedAt"] = time(0);
        }
        else
        {
        }

        std::ofstream ofs = std::ofstream(filepath, std::ios_base::out);
        ofs << std::setw(4) << existingData << std::endl;
        ofs.close();
    }
}

void TaskCLI::TaskReader::deleteTask(const std::string taskId)
{

    std::ifstream ifs = std::ifstream(filepath, std::ios_base::in);

    nlohmann::json existingData;
    ifs >> existingData;
    ifs.close();

    existingData.erase(taskId);
    std::ofstream ofs = std::ofstream(filepath, std::ios_base::out);
    ofs << std::setw(4) << existingData << std::endl;
    ofs.close();
}

void TaskCLI::TaskReader::displayTasks(const std::string &type)
{
    std::fstream fs = std::fstream(filepath, std::ios_base::in);
    fs.seekg(std::ios::beg);
    nlohmann::json data = nlohmann::json::parse(fs);
    if (type == "")
    {
        for (auto &el : data.items())
        {

            std::cout << el.value() << '\n';
        }
    }
    else if (type == "done")
    {
        for (auto &el : data.items())
        {

            if (el.value()["status"] == TaskCLI::Taskstatus::DONE)
                std::cout << el.value() << '\n';
        }
    }
    else if (type == "in-progress")
    {
        for (auto &el : data.items())
        {

            if (el.value()["status"] == TaskCLI::Taskstatus::IN_PROGRESS)
                std::cout << el.value() << '\n';
        }
    }
    else if (type == "todo")
    {
        for (auto &el : data.items())
        {

            if (el.value()["status"] == TaskCLI::Taskstatus::TO_DO)
                std::cout << el.value() << '\n';
        }
    }
    else
    {
    }
}

TaskCLI::TaskReader::TaskReader()
{
    std::fstream fs = std::fstream(filepath);

    if (!fs.is_open())
    {
        fs.open(filepath, std::ios_base::out);
        auto j = nlohmann::json::object();
        fs << j;
    }
    else
    {
        if (!nlohmann::json::accept(fs))
        {
            std::ofstream ofs = std::ofstream(filepath, std::ios_base::out);
            ofs << nlohmann::json::object();
            ofs.close();
        }
    }
    fs.close();
}

TaskCLI::TaskReader::~TaskReader()
{
}
