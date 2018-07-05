//#include <Arduino.h>
#include <SPI.h>
#include <flashlib.h>
#include <test.h>

/* pin definition*/
#define pinSS 10 // Chip select for SPI
#define pinMOSI 11 // MOSI pin for SPI
#define pinMISO 12 // MISO pin for SPI
#define pinSCK 13 // SysClock pin for SPI
Test test;

long writeBuf2[1]; // test string
uint8_t writeBufs[144];
uint8_t lass[4];
uint8_t b;
char command[16];
//const char commandTable[10][10] ;
//commandTable[0] = "test_mem";

void readString() {
  int i = 0;

	char c = '0';
  while (c != '\r') {
    while(Serial.available() <= 0) {}
    command[i] = Serial.read();
    i++;           
  }
}

bool stringEqual(char * str1, char * str2, uint8_t len ) {
	int i = 0;
	while (*str2 != '\0') {
		if (str1[i] != str2[i]) {
			return 1;
		}
		
		str2++;
	}
	return 0;
}

void setup() {
    Serial.begin(9600);
    SPI.begin();
    pinMode(pinMOSI, OUTPUT);
    pinMode(pinMISO, INPUT);
    Serial.write("Enter a functionality: ");
    test.init();

}

void loop() {
  if(Serial.available() > 0) {
    switch (Serial.read()) {
      case '1':
        test.test_mem1();
        break;
      case '2':
        break;
      case '3':
        break;
    }
  }
    
    
  /*switch () {
    case 't':
    Serial.println("erasing flash");
    erase_block(0x000000, 512);
    delay(1000);
    Serial.println("prepairing random array");
    for (int i = 0; i < 28; i++) {
      for (int j = 0; j < 36; j++) {
        ltos(random(0xfffffff), j);
      }
      write_array(0x000090*i, writeBufs, 144);


    }

    for (int i = 1; i < 17; i++) {
      read_page(i, readBuf);
      print_page(readBuf);
    }
    break;

    case 'r':
      read_manu_id(&b);
    break;
    }
*/
}
