#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <cstdint>
#include <vector>

class Memory {
public:
    static constexpr std::size_t MEMORY_SIZE = 1'048'576; // 1 MiB

    Memory();

    // Byte-level access
    uint8_t  read_byte(uint32_t address) const;
    void     write_byte(uint32_t address, uint8_t value);

    // Word-level access (little-endian). Decide policy for unaligned/OOB accesses.
    uint32_t read_word(uint32_t address) const;
    void     write_word(uint32_t address, uint32_t value);

    // Reset/initialize memory (zero-fill)
    void reset();

private:
    std::vector<uint8_t> mem;
};

#endif