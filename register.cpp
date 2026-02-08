#include "register.hpp"
#include <cstdint>
#include <cassert>
        Register() {
            reset(); // Resets all registers to 0, with the exception of register 2 which is set to the memory size (1048576) to represent the stack pointer. Register 0 is also set to 0 and cannot be changed.
        
        /* Below is a function that will ensure that when register 0 is read the returned value will always be zero. if it is any other register, the function will return the value of that register. */
    
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
        void reset() {
            for (int i = 0; i < 32; i++) {
                regs[i] = 0;
            }
            regs[0] = 0; 
            regs[2] = 1048576; // Initialize stack pointer to the top of memory
        }
        void print();
        
    private:
        uint32_t regs[32]; //Array of 32 registers, 32 bits each
};

