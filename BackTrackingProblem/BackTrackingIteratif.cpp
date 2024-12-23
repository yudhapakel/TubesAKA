#include <iostream>
#include <string>
#include <stack>
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

int main() {
    string tugas[MAX_TUGAS];
    string waktu[MAX_WAKTU];
    int jumlahTugas, jumlahWaktu;
    char pilih;

    // Data dummy tugas dan waktu
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
    string waktuDummy[] = {
        "Senin Pagi", "Senin Siang", "Selasa Pagi", "Selasa Siang",
        "Rabu Pagi", "Rabu Siang", "Kamis Pagi", "Kamis Siang",
        "Jumat Pagi", "Jumat Siang","senin siang", "Senin Pagi", "Senin Siang", "Selasa Pagi", "Selasa Siang",
        "Rabu Pagi", "Rabu Siang", "Kamis Pagi", "Kamis Siang",
        "Jumat Pagi", "Jumat Siang","senin siang",  "Senin Pagi", "Senin Siang", "Selasa Pagi", "Selasa Siang",
        "Rabu Pagi", "Rabu Siang", "Kamis Pagi", "Kamis Siang",
        "Jumat Pagi", "Jumat Siang","senin siang",  "Senin Pagi", "Senin Siang", "Selasa Pagi", "Selasa Siang",
        "Rabu Pagi", "Rabu Siang", "Kamis Pagi", "Kamis Siang",
        "Jumat Pagi", "Jumat Siang","senin siang",  "Senin Pagi", "Senin Siang", "Selasa Pagi", "Selasa Siang",
        "Rabu Pagi", "Rabu Siang", "Kamis Pagi", "Kamis Siang",
        "Jumat Pagi", "Jumat Siang","senin siang", 
    };

    // Jumlah tugas dan waktu dummy
    jumlahTugas = 50;
    jumlahWaktu = 50;

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