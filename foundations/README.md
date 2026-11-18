# Embedded C foundations

The first stage of my path to embedded systems engineering: from bits and bytes to a tested, cross-compiled C library. Everything here was written, compiled and debugged by hand on Linux. No hardware board is needed for any of it.

## Highlights

| Project | What it is | Status |
|---|---|---|
| [`ringbuf/`](ringbuf/) | Allocation-free ring buffer (circular FIFO) of bytes, designed for UART/CAN receive queues | v1.0: 10 unit tests, 100% line, function and branch coverage |
| [`bits/`](bits/) | `bits.h`: SET, CLEAR, TOGGLE and READ macros for single bits and bit fields, the same operations used on hardware registers | Unit tested |

### ringbuf at a glance

- No dynamic memory: the caller provides the storage
- Clean under `-Wall -Wextra -Wconversion -Werror`, cppcheck, clang-tidy, `gcc -fanalyzer`, AddressSanitizer and UBSan
- Builds with both Make and CMake
- Cross-compiles for ARM Cortex-M4 (182 bytes of code with `-Os`)
- Includes a bare-metal firmware image with its own startup code and linker script

The API, usage example and design decisions are in [`ringbuf/README.md`](ringbuf/README.md).

## Skills demonstrated

| Topic | What it covers | Where |
|---|---|---|
| Number representation | Bits, bytes, hex, integer types, overflow, two's complement, integer promotion, endianness | `01-c-basics/`, `02-pointers-memory/` |
| Pointers and memory | Arrays, structs, pointers, memory layout (stack, heap, `.data`, `.bss`), `volatile`, struct padding | `02-pointers-memory/` |
| Debugging | GDB: breakpoints, stepping, `print`, `watch`, backtraces | `02-pointers-memory/` |
| Build systems | Headers vs sources, linker errors, Make, CMake | `03-build-cross-compile/`, `ringbuf/` |
| Cross-compiling | `arm-none-eabi-gcc`, startup code, linker script, map file | `ringbuf/baremetal/` |
| Testing and quality | Unity, TDD, gcov/lcov coverage, static analysis, sanitizers, MISRA C basics | `ringbuf/` |
| Git workflow | Branches, pull requests, tagged releases, rebase, bisect | repository history |

## Folder layout

```text
foundations/
├── 01-c-basics/      first C programs: types, control flow, bit operators
├── 02-pointers-memory/      pointers, memory layout, debugging exercises
├── 03-build-cross-compile/      build experiments: compiler stages, multi-file project
├── 04-testing-quality/      static analysis exercise
├── bits/       bits.h and its tests
└── ringbuf/    the ring buffer library
    ├── include/ringbuf.h
    ├── src/ringbuf.c
    ├── app/        demo program for the PC
    ├── baremetal/  startup code, linker script, firmware
    ├── test/       Unity tests
    ├── Makefile
    └── CMakeLists.txt
```

The learning notes for each stage are in [`../log/`](../log/).

## Build and test

Install the tools on Ubuntu (or WSL):

```bash
sudo apt update
sudo apt install -y build-essential gdb git make cmake valgrind cppcheck clang-tidy lcov gcc-arm-none-eabi binutils-arm-none-eabi
```

Then, from `foundations/ringbuf`:

```bash
make test        # run the unit tests
make coverage    # coverage report in build/cov/html/index.html
make analyze     # static analysis
make arm         # ringbuf.o for Cortex-M4 and its size
make firmware    # bare-metal firmware.elf for an STM32F407-class chip
make clean
```

## Status

Complete. The firmware image builds for an STM32F407-class chip but has not been run on a real board yet. That is the next step.