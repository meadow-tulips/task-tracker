#include <string>
#include "../lib/nlohmann/json.hpp"

namespace TaskCLI
{
    enum Taskstatus
    {
        TO_DO,
        IN_PROGRESS,
        DONE
    };

    class Task
    {
    private:
        int id;
        std::string description;
        Taskstatus status;
        time_t updatedAt;
        time_t createdAt;

    public:
        Task(std::string description);
        nlohmann::json generateJson();
        void displayTask();
        int getTaskId();
    };
};