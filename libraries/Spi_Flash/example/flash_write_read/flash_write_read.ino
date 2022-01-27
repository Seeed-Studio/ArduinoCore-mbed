/*
  Spi Flash write read demo
  This demo is based on Seeed XIAO BLE.
  The spi flash chip is P25Q16H(https://www.puyasemi.com/uploadfiles/2018/08/20180807152503253.pdf)
*/

#include "QSPIFBlockDevice.h"

using namespace mbed;

QSPIFBlockDevice root(QSPI_FLASH1_IO0, QSPI_FLASH1_IO1, QSPI_FLASH1_IO2, QSPI_FLASH1_IO3, QSPI_FLASH1_SCK, QSPI_FLASH1_CSN, QSPIF_POLARITY_MODE_1, MBED_CONF_QSPIF_QSPI_FREQ);

void setup() {

  Serial.begin(115200);
  while (!Serial);
  
  Serial.println("init the spi flash...");
  int ret = root.init();
  if(ret) {
    Serial.print("init error. err code=");
    Serial.println(ret);
  }
  
  Serial.print("QSPIF BD size:");
  Serial.println(root.size());
  Serial.print("QSPIF read size:");
  Serial.println(root.get_read_size());
  Serial.print("QSPIF program size:");
  Serial.println(root.get_program_size());
  uint64_t sector_size_at_address_0 = root.get_erase_size(0);
  Serial.print("QSPIF erase size:");
  Serial.println(sector_size_at_address_0);

  // Init the buffer for write and read
  char *write_buffer = (char *) malloc(sector_size_at_address_0);
  char *read_buffer = (char *) malloc(sector_size_at_address_0);
  memset(write_buffer, 0x00, sector_size_at_address_0);
  memset(read_buffer, 0x00, sector_size_at_address_0);

  // Write the data to the spi flash
  sprintf(write_buffer, "Hello World!\n");
  Serial.println("writing data to spi flash...");
  root.erase(0, sector_size_at_address_0);
  root.program(write_buffer, 0, sector_size_at_address_0);

  // Read back what was stored
  Serial.println("Reading data from spi flash...");
  root.read(read_buffer, 0, sector_size_at_address_0);
  Serial.println(read_buffer);

  if(!memcmp(write_buffer, read_buffer, sector_size_at_address_0)){
    Serial.println("spi flash read write success");
  } else {
    Serial.println("spi flash read write failed");
  }

  root.deinit();
}

void loop() {

}
