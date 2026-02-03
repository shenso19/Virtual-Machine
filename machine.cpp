#include <iostream>
#include <cstdint>
using namespace std;

class Machine {
private:
    static constexpr size_t MEMORY_SIZE = 1048576; // 1 MiB
    uint32_t regs[32]; // array of 32 registers, 32 bits each
    uint8_t memory[MEMORY_SIZE]; // RAM
    uint32_t pc; // program counter

    /* Below is a function that will ensure that when register 0 is read that the returned value will always be zero,
    and when any other register is read that it will return the stored value of that register. */
    uint32_t read_reg(uint32_t index) {
        if (index == 0) {
            return 0;
        } else {
            return regs[index];
        }
        }


    /* Below is a function that will ensure that when a user attempt to write to register 0 that nothing happens. When a user attempt to write to any other register, the value of
    the register changes to the input value. */
    void write_reg(uint32_t index, uint32_t value) {
        if (index == 0) {
            return;
        } else {
            regs[index] = value;

        }
        }
public:
    void reset() {
        for (uint32_t index = 0; index <= 32; index++) {
            regs[index] = 0;
        regs[0] = 0;
        pc = 0;
        }
}
    };
