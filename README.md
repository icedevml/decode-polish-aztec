# Decode AZTEC codes in Polish vehicle cards
Data in Polish vehicle card AZTEC codes is encoded using NRV2E algorithm, which is open source since ca. 1996 and is part of UCL data compression library. Original copyright of the library:

```
Copyright (C) 1996-2004 Markus Franz Xaver Johannes Oberhumer
```

## Usage
```
$ sudo apt install libucl1-dev
$ g++ -o decompress decompress_polish_aztec.c -lucl
$ cat vehicle.bin
BgQAANtYAAJDAPkxAHwAQXIw7zcGNN4ANiox+w81HrUGOP8eUABSAEUA+1oAWQBEDv9OAFQAIABN3wAuClMAvlQPV/eKUhq9Wg5X7k58UtcWSVq9TF5J79pBZ+5PAEsG12bTSm5GVQBM/ntSAEH7L1dj+0MAS1vvMvovewo3Ut4wDi39HjEAN6Pbl0FNe3YgPt5Q3kv3IlSevVnX1z9FMmuCShL2WgBaG9umKADvSAApJnx75k+itwZMAEx9X0rvbkSOTXtOOF/DRy0WOW53fPYLFoMzLr0xAi3DGnevLQOCfJ/vQZ5TcBZrN0oa9k4AfA82Q4QaDzj3q8deN6sN7zIE/1x8lbMnQdwBQi5ZT86jL2tqNAr2MwAw34xSH+uPSVPYFxZThBMzON8AMJM5wQA3MwRcMX7bNcET2jInwyedE01HZ4dlM94qKy0DL38fNgAqeBszSxOvNIeKfHM7fCLxNQAwVkMtdzl7Xiw/YMyrFzxQACBWw+Hza7c3C93/NWuHg1OWRquPQ5KP02K9IBZT4QZC9oNZU7aXFiOX83U4ADJFC7ADhrNVCyOW8w9qMbEnZhdHbHxjdjIT7E4DW0M3OQuGaxYmCSSSSSr/
$ base64 -d vehicle.bin | ./decompress | iconv -f UCS-2LE -t UTF-8//TRANSLIT

UCL data compression library (v1.03, Jul 20 2004).
Copyright (C) 1996-2004 Markus Franz Xaver Johannes Oberhumer
http://www.oberhumer.com/opensource/ucl/

XXC1|AAA0007046|1465058|PREZYDENT M. ST. WARSZAWY|DZIELNICA MOKOTÓW|UL. RAKOWIECKA 25/27|02-517 WARSZAWA|DMI 1PNK|TOYOTA|E12J|ZZE120(H)||COROLLA|JTDKM28E100089120|2013-11-06|---|KOWALSKI JAN|JAN|KOWALSKI||82091711022|02-517|WARSZAWA||WAŁBRZYSKA|24|30|KOWALSKA MARIA|MARIA|KOWALSKA||88030971022|02-517|WARSZAWA||WAŁBRZYSKA|24|30|1655|1655|2655|1205|M1|e11*2001/116*0180*04|2|1000|450|---|1398,00|71,00|P |2005-07-01|5|---|SAMOCHÓD OSOBOWY|---|2005|---|8,82|AAA0000000|02650008000158|03|02|000|2000NNNNNNNN|009002001|
```

## Friendly advice
I would like to ask some companies not to troll me with DMCA as it was done in previous cases. Everybody in Poland should have possibility to decode vehicle cards in their's vehicle control station for **FREE**. Claiming exclusive property rights for the algorithm or library developed in '90 and released under GPL is ILLEGAL.
