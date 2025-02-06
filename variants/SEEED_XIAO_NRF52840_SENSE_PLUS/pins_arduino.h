#pragma once
#include <stdint.h>
#include <macros.h>

#ifndef __PINS_ARDUINO__
#define __PINS_ARDUINO__

#define ANALOG_CONFIG

/* Analog reference options 
 * Different possibilities available combining Reference and Gain
 */
enum _AnalogReferenceMode
{
  AR_VDD,         // 3.3 V
  AR_INTERNAL,    // 0.6 V
  AR_INTERNAL1V2, // 1.2 V
  AR_INTERNAL2V4  // 2.4 V
};

/* Analog acquisition time options */
enum _AnalogAcquisitionTime
{
  AT_3_US,         
  AT_5_US,    
  AT_10_US, // Default value
  AT_15_US,
  AT_20_US,  
  AT_40_US  
};

// Frequency of the board main oscillator
#define VARIANT_MAINOSC (32768ul)

// Master clock frequency
#define VARIANT_MCK     (64000000ul)

// Pins
// ----

// Number of pins defined in PinDescription array
#ifdef __cplusplus
extern "C" unsigned int PINCOUNT_fn();
#endif
#define PINS_COUNT           (PINCOUNT_fn())
#define NUM_DIGITAL_PINS     (33u)
#define NUM_ANALOG_INPUTS    (7u)
#define NUM_ANALOG_OUTPUTS   (0u)

extern PinName digitalPinToPinName(pin_size_t P);

// LEDs
// ----
#define PIN_LED     (12u)
#define LED_BUILTIN PIN_LED
#define LEDR        (12u)
#define LEDG        (13u)
#define LEDB        (14u)
#define LED_PWR     (12u)

// Analog pins
// -----------
#define PIN_A0 (0u)
#define PIN_A1 (1u)
#define PIN_A2 (2u)
#define PIN_A3 (3u)
#define PIN_A4 (4u)
#define PIN_A5 (5u)
#define PIN_VBAT (35u)
//#define PIN_A6 (6u)
//#define PIN_A7 (u)
static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
static const uint8_t A4  = PIN_A4;
static const uint8_t A5  = PIN_A5;
static const uint8_t ADC_BAT  = PIN_VBAT;
//static const uint8_t A6  = PIN_A6;
//static const uint8_t A7  = PIN_A7;
#define ADC_RESOLUTION 12

// Digital pins
// -----------
#define D0  (0u)
#define D1  (1u)
#define D2  (2u)
#define D3  (3u)
#define D4  (4u)
#define D5  (5u)
#define D6  (7u)
#define D7  (8u)
#define D8  (9u)
#define D9  (10u)
#define D10 (11u)


#define D11  (30u)
#define D12  (31u)
#define D13  (32u)
#define D14  (33u)
#define D15  (34u)
#define D16  (35u)
#define D17  (36u)
#define D18  (37u)
#define D19  (38u)

// Other pins
// ----------
#define PIN_VBAT_ENABLE (29u)

/*
 * Serial interfaces
 */
// Serial (EDBG)
#define PIN_SERIAL_RX (7ul)
#define PIN_SERIAL_TX (6ul)

#define PIN_SERIAL1_RX        (33u)
#define PIN_SERIAL1_TX        (34u)

//Needed for SD library
#define SDCARD_SPI    SPI
#define SDCARD_SS_PIN   PIN_SPI_SS
 
// SPI
#define PIN_SPI_MISO  (9u)
#define PIN_SPI_MOSI  (10u)
#define PIN_SPI_SCK   (8u)
#define PIN_SPI_SS    (2u)

static const uint8_t SS   = PIN_SPI_SS;   // SPI Slave SS not used. Set here only for reference.
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

#define PIN_SPI1_MISO           (37)
#define PIN_SPI1_MOSI           (36)
#define PIN_SPI1_SCK            (38)

static const uint8_t MOSI1 = PIN_SPI1_MOSI;
static const uint8_t MISO1 = PIN_SPI1_MISO;
static const uint8_t SCK1  = PIN_SPI1_SCK ;
// Wire
#define PIN_WIRE_SDA        (4u)
#define PIN_WIRE_SCL        (5u)

#define PIN_WIRE_SDA1       (16u)
#define PIN_WIRE_SCL1       (15u)

#define PIN_LSM6DS3TR_C_POWER (14u)
#define PIN_LSM6DS3TR_C_INT1  (17u)

//#define PIN_ENABLE_I2C_PULLUP      (32u)
//#define PIN_ENABLE_SENSORS_3V3     (33u)
//
//#define PIN_INT_APDS (26u)

// Other pins
#define PIN_NFC1                (33u)
#define PIN_NFC2                (34u)

// i2s Interfaces
#define PIN_I2S_SCK             (31)
#define PIN_I2S_SD              (30)
#define PIN_I2S_WS              (32)

static const uint8_t I2S_SCK = PIN_I2S_SCK;
static const uint8_t I2S_SD  = PIN_I2S_SD ;
static const uint8_t I2S_WS  = PIN_I2S_WS ;

// PDM Interfaces
// ---------------
#define PIN_PDM_PWR	 (18u)
#define PIN_PDM_CLK	 (19u)
#define PIN_PDM_DIN	 (20u)

// QSPI Pins
#define PIN_QSPI_SCK         (23u)
#define PIN_QSPI_CS          (24u)
#define PIN_QSPI_IO0         (25u)
#define PIN_QSPI_IO1         (26u)
#define PIN_QSPI_IO2         (27u)
#define PIN_QSPI_IO3         (28u)

// On-board QSPI Flash
#define EXTERNAL_FLASH_DEVICES   P25Q16H
#define EXTERNAL_FLASH_USE_QSPI

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1


// Mbed specific defines
#define SERIAL_HOWMANY		2
#define SERIAL1_TX			(digitalPinToPinName(PIN_SERIAL_TX))
#define SERIAL1_RX			(digitalPinToPinName(PIN_SERIAL_RX))
#define SERIAL2_TX			(digitalPinToPinName(PIN_SERIAL1_TX))
#define SERIAL2_RX			(digitalPinToPinName(PIN_SERIAL1_RX))

#define SERIAL_CDC			1
#define HAS_UNIQUE_ISERIAL_DESCRIPTOR
#define BOARD_VENDORID		0x2886
#define BOARD_PRODUCTID		0x8064
#define BOARD_NAME			"Seeed XIAO nRF52840 Plus"

#define DFU_MAGIC_SERIAL_ONLY_RESET   0x4E//0xb0

#define WIRE_HOWMANY		2

#define I2C_SDA				(digitalPinToPinName(PIN_WIRE_SDA))
#define I2C_SCL				(digitalPinToPinName(PIN_WIRE_SCL))
#define I2C_SDA1			(digitalPinToPinName(PIN_WIRE_SDA1))
#define I2C_SCL1			(digitalPinToPinName(PIN_WIRE_SCL1))

#define SPI_HOWMANY			2

#define SPI_MISO			(digitalPinToPinName(PIN_SPI_MISO))
#define SPI_MOSI			(digitalPinToPinName(PIN_SPI_MOSI))
#define SPI_SCK				(digitalPinToPinName(PIN_SPI_SCK))

#define SPI_MISO1			(digitalPinToPinName(PIN_SPI1_MISO))
#define SPI_MOSI1			(digitalPinToPinName(PIN_SPI1_MOSI))
#define SPI_SCK1				(digitalPinToPinName(PIN_SPI1_SCK))

#define digitalPinToPort(P)		(digitalPinToPinName(P)/32)

uint8_t getUniqueSerialNumber(uint8_t* name);
void _ontouch1200bps_();

#endif //__PINS_ARDUINO__
