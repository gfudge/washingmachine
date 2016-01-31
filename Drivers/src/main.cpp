/**
  ******************************************************************************
  * @file    main.cpp
  * @author  DJM
  * @version 0.1
  * @date    18 Sep 2014
  * @brief   Example C code for the washing machine
  ******************************************************************************
  */


#include "main.h"
#include "BuzzerController.h"

extern "C" {  // this is needed to make C++ and C work together
  #include "board_startup.h"   // you DON'T need to worry about the contents of this file
}

using namespace WashingMachine;

/* 
  washing machine outputs
  -----------------------
  PC6  Buzzer		
  PD8  7 segment display bit A
  PD10 7 segment display bit C
  PD11 7 segment display bit B
  PD12 motor control	
  PD13 7 segment display bit D
  PD14 reset switches
  PD15 motor direction

  washing machine inputs
  ----------------------
  PE8  programme select 1
  PE9  programme select 2
  PE10 programme select 3
  PE11 door open/close
  PE12 accept switch
  PE15 motor speed feedback
*/

// port base addresses
#define GPIO_C_BASE_ADDR  0x40000000 + 0x08000000 + 0x00000800
#define GPIO_D_BASE_ADDR  0x40000000 + 0x08000000 + 0x00000C00
#define GPIO_E_BASE_ADDR  0x40000000 + 0x08000000 + 0x00001000

// port register addresses
#define GPIO_C_MODE  (GPIO_C_BASE_ADDR)
#define GPIO_C_SPEED (GPIO_C_BASE_ADDR + 0x08)
#define GPIO_C_PULL  (GPIO_C_BASE_ADDR + 0x0C)
#define GPIO_C_IDR   (GPIO_C_BASE_ADDR + 0x10)
#define GPIO_C_ODR   (GPIO_C_BASE_ADDR + 0x14)

#define GPIO_D_MODE  (GPIO_D_BASE_ADDR)
#define GPIO_D_SPEED (GPIO_D_BASE_ADDR + 0x08)
#define GPIO_D_PULL  (GPIO_D_BASE_ADDR + 0x0C)
#define GPIO_D_IDR   (GPIO_D_BASE_ADDR + 0x10)
#define GPIO_D_ODR   (GPIO_D_BASE_ADDR + 0x14)

#define GPIO_E_MODE  (GPIO_E_BASE_ADDR)
#define GPIO_E_SPEED (GPIO_E_BASE_ADDR + 0x08)
#define GPIO_E_PULL  (GPIO_E_BASE_ADDR + 0x0C)
#define GPIO_E_IDR   (GPIO_E_BASE_ADDR + 0x10)
#define GPIO_E_ODR   (GPIO_E_BASE_ADDR + 0x14)

// pointers to port registers
uint32_t *GPIO_C_Mode_Addr  = (uint32_t *) GPIO_C_MODE;
uint32_t *GPIO_C_Speed_Addr = (uint32_t *) GPIO_C_SPEED;
uint32_t *GPIO_C_Pull_Addr  = (uint32_t *) GPIO_C_PULL;
uint16_t *GPIO_C_Idr_Addr   = (uint16_t *) GPIO_C_IDR;
uint16_t *GPIO_C_Odr_Addr   = (uint16_t *) GPIO_C_ODR;

uint32_t *GPIO_D_Mode_Addr  = (uint32_t *) GPIO_D_MODE;
uint32_t *GPIO_D_Speed_Addr = (uint32_t *) GPIO_D_SPEED;
uint32_t *GPIO_D_Pull_Addr  = (uint32_t *) GPIO_D_PULL;
uint16_t *GPIO_D_Idr_Addr   = (uint16_t *) GPIO_D_IDR;
uint16_t *GPIO_D_Odr_Addr   = (uint16_t *) GPIO_D_ODR;

uint32_t *GPIO_E_Mode_Addr  = (uint32_t *) GPIO_E_MODE;
uint32_t *GPIO_E_Speed_Addr = (uint32_t *) GPIO_E_SPEED;
uint32_t *GPIO_E_Pull_Addr  = (uint32_t *) GPIO_E_PULL;
uint16_t *GPIO_E_Idr_Addr   = (uint16_t *) GPIO_E_IDR;
uint16_t *GPIO_E_Odr_Addr   = (uint16_t *) GPIO_E_ODR;

// port C - set to output
uint32_t GPIO_C_Mode = 0x55555555;  // 0b01010101010101010101010101010101  00 = input, 01 = output
uint32_t GPIO_C_Speed = 0xFFFFFFFF; // 0b11111111111111111111111111111111  11 - high speed output only
uint32_t GPIO_C_Pull = 0xaaaaaaaa;  // 0b10101010101010101010101010101010  00 none, 01 = pull up, 10 pull down

// port D - set to output
uint32_t GPIO_D_Mode = 0x55555555;  // 0b01010101010101010101010101010101  00 = input, 01 = output
uint32_t GPIO_D_Speed = 0xFFFFFFFF; // 0b11111111111111111111111111111111  11 - high speed output only
uint32_t GPIO_D_Pull = 0xaaaaaaaa;  // 0b10101010101010101010101010101010  00 none, 01 = pull up, 10 pull down

// port E - set to input
uint32_t GPIO_E_Mode = 0x00000000;  // 0b00000000000000000000000000000000  00 = input, 01 = output
uint32_t GPIO_E_Pull = 0x55555555;    // 0b10101010101010101010101010101010  00 none, 01 = pull up, 10 pull down

// all the washing machine test code is in here
int main(void)
{
	board_startup();
	
	// configure port C
  *GPIO_C_Mode_Addr =  (uint32_t) GPIO_C_Mode;
  *GPIO_C_Speed_Addr = (uint32_t) GPIO_C_Speed;
  *GPIO_C_Pull_Addr =  (uint32_t) GPIO_C_Pull;

  // configure port D
  *GPIO_D_Mode_Addr =  (uint32_t) GPIO_D_Mode;
  *GPIO_D_Speed_Addr = (uint32_t) GPIO_D_Speed;
  *GPIO_D_Pull_Addr =  (uint32_t) GPIO_D_Pull;

  // configure port E
  *GPIO_E_Mode_Addr =  (uint32_t) GPIO_E_Mode;
  *GPIO_E_Pull_Addr =  (uint32_t) GPIO_E_Pull;


	BuzzerController buzzer_controller;
	
	// Test the buzzer
	buzzer_controller.on();
	HAL_Delay(1000);
	buzzer_controller.off();
	HAL_Delay(1000);
	
	while (1)	HAL_Delay(100);
	return 0;
}

int dave_test() 
{
  // STM32F3 Discovery Board initialization
  board_startup();

  // configure port C
  *GPIO_C_Mode_Addr =  (uint32_t) GPIO_C_Mode;
  *GPIO_C_Speed_Addr = (uint32_t) GPIO_C_Speed;
  *GPIO_C_Pull_Addr =  (uint32_t) GPIO_C_Pull;

  // configure port D
  *GPIO_D_Mode_Addr =  (uint32_t) GPIO_D_Mode;
  *GPIO_D_Speed_Addr = (uint32_t) GPIO_D_Speed;
  *GPIO_D_Pull_Addr =  (uint32_t) GPIO_D_Pull;

  // configure port E
  *GPIO_E_Mode_Addr =  (uint32_t) GPIO_E_Mode;
  *GPIO_E_Pull_Addr =  (uint32_t) GPIO_E_Pull;

  // hold a bit value returned from a port
  bool port;
	
  // try out each washing machine device in turn
  *GPIO_C_Odr_Addr ^= (uint16_t) 0x0040;   // toggle PC6 buzzer
  HAL_Delay(100); // 100ms delay
  *GPIO_D_Odr_Addr |= (uint16_t) 0x1000;   // PD12 motor control - on
  HAL_Delay(100); // 100ms delay		
  *GPIO_D_Odr_Addr &= ~(uint16_t) 0x8000;  // PD15 motor direction - clockwise
  HAL_Delay(1900); // 100ms delay		
  *GPIO_D_Odr_Addr |= (uint16_t) 0x8000;   // PD15 motor direction - anticlockwise
  HAL_Delay(1000); // 100ms delay
  *GPIO_D_Odr_Addr &= ~(uint16_t) 0x1000;  // PD12 motor control - off 
  HAL_Delay(100); // 100ms delay	
		
  *GPIO_D_Odr_Addr &= ~(uint16_t) 0x2D00;  // turn off all 7 segments of display (display 0)
  HAL_Delay(100); // 100ms delay
  *GPIO_D_Odr_Addr |= (uint16_t) 0x2000;   // turn on bit D MSB
  HAL_Delay(100); // 100ms delay		
  *GPIO_D_Odr_Addr |= (uint16_t) 0x0400;   // turn on bit C	
  HAL_Delay(100); // 100ms delay
  *GPIO_D_Odr_Addr |= (uint16_t) 0x0800;   // turn on bit B
  HAL_Delay(100); // 100ms delay		
  *GPIO_D_Odr_Addr |= (uint16_t) 0x0100;   // turn on bit A LSB (all outputs 1 - display blank)
  HAL_Delay(100); // 100ms delay
  *GPIO_D_Odr_Addr &= ~(uint16_t) 0x2D00;  // turn off all 7 segments of display  (display 0)
  HAL_Delay(100); // 100ms delay
		
  *GPIO_D_Odr_Addr |= (uint16_t) 0x4000;  // PD14 HIGH accept switch input
  HAL_Delay(100); // 100ms delay
  port = (*GPIO_E_Idr_Addr) & 0x0100 ;  // PE8  programme select 1 (rightmost)
  if (port) *GPIO_D_Odr_Addr |= (uint16_t) 0x0100; else *GPIO_D_Odr_Addr &= ~(uint16_t) 0x2D00;
  HAL_Delay(100); // 100ms delay
  port = (*GPIO_E_Idr_Addr) & 0x0200 ;  // PE9  programme select 2 (middle)
  if (port) *GPIO_D_Odr_Addr |= (uint16_t) 0x0100; else *GPIO_D_Odr_Addr &= ~(uint16_t) 0x2D00;
  HAL_Delay(100); // 100ms delay
  port = (*GPIO_E_Idr_Addr) & 0x0400 ;  // PE10 programme select 3 (leftmost)
  if (port) *GPIO_D_Odr_Addr |= (uint16_t) 0x0100; else *GPIO_D_Odr_Addr &= ~(uint16_t) 0x2D00;
  HAL_Delay(100); // 100ms delay
  port = (*GPIO_E_Idr_Addr) & 0x0800 ;  // PE11 door open/close	
  if (port) *GPIO_D_Odr_Addr |= (uint16_t) 0x0100; else *GPIO_D_Odr_Addr &= ~(uint16_t) 0x2D00;
  HAL_Delay(100); // 100ms delay
  port = (*GPIO_E_Idr_Addr) & 0x1000 ;  // PE12 accept switch		
  if (port) *GPIO_D_Odr_Addr |= (uint16_t) 0x0100; else *GPIO_D_Odr_Addr &= ~(uint16_t) 0x2D00;
  HAL_Delay(100); // 100ms delay
  port = (*GPIO_E_Idr_Addr) & 0x2000 ;  // PE13 cancel switch			
  if (port) *GPIO_D_Odr_Addr |= (uint16_t) 0x0100; else *GPIO_D_Odr_Addr &= ~(uint16_t) 0x2D00;
  HAL_Delay(100); // 100ms delay	
  port = (*GPIO_E_Idr_Addr) & 0x8000 ;  // PE15 motor speed feedback	
  HAL_Delay(100); // 100ms delay	
  *GPIO_D_Odr_Addr &= ~(uint16_t) 0x4000;  // PD14 LOW reset switches
  HAL_Delay(100); // 100ms delay

  // Only run the motor if the door is closed
  *GPIO_D_Odr_Addr &= ~(uint16_t) 0x8000;  // PD15 motor direction - set to clockwise
  while(1) {
    port = (*GPIO_E_Idr_Addr) & 0x0800 ;  // PE11 check if door open or closed	
    if (port) {
      *GPIO_D_Odr_Addr |= (uint16_t) 0x1000;  // PD12 motor control - off 
    }
    else {
      *GPIO_D_Odr_Addr &= ~(uint16_t) 0x1000;  // PD12 motor control - off 
    }
  }
}


