# MEMZ
A trojan made for Danooct1's User Made Malware Series.

I am not responsible for any damage made using this trojan.

The converters for the MBR payload are very noobish. You will need some things to run these:

 - Python 2.7 and [this](https://github.com/vishnubob/python-midi) library.
 - PIL / Pillow installed in Python 2.7
 - linux tools or WSL
 - NASM
 - The [Nyan Cat midi file](https://github.com/Leurak/MEMZ/issues/47)
 - qemu (additional, if you want to test the payload)
 
If you want to use the exe to batch converter, don't forget to append -zip to it's command line, because this gives way smaller file sizes and also works on Windows XP.

You'll also need MingW-W64 to build the actual Trojan.

The ASM code may look very noobish, but this is my first big thing written in assembly.