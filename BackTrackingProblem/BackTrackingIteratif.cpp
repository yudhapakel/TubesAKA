#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
// Fungsi untuk memeriksa apakah jadwal kuliah aman
bool isSafe(const vector<int>& schedule, int course, int timeSlot) {
    for (int i = 0; i < schedule.size(); ++i) {
        if (schedule[i] == timeSlot && i != course) {
            return false;
        }
    }
    return true;
}

// Fungsi untuk mencetak jadwal kuliah
void printSchedule(const vector<string>& courses, const vector<int>& schedule) {
    for (int i = 0; i < courses.size(); ++i) {
        cout << "Course: " << courses[i] << ", Time Slot: " << schedule[i] << endl;
    }
}

// Fungsi utama untuk mengatur penjadwalan kuliah secara iteratif
void scheduleCoursesIterative(const vector<string>& courses, const vector<int>& timeSlots) {
    vector<int> schedule(courses.size(), -1); // -1 berarti belum dijadwalkan
    stack<pair<int, vector<int>>> stack;  // Stack untuk menyimpan (courseIndex, schedule)
    stack.push({0, schedule}); // Mulai dari mata kuliah pertama

    while (!stack.empty()) {
        auto [courseIndex, currentSchedule] = stack.top();
        stack.pop();

        if (courseIndex == courses.size()) {
            printSchedule(courses, currentSchedule);
            return;
        }

        bool placed = false;
        for (int timeSlot : timeSlots) {
            if (isSafe(currentSchedule, courseIndex, timeSlot)) {
                vector<int> newSchedule = currentSchedule;
                newSchedule[courseIndex] = timeSlot;
                stack.push({courseIndex + 1, newSchedule});
                placed = true;
                break;
            }
        }

        if (!placed) {
            // Jika tidak ada posisi yang valid ditemukan, backtrack
            continue;
        }
    }

    cout << "No valid schedule found" << endl;
}

int main() {
    vector<string> courses = {"Math", "Physics", "Chemistry", "Biology"};
    vector<int> timeSlots = {1, 2, 3}; // 3 waktu yang tersedia

    scheduleCoursesIterative(courses, timeSlots);

    return 0;
}