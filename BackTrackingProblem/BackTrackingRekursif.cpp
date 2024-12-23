#include <iostream>
#include <vector>
#include <string>

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
// Fungsi rekursif untuk menyelesaikan penjadwalan kuliah
bool scheduleCoursesRecursive(vector<int>& schedule, const vector<string>& courses, const vector<int>& timeSlots, int courseIndex) {
    if (courseIndex == courses.size()) {
        return true; // Semua mata kuliah sudah dijadwalkan
    }

    for (int timeSlot : timeSlots) {
        if (isSafe(schedule, courseIndex, timeSlot)) {
            schedule[courseIndex] = timeSlot;

            if (scheduleCoursesRecursive(schedule, courses, timeSlots, courseIndex + 1)) {
                return true;
            }

            schedule[courseIndex] = -1; // Backtrack
        }
    }

return false;
}
// Fungsi untuk mencetak jadwal kuliah
void printSchedule(const vector<string>& courses, const vector<int>& schedule) {
    for (int i = 0; i < courses.size(); ++i) {
        cout << "Course: " << courses[i] << ", Time Slot: " << schedule[i] << endl;
    }
}
// Fungsi utama untuk mengatur penjadwalan kuliah
void scheduleCourses(const vector<string>& courses, const vector<int>& timeSlots) {
    vector<int> schedule(courses.size(), -1); // -1 berarti belum dijadwalkan

    if (scheduleCoursesRecursive(schedule, courses, timeSlots, 0)) {
        printSchedule(courses, schedule);
    } else {
        cout << "No valid schedule found" << endl;
    }
}
int main() {
    vector<string> courses = {"Math", "Physics", "Chemistry", "Biology"};
    vector<int> timeSlots = {1, 2, 3}; // 3 waktu yang tersedia

    scheduleCourses(courses, timeSlots);

    return 0;
}