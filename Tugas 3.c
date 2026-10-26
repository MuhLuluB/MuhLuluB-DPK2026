#include <stdio.h>
#include <stdlib.h>

char papan[3][3];
char pemainAktif = 'X'; // Dimulai dari Player X

// 1. Mengosongkan papan dengan tanda '-' di awal
void inisialisasiPapan() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            papan[i][j] = '-';
        }
    }
}

// 2. Menampilkan papan ke layar (Mirip seperti contoh gambarmu!)
void tampilkanPapan() {
    system("cls"); // Gunakan "clear" jika di Linux/Mac
    printf("\n=== TIC-TAC-TOE (2 PLAYER) ===\n\n");
    printf("     0   1   2  \n");
    for (int i = 0; i < 3; i++) {
        printf("  %d  ", i);
        for (int j = 0; j < 3; j++) {
            printf("%c   ", papan[i][j]);
        }
        printf("\n\n");
    }
}

// 3. Cek apakah ada yang menang atau seri
char cekPemenang() {
    // Cek Baris & Kolom
    for (int i = 0; i < 3; i++) {
        if (papan[i][0] != '-' && papan[i][0] == papan[i][1] && papan[i][1] == papan[i][2]) return papan[i][0];
        if (papan[0][i] != '-' && papan[0][i] == papan[1][i] && papan[1][i] == papan[2][i]) return papan[0][i];
    }
    // Cek Diagonal
    if (papan[0][0] != '-' && papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2]) return papan[0][0];
    if (papan[0][2] != '-' && papan[0][2] == papan[1][1] && papan[1][1] == papan[2][0]) return papan[0][2];

    // Cek Kotak Kosong
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (papan[i][j] == '-') return ' '; // Belum selesai
        }
    }
    return 'S'; // Seri
}

// 4. Fungsi Utama (Main)
int main() {
    int baris, kolom;
    char pemenang = ' ';

    inisialisasiPapan();

    while (pemenang == ' ') {
        tampilkanPapan();
        printf("Giliran Player [%c]\n", pemainAktif);
        
        printf("Masukkan baris (0-2): ");
        scanf("%d", &baris);
        printf("Masukkan kolom (0-2): ");
        scanf("%d", &kolom);

        // Validasi input koordinat
        if (baris >= 0 && baris <= 2 && kolom >= 0 && kolom <= 2 && papan[baris][kolom] == '-') {
            papan[baris][kolom] = pemainAktif;
            
            // Cek pemenang setelah langkah dibuat
            pemenang = cekPemenang();
            if (pemenang != ' ') break;

            // Ganti giliran Player (Jika X jadi O, jika O jadi X)
            if (pemainAktif == 'X') {
                pemainAktif = 'O';
            } else {
                pemainAktif = 'X';
            }
        } else {
            printf("\nKotak tidak valid atau sudah terisi! Tekan Enter untuk ulang...");
            getchar(); getchar(); // Menahan layar sebentar
        }
    }

    // Tampilan Hasil Akhir
    tampilkanPapan();
    if (pemenang == 'X' || pemenang == 'O') {
        printf("Selamat! Player [%c] Menang! 🎉\n", pemenang);
    } else {
        printf("Permainan Seri / Imbang! 🤝\n");
    }

    return 0;
}
