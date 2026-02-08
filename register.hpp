#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <cstdint>

class Register {
public:
    Register();

    void reset();

    uint32_t read(uint8_t index) const;


    void write(uint8_t index, uint32_t value);


private:
    uint32_t regs[32];
};

#endif