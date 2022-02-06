#include<bits/stdc++.h>
using namespace std;

int max_tasks(vector<int> task_times, int total_time) {

    sort(task_times.begin(), task_times.end());
    int result = 0;

    for (int i = 0; i < task_times.size(); i++) {
        if (task_times[i] <= total_time) {
            result++;
            total_time -= task_times[i];
        }
        else {
            break;
        }
    }

    return result;
}

int main() {

    cout << max_tasks({4, 2, 1, 2, 5}, 8) << endl;
}