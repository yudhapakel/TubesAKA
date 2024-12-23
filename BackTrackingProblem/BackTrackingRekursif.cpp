#include <iostream>
#include <string>
using namespace std;

const int MAX_TUGAS = 100; // Maksimal jumlah tugas
const int MAX_WAKTU = 100; // Maksimal jumlah waktu

class PenjadwalanTugas {
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
    PenjadwalanTugas(string tugasArr[], int jumlahTugas, string waktuArr[], int jumlahWaktu) {
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

int main() {
    string tugas[MAX_TUGAS];
    string waktu[MAX_WAKTU];
    int jumlahTugas, jumlahWaktu;
    char pilih;

    // Data dummy tugas dan waktu
    string tugasDummy[] = {
        "Tugas 1", "Tugas 2", "Tugas 3", "Tugas 4", "Tugas 5",
        "Tugas 6", "Tugas 7", "Tugas 8", "Tugas 9", "Tugas 10"
    };
    string waktuDummy[] = {
        "Senin Pagi", "Senin Siang", "Selasa Pagi", "Selasa Siang",
        "Rabu Pagi", "Rabu Siang", "Kamis Pagi", "Kamis Siang",
        "Jumat Pagi", "Jumat Siang"
    };

    // Jumlah tugas dan waktu dummy
    jumlahTugas = 10;
    jumlahWaktu = 10;

    // Menanyakan apakah pengguna ingin memasukkan data sendiri atau menggunakan data dummy
    cout << "Apakah Anda ingin memasukkan data tugas dan waktu sendiri? (y/n): ";
    cin >> pilih;
    cin.ignore(); // Membersihkan buffer input

    if (pilih == 'n' || pilih == 'N') {
        // Menggunakan data dummy
        PenjadwalanTugas penjadwalan(tugasDummy, jumlahTugas, waktuDummy, jumlahWaktu);

        // Menjadwalkan tugas
        if (penjadwalan.jadwalkan()) {
            cout << "Hasil Penjadwalan:" << endl;
            penjadwalan.printJadwal();
        } else {
            cout << "Tidak dapat menjadwalkan semua tugas tanpa konflik waktu." << endl;
        }
    } else {
        // Input data tugas dan waktu dari pengguna
        cout << "Masukkan jumlah tugas: ";
        cin >> jumlahTugas;
        cin.ignore(); // Membersihkan buffer input

        // Input daftar tugas
        cout << "Masukkan nama tugas:" << endl;
        for (int i = 0; i < jumlahTugas; i++) {
            cout << "Tugas " << i + 1 << ": ";
            getline(cin, tugas[i]);
        }

        // Input jumlah waktu
        cout << "Masukkan jumlah waktu: ";
        cin >> jumlahWaktu;
        cin.ignore(); // Membersihkan buffer input

        // Input daftar waktu
        cout << "Masukkan nama waktu yang tersedia:" << endl;
        for (int i = 0; i < jumlahWaktu; i++) {
            cout << "Waktu " << i + 1 << ": ";
            getline(cin, waktu[i]);
        }

        // Membuat objek penjadwalan
        PenjadwalanTugas penjadwalan(tugas, jumlahTugas, waktu, jumlahWaktu);

        // Menjadwalkan tugas
        if (penjadwalan.jadwalkan()) {
            cout << "Hasil Penjadwalan:" << endl;
            penjadwalan.printJadwal();
        } else {
            cout << "Tidak dapat menjadwalkan semua tugas tanpa konflik waktu." << endl;
        }
    }

    return 0;
}