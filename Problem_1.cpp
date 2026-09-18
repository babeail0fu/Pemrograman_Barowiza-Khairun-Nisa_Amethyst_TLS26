#include <iostream>

using namespace std;

int main() {
    int N, K;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai K awal: ";
    cin >> K;

    int astronot[1000];
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }

    int saiz = N;
    int indeks_semasa = 0;

    cout << "\nUrutan eliminasi: ";
    while (saiz > 1) {
        // Mengira posisi target eliminasi menggunakan modulus
        int target = (indeks_semasa + K - 1) % saiz;
        int nomor_tereliminasi = astronot[target];
        
        cout << nomor_tereliminasi << " ";

        // Membuang elemen dengan menggeser tatatanda ke kiri
        for (int i = target; i < saiz - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        saiz--;

        // Jika hanya tinggal seorang, hentikan gelung
        if (saiz == 1) break;

        // Peraturan pengemaskinian nilai K
        if (nomor_tereliminasi % 2 == 0) {
            K += 2; // Genap tambah 2
        } else {
            K -= 1; // Ganjil kurang 1
        }

        // K tidak boleh kurang daripada 2
        if (K < 2) {
            K = 2;
        }

        // Indeks seterusnya bermula dari posisi elemen yang baru digeser
        indeks_semasa = target % saiz;
    }

    cout << "\nAstronot terakhir yang bertahan: " << astronot[0] << endl;

    return 0;
}

