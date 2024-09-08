# 8-Channel NRF24L01 Wireless Control System

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

### Receiver Pinout

| **Component**            | **Function**           | **Pin**           | **Notes**                          |
|--------------------------|------------------------|-------------------|------------------------------------|
| **nRF24L01 Module**       | CE (Chip Enable)       | Pin 9             | SPI communication                 |
|                          | CSN (Chip Select Not)  | Pin 10            | SPI communication                 |
|                          | SCK (Clock)            | Hardware SPI (13) | SPI communication                 |
|                          | MISO (Data Out)        | Hardware SPI (12) | SPI communication                 |
|                          | MOSI (Data In)         | Hardware SPI (11) | SPI communication                 |
| **Servo Motors**          | Channel 1 (Servo 1)    | Pin 3             | Controls Servo 1                  |
|                          | Channel 2 (Servo 2)    | Pin 4             | Controls Servo 2                  |
|                          | Channel 3 (Servo 3)    | Pin 5             | Controls Servo 3                  |
|                          | Channel 4 (Servo 4)    | Pin 6             | Controls Servo 4                  |
|                          | Channel 5 (Servo 5)    | Pin 7             | Controls Servo 5                  |
|                          | Channel 6 (Servo 6)    | Pin 8             | Controls Servo 6                  |
|                          | Channel 7 (Servo 7)    | Pin 9             | Controls Servo 7                  |
|                          | Channel 8 (Servo 8)    | Pin 10            | Controls Servo 8                  |

### Transmitter Pinout

| **Component**            | **Function**           | **Pin**           | **Notes**                           |
|--------------------------|------------------------|-------------------|-------------------------------------|
| **nRF24L01 Module**       | CE (Chip Enable)       | Pin 9             | SPI communication                  |
|                          | CSN (Chip Select Not)  | Pin 10            | SPI communication                  |
|                          | SCK (Clock)            | Hardware SPI (13) | SPI communication                  |
|                          | MISO (Data Out)        | Hardware SPI (12) | SPI communication                  |
|                          | MOSI (Data In)         | Hardware SPI (11) | SPI communication                  |
| **Joysticks (Analog Input)** | Throttle              | Pin A0            | Analog input for throttle           |
|                          | Yaw                    | Pin A1            | Analog input for yaw                |
|                          | Pitch                  | Pin A2            | Analog input for pitch              |
|                          | Roll                   | Pin A3            | Analog input for roll               |

---

## Circuit Schematic

You can wire the **NRF24L01 module** to the Arduino using the following connections:

| **NRF24L01 Pin** | **Arduino Pin** |
|------------------|-----------------|
| VCC              | 3.3V            |
| GND              | GND             |
| CE               | 9               |
| CSN              | 10              |
| SCK              | 13              |
| MOSI             | 11              |
| MISO             | 12              |

For servos, connect each signal wire (usually yellow or orange) to the appropriate pin defined in the code and provide the servos with 5V power.

---

## Installation

### 1. Clone the Repository

Open a terminal and run:

```bash
git clone https://github.com/yourusername/8-channel-nrf24l01-receiver.git
