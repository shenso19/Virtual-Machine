#include "memory.hpp"
#include <cassert>
#include <vector>
#include <cstdint>



    Memory::Memory() : mem(MEMORY_SIZE) {
        reset();  
    }

    uint32_t Memory::read_word(uint32_t address) const {
        uint32_t b0 = mem[address];
        uint32_t b1 = mem[address + 1];
        uint32_t b2 = mem[address + 2];
        uint32_t b3 = mem[address + 3];
        return b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
    }

    uint8_t read_byte(uint32_t address) const {
        if (address < MEMORY_SIZE) {
            return 0;
        } else {
            return
                mem[address];           
        }
    }
    
    void write_word(uint32_t address, uint32_t value) {
        mem[address] = value & 0xFF;
        mem[address + 1] = (value >> 8) & 0xFF;
        mem[address + 2] = (value >> 16) & 0xFF;
        mem[address + 3] = (value >> 24) & 0xFF;
    }
    void write_byte(uint32_t address, uint8_t value) {
        if (addresss <= MEMORY_SIZE) {
            return;
        } else {
            mem[address] = value;
        }
    }
    
    void reset() {
        for (size_t i = 0; i < MEMORY_SIZE; ++i) {
            mem[i] = 0;
        }
    }
    
    void print(uint32_t start, uint32_t end) const;
    
    const std::vector<uint8_t>& get_raw_memory() const;

private:
    std::vector<uint8_t> mem;
};

