![Hexiwear](https://i.ytimg.com/vi/ouVRboD-2Ds/maxresdefault.jpg)

---

Hexiwear is a complete IoT development solution. It has an optimized hardware 
design and it is compatible with more than 250 plug-and-play boards, so you can 
easily adjust it to your needs. Built your prototypes, and add different click 
boards until you get the perfect device, suited just for you. 

Hexiwear could be your smartwatch or a remote sensor or maybe a remote control 
for the smart devices in your home. The possibilities are endless. 
Since it is wearable, small, sleek and has a low power consumption you can take 
it anywhere with you. From a business meeting to your morning jog in the park.
Hexiwear is compatible with iOS/Android applications, connects to the cloud and 
has BLE (Bluetooth Low Energy) — you can connect you a device near you or cloud 
servers. You can download iOS and Android apps for free on Google Play.

Visit the official [Hexiwear website](http://www.hexiwear.com/) to learn more 
about it. The “Getting Started” video is an excellent place to start. 

## NESL Modification to the Software
To facilitate the process of students starting a project, a more general message
passing mechanism over BLE is proposed. In short, a new `Message` service has
been added to HEXIWEAR. To implement this new service, changes have been made
to the BLE firmware of HEXIWEAR and also the Mbed driver at the Application
Processor side.

 
## How to setup the toolchain
### BLE Chip Toolchain
Just follow this guide by HEXIWEAR official: https://github.com/nesl/HEXIWEAR/blob/master/documentation/HEXIWEAR%20Setting%20Up%20Toolchain%20for%20KW40.pdf

The modified version of firmware is kept within this repo.

### AP Mbed Toolchain
Follow the official Mbed CLI tutorial and import the KW40z driver. Then replace
the files with the those inside this repo.

