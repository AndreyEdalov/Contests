#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads;
    using Workload = std::pair<std::string, int>;

    Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads);

    int getTotalLoad() const {
        int total = 0;
        for (const auto& workload : workloads) {
            total += workload.second;
        }
        return total;
    }

    bool operator<(const Task& other) const {
        if (this->getTotalLoad() == other.getTotalLoad()) {
            if (this->date == other.date) {
                return this->text < other.text; // Finally, compare by text
            }
            return this->date < other.date; // First, if workloads are equal, compare by date
        }
        return this->getTotalLoad() < other.getTotalLoad(); // First compare by total workload
    }
};

Task::Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads)
    : text(text), date(date), workloads(workloads) {}

struct Worker {
    std::string name;
    std::string login;
    int maxLoad;

    Worker(const std::string& name, const std::string& login, int maxLoad);

    bool isOverworked(const std::vector<Task>& tasks) const;
};

Worker::Worker(const std::string& name, const std::string& login, int maxLoad)
    : name(name), login(login), maxLoad(maxLoad) {}


bool Worker::isOverworked(const std::vector<Task>& tasks) const {
    int totalLoad = 0;
    for (const auto& task : tasks) {
        auto it = task.workloads.find(login);
        if (it != task.workloads.end()) {
            totalLoad += it->second;
        }
    }
    return totalLoad > maxLoad;
}



void sortTasks(std::vector<Task>& tasks) {
    std::sort(tasks.begin(), tasks.end());
}

int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker) {
    int totalLoad = 0;
    for (const auto& task : allTasks) {
        auto it = task.workloads.find(worker.login);
        if (it != task.workloads.end()) {
            totalLoad += it->second;
        }
    }
    return totalLoad;
}

void addTask(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers) {
    std::map<std::string, int> tempWorkloads;
    for (const auto& workload : newTask.workloads) {
        tempWorkloads[workload.first] += workload.second;
    }
    for (const auto& task : tasks) {
        for (const auto& workload : task.workloads) {
            tempWorkloads[workload.first] += workload.second;
        }
    }
    for (const auto& worker : workers) {
        auto found = tempWorkloads.find(worker.login);
        if (found != tempWorkloads.end() && found->second > worker.maxLoad) {
            // Worker's total workload exceeds their maxLoad
            throw std::runtime_error("Overworked");
        }
    }
    tasks.push_back(newTask);
}

void addTaskVerbose(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers) {
    std::map<std::string, int> tempWorkloads;

    for (const auto& workload : newTask.workloads) {
        tempWorkloads[workload.first] += workload.second;
    }

    for (const auto& task : tasks) {
        for (const auto& workload : task.workloads) {
            tempWorkloads[workload.first] += workload.second;
        }
    }
    std::vector<std::string> overworkedDetails;
    for (const auto& worker : workers) {
        auto found = tempWorkloads.find(worker.login);
        if (found != tempWorkloads.end() && found->second > worker.maxLoad) {
            // Calculate the difference by which the worker is overworked
            int overWorkedBy = found->second - worker.maxLoad;
            // Create detailed message for each overworked worker
            std::stringstream message;
            message << worker.login << " by " << overWorkedBy;
            overworkedDetails.push_back(message.str());
        }
    }
    if (!overworkedDetails.empty()) {
        std::sort(overworkedDetails.begin(), overworkedDetails.end());
        std::string errorMessage = "Overworked: " + overworkedDetails[0];
        for (size_t i = 1; i < overworkedDetails.size(); ++i) {
            errorMessage += ", " + overworkedDetails[i];
        }
        throw std::runtime_error(errorMessage);
    }
    tasks.push_back(newTask);
}


