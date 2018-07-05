#include <flashlib.h>
#include <test.h>
#include <Arduino.h>
#include <SPI.h>

void Test::init(void) {
}

void Test::ltos () {
	uint32_t data; 	
	for (int i = 0; i < PAYL_SIZE; i++){ 
    	data = random(0xfffffff);
		writeBufs[i*4] = (uint8_t)(data >> 24);
 		writeBufs[i*4 + 1] = (uint8_t)(data >> 16);
		writeBufs[i*4 + 2] = (uint8_t)(data >> 8);
		writeBufs[i*4 + 3] = (uint8_t)(data >> 0);
	}  
}
bool Test::cmp_arrays(uint8_t * arr1, uint8_t * arr2, int arrSize) {
	for(int i = 0; i < 144; i++ ) {
		if (arr1[i] != arr2[i]) {
			return false;
		}
	}
	//Serial.print("1 ");
	return true;
}
/*
void Test::arrInit() {
	for(int i = 0; i < 0x100; i++) {
		readBuf[i] = 0xff;
		writeBufs[i] = 0xff;
	}
}
*/
void Test::test_mem1 (void) {
	FLASH flash;
	bool test_flag = true;

	Serial.println("erasing flash");
	flash.erase_block(0x000000, 512);

	Serial.println("prepairing random array");
	for(int i = 0; i < 8; i++) {	
		//delay(1000);
		for (int j = 0; j < 455; j++) {
			ltos();

			flash.write_array((0x000090*j)+(0x010000*i), 144, writeBufs);
			flash.read_array((0x000090*j)+(0x010000*i), 144,readBuf);	

			if(!cmp_arrays(writeBufs, readBuf, 144)) 
				test_flag = false;
			}
  		
		
		Serial.print("Block #");
		Serial.print(i+1, DEC);
		Serial.println(" was written") ;
		if(test_flag == true) 
			Serial.println("Success!");
		else {
			Serial.println("Failure!");
			//for (int i = 1; i <= PAGES_IN_BLCK; i++) {
      			//flash.read_array(0x001000*45, 256, readBuf);
      			//flash.print_page(readBuf);
				//Serial.println(" ");
			//}
		}

		}
	}

  	
