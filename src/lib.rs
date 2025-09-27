#![allow(unused_variables, dead_code)]

const MEMORY_MAX: usize = 1 << 16;

// array of memory
pub static mut MEMORY: [u16; MEMORY_MAX] = [0; MEMORY_MAX];

pub enum Registers {
    R0 = 0,
    R1,
    R2,
    R3,
    R4,
    R5,
    R6,
    R7,
    RPC, // program counter
    RCond,
    RCount,
}

// array of registers
pub static mut REG: [u16; Registers::RCount as usize] = [0; Registers::RCount as usize];

// opcodes
pub enum Opcodes {
    BR = 0, //branch
    ADD,    // add
    LD,     // load
    ST,     //store
    JSR,    // jump register
    AND,    // bitwise and
    LDR,    // load register
    STR,    // store register
    RTI,    //unused
    NOT,    // bitwise not
    LDI,    //load indirect
    STI,    // store indirect
    JMP,    //jump
    RES,    //reserved (unused)
    LEA,    // load effective address
    TRAP,   //execute trap
}

// condition flags
pub enum ConditionFlags {
    FlPos = 1 << 0,
    FlZro = 1 << 1,
    FlNeg = 1 << 2,
}
