#include <iostream>
#include <string>
#include <stack>
#include <chrono>
using namespace std;

const int MAX_TUGAS = 100; // Maksimal jumlah tugas
const int MAX_WAKTU = 100; // Maksimal jumlah waktu

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

class PenjadwalanTugasIteratif {
private:
    string tugas[MAX_TUGAS];  // Daftar tugas
    string waktu[MAX_WAKTU];  // Daftar waktu yang tersedia
    string jadwal[MAX_TUGAS]; // Jadwal hasil (waktu untuk setiap tugas)
    int jumlahTugas;          // Jumlah tugas
    int jumlahWaktu;          // Jumlah waktu yang tersedia

    // Mengecek apakah waktu tertentu sudah digunakan
    bool isValid(const string& waktuSekarang, int idx) {
        for (int i = 0; i < idx; i++) {
            if (jadwal[i] == waktuSekarang) {
                return false;
            }
        }
        return true;
    }

public:
    PenjadwalanTugasIteratif(string tugasArr[], int jumlahTugas, string waktuArr[], int jumlahWaktu) {
        this->jumlahTugas = jumlahTugas;
        this->jumlahWaktu = jumlahWaktu;

        for (int i = 0; i < jumlahTugas; i++) {
            this->tugas[i] = tugasArr[i];
            this->jadwal[i] = ""; // Inisialisasi jadwal kosong
        }

        for (int i = 0; i < jumlahWaktu; i++) {
            this->waktu[i] = waktuArr[i];
        }
    }

    // Fungsi untuk menjadwalkan tugas secara iteratif (menggunakan stack)
    bool jadwalkan() {
        stack<pair<int, int>> s;  // Stack untuk menyimpan pasangan (idxTugas, idxWaktu)
        s.push({0, 0});  // Mulai dari tugas pertama dan waktu pertama

        while (!s.empty()) {
            auto [idxTugas, idxWaktu] = s.top();  // Ambil indeks tugas dan waktu
            s.pop();

            if (idxTugas == jumlahTugas) {
                // Semua tugas telah dijadwalkan
                return true;
            }

            // Mencoba waktu untuk tugas ini
            for (int i = idxWaktu; i < jumlahWaktu; i++) {
                if (isValid(waktu[i], idxTugas)) {
                    jadwal[idxTugas] = waktu[i];  // Menjadwalkan tugas

                    // Menambahkan tugas berikutnya ke stack
                    s.push({idxTugas + 1, 0});  // Lanjutkan ke tugas berikutnya
                    break;
                }
            }

            // Jika tidak ada waktu yang valid, backtrack dengan mundur ke tugas sebelumnya
            if (jadwal[idxTugas] == "") {
                continue;
            }
        }

        return false;  // Tidak ada solusi
    }

    // Menampilkan hasil penjadwalan
    void printJadwal() {
        for (int i = 0; i < jumlahTugas; i++) {
            cout << tugas[i] << " -> " << jadwal[i] << endl;
        }
    }
};

class PenjadwalanTugasRekursif {
private:
    string tugas[MAX_TUGAS];  // Daftar tugas
    string waktu[MAX_WAKTU];  // Daftar waktu yang tersedia
    string jadwal[MAX_TUGAS]; // Jadwal hasil (waktu untuk setiap tugas)
    int jumlahTugas;          // Jumlah tugas
    int jumlahWaktu;          // Jumlah waktu yang tersedia

    // Mengecek apakah waktu tertentu sudah digunakan
    bool isValid(const string& waktuSekarang, int idx) {
        for (int i = 0; i < idx; i++) {
            if (jadwal[i] == waktuSekarang) {
                return false;
            }
        }
        return true;
    }

    // Fungsi backtracking untuk menjadwalkan tugas
    bool backtrack(int idx) {
        // Jika semua tugas sudah dijadwalkan
        if (idx == jumlahTugas) {
            return true;
        }

        // Mencoba setiap waktu yang tersedia
        for (int i = 0; i < jumlahWaktu; i++) {
            if (isValid(waktu[i], idx)) {
                // Menjadwalkan tugas ke waktu ini
                jadwal[idx] = waktu[i];

                // Rekursi ke tugas berikutnya
                if (backtrack(idx + 1)) {
                    return true;
                }

                // Backtrack
                jadwal[idx] = "";
            }
        }

        return false;
    }

public:
    PenjadwalanTugasRekursif(string tugasArr[], int jumlahTugas, string waktuArr[], int jumlahWaktu) {
        this->jumlahTugas = jumlahTugas;
        this->jumlahWaktu = jumlahWaktu;

        for (int i = 0; i < jumlahTugas; i++) {
            this->tugas[i] = tugasArr[i];
            this->jadwal[i] = ""; // Inisialisasi jadwal kosong
        }

        for (int i = 0; i < jumlahWaktu; i++) {
            this->waktu[i] = waktuArr[i];
        }
    }

    // Memulai proses penjadwalan
    bool jadwalkan() {
        return backtrack(0);
    }

    // Menampilkan hasil penjadwalan
    void printJadwal() {
        for (int i = 0; i < jumlahTugas; i++) {
            cout << tugas[i] << " -> " << jadwal[i] << endl;
        }
    }
};

void simulate_case(const string& case_name, int n, bool isRecursive) {
    Timer my_timer;
    string tugasDummy[MAX_TUGAS];
    string waktuDummy[MAX_WAKTU];

    for (int i = 0; i < n; ++i) {
        tugasDummy[i] = "Tugas " + to_string(i + 1);
        waktuDummy[i] = "Waktu " + to_string(i + 1);
    }

    if (isRecursive) {
        PenjadwalanTugasRekursif penjadwalan(tugasDummy, n, waktuDummy, n);
        if (penjadwalan.jadwalkan()) {
            penjadwalan.printJadwal();
        } else {
            cout << "Tidak dapat menjadwalkan semua tugas tanpa konflik waktu." << endl;
        }
    } else {
        PenjadwalanTugasIteratif penjadwalan(tugasDummy, n, waktuDummy, n);
        if (penjadwalan.jadwalkan()) {
            penjadwalan.printJadwal();
        } else {
            cout << "Tidak dapat menjadwalkan semua tugas tanpa konflik waktu." << endl;
        }
    }

    float elapsed = my_timer.elapsed_ms();
    std::cout << "Total waktu (" << case_name << " - " << n << " tugas): " << elapsed * 0.001f << " sec\n";
}

int main() {
    const int loop_counts[] = {10, 50, 100};

    for (int n : loop_counts) {
        cout << "\nIterative Backtracking:\n";
        simulate_case("Iteratif", n, false);
        cout << "\nRecursive Backtracking:\n";
        simulate_case("Rekursif", n, true);
    }

    return 0;
}
