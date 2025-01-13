#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a job
struct Job {
    int id;
    int priority;
    string description;

    // Comparator for Min-Heap (Lower priority number = Higher priority)
    bool operator>(const Job& other) const {
        return priority > other.priority;
    }
};

// Priority Queue (Min-Heap)
priority_queue<Job, vector<Job>, greater<Job>> jobQueue;

// Function to add a new job
void addJob(int id, int priority, string description) {
    jobQueue.push({id, priority, description});
    cout << "Job Added: " << description << " (Priority: " << priority << ")\n";
}

// Function to execute the highest priority job
void executeJob() {
    if (jobQueue.empty()) {
        cout << "No jobs to execute.\n";
        return;
    }
    
    Job topJob = jobQueue.top();
    jobQueue.pop();
    cout << "Executing Job: " << topJob.description << " (Priority: " << topJob.priority << ")\n";
}

// Function to display all pending jobs
void displayJobs() {
    if (jobQueue.empty()) {
        cout << "No jobs in the queue.\n";
        return;
    }

    priority_queue<Job, vector<Job>, greater<Job>> tempQueue = jobQueue;

    cout << "\nPending Jobs:\n";
    while (!tempQueue.empty()) {
        Job job = tempQueue.top();
        tempQueue.pop();
        cout << "ID: " << job.id << ", Priority: " << job.priority << ", Description: " << job.description << "\n";
    }
}

int main() {
    int choice, id, priority;
    string description;

    while (true) {
        cout << "\nJob Scheduling System\n";
        cout << "1. Add Job\n";
        cout << "2. Execute Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Job ID: ";
                cin >> id;
                cout << "Enter Priority (lower number = higher priority): ";
                cin >> priority;
                cin.ignore();
                cout << "Enter Description: ";
                getline(cin, description);
                addJob(id, priority, description);
                break;
            case 2:
                executeJob();
                break;
            case 3:
                displayJobs();
                break;
            case 4:
                cout << "Exiting Job Scheduler...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
