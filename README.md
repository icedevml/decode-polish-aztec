# Decode AZTEC codes in polish vehicle cards
Data in polish vehicle card AZTEC codes is encoded using NRV2E algorithm, which is open source since ca. 1996 and is part of UCL data compression library. Original copyright of the library:

```
Copyright (C) 1996-2004 Markus Franz Xaver Johannes Oberhumer
```

## Usage
```
$ sudo apt install libucl1-dev
$ g++ -o decompress decompress_polish_aztec.c -lucl
$ cat vehicle.bin
BgQAANtYAAJDAPkxAHwAQXIw7zcGNN4ANiox+w81HrUGOP8eUABSAEUA+1oAWQBEDv9OAFQAIABN3wAuClMAvlQPV/eKUhq9Wg5X7k58UtcWSVq9TF5J79pBZ+5PAEsG12bTSm5GVQBM/ntSAEH7L1dj+0MAS1vvMvovewo3Ut4wDi39HjEAN6Pbl0FNe3YgPt5Q3kv3IlSevVnX1z9FMmuCShL2WgBaG9umKADvSAApJnx75k+itwZMAEx9X0rvbkSOTXtOOF/DRy0WOW53fPYLFoMzLr0xAi3DGnevLQOCfJ/vQZ5TcBZrN0oa9k4AfA82Q4QaDzj3q8deN6sN7zIE/1x8lbMnQdwBQi5ZT86jL2tqNAr2MwAw34xSH+uPSVPYFxZThBMzON8AMJM5wQA3MwRcMX7bNcET2jInwyedE01HZ4dlM94qKy0DL38fNgAqeBszSxOvNIeKfHM7fCLxNQAwVkMtdzl7Xiw/YMyrFzxQACBWw+Hza7c3C93/NWuHg1OWRquPQ5KP02K9IBZT4QZC9oNZU7aXFiOX83U4ADJFC7ADhrNVCyOW8w9qMbEnZhdHbHxjdjIT7E4DW0M3OQuGaxYmCSSSSSr/
$ base64 -d vehicle.bin > vehicle2.bin
$ ./decompress < vehicle2.bin > vehicle3.bin

UCL data compression library (v1.03, Jul 20 2004).
Copyright (C) 1996-2004 Markus Franz Xaver Johannes Oberhumer
http://www.oberhumer.com/opensource/ucl/

$ xxd vehicle3.bin | head
00000000: 0000 0000 0000 0000 0002 4300 0000 0000  ..........C.....
00000010: 007c 0000 0000 0000 0000 0000 0000 0000  .|..............
00000020: 0000 0000 0000 0000 0000 0000 0000 0000  ................
00000030: 0000 0000 0600 0000 0036 0000 0031 0000  .........6...1..
00000040: 0036 0035 0600 0035 0638 0000 0050 0052  .6.5...5.8...P.R
00000050: 0045 005a 0059 0044 0045 004e 0054 0020  .E.Z.Y.D.E.N.T.
00000060: 004d 002e 0020 0053 0054 002e 0020 0057  .M... .S.T... .W
00000070: 0000 0052 0053 005a 0000 0057 0059 007c  ...R.S.Z...W.Y.|
00000080: 0044 005a 0049 0045 004c 004e 0049 0000  .D.Z.I.E.L.N.I..
00000090: 0041 0020 004d 004f 004b 004f 0054 00d3  .A. .M.O.K.O.T..
```

## Friendly advice
I would like to ask some companies not to troll me with DMCA as it was done in previous cases. Everybody in Poland should have possibility to decode vehicle cards in their's vehicle control station for **FREE**. Claiming exclusive property rights for the algorithm or library developed in '90 and released under GPL is ILLEGAL.
