# 8-Channel Radio Control using Arduino and NRF24L01

This project is an **8-channel remote control system** using Arduino, **NRF24L01** wireless modules, and servo motors. It allows wireless communication between a transmitter and receiver, which can control up to 8 different servos or electronic speed controllers (ESCs). The system is ideal for RC vehicles, drones, robots, or any multi-channel control system.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Pinout](#pinout)
  - [Receiver Pinout](#receiver-pinout)
  - [Transmitter Pinout](#transmitter-pinout)
- [Circuit Schematic](#circuit-schematic)
- [Installation](#installation)
- [How to Use](#how-to-use)
  - [Receiver Setup](#receiver-setup)
  - [Transmitter Setup](#transmitter-setup)
- [Code Breakdown](#code-breakdown)
  - [Receiver Code](#receiver-code)
  - [Transmitter Code](#transmitter-code)
- [Troubleshooting](#troubleshooting)
- [Additional Information](#additional-information)
- [License](#license)

---

## Overview

This project enables you to control up to 8 channels wirelessly using the **NRF24L01** module, which offers stable and long-range communication. It's perfect for projects like drones, RC cars, or robots that require multi-channel wireless control.

---

## Features

- **Wireless communication** using NRF24L01 at a stable 2.4 GHz frequency.
- **8-channel control** for servos, ESCs, or other devices.
- Adjustable data rate for stable communication.
- Supports **joystick input** for intuitive control.
- Modular code for easy expansion and customization.

---

## Hardware Requirements

### Required Components
1. **2x Arduino Boards** (One for the transmitter and one for the receiver)
2. **2x NRF24L01 Modules**
3. **Servos or ESCs** (up to 8 channels)
4. **Joystick Module** (for the transmitter)
5. **Power Supply** (appropriate for servos or ESCs)
6. **Jumper Wires and Breadboard**

---

## Software Requirements

- **Arduino IDE** (latest version)
- **RF24 Library** (for NRF24L01 communication)
- **Servo Library** (for controlling servo motors)

### Installing Libraries

1. Open the Arduino IDE.
2. Go to **Sketch > Include Library > Manage Libraries**.
3. Search for "RF24" and install it.
4. The Servo library is built-in, so no need to install it separately.

---

## Pinout

## NRF24L01 Arduino Pinout for Transmitter (TX) and Receiver (RX)

### Transmitter (TX) NRF24L01 to Arduino Nano Pinout

| **NRF24L01 Pin**        | **Arduino Nano Pin** | **Description**                   |
|-------------------------|----------------------|------------------------------------|
| GND                     | GND                  | Ground                            |
| VCC                     | +5V                  | Power Supply (5V)                 |
| CE                      | D9                   | Chip Enable                       |
| CSN                     | D10                  | Chip Select Not                   |
| SCK                     | D13                  | Serial Clock (SPI)                |
| MOSI                    | D11                  | Master Out Slave In (SPI)         |
| MISO                    | D12                  | Master In Slave Out (SPI)         |

### Receiver (RX) NRF24L01 to Arduino Nano Pinout

| **NRF24L01 Pin**        | **Arduino Nano Pin** | **Description**                   |
|-------------------------|----------------------|------------------------------------|
| GND                     | GND                  | Ground                            |
| VCC                     | +5V                  | Power Supply (5V)                 |
| CE                      | D9                   | Chip Enable                       |
| CSN                     | D10                  | Chip Select Not                   |
| SCK                     | D13                  | Serial Clock (SPI)                |
| MOSI                    | D11                  | Master Out Slave In (SPI)         |
| MISO                    | D12                  | Master In Slave Out (SPI)         |

### Additional Connections (Common to TX and RX)

| **Other Component**      | **Arduino Nano Pin** | **Description**                   |
|--------------------------|----------------------|------------------------------------|
| 10uF Capacitor            | Between VCC and GND  | Stabilizes voltage for NRF24L01    |
| CH1 to CH8 (RX Only)      | D0 to D7             | Servo Channels 1 to 8             |
| Power Input (for Servo)   | External 5V-6V       | Power input for the servos         |
| VCC (Arduino)             | VCC                  | 7V-9V Power Input                 |
| GND (Arduino)             | GND                  | Ground                            |

### Schematics

#### Transmitter (TX)
![Transmitter Schematic](https://github.com/40pet/40pet/blob/main/TX.jpg)

#### Receiver (RX)
![Receiver Schematic](https://github.com/40pet/40pet/blob/main/RX%20(1).jpg)


For servos, connect each signal wire (usually yellow or orange) to the appropriate pin defined in the code and provide the servos with 5V power.

---

## Installation

### 1. Clone the Repository

Open a terminal and run:

```bash
git clone https://github.com/40pet/Radio-Control-using-Arduino-and-NRF.git
