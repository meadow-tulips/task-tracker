#include <iostream>
#include "taskReader.hpp"

int main(int argc, const char **argv)
{
    srand(time(0));

    TaskCLI::TaskReader _taskReader = TaskCLI::TaskReader();

    if (argc == 2)
    {
        _taskReader.displayTasks();
    }
    else if (argc == 3)
    {
        if (std::string(argv[1]) == "list")
        {
            _taskReader.displayTasks(argv[2]);
        }
        else if (std::string(argv[1]) == "delete")
        {
            _taskReader.deleteTask(argv[2]);
        }
        else if (std::string(argv[1]) == "add")
        {
            _taskReader.addTask(argv[2]);
        }
        else
        {
            _taskReader.updateStatus(argv[2], argv[1]);
        }
    }
    else if (argc == 4)
    {
        _taskReader.updateTask(argv[2], argv[3]);
    }
    else
    {
    }

    return 0;
}