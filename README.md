# CanBusChangeHighlighter-Hardware

Arduino &amp; MCP2515 Hardware for the CanBusChangeHighlighter.

## Overview

This project is based on the [arduino-mcp2515](https://github.com/autowp/arduino-mcp2515) librairy from [autowp](https://github.com/autowp).
CAN bus message are received using interrupt based read and write message to Serial port in byte format with a '**\n**' new line separator. Those data must be processed in [CanBusChangeHighlighter-GUI](https://github.com/fligneul/CanBusChangeHighlighter-GUI).

In order to prevent any emission of unwanted message on the bus, the module is set to **listen only** mode

## Hardware

The project's hardware is based on a MCP2515 can module (available on Aliexpress for few bucks).

![Wiring diagram](https://github.com/autowp/arduino-mcp2515/raw/master/examples/wiring.png "Wiring diagram")

## Configuration

Edit the Configuration.h for your specific needs.

* SERIAL_SPEED : Arduino serial speed (value over 115200 is recommended for processing fast speed CAN bus)
* MCP2515_CS_PIN : CAN bus module CS pin for SPI communication
* MCP2515_INTERRUPT_PIN : CAN bus module interruption pin
* CAN_BUS_SPEED : Baudrate of the CAN bus (see available values [here](https://github.com/autowp/arduino-mcp2515#initialization))
* MCP_CLOCK : oscillator frequency of the MCP2515 module (see value of the module oscillator)
