#include<bits/stdc++.h>
using namespace std;

// TC: O(n^2)
// Aux Space: O(n)

class job {
    public:
    int id;
    int deadline;
    int profit;

    job(int i, int d, int p) {
        id = i;
        deadline = d;
        profit = p;
    }
};

bool sort_by_profit(job &a, job &b) {
    return a.profit > b.profit;
}

// Return {number of jobs, maximum profit}.
vector<int> job_scheduling(vector<job> jobs) {

    sort(jobs.begin(), jobs.end(), sort_by_profit);

    int n = jobs.size();
    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        max_deadline = max(max_deadline, jobs[i].deadline);
    }

    vector<bool> slots(min(n, max_deadline), false); // Marking all of the slots as empty.

    int job_count = 0;
    int max_profit = 0;

    for (int i = 0; i < n; i++) {
        
        // Find the rightmost empty time slot where this job can be accommodated.
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slots[j] == false) {
                // Fill the current job at the current slot.
                job_count++;
                max_profit += jobs[i].profit;
                slots[j] = true; // Marking the slot as filled.
                break;
            }
        }
    }

    return {job_count, max_profit};
}

int main() {

    // Passing the {id, deadline, profit} of each job in the input array.
    vector<int> result = job_scheduling({{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}});
    cout << result[0] << " " << result[1] << endl;

    result = job_scheduling({{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}});
    cout << result[0] << " " << result[1] << endl;
}
