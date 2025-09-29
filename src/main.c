#include "definitions.h"
#include "stdlib.h"
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
/* unix only */
#include <csignal>
#include <cstdint>
#include <cstdlib>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/termios.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

void restore_input_buffering();
void handle_interrupt(int signal) {
  restore_input_buffering();
  printf("\n");
  exit(-2);
}
int main(int argc, char *argv[]) {

  signal(SIGINT, handle_interrupt);
  disable_input_buffering();

  if (argc < 2) {
    printf("main [image-file]...\n\texpected image file");
    exit(2);
  }

  for (int i = 1; i < argc; ++i) {
    if (!read_image([argv[j])) {
      printf("failed to load image:%s\n", argv[i]);
      exit(1);
    }
  }

  reg[R_COND] = FL_ZRO;

  // starting position of the program
  enum { PC_START = 0x3000 };
  reg[R_PC] = PC_START;

  int running = 1;
  while (running) {
    uint16_t instr = mem_read(reg[R_PC]++);
    /*
     Extracting the opcode from the instrution, as remaning 4 bits after
     shifting usually is representation of an opcode.
       15            12 11                         0
       +---------------+----------------------------+
       |   OPCODE      |         Operands           |
       +---------------+----------------------------+
      */
    uint16_t op = instr >> 12;

    switch (op) {
    case OP_ADD: {
        // as register mode(using registers to pass around values) and immediate mode(using values directly ) both are supported
      uint16_t r0 = (instr >> 9) & 0x7; 
      break;
    }

    case OP_BR: {
      break;
    }

    case OP_LD: {
      break;
    }

    case OP_ST: {
      break;
    }

    case OP_JSR: {
      break;
    }

    case OP_AND: {
      break;
    }

    case OP_LDR: {
      break;
    }

    case OP_STR: {
      break;
    }

    case OP_RTI: {
      break;
    }

    case OP_NOT: {
      break;
    }

    case OP_LDI: {
      break;
    }

    case OP_STI: {
      break;
    }

    case OP_JMP: {
      break;
    }

    case OP_RES: {
      break;
    }

    case OP_LEA: {
      break;
    }

    case OP_TRAP: {
      break;
    }
    }
  }

  restore_input_buffering();
  return EXIT_SUCCESS;
}
