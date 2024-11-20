#include <iostream>
#include <ctime>
#include "task.hpp"

TaskCLI::Task::Task(std::string description)
{
    this->description = description;
    this->id = rand() % 10001;
    this->createdAt = time(0);
    this->updatedAt = this->createdAt;
    this->status = TO_DO;
}

nlohmann::json TaskCLI::Task::generateJson()
{
    nlohmann::json j;
    j[std::to_string(this->id)]["id"] = this->id;
    j[std::to_string(this->id)]["description"] = this->description;
    j[std::to_string(this->id)]["createdAt"] = this->createdAt;
    j[std::to_string(this->id)]["updatedAt"] = this->updatedAt;
    j[std::to_string(this->id)]["status"] = this->status;

    return j;
}

void TaskCLI::Task::displayTask()
{
    std::cout << std::endl
              << this->id << " " << this->description << std::endl;
}

int TaskCLI::Task::getTaskId()
{
    return id;
}