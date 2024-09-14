//program untuk menghitung harga bimbel
#include <iostream>
#include <iomanip>  // Untuk std::setprecision
#include <fstream>  // Untuk file I/O
#include <string>   // Untuk std::string
#include <cstdlib>  // Untuk std::exit

using namespace std;

int main() {
    // Mendeklarasikan variabel
    const double hargaNormal = 5000000.0;
    double hargaDiskon;
    int ranking;
    string statusGuru;

    // Input ranking
    cout << "Masukkan ranking Anda (1, 2, ..., 10): ";
    cin >> ranking;

    // Input status sebagai anak guru PNS
    cout << "Apakah Anda anak guru PNS? (ya/tidak): ";
    cin >> statusGuru;

    // Validasi ranking
    if (ranking < 1 || ranking > 10) {
        cerr << "Ranking tidak valid. Harap masukkan nilai antara 1 hingga 10." << endl;
        return EXIT_FAILURE; // Keluar dari program dengan status error
    }

    // Menghitung diskon berdasarkan ranking
    if (ranking == 1) {
        hargaDiskon = hargaNormal * (1 - 0.20); // Diskon 20%
    } else if (ranking <= 5) {
        hargaDiskon = hargaNormal * (1 - 0.10); // Diskon 10%
    } else {
        hargaDiskon = hargaNormal * (1 - 0.05); // Diskon 5%
    }

    // Mengecek status anak guru PNS
    if (statusGuru == "ya") {
        hargaDiskon *= (1 - 0.20); // Diskon tambahan 20%
    }

    // Menampilkan hasil ke terminal
    cout << fixed << setprecision(2); // Format angka dengan 2 desimal
    cout << "Harga bimbel setelah diskon: Rp " << hargaDiskon << endl;
    return EXIT_SUCCESS;
}