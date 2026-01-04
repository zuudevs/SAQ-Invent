#pragma once

#include "registry/table.hpp"
#include <cstddef>
#include <unordered_map>
#include <vector>

namespace saq {

class Manager {
private:
	Table table;
	std::unordered_map<std::string, std::size_t> qty;

public:
	Manager() = default;
	~Manager() = default;

	Manager(const Manager&) = delete;
	Manager& operator=(const Manager&) = delete;

    // Cek apakah item ada
    bool hasItem(const std::string& code) const noexcept {
        try {
            table.get(code);
            return true;
        } catch(...) {
            return false;
        }
    }

	const Item& getItem(const std::string& code) const { return table.get(code); }
	Item& getItem(const std::string& code) { return table.get(code); }

	Manager& addItem(const Item& item) noexcept { 
        table.push(item); 
        qty[item.code]++; // Tambah quantity
        return *this; 
    }

	Manager& removeItem(const std::string& code) noexcept { 
        if (qty.contains(code) && qty[code] > 0) {
            qty[code]--;
            if(qty[code] == 0) {
                // table.pop(code); // Uncomment jika ingin hapus permanen saat habis
            }
        }
        return *this; 
    }
    
    std::size_t getQuantity(const std::string& code) const noexcept {
        if(qty.contains(code)) return qty.at(code);
        return 0;
    }
};

} // namespace saq