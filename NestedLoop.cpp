#include <iostream>
#include <iomanip>
#include <cctype>

class MultiplicationTable {
public:
    MultiplicationTable(size_t size = 0) : table_size(size) {}
    
    void setSize(size_t size) {
        if (size >= table_min && size <= table_max) {
            table_size = size;
        } else {
            std::cerr << "Invalid table size entered. Program terminated." << std::endl;
            exit(1); // Exit the program if the size is invalid
        }
    }
    
    void printTable() const {
        // Create the top line of the table
        std::cout << std::setw(6) << " |";
        for (size_t i = 1; i <= table_size; ++i) {
            std::cout << " " << std::setw(3) << i << " |";
        }
        std::cout << std::endl;

        // Create the separator row
        for (size_t i = 0; i <= table_size; ++i) {
            std::cout << "------";
        }
        std::cout << std::endl;

        // Output the multiplication table
        for (size_t i = 1; i <= table_size; ++i) {
            std::cout << " " << std::setw(3) << i << " |";
            for (size_t j = 1; j <= table_size; ++j) {
                std::cout << " " << std::setw(3) << i * j << " |";
            }
            std::cout << std::endl;
        }
    }

public:
    size_t table_size;
    static const size_t table_min = 2;  // Minimum table size
    static const size_t table_max = 12; // Maximum table size
};

// Define static members outside the class
const size_t MultiplicationTable::table_min;
const size_t MultiplicationTable::table_max;

int main() {
    char reply {};
    do {
        size_t size {};
        std::cout << "What size table would you like (" << MultiplicationTable::table_min<< " to " << MultiplicationTable::table_max << ")? ";
        std::cin >> size;

        MultiplicationTable table;
        table.setSize(size);
        table.printTable();

        std::cout << "\nDo you want another table (y or n)? ";
        std::cin >> reply;
    } while (std::tolower(reply) == 'y');

    return 0;
}
