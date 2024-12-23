// #include <iostream>
// #include <string>
// using namespace std;

// const int MAX_TUGAS = 100; // Batas maksimal jumlah tugas

// class PenjadwalanTugas {
// private:
//     struct Tugas {
//         string nama;    // Nama tugas
//         int prioritas;  // Prioritas tugas (semakin kecil semakin penting)
//         int durasi;     // Durasi pengerjaan tugas
//     };

//     Tugas tugas[MAX_TUGAS]; // Array untuk menyimpan daftar tugas
//     int jumlahTugas;        // Jumlah tugas yang ada

//     // **Rekursif: Sorting tugas berdasarkan prioritas**
//     void recursiveSort(int n) {
//         if (n <= 1) return;

//         // Menempatkan elemen terbesar di akhir
//         for (int i = 0; i < n - 1; i++) {
//             if (tugas[i].prioritas > tugas[i + 1].prioritas) {
//                 // Swap tugas[i] dengan tugas[i+1]
//                 Tugas temp = tugas[i];
//                 tugas[i] = tugas[i + 1];
//                 tugas[i + 1] = temp;
//             }
//         }

//         // Rekursi untuk elemen lainnya
//         recursiveSort(n - 1);
//     }

// public:
//     PenjadwalanTugas() {
//         jumlahTugas = 0;
//     }

//     // **Iteratif: Menambahkan tugas ke dalam daftar**
//     void tambahTugas(const string &nama, int prioritas, int durasi) {
//         if (jumlahTugas < MAX_TUGAS) {
//             tugas[jumlahTugas].nama = nama;
//             tugas[jumlahTugas].prioritas = prioritas;
//             tugas[jumlahTugas].durasi = durasi;
//             jumlahTugas++;
//         } else {
//             cout << "Tidak dapat menambahkan tugas lagi, daftar penuh!\n";
//         }
//     }

//     // **Rekursif: Menjadwalkan tugas berdasarkan prioritas**
//     void jadwalkan() {
//         recursiveSort(jumlahTugas);
//     }

//     // **Iteratif: Menampilkan hasil penjadwalan**
//     void printJadwal() {
//         cout << "Daftar Tugas Berdasarkan Prioritas:\n";
//         for (int i = 0; i < jumlahTugas; i++) {
//             cout << "Nama: " << tugas[i].nama
//                  << ", Prioritas: " << tugas[i].prioritas
//                  << ", Durasi: " << tugas[i].durasi << " jam\n";
//         }
//     }
// };

// int main() {
//     PenjadwalanTugas penjadwalan;
//     char pilih;
//     int jumlahTugas;

//     // Data dummy
//     string tugasDummy[] = {"Tugas 1", "Tugas 2", "Tugas 3", "Tugas 4", "Tugas 5"};
//     int prioritasDummy[] = {3, 1, 2, 4, 5};
//     int durasiDummy[] = {2, 4, 3, 1, 5};

//     // Menanyakan apakah pengguna ingin memasukkan data sendiri atau menggunakan data dummy
//     cout << "Apakah Anda ingin memasukkan data tugas sendiri? (y/n): ";
//     cin >> pilih;
//     cin.ignore(); // Membersihkan buffer input

//     if (pilih == 'n' || pilih == 'N') {
//         // Menggunakan data dummy
//         for (int i = 0; i < 5; i++) {
//             penjadwalan.tambahTugas(tugasDummy[i], prioritasDummy[i], durasiDummy[i]);
//         }
//     } else {
//         // Input data tugas dari pengguna
//         cout << "Masukkan jumlah tugas: ";
//         cin >> jumlahTugas;
//         cin.ignore(); // Membersihkan buffer input

//         for (int i = 0; i < jumlahTugas; i++) {
//             string nama;
//             int prioritas, durasi;

//             cout << "Tugas " << i + 1 << ":\n";
//             cout << "Nama: ";
//             getline(cin, nama);

//             cout << "Prioritas (semakin kecil semakin penting): ";
//             cin >> prioritas;

//             cout << "Durasi (jam): ";
//             cin >> durasi;
//             cin.ignore(); // Membersihkan buffer input

//             penjadwalan.tambahTugas(nama, prioritas, durasi);
//         }
//     }

//     // Menjadwalkan tugas berdasarkan prioritas
//     penjadwalan.jadwalkan();

//     // Menampilkan hasil penjadwalan
//     cout << "\nHasil Penjadwalan:\n";
//     penjadwalan.printJadwal();

//     return 0;
// }
