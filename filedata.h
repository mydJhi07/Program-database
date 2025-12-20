#ifndef filedata_h
#define filedata_h

#define MAX_NAME_LEN 100
#define MAX_PRODI_LEN 50
#define MAX_NIM_LEN 20
#define MAX_MK_ID_LEN 20

typedef struct
{
    char nim[MAX_NIM_LEN];
    char nama[MAX_NAME_LEN];
    char prodi[MAX_PRODI_LEN];
    float ipk;
} Mahasiswa;

typedef struct
{
    char id_mk[MAX_MK_ID_LEN];
    char nama[MAX_NAME_LEN];
    int sks;
} Matakuliah;

typedef struct
{
    char nim_mahasiswa[MAX_NIM_LEN];
    char id_matakuliah[MAX_MK_ID_LEN];
} KRS;

void bersihkanBufferInput();

void inisialisasiFile(const char *namaFile, const char *header);
int cekDuplikat(const char *namaFile, const char *key, int kolom);
int cekDuplikatKRS(const char *nim, const char *id_mk);

void tambahDataMatakuliah();
void tambahDataMahasiswa();
void tambahDataKRS();
void hapusDataMahasiswa(const char *nim_target);

#endif