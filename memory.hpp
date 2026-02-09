#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <cstdint>
#include <vector>
#include <cstddef>

class Memory {
public:
    static constexpr std::size_t MEMORY_SIZE = 1'048'576; // 1 MiB

    Memory();

 
    uint8_t  read_byte(uint32_t address) const;
    void     write_byte(uint32_t address, uint8_t value);

    uint32_t read_word(uint32_t address) const;
    void     write_word(uint32_t address, uint32_t value);

  
    void reset();

private:
    std::vector<uint8_t> mem;
};

#endif
