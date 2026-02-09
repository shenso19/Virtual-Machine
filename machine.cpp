#include <cstdint>
#include "register.hpp"
#include "memory.hpp"

class Machine {
private:
    Register regs;       // 32 integer registers 
    Memory mem;          // 1 MiB memory
    uint32_t pc;         // program counter

public:
    // Constructor: initializes registers, memory, and PC
    Machine() {
        reset();
    }

    // Reset function: resets PC, registers, and memory (optional)
    void reset() {
        pc = 0;
        regs.reset();  
        mem.reset();    
    }

    // PC access
    uint32_t get_pc() const {
        return pc;
    }

    void set_pc(uint32_t new_pc) {
        pc = new_pc;
    }

    // Register access (delegates to Register class)
    uint32_t read_reg(uint8_t i) const {
        return read_reg(i);
    }

    void write_reg(uint8_t i, uint32_t value) {
        regs.write(i, value);
    }

    // Memory access (delegates to Memory class)
    uint8_t read_byte(uint32_t addr) const {
        return mem.read_byte(addr);
    }

    void write_byte(uint32_t addr, uint8_t value) {
        mem.write_byte(addr, value);
    }

    uint32_t read_word(uint32_t addr) const {
        return mem.read_word(addr);
    }

    void write_word(uint32_t addr, uint32_t value) {
        mem.write_word(addr, value);
    }
};


