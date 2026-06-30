<div align="center">

# 🎓 Sistem Database Akademik (KRS)
### Academic Records System (KRS)

CLI berbasis **C** untuk mengelola data **mahasiswa**, **matakuliah**, dan **KRS** dengan penyimpanan file CSV.
<br/>
A **C**-based CLI for managing **student**, **course**, and **enrollment (KRS)** data with CSV file storage.

![Language](https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c&logoColor=white)
![Build](https://img.shields.io/badge/Build-GCC-darkgreen?style=flat-square&logo=gnu)
![Interface](https://img.shields.io/badge/Interface-CLI-555?style=flat-square&logo=gnubash&logoColor=white)
![Storage](https://img.shields.io/badge/Storage-CSV-217346?style=flat-square&logo=files&logoColor=white)

🇮🇩 Bahasa Indonesia &nbsp;•&nbsp; 🇬🇧 English

</div>

---

## 📖 Tentang / About

**🇮🇩** Program ini adalah sistem manajemen data akademik sederhana yang dijalankan lewat baris perintah (command-line). Program mengelola tiga entitas yang saling berhubungan — Mahasiswa, Matakuliah, dan KRS (Kartu Rencana Studi) — dan menyimpan semuanya secara permanen dalam file `.csv`. Setiap operasi dipilih melalui argumen saat program dijalankan.

**🇬🇧** This is a simple command-line academic data management system. It handles three related entities — Students, Courses, and KRS (course enrollment) — and persists everything to `.csv` files. Each operation is selected through a command-line argument at runtime.

---

## ✨ Fitur / Features

| 🇮🇩 Fitur | 🇬🇧 Feature |
|----------|------------|
| ➕ Tambah data matakuliah, mahasiswa, & KRS | Add course, student & enrollment data |
| 🗑️ Hapus data mahasiswa berdasarkan NIM | Delete a student by their ID (NIM) |
| 🔁 Pengecekan duplikat otomatis | Automatic duplicate detection |
| 📄 Auto-inisialisasi file CSV beserta header | Auto-creates CSV files with headers |
| 🛡️ Penanganan input yang aman (buffer cleaning) | Safe input handling (buffer cleaning) |
| 🧩 Struktur modular (header + implementasi terpisah) | Modular structure (separate header & implementation) |

---

## 🗂️ Model Data / Data Model

**🇮🇩** Tiga entitas membentuk relasi many-to-many: mahasiswa mengambil banyak matakuliah, dicatat lewat tabel penghubung KRS.
**🇬🇧** Three entities form a many-to-many relationship: students take many courses, linked through the KRS junction table.

```
┌──────────────────┐        ┌──────────────────┐        ┌──────────────────┐
│    Mahasiswa     │        │       KRS        │        │   Matakuliah     │
│  (mahasiswa.csv) │◄──────►│    (krs.csv)     │◄──────►│ (matakuliah.csv) │
├──────────────────┤        ├──────────────────┤        ├──────────────────┤
│ NIM   (PK)       │        │ NIM_Mahasiswa    │        │ ID_MK  (PK)      │
│ Nama             │        │ ID_Matakuliah    │        │ Nama             │
│ Prodi            │        └──────────────────┘        │ SKS              │
│ IPK              │                                    └──────────────────┘
└──────────────────┘
```

---

## 🛠️ Teknologi / Tech Stack

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![GCC](https://img.shields.io/badge/GCC-A42E2B?style=for-the-badge&logo=gnu&logoColor=white)

- **Bahasa / Language:** C (standard library: `stdio.h`, `stdlib.h`, `string.h`)
- **Konsep / Concepts:** File I/O, parsing CSV (`strtok`), `struct`, modular programming, argument handling

---

## 🚀 Cara Menjalankan / Getting Started

**1. Compile**

```bash
gcc main.c filedata.c -o program
```

**2. Jalankan / Run**

```bash
# 🇮🇩 Tambah matakuliah   |  🇬🇧 Add courses
./program 1

# 🇮🇩 Tambah mahasiswa    |  🇬🇧 Add students
./program 2

# 🇮🇩 Tambah KRS          |  🇬🇧 Add enrollment (KRS)
./program 3

# 🇮🇩 Hapus mahasiswa berdasarkan NIM  |  🇬🇧 Delete student by NIM
./program 4 220001
```

> 💡 **Windows:** ganti `./program` menjadi `program.exe` / replace `./program` with `program.exe`.

---

## 📋 Contoh Output CSV / Sample CSV Output

```csv
# mahasiswa.csv
NIM,Nama,Prodi,IPK
220001,Kiyo,Teknik Informatika,3.85

# matakuliah.csv
ID_MK,Nama,SKS
IF101,Struktur Data,3

# krs.csv
NIM_Mahasiswa,ID_Matakuliah
220001,IF101
```

---

## 📁 Struktur Proyek / Project Structure

```
Program-database/
├── main.c          # 🇮🇩 Entry point & routing argumen  | 🇬🇧 Entry point & argument routing
├── filedata.c      # 🇮🇩 Logika baca/tulis & validasi   | 🇬🇧 Read/write & validation logic
├── filedata.h      # 🇮🇩 Definisi struct & prototipe      | 🇬🇧 Struct definitions & prototypes
└── *.csv           # 🇮🇩 File data (dibuat otomatis)      | 🇬🇧 Data files (auto-generated)
```

---

## 🧠 Apa yang Dipelajari / Key Takeaways

**🇮🇩** Proyek ini melatih manajemen file di C, pemisahan kode menjadi modul (`.h` / `.c`), pemodelan relasi data, dan parsing teks CSV manual tanpa library eksternal.

**🇬🇧** This project practices file management in C, separating code into modules (`.h` / `.c`), modeling data relationships, and parsing CSV text manually without external libraries.

---

<div align="center">

### 👤 Author

**Yeurekaaa** — Teknik Informatika, Universitas Hasanuddin (UNHAS)

[![GitHub](https://img.shields.io/badge/GitHub-mydJhi07-181717?style=for-the-badge&logo=github)](https://github.com/mydJhi07)

⭐ *Star repo ini jika bermanfaat! / Star this repo if you find it useful!*

</div>
