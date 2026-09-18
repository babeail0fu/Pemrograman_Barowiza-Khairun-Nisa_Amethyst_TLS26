#include <iostream>

using namespace std;

// Fungsi buatan sendiri untuk menghitung panjang string (pengganti strlen)
int hitungPanjang(char str[]) {
    int panjang = 0;
    while (str[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

int main() {
    char pesan[1000];
    
    cout << "Masukkan pesan rahasia (huruf kapital): ";
    cin >> pesan; // Menggunakan cin untuk membaca string karakter

    int n = hitungPanjang(pesan);
    int prev_val = 0; // Menyimpan nilai huruf sebelumnya (huruf pertama bergeser 0)

    cout << "Pesan terenkripsi: ";
    for (int i = 0; i < n; i++) {
        // Memastikan karakter adalah huruf kapital A-Z
        if (pesan[i] >= 'A' && pesan[i] <= 'Z') {
            int current_val = (pesan[i] - 'A') + 1; // Ubah A=1, B=2, dst.
            int total_geser = current_val + prev_val;

            // Perhitungan modulus 26 untuk wrap-around jika melewati 'Z'
            int new_val = ((total_geser - 1) % 26) + 1;
            char new_char = new_val + 'A' - 1; // Konversi kembali ke bentuk karakter

            cout << new_char;

            // Perbarui nilai prev_val dengan nilai asli huruf saat ini untuk iterasi berikutnya
            prev_val = current_val;
        } else {
            // Jika karakter berupa spasi atau simbol lain, biarkan dan reset prev_val
            cout << pesan[i];
            prev_val = 0;
        }
    }
    cout << endl;

    return 0;
}
