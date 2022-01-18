EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "generator_scheme"
Date "2021-03-25"
Rev "v3.2"
Comp "piro.tex"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R R4
U 1 1 603FDA6E
P 2100 2200
F 0 "R4" H 2170 2246 50  0000 L CNN
F 1 "0" H 2170 2155 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 2030 2200 50  0001 C CNN
F 3 "~" H 2100 2200 50  0001 C CNN
	1    2100 2200
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR01
U 1 1 603FE213
P 750 4600
F 0 "#PWR01" H 750 4450 50  0001 C CNN
F 1 "+3V3" H 765 4773 50  0000 C CNN
F 2 "" H 750 4600 50  0001 C CNN
F 3 "" H 750 4600 50  0001 C CNN
	1    750  4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 2050 2100 1950
$Comp
L power:GND #PWR09
U 1 1 603FE7A6
P 2000 5650
F 0 "#PWR09" H 2000 5400 50  0001 C CNN
F 1 "GND" H 2005 5477 50  0000 C CNN
F 2 "" H 2000 5650 50  0001 C CNN
F 3 "" H 2000 5650 50  0001 C CNN
	1    2000 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 5550 1900 5600
Wire Wire Line
	1900 5600 2000 5600
Wire Wire Line
	2000 5600 2000 5550
Wire Wire Line
	2000 5600 2100 5600
Wire Wire Line
	2100 5600 2100 5550
Connection ~ 2000 5600
Wire Wire Line
	2000 5650 2000 5600
Text Label 1200 4850 0    50   ~ 0
SCL
Text Label 1200 4950 0    50   ~ 0
SDA
Text Label 2750 3850 0    50   ~ 0
Impulse
Wire Wire Line
	2700 3850 2750 3850
Wire Wire Line
	2750 4450 2700 4450
Wire Wire Line
	2750 4550 2700 4550
Wire Wire Line
	2750 4750 2700 4750
Wire Wire Line
	2750 4850 2700 4850
Text Label 1000 5050 0    50   ~ 0
Status_R
Text Label 700  4150 0    50   ~ 0
ExtendedStatus_R
Text Label 2750 4450 0    50   ~ 0
DAC_LDAC
Text Label 2750 4550 0    50   ~ 0
DAC_READY
Text Label 2750 4750 0    50   ~ 0
TX
Text Label 2750 4850 0    50   ~ 0
RX
Text Label 1000 5150 0    50   ~ 0
Status_G
Text Label 1000 5250 0    50   ~ 0
Status_B
Wire Wire Line
	700  4150 1400 4150
Wire Wire Line
	1200 4850 1400 4850
Wire Wire Line
	700  4250 1400 4250
Wire Wire Line
	700  4350 1400 4350
Text Label 700  4250 0    50   ~ 0
ExtendedStatus_G
Text Label 700  4350 0    50   ~ 0
ExtendedStatus_B
$Comp
L Device:R R3
U 1 1 604085C1
P 1650 2450
F 0 "R3" V 1550 2450 50  0000 C CNN
F 1 "22k" V 1750 2500 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 1580 2450 50  0001 C CNN
F 3 "~" H 1650 2450 50  0001 C CNN
	1    1650 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	1400 2750 1300 2750
Wire Wire Line
	1300 2750 1300 2450
Wire Wire Line
	1300 2450 1500 2450
Text Label 2750 5050 0    50   ~ 0
EEPROM_WP
Wire Notes Line
	4100 6300 2500 6300
Text Notes 2550 6300 0    50   Italic 10
EEPROM
$Comp
L Regulator_Linear:AMS1117-3.3 DA1
U 1 1 604193C7
P 2650 900
F 0 "DA1" H 2500 1050 50  0000 C CNN
F 1 "AMS1117" H 2850 1050 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 2650 1100 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 2750 650 50  0001 C CNN
	1    2650 900 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 60422E3A
P 2650 1350
F 0 "#PWR013" H 2650 1100 50  0001 C CNN
F 1 "GND" H 2655 1177 50  0000 C CNN
F 2 "" H 2650 1350 50  0001 C CNN
F 3 "" H 2650 1350 50  0001 C CNN
	1    2650 1350
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 60425F26
P 850 900
F 0 "J1" H 850 1000 50  0000 C CNN
F 1 "Power_5V" H 800 700 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 850 900 50  0001 C CNN
F 3 "~" H 850 900 50  0001 C CNN
	1    850  900 
	-1   0    0    -1  
$EndComp
$Comp
L Device:CP C3
U 1 1 604292AA
P 3300 1100
F 0 "C3" H 3418 1146 50  0000 L CNN
F 1 "220u" H 3418 1055 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-7260-15_AVX-R_Pad2.68x6.30mm_HandSolder" H 3338 950 50  0001 C CNN
F 3 "~" H 3300 1100 50  0001 C CNN
	1    3300 1100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 6042C531
P 1100 1150
F 0 "#PWR03" H 1100 900 50  0001 C CNN
F 1 "GND" H 1105 977 50  0000 C CNN
F 2 "" H 1100 1150 50  0001 C CNN
F 3 "" H 1100 1150 50  0001 C CNN
	1    1100 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 1150 1100 1000
Wire Wire Line
	1100 1000 1050 1000
$Comp
L power:GND #PWR017
U 1 1 6042D891
P 3300 1350
F 0 "#PWR017" H 3300 1100 50  0001 C CNN
F 1 "GND" H 3305 1177 50  0000 C CNN
F 2 "" H 3300 1350 50  0001 C CNN
F 3 "" H 3300 1350 50  0001 C CNN
	1    3300 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 1350 3300 1250
Wire Wire Line
	3750 950  3750 900 
Wire Wire Line
	3750 1350 3750 1250
$Comp
L power:GND #PWR019
U 1 1 6042DBA8
P 3750 1350
F 0 "#PWR019" H 3750 1100 50  0001 C CNN
F 1 "GND" H 3755 1177 50  0000 C CNN
F 2 "" H 3750 1350 50  0001 C CNN
F 3 "" H 3750 1350 50  0001 C CNN
	1    3750 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 6042A1F6
P 3750 1100
F 0 "C4" H 3865 1146 50  0000 L CNN
F 1 "100n" H 3865 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 3788 950 50  0001 C CNN
F 3 "~" H 3750 1100 50  0001 C CNN
	1    3750 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 60414398
P 1400 1100
F 0 "C1" H 1518 1146 50  0000 L CNN
F 1 "220u" H 1518 1055 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-7260-15_AVX-R_Pad2.68x6.30mm_HandSolder" H 1438 950 50  0001 C CNN
F 3 "~" H 1400 1100 50  0001 C CNN
	1    1400 1100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 6041439E
P 1400 1350
F 0 "#PWR05" H 1400 1100 50  0001 C CNN
F 1 "GND" H 1405 1177 50  0000 C CNN
F 2 "" H 1400 1350 50  0001 C CNN
F 3 "" H 1400 1350 50  0001 C CNN
	1    1400 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 900  1400 950 
Wire Wire Line
	1850 950  1850 900 
Wire Wire Line
	1850 1350 1850 1250
$Comp
L power:GND #PWR08
U 1 1 604143A8
P 1850 1350
F 0 "#PWR08" H 1850 1100 50  0001 C CNN
F 1 "GND" H 1855 1177 50  0000 C CNN
F 2 "" H 1850 1350 50  0001 C CNN
F 3 "" H 1850 1350 50  0001 C CNN
	1    1850 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 604143AE
P 1850 1100
F 0 "C2" H 1965 1146 50  0000 L CNN
F 1 "100n" H 1965 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 1888 950 50  0001 C CNN
F 3 "~" H 1850 1100 50  0001 C CNN
	1    1850 1100
	1    0    0    -1  
$EndComp
Connection ~ 1850 900 
Wire Wire Line
	1850 900  2150 900 
Connection ~ 1400 900 
Wire Wire Line
	1400 900  1850 900 
Wire Wire Line
	1050 900  1400 900 
$Comp
L power:+3V3 #PWR022
U 1 1 60415694
P 3900 850
F 0 "#PWR022" H 3900 700 50  0001 C CNN
F 1 "+3V3" H 3915 1023 50  0000 C CNN
F 2 "" H 3900 850 50  0001 C CNN
F 3 "" H 3900 850 50  0001 C CNN
	1    3900 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 900  3900 900 
Wire Wire Line
	3900 900  3900 850 
Connection ~ 3750 900 
Wire Notes Line
	4100 600  650  600 
Wire Notes Line
	650  600  650  1600
Wire Notes Line
	650  1600 4100 1600
Wire Notes Line
	4100 1600 4100 600 
Text Notes 700  600  0    50   Italic 10
Power
Wire Wire Line
	9200 1400 9150 1400
$Comp
L power:+3V3 #PWR049
U 1 1 6042DDEE
P 9150 850
F 0 "#PWR049" H 9150 700 50  0001 C CNN
F 1 "+3V3" H 9165 1023 50  0000 C CNN
F 2 "" H 9150 850 50  0001 C CNN
F 3 "" H 9150 850 50  0001 C CNN
	1    9150 850 
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 60437677
P 9100 2000
F 0 "C13" H 9150 2100 50  0000 L CNN
F 1 "446p" H 9150 1900 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 9138 1850 50  0001 C CNN
F 3 "~" H 9100 2000 50  0001 C CNN
	1    9100 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C12
U 1 1 60438A85
P 8900 1600
F 0 "C12" H 9018 1646 50  0000 L CNN
F 1 "220u" H 9018 1555 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-7260-15_AVX-R_Pad2.68x6.30mm_HandSolder" H 8938 1450 50  0001 C CNN
F 3 "~" H 8900 1600 50  0001 C CNN
	1    8900 1600
	1    0    0    -1  
$EndComp
Connection ~ 9150 1400
$Comp
L power:GND #PWR047
U 1 1 6043C8C9
P 8900 1800
F 0 "#PWR047" H 8900 1550 50  0001 C CNN
F 1 "GND" H 8905 1627 50  0000 C CNN
F 2 "" H 8900 1800 50  0001 C CNN
F 3 "" H 8900 1800 50  0001 C CNN
	1    8900 1800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR048
U 1 1 6043CBB1
P 9100 2200
F 0 "#PWR048" H 9100 1950 50  0001 C CNN
F 1 "GND" H 9105 2027 50  0000 C CNN
F 2 "" H 9100 2200 50  0001 C CNN
F 3 "" H 9100 2200 50  0001 C CNN
	1    9100 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR052
U 1 1 6043CECA
P 9600 2200
F 0 "#PWR052" H 9600 1950 50  0001 C CNN
F 1 "GND" H 9605 2027 50  0000 C CNN
F 2 "" H 9600 2200 50  0001 C CNN
F 3 "" H 9600 2200 50  0001 C CNN
	1    9600 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 2200 9600 2100
Wire Wire Line
	9100 2200 9100 2150
Wire Wire Line
	8900 1800 8900 1750
$Comp
L Device:R R13
U 1 1 6042BD48
P 9500 1100
F 0 "R13" V 9400 1100 50  0000 C CNN
F 1 "2" V 9600 1100 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 9430 1100 50  0001 C CNN
F 3 "~" H 9500 1100 50  0001 C CNN
	1    9500 1100
	0    1    1    0   
$EndComp
Wire Wire Line
	9150 850  9150 950 
Wire Wire Line
	9150 1400 9150 1100
Connection ~ 9150 1100
Wire Wire Line
	9150 1100 9350 1100
$Comp
L Device:R R15
U 1 1 6045673C
P 10150 2100
F 0 "R15" H 10050 2100 50  0000 C CNN
F 1 "3.3k" H 10000 2200 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 10080 2100 50  0001 C CNN
F 3 "~" H 10150 2100 50  0001 C CNN
	1    10150 2100
	-1   0    0    1   
$EndComp
$Comp
L Device:R R14
U 1 1 60456DEA
P 9800 950
F 0 "R14" V 9700 950 50  0000 C CNN
F 1 "1" V 9900 950 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 9730 950 50  0001 C CNN
F 3 "~" H 9800 950 50  0001 C CNN
	1    9800 950 
	0    1    1    0   
$EndComp
Wire Wire Line
	9650 950  9150 950 
Connection ~ 9150 950 
Wire Wire Line
	9150 950  9150 1100
Text Notes 9300 900  0    25   ~ 0
To get 0.663 Ohm
$Comp
L Device:R R17
U 1 1 60464C88
P 10350 1900
F 0 "R17" V 10250 1900 50  0000 C CNN
F 1 "12k" V 10450 1900 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 10280 1900 50  0001 C CNN
F 3 "~" H 10350 1900 50  0001 C CNN
	1    10350 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	10500 1900 10550 1900
Wire Wire Line
	10200 1900 10150 1900
$Comp
L Device:CP C16
U 1 1 6047B1BD
P 10550 2150
F 0 "C16" H 10668 2196 50  0000 L CNN
F 1 "220u" H 10668 2105 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-7260-15_AVX-R_Pad2.68x6.30mm_HandSolder" H 10588 2000 50  0001 C CNN
F 3 "~" H 10550 2150 50  0001 C CNN
	1    10550 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	10550 2000 10550 1900
Connection ~ 10550 1900
$Comp
L power:GND #PWR054
U 1 1 6047DB67
P 10550 2350
F 0 "#PWR054" H 10550 2100 50  0001 C CNN
F 1 "GND" H 10555 2177 50  0000 C CNN
F 2 "" H 10550 2350 50  0001 C CNN
F 3 "" H 10550 2350 50  0001 C CNN
	1    10550 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	10550 2350 10550 2300
$Comp
L power:Vdrive #PWR057
U 1 1 60485593
P 10950 1850
F 0 "#PWR057" H 10750 1700 50  0001 C CNN
F 1 "Vdrive" H 10965 2023 50  0000 C CNN
F 2 "" H 10950 1850 50  0001 C CNN
F 3 "" H 10950 1850 50  0001 C CNN
	1    10950 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	10550 1900 10950 1900
Wire Wire Line
	10950 1900 10950 1850
Wire Wire Line
	10150 1950 10150 1900
Connection ~ 10150 1900
Wire Wire Line
	10150 1900 10000 1900
Wire Notes Line
	8750 600  8750 2650
Wire Notes Line
	8750 2650 11100 2650
Wire Notes Line
	11100 2650 11100 600 
Wire Notes Line
	11100 600  8750 600 
Text Notes 8800 600  0    50   Italic 10
Power driver
Wire Notes Line
	3250 5900 3250 1700
Wire Notes Line
	3250 1700 650  1700
Wire Notes Line
	650  1700 650  5900
Wire Notes Line
	650  5900 3250 5900
Text Notes 700  1700 0    50   Italic 10
Brain
Wire Wire Line
	9100 1800 9200 1800
Wire Wire Line
	8900 1450 8900 1400
Wire Wire Line
	8900 1400 9150 1400
Wire Wire Line
	9100 1850 9100 1800
Text Label 8500 4400 0    50   ~ 0
TX
Wire Wire Line
	8500 4400 8650 4400
Text Label 8500 4800 0    50   ~ 0
RX
Wire Wire Line
	10600 4700 10750 4700
Wire Wire Line
	10600 4400 10600 4700
$Comp
L Connector_Generic:Conn_01x02 J8
U 1 1 60455144
P 10950 4700
F 0 "J8" H 10950 4800 50  0000 C CNN
F 1 "RS232" H 10900 4500 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 10950 4700 50  0001 C CNN
F 3 "~" H 10950 4700 50  0001 C CNN
	1    10950 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 6046C6C0
P 8500 3550
F 0 "C11" H 8615 3596 50  0000 L CNN
F 1 "100n" H 8615 3505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 8538 3400 50  0001 C CNN
F 3 "~" H 8500 3550 50  0001 C CNN
	1    8500 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C15
U 1 1 6046CD0A
P 10450 4200
F 0 "C15" V 10300 4150 50  0000 L CNN
F 1 "100n" V 10600 4100 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 10488 4050 50  0001 C CNN
F 3 "~" H 10450 4200 50  0001 C CNN
	1    10450 4200
	0    1    1    0   
$EndComp
$Comp
L Device:C C14
U 1 1 6046D404
P 10350 3550
F 0 "C14" H 10465 3596 50  0000 L CNN
F 1 "100n" H 10465 3505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 10388 3400 50  0001 C CNN
F 3 "~" H 10350 3550 50  0001 C CNN
	1    10350 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 6046D7E3
P 10700 3750
F 0 "C17" H 10815 3796 50  0000 L CNN
F 1 "100n" H 10815 3705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 10738 3600 50  0001 C CNN
F 3 "~" H 10700 3750 50  0001 C CNN
	1    10700 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 3900 10700 3900
$Comp
L power:+3V3 #PWR056
U 1 1 60477376
P 10700 3500
F 0 "#PWR056" H 10700 3350 50  0001 C CNN
F 1 "+3V3" H 10715 3673 50  0000 C CNN
F 2 "" H 10700 3500 50  0001 C CNN
F 3 "" H 10700 3500 50  0001 C CNN
	1    10700 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	10700 3500 10700 3600
$Comp
L power:GND #PWR055
U 1 1 6047B1DB
P 10650 4200
F 0 "#PWR055" H 10650 3950 50  0001 C CNN
F 1 "GND" H 10750 4200 50  0000 C CNN
F 2 "" H 10650 4200 50  0001 C CNN
F 3 "" H 10650 4200 50  0001 C CNN
	1    10650 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10300 4200 10250 4200
Wire Wire Line
	10600 4200 10650 4200
Wire Wire Line
	8500 3400 8650 3400
Wire Wire Line
	8500 3700 8650 3700
Wire Wire Line
	10250 3400 10350 3400
Wire Wire Line
	10350 3700 10250 3700
Wire Wire Line
	10600 4400 10250 4400
$Comp
L power:GND #PWR051
U 1 1 6043426C
P 9450 5550
F 0 "#PWR051" H 9450 5300 50  0001 C CNN
F 1 "GND" H 9455 5377 50  0000 C CNN
F 2 "" H 9450 5550 50  0001 C CNN
F 3 "" H 9450 5550 50  0001 C CNN
	1    9450 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 5550 9450 5500
Wire Notes Line
	7750 2750 7750 5800
Wire Notes Line
	7750 5800 11100 5800
Wire Notes Line
	11100 5800 11100 2750
Wire Notes Line
	11100 2750 7750 2750
Text Notes 7800 2750 0    50   Italic 10
Connection
Wire Wire Line
	2700 4950 2750 4950
Text Label 2750 4950 0    50   ~ 0
DRIVER_EN
Text Label 6950 1450 0    50   ~ 0
DRIVER_EN
Text Label 6950 1350 0    50   ~ 0
Impulse
Wire Wire Line
	6950 1350 7400 1350
Wire Wire Line
	7400 1450 6950 1450
$Comp
L Connector_Generic:Conn_01x02 J7
U 1 1 60497712
P 8450 1350
F 0 "J7" H 8450 1450 50  0000 C CNN
F 1 "Impulse" H 8450 1150 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8450 1350 50  0001 C CNN
F 3 "~" H 8450 1350 50  0001 C CNN
	1    8450 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR046
U 1 1 60498947
P 8200 1600
F 0 "#PWR046" H 8200 1350 50  0001 C CNN
F 1 "GND" H 8205 1427 50  0000 C CNN
F 2 "" H 8200 1600 50  0001 C CNN
F 3 "" H 8200 1600 50  0001 C CNN
	1    8200 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 1450 8200 1450
Wire Wire Line
	8200 1450 8200 1600
Wire Notes Line
	6850 600  8650 600 
Wire Notes Line
	8650 600  8650 2200
Wire Notes Line
	8650 2200 6850 2200
Wire Notes Line
	6850 2200 6850 600 
Text Notes 6900 600  0    50   Italic 10
Impulse signal
$Comp
L power:GND #PWR045
U 1 1 604D4E05
P 7750 1900
F 0 "#PWR045" H 7750 1650 50  0001 C CNN
F 1 "GND" H 7755 1727 50  0000 C CNN
F 2 "" H 7750 1900 50  0001 C CNN
F 3 "" H 7750 1900 50  0001 C CNN
	1    7750 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 1850 7750 1850
Wire Wire Line
	7750 1850 7750 1900
Connection ~ 7750 1850
Wire Wire Line
	7750 1850 7850 1850
Text Label 3900 6950 0    50   ~ 0
SCL
Text Label 3900 6850 0    50   ~ 0
SDA
Text Label 3600 7050 0    50   ~ 0
EEPROM_WP
Wire Wire Line
	2650 6950 2650 6850
Connection ~ 2650 6950
Wire Wire Line
	2800 6950 2650 6950
Wire Wire Line
	2650 7050 2650 6950
Connection ~ 2650 7050
Wire Wire Line
	2800 7050 2650 7050
Wire Wire Line
	2650 6850 2800 6850
Wire Wire Line
	2650 7100 2650 7050
$Comp
L power:GND #PWR014
U 1 1 6040F76C
P 2650 7100
F 0 "#PWR014" H 2650 6850 50  0001 C CNN
F 1 "GND" H 2655 6927 50  0000 C CNN
F 2 "" H 2650 7100 50  0001 C CNN
F 3 "" H 2650 7100 50  0001 C CNN
	1    2650 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 7350 3200 7250
$Comp
L power:GND #PWR016
U 1 1 6040ECA9
P 3200 7350
F 0 "#PWR016" H 3200 7100 50  0001 C CNN
F 1 "GND" H 3205 7177 50  0000 C CNN
F 2 "" H 3200 7350 50  0001 C CNN
F 3 "" H 3200 7350 50  0001 C CNN
	1    3200 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 6950 3900 6950
Wire Notes Line
	2500 6300 2500 7600
Wire Notes Line
	4100 7600 4100 6300
Wire Notes Line
	2500 7600 4100 7600
Wire Wire Line
	3200 6650 3200 6550
$Comp
L power:+3V3 #PWR015
U 1 1 6040E1F6
P 3200 6550
F 0 "#PWR015" H 3200 6400 50  0001 C CNN
F 1 "+3V3" H 3215 6723 50  0000 C CNN
F 2 "" H 3200 6550 50  0001 C CNN
F 3 "" H 3200 6550 50  0001 C CNN
	1    3200 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 950  7850 950 
Wire Wire Line
	7750 950  7650 950 
Connection ~ 7750 950 
Wire Wire Line
	7750 900  7750 950 
$Comp
L power:Vdrive #PWR044
U 1 1 604647BE
P 7750 900
F 0 "#PWR044" H 7550 750 50  0001 C CNN
F 1 "Vdrive" H 7765 1073 50  0000 C CNN
F 2 "" H 7750 900 50  0001 C CNN
F 3 "" H 7750 900 50  0001 C CNN
	1    7750 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 3050 9450 3100
$Comp
L power:+3V3 #PWR050
U 1 1 6046E420
P 9450 3050
F 0 "#PWR050" H 9450 2900 50  0001 C CNN
F 1 "+3V3" H 9465 3223 50  0000 C CNN
F 2 "" H 9450 3050 50  0001 C CNN
F 3 "" H 9450 3050 50  0001 C CNN
	1    9450 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 60570B9D
P 4400 1100
F 0 "C5" H 4515 1146 50  0000 L CNN
F 1 "100n" H 4515 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 4438 950 50  0001 C CNN
F 3 "~" H 4400 1100 50  0001 C CNN
	1    4400 1100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR024
U 1 1 6057167A
P 4400 1300
F 0 "#PWR024" H 4400 1050 50  0001 C CNN
F 1 "GND" H 4405 1127 50  0000 C CNN
F 2 "" H 4400 1300 50  0001 C CNN
F 3 "" H 4400 1300 50  0001 C CNN
	1    4400 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 1300 4400 1250
$Comp
L power:+3V3 #PWR023
U 1 1 6058277E
P 4400 850
F 0 "#PWR023" H 4400 700 50  0001 C CNN
F 1 "+3V3" H 4415 1023 50  0000 C CNN
F 2 "" H 4400 850 50  0001 C CNN
F 3 "" H 4400 850 50  0001 C CNN
	1    4400 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 850  4400 900 
Wire Wire Line
	4400 900  4800 900 
Wire Wire Line
	4800 900  4800 950 
Connection ~ 4400 900 
Wire Wire Line
	4400 900  4400 950 
Text Notes 4800 900  0    25   Italic 0
ADM3202
Text Notes 4450 900  0    25   Italic 0
24LC512
Wire Wire Line
	3600 6850 3900 6850
Wire Wire Line
	750  4900 750  4950
Wire Wire Line
	10250 4800 10750 4800
Wire Wire Line
	8050 4050 7900 4050
Wire Wire Line
	7900 4150 8050 4150
Text Label 7900 4150 0    50   ~ 0
RX
Text Label 7900 4050 0    50   ~ 0
TX
$Comp
L Connector_Generic:Conn_01x02 J6
U 1 1 60451F75
P 8250 4050
F 0 "J6" H 8250 4150 50  0000 C CNN
F 1 "UART" H 8250 3850 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8250 4050 50  0001 C CNN
F 3 "~" H 8250 4050 50  0001 C CNN
	1    8250 4050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR011
U 1 1 605DDC4C
P 2150 850
F 0 "#PWR011" H 2150 700 50  0001 C CNN
F 1 "+5V" H 2165 1023 50  0000 C CNN
F 2 "" H 2150 850 50  0001 C CNN
F 3 "" H 2150 850 50  0001 C CNN
	1    2150 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 850  2150 900 
Connection ~ 2150 900 
Wire Wire Line
	2150 900  2350 900 
$Comp
L Connector_Generic:Conn_01x04 J4
U 1 1 604D254A
P 6600 2100
F 0 "J4" H 6550 2300 50  0000 L CNN
F 1 "BMP180" H 6400 1800 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6600 2100 50  0001 C CNN
F 3 "~" H 6600 2100 50  0001 C CNN
	1    6600 2100
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR038
U 1 1 604D2DE9
P 6300 1900
F 0 "#PWR038" H 6300 1750 50  0001 C CNN
F 1 "+3V3" H 6315 2073 50  0000 C CNN
F 2 "" H 6300 1900 50  0001 C CNN
F 3 "" H 6300 1900 50  0001 C CNN
	1    6300 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR039
U 1 1 604D3716
P 6300 2400
F 0 "#PWR039" H 6300 2150 50  0001 C CNN
F 1 "GND" H 6305 2227 50  0000 C CNN
F 2 "" H 6300 2400 50  0001 C CNN
F 3 "" H 6300 2400 50  0001 C CNN
	1    6300 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 2400 6300 2300
Wire Wire Line
	6300 2300 6400 2300
Wire Wire Line
	6400 2000 6300 2000
Wire Wire Line
	6300 2000 6300 1900
Text Label 6200 2100 0    50   ~ 0
SCL
Text Label 6200 2200 0    50   ~ 0
SDA
Wire Wire Line
	6200 2100 6400 2100
Wire Wire Line
	6400 2200 6200 2200
Wire Notes Line
	6150 1650 6750 1650
Wire Notes Line
	6750 1650 6750 2650
Wire Notes Line
	6750 2650 6150 2650
Wire Notes Line
	6150 2650 6150 1650
Text Notes 6200 1650 0    50   Italic 10
Temperature
$Comp
L Sensor_Optical:KPS-5130 VD2
U 1 1 604FFA84
P 4150 5750
F 0 "VD2" H 4150 6150 50  0000 C CNN
F 1 "LED RGB" H 4150 5400 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_1x04_P1.27mm_Vertical" H 4150 5300 50  0001 C CNN
F 3 "http://www.kingbright.com/attachments/file/psearch/000/00/00/KPS-5130PD7C(Ver.15).pdf" H 4100 5750 50  0001 C CNN
	1    4150 5750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 60500E70
P 4700 5750
F 0 "R5" V 4600 5700 50  0000 L CNN
F 1 "300R" V 4800 5650 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4630 5750 50  0001 C CNN
F 3 "~" H 4700 5750 50  0001 C CNN
	1    4700 5750
	0    1    1    0   
$EndComp
$Comp
L power:+3V3 #PWR029
U 1 1 60501F6B
P 4950 5650
F 0 "#PWR029" H 4950 5500 50  0001 C CNN
F 1 "+3V3" H 4965 5823 50  0000 C CNN
F 2 "" H 4950 5650 50  0001 C CNN
F 3 "" H 4950 5650 50  0001 C CNN
	1    4950 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 5650 4950 5750
Wire Wire Line
	4950 5750 4850 5750
Wire Wire Line
	4550 5750 4450 5750
Text Label 3450 5550 0    50   ~ 0
Status_R
Text Label 3450 5750 0    50   ~ 0
Status_G
Text Label 3450 5950 0    50   ~ 0
Status_B
Wire Wire Line
	3450 5950 3850 5950
Wire Wire Line
	3850 5750 3450 5750
Wire Wire Line
	3450 5550 3850 5550
$Comp
L Sensor_Optical:KPS-5130 VD3
U 1 1 605356FA
P 6150 5750
F 0 "VD3" H 6150 6150 50  0000 C CNN
F 1 "LED RGB" H 6150 5400 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_1x04_P1.27mm_Vertical" H 6150 5300 50  0001 C CNN
F 3 "http://www.kingbright.com/attachments/file/psearch/000/00/00/KPS-5130PD7C(Ver.15).pdf" H 6100 5750 50  0001 C CNN
	1    6150 5750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R12
U 1 1 60535700
P 6700 5750
F 0 "R12" V 6600 5700 50  0000 L CNN
F 1 "300R" V 6800 5650 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 6630 5750 50  0001 C CNN
F 3 "~" H 6700 5750 50  0001 C CNN
	1    6700 5750
	0    1    1    0   
$EndComp
$Comp
L power:+3V3 #PWR042
U 1 1 60535706
P 6950 5650
F 0 "#PWR042" H 6950 5500 50  0001 C CNN
F 1 "+3V3" H 6965 5823 50  0000 C CNN
F 2 "" H 6950 5650 50  0001 C CNN
F 3 "" H 6950 5650 50  0001 C CNN
	1    6950 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 5650 6950 5750
Wire Wire Line
	6950 5750 6850 5750
Wire Wire Line
	6550 5750 6450 5750
Text Label 5150 5550 0    50   ~ 0
ExtendedStatus_R
Text Label 5150 5750 0    50   ~ 0
ExtendedStatus_G
Text Label 5150 5950 0    50   ~ 0
ExtendedStatus_B
Wire Wire Line
	5150 5550 5850 5550
Wire Wire Line
	5150 5750 5850 5750
Wire Wire Line
	5150 5950 5850 5950
Wire Notes Line
	3350 5250 7150 5250
Wire Notes Line
	7150 5250 7150 6200
Wire Notes Line
	7150 6200 3350 6200
Wire Notes Line
	3350 6200 3350 5250
Text Notes 3400 5250 0    50   Italic 10
RGB
$Comp
L Device:C C7
U 1 1 6058A327
P 5200 1100
F 0 "C7" H 5315 1146 50  0000 L CNN
F 1 "100n" H 5315 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5238 950 50  0001 C CNN
F 3 "~" H 5200 1100 50  0001 C CNN
	1    5200 1100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR030
U 1 1 6058A32D
P 5200 1300
F 0 "#PWR030" H 5200 1050 50  0001 C CNN
F 1 "GND" H 5205 1127 50  0000 C CNN
F 2 "" H 5200 1300 50  0001 C CNN
F 3 "" H 5200 1300 50  0001 C CNN
	1    5200 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 1300 5200 1250
Wire Wire Line
	5200 900  5200 950 
Text Notes 5100 900  0    25   Italic 0
MC34063
$Comp
L Device:C C8
U 1 1 605A742B
P 5600 1100
F 0 "C8" H 5715 1146 50  0000 L CNN
F 1 "100n" H 5715 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5638 950 50  0001 C CNN
F 3 "~" H 5600 1100 50  0001 C CNN
	1    5600 1100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR034
U 1 1 605A7431
P 5600 1300
F 0 "#PWR034" H 5600 1050 50  0001 C CNN
F 1 "GND" H 5605 1127 50  0000 C CNN
F 2 "" H 5600 1300 50  0001 C CNN
F 3 "" H 5600 1300 50  0001 C CNN
	1    5600 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 1300 5600 1250
Wire Wire Line
	5600 900  5600 950 
Text Notes 5600 900  0    25   Italic 0
MCP4728
Text Label 3450 3250 0    50   ~ 0
SCL
Text Label 3450 3350 0    50   ~ 0
SDA
Text Label 3450 3450 0    50   ~ 0
DAC_LDAC
Text Label 3450 3550 0    50   ~ 0
DAC_READY
Wire Wire Line
	3450 3250 3950 3250
Wire Wire Line
	3450 3350 3950 3350
Wire Wire Line
	3450 3450 3950 3450
Wire Wire Line
	3950 3550 3450 3550
$Comp
L power:GND #PWR027
U 1 1 605E6FA4
P 4550 3800
F 0 "#PWR027" H 4550 3550 50  0001 C CNN
F 1 "GND" H 4555 3627 50  0000 C CNN
F 2 "" H 4550 3800 50  0001 C CNN
F 3 "" H 4550 3800 50  0001 C CNN
	1    4550 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 3800 4550 3750
Wire Wire Line
	4550 3050 4550 3000
$Comp
L mine:LVM324M DD3
U 1 1 60600E53
P 6200 3050
F 0 "DD3" H 6200 3250 50  0000 C CNN
F 1 "LVM324M" H 6250 2850 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 6150 3150 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2902-n.pdf" H 6250 3250 50  0001 C CNN
	1    6200 3050
	1    0    0    -1  
$EndComp
$Comp
L mine:LVM324M DD3
U 2 1 6060300D
P 6200 3600
F 0 "DD3" H 6200 3800 50  0000 C CNN
F 1 "LVM324M" H 6250 3400 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 6150 3700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2902-n.pdf" H 6250 3800 50  0001 C CNN
	2    6200 3600
	1    0    0    -1  
$EndComp
$Comp
L mine:LVM324M DD3
U 3 1 6060598B
P 6200 4150
F 0 "DD3" H 6200 4350 50  0000 C CNN
F 1 "LVM324M" H 6250 3950 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 6150 4250 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2902-n.pdf" H 6250 4350 50  0001 C CNN
	3    6200 4150
	1    0    0    -1  
$EndComp
$Comp
L mine:LVM324M DD3
U 4 1 60606DD9
P 6200 4700
F 0 "DD3" H 6200 4900 50  0000 C CNN
F 1 "LVM324M" H 6250 4500 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 6150 4800 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2902-n.pdf" H 6250 4900 50  0001 C CNN
	4    6200 4700
	1    0    0    -1  
$EndComp
$Comp
L mine:LVM324M DD3
U 5 1 6060837C
P 3900 4400
F 0 "DD3" H 3858 4446 50  0000 L CNN
F 1 "LVM324M" H 3858 4355 50  0000 L CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 3850 4500 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2902-n.pdf" H 3950 4600 50  0001 C CNN
	5    3900 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 606373B1
P 6650 3250
F 0 "R8" H 6550 3200 50  0000 C CNN
F 1 "1R" H 6550 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 6580 3250 50  0001 C CNN
F 3 "~" H 6650 3250 50  0001 C CNN
	1    6650 3250
	-1   0    0    1   
$EndComp
$Comp
L Device:R R9
U 1 1 606524F4
P 6650 3800
F 0 "R9" H 6550 3750 50  0000 C CNN
F 1 "1R" H 6550 3850 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 6580 3800 50  0001 C CNN
F 3 "~" H 6650 3800 50  0001 C CNN
	1    6650 3800
	-1   0    0    1   
$EndComp
$Comp
L Device:R R10
U 1 1 606526B1
P 6650 4350
F 0 "R10" H 6550 4300 50  0000 C CNN
F 1 "1R" H 6550 4400 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 6580 4350 50  0001 C CNN
F 3 "~" H 6650 4350 50  0001 C CNN
	1    6650 4350
	-1   0    0    1   
$EndComp
$Comp
L Device:R R11
U 1 1 6065295E
P 6650 4900
F 0 "R11" H 6550 4850 50  0000 C CNN
F 1 "1R" H 6550 4950 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 6580 4900 50  0001 C CNN
F 3 "~" H 6650 4900 50  0001 C CNN
	1    6650 4900
	-1   0    0    1   
$EndComp
Wire Wire Line
	5650 2950 5900 2950
Wire Wire Line
	5650 3500 5900 3500
Wire Wire Line
	5650 3500 5650 4050
Wire Wire Line
	5650 4050 5900 4050
Connection ~ 5650 3500
Wire Wire Line
	5650 4050 5650 4600
Wire Wire Line
	5650 4600 5900 4600
Connection ~ 5650 4050
Wire Wire Line
	5900 3150 5850 3150
Wire Wire Line
	5850 3150 5850 3350
Wire Wire Line
	5850 3350 6550 3350
Wire Wire Line
	6550 3350 6550 3050
Wire Wire Line
	6550 3050 6500 3050
Wire Wire Line
	5900 3700 5850 3700
Wire Wire Line
	5850 3700 5850 3900
Wire Wire Line
	5850 3900 6550 3900
Wire Wire Line
	6550 3900 6550 3600
Wire Wire Line
	6550 3600 6500 3600
Wire Wire Line
	5900 4250 5850 4250
Wire Wire Line
	5850 4250 5850 4450
Wire Wire Line
	5850 4450 6550 4450
Wire Wire Line
	6550 4450 6550 4150
Wire Wire Line
	6550 4150 6500 4150
Wire Wire Line
	5900 4800 5850 4800
Wire Wire Line
	5850 4800 5850 5000
Wire Wire Line
	5850 5000 6550 5000
Wire Wire Line
	6550 5000 6550 4700
Wire Wire Line
	6550 4700 6500 4700
Wire Wire Line
	6550 3050 6650 3050
Wire Wire Line
	6650 3050 6650 3100
Connection ~ 6550 3050
Wire Wire Line
	6550 3600 6650 3600
Wire Wire Line
	6650 3600 6650 3650
Connection ~ 6550 3600
Wire Wire Line
	6550 4150 6650 4150
Wire Wire Line
	6650 4150 6650 4200
Connection ~ 6550 4150
Wire Wire Line
	6550 4700 6650 4700
Wire Wire Line
	6650 4700 6650 4750
Connection ~ 6550 4700
$Comp
L Connector_Generic:Conn_01x02 J5
U 1 1 607255D5
P 7250 3600
F 0 "J5" H 7250 3700 50  0000 C CNN
F 1 "Analog" H 7250 3400 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7250 3600 50  0001 C CNN
F 3 "~" H 7250 3600 50  0001 C CNN
	1    7250 3600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR043
U 1 1 60732230
P 7000 3800
F 0 "#PWR043" H 7000 3550 50  0001 C CNN
F 1 "GND" H 7005 3627 50  0000 C CNN
F 2 "" H 7000 3800 50  0001 C CNN
F 3 "" H 7000 3800 50  0001 C CNN
	1    7000 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 3800 7000 3700
Wire Wire Line
	7000 3700 7050 3700
Wire Wire Line
	6650 3400 6650 3450
Wire Wire Line
	6650 3450 6850 3450
Wire Wire Line
	6850 3450 6850 3600
Wire Wire Line
	6850 4000 6650 4000
Wire Wire Line
	6650 4000 6650 3950
Wire Wire Line
	6650 4500 6650 4550
Wire Wire Line
	6650 4550 6850 4550
Wire Wire Line
	6850 4550 6850 4000
Connection ~ 6850 4000
Wire Wire Line
	6650 5050 6650 5100
Wire Wire Line
	6650 5100 6850 5100
Wire Wire Line
	6850 5100 6850 4550
Connection ~ 6850 4550
Wire Wire Line
	7050 3600 6850 3600
Connection ~ 6850 3600
Wire Wire Line
	6850 3600 6850 4000
$Comp
L power:GND #PWR021
U 1 1 607E1EAE
P 3800 4750
F 0 "#PWR021" H 3800 4500 50  0001 C CNN
F 1 "GND" H 3805 4577 50  0000 C CNN
F 2 "" H 3800 4750 50  0001 C CNN
F 3 "" H 3800 4750 50  0001 C CNN
	1    3800 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 4750 3800 4700
Wire Wire Line
	3800 4100 3800 4050
$Comp
L Device:C C10
U 1 1 605713F6
P 6400 1100
F 0 "C10" H 6515 1146 50  0000 L CNN
F 1 "100n" H 6515 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6438 950 50  0001 C CNN
F 3 "~" H 6400 1100 50  0001 C CNN
	1    6400 1100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR041
U 1 1 60571FD9
P 6400 1300
F 0 "#PWR041" H 6400 1050 50  0001 C CNN
F 1 "GND" H 6405 1127 50  0000 C CNN
F 2 "" H 6400 1300 50  0001 C CNN
F 3 "" H 6400 1300 50  0001 C CNN
	1    6400 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 1300 6400 1250
$Comp
L power:Vdrive #PWR040
U 1 1 60593C04
P 6400 850
F 0 "#PWR040" H 6200 700 50  0001 C CNN
F 1 "Vdrive" H 6415 1023 50  0000 C CNN
F 2 "" H 6400 850 50  0001 C CNN
F 3 "" H 6400 850 50  0001 C CNN
	1    6400 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 850  6400 950 
Text Notes 6450 900  0    25   Italic 0
FAN3122
Wire Wire Line
	4800 1300 4800 1250
$Comp
L power:GND #PWR028
U 1 1 60571BDD
P 4800 1300
F 0 "#PWR028" H 4800 1050 50  0001 C CNN
F 1 "GND" H 4805 1127 50  0000 C CNN
F 2 "" H 4800 1300 50  0001 C CNN
F 3 "" H 4800 1300 50  0001 C CNN
	1    4800 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 6057104E
P 4800 1100
F 0 "C6" H 4915 1146 50  0000 L CNN
F 1 "100n" H 4915 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 4838 950 50  0001 C CNN
F 3 "~" H 4800 1100 50  0001 C CNN
	1    4800 1100
	1    0    0    -1  
$EndComp
Connection ~ 4800 900 
Wire Wire Line
	4800 900  5200 900 
$Comp
L Device:C C9
U 1 1 6089F022
P 6000 1100
F 0 "C9" H 6115 1146 50  0000 L CNN
F 1 "100n" H 6115 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6038 950 50  0001 C CNN
F 3 "~" H 6000 1100 50  0001 C CNN
	1    6000 1100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR037
U 1 1 6089F028
P 6000 1300
F 0 "#PWR037" H 6000 1050 50  0001 C CNN
F 1 "GND" H 6005 1127 50  0000 C CNN
F 2 "" H 6000 1300 50  0001 C CNN
F 3 "" H 6000 1300 50  0001 C CNN
	1    6000 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 1300 6000 1250
Wire Wire Line
	6000 900  6000 950 
Wire Wire Line
	5600 900  6000 900 
$Comp
L Analog_DAC:MCP4728 DD4
U 1 1 6090378B
P 4550 3350
F 0 "DD4" H 4100 3600 50  0000 C CNN
F 1 "MCP4728" H 4850 3600 50  0000 C CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 4550 2750 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22187E.pdf" H 4550 3600 50  0001 C CNN
	1    4550 3350
	1    0    0    -1  
$EndComp
Text Notes 5900 900  0    25   Italic 0
LVM324M
$Comp
L power:+3V3 #PWR010
U 1 1 6093C3C7
P 2100 1950
F 0 "#PWR010" H 2100 1800 50  0001 C CNN
F 1 "+3V3" H 2115 2123 50  0000 C CNN
F 2 "" H 2100 1950 50  0001 C CNN
F 3 "" H 2100 1950 50  0001 C CNN
	1    2100 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR026
U 1 1 6093C93B
P 4550 3000
F 0 "#PWR026" H 4550 2850 50  0001 C CNN
F 1 "+5V" H 4565 3173 50  0000 C CNN
F 2 "" H 4550 3000 50  0001 C CNN
F 3 "" H 4550 3000 50  0001 C CNN
	1    4550 3000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR020
U 1 1 6093D002
P 3800 4050
F 0 "#PWR020" H 3800 3900 50  0001 C CNN
F 1 "+5V" H 3815 4223 50  0000 C CNN
F 2 "" H 3800 4050 50  0001 C CNN
F 3 "" H 3800 4050 50  0001 C CNN
	1    3800 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV1
U 1 1 6093E24D
P 5350 3500
F 0 "RV1" H 5500 3600 50  0000 C CNN
F 1 "1k" H 5450 3400 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_1x03_P1.27mm_Vertical" H 5350 3500 50  0001 C CNN
F 3 "~" H 5350 3500 50  0001 C CNN
	1    5350 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 2950 5650 3500
Wire Wire Line
	5150 3250 5350 3250
Wire Wire Line
	5350 3250 5350 3350
$Comp
L power:GND #PWR031
U 1 1 6097B447
P 5350 3750
F 0 "#PWR031" H 5350 3500 50  0001 C CNN
F 1 "GND" H 5355 3577 50  0000 C CNN
F 2 "" H 5350 3750 50  0001 C CNN
F 3 "" H 5350 3750 50  0001 C CNN
	1    5350 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 3750 5350 3650
Wire Wire Line
	5500 3500 5650 3500
$Comp
L power:+5V #PWR033
U 1 1 6099AB95
P 5600 850
F 0 "#PWR033" H 5600 700 50  0001 C CNN
F 1 "+5V" H 5615 1023 50  0000 C CNN
F 2 "" H 5600 850 50  0001 C CNN
F 3 "" H 5600 850 50  0001 C CNN
	1    5600 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 850  5600 900 
Connection ~ 5600 900 
Wire Notes Line
	3350 2750 7400 2750
Wire Notes Line
	7400 2750 7400 5150
Wire Notes Line
	7400 5150 3350 5150
Wire Notes Line
	3350 5150 3350 2750
Text Notes 3400 2750 0    50   Italic 10
Analog
Wire Notes Line
	4200 600  6750 600 
Wire Notes Line
	6750 600  6750 1550
Wire Notes Line
	6750 1550 4200 1550
Wire Notes Line
	4200 1550 4200 600 
Text Notes 4250 600  0    50   Italic 10
Caps
$Comp
L Connector:TestPoint TP1
U 1 1 60AB6E55
P 1200 6350
F 0 "TP1" H 1142 6376 50  0000 R CNN
F 1 "5V" H 1142 6467 50  0000 R CNN
F 2 "TestPoint:TestPoint_Keystone_5000-5004_Miniature" H 1400 6350 50  0001 C CNN
F 3 "~" H 1400 6350 50  0001 C CNN
	1    1200 6350
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR04
U 1 1 60AD5718
P 1200 6250
F 0 "#PWR04" H 1200 6100 50  0001 C CNN
F 1 "+5V" H 1215 6423 50  0000 C CNN
F 2 "" H 1200 6250 50  0001 C CNN
F 3 "" H 1200 6250 50  0001 C CNN
	1    1200 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 6350 1200 6300
$Comp
L Device:R R2
U 1 1 60AE5917
P 1000 6300
F 0 "R2" V 900 6250 50  0000 L CNN
F 1 "300R" V 1100 6200 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 930 6300 50  0001 C CNN
F 3 "~" H 1000 6300 50  0001 C CNN
	1    1000 6300
	0    1    1    0   
$EndComp
$Comp
L Device:LED VD1
U 1 1 60AE69E6
P 800 6500
F 0 "VD1" V 800 6400 50  0000 R CNN
F 1 "LED" V 700 6400 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 800 6500 50  0001 C CNN
F 3 "~" H 800 6500 50  0001 C CNN
	1    800  6500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	850  6300 800  6300
Wire Wire Line
	800  6300 800  6350
$Comp
L power:GND #PWR02
U 1 1 60AF74FA
P 800 6750
F 0 "#PWR02" H 800 6500 50  0001 C CNN
F 1 "GND" H 805 6577 50  0000 C CNN
F 2 "" H 800 6750 50  0001 C CNN
F 3 "" H 800 6750 50  0001 C CNN
	1    800  6750
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  6750 800  6650
$Comp
L Connector:TestPoint TP2
U 1 1 60B07DF3
P 1500 6350
F 0 "TP2" H 1442 6376 50  0000 R CNN
F 1 "3V3" H 1442 6467 50  0000 R CNN
F 2 "TestPoint:TestPoint_Keystone_5000-5004_Miniature" H 1700 6350 50  0001 C CNN
F 3 "~" H 1700 6350 50  0001 C CNN
	1    1500 6350
	-1   0    0    1   
$EndComp
$Comp
L power:+3V3 #PWR06
U 1 1 60B08180
P 1500 6250
F 0 "#PWR06" H 1500 6100 50  0001 C CNN
F 1 "+3V3" H 1515 6423 50  0000 C CNN
F 2 "" H 1500 6250 50  0001 C CNN
F 3 "" H 1500 6250 50  0001 C CNN
	1    1500 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 6250 1500 6350
$Comp
L Connector:TestPoint TP5
U 1 1 60B1A55C
P 1800 6350
F 0 "TP5" H 1742 6376 50  0000 R CNN
F 1 "Driver" H 1742 6467 50  0000 R CNN
F 2 "TestPoint:TestPoint_Keystone_5000-5004_Miniature" H 2000 6350 50  0001 C CNN
F 3 "~" H 2000 6350 50  0001 C CNN
	1    1800 6350
	-1   0    0    1   
$EndComp
Wire Wire Line
	1800 6250 1800 6350
$Comp
L power:Vdrive #PWR07
U 1 1 60B2A48F
P 1800 6250
F 0 "#PWR07" H 1600 6100 50  0001 C CNN
F 1 "Vdrive" H 1815 6423 50  0000 C CNN
F 2 "" H 1800 6250 50  0001 C CNN
F 3 "" H 1800 6250 50  0001 C CNN
	1    1800 6250
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint_2Pole TP3
U 1 1 60B2BC01
P 1500 6800
F 0 "TP3" H 1500 6900 50  0000 C CNN
F 1 "I2C" H 1500 6700 50  0000 C CNN
F 2 "TestPoint:TestPoint_2Pads_Pitch2.54mm_Drill0.8mm" H 1500 6800 50  0001 C CNN
F 3 "~" H 1500 6800 50  0001 C CNN
	1    1500 6800
	1    0    0    -1  
$EndComp
Text Label 1750 6800 0    50   ~ 0
SDA
Text Label 1100 6800 0    50   ~ 0
SCL
Wire Wire Line
	1750 6800 1700 6800
Wire Wire Line
	1300 6800 1100 6800
Wire Wire Line
	1150 6300 1200 6300
Connection ~ 1200 6300
Wire Wire Line
	1200 6300 1200 6250
$Comp
L Connector:TestPoint_2Pole TP4
U 1 1 60B5FA03
P 1500 7100
F 0 "TP4" H 1500 7200 50  0000 C CNN
F 1 "UART" H 1500 7000 50  0000 C CNN
F 2 "TestPoint:TestPoint_2Pads_Pitch2.54mm_Drill0.8mm" H 1500 7100 50  0001 C CNN
F 3 "~" H 1500 7100 50  0001 C CNN
	1    1500 7100
	1    0    0    -1  
$EndComp
Text Label 1750 7100 0    50   ~ 0
RX
Text Label 1100 7100 0    50   ~ 0
TX
Wire Wire Line
	1100 7100 1300 7100
Wire Wire Line
	1750 7100 1700 7100
Wire Notes Line
	650  6000 2400 6000
Wire Notes Line
	2400 6000 2400 7250
Wire Notes Line
	2400 7250 650  7250
Wire Notes Line
	650  7250 650  6000
Text Notes 700  6000 0    50   Italic 10
TestPoints
Wire Wire Line
	8100 1350 8250 1350
$Comp
L mine:STM32F103C8_BluePill DD1
U 1 1 60C48B1F
P 2100 4050
F 0 "DD1" H 1550 5500 50  0000 C CNN
F 1 "STM32F103C8_BluePill" H 2650 5500 50  0000 C CNN
F 2 "mine:STM32F103C8_BluePill" H 1500 2650 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00161566.pdf" H 2100 4050 50  0001 C CNN
	1    2100 4050
	1    0    0    -1  
$EndComp
$Comp
L Memory_EEPROM:24LC512 DD2
U 1 1 60C4DF60
P 3200 6950
F 0 "DD2" H 2950 7200 50  0000 C CNN
F 1 "24LC512" H 3400 7200 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 3200 6950 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21754M.pdf" H 3200 6950 50  0001 C CNN
	1    3200 6950
	1    0    0    -1  
$EndComp
$Comp
L mine:FAN3122 DD5
U 1 1 60C4F5DA
P 7400 1200
F 0 "DD5" H 7350 1400 50  0000 L CNN
F 1 "FAN3122" H 7900 1400 50  0000 L CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 7800 150 50  0001 C CNN
F 3 "" H 7400 1200 50  0001 C CNN
	1    7400 1200
	1    0    0    -1  
$EndComp
$Comp
L Interface_UART:MAX232 DD6
U 1 1 60C57F18
P 9450 4300
F 0 "DD6" H 8900 5350 50  0000 C CNN
F 1 "ADM3202" H 9850 5350 50  0000 C CNN
F 2 "Package_SO:SO-16_3.9x9.9mm_P1.27mm" H 9500 3250 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/max232.pdf" H 9450 4400 50  0001 C CNN
	1    9450 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 4800 8650 4800
Wire Wire Line
	1000 5050 1400 5050
Wire Wire Line
	1400 5150 1000 5150
Wire Wire Line
	1000 5250 1400 5250
Wire Wire Line
	2750 4350 2700 4350
Text Label 2750 4350 0    50   ~ 0
ADC_Analog
Wire Wire Line
	2750 5050 2700 5050
$Comp
L Connector:TestPoint TP6
U 1 1 60DEF490
P 2150 6300
F 0 "TP6" H 2208 6418 50  0000 L CNN
F 1 "GND" H 2208 6327 50  0000 L CNN
F 2 "TestPoint:TestPoint_Keystone_5000-5004_Miniature" H 2350 6300 50  0001 C CNN
F 3 "~" H 2350 6300 50  0001 C CNN
	1    2150 6300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 60E1FD79
P 2150 6400
F 0 "#PWR012" H 2150 6150 50  0001 C CNN
F 1 "GND" H 2155 6227 50  0000 C CNN
F 2 "" H 2150 6400 50  0001 C CNN
F 3 "" H 2150 6400 50  0001 C CNN
	1    2150 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 6400 2150 6300
NoConn ~ 8650 4600
NoConn ~ 8650 5000
NoConn ~ 10250 5000
NoConn ~ 10250 4600
NoConn ~ 2700 5350
NoConn ~ 2700 4650
NoConn ~ 2700 4250
NoConn ~ 2700 4150
NoConn ~ 1400 5350
NoConn ~ 1400 3950
NoConn ~ 1400 3850
NoConn ~ 1400 3450
NoConn ~ 1900 2550
NoConn ~ 2000 2550
$Comp
L power:PWR_FLAG #FLG03
U 1 1 607CDBF1
P 2200 2450
F 0 "#FLG03" H 2200 2525 50  0001 C CNN
F 1 "PWR_FLAG" V 2250 2600 50  0000 L CNN
F 2 "" H 2200 2450 50  0001 C CNN
F 3 "~" H 2200 2450 50  0001 C CNN
	1    2200 2450
	0    1    1    0   
$EndComp
$Comp
L power:PWR_FLAG #FLG04
U 1 1 607CE253
P 10950 1900
F 0 "#FLG04" H 10950 1975 50  0001 C CNN
F 1 "PWR_FLAG" H 11150 2000 50  0000 C CNN
F 2 "" H 10950 1900 50  0001 C CNN
F 3 "~" H 10950 1900 50  0001 C CNN
	1    10950 1900
	-1   0    0    1   
$EndComp
Connection ~ 10950 1900
NoConn ~ 5150 3350
NoConn ~ 5150 3450
NoConn ~ 5150 3550
NoConn ~ 8100 1450
NoConn ~ 2700 4050
$Comp
L power:PWR_FLAG #FLG01
U 1 1 608463EF
P 1400 900
F 0 "#FLG01" H 1400 975 50  0001 C CNN
F 1 "PWR_FLAG" H 1400 1073 50  0000 C CNN
F 2 "" H 1400 900 50  0001 C CNN
F 3 "~" H 1400 900 50  0001 C CNN
	1    1400 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 900  3300 900 
Wire Wire Line
	3300 950  3300 900 
Connection ~ 3300 900 
Wire Wire Line
	3300 900  3750 900 
Wire Wire Line
	1400 1250 1400 1350
Wire Wire Line
	2100 2350 2100 2400
Wire Wire Line
	2200 2450 2200 2550
Wire Wire Line
	1800 2450 2200 2450
Connection ~ 2200 2450
$Comp
L power:PWR_FLAG #FLG02
U 1 1 608B3210
P 2100 2400
F 0 "#FLG02" H 2100 2475 50  0001 C CNN
F 1 "PWR_FLAG" V 2100 2528 50  0000 L CNN
F 2 "" H 2100 2400 50  0001 C CNN
F 3 "~" H 2100 2400 50  0001 C CNN
	1    2100 2400
	0    1    1    0   
$EndComp
Connection ~ 2100 2400
Wire Wire Line
	2100 2400 2100 2550
Wire Wire Line
	2650 1200 2650 1350
$Comp
L Connector_Generic:Conn_01x04 J3
U 1 1 60580833
P 5900 2100
F 0 "J3" H 5850 2300 50  0000 L CNN
F 1 "OLED" H 5800 1800 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5900 2100 50  0001 C CNN
F 3 "~" H 5900 2100 50  0001 C CNN
	1    5900 2100
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR035
U 1 1 60580839
P 5600 1900
F 0 "#PWR035" H 5600 1750 50  0001 C CNN
F 1 "+3V3" H 5615 2073 50  0000 C CNN
F 2 "" H 5600 1900 50  0001 C CNN
F 3 "" H 5600 1900 50  0001 C CNN
	1    5600 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR036
U 1 1 6058083F
P 5600 2400
F 0 "#PWR036" H 5600 2150 50  0001 C CNN
F 1 "GND" H 5605 2227 50  0000 C CNN
F 2 "" H 5600 2400 50  0001 C CNN
F 3 "" H 5600 2400 50  0001 C CNN
	1    5600 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2400 5600 2300
Wire Wire Line
	5600 2300 5700 2300
Wire Wire Line
	5700 2000 5600 2000
Wire Wire Line
	5600 2000 5600 1900
Text Label 5500 2100 0    50   ~ 0
SCL
Text Label 5500 2200 0    50   ~ 0
SDA
Wire Wire Line
	5500 2100 5700 2100
Wire Wire Line
	5700 2200 5500 2200
Wire Notes Line
	5450 1650 6050 1650
Wire Notes Line
	6050 1650 6050 2650
Wire Notes Line
	6050 2650 5450 2650
Wire Notes Line
	5450 2650 5450 1650
Text Notes 5500 1650 0    50   Italic 10
OLED
$Comp
L Connector_Generic:Conn_01x09 J2
U 1 1 60593961
P 4050 1900
F 0 "J2" V 4150 2300 50  0000 C CNN
F 1 "miniKeyboard_v0.1" V 4150 1750 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x09_P2.54mm_Vertical" H 4050 1900 50  0001 C CNN
F 3 "~" H 4050 1900 50  0001 C CNN
	1    4050 1900
	0    -1   -1   0   
$EndComp
$Comp
L power:+3V3 #PWR018
U 1 1 605BA294
P 3450 2050
F 0 "#PWR018" H 3450 1900 50  0001 C CNN
F 1 "+3V3" H 3465 2223 50  0000 C CNN
F 2 "" H 3450 2050 50  0001 C CNN
F 3 "" H 3450 2050 50  0001 C CNN
	1    3450 2050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR025
U 1 1 605BA8DD
P 4450 2150
F 0 "#PWR025" H 4450 1900 50  0001 C CNN
F 1 "GND" H 4455 1977 50  0000 C CNN
F 2 "" H 4450 2150 50  0001 C CNN
F 3 "" H 4450 2150 50  0001 C CNN
	1    4450 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 2050 3450 2150
Wire Wire Line
	3450 2150 3650 2150
Wire Wire Line
	3650 2150 3650 2100
Wire Wire Line
	4450 2150 4450 2100
$Comp
L Device:R R1
U 1 1 6040B19D
P 750 4750
F 0 "R1" H 820 4796 50  0000 L CNN
F 1 "2k" H 820 4705 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 680 4750 50  0001 C CNN
F 3 "~" H 750 4750 50  0001 C CNN
	1    750  4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	750  4950 1400 4950
Text Label 1000 4450 0    50   ~ 0
Button_1
Text Label 1000 4550 0    50   ~ 0
Button_2
Text Label 1000 4650 0    50   ~ 0
Button_3
Text Label 1000 4750 0    50   ~ 0
Button_4
Text Label 2750 3950 0    50   ~ 0
Button_5
Text Label 1000 3650 0    50   ~ 0
Button_6
Text Label 1000 3550 0    50   ~ 0
Button_7
Wire Wire Line
	2750 3950 2700 3950
Wire Wire Line
	1400 3650 1000 3650
Wire Wire Line
	1000 3550 1400 3550
Wire Wire Line
	1000 4450 1400 4450
Wire Wire Line
	1400 4550 1000 4550
Wire Wire Line
	1000 4650 1400 4650
Wire Wire Line
	1400 4750 1000 4750
Text Label 3750 2500 1    50   ~ 0
Button_1
Text Label 3850 2500 1    50   ~ 0
Button_2
Text Label 3950 2500 1    50   ~ 0
Button_3
Text Label 4150 2500 1    50   ~ 0
Button_5
Text Label 4050 2500 1    50   ~ 0
Button_4
Text Label 4250 2500 1    50   ~ 0
Button_6
Text Label 4350 2500 1    50   ~ 0
Button_7
Wire Wire Line
	4350 2500 4350 2100
Wire Wire Line
	4250 2100 4250 2500
Wire Wire Line
	4150 2500 4150 2100
Wire Wire Line
	4050 2100 4050 2500
Wire Wire Line
	3950 2500 3950 2100
Wire Wire Line
	3850 2100 3850 2500
Wire Wire Line
	3750 2500 3750 2100
Wire Notes Line
	3350 1700 4600 1700
Wire Notes Line
	4600 1700 4600 2550
Wire Notes Line
	4600 2550 3350 2550
Wire Notes Line
	3350 2550 3350 1700
Text Notes 3400 1700 0    50   Italic 10
miniKeyboard_v0.1
$Comp
L Regulator_Switching:MC34063AD DA2
U 1 1 6042760F
P 9600 1600
F 0 "DA2" H 9350 1950 50  0000 C CNN
F 1 "MC34063AD" H 9750 1950 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 9650 1150 50  0001 L CNN
F 3 "http://www.onsemi.com/pub_link/Collateral/MC34063A-D.PDF" H 10100 1500 50  0001 C CNN
	1    9600 1600
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky VD4
U 1 1 6046322D
P 10550 1750
F 0 "VD4" V 10596 1670 50  0000 R CNN
F 1 "D_Sch" V 10505 1670 50  0000 R CNN
F 2 "Diode_SMD:D_0603_1608Metric" H 10550 1750 50  0001 C CNN
F 3 "~" H 10550 1750 50  0001 C CNN
	1    10550 1750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10150 2300 10150 2250
Wire Wire Line
	10100 2300 10150 2300
Wire Wire Line
	10100 2300 10100 2350
$Comp
L power:GND #PWR053
U 1 1 6047467F
P 10100 2350
F 0 "#PWR053" H 10100 2100 50  0001 C CNN
F 1 "GND" H 10105 2177 50  0000 C CNN
F 2 "" H 10100 2350 50  0001 C CNN
F 3 "" H 10100 2350 50  0001 C CNN
	1    10100 2350
	1    0    0    -1  
$EndComp
Connection ~ 10100 2300
Wire Wire Line
	10050 2300 10100 2300
Wire Wire Line
	10050 1800 10000 1800
Wire Wire Line
	10050 1800 10050 2300
Wire Wire Line
	10000 1600 10550 1600
Wire Wire Line
	10100 1500 10000 1500
Wire Wire Line
	10450 1400 10450 1500
Wire Wire Line
	10450 1500 10400 1500
Wire Wire Line
	10550 1550 10550 1600
Connection ~ 10550 1600
Wire Wire Line
	10450 1100 10450 1400
Wire Wire Line
	9650 1100 10450 1100
Connection ~ 10450 1400
Wire Wire Line
	10450 950  10450 1100
Wire Wire Line
	9950 950  10450 950 
Connection ~ 10450 1100
$Comp
L Device:R R16
U 1 1 6043100C
P 10250 1500
F 0 "R16" V 10350 1500 50  0000 C CNN
F 1 "180" V 10150 1500 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 10180 1500 50  0001 C CNN
F 3 "~" H 10250 1500 50  0001 C CNN
	1    10250 1500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10000 1400 10450 1400
$Comp
L Device:L L1
U 1 1 60429EED
P 10550 1400
F 0 "L1" H 10650 1450 50  0000 C CNN
F 1 "57u" H 10650 1350 50  0000 C CNN
F 2 "Inductor_SMD:L_7.3x7.3_H4.5" H 10550 1400 50  0001 C CNN
F 3 "~" H 10550 1400 50  0001 C CNN
	1    10550 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	10550 1250 10550 1100
Wire Wire Line
	10550 1100 10450 1100
$Comp
L Device:R R6
U 1 1 6056E8EE
P 5350 4300
F 0 "R6" H 5200 4250 50  0000 L CNN
F 1 "1k" H 5200 4350 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5280 4300 50  0001 C CNN
F 3 "~" H 5350 4300 50  0001 C CNN
	1    5350 4300
	-1   0    0    1   
$EndComp
$Comp
L Device:R R7
U 1 1 6056ED37
P 5350 4700
F 0 "R7" H 5200 4650 50  0000 L CNN
F 1 "2k" H 5200 4750 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5280 4700 50  0001 C CNN
F 3 "~" H 5350 4700 50  0001 C CNN
	1    5350 4700
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR032
U 1 1 60585EE2
P 5350 4900
F 0 "#PWR032" H 5350 4650 50  0001 C CNN
F 1 "GND" H 5355 4727 50  0000 C CNN
F 2 "" H 5350 4900 50  0001 C CNN
F 3 "" H 5350 4900 50  0001 C CNN
	1    5350 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 4900 5350 4850
Wire Wire Line
	5350 4450 5350 4500
Text Label 4850 4500 0    50   ~ 0
ADC_Analog
Wire Wire Line
	4850 4500 5350 4500
Connection ~ 5350 4500
Wire Wire Line
	5350 4500 5350 4550
Wire Wire Line
	5350 4150 5350 4050
Wire Wire Line
	5350 4050 5650 4050
$EndSCHEMATC
