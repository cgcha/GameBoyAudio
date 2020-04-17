#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    GameBoy Memory Areas

 	$FFFF 	Interrupt Enable Flag
	$FF80-$FFFE 	Zero Page - 127 bytes
	$FF00-$FF7F 	Hardware I/O Registers
	$FEA0-$FEFF 	Unusable Memory
	$FE00-$FE9F 	OAM - Object Attribute Memory
	$E000-$FDFF 	Echo RAM - Reserved, Do Not Use
	$D000-$DFFF 	Internal RAM - Bank 1-7 (switchable - CGB only)
	$C000-$CFFF 	Internal RAM - Bank 0 (fixed)
	$A000-$BFFF 	Cartridge RAM (If Available)
	$9C00-$9FFF 	BG Map Data 2
	$9800-$9BFF 	BG Map Data 1
	$8000-$97FF 	Character RAM
	$4000-$7FFF 	Cartridge ROM - Switchable Banks 1-xx
	$0150-$3FFF 	Cartridge ROM - Bank 0 (fixed)
	$0100-$014F 	Cartridge Header Area
	$0000-$00FF 	Restart and Interrupt Vectors (BIOS)
 */


// The CPU of the Game Boy is a custom chip similar to the Intel 8080 and the Zilog Z80
// It is an 8-bit processor, so it can access 8-bits of data at a time, but 
// can read and write 16 bits at the same time
// The registers are labelled a-l, but are missing g, i, j, and k in documentation.

// Main documentation used in http://bgb.bircd.org/pandocs.htm

struct Registers
{
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t f;
    uint8_t h;
    uint8_t l;
    uint16_t SP; // Stack pointer
    uint16_t PC; // Program Counter
    uint16_t af;
    uint16_t bc;
    uint16_t de;
    uint16_t hl;

};
struct FlagsRegister //lower 8bit of af register
{
    bool zero;  // zf flag - bit 7
                // set to (1) if the result of an operation
                // has been (0). For conditional jumps
    bool subtract;   // n flag - bit 6
    bool half_carry; // h flag - bit 5
                     // n and h rarely used, mostly for overflow or underflow


    bool carry; //cy flag - bit 4
    //bits 3-0 are unused and always zero
};

void reset() {
    //af = 0x01B0;
    //bc = 0x0013;
    //de = 0x00D8;
    //hl = 0x014D;
    //SP = 0xFFFE;
    //PC = 0x0100;
}

void get_af() 
{
    
}

void get_bc() 
{
    
}

void get_de() 
{
    
}

void get_hl() 
{
    
}


// Opcode documentation from http://www.devrs.com/gb/files/opcodes.html




int main()
{

}