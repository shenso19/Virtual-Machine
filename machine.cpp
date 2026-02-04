#include <iostream>
#include <cstddef>
#include <cstdint>
using namespace std;

class Machine {
    private:
    static constexpr size_t MEMORY_SIZE = 1048576; // 1MiB
    uint32_t regs[32]; // Array of 32 registers, 32 bits each
    uint8_t memory[MEMORY_SIZE]; // RAM (Array of 1048576 8 bit values)
    uint32_t pc; // Program Counter
    
    /* Below is a function that will ensure that when register 0 is read the returned value will always be zero. if it is any other register, the function will return the value of that register. */
    public:
    uint32_t read_reg(int i) {
        if (i == 0) {
            return 0;
        } else {
            return regs[i];
        }
    }
    
    /* Below is a function that will ensure that if there is an attempt to write to register 0 (regs[0]), nothing will happen. When any other register is written to, the new value of the register will be the written value */
    
    void write_reg(uint32_t i, uint32_t value) {
        if (i == 0) {
            return;
        }else {
            regs[i] = value;
        }
    }
    
    /* Below is the reset function that sets every value of regs to 0, specifically forces regs 0 to 0, and sets the pc to 0. with public access */
    
   
    void reset() {
        for (int i = 0; i < 32; i++) { 
            regs[i] = 0;
        }
        regs[0] = 0;
        pc = 0;
        regs[2] = MEMORY_SIZE;
    }
    
}

