#ifndef SIGNEXT_HPP
#define SIGNEXT_HPP

#include <cstdint>



inline uint32_t sign_extend(uint32_t value, unsigned sign_bit_index) {  // sign extend function that takes a value and the location of the sign bit within the field.
  
    const uint32_t sign_bit = (1u << sign_bit_index);           // shifts 1 to the sign bit position to create a mask that identifies the sign bit within the field.
    const uint32_t field_mask = (sign_bit << 1) - 1u;          // shifts the sign bit to the left by 1 and then subtracts 1 to create a mask of all ones across the field width. This will be used to isolate the bits of the immediate value that we want to sign-extend.
    const uint32_t sign = (value >> sign_bit_index) & 1u;       // shifts the value right by the sign bit index and masks it with 1 to extract the actual sign bit (0 or 1) from the value.
    const uint32_t full_sign = 0u - sign;                      // negates the sign bit to create a full-width sign extension mask. If the sign bit is 1, this results in all bits being set to 1 (0xFFFFFFFF); if the sign bit is 0, this results in all bits being 0 (0x00000000).
    const uint32_t high_mask = ~field_mask;                    // inverts the field mask to create a mask that has zeros in the field width and ones elsewhere. This will be used to apply the sign extension to the higher bits of the value.
    return (value & field_mask) | (full_sign & high_mask);      // combines the original value (masked to keep only the bits within the field) with the sign extension (applied to the higher bits) using a bitwise OR operation. This results in the final sign-extended value.
}

#endif // SIGNEXT_HPP
``