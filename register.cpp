class Register {
    public:
        Register();
        
        uint32_t read(uint8_t reg) const;
        void write(uint8_t reg, uint32_t value);
        void reset();
        void print();
        
    private:
        uint32_t regs[32]; //Array of 32 registers, 32 bits each
}

