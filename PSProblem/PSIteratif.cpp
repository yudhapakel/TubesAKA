#include <iostream>
#include <string>
using namespace std;

const int MAX_TUGAS = 100; // Batas maksimal jumlah tugas

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
    PrioritySchedulingIterative penjadwalan;
    char pilih;
    int jumlahTugas;

    // Data dummy
    string tugasDummy[] = {
    "Tugas 1", "Tugas 2", "Tugas 3", "Tugas 4", "Tugas 5", 
    "Tugas 6", "Tugas 7", "Tugas 8", "Tugas 9", "Tugas 10", 
    "Tugas 11", "Tugas 12", "Tugas 13", "Tugas 14", "Tugas 15", 
    "Tugas 16", "Tugas 17", "Tugas 18", "Tugas 19", "Tugas 20", 
    "Tugas 21", "Tugas 22", "Tugas 23", "Tugas 24", "Tugas 25", 
    "Tugas 26", "Tugas 27", "Tugas 28", "Tugas 29", "Tugas 30", 
    "Tugas 31", "Tugas 32", "Tugas 33", "Tugas 34", "Tugas 35", 
    "Tugas 36", "Tugas 37", "Tugas 38", "Tugas 39", "Tugas 40", 
    "Tugas 41", "Tugas 42", "Tugas 43", "Tugas 44", "Tugas 45", 
    "Tugas 46", "Tugas 47", "Tugas 48", "Tugas 49", "Tugas 50"
    };

    int durasiDummy[] = {
    2, 4, 3, 1, 5, 
    6, 8, 7, 9, 10, 
    1, 3, 2, 5, 4, 
    6, 8, 10, 9, 7, 
    3, 5, 4, 1, 2, 
    7, 6, 8, 10, 9, 
    4, 3, 1, 2, 5, 
    10, 9, 7, 8, 6, 
    2, 1, 5, 4, 3, 
    9, 10, 8, 6, 7
    };

    cout << "Apakah Anda ingin memasukkan data tugas sendiri? (y/n): ";
    cin >> pilih;
    cin.ignore(); // Membersihkan buffer input

    if (pilih == 'n' || pilih == 'N') {
        for (int i = 0; i < 50; i++) {
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

    return 0;
}
