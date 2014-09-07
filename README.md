SerialAttack
============

Arduino Serial combat  We will connect N number of Arduinos that have more than three hardware serial ports together. Each Arduino will have hit points and a name. Attacks will have a psuedo random chance of succes. All linked Arduinos will pass messages to each other. These messages will list who is still alive. Attaks have to be declared by typing into the serial terminal the name of Arduino they are attacking. The message passing will continue until one last Arduino is standing.

![alt WhiteBoardDesign](https://raw.github.com/ricklon/SerialAttack/master/imgs/WhiteBoardDesign.jpg "White Board Design")

Message Protocol
====


Packet Frame
====


References:
====
* Token Ring (http://en.wikipedia.org/wiki/Token_ring)
* Framing in Serial Communication (http://eli.thegreenplace.net/2009/08/12/framing-in-serial-communications/)
