#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void FIFO(vector<int>& requests, int head) {
    int total_seek = 0;
    cout << "FIFO Sequence: ";
    for (int i = 0; i < requests.size(); i++) {
        total_seek += abs(head - requests[i]);
        cout << requests[i] << " ";
        head = requests[i];
    }
    cout << "\nFIFO Total Seek: " << total_seek << endl;
}

void SSTF(vector<int>& requests, int head) {
    int total_seek = 0;
    cout << "SSTF Sequence: ";
    while (!requests.empty()) {
        int closest_index = 0;
        int min_distance = abs(head - requests[0]);
        for (int i = 1; i < requests.size(); i++) {
            int distance = abs(head - requests[i]);
            if (distance < min_distance) {
                min_distance = distance;
                closest_index = i;
            }
        }
        total_seek += min_distance;
        cout << requests[closest_index] << " ";
        head = requests[closest_index];
        requests.erase(requests.begin() + closest_index);
    }
    cout << "\nSSTF Total Seek: " << total_seek << endl;
}

void SCAN(vector<int>& requests, int head) {
    int total_seek = 0;
    sort(requests.begin(), requests.end());
    cout << "SCAN Sequence: ";
    int start = 0, end = requests.size() - 1;
    while (start < end) {
        total_seek += abs(head - requests[start]);
        cout << requests[start] << " ";
        head = requests[start];
        start++;
        total_seek += abs(head - requests[end]);
        cout << requests[end] << " ";
        head = requests[end];
        end--;
    }
    cout << "\nSCAN Total Seek: " << total_seek << endl;
}

void CSCAN(vector<int>& requests, int head) {
    int total_seek = 0;
    sort(requests.begin(), requests.end());
    cout << "C-SCAN Sequence: ";
    int start = 0, end = requests.size() - 1;
    total_seek += abs(head - requests[start]);
    cout << requests[start] << " ";
    head = requests[start];
    start++;
    while (start <= end) {
        total_seek += abs(head - requests[start]);
        cout << requests[start] << " ";
        head = requests[start];
        start++;
    }
    total_seek += abs(head - requests[0]);
    cout << requests[0] << " ";
    head = requests[0];
    cout << "\nC-SCAN Total Seek: " << total_seek << endl;
}

int main() {
    vector<int> requests;
    int head, request_count, request;

    cout << "Enter the number of disk I/O requests: ";
    cin >> request_count;
    cout << "Enter the disk I/O requests separated by spaces: ";
    for (int i = 0; i < request_count; i++) {
        cin >> request;
        requests.push_back(request);
    }

    cout << "Enter the initial head position: ";
    cin >> head;

    FIFO(requests, head);
    SSTF(requests, head);
    SCAN(requests, head);
    CSCAN(requests, head);

    return 0;
}
