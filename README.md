# Custom CPU fan driver

### *Arduino code*

TL;DR my fan driver didn't work so I made a *custom Arduino board* connected to my fan (through mosfet transistor) that
communicates with a *custom daemon* through USB UART to set the speed of the fan

This is the part for the Arduino Nano board (328p old bootloader) - to upload it:

```bash
git clone https://github.com/TheLastGimbus/cpu-fan-driver-arduino
cd cpu-fan-driver-arduino
pip install platformio
pio run --target upload
```

To update the speed, send it a single byte through UART, between 0-255 to set the speed %

If everything is ok, it will send back `1`, and `0` if it's not

The part for the daemon is in https://github.com/TheLastGimbus/cpu-fan-driver-python
