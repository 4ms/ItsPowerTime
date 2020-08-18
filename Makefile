# This file was automagically generated by mbed.org. For more information,
# see http://mbed.org/handbook/Exporting-to-GCC-ARM-Embedded
#
# Modified by Dan Green

###############################################################################
# Boiler-plate

# cross-platform directory manipulation
ifeq ($(shell echo $$OS),$$OS)
    MAKEDIR = if not exist "$(1)" mkdir "$(1)"
    RM = rmdir /S /Q $(1)
else
    MAKEDIR = '$(SHELL)' -c "mkdir -p \"$(1)\""
    RM = $(SHELL) -c "rm -rf $(1)"
endif

OBJDIR := BUILD

###############################################################################
# Project settings

PROJECT := VM-Z
TARGET_PATH := /Volumes/DIS_F429ZI/

###############################################################################
ELF = $(OBJDIR)/$(PROJECT).elf
BIN = $(OBJDIR)/$(PROJECT).bin
HEX = $(OBJDIR)/$(PROJECT).hex

OBJECTS += $(OBJDIR)/BSP_DISCO_F429ZI/Drivers/BSP/Components/ili9341/ili9341.o
OBJECTS += $(OBJDIR)/BSP_DISCO_F429ZI/Drivers/BSP/Components/l3gd20/l3gd20.o
OBJECTS += $(OBJDIR)/BSP_DISCO_F429ZI/Drivers/BSP/Components/stmpe811/stmpe811.o
OBJECTS += $(OBJDIR)/BSP_DISCO_F429ZI/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery.o
OBJECTS += $(OBJDIR)/BSP_DISCO_F429ZI/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_eeprom.o
OBJECTS += $(OBJDIR)/BSP_DISCO_F429ZI/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_gyroscope.o
OBJECTS += $(OBJDIR)/BSP_DISCO_F429ZI/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_io.o
OBJECTS += $(OBJDIR)/BSP_DISCO_F429ZI/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_lcd.o
OBJECTS += $(OBJDIR)/BSP_DISCO_F429ZI/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_sdram.o
OBJECTS += $(OBJDIR)/BSP_DISCO_F429ZI/Drivers/BSP/STM32F429I-Discovery/stm32f429i_discovery_ts.o
OBJECTS += $(OBJDIR)/BSP_DISCO_F429ZI/Utilities/Fonts/font12.o
OBJECTS += $(OBJDIR)/BSP_DISCO_F429ZI/Utilities/Fonts/font16.o
OBJECTS += $(OBJDIR)/BSP_DISCO_F429ZI/Utilities/Fonts/font20.o
OBJECTS += $(OBJDIR)/BSP_DISCO_F429ZI/Utilities/Fonts/font24.o
OBJECTS += $(OBJDIR)/BSP_DISCO_F429ZI/Utilities/Fonts/font8.o
OBJECTS += $(OBJDIR)/LCD_DISCO_F429ZI/LCD_DISCO_F429ZI.o
OBJECTS += $(OBJDIR)/TS_DISCO_F429ZI/TS_DISCO_F429ZI.o

SRCDIR = src/
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
SOURCES += $(wildcard $(SRCDIR)/*.c)

OBJECTS += $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(SOURCES))))

SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/PeripheralPins.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/analogin_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/analogin_device.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/analogout_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/analogout_device.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/can_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/except.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/flash_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/gpio_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/gpio_irq_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/gpio_irq_device.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/hal_tick_overrides.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/i2c_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/lp_ticker.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/mbed_board.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/mbed_crc_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/mbed_fault_handler.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/mbed_overrides.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/mbed_retarget.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/mbed_sdk_boot.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/mbed_tz_context.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/pinmap.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/port_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/pwmout_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/pwmout_device.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/qspi_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/rtc_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/serial_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/serial_device.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/sleep.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/spi_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/startup_stm32f429xx.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_adc.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_adc_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_can.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_can_legacy.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_cec.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_cortex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_crc.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_cryp.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_cryp_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dac.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dac_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dcmi.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dcmi_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dfsdm.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dma.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dma2d.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dma_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dsi.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_eth.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_flash.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_flash_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_flash_ramfunc.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_fmpi2c.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_fmpi2c_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_gpio.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_hash.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_hash_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_hcd.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_i2c.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_i2c_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_i2s.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_i2s_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_irda.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_iwdg.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_lptim.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_ltdc.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_ltdc_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_mmc.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_nand.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_nor.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_pccard.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_pcd.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_pcd_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_pwr.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_pwr_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_qspi.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_rcc.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_rcc_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_rng.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_rtc.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_rtc_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_sai.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_sai_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_sd.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_sdram.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_smartcard.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_spdifrx.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_spi.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_sram.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_tim.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_tim_ex.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_uart.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_usart.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_wwdg.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_adc.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_crc.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_dac.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_dma.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_dma2d.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_exti.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_fmc.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_fsmc.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_gpio.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_i2c.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_lptim.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_pwr.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_rcc.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_rng.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_rtc.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_sdmmc.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_spi.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_tim.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_usart.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_usb.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_utils.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/stm_spi_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/system_clock.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/system_init_pre.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/system_stm32f4xx.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/trng_api.o
SYS_OBJECTS += mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/us_ticker.o

INCLUDE_PATHS += -I.
INCLUDE_PATHS += -Iinc
#INCLUDE_PATHS += -I/usr/src/mbed-sdk
INCLUDE_PATHS += -IBSP_DISCO_F429ZI
INCLUDE_PATHS += -IBSP_DISCO_F429ZI/Drivers
INCLUDE_PATHS += -IBSP_DISCO_F429ZI/Drivers/BSP
INCLUDE_PATHS += -IBSP_DISCO_F429ZI/Drivers/BSP/Components
INCLUDE_PATHS += -IBSP_DISCO_F429ZI/Drivers/BSP/Components/Common
INCLUDE_PATHS += -IBSP_DISCO_F429ZI/Drivers/BSP/Components/ili9341
INCLUDE_PATHS += -IBSP_DISCO_F429ZI/Drivers/BSP/Components/l3gd20
INCLUDE_PATHS += -IBSP_DISCO_F429ZI/Drivers/BSP/Components/stmpe811
INCLUDE_PATHS += -IBSP_DISCO_F429ZI/Drivers/BSP/STM32F429I-Discovery
INCLUDE_PATHS += -IBSP_DISCO_F429ZI/Utilities
INCLUDE_PATHS += -IBSP_DISCO_F429ZI/Utilities/Fonts
INCLUDE_PATHS += -ILCD_DISCO_F429ZI
INCLUDE_PATHS += -ITS_DISCO_F429ZI
INCLUDE_PATHS += -Imbed
INCLUDE_PATHS += -Imbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM
INCLUDE_PATHS += -Imbed/drivers
INCLUDE_PATHS += -Imbed/hal
INCLUDE_PATHS += -Imbed/platform

LIBRARY_PATHS := -Lmbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM
LIBRARIES := -lmbed
LINKER_SCRIPT ?= mbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM/STM32F429xI.ld

# Objects and Paths
###############################################################################
# Tools and Flags

AS      = arm-none-eabi-gcc
CC      = arm-none-eabi-gcc
CPP     = arm-none-eabi-g++
LD      = arm-none-eabi-g++
ELF2BIN = arm-none-eabi-objcopy
PREPROC = arm-none-eabi-cpp -E -P -Wl,--gc-sections -Wl,--wrap,main -Wl,--wrap,_malloc_r -Wl,--wrap,_free_r -Wl,--wrap,_realloc_r -Wl,--wrap,_memalign_r -Wl,--wrap,_calloc_r -Wl,--wrap,exit -Wl,--wrap,atexit -Wl,-n -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -DMBED_ROM_START=0x8000000 -DMBED_ROM_SIZE=0x200000 -DMBED_RAM1_START=0x10000000 -DMBED_RAM1_SIZE=0x10000 -DMBED_RAM_START=0x20000000 -DMBED_RAM_SIZE=0x30000 -DMBED_BOOT_STACK_SIZE=4096 -DXIP_ENABLE=0


# C_FLAGS += -std=gnu11
# C_FLAGS += -include
# C_FLAGS += mbed_config.h
C_FLAGS += -DCOMPONENT_NSPE=1
C_FLAGS += -DDEVICE_ANALOGIN=1
C_FLAGS += -DTARGET_CORTEX_M
C_FLAGS += -D__CORTEX_M4
C_FLAGS += -DTOOLCHAIN_GCC_ARM
C_FLAGS += -DTRANSACTION_QUEUE_SIZE_SPI=2
C_FLAGS += -DTARGET_M4
C_FLAGS += -DDEVICE_PORTINOUT=1
C_FLAGS += -DDEVICE_SERIAL_ASYNCH=1
C_FLAGS += -DUSE_FULL_LL_DRIVER
C_FLAGS += -DDEVICE_STDIO_MESSAGES=1
C_FLAGS += -DDEVICE_PORTOUT=1
C_FLAGS += -DDEVICE_SPI=1
C_FLAGS += -DTARGET_CORTEX
C_FLAGS += -DDEVICE_LPTICKER=1
C_FLAGS += -DTARGET_STM
C_FLAGS += -DTARGET_STM32F429xI
C_FLAGS += -DDEVICE_SPI_ASYNCH=1
C_FLAGS += -DDEVICE_RESET_REASON=1
C_FLAGS += -DTARGET_LIKE_CORTEX_M4
C_FLAGS += -DTARGET_RTOS_M4_M7
C_FLAGS += -D__FPU_PRESENT=1
C_FLAGS += -DTARGET_STM32F4
C_FLAGS += -D__MBED__=1
C_FLAGS += -DDEVICE_RTC=1
C_FLAGS += -DTARGET_LIKE_MBED
C_FLAGS += -DDEVICE_TRNG=1
C_FLAGS += -DDEVICE_PORTIN=1
C_FLAGS += -DDEVICE_SERIAL=1
C_FLAGS += -DTARGET_NAME=DISCO_F429ZI
C_FLAGS += -DCOMPONENT_PSA_SRV_EMUL=1
C_FLAGS += -DDEVICE_I2C_ASYNCH=1
C_FLAGS += -DDEVICE_INTERRUPTIN=1
C_FLAGS += -DARM_MATH_CM4
C_FLAGS += -DDEVICE_CAN=1
C_FLAGS += -D__MBED_CMSIS_RTOS_CM
C_FLAGS += -DDEVICE_PWMOUT=1
C_FLAGS += -DTARGET_STM32F429xx
C_FLAGS += -DTARGET_STM32F429
C_FLAGS += -DDEVICE_MPU=1
C_FLAGS += -DCOMPONENT_PSA_SRV_IMPL=1
C_FLAGS += -DTOOLCHAIN_GCC
C_FLAGS += -D__CMSIS_RTOS
C_FLAGS += -DDEVICE_FLASH=1
C_FLAGS += -DDEVICE_SPISLAVE=1
C_FLAGS += -DDEVICE_SLEEP=1
C_FLAGS += -DDEVICE_I2CSLAVE=1
C_FLAGS += -DTARGET_DISCO_F429ZI
C_FLAGS += -DTARGET_FAMILY_STM32
C_FLAGS += -DDEVICE_WATCHDOG=1
C_FLAGS += -DUSE_HAL_DRIVER
C_FLAGS += -DDEVICE_I2C=1
C_FLAGS += -DTARGET_STM32F429ZI
C_FLAGS += -DDEVICE_ANALOGOUT=1
C_FLAGS += -DDEVICE_USTICKER=1
C_FLAGS += -DDEVICE_SERIAL_FC=1
C_FLAGS += -DTARGET_RELEASE
C_FLAGS += -DMBED_BUILD_TIMESTAMP=1584399854.9657936
C_FLAGS += -include
C_FLAGS += mbed_config.h
C_FLAGS += -std=gnu11
C_FLAGS += -c
C_FLAGS += -Wall
C_FLAGS += -Wextra
C_FLAGS += -Wno-unused-parameter
C_FLAGS += -Wno-missing-field-initializers
C_FLAGS += -fmessage-length=0
C_FLAGS += -fno-exceptions
C_FLAGS += -ffunction-sections
C_FLAGS += -fdata-sections
C_FLAGS += -funsigned-char
C_FLAGS += -MMD
C_FLAGS += -fno-delete-null-pointer-checks
C_FLAGS += -fomit-frame-pointer
C_FLAGS += -Os
C_FLAGS += -g
C_FLAGS += -DMBED_TRAP_ERRORS_ENABLED=1
C_FLAGS += -mcpu=cortex-m4
C_FLAGS += -mthumb
C_FLAGS += -mfpu=fpv4-sp-d16
C_FLAGS += -mfloat-abi=softfp
C_FLAGS += -DMBED_ROM_START=0x8000000
C_FLAGS += -DMBED_ROM_SIZE=0x200000
C_FLAGS += -DMBED_RAM1_START=0x10000000
C_FLAGS += -DMBED_RAM1_SIZE=0x10000
C_FLAGS += -DMBED_RAM_START=0x20000000
C_FLAGS += -DMBED_RAM_SIZE=0x30000

# CXX_FLAGS += -std=gnu++17
# CXX_FLAGS += -fno-rtti
# CXX_FLAGS += -Wvla
# CXX_FLAGS += -include
# CXX_FLAGS += mbed_config.h
CXX_FLAGS += -DCOMPONENT_NSPE=1
CXX_FLAGS += -DDEVICE_ANALOGIN=1
CXX_FLAGS += -DTARGET_CORTEX_M
CXX_FLAGS += -D__CORTEX_M4
CXX_FLAGS += -DTOOLCHAIN_GCC_ARM
CXX_FLAGS += -DTRANSACTION_QUEUE_SIZE_SPI=2
CXX_FLAGS += -DTARGET_M4
CXX_FLAGS += -DDEVICE_PORTINOUT=1
CXX_FLAGS += -DDEVICE_SERIAL_ASYNCH=1
CXX_FLAGS += -DUSE_FULL_LL_DRIVER
CXX_FLAGS += -DDEVICE_STDIO_MESSAGES=1
CXX_FLAGS += -DDEVICE_PORTOUT=1
CXX_FLAGS += -DDEVICE_SPI=1
CXX_FLAGS += -DTARGET_CORTEX
CXX_FLAGS += -DDEVICE_LPTICKER=1
CXX_FLAGS += -DTARGET_STM
CXX_FLAGS += -DTARGET_STM32F429xI
CXX_FLAGS += -DDEVICE_SPI_ASYNCH=1
CXX_FLAGS += -DDEVICE_RESET_REASON=1
CXX_FLAGS += -DTARGET_LIKE_CORTEX_M4
CXX_FLAGS += -DTARGET_RTOS_M4_M7
CXX_FLAGS += -D__FPU_PRESENT=1
CXX_FLAGS += -DTARGET_STM32F4
CXX_FLAGS += -D__MBED__=1
CXX_FLAGS += -DDEVICE_RTC=1
CXX_FLAGS += -DTARGET_LIKE_MBED
CXX_FLAGS += -DDEVICE_TRNG=1
CXX_FLAGS += -DDEVICE_PORTIN=1
CXX_FLAGS += -DDEVICE_SERIAL=1
CXX_FLAGS += -DTARGET_NAME=DISCO_F429ZI
CXX_FLAGS += -DCOMPONENT_PSA_SRV_EMUL=1
CXX_FLAGS += -DDEVICE_I2C_ASYNCH=1
CXX_FLAGS += -DDEVICE_INTERRUPTIN=1
CXX_FLAGS += -DARM_MATH_CM4
CXX_FLAGS += -DDEVICE_CAN=1
CXX_FLAGS += -D__MBED_CMSIS_RTOS_CM
CXX_FLAGS += -DDEVICE_PWMOUT=1
CXX_FLAGS += -DTARGET_STM32F429xx
CXX_FLAGS += -DTARGET_STM32F429
CXX_FLAGS += -DDEVICE_MPU=1
CXX_FLAGS += -DCOMPONENT_PSA_SRV_IMPL=1
CXX_FLAGS += -DTOOLCHAIN_GCC
CXX_FLAGS += -D__CMSIS_RTOS
CXX_FLAGS += -DDEVICE_FLASH=1
CXX_FLAGS += -DDEVICE_SPISLAVE=1
CXX_FLAGS += -DDEVICE_SLEEP=1
CXX_FLAGS += -DDEVICE_I2CSLAVE=1
CXX_FLAGS += -DTARGET_DISCO_F429ZI
CXX_FLAGS += -DTARGET_FAMILY_STM32
CXX_FLAGS += -DDEVICE_WATCHDOG=1
CXX_FLAGS += -DUSE_HAL_DRIVER
CXX_FLAGS += -DDEVICE_I2C=1
CXX_FLAGS += -DTARGET_STM32F429ZI
CXX_FLAGS += -DDEVICE_ANALOGOUT=1
CXX_FLAGS += -DDEVICE_USTICKER=1
CXX_FLAGS += -DDEVICE_SERIAL_FC=1
CXX_FLAGS += -DTARGET_RELEASE
CXX_FLAGS += -DMBED_BUILD_TIMESTAMP=1584399854.9657936
CXX_FLAGS += -include
CXX_FLAGS += mbed_config.h
CXX_FLAGS += -std=gnu++17
CXX_FLAGS += -fno-rtti
CXX_FLAGS += -Wvla
CXX_FLAGS += -c
CXX_FLAGS += -Wall
CXX_FLAGS += -Wextra
CXX_FLAGS += -Wno-unused-parameter
CXX_FLAGS += -Wno-missing-field-initializers
CXX_FLAGS += -Wno-register
CXX_FLAGS += -fmessage-length=0
CXX_FLAGS += -fno-exceptions
CXX_FLAGS += -ffunction-sections
CXX_FLAGS += -fdata-sections
CXX_FLAGS += -funsigned-char
CXX_FLAGS += -MMD
CXX_FLAGS += -fno-delete-null-pointer-checks
CXX_FLAGS += -fomit-frame-pointer
CXX_FLAGS += -Os
CXX_FLAGS += -g
CXX_FLAGS += -DMBED_TRAP_ERRORS_ENABLED=1
CXX_FLAGS += -mcpu=cortex-m4
CXX_FLAGS += -mthumb
CXX_FLAGS += -mfpu=fpv4-sp-d16
CXX_FLAGS += -mfloat-abi=softfp
CXX_FLAGS += -DMBED_ROM_START=0x8000000
CXX_FLAGS += -DMBED_ROM_SIZE=0x200000
CXX_FLAGS += -DMBED_RAM1_START=0x10000000
CXX_FLAGS += -DMBED_RAM1_SIZE=0x10000
CXX_FLAGS += -DMBED_RAM_START=0x20000000
CXX_FLAGS += -DMBED_RAM_SIZE=0x30000

ASM_FLAGS += -x
ASM_FLAGS += assembler-with-cpp
ASM_FLAGS += -DUSE_FULL_LL_DRIVER
ASM_FLAGS += -D__CORTEX_M4
ASM_FLAGS += -DUSE_HAL_DRIVER
ASM_FLAGS += -DTRANSACTION_QUEUE_SIZE_SPI=2
ASM_FLAGS += -DARM_MATH_CM4
ASM_FLAGS += -D__MBED_CMSIS_RTOS_CM
ASM_FLAGS += -D__FPU_PRESENT=1
ASM_FLAGS += -D__CMSIS_RTOS
#ASM_FLAGS += -I/usr/src/mbed-sdk
ASM_FLAGS += -IBSP_DISCO_F429ZI
ASM_FLAGS += -IBSP_DISCO_F429ZI/Drivers
ASM_FLAGS += -IBSP_DISCO_F429ZI/Drivers/BSP
ASM_FLAGS += -IBSP_DISCO_F429ZI/Drivers/BSP/Components
ASM_FLAGS += -IBSP_DISCO_F429ZI/Drivers/BSP/Components/Common
ASM_FLAGS += -IBSP_DISCO_F429ZI/Drivers/BSP/Components/ili9341
ASM_FLAGS += -IBSP_DISCO_F429ZI/Drivers/BSP/Components/l3gd20
ASM_FLAGS += -IBSP_DISCO_F429ZI/Drivers/BSP/Components/stmpe811
ASM_FLAGS += -IBSP_DISCO_F429ZI/Drivers/BSP/STM32F429I-Discovery
ASM_FLAGS += -IBSP_DISCO_F429ZI/Utilities
ASM_FLAGS += -IBSP_DISCO_F429ZI/Utilities/Fonts
ASM_FLAGS += -ILCD_DISCO_F429ZI
ASM_FLAGS += -ITS_DISCO_F429ZI
ASM_FLAGS += -Imbed
ASM_FLAGS += -Imbed/TARGET_DISCO_F429ZI/TOOLCHAIN_GCC_ARM
ASM_FLAGS += -Imbed/drivers
ASM_FLAGS += -Imbed/hal
ASM_FLAGS += -Imbed/platform
ASM_FLAGS += -include
#ASM_FLAGS += /filer/workspace_data/exports/0/03b50b28e9e17a55b496cbc8d49e1237/VM-Z/mbed_config.h
ASM_FLAGS += -x
ASM_FLAGS += assembler-with-cpp
ASM_FLAGS += -c
ASM_FLAGS += -Wall
ASM_FLAGS += -Wextra
ASM_FLAGS += -Wno-unused-parameter
ASM_FLAGS += -Wno-missing-field-initializers
ASM_FLAGS += -fmessage-length=0
ASM_FLAGS += -fno-exceptions
ASM_FLAGS += -ffunction-sections
ASM_FLAGS += -fdata-sections
ASM_FLAGS += -funsigned-char
ASM_FLAGS += -MMD
ASM_FLAGS += -fno-delete-null-pointer-checks
ASM_FLAGS += -fomit-frame-pointer
ASM_FLAGS += -Os
ASM_FLAGS += -g
ASM_FLAGS += -DMBED_TRAP_ERRORS_ENABLED=1
ASM_FLAGS += -mcpu=cortex-m4
ASM_FLAGS += -mthumb
ASM_FLAGS += -mfpu=fpv4-sp-d16
ASM_FLAGS += -mfloat-abi=softfp


#LD_FLAGS :=-Wl,--gc-sections -Wl,--wrap,main -Wl,--wrap,_malloc_r -Wl,--wrap,_free_r -Wl,--wrap,_realloc_r -Wl,--wrap,_memalign_r -Wl,--wrap,_calloc_r -Wl,--wrap,exit -Wl,--wrap,atexit -Wl,-n -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -DMBED_ROM_START=0x8000000 -DMBED_ROM_SIZE=0x200000 -DMBED_RAM1_START=0x10000000 -DMBED_RAM1_SIZE=0x10000 -DMBED_RAM_START=0x20000000 -DMBED_RAM_SIZE=0x30000 -DMBED_BOOT_STACK_SIZE=4096 -DXIP_ENABLE=0
LD_FLAGS :=-Wl,--gc-sections \
	-Wl,-Map,main.map \
	-Wl,-n \
	-mcpu=cortex-m4 \
	-mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp \
	-DMBED_ROM_START=0x8000000 \
	-DMBED_ROM_SIZE=0x200000 -DMBED_RAM1_START=0x10000000 -DMBED_RAM1_SIZE=0x10000 -DMBED_RAM_START=0x20000000 -DMBED_RAM_SIZE=0x30000 -DMBED_BOOT_STACK_SIZE=4096 -DXIP_ENABLE=0
LD_SYS_LIBS :=-specs=nosys.specs -Wl,--start-group -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys -lmbed -Wl,--end-group

# Tools and Flags
###############################################################################
# Rules

.PHONY: all lst size


all: $(BIN) $(HEX) size

flash: $(BIN) $(HEX) size
	cp $(BIN) $(TARGET_PATH)

$(OBJDIR)/%.o: %.S
	+@$(call MAKEDIR,$(dir $@))
	+@echo "Assemble: $(notdir $<)"
	@$(AS) -c $(ASM_FLAGS) -o $@ $<

$(OBJDIR)/%.o: %.s
	+@$(call MAKEDIR,$(dir $@))
	+@echo "Assemble: $(notdir $<)"
	@$(AS) -c $(ASM_FLAGS) -o $@ $<

$(OBJDIR)/%.o: %.c $(OBJDIR)/%.d
	+@$(call MAKEDIR,$(dir $@))
	+@echo "Compile: $(notdir $<)"
	@$(CC) $(C_FLAGS) $(INCLUDE_PATHS) -o $@ $<

$(OBJDIR)/%.o: %.cpp $(OBJDIR)/%.d
	+@$(call MAKEDIR,$(dir $@))
	+@echo "Compile: $(notdir $<)"
	@$(CPP) $(CXX_FLAGS) $(INCLUDE_PATHS) -o $@ $<

$(OBJDIR)/$(PROJECT).link_script.ld: $(LINKER_SCRIPT)
	@$(PREPROC) $< -o $@


$(ELF): $(OBJECTS) $(SYS_OBJECTS) $(OBJDIR)/$(PROJECT).link_script.ld
	+@echo "$(filter %.o, $^)" > $(OBJDIR)/.link_options.txt
	+@echo "link: $(notdir $@)"
	$(LD) $(LD_FLAGS) -T $(filter-out %.o, $^) $(LIBRARY_PATHS) --output $@ @$(OBJDIR)/.link_options.txt $(LIBRARIES) $(LD_SYS_LIBS)

$(BIN): $(ELF)
	$(ELF2BIN) -O binary $< $@
	+@echo "===== bin file ready to flash: $@ ====="

$(HEX): $(ELF)
	$(ELF2BIN) -O ihex $< $@


DEPS = $(OBJECTS:.o=.d) $(SYS_OBJECTS:.o=.d)
-include $(DEPS)

clean:
	$(call RM, $(OBJDIR))

%: ;

# $(RM) -rf $(OBJDIR)
