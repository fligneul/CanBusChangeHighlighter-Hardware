#ifndef _CAN_BUS_CHANGE_HIGHLIGHTER_CONFIG_H_
#define _CAN_BUS_CHANGE_HIGHLIGHTER_CONFIG_H_

#include <mcp2515.h>

#define SERIAL_SPEED 115200
#define MCP2515_CS_PIN 10
#define MCP2515_INTERRUPT_NUMBER 0

#define CAN_BUS_SPEED CAN_SPEED::CAN_50KBPS
#define MCP_CLOCK CAN_CLOCK::MCP_8MHZ

#endif
