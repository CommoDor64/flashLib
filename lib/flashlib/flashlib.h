#ifndef FLASHLIB_H
#define FLASHLIB_H
#include <stdint.h>



/* */
class FLASH {
private:
	/* pin definition*/
	#define pinSS 10 // Chip select for SPI
	#define pinMOSI 11 // MOSI pin for SPI
	#define pinMISO 12 // MISO pin for SPI
	#define pinSCK 13 // SysClock pin for SPI

/* fixes sized in memory*/
	#define PAGES 2048
	#define BYTES 65536
	#define MEM_BLOCKS 7
/*Casting between variable sizes*/
	#define BITSHIFT_HIGH 16
	#define BITSHIFT_MID 8
	#define BITSHIFT_LOW 0

/* OPCODES for flash memory */
	const uint8_t READ_BYTE_FLASH = 0x03;
	const uint8_t WRITE_ENABLE = 0x06;
	const uint8_t WRITE_BYTE_FLASH = 0x02;
	const uint8_t BLOCK_ERASE_8 = 0x20;
	const uint8_t BLOCK_ERASE_32 = 0x52;
	const uint8_t BLOCK_ERASE_64 = 0xD8;
	const uint8_t CHIP_ERASE = 0xC7;
	const uint8_t DEEP_POWERDOWN = 0xB9;
	const uint8_t RESUME_FROM_POWERDOWN = 0xAB;
	const uint8_t READ_MANU_ID = 0x9F;
	const uint8_t STATUS_REG_1 = 0x05;
/* Private functions*/
	void _busy(void);
	void _write_byte (uint32_t addr, uint8_t w1);

public:
/* functions declaration*/
    void read_manu_id (uint8_t * manu_info);
	void deep_powerdown_on (void);
	void deep_powerdown_off (void);
	void read_array (uint32_t page, int bytesNum,uint8_t * readBuf);
	void write_array (uint32_t addr, int bytesNum,uint8_t * w1);
	uint8_t erase_block (uint32_t addr, uint16_t blocksize);
	void print_page (uint8_t * buf);
	void _read_byte (uint32_t addr, uint8_t * b1);

};

#endif
