
inline uint32_t sign_extend(uint32_t value, unsigned sign_bit_index) {
  
    const uint32_t sign_bit = (1u << sign_bit_index);           // shifts 1 to the sign bit position ensuring that we keep negative vs positive. The index determines how many positions to shift. 
    const uint32_t field_mask = (sign_bit << 1) - 1u;          // shifts the sign bit to the left by 1 and then subtracts 1 to create a mask of all ones across the field width. This will be used to isolate the bits of the immediate value that we want to sign-extend.
    const uint32_t sign = (value >> sign_bit_index) & 1u;       
    const uint32_t full_sign = 0u - sign;                      
    const uint32_t high_mask = ~field_mask;                    
    return (value & field_mask) | (full_sign & high_mask);      
}