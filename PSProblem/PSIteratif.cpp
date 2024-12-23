#include <iostream>
#include <string>
#include <chrono>
using namespace std;

const int MAX_TUGAS = 100; // Batas maksimal jumlah tugas
// timer untuk menghitung waktu algoritma
class timer
{
public:
    timer() { start = std::chrono::high_resolution_clock::now(); }
    ~timer() {}

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
        string nama;    // Nama tugas
        int prioritas;  // Prioritas tugas (semakin kecil semakin penting)
        int durasi;     // Durasi pengerjaan tugas
    };

    Tugas tugas[MAX_TUGAS]; // Array untuk menyimpan daftar tugas
    int jumlahTugas;        // Jumlah tugas yang ada

    // Iteratif: Sorting tugas berdasarkan durasi menggunakan Bubble Sort
    void sortTasks() {
        for (int i = 0; i < jumlahTugas - 1; i++) {
            for (int j = i + 1; j < jumlahTugas; j++) {
                if (tugas[i].durasi > tugas[j].durasi) {
                    // Tukar tugas[i] dengan tugas[j]
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

    // Iteratif: Menambahkan tugas ke dalam daftar
    void tambahTugas(const string &nama, int durasi) {
        if (jumlahTugas < MAX_TUGAS) {
            tugas[jumlahTugas].nama = nama;
            tugas[jumlahTugas].durasi = durasi;
            jumlahTugas++;
        } else {
            cout << "Tidak dapat menambahkan tugas lagi, daftar penuh!\n";
        }
    }

    // Menjadwalkan tugas berdasarkan durasi dan menetapkan prioritas
    void jadwalkan() {
        sortTasks();
        for (int i = 0; i < jumlahTugas; i++) {
            tugas[i].prioritas = i + 1; // Menetapkan prioritas berdasarkan urutan setelah sorting
        }
    }

    // Iteratif: Menampilkan hasil penjadwalan
    void printJadwal() {
        cout << "Daftar Tugas Berdasarkan Durasi dan Prioritas:\n";
        for (int i = 0; i < jumlahTugas; i++) {
            cout << "Nama: " << tugas[i].nama
                 << ", Prioritas: " << tugas[i].prioritas
                 << ", Durasi: " << tugas[i].durasi << " jam\n";
        }
    }
};

int main() {
     timer my_timer; // mulai
    PrioritySchedulingIterative penjadwalan;
    char pilih;
    int jumlahTugas;

    // Data dummy
    string tugasDummy[] = {
    "Tugas 1", "Tugas 2", "Tugas 3", "Tugas 4", "Tugas 5", 
    "Tugas 6", "Tugas 7", "Tugas 8", "Tugas 9", "Tugas 10"};

    int durasiDummy[] = {
    2, 4, 3, 1, 5, 
    6, 8, 7, 9, 10 };

    cout << "Apakah Anda ingin memasukkan data tugas sendiri? (y/n): ";
    cin >> pilih;
    cin.ignore(); // Membersihkan buffer input

    if (pilih == 'n' || pilih == 'N') {
        for (int i = 0; i < 10; i++) {
            penjadwalan.tambahTugas(tugasDummy[i], durasiDummy[i]);
        }
    } else {
        cout << "Masukkan jumlah tugas: ";
        cin >> jumlahTugas;
        cin.ignore();

        for (int i = 0; i < jumlahTugas; i++) {
            string nama;
            int durasi;

            cout << "Tugas " << i + 1 << ":\n";
            cout << "Nama: ";
            getline(cin, nama);

            cout << "Durasi (jam): ";
            cin >> durasi;
            cin.ignore();

            penjadwalan.tambahTugas(nama, durasi);
        }
    }

    penjadwalan.jadwalkan();
    penjadwalan.printJadwal();

    float elapsed = my_timer.elapsed_ms(); // akhir
    std::cout << "Total waktu: " << elapsed * 0.001f << " sec\n";

    return 0;
}
