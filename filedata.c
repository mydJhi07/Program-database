#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef filedata_h
#include "filedata.h"
#endif

void amankanInput(char *buffer, int size)
{
    if (strchr(buffer, '\n') == NULL)
    {
        bersihkanBufferInput();
    }
    else
    {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

void bersihkanBufferInput()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void inisialisasiFile(const char *namaFile, const char *header)
{
    FILE *fp = fopen(namaFile, "r");
    if (fp == NULL)
    {
        fp = fopen(namaFile, "w");
        if (fp == NULL)
        {
            fprintf(stderr, "Error: Gagal membuat file '%s'.\n", namaFile);
            exit(1);
        }
        fprintf(fp, "%s", header);
        printf("Info: File '%s' tidak ditemukan, file baru dibuat.\n", namaFile);
    }
    fclose(fp);
}

int cekDuplikat(const char *namaFile, const char *key, int kolom)
{
    FILE *fp = fopen(namaFile, "r");
    if (!fp)
        return 0;

    char baris[512];
    fgets(baris, sizeof(baris), fp);

    while (fgets(baris, sizeof(baris), fp))
    {
        baris[strcspn(baris, "\n")] = '\0';
        char temp_baris[512];
        strcpy(temp_baris, baris);

        char *token = strtok(temp_baris, ",");
        int i = 0;

        while (token != NULL)
        {
            if (i == kolom)
            {
                if (strcmp(token, key) == 0)
                {
                    fclose(fp);
                    return 1;
                }
                break;
            }
            token = strtok(NULL, ",");
            i++;
        }
    }
    fclose(fp);
    return 0;
}

int cekDuplikatKRS(const char *nim, const char *id_mk)
{
    FILE *fp = fopen("krs.csv", "r");
    if (!fp)
        return 0;

    char baris[256];
    fgets(baris, sizeof(baris), fp);

    while (fgets(baris, sizeof(baris), fp))
    {
        baris[strcspn(baris, "\n")] = '\0';
        char temp_baris[256];
        strcpy(temp_baris, baris);

        char *nim_csv = strtok(temp_baris, ",");
        char *id_mk_csv = strtok(NULL, ",");

        if (nim_csv && id_mk_csv)
        {
            if (strcmp(nim_csv, nim) == 0 && strcmp(id_mk_csv, id_mk) == 0)
            {
                fclose(fp);
                return 1;
            }
        }
    }
    fclose(fp);
    return 0;
}

void tambahDataMatakuliah()
{
    int jumlah;
    printf("Masukkan jumlah matakuliah yang ingin diinput: ");
    if (scanf("%d", &jumlah) != 1)
    {
        printf("Input tidak valid!\n");
        bersihkanBufferInput();
        return;
    }
    bersihkanBufferInput();

    int sukses = 0;
    for (int i = 0; i < jumlah; i++)
    {
        Matakuliah mk;
        printf("\n--- Matakuliah #%d ---\n", i + 1);

        printf("ID MK  : ");
        fgets(mk.id_mk, MAX_MK_ID_LEN, stdin);
        amankanInput(mk.id_mk, MAX_MK_ID_LEN);

        if (cekDuplikat("matakuliah.csv", mk.id_mk, 0))
        {
            printf("Error: ID Matakuliah '%s' sudah terdaftar. Data ini dibatalkan.\n", mk.id_mk);
            continue;
        }

        printf("Nama   : ");
        fgets(mk.nama, MAX_NAME_LEN, stdin);
        amankanInput(mk.nama, MAX_NAME_LEN);

        printf("SKS    : ");
        scanf("%d", &mk.sks);
        bersihkanBufferInput();

        FILE *fp = fopen("matakuliah.csv", "a");
        if (fp)
        {
            fprintf(fp, "%s,%s,%d\n", mk.id_mk, mk.nama, mk.sks);
            fclose(fp);
            printf("Berhasil disimpan.\n");
            sukses++;
        }
        else
        {
            printf("Gagal menyimpan data ke file.\n");
        }
    }
    printf("\nProses selesai. Berhasil menambahkan %d dari %d data matakuliah.\n", sukses, jumlah);
}

void tambahDataMahasiswa()
{
    int jumlah;
    printf("Masukkan jumlah mahasiswa yang ingin diinput: ");
    if (scanf("%d", &jumlah) != 1)
    {
        printf("Input tidak valid!\n");
        bersihkanBufferInput();
        return;
    }
    bersihkanBufferInput();

    int sukses = 0;
    for (int i = 0; i < jumlah; i++)
    {
        Mahasiswa mhs;
        printf("\n--- Mahasiswa #%d ---\n", i + 1);

        printf("NIM    : ");
        fgets(mhs.nim, MAX_NIM_LEN, stdin);
        amankanInput(mhs.nim, MAX_NIM_LEN);

        if (cekDuplikat("mahasiswa.csv", mhs.nim, 0))
        {
            printf("Error: NIM '%s' sudah terdaftar. Data ini dibatalkan.\n", mhs.nim);
            continue;
        }

        printf("Nama   : ");
        fgets(mhs.nama, MAX_NAME_LEN, stdin);
        amankanInput(mhs.nama, MAX_NAME_LEN);

        printf("Prodi  : ");
        fgets(mhs.prodi, MAX_PRODI_LEN, stdin);
        amankanInput(mhs.prodi, MAX_PRODI_LEN);

        printf("IPK    : ");
        scanf("%f", &mhs.ipk);
        bersihkanBufferInput();

        FILE *fp = fopen("mahasiswa.csv", "a");
        if (fp)
        {
            fprintf(fp, "%s,%s,%s,%.2f\n", mhs.nim, mhs.nama, mhs.prodi, mhs.ipk);
            fclose(fp);
            printf("Berhasil disimpan.\n");
            sukses++;
        }
        else
        {
            printf("Gagal menyimpan data ke file.\n");
        }
    }
    printf("\nProses selesai. Berhasil menambahkan %d dari %d data mahasiswa.\n", sukses, jumlah);
}

void tambahDataKRS()
{
    int jumlah;
    printf("Masukkan jumlah entri KRS yang ingin diinput: ");
    if (scanf("%d", &jumlah) != 1)
    {
        printf("Input tidak valid!\n");
        bersihkanBufferInput();
        return;
    }
    bersihkanBufferInput();

    int sukses = 0;
    for (int i = 0; i < jumlah; i++)
    {
        KRS krs;
        printf("\n--- Entri KRS #%d ---\n", i + 1);

        printf("Masukkan NIM Mahasiswa: ");
        fgets(krs.nim_mahasiswa, MAX_NIM_LEN, stdin);
        amankanInput(krs.nim_mahasiswa, MAX_NIM_LEN);

        if (!cekDuplikat("mahasiswa.csv", krs.nim_mahasiswa, 0))
        {
            printf("Error: Mahasiswa dengan NIM '%s' tidak ditemukan.\n", krs.nim_mahasiswa);
            continue;
        }

        printf("Mahasiswa ditemukan. Masukkan Kode Matakuliah: ");
        fgets(krs.id_matakuliah, MAX_MK_ID_LEN, stdin);
        amankanInput(krs.id_matakuliah, MAX_MK_ID_LEN);

        if (!cekDuplikat("matakuliah.csv", krs.id_matakuliah, 0))
        {
            printf("Error: ID Matakuliah '%s' tidak valid/tidak ditemukan.\n", krs.id_matakuliah);
            continue;
        }

        if (cekDuplikatKRS(krs.nim_mahasiswa, krs.id_matakuliah))
        {
            printf("Error: Mahasiswa ini sudah mengambil matakuliah tersebut sebelumnya.\n");
            continue;
        }

        FILE *fp = fopen("krs.csv", "a");
        if (fp)
        {
            fprintf(fp, "%s,%s\n", krs.nim_mahasiswa, krs.id_matakuliah);
            fclose(fp);
            printf("KRS berhasil disimpan.\n");
            sukses++;
        }
        else
        {
            printf("Gagal menyimpan data ke file.\n");
        }
    }
    printf("\nProses selesai. Berhasil menambahkan %d dari %d data KRS.\n", sukses, jumlah);
}

void hapusDataMahasiswa(const char *nim_target)
{
    FILE *fp_in = fopen("mahasiswa.csv", "r");
    if (!fp_in)
    {
        printf("Error: Gagal membuka file mahasiswa.csv.\n");
        return;
    }

    FILE *fp_out = fopen("temp.csv", "w");
    if (!fp_out)
    {
        printf("Error: Gagal membuat file sementara (temp.csv).\n");
        fclose(fp_in);
        return;
    }

    char baris[512];
    int ditemukan = 0;
    int baris_ke = 0;

    while (fgets(baris, sizeof(baris), fp_in))
    {
        baris_ke++;

        if (baris_ke == 1)
        {
            fprintf(fp_out, "%s", baris);
            continue;
        }

        char temp_baris[512];
        strcpy(temp_baris, baris);

        char *nim_csv = strtok(temp_baris, ",");

        if (nim_csv != NULL && strcmp(nim_csv, nim_target) == 0)
        {
            printf("Info: Data Mahasiswa dengan NIM '%s' ditemukan dan akan dihapus.\n", nim_target);
            ditemukan = 1;
            continue;
        }

        fprintf(fp_out, "%s", baris);
    }

    fclose(fp_in);
    fclose(fp_out);

    if (ditemukan)
    {
        remove("mahasiswa.csv");
        if (rename("temp.csv", "mahasiswa.csv") != 0)
        {
            perror("Error: Gagal mengganti nama file sementara");
        }
        else
        {
            printf("Berhasil menghapus data Mahasiswa dengan NIM '%s'.\n", nim_target);
        }
    }
    else
    {
        remove("temp.csv");
        printf("Error: Data Mahasiswa dengan NIM '%s' tidak ditemukan.\n", nim_target);
    }
}