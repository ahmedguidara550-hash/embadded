#!/bin/sh
# Download the official ST/Arm header files needed to build for the STM32F407.
set -e
mkdir -p third_party
cd third_party
[ -d cmsis_core ]      || git clone --depth 1 https://github.com/STMicroelectronics/cmsis_core.git
[ -d cmsis_device_f4 ] || git clone --depth 1 https://github.com/STMicroelectronics/cmsis_device_f4.git
echo "third_party is ready"
