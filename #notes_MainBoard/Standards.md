
slotting header pinout:

| VCC | GND | G0  | RX+ | RX- | TX- | TX+ | G1  | GND | VCC |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| VCC | GND | G1  | TX+ | TX- | RX- | RX+ | G0  | GND | VCC |

JST pinout


| VCC | GND | RX+ | RX- |
| --- | --- | --- | --- |
| G0  | G1  | TX- | TX+ |



-----
data packaging structure:

| type [1] | ID [2] | Data [64] |
| -------- | ------ | --------- |

message type:
0x10 - publishing data
0x11 - subscribing to data
