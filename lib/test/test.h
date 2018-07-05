#ifndef TEST_H
#define TEST_H
#include <stdint.h>

#define PAYL_SIZE 36
#define PAYL_IN_BLCK 28
#define PAGES_IN_BLCK 16
#define BLCK_IN_MEM 128

class Test {  
  private:
    uint8_t writeBufs[144];
    void ltos(void);
	bool cmp_arrays(uint8_t * arr1, uint8_t * arr2, int arrSize);
  public:
    uint8_t readBuf[144];
	void arrInit(void);
    void init(void);
    void test_mem1(void);
};

#endif
