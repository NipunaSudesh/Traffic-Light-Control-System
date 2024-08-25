# Traffic Light Control System using Arduino

## Project Overview

This project simulates a traffic light control system for a road with pedestrian and vehicle paths. Pedestrians can safely cross when they press a push button, which triggers a sequence of light changes to stop vehicles and allow safe crossing.

## Components Used
- Arduino Uno
- LEDs (2 Green, 2 Red, 1 Yellow)
- Push Button
- Resistors (220Ω)
- Breadboard
- Jumper Wires

## Circuit Setup
1. **Vehicle Path:**
   - Green LED (Pin 2)
   - Yellow LED (Pin 3)
   - Red LED (Pin 4)

2. **Pedestrian Path:**
   - Green LED (Pin 5)
   - Red LED (Pin 6)

3. **Push Button:**
   - Connected to Pin 7 (configured with a pull-down resistor).

## Functionality
- The vehicle path is initially green while the pedestrian path is red.
- When the push button is pressed:
  - The vehicle light changes from green to yellow (blinks for 3 seconds) and then red.
  - After 6 seconds, the pedestrian light turns green, allowing pedestrians to cross.
- The system resets after the pedestrian crossing is complete.

## Arduino Code
Refer to the code in `traffic_light_control.ino` for the full implementation.

## How to Use
1. Build the circuit as described.
2. Upload the provided Arduino code to your Arduino Uno.
3. Press the button to observe the traffic light sequence.

