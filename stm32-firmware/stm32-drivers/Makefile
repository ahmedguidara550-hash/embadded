# ============ settings ============
APP      ?= blink_cmsis
BUILD    := build
 
CC       := arm-none-eabi-gcc
CPU      := -mcpu=cortex-m4 -mthumb -mfloat-abi=soft
CMSIS    := -isystem third_party/cmsis_device_f4/Include \
            -isystem third_party/cmsis_core/CMSIS/Core/Include
CFLAGS   := -std=c11 $(CPU) -Os -g3 -Wall -Wextra -Wconversion -Werror \
            -ffunction-sections -fdata-sections -DSTM32F407xx -Iinclude $(CMSIS) -MMD -MP
LDFLAGS  := $(CPU) -T linker/stm32f407.ld -nostartfiles --specs=nano.specs --specs=nosys.specs \
            -Wl,--gc-sections -Wl,-Map=$(BUILD)/$(APP).map
 
DRIVER_SRC := startup/startup_stm32f407.c src/system.c
OBJ      := $(DRIVER_SRC:%.c=$(BUILD)/%.o) $(BUILD)/app/$(APP).o
 
RENODE   ?= renode
 
# ============ targets ============
.PHONY: all size run clean
 
all: $(BUILD)/$(APP).elf size
 
$(BUILD)/$(APP).elf: $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@
 
size: $(BUILD)/$(APP).elf
	arm-none-eabi-size $<
 
# Run the firmware in the Renode simulator (no board needed).
run: $(BUILD)/$(APP).elf
	$(RENODE) --disable-xwt --console --plain renode/$(APP).resc
 
# one rule that builds ANY .o file from the .c file with the same name
$(BUILD)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
 
$(BUILD)/app/%.o: app/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	rm -rf $(BUILD)
 
-include $(OBJ:.o=.d)
