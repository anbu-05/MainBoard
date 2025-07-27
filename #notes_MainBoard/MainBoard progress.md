#### 27 july
- i have 2 nano's connected to an stm. the stm does dma recieve from one nano -the publisher, and dma transmit to another nano -the subscriber. everything works as intended except for two problems
	- messages are being forwarded to the subscriber continuously instead of being transmitted only when there's a message from the subscriber
	- ![[Pasted image 20250727041258.png]]
	- i have to restart transmit dma even though it's in circular mode. i dont have the same problem with receive dma. i only have to start it once. i am figuring out what the problem is
- ive added git to this project
- i need to figure out permanent communication paths for now. the dynamic ROS-like topic/node structure will take a lot more work. the first step would be to set up a permanent path between the existing modules.
- [DMA circular mode issue](https://chatgpt.com/c/68854b27-3ba8-8007-a93c-30b35e8cbc77)
- [#include <Arduino.h> // #include <HardwareSerial.h> // HardwareSerial...](https://www.perplexity.ai/search/include-arduino-h-include-hard-iZ3fW8_pS2C9Zq5DHbMjaA)
- for the continuous data transfer, both AI say the same fixes:

|Approach|Buffer Mode|Only Sends Once?|Complexity|
|---|---|---|---|
|Normal + Rx Restart|Normal|Yes|Simple|
|Circular + Change Check|Circular|Yes|Simple|
|Circular + IDLE|Circular|Yes, fewer spurious|More code|
- circular + change check doesnt seem usefull. i will do normal + rx_restart for and build the rest of the architecture around transmitting one byte for now, and when im transferring multiple bytes ill switch to circular + IDLE.
---
- okay that was of no use. i changed receive dma to normal mode and restarted it in it's own callback function if there was data received. literally nothing changed. 
- i also have a doubt: if i have to restart the transmit DMA even though it's in circular DMA mode -why does my same code with the restarts not work when i set the transmit DMA to normal mode?

- for now im gonna use the circular + change check ig, because that seems the most fool proof.
---
- that didnt work either. sigh. i have a feeling there's something wrong with the AI's explanation
---
- i think i might have to re-approach this project. the technology is there. instead of trying to make a generic prototype, i need to start getting more specific. since i will be setting up permanent communication paths for now, ill start rebuilding this entire project with the rover as the focus. to be specific:
	- i will make the publisher a LoRa receiver emulation -it will publish the same kind of data the LoRa receiver would publish.
	- the subscribers will be the traversal board and the robotic arm board (which means ill need to add another nano to this prototype board -ill probably switch away from breadboards and use protoboards)
	- ill add an on board computer publisher too. which will also publish emulated traversal data.
	- all the code on the stm32 will be specific to communicating the data between these four modules for now.