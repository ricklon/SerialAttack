SerialAttack
============

Arduino Serial combat  We will connect N number of Arduinos that have more than three hardware serial ports together. Each Arduino will have hit points and a name. Attacks will have a psuedo random chance of succes. All linked Arduinos will pass messages to each other. These messages will list who is still alive. Attaks have to be declared by typing into the serial terminal the name of Arduino they are attacking. The message passing will continue until one last Arduino is standing.

![alt WhiteBoardDesign](https://raw.github.com/ricklon/SerialAttack/master/imgs/WhiteBoardDesign.jpg "White Board Design")

Physical Layer
====
The physical layer is directly connect serial devices either in a ring or a star pattern.

Data Link layer (How the messages are moved between devices)
====
A token in is a empty packet passed to all connected devices in the network. Each
machine get's incoming token and passes it away as an out going token.

When a system needs to send a message it captures the token and then fills it
with destination, and data information. Also, known as a data frame. Now this packet is passed machine to machine
until it reaches the intended destination.

A system that receives a message removes the message from the packet and then sends an empty token
back into the network via the next device.

If the original sending machine receives the packet it sent it will remove the message
and then send a token back into the network.

Packet Frame
====

Frame Format derived Wikipedia definition:
Token
3 bytes:
* 1 start delimeter || SD
* 1 acl byte || ACL
* 1 end delimeter || ED

?? Does the token need a CRC
The thought is that you can hack the game by playing the rules.
You can also hack the game by changing the protocol.

Details derived from Eli Bendersky's example:
* Start flag: 0x12 || SD
* End flag: 0x13 || ED
* Escape (DLE): 0x7D || ESC

Data/Command Frame
SD
ACL
Destination Address 6 bytes || DA
Source Address 6 bytes || SA
Data || Data
ED
CRC

?? Which order should the crc go?

Data Packet Map
SD | ACL | DA  | SA | Data | ED | CRC

Summary
====

Empty tokens zoom around. Then a data packet is created with CRC and then sent
to destination if it arrives full circle the source system removes it.

What if both source and destination are gone? Who takes it out?

Seems like a a noise protocol why send things at all if no once is interested?

Also, who do we want to add new devces to the network. We want to be able to dynamicly add.


References:
====
* Token Ring: (http://en.wikipedia.org/wiki/Token_ring)
* Framing in Serial Communication: (http://eli.thegreenplace.net/2009/08/12/framing-in-serial-communications/)
* Mod Bus: http://en.wikipedia.org/wiki/Modbus
