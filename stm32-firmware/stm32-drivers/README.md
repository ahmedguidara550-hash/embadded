# stm32-drivers
 
Bare-metal drivers for the STM32F407 (Cortex-M4), written step by step.
Runs in the Renode simulator, no board needed. Also runs on the STM32F4-Discovery.
 
## Build and run
    ./scripts/fetch_third_party.sh   # once: official ST/Arm headers
    make APP=blink_cmsis             # build app/blink_cmsis.c
    make APP=blink_cmsis run         # run it in the Renode simulator
 
## Requirements
- arm-none-eabi-gcc (xPack 15.2.1), GNU make, git
- Renode 1.17.0 for the simulator
 
## Status
Step 1: startup file (98 vectors), linker script, GPIO blink with raw addresses and with the CMSIS headers. Stretches: four-LED walk with BSRR, comparison with ST's Reset_Handler, and a CubeMX/HAL blink compared with register code (42 lines against 3).
