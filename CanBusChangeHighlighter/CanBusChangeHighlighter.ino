#include <SPI.h>
#include <mcp2515.h>
#include "Configuration.h"

MCP2515 mcp2515(MCP2515_CS_PIN);
bool interrupt = false;
struct can_frame frame;

void irqHandler() {
  interrupt = true;
}

void setup() {
  Serial.begin(SERIAL_SPEED);
  SPI.begin();

  mcp2515.reset();
  mcp2515.setConfigMode();
  mcp2515.setBitrate(CAN_BUS_SPEED, MCP_CLOCK);
  mcp2515.setListenOnlyMode();

  attachInterrupt(MCP2515_INTERRUPT_NUMBER, irqHandler, FALLING);
}

void loop() {
  if (interrupt) {
    interrupt = false;

    uint8_t irq = mcp2515.getInterrupts();

    if (irq & MCP2515::CANINTF_RX0IF) {
      if (mcp2515.readMessage(MCP2515::RXB0, &frame) == MCP2515::ERROR_OK) {
        serialWriteMessage(frame);
      }
    }

    if (irq & MCP2515::CANINTF_RX1IF) {
      if (mcp2515.readMessage(MCP2515::RXB1, &frame) == MCP2515::ERROR_OK) {
        serialWriteMessage(frame);
      }
    }
  }

}

void serialWriteMessage(can_frame frame) {
  // Write CANBus message
  // 4 bytes: ID
  // 1 byte: DLC
  // 3 bytes: padding
  // 8 bytes: data
  // -> 16 bytes
  Serial.write((byte*)&frame, sizeof(frame));
  Serial.flush();
}
