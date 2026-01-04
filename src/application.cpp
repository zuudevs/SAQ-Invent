#include "SAQ-Invent.hpp"
#include <iostream>
#include <limits>

namespace saq {

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Application::run() {
    saq::Manager manager;
    bool running = true;

    while (running) {
        std::cout << "\n=== SAQ Inventaris===\n";
        std::cout << "1. Tambah Barang\n";
        std::cout << "2. Cek Barang (Cari Kode)\n";
        std::cout << "3. Hapus Stock Barang\n";
        std::cout << "4. Keluar\n";
        std::cout << "Pilih menu > ";

        int choice;
        if (!(std::cin >> choice)) {
            clearInput();
            std::cout << "Input ngawur! Masukkan angka.\n";
            continue;
        }
        clearInput(); // Bersihkan buffer newline

        if (choice == 1) {
            std::string name, brand, code, loc, detail;
            std::cout << "Kode Barang: "; std::getline(std::cin, code);
            std::cout << "Nama Barang: "; std::getline(std::cin, name);
            std::cout << "Brand: "; std::getline(std::cin, brand);
            std::cout << "Lokasi: "; std::getline(std::cin, loc);
            std::cout << "Detail: "; std::getline(std::cin, detail);
            
            // Default state Good
            manager.addItem(saq::Item(name, brand, code, loc, saq::State::Good, detail));
            std::cout << "[INFO] Barang berhasil ditambahkan! Total Qty: " << manager.getQuantity(code) << "\n";

        } else if (choice == 2) {
            std::string code;
            std::cout << "Masukkan Kode Barang: "; std::getline(std::cin, code);

            if (manager.hasItem(code)) {
                const auto& item = manager.getItem(code);
                std::cout << "\n--- Detail Barang ---\n";
                std::cout << "Nama    : " << item.name << "\n";
                std::cout << "Brand   : " << item.brand << "\n";
                std::cout << "Lokasi  : " << item.location << "\n";
                std::cout << "Jumlah  : " << manager.getQuantity(code) << "\n";
                std::cout << "Status  : " << (saq::isBorrowed(item.state) ? "DIPINJAM" : "TERSEDIA") << "\n";
            } else {
                std::cout << "[404] Barang tidak ditemukan, Rara...\n";
            }

        } else if (choice == 3) {
            std::string code;
            std::cout << "Masukkan Kode Barang: "; std::getline(std::cin, code);
            manager.removeItem(code);
            std::cout << "[INFO] Stock dikurangi. Sisa: " << manager.getQuantity(code) << "\n";

        } else if (choice == 4) {
            running = false;
            std::cout << "Bye-bye! Belajar yang rajin ya.\n";
        }
    }
}

} // namespace saq