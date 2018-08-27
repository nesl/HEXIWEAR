# NESL HEXIWEAR KW40Z Mbed Driver

This driver is a modified version of the original KW40Z driver at https://os.mbed.com/teams/Hexiwear/code/Hexi_KW40Z/ to support the new Message BLE service. You can either develop remotely with the mbed online IDE or locally with mbed CLI. I would recommend you develop with mbed CLI to avoid repeatly downloading the binary.

## Develop with Mbed CLI

Mbed CLI is mbed's offline development toolchain. Mbed has a detailed doc to help you start. Check out the tutorials at https://os.mbed.com/docs/v5.9/tools/arm-mbed-cli.html. Follow the instructions installing the CLI and import the KW40Z driver from the official repo. After that, replace the files with those in this repo, and you are good to go!

## What's Changed?
- The event queue is extended from 50 slots to 500 slots to lower the chance of an overflow.
- New definitions and functions are added to support the Message service.

## Message Service
The Message service is a general purpose data transimission service added to HEXIWEAR. Similar to the original Alert service, you can send arbitrary data to and from a client. However, unlike the Alert service, Message service supports any data length up to 18 bytes. In the raw buffer of the BLE packet, the first byte is always the length of the data, and ranges from 0 to 18. The mbed driver has an interface which handles this encoding procedure for you, but on the client side, you need to be aware of this format to correctly interact with the Message service.