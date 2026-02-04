class Memory {
    public:
        Memory();
        
        uint32_t read_word(uint32_t address) const;
        uint8_t read_byte(uint32_t address) const;
        
        void write_word(uint32_t address, uint32_t value);
        void write_bye(uint32_t address, uint8_t value);
        
        void reset();
        
        void print(uint32_t start, uint32_t end) const;
        
        const std::vector<uint8_t>& get_raw_memory() const;
        
    private:
    std::vector<uint8_t> mem;
};
