<div id="readme" class="Box-body readme blob js-code-block-container">
 <article class="markdown-body entry-content p-3 p-md-6" itemprop="This needs to locked down and 'never' changed"><p><a href="https://www.microchip.com" rel="nofollow"><img src="images/MicrochipLogo.png" alt="MCHP" style="max-width:40%;"></a></p>

# PIC18F47Q10 GPIO Read/Write

The PIC18F47Q10 provides multiple PORT modules.
In this demo, a PORT pin is configured as input and connected to a button. Another pin is used as an output and connected to an LED. If the button is pressed, the LED will be turned on. If the button is released, the LED will be off.

## Related Documentation
- [PIC18F-Q10 Family Product Page](https://www.microchip.com/design-centers/8-bit/pic-mcus/device-selection/pic18f-q10-product-family)
- Technical Brief Link [(linkTBD)](http://www.microchip.com/)

## Software Used
- MPLAB® X IDE 5.30 or newer [(microchip.com/mplab/mplab-x-ide)](http://www.microchip.com/mplab/mplab-x-ide)
- MPLAB® XC8 2.10 or newer compiler [(microchip.com/mplab/compilers)](http://www.microchip.com/mplab/compilers)

## Hardware Used
- PIC18F47Q10 Curiosity Nano [(DM182029)](https://www.microchip.com/Developmenttools/ProductDetails/DM182029)

## Setup

The following configurations must be made for this project:

|Pin           | Configuration      |
| :----------: | :----------------: |
|RE2           | Digital Input      |
|RE0 (LED0)    | Output             |

## Operation
Run the code. While the button is pressed, the microcontroller will drive the output low, so the LED will be on. While the button is released, the LED will be turned off.

<img src="images/demo.gif" alt="Demo" width="500"/>

## Summary 
This project showcases how the General Purpose Input/Output pins on the PIC18-Q43 can be used as inputs and outputs in order to read an input value and drive the output high or low (to turn an LED on or off).
