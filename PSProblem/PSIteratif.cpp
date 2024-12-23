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

    // Iteratif: Sorting tugas berdasarkan prioritas menggunakan Bubble Sort
    void sortTasks() {
        for (int i = 0; i < jumlahTugas - 1; i++) {
            for (int j = i + 1; j < jumlahTugas; j++) {
                if (tugas[i].prioritas > tugas[j].prioritas) {
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
    void tambahTugas(const string &nama, int prioritas, int durasi) {
        if (jumlahTugas < MAX_TUGAS) {
            tugas[jumlahTugas].nama = nama;
            tugas[jumlahTugas].prioritas = prioritas;
            tugas[jumlahTugas].durasi = durasi;
            jumlahTugas++;
        } else {
            cout << "Tidak dapat menambahkan tugas lagi, daftar penuh!\n";
        }
    }

    // Menjadwalkan tugas berdasarkan prioritas
    void jadwalkan() {
        sortTasks();
    }

    // Iteratif: Menampilkan hasil penjadwalan
    void printJadwal() {
        cout << "Daftar Tugas Berdasarkan Prioritas:\n";
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
    string tugasDummy[] = {"Tugas 1", "Tugas 2", "Tugas 3", "Tugas 4", "Tugas 5"};
    int prioritasDummy[] = {3, 1, 2, 4, 5};
    int durasiDummy[] = {2, 4, 3, 1, 5};

    cout << "Apakah Anda ingin memasukkan data tugas sendiri? (y/n): ";
    cin >> pilih;
    cin.ignore(); // Membersihkan buffer input

    if (pilih == 'n' || pilih == 'N') {
        for (int i = 0; i < 5; i++) {
            penjadwalan.tambahTugas(tugasDummy[i], prioritasDummy[i], durasiDummy[i]);
        }
    } else {
        cout << "Masukkan jumlah tugas: ";
        cin >> jumlahTugas;
        cin.ignore();

        for (int i = 0; i < jumlahTugas; i++) {
            string nama;
            int prioritas, durasi;

            cout << "Tugas " << i + 1 << ":\n";
            cout << "Nama: ";
            getline(cin, nama);

            cout << "Prioritas (semakin kecil semakin penting): ";
            cin >> prioritas;

            cout << "Durasi (jam): ";
            cin >> durasi;
            cin.ignore();

            penjadwalan.tambahTugas(nama, prioritas, durasi);
        }
    }

    penjadwalan.jadwalkan();
    penjadwalan.printJadwal();

    return 0;
}