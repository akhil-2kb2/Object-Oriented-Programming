#include <iostream>
#include <iomanip> // For std::setw and std::setfill

using namespace std;

int main() {
    unsigned int red = 0xFF0000u; // Color red
    unsigned int white = 0xFFFFFFu; // Color white - RGB all maximum
    
    cout << hex << setfill('0'); // Hexadecimal output and fill character 0
    cout << "Try out bitwise complement, AND and OR operators:\n";
    cout << "Initial value: red = " << setw(8) << red << endl;
    cout << "Complement: ~red = " << setw(8) << ~red << endl;
    cout << "Initial value: white = " << setw(8) << white << endl;
    cout << "Complement: ~white = " << setw(8) << ~white << endl;
    cout << "Bitwise AND: red & white = " << setw(8) << (red & white) << endl;
    cout << "Bitwise OR: red | white = " << setw(8) << (red | white) << endl;

    cout << "\nNow try successive exclusive OR operations:\n";
    unsigned int mask = red ^ white;
    cout << "mask = red ^ white = " << setw(8) << mask << endl;
    cout << "mask ^ red = " << setw(8) << (mask ^ red) << endl;
    cout << "mask ^ white = " << setw(8) << (mask ^ white) << endl;

    unsigned int flags = 0xFF; // Flags variable
    unsigned int bit1mask = 0x1; // Selects bit 1
    unsigned int bit6mask = 0b100000; // Selects bit 6
    unsigned int bit20mask = 1u << 19; // Selects bit 20
    
    cout << "\nUse masks to select or set a particular flag bit:\n";
    cout << "Select bit 1 from flags : " << setw(8) << (flags & bit1mask) << endl;
    cout << "Select bit 6 from flags : " << setw(8) << (flags & bit6mask) << endl;
    flags &= ~bit6mask; // Switch off bit 6 in flags
    cout << "Switch off bit 6 in flags: " << setw(8) << flags << endl;
    flags |= bit20mask; // Switch on bit 20 in flags
    cout << "Switch on bit 20 in flags: " << setw(8) << flags << endl;

    return 0;
}

