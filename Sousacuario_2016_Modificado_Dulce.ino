///*****************************************************************************************************************************************************
//......................................................................................................................................................
//...............           .           ...           .....         . .....     ..... .   ...     ...     .....     .....           ....................
//..............                                       ...             . .       ....      .       .         .       ...     ...     . .................
//.............  2@B@B@B@B@.  @B@B@B@B@B,  N@B@B@@@BN:  . iB@B@B@@@B5:     .@@@i .... vB@@   .@B@i   N@B@B:   . OB@;  .  :qB@@@B@BM7   .................
//.............  ZB@BXqGZ8Z  .B@BMX00GGM.  BB@BXNZB@B@q   r@@@N00MB@B@B:   ,B@Br ...  L@B@   .B@B7   @B@B@B:    B@B7    8@B@M1JUO@B@B: .................
//.............  S@BO         @B@.         G@Bk    j@B@.  iB@B     ,@B@B.  .@B@:  ... vB@B   .@B@i   O@@YB@B.   M@@i   B@B@.      BB@B  ................
//.............  XB@O         @@B:         8B@F    J@@B   i@B@       @B@G  .B@Bi ...  7@B@   .B@Bi   MB@ rB@B   G@@i  r@B@,       .@B@v  ...............
//.............  F@B@q8OMB5   @B@B@B@@@,   Z@BBJ2UMB@B:   iB@@  . .  P@B@  .@B@i  ... vB@B   .@B@i   M@@, E@@B  GB@i  qB@B  .....  B@BN  ...............
//.............. kB@B@@@B@M   B@@8XZGOO.   8B@B@B@B@v     i@B@   .   qB@B  .B@B: ...  r@B@   .B@B;   MB@:  MB@G S@Bi  q@B@   ...   @B@k  ...............
//.............  S@BM         @B@,         Z@Bq  :@@@5    iB@B       B@BZ  .@B@:      7B@B   .@B@i   O@Bi   @B@7uB@i  uB@@.   .   ,@@B7 ................
//.............  kB@M      .  B@B:         8B@N   :@B@Y   i@@@      O@B@.   B@@0      M@BM   .B@B;   MB@i    @@@B@@i  .@B@G       B@B@   ...............
//.............  q@@@   ....  @B@Nju1UFk.  M@BM    1@B@:  rB@B2u1X@B@B@:    r@@B@Jrr2B@B@.   .@B@r   B@Br    ,@B@B@r   i@B@BS777NB@@@   ................
//.............. NB@B  ..... .B@B@B@B@@@:  MB@O  .  B@B@  i@B@B@B@B@q;   ..  ,P@B@B@B@Bu   . ,@@B7   @@@;  .  i@B@Bi     1B@B@B@B@O7   .................
//.............   ..  .......   . ... ..    ..  ...  ...   ..   .       ....    .:::,     ... ...     ..  ...   . .  ..     ,:::.     ..................
//..............     .........           .     .....     .           ....... .         . ....     ..     .....     .......         .....................
//................................... ................. ......... ............... . ........... ................. ........... . . ......................
//******************************************************************************************************************************************************
//***********************              Desenvolvido por Fernando Garcia         ************************************************************************
//******************************************************************************************************************************************************
//******* Dúvidas, sugestões e elogios: info@ferduino.com **********************************************************************************************
//******************************************************************************************************************************************************

// Este programa é compatível com a IDE 1.6.7 e 1.0.6

// As funções para controle via web foram implementadas graças à preciosa ajuda do Simone Grimaldi e Danilo Castellano.

//---------------------------------------------------------

// Este programa foi desenvolvido com base na versão Stilo 2.1
// Disponível nesta página http://code.google.com/p/stilo/

//-----------------------------------------------------------
// Este programa é software livre; Você pode redistribuí-lo e/ou
// modificá-lo sob os termos da GNU General Public License
// como publicada pela Free Software Foundation versão 3
// da licença, ou (por sua opção) qualquer versão posterior.
// Este programa é distribuído na esperança que seja útil,
// mas sem qualquer garantia; sem mesmo a garantia implícita de
// comercialização ou propósito particular. Consulte o
// GNU General Public License para mais detalhes.

//*************************************************************************************************
//*************** Selecionar idioma ***************************************************************
//*************************************************************************************************

// Descomente a linha correspondente ao seu idioma.
// Uncomment the line corresponding to your language.

//#define ENGLISH    // If this program is useful for you, make a donation to help with development. Paypal: fefegarcia_1@hotmail.com
//#define FRENCH     // Si ce programme est utile pour vous, faire un don pour aider au développement. Paypal: fefegarcia_1@hotmail.com
//#define GERMAN     // Wenn dieses Programm ist nützlich für Sie, eine Spende an mit Entwicklung zu helfen. Paypal: fefegarcia_1@hotmail.com
//#define ITALIAN    // Se questo programma vi è utile, fate una donazione per aiutare con il suo sviluppo. Paypal: fefegarcia_1@hotmail.com
//#define PORTUGUESE   // Se este programa é útil para você, faça uma doação para ajudar no desenvolvimento. Paypal: fefegarcia_1@hotmail.com
#define SPANISH    // Si este programa es útil para usted, hacer una donación para ayudar con el desarrollo. Paypal: fefegarcia_1@hotmail.com

//*************************************************************************************************
//**************************** ATIVAR OU DESATIVAR FUNÇÕES  ***************************************
//**************************** ENABLE OR DISABLE FUNCTIONS ****************************************
//*************************************************************************************************
// Comment the line below to disable watchdog
//#define WATCHDOG // Reseta o controlador se a função "wdt_reset()" não for executada em até 8 segundos.
// Essa função minimiza problemas com o travamento do código mas, pode apresentar incompatibilidades com alguns bootloaders

// Comment the line below to disable ethernet functions
#define ETHERNET_SHIELD // Comente esta linha para desativar as funções do ethernet shield.

// Comment this two lines below if have not stamps
// Comente as duas linhas abaixo se não tiver stamps
//#define STAMPS_V4X     // Comente esta linha para usar Stamps EZO
//#define STAMPS_EZO     // Descomente esta linha para usar Stamps EZO

// Comment this two lines below if have not RFM12B wireless transceiver
//#define RFM12B_LED_CONTROL   // Descomente esta linha para controlar os LEDs via RF
//#define RFM12B_RELAY_CONTROL // Descomente esta linha  para controlar os relês via RF


// Comment the line below if have not a PCF8575
//#define USE_PCF8575 // Descomente essa linha para usar um PCF8575

// Comente esta linha para desativar as mensagens no monitor serial ou para usar os pinos 0 e 1 (RX e TX) como OUTPUT
// Comment this line to disable the messages on serial monitor or to use pins 0 and 1 (RX e TX) as OUTPUT
//#define DEBUG  // Comente esta linha para usar os pinos 0 e 1 para controle dos coolers e buzzer.

// Comment the line below to disable this function
// Comente a linha abaixo para desativar esta função
//#define DISABLE_SKIMMER // Desliga o skimmer caso o nível no compartimento esteja alto.
// Evita transbordamento do skimmer caso a bomba de retorno seja desligada

// Comment this line to enable password screen
// Comente esta linha para ativar a solicitação de senha.
//#define SKIP_PASSWORD_SCREEN // comente esta linha se deseja solicitar uma senha após o primeiro toque no TFT

// Comment this line to use static IP.
// Comente esta linha para usar IP estático
#define USE_DHCP // Descomente esta linha para usar DHCP

// Uncomment the line below to use screensaver
// Descomente a linha abaixo para ativar o protetor de tela
#define USE_SCREENSAVER

// Comment the line below to disable night mode for stream pumps
// Comente a linha abaixo para desativar o modo noturno para bombas de circulação.
//#define NIGHT_MODE // Reduz a potência das bombas de circulação quando os LEDs estão desligados.

// Uncomment the line below to use temperature in Fahrenheit.
//#define USE_FAHRENHEIT // Descomente esta linha para usar temperatura em Fahrenheit 

// Comment the line bellow if you don't want use a TFT. This function works only with IDE 1.6.7.
#define USE_TFT // Comente esta linha se você não quer usar um TFT. Estão função funciona apenas com a IDE 1.6.7.
//*************************************************************************************************
//*************** Bibliotecas utilizadas **********************************************************
//*************************************************************************************************
#ifdef USE_TFT
#include <UTFT.h>
#include <UTouch.h>
#endif
#include <Wire.h>
#include <EEPROM.h>
#include <writeAnything.h>
#include <DS1307_HENNING.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SdFat.h>
#include <SdFatUtil.h>
#include <avr/pgmspace.h>

#ifdef USE_PCF8575 // Do not change this line!
#include <PCF8575.h>
#endif // Do not change this line!

#if defined(RFM12B_LED_CONTROL) || defined(RFM12B_RELAY_CONTROL) // Do not change this line!
#include <RFM12B.h>
#endif // Do not change this line!

#ifdef ETHERNET_SHIELD // Do not change this line!
#include <Base64.h>
#include <SPI.h>
#include <Ethernet.h>
#endif // Do not change this line!

#ifdef WATCHDOG // Do not change this line!
#include <avr/wdt.h>
#endif // Do not change this line!

//*************************************************************************************************
//************************* Atualizações **********************************************************
//*************************************************************************************************
const char lastUpdate[] = "01/10/2016"; // Data da última modificação

//****************************************************************************************************
//****************** Variáveis de textos e fontes ****************************************************
//****************************************************************************************************
#ifdef USE_TFT
#define LARGE false
#define SMALL true
extern uint8_t RusFont1[];    // Declara que fontes vamos usar
extern uint8_t BigFont[];     // Declara que fontes vamos usar
#endif
char buffer[50];

#ifdef USE_SCREENSAVER
extern uint8_t SevenSegNumFontPlus[];
#endif

//****************************************************************************************************
//****************** Define funções dos pinos digitais e analógicos **********************************
//****************************************************************************************************
// Pinos 0 e 1 reservados para a porta serial 0.
int lectura; //Variable en la que guardaremos el valor del fotoresistor
const byte alarmPin = 0;          // Pino que aciona o alarme
const byte desativarFanPin = 1;   // Pino que desativa os coolers.
// Pino 2 reservado para INT do RFM12B.
// Pinos 3, 4, 5, 6 e 7 reservados para o touch.
// Pino 5 também é o chip select do cartão SD.
const byte ledPinWhite = 14;     // Pino que liga os leds  4000K
const byte ledPinBlue = 15;       // Pino que liga os leds  6500K
const byte ledPinRoyBlue = 16;   // Pino que liga os leds 10.000K
//const byte ledPinUV = 12;         // Pino que liga os leds AZULES 
//const byte ledPinRed = 11;       // Pino que liga os leds ROJOS
const byte fanPin = 8;          // Pino que controla a velocidade das ventoinhas do dissipador
// Pinos 14 e 15 reservados para a porta serial 3 que se comunica com os "Stamps"
//const byte multiplexadorS0Pin = 16; // Pino S0 de controle dos stamps
//const byte multiplexadorS1Pin = 17; // Pino S1 de controle dos stamps
// Pinos 18 e 19 reservados para o RTC.
// Pinos 20 e 21 reservados para comunicação I2C do PCF8575.
// Pinos 22 à 41 reservados para o LCD.
//const byte desativarFonte = 42;  // Pin que controla la fuente de alimentacion luces para leds pin original de la pcb 2.4
const byte calentadorPin = 42;   // Pin que liga o calentador del acuario
const byte ledPinMoon = 17;      // Pin que liga os leds da luz noturna
const byte Co2 = 45;            // Pin que liga o CO2 del acuario
//pin 46pwm libre (futura ampliacion canal led )
//const byte calentadordepoPin = 47;   // Pin que liga o calentador de deposito
const byte comederopin = 49;   // Pin que liga el alimentador automatico (alimentadorPin)
const byte sensoresPin = 43;    // Pin que lee los sensores de temperatura

//***************************************************************************************************
//***************************************************************************************************
// Os 2 pinos abaixo serão controlados pelo PCF8575 caso esteja usando um.
// Observe que estes pinos também estão declarados na seção PCF8575.
// Caso esteja usando um PCF8575 os pinos 47 e 48 estarão livres para ser usados em outras funções

// The 2 pins below will be controlled for PCF8575 if you have an installed.
// Notice that this pins also are declared in PCF8575 section.
// when using a PCF8575 the pins 47 and 48 will be free to be used in others functions.
//***************************************************************************************************
#ifndef USE_PCF8575 // Do not change this line!
//const byte Co2 = 45;            // Pin que liga o CO2 del acuario
//const byte bomba_relleno_urna = A7;    // Bomba rellena el acuario principal.. controlado por el mega 2560
//const byte bomba_relleno_depo = A6;    // Bomba rellena el deposito de cambios de agua.. controlado por el mega 2560
//const byte valvula_vacio_urna = A7;    // Bomba que vacia el acuario principal.. controlado por el mega 2560
#endif // Do not change this line!
//***************************************************************************************************
//***************************************************************************************************

const byte sensor_urna = A8;              // Pin analógico que verifica si hay nivel maximo en la urna principal
/*
const byte sensor_minimodepo = A1;        // Pin analógico que verifica si hay nivel nimimo en el deposito inferior
const byte sensor_maximodepo = A2;        // Pin analógico que verifica si hay nivel maximo en el deposito inferior
const byte sensor_seguridaddepo = A3;     // Pin analógico que verifica si hay nivel seguridad en el deposito inferior
const byte sensor_minimourna = A4;       // Pin analógico que verifica si hay nivel minimo en la urna principal
*/
const byte bomba_relleno_urna = A7;    // Bomba rellena el acuario principal.. controlado por el mega 2560
//const byte bomba_relleno_depo = A6;    // Bomba rellena el deposito de cambios de agua.. controlado por el mega 2560
//const byte valvula_vacio_urna = A7;    // Bomba que vacia el acuario principal.. controlado por el mega 2560

//***************************************************************************************************
//***************************************************************************************************
// Os 3 pinos abaixo serão controlados pelo PCF8575 caso esteja usando um.
// Observe que estes pinos também estão declarados na seção PCF8575.
// Caso esteja usando um PCF8575 os pinos 60, 61 e 62 estarão livres para ser usados em outras funções

// The 3 pins below will be controlled for PCF8575 if you have an installed.
// Notice that this pins also are declared in PCF8575 section.
// when using a PCF8575 the pins 60, 61 and 62 will be free to be used in others functions.
//***************************************************************************************************
#ifndef USE_PCF8575 // Do not change this line! 
//const byte bomba_relleno_urna = A5;    // Bomba rellena el acuario principal.. controlado por el mega 2560
//const byte bomba_relleno_depo = A6;    // Bomba rellena el deposito de cambios de agua.. controlado por el mega 2560
//const byte valvula_vacio_urna = A7;    // Bomba que vacia el acuario principal.. controlado por el mega 2560
#endif // Do not change this line!
//***************************************************************************************************
//***************************************************************************************************

const byte dosadora1 = A8;      // Bomba dosadora 1  pin controlados por el mega 2560
const byte dosadora2 = A9;      // Bomba dosadora 2  pin controlados por el mega 2560
const byte dosadora3 = A10;     // Bomba dosadora 3  pin controlados por el mega 2560
const byte dosadora4 = A11;     // Bomba dosadora 4  pin controlados por el mega 2560
const byte dosadora5 = A12;     // Bomba dosadora 5  pin controlados por el mega 2560
const byte dosadora6 = A13;     // Bomba dosadora 6  pin controlados por el mega 2560
// Pino 69 (A15) reservado para SS do RFM12B

//***************************************************************************************************
//***************************************************************************************************
// Os 7 pinos abaixo serão controlados pelo PCF8575 caso esteja usando um.
// Observe que estes pinos também estão declarados na seção PCF8575.

// The 7 pins below will be controlled for PCF8575 if you have an installed.
// Notice that this pins also are declared in PCF8575 section.
//***************************************************************************************************
#ifndef USE_PCF8575 // Do not change this line!
const byte temporizador1 = 44;           // Pino que liga o timer 1.
const byte temporizador2 = 45;           // Pino que liga o timer 2.
const byte temporizador3 = 46;           // Pino que liga o timer 3.
const byte temporizador4 = 47;           // Pino que liga o timer 4.
const byte temporizador5 = 48;           // Pino que liga o timer 5.
//const byte solenoide1Pin = 85;           // Liga a reposicao de água doce.
//const byte alimentadorPin = 86;          // Pino que controla o alimentador automático.
//const byte skimmerPin = 87;              // Pino que controla o skimmer
#endif // Do not change this line!

//****************************************************************************************************
///************************************** PCF8575 ****************************************************
//****************************************************************************************************
// Do not change this part if you have not a PCF8575 installed.
// Não altere esta parte se você não tem um PCF8575 instalado.
#ifdef USE_PCF8575 // Do not change this line!
//const byte XXXXXXXX = 0;          // P0       // LIBRE
const byte Co2 = 1;                 // P1       // Pin que controla el CO2 del acuario..controlado por el modulo pcf8575 
const byte valvula_vacio_urna = 2;  // P2       // Pin que controla el vaciado del acuario principal..controlado por el modulo pcf8575
const byte bomba_relleno_depo = 3;  // P3       // Pin que controla el relleno del deposito de cambios de agua..controlado por el modulo pcf8575 
const byte bomba_relleno_urna = 4;  // P4       // Pin que controla el rellenado del acuario principal..controlado por el modulo pcf8575 
const byte temporizador1 = 5;       // P5       // Pin que controla el temporizador 1..controlado por el modulo pcf8575 
const byte temporizador2 = 6;       // P6       // Pin que controla el temporizador 2..controlado por el modulo pcf8575 
const byte temporizador3 = 7;       // P7       // Pin que controla el temporizador 3..controlado por el modulo pcf8575 
const byte temporizador4 = 8;       // P8       // Pin que controla el temporizador 4..controlado por el modulo pcf8575 
const byte temporizador5 = 9;       // P9       // Pin que controla el temporizador 5..controlado por el modulo pcf8575 
//const byte alimentadorPin = 10;     // P10      // Pin que controla el alimentador automático..controlado por el modulo pcf8575 
//const byte XXXXXXXXXX  = 11;      // P11      // LIBRE
//const byte XXXXXXXXXX  = 12;      // P12      // LIBRE
#endif // Do not change this line!
//****************************************************************************************************
//***************** Variáveis dos sensores de temperatura ********************************************
//****************************************************************************************************
OneWire OneWireBus(sensoresPin);        // Sensores de temperatura
DallasTemperature sensors(&OneWireBus); // Passa a nossa referência OneWire para sensores de temperatura.
DeviceAddress sensor_agua;              // Atribui os endereços dos sensores de temperatura.
DeviceAddress sensor_dissipador;        // Atribui os endereços dos sensores de temperatura.
DeviceAddress sensor_ambiente;          // Atribui os endereços dos sensores de temperatura.
byte sonda_associada_1 = 2;
byte sonda_associada_2 = 3;
byte sonda_associada_3 = 1;

//****************************************************************************************************
//***************** Variáveis temporárias dos sensores de temperatura ********************************
//****************************************************************************************************
DeviceAddress tempDeviceAddress; // Endereço temporário da sonda.
DeviceAddress sonda1; // Endereço temporário da sonda1.
DeviceAddress sonda2; // Endereço temporário da sonda2.
DeviceAddress sonda3; // Endereço temporário da sonda3.
byte sonda_associada_1_temp = 2;
byte sonda_associada_2_temp = 3;
byte sonda_associada_3_temp = 1;

//*******************************************************************************************************
//********************** Funções do RTC ********************************************************************
//*******************************************************************************************************
//        (SDA,SCL) Indica em quais pinos o RTC está conectado.
DS1307 rtc(20, 21);     // Comente esta linha para usar o Ferduino Mega 2560
//DS1307 rtc(18, 19);  // Descomente esta linha para usar o Ferduino Mega 2560
Time t_temp, t;

//*******************************************************************************************************
//********************** Variáveis das fuções do touch screen e tela inicial ****************************
//*******************************************************************************************************
#ifdef USE_TFT
UTFT        myGLCD(ILI9327, 38, 39, 40, 41); // "ITDB32WD" é o modelo do LCD
UTouch      myTouch(6,5,4,3,2);              // Comente esta linha para usar o Ferduino Mega 2560
//UTouch      myTouch(7, 6, 5, 4, 3);       // Descomente esta linha para usar o Ferduino Mega 2560

unsigned int ano = 0;
byte dia = 0;
byte whiteLed, blueLed, azulroyalLed; //, vermelhoLed, violetaLed;    // Valor anterior de PWM.
#endif

byte dispScreen = 0;
unsigned long previousMillis = 0;

#ifdef USE_SCREENSAVER
unsigned long previousMillis_2 = 0;
int interval = 30; // In seconds
boolean firstTime = true;
#endif
//*****************************************************************************************
//*********************** Parâmetros ******************************************************
//*****************************************************************************************
byte status_parametros = 0x0;
//bit 0;   // Señaliza que el calentador urna esta on/off
//bit 1;   // Señaliza que el calentador depo esta on/off
//bit 2;   // Señaliza que existe alarma de temperatura en pantalla principal del calentador del acuario
//bit 3;   // Señaliza que el ph acuario esta fuera de rango
//bit 4;   // Señaliza que existe alarma de temperatura en pantalla principal del calentador del deposito
//bit 5;   // Señaliza que co2 conectado/desconectado
//bit 6;   // Libre
//bit 7;   // Señaliza estado on/off de fuente alimentacion de leds.
byte status_parametros_1 = 0x0;
//bit 0    // Sinaliza que a ORP esta fora do especificado

byte outlets[9];
//outlets[0] = CALENTADOR URNA > 0 = auto, 1 = on, 2 = off
//outlets[1] = CALENTADOR DEPO > 0 = auto, 1 = on, 2 = off
//outlets[2] = FUENTE DE LEDS > 0 = auto, 1 = on, 2 = off
//outlets[3] = INYECCION CO2  > 0 = auto, 1 = on, 2 = off
//outlets[4] = SKIMMER > 0 = auto, 1 = on, 2 = off
//outlets[5] = Bomba 1 (TPA) > 0 = auto, 1 = on, 2 = off
//outlets[6] = ELECTROVALVULA VACIADO ACUARIO > 0 = auto, 1 = on, 2 = off
//outlets[7] = BOMBA RELLENO DEPO > 0 = auto, 1 = on, 2 = off
//outlets[8] = BOMBA RELLENO URNA  > 0 = auto, 1 = on, 2 = off
byte outlets_changed[9];
boolean outlets_settings = false;
unsigned long outlets_millis = 0;

//*****************************************************************************************
//*********************** Variables de control de temperatura de agua ********************
//*****************************************************************************************
float tempC = 0;               // Temperatura da água
float setTempC = 26.0;         // Temperatura desejada
float offTempC = 1.0;          // Variação permitida da temperatura
float alarmTempC = 5.0;          // Variacao para acionar o alarme de temperatura da água
byte contador_temp = 0;
float temperatura_agua_temp = 0; // Temperatura temporária

//*****************************************************************************************
//************************* Variables de temperatura deposito *****************************
//*****************************************************************************************
float tempA = 0;                     // Temperatura deposito
float setTempA = 26.0;               // Temperatura deseada en deposito
float offTempA = 1.0;                // Variacion permitida da temperatura
float alarmTempA = 5.0;              // Variacion para accionar la alarma de temperatura de agua
float temperatura_ambiente_temp = 0; // Temperatura temporal

//*****************************************************************************************
//************************ Variables temporales de control de temperaturas de agua *******
//*****************************************************************************************
float temp2beS;     //variable temperatura urna set 
float temp2beO;     //variable temperatura urna off
float temp2beA;     //variable temperatura urna alarma

float tempA2beS;  //variable temperatura deposito set
float tempA2beO;  //variable temperatura deposito off
float tempA2beA;  //variable temperatura deposito alarma

//*****************************************************************************************
//************************ Variáveis do controle do PH do aquário *************************
//*****************************************************************************************
float PHA = 0;              // PH do aquário
float setPHA = 0.0;           // PH desejado do aquário
float offPHA = 0.0;           // Variaçãoo permitida do PH do aquário
float alarmPHA = 0.0;         // Variação para acionar o alarme de ph do aquário

//*****************************************************************************************
//************************ Variáveis temporárias de controle do PH do aquário *************
//*****************************************************************************************
float PHA2beS;
float PHA2beO;
float PHA2beA;

//*****************************************************************************************
//************************ Variáveis de controle de densidade *****************************
//*****************************************************************************************
int DEN = 0;                 // Densidade
int setDEN = 1025;           // Densidade desejada
byte offDEN = 2;             // Variação permitida da densidade
byte alarmDEN = 1;           // Variação para acionar o alarme de densidade

//*****************************************************************************************
//************************ Variáveis de controle do PH do reator de cálcio ****************
//*****************************************************************************************
float PHR = 0;              // Valores PH reator
float setPHR = 0;           // PH do reator desejado
float offPHR = 0;           // Variacao permitida do PH do reator
float alarmPHR = 0;         // Variacao para acionar o alarme do PH do reator de calcio

//*****************************************************************************************
//************************ Variáveis temporárias de controle do PH do reator de cálcio ****
//*****************************************************************************************
float PHR2beS;
float PHR2beO;
float PHR2beA;

//*****************************************************************************************
//************************ Variáveis de controle da  ORP **********************************
//*****************************************************************************************
int ORP = 0;                // Valores ORP
int setORP = 420;           // ORP desejada
byte offORP = 10;           // Variação permitida da ORP
byte alarmORP = 10;         // Variacão para acionar o alarme da ORP

//*****************************************************************************************
//************************ Variáveis temporárias de controle da ORP ***********************
//*****************************************************************************************
int ORP2beS;
byte ORP2beO;
byte ORP2beA;

//*****************************************************************************************
//************************ Variáveis temporárias de controle da densidade *****************
//*****************************************************************************************
int DEN2beS;
byte DEN2beO;
byte DEN2beA;

//*****************************************************************************************
//************************ Variáveis de controle de velocidade dos coolers ****************
//*****************************************************************************************
#ifdef USE_FAHRENHEIT
float HtempMin = 86.9;
float HtempMax = 104.9;
#else
float HtempMin = 30.0;    // Declara a temperatura para iniciar o funcionamento das ventoinhas do dissipador
float HtempMax = 30.5;    // Declara que as ventoinhas devem estar em sua velocidade máxima quando o dissipador estiver com 40°c
#endif
int fanSpeed = 0;         // PWM dos coolers

//*****************************************************************************************
//************** Variáveis temperárias de controle de velocidade dos coolers **************
//*****************************************************************************************
float HtempMin_temp = 0;    // Declara a temperatura para iniciar o funcionamento das ventoinhas do dissipador
float HtempMax_temp = 0;    // Declara que as ventoinhas devem estar em sua velocidade máxima quando o dissipador estiver com 40°c

//*****************************************************************************************
//*********************** Variáveis de controle da temperatura do dissipador **************
//*****************************************************************************************
float tempH = 0;    // Temperatura do dissipador
byte tempHR = 70;   // Temperatura para reduzir potência dos leds
byte potR = 100;     // Porcentagem a ser reduzida.

//*****************************************************************************************
//*********** Variáveis temporárias de controle da temperatura do dissipador **************
//*****************************************************************************************
float temperatura_dissipador_temp = 0; // Temperatura temporária
byte tempHR_t = 0;                     // Temperatura temporária para reduzir potência dos leds
byte potR_t = 0;                       // Porcentagem temporária a ser reduzida.
boolean temperatura_alta = false;      // Sinaliza que a temperatura dos leds está alta.
boolean temperatura_baixou = false;    // Sinaliza que a temperatura dos leds esteve alta.

//*****************************************************************************************
//************************ Variáveis de controle da iluminação ****************************
//*****************************************************************************************
int LedChangTime = 0;             // Página de alteração do leds, tempo e valores.
boolean MeanWell = false;          // Se estiver usando drivers cuja potência máxima seja obtida aplicando zero volt e a mínima seja 5 volts altere de "true" para "false".
boolean LEDtestTick = false;      // Acelerar o tempo durante o teste dos leds.
int min_cnt ;
byte bled_out;
byte wled_out;
byte rbled_out;
//byte rled_out;
//byte uvled_out;
byte bled_out_temp;
byte wled_out_temp;
byte rbled_out_temp;
//byte rled_out_temp;
//byte uvled_out_temp;
byte moonled_out;
boolean periodo_selecionado = false;
byte y_tocado;
boolean teste_em_andamento = false;
byte cor_selecionada = 0;
// bit 1 = BLANCO 4000K 
// bit 2 = BLANCO 6500K
// bit 3 = BLANCO 10.000K 
// bit 4 = AZUL 
// bit 5 = ROJO
byte setor_selecionado = 0;
boolean mensagem = true;
float suavizar = 0.0; // LEDS iniciam suavemente e chega ao valor especificado em 50 segundos.
byte predefinido = 0;
byte pre_definido_ativado = 0;
byte pwm_pre_definido = 0;
byte led_on_minuto;
byte led_on_hora;
byte led_off_minuto;
byte led_off_hora;
boolean horario_alterado = false;
boolean hora_modificada = false;
byte amanhecer_anoitecer = 60;
boolean teste_iniciado = false;

//*****************************************************************************************
//**************** Variáveis temporárias de controle da iluminação ************************
//*****************************************************************************************
byte predefinido_t = 0;
byte pre_definido_ativado_t = 0;
byte pwm_pre_definido_t = 0;
byte led_on_minuto_t;
byte led_on_hora_t;
byte led_off_minuto_t;
byte led_off_hora_t;
byte amanhecer_anoitecer_t = 0;

//*****************************************************************************************
//************************* LED design ****************************************************
//*****************************************************************************************
const byte cor_canal[5][3] = {
  {240, 214, 59}, //BLANCO 4000K
  {198, 226, 228}, //BLANCO 6500K
  {147, 242, 253}, //BLANCO 10000K
  {58, 95, 205},   //AZUL
  {255, 0, 0}      //ROJO
};
/*
byte cor_canal1[] = {255, 255, 255};  // Branco
byte cor_canal2[] = {9, 184, 255};    // Azul
byte cor_canal3[] = {58, 95, 205};    // Azul Royal
byte cor_canal4[] = {255, 0, 0};      // Vermelho
byte cor_canal5[] = {224, 102, 255};  // Violeta*/

//*****************************************************************************************
//************************ Variáveis da fase lunar ****************************************
//*****************************************************************************************
String LP;
byte MaxI = 255; // Potência  máxima na Lua cheia.
byte tMaxI;
byte MinI = 0;   // Potência  mínima na Lua nova.
byte tMinI;
byte fase = 0;

//*****************************************************************************************
//********* Variáveis da TPA (Troca Parcial de Água) automática ***************************
//*****************************************************************************************
byte hora = 0;
byte minuto = 0;
byte duracaomaximatpa = 0;
byte semana_e[7]; // Index 0 = segunda-feira, 1 = terça-feira, 2 = quarta-feira, 3 = quinta-feira, 4 = sexta-feira, 5 = sábado, 6 = domingo.
byte tpa = 0;                             // Controla os estágios da TPA automática
byte tpa_status = 0x0; // 0 = false e 1 = true
// bit 1 = Sinaliza TPA automática em andamento
// bit 2 = Sinaliza falha durante a TPA automática
unsigned long tempo = 0;                 // Duração de cada estágio da TPA automática
unsigned long marcadoriniciotpa = 0;   // Evita que uma tpa inicie próximo do millis zerar
unsigned long shiftedmillis = 0;       // Evita que uma tpa inicie próximo do millis zerar

//*****************************************************************************************
//********** Variáveis temporárias da TPA (Troca Parcial de Água) automática **************
//*****************************************************************************************
byte temp2hora;
byte temp2minuto;
byte temp2duracaomaximatpa;
byte semana[7];

//****************************************************************************************
//*********************** Variáveis de controle das funções que utilizam o cartao SD *****
//****************************************************************************************
SdFat SD;
SdFile file;
unsigned long log_SD_millis = 0;
void writeCRLF(SdFile& f); 

//*****************************************************************************************
//*********************** Variável do controle de níveis **********************************
//*****************************************************************************************
boolean nivel_status1 = 0;             // Sinaliza nível baixo sensor 1
boolean nivel_status2 = 0;             // Sinaliza nível baixo sensor 2
boolean nivel_status3 = 0;             // Sinaliza nível baixo sensor 3
boolean nivel_status4 = 0;             // Sinaliza nível baixo sensor 4
boolean nivel_status5 = 0;             // Sinaliza nível baixo sensor 5
boolean nivel_status6 = 0;             // Sinaliza nível baixo sensor 6
boolean nivel_urna = 0;                // Sinaliza nivel bajo en acuario
boolean nivel_depo = 0;                // señaliza nivel bajo en deposito.


//*****************************************************************************************
//************************ Variável de controle da reposição de água doce *****************
//*****************************************************************************************
byte Status = 0x0;
// bit 1 // Sinaliza relleno acuario conectado/desconectado
// bit 2 // señaliza relleno deposito conectado/desconectado
// bit 3 // señaliza 
//*****************************************************************************************
//************************* Funções do ethernet shield ************************************
//*****************************************************************************************
#ifdef ETHERNET_SHIELD
const char *Username  = "sousa112";                      // Coloque aqui el nombre de usuario registrado en servidor http://ferduino.com/webcontrol
const char *APIKEY = "fb9d9fe3";                     // Coloque aqui el ApiKey generado en la web de http://ferduino.com/webcontrol

const byte maxima_tentativa = 3;                                   // Número máximo de tentativas de autenticação.
const byte intervalo_tentativa = 15;                               // Tempo  de espera (em minutos) para novas tentativas.
const byte limite_falha = 30;                                      // Reseta o controlador após 30 tentativas de upload para Ferduino. Para desabilitar esta função altere o valor para 0 (ZERO).
byte mac[] = {0xCC, 0x2C, 0x8C, 0xCC, 0xD8, 0xD4 };                // Este MAC deve ser único na sua rede local.
byte ip[] = {192, 168, 1, 10};     //test                         // Configure o IP conforme a sua rede local.
IPAddress dnsServer(8, 8, 8, 8);                                   // Configure o IP conforme a sua rede local. Este é o DNS do Google, geralmente não é necessário mudar.
IPAddress gateway(192, 168, 1, 1);                                 // Configure o "Gateway" conforme a sua rede local.
IPAddress subnet(255, 255, 255, 0);                                // Configure a máscara de rede conforme a sua rede local.
EthernetServer server(9000);                                       // Coloque aqui o número da porta configurada no seu roteador para redirecionamento.
// O número da porta deverá ser obrigatóriamente um destes: 80, 5000, 6000, 7000, 8000, 8080 ou 9000.

EthernetClient client;
IPAddress ferduino(104, 131, 49, 99); // Do NOT change this IP!
unsigned long intervalo = 0;
char *inParse[25];
byte tentativa = 0;
boolean web_dosage = false;
unsigned long millis_dosagem = 0;
unsigned long millis_enviar = 0;
boolean web_calibracao = false;
const char *token = ":";
char Auth1[50];
unsigned long teste_led_millis = 0;
unsigned long close_millis = 0;
byte notconnected = 0;
#endif

boolean web_teste = false;
//*****************************************************************************************
//************************** Variáveis de controle do multiplexador ***********************
//*****************************************************************************************
#if defined(STAMPS_EZO) || defined(STAMPS_V4X)
unsigned long millis_antes = 0;
const byte ph1 = 0; // Y0
const byte ph2 = 1; // Y1
const byte orp = 2; // Y2
const byte ec = 3;  // Y3
#endif

//*****************************************************************************************
//************************** Variáveis da solicitação de senha ****************************
//*****************************************************************************************
char stCurrent[5] = "";
char limpar_senha [5] = "";
byte stCurrentLen = 0;
const char senha [5] = {'9', '4', '6', '7', '\0'}; // Insira sua senha aqui. O caracter '\0' não deve ser alterado.

//*****************************************************************************************
//************************** Variáveis dosadoras ******************************************
//*****************************************************************************************
boolean dosadoras = false; //Altere para "false" caso não tenha as dosadoras.
const char *arquivo[6] = {"HDP1.TXT", "HDP2.TXT", "HDP3.TXT", "HDP4.TXT", "HDP5.TXT", "HDP6.TXT"};
unsigned long tempo_dosagem = 0;
unsigned long dosadoras_millis = 0;
boolean modo_manual = false;
boolean modo_personalizado = false;
boolean modo_calibrar = false;
byte dosadora_selecionada = 0; // 0 = false, 1 = true
byte dosadora[6] = {dosadora1, dosadora2, dosadora3, dosadora4, dosadora5, dosadora6}; // Index 0 = dosadora 1 , 1 = dosadora 2, 2 = dosadora 3, 3 = dosadora 4, 4 = dosadora 5, 5 = dosadora 6
byte ativar_desativar = 0x0;     // 0 = false, 1 = true
byte hora_inicial_dosagem_personalizada_e[6];
byte minuto_inicial_dosagem_personalizada_e[6];
byte hora_final_dosagem_personalizada_e[6];
byte minuto_final_dosagem_personalizada_e[6];
byte segunda_dosagem_personalizada_e[6];
byte terca_dosagem_personalizada_e[6];
byte quarta_dosagem_personalizada_e[6];
byte quinta_dosagem_personalizada_e[6];
byte sexta_dosagem_personalizada_e[6];
byte sabado_dosagem_personalizada_e[6];
byte domingo_dosagem_personalizada_e[6];
float dose_dosadora_personalizada_e[6] = {101, 102, 103, 104, 105, 106};
byte quantidade_dose_dosadora_personalizada_e[6];
byte modo_personalizado_on_e[6];
float dose_dosadora_manual_e[6] = {20, 20, 20, 20, 20, 20};
float fator_calib_dosadora_e[6] = {35.1, 35.2, 35.3, 35.4, 35.5, 35.6};

//*****************************************************************************************
//************************** Variáveis temporárias das dosadoras **************************
//*****************************************************************************************
byte hora_inicial_dosagem_personalizada[6];
byte minuto_inicial_dosagem_personalizada[6];
byte hora_final_dosagem_personalizada[6];
byte minuto_final_dosagem_personalizada[6];
byte segunda_dosagem_personalizada[6];
byte terca_dosagem_personalizada[6];
byte quarta_dosagem_personalizada[6];
byte quinta_dosagem_personalizada[6];
byte sexta_dosagem_personalizada[6];
byte sabado_dosagem_personalizada[6];
byte domingo_dosagem_personalizada[6];
float dose_dosadora_personalizada[6];
byte quantidade_dose_dosadora_personalizada[6];
byte modo_personalizado_on[6];
float dose_dosadora_manual[6];
float volume_dosado[6];
float fator_calib_dosadora[6];
//*****************************************************************************************
//************************** Variáveis dos timers *****************************************
//*****************************************************************************************
byte temporizador = 0;
byte temporizador_e[5] = {temporizador1, temporizador2, temporizador3, temporizador4, temporizador5};  // Index 0 = timer 1 , 1 = timer 2, 2 = timer 3, 3 = timer 4, 4 = timer 5

boolean web_timer = false;
byte temporizador_status = 0x0; // 1 = true e 0 = false
//bit 1 = temporizador 1
//bit 2 = temporizador 2
//bit 3 = temporizador 3
//bit 4 = temporizador 4
//bit 5 = temporizador 5
byte temporizador_modificado = 0x0;
//bit 1 = temporizador 1
//bit 2 = temporizador 2
//bit 3 = temporizador 3
//bit 4 = temporizador 4
//bit 5 = temporizador 5

byte on_hora_e[5]; // Index 0 = timer 1 , 1 = timer 2, 2 = timer 3, 3 = timer 4, 4 = timer 5
byte on_minuto_e[5];
byte off_hora_e[5];
byte off_minuto_e[5];
byte temporizador_ativado_e[5];

//*****************************************************************************************
//******************** Variáveis temporárias dos timers ***********************************
//*****************************************************************************************
byte on_hora[5];
byte on_minuto[5];
byte off_hora[5];
byte off_minuto[5];
byte temporizador_ativado[5];

//*****************************************************************************************
//************************** Variáveis do PCF8575 *****************************************
//*****************************************************************************************
#ifdef USE_PCF8575
byte endereco_PCF8575TS = 0x20; // Endereço em hexadecimal = 0x20
PCF8575 PCF8575;
#endif

//*****************************************************************************************
//*********************** Wireless transceiver (RFM12B) ***********************************
//*****************************************************************************************
#if defined(RFM12B_LED_CONTROL) || defined(RFM12B_RELAY_CONTROL)
RFM12B radio;
#define ACK_TIME    200
#define MY_ID      99                   // ID deste dispositivo
#define NETWORK_ID   100                // Todos os dispositivos devem estar na mesma rede.
#define TARGET_ID_LED   1               // 1 = ID do dispositivos que receberá a informação
#define TARGET_ID_RELAY   2             // 2 = ID do dispositivos que receberá a informação
#define FREQUENCY   RF12_915MHZ         // Frequência de operação do rádio.
#define KEY         "thisIsEncryptKey"  // Esta senha deve ter exatamente 16 caracteres.
#define ACK_TIME    200
const byte limite_sem_resposta = 4;     // Reseta o controlador após 4 envios sem resposta. Para desabilitar esta função altere o valor para 0 (ZERO).
unsigned long lastPeriod_millis = 0;
boolean requestACK_LED = false;         // true = Solicitar uma resposta do dispositivo que recebe a informação
boolean requestACK_RELAY = false;       // true = Solicitar uma resposta do dispositivo que recebe a informação
byte nothing = 0;
#endif

#ifdef RFM12B_LED_CONTROL
typedef struct {
  int  nodeId;
  byte channel_white;
  byte channel_blue;
  byte channel_royalBlue;
  byte channel_red;
  byte channel_violet;
  byte channel_moon;
  byte channel_6;  // canal extra
  byte channel_7;  // canal extra
  byte channel_8;  // canal extra
  byte channel_9;  // canal extra
  byte channel_10; // canal extra
  byte channel_11; // canal extra
  byte channel_12; // canal extra
  byte channel_13; // canal extra
  byte channel_14; // canal extra
  byte channel_15; // canal extra
}
Payload_led;
Payload_led theData_led  = {MY_ID, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
#endif

#ifdef RFM12B_RELAY_CONTROL
typedef struct {
  int  nodeId;
  byte relay_0;
  byte relay_1;
  byte relay_2;
  byte relay_3;
  byte relay_4;
  byte relay_5;
  byte relay_6;
  byte relay_7;
  byte relay_8;
  byte relay_9;
  byte relay_10;
  byte relay_11;
  byte relay_12;
  byte relay_13;
  byte relay_14;
  byte relay_15;
}
Payload_relay;
Payload_relay theData_relay  = {MY_ID, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#endif

//*****************************************************************************************
//************************** Dispositivos SPI *********************************************
//*****************************************************************************************
const byte SD_CARD = 0;
const byte ETHER_CARD = 1;
const byte RFM = 2;
const byte ChipSelect_SD = 4; // Comente esta linha para usar o Ferduino Mega 2560
//const byte ChipSelect_SD = 5;  // Descomente esta linha para usar o Ferduino Mega 2560
const byte SelectSlave_ETH = 53;
const byte ChipSelect_RFM = 69; // A15


//*****************************************************************************************
//************************* Variáveis das bombas de circulação ****************************
//*****************************************************************************************
#ifdef NIGHT_MODE
const float POWER_PUMP1 = 0.5; // 50%
const float POWER_PUMP2 = 0.5; // 50%
#endif
byte modo_selecionado = 1;
byte Pump1PWM_temp = 0;
byte Pump2PWM_temp = 0;
int periodo = 10000;
unsigned int duracao = 5000; // Duração do ciclo em milisegundos para o modo 3.
unsigned long millis_antes_1 = 0;
byte conta = 0;
byte Pump1PWM = 0;
byte Pump2PWM = 0;

//*****************************************************************************************
//*********************** Variáveis de controle do alimentador automático *****************
//*****************************************************************************************
/*
byte horario_alimentacao_e[4]; // horario_e[0] = hora para iniciar, horario_e[1] = minuto para iniciar, horario_e[2] = hora para terminar, horario_e[3] = minuto para terminar
byte dia_alimentacao_e[7];
byte duracao_alimentacao = 1; // Duração em segundos
byte desligar_wavemaker = 2; // Tempo em minutos
byte quantidade_alimentacao = 1;
byte alimentacao_wavemaker_on_off = 0; // bit 0 = alimentação automática ativada  ou desativada bit 1 = desligar wavemaker ativado / desativado
boolean modo_alimentacao = false;
boolean wavemaker_on_off = false;
unsigned long alimentacao_millis = 0;
unsigned long wavemaker_on_off_millis = 0;
unsigned long check_alimentador_millis = 0;
boolean alimentacao_erro = false;
*/
int comedero = 1;
int comedero1 = 1;       //Valor a cero comedero desactivado valor a 1 comedero activado
int comedero2 = 1;       //Valor a cero comedero desactivado valor a 1 comedero activado
int comedero3 = 1;       //Valor a cero comedero desactivado valor a 1 comedero activado
int comedero4 = 1;       //Valor a cero comedero desactivado valor a 1 comedero activado

int comedero1H = 8;
int comedero1M = 00;
int comedero2H = 12;
int comedero2M = 00;
int comedero3H = 16;
int comedero3M = 00;
int comedero4H = 20;
int comedero4M = 00;

//*****************************************************************************************
//********************* Variáveis temporárias do alimentador automático *******************
//*****************************************************************************************
/*
byte horario_alimentacao[4];
byte dia_alimentacao[7];
byte duracao_alimentacao_temp = 0;
byte desligar_wavemaker_temp = 0;
byte quantidade_alimentacao_temp = 0;
byte alimentacao_wavemaker_on_off_temp = 0;
*/
int comedero1_Temp = 1;
int comedero2_Temp = 1;
int comedero3_Temp = 1;
int comedero4_Temp = 1;

int comedero1H_Temp = 8;
int comedero1M_Temp = 00;
int comedero2H_Temp = 12;
int comedero2M_Temp = 00;
int comedero3H_Temp = 16;
int comedero3M_Temp = 00;
int comedero4H_Temp = 20;
int comedero4M_Temp = 00;

//*****************************************************************************************
//************************** Variáveis de controle da potência dos leds *******************
//*****************************************************************************************
byte wled[96] = {                         //Potência de saída dos leds brancos 255 = 100% da potência
  0, 0, 0, 0, 0, 0, 0, 0,         // 0 e 2
  0, 0, 0, 0, 0, 0, 0, 0,         // 2 e 4
  0, 0, 0, 0, 0, 0, 0, 0,         // 4 e 6
  0, 0, 0, 0, 255, 255, 255, 255,         // 6 e 8 
  255, 255, 255, 255, 255, 255, 255, 255, // 8 e 10
  255, 255, 255, 255, 255, 255, 255, 255, // 10 e 12
  255, 255, 255, 255, 255, 255, 255, 255, // 12 e 14
  255, 255, 255, 255, 0, 0, 0, 0, // 14 e 16
  0, 0, 0, 0, 0, 0, 0, 0,         // 16 e 18
  0, 0, 0, 0, 0, 0, 0, 0,         // 18 a 20
  0, 0, 0, 0, 0, 0, 0, 0,         // 20 e 22
  0, 0, 0, 0, 0, 0, 0, 0,         // 22 a 0
};

byte bled[96] = {                       // Potência de saída dos leds azuis 255 = 100% da potência
  0, 0, 0, 0, 0, 0, 0, 0,       // 0 e 2
  0, 0, 0, 0, 0, 0, 0, 0,       // 2 e 4
  0, 0, 0, 0, 0, 0, 0, 0,       // 4 e 6
  0, 0, 0, 0, 0, 0, 0, 0,       // 6 e 8 
  0, 0, 0, 0, 0, 0, 0, 0,       // 8 e 10
  255, 255, 255, 255, 255, 255, 255, 255,         // 10 e 12
  255, 255, 255, 255, 255, 255, 255, 255, // 12 e 14
  255, 255, 255, 255, 255, 255, 255, 255, // 14 e 16
  255, 255, 255, 255, 255, 255, 255, 255, // 16 e 18
  0, 0, 0, 0, 0, 0, 0, 0,         // 18 a 20
  0, 0, 0, 0, 0, 0, 0, 0,         // 20 e 22
  0, 0, 0, 0, 0, 0, 0, 0,         // 22 a 0
};  

byte rbled[96] = {                         //Potência de saída dos leds brancos 255 = 100% da potência
  0, 0, 0, 0, 0, 0, 0, 0,       // 0 e 2
  0, 0, 0, 0, 0, 0, 0, 0,       // 2 e 4
  0, 0, 0, 0, 0, 0, 0, 0,       // 4 e 6
  0, 0, 0, 0, 0, 0, 0, 0,       // 6 e 8 
  0, 0, 0, 0, 0, 0, 0, 0,       // 8 e 10
  0, 0, 0, 0, 0, 0, 0, 0,       // 10 e 12
  0, 0, 0, 0, 255, 255, 255, 255, // 12 e 14
  255, 255, 255, 255, 255, 255, 255, 255, // 14 e 16
  255, 255, 255, 255, 255, 255, 255, 255, // 16 e 18
  255, 255, 255, 255, 255, 255, 255, 255, // 18 a 20
  255, 255, 255, 255, 0, 0, 0, 0,         // 20 e 22
  0, 0, 0, 0, 0, 0, 0, 0,         // 22 a 0
};
/*
byte rled[96] = {                         //Potência de saída dos leds brancos 255 = 100% da potência
  0, 0, 0, 0, 0, 0, 0, 0,       // 0 e 2
  0, 0, 0, 0, 0, 0, 0, 0,       // 2 e 4
  0, 0, 0, 0, 0, 0, 0, 0,       // 4 e 6
  0, 0, 0, 0, 0, 0, 0, 0,     // 6 e 8 
  0, 0, 0, 1, 12, 21, 30, 39, // 8 e 10
  255, 255, 255, 255, 255, 255, 255, 255, // 10 e 12
  255, 255, 255, 255, 255, 255, 255, 255, // 12 e 14
  255, 255, 255, 255, 255, 255, 255, 255,  // 14 e 16
  255, 255, 255, 255, 255, 255, 255, 255,       // 16 e 18
  255, 255, 255, 255, 255, 255, 255, 255,         // 18 a 20
  255, 255, 255, 200, 170, 30, 0, 0,         // 20 e 22
  0, 0, 0, 0, 0, 0, 0, 0,          // 22 a 0
};
byte uvled[96] = {                         //Potência de saída dos leds brancos 255 = 100% da potência
  0, 0, 0, 0, 0, 0, 0, 0,       // 0 e 2
  0, 0, 0, 0, 0, 0, 0, 0,       // 2 e 4
  0, 0, 0, 0, 0, 0, 0, 0,       // 4 e 6
  0, 0, 0, 0, 0, 0, 0, 0,     // 6 e 8 
  0, 0, 0, 1, 12, 21, 30, 39, // 8 e 10
  255, 255, 255, 255, 255, 255, 255, 255, // 10 e 12
  255, 255, 255, 255, 255, 255, 255, 255, // 12 e 14
  255, 255, 255, 255, 255, 255, 255, 255,  // 14 e 16
  255, 255, 255, 255, 255, 255, 255, 255,       // 16 e 18
  255, 255, 255, 255, 255, 255, 255, 255,         // 18 a 20
  255, 255, 252, 239, 170, 48, 26, 1,         // 20 e 22
  0, 0, 0, 0, 0, 0, 0, 0,          // 22 a 0
};
*/
byte *cor[3] = {wled, bled, rbled};

//*****************************************************************************************
//************************** Textos *******************************************************
//*****************************************************************************************
const char string0[] PROGMEM = "POST /webcontrol/api/index.php HTTP/1.1";
const char string1[] PROGMEM = "Host: www.ferduino.com";
const char string2[] PROGMEM = "Authorization: Basic ";
const char string3[] PROGMEM = "Cache-Control: no-cache";
const char string4[] PROGMEM = "Content-Type: application/x-www-form-urlencoded";
const char string5[] PROGMEM = "Connection: Keep-Alive";
const char string6[] PROGMEM = "Content-Length: ";
const char string7[] PROGMEM = "{\"response\":\"ok\"}";
const char string8[] PROGMEM = "HTTP/1.1 200 OK";
const char string9[] PROGMEM = "Content-Type: application/json";
const char string10[] PROGMEM = "{\"response\":\"000\"}";
const char string11[] PROGMEM = "{\"response\":\"001\",\"interval\":\"";
const char string12[] PROGMEM = "{\"response\":\"stop\"}";

const char* const tabela_strings[] PROGMEM =
{
  string0, string1, string2, string3,
  string4, string5, string6, string7,
  string8, string9, string10, string11,
  string12
};
