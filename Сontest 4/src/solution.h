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


//
//This C++ code defines a simple task management system, focusing on tasks, workers, and their respective workloads. Let's break down the main components and functionalities of this system:
//
//Struct Task
//Attributes:
//text: Descriptive text of the task.
//date: The due date of the task, as a string.
//workloads: A map where keys are worker logins and values are the amount of work (as an integer) assigned to that worker for this task.
//Methods:
//getTotalLoad(): Calculates the total workload of the task by summing all individual workloads.
//operator<: Defines a comparison operator to enable sorting of tasks. Tasks are primarily compared by their total workload, then by date, and finally by their text description.
//Constructor: Initializes a Task object with given text, date, and workloads.
//Struct Worker
//Attributes:
//name: The worker's name.
//login: A unique identifier for the worker (used in the workloads map of Task).
//maxLoad: The maximum workload this worker can handle.
//Methods:
//isOverworked(): Determines if assigning the given tasks would exceed the worker's maxLoad.
//Constructor: Initializes a Worker object with a given name, login, and maximum load.
//Global Functions
//sortTasks(std::vector<Task>& tasks): Sorts tasks based on their total
//workload, date, and text, in that order, utilizing the overloaded < operator defined in the Task struct.
//
//getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker): Calculates the total workload assigned to a specific worker across all tasks.
//
//addTask(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers): Adds a new task to the list of tasks if doing so does not result in any worker being overworked beyond their maxLoad. It throws a std::runtime_error with the message "Overworked" if adding the task would exceed any worker's capacity.
//
//addTaskVerbose(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers): Similar to addTask, but provides a more detailed error message in case of overwork. It lists each overworked worker's login and the amount by which they are overworked, then sorts these details alphabetically by worker login before constructing and throwing the error message.
//
//Key Concepts Illustrated by the Code
//Object-Oriented Design: The code demonstrates basic principles of object-oriented programming (OOP), including encapsulation (bundling data and methods that operate on the data into classes) and the use of constructors for initializing objects.
//
//Exception Handling: The addTask and addTaskVerbose functions demonstrate exception handling by throwing an exception when a logical condition (a worker being overworked) is met. This is a crucial aspect of robust software design, allowing for error conditions to be communicated and managed effectively.
//
//Standard Template Library (STL) Usage: The code makes extensive use of the C++ Standard Template Library, including data structures like std::vector, std::map, and std::string, as well as algorithms such as std::sort. This showcases the power and flexibility of the STL for handling common data structures and algorithms.
//
//Sorting and Comparators: Custom sorting logic is implemented through the overloaded < operator in the Task struct, demonstrating how custom comparison logic can be defined for sorting complex objects.
//
//Aggregation and Composition: The system design illustrates the concept of aggregation and composition, where Task objects contain a collection of workloads related to various workers, and the overall task list aggregates multiple Task objects.
//
//Error Reporting with Details: The addTaskVerbose function exemplifies a pattern of detailed error reporting, where not just the fact of an error (overwork) is reported, but specific details about the error condition (which workers are overworked and by how much) are also included. This can greatly aid in debugging and user feedback.
//
//Overall, this code provides a concise yet comprehensive example of a small, object-oriented system in C++, demonstrating several key programming concepts and best practices.
//
