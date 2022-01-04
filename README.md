# macropunk2022 🙏
## ⌨️ An arduino project for effortless interaction with the computer 🖱️

This project was made to help people with RSI (Repetitive Strain Injury), use their computer without experiencing pain, and prevent further damage their hands. 

## Requirements
- 5x Infared Proximity Sensors
- 1 A500k pot (A linear potentiometer would work better, but the build and the code uses a logarithmic pot) (Please keep in mind that every potentiometer is different and might need fine tuning)
- Arduino Pro Micro (or any model that supports the Keyboard.h and Mouse.h libraries)

## Wiring
![fritzingdiagram](https://i.imgur.com/6eC7UHg.png)

## Build with arduino-cli

    arduino-cli compile --fqbn arduino:avr:leonardo MacroPunkLeo --clean

## Upload with arduino-cli

    arduino-cli upload --port /dev/cu.usbmodemHIDFG1 --fqbn arduino:avr:leonardo MacroPunkLeo

