#ifndef __POISON_H__
#define __POISON_H__
#include "stm32f0xx.h"

#define TRUE 1
#define FALSE 0
#define GAS_TYPE_NUM 25
#define makeword(a,b) (a<<8) | b
#define Bit7  7
#define Bit6	6
#define Bit5  5


#define MAX_CMD_LEN   7
#define MAX_REC_LEN   7
//#define NO_OF_SENSOR  4
#define NO_OF_SENSOR  8

extern uint32_t sensor_type;
extern uint8_t ControlType;/*7->7Bit 6->6Bit 5->5Bit*/
//enum GAS_TYPE {    //old
//      CO=0x01, H2S, NH3, CO2, N02, 
//      NO, SO2, CL2, O2, H2, 
//      PH3, CH2O, O3, F2, HF, 
//      HCL, HBR, C2H4O, COCL2, SIH4, 
//      CLO2, SF6, TVOC, CH4
//};

enum GAS_TYPE {    
      CO=0x01, H2S, O2, Ex, N02, 
      NO, SO2, CL2, NH3, H2, 
      PH3, CH2O, O3, F2, HF, 
      HCL, HBR, C2H4O, COCL2, SIH4, 
      CLO2, CO2, SF6, TVOC, CH4
};

enum GAS_ADDRESS {
	CO_ADD=0x01, NH3_ADD, H2S_ADD, CO2_ADD, 
	TVOC_ADD, CL2_ADD, SO2_ADD, CH4_ADD
};   //add by yanly according to 8 sersor info

uint8_t ReadModel (uint8_t address, uint16_t *model);//
uint8_t ReadType (uint8_t address, uint8_t *model);
uint8_t ReadMeaRange (uint8_t address, uint16_t *range);
uint8_t ReadUint (uint8_t address, uint8_t *uint);
uint8_t ReadDecimal (uint8_t address, uint8_t *decimal);
uint8_t ReadMeaVal (uint8_t address, uint16_t *meaval);
uint8_t CalibraZero (uint8_t address);
uint8_t CalibraSpan (uint8_t address,uint16_t val);
uint8_t CalibraReset(uint8_t address,uint16_t val);
uint8_t ChangeAddr(uint8_t address,uint8_t target_addr);
//void CheckSensorType(uint32_t *sen_type);
void CheckSensorType(void);
void ReadAllVal(uint32_t sen_type,uint16_t *buff);
void ReadAllVal_V2(uint16_t *buff);
uint8_t get_addr_in_typearry(uint8_t type);
#endif
