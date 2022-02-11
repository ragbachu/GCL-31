#include<bits/stdc++.h>
using namespace std;

// TC: O(n * log(n))
// Aux space: O(n)

/*
meetings[i][0] -> start time of the ith meeting
meetings[i][1] -> end time of the ith meeting
*/
int min_meeting_rooms(vector<vector<int>> meetings) { 

    vector<pair<int, int>> times;
    for (int i = 0; i < meetings.size(); i++) {
        times.push_back({meetings[i][0], +1});
        times.push_back({meetings[i][1], -1});
    }

    sort(times.begin(), times.end());

    int max_concurrent_meetings = 0;
    int current_concurrent_meetings = 0;

    for (int i = 0; i < times.size(); i++) {
        current_concurrent_meetings += times[i].second;
        max_concurrent_meetings = max(max_concurrent_meetings, current_concurrent_meetings);
    }

    return max_concurrent_meetings;
}

int main() {

    cout << min_meeting_rooms({{0, 30}, {5, 10}, {15, 20}}) << endl;
    cout << min_meeting_rooms({{1, 18}, {18, 23}, {15, 29}, {4, 15}, {2, 11}, {5, 13}}) << endl;
    
}