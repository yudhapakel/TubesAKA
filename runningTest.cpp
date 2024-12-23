#include <iostream>
#include <string>
#include <chrono>
using namespace std;

const int MAX_TUGAS = 100; // Batas maksimal jumlah tugas

// Timer untuk menghitung waktu algoritma
class Timer
{
public:
    Timer() { start = std::chrono::high_resolution_clock::now(); }
    ~Timer() {}

    void reset() { start = std::chrono::high_resolution_clock::now(); }
    float elapsed_ms()
    {
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        return static_cast<float>(elapsed);
    }

private:
    std::chrono::high_resolution_clock::time_point start;
};

class PrioritySchedulingIterative {
private:
    struct Tugas {
        string nama;
        int prioritas;
        int durasi;
    };

    Tugas tugas[MAX_TUGAS];
    int jumlahTugas;

    void sortTasks() {
        for (int i = 0; i < jumlahTugas - 1; i++) {
            for (int j = i + 1; j < jumlahTugas; j++) {
                if (tugas[i].durasi > tugas[j].durasi) {
                    Tugas temp = tugas[i];
                    tugas[i] = tugas[j];
                    tugas[j] = temp;
                }
            }
        }
    }

public:
    PrioritySchedulingIterative() {
        jumlahTugas = 0;
    }

    void tambahTugas(const string &nama, int durasi) {
        if (jumlahTugas < MAX_TUGAS) {
            tugas[jumlahTugas].nama = nama;
            tugas[jumlahTugas].durasi = durasi;
            jumlahTugas++;
        } else {
            cout << "Tidak dapat menambahkan tugas lagi, daftar penuh!\n";
        }
    }

    void jadwalkan() {
        sortTasks();
        for (int i = 0; i < jumlahTugas; i++) {
            tugas[i].prioritas = i + 1;
        }
    }

    void printJadwal() {
        for (int i = 0; i < jumlahTugas; i++) {
            cout << "Nama: " << tugas[i].nama
                 << ", Prioritas: " << tugas[i].prioritas
                 << ", Durasi: " << tugas[i].durasi << " jam\n";
        }
    }
};

class PrioritySchedulingRecursive {
private:
    struct Tugas {
        string nama;
        int prioritas;
        int durasi;
    };

    Tugas tugas[MAX_TUGAS];
    int jumlahTugas;

    void recursiveSort(int n) {
        if (n <= 1) return;

        for (int i = 0; i < n - 1; i++) {
            if (tugas[i].durasi > tugas[i + 1].durasi) {
                Tugas temp = tugas[i];
                tugas[i] = tugas[i + 1];
                tugas[i + 1] = temp;
            }
        }

        recursiveSort(n - 1);
    }

public:
    PrioritySchedulingRecursive() {
        jumlahTugas = 0;
    }

    void tambahTugas(const string &nama, int durasi) {
        if (jumlahTugas < MAX_TUGAS) {
            tugas[jumlahTugas].nama = nama;
            tugas[jumlahTugas].durasi = durasi;
            jumlahTugas++;
        } else {
            cout << "Tidak dapat menambahkan tugas lagi, daftar penuh!\n";
        }
    }

    void jadwalkan() {
        recursiveSort(jumlahTugas);
        for (int i = 0; i < jumlahTugas; i++) {
            tugas[i].prioritas = i + 1;
        }
    }

    void printJadwal() {
        for (int i = 0; i < jumlahTugas; i++) {
            cout << "Nama: " << tugas[i].nama
                 << ", Prioritas: " << tugas[i].prioritas
                 << ", Durasi: " << tugas[i].durasi << " jam\n";
        }
    }
};

void simulate_case(const string& case_name, int n, bool isRecursive) {
    Timer my_timer;
    string tugasDummy[MAX_TUGAS];
    int durasiDummy[MAX_TUGAS];

    for (int i = 0; i < n; ++i) {
        tugasDummy[i] = "Tugas " + to_string(i + 1);
        durasiDummy[i] = rand() % 10 + 1; // Random duration between 1 and 10
    }

    if (isRecursive) {
        PrioritySchedulingRecursive penjadwalan;
        for (int i = 0; i < n; ++i) {
            penjadwalan.tambahTugas(tugasDummy[i], durasiDummy[i]);
        }
        penjadwalan.jadwalkan();
        penjadwalan.printJadwal();
    } else {
        PrioritySchedulingIterative penjadwalan;
        for (int i = 0; i < n; ++i) {
            penjadwalan.tambahTugas(tugasDummy[i], durasiDummy[i]);
        }
        penjadwalan.jadwalkan();
        penjadwalan.printJadwal();
    }

    float elapsed = my_timer.elapsed_ms();
    std::cout << "Total waktu (" << case_name << " - " << n << " tugas): " << elapsed * 0.001f << " sec\n";
}

int main() {
    const int loop_counts[] = {10, 50, 100};

    for (int n : loop_counts) {
        cout << "\nIterative Priority Scheduling:\n";
        simulate_case("Iteratif", n, false);
        cout << "\nRecursive Priority Scheduling:\n";
        simulate_case("Rekursif", n, true);
    }

    return 0;
}
