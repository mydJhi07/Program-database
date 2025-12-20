#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef filedata_h
#include "filedata.h"
#endif

void tampilkanUsage(char *namaProgram)
{
    printf("Usage: %s [PILIHAN]\n", namaProgram);
    printf("Pilihan:\n");
    printf("  1 : Tambah Data Matakuliah (matakuliah.csv)\n");
    printf("  2 : Tambah Data Mahasiswa (mahasiswa.csv)\n");
    printf("  3 : Tambah Data KRS (krs.csv)\n");
    printf("  4 : Hapus Data Mahasiswa berdasarkan NIM (mahasiswa.csv)\n");
}

int main(int argc, char *argv[])
{

    // Perubahan logika argumen: minimum 2 argumen untuk semua, 3 argumen untuk Hapus (Pilihan 4)
    if (argc < 2 || (argc == 2 && atoi(argv[1]) == 4))
    {
        fprintf(stderr, "Error: Argumen tidak sesuai.\n");
        tampilkanUsage(argv[0]);
        return 1;
    }

    int pilihan = atoi(argv[1]);

    // Inisialisasi file
    inisialisasiFile("matakuliah.csv", "ID_MK,Nama,SKS\n");
    inisialisasiFile("mahasiswa.csv", "NIM,Nama,Prodi,IPK\n");
    inisialisasiFile("krs.csv", "NIM_Mahasiswa,ID_Matakuliah\n");

    switch (pilihan)
    {
    case 1:
        printf("--- MODUL TAMBAH MATAKULIAH ---\n");
        tambahDataMatakuliah();
        break;

    case 2:
        printf("--- MODUL TAMBAH MAHASISWA ---\n");
        tambahDataMahasiswa();
        break;

    case 3:
        printf("--- MODUL TAMBAH KRS ---\n");
        tambahDataKRS();
        break;

    case 4:
        if (argc != 3)
        {
            fprintf(stderr, "Error: Pilihan 4 memerlukan argumen NIM target.\n");
            tampilkanUsage(argv[0]);
            return 1;
        }
        printf("--- MODUL HAPUS MAHASISWA ---\n");
        hapusDataMahasiswa(argv[2]);
        break;

    default:
        fprintf(stderr, "Error: Pilihan '%s' tidak valid.\n", argv[1]);
        tampilkanUsage(argv[0]);
        return 1;
    }

    return 0;
}