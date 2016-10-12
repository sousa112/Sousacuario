//------------------------setup------------------------------
void setup()
{
#ifdef WATCHDOG // Do not change this line!
  wdt_disable();
#endif // Do not change this line!


#ifdef DEBUG
  Serial.begin(38400); // Inicia a comunicação com a  porta serial 0 para obter mensagens de depuração.
  Serial.flush();
  Serial.println();
#endif

#if defined(STAMPS_EZO) || defined(STAMPS_V4X) // Do not change this line!
  Serial3.begin(38400); // Inicia a comunicação com a  porta serial 3 onde estão conectados os "stamps".
#endif // Do not change this line!

  // Define a função dos pinos.
  pinMode(9,OUTPUT); //Establecemos el pin 9 como salida (led del TFT) 
  pinMode(A9,INPUT); //y el A9 como entrada (fotoresistor)
  pinMode(alarmPin, OUTPUT);               // Pin 0;
  pinMode(desativarFanPin, OUTPUT);        // Pin 1;

  pinMode (ChipSelect_SD, OUTPUT);         // Pin 4 o 5;

  //pinMode(ledPinUV, OUTPUT);               // Pin ;
  pinMode(ledPinBlue, OUTPUT);             // Pin 14;
  pinMode(ledPinWhite, OUTPUT);            // Pin 15;
  pinMode(ledPinRoyBlue, OUTPUT);          // Pin 16;
  //pinMode(ledPinRed, OUTPUT);              // Pin 12;
  pinMode(fanPin, OUTPUT);                 // Pin 8;
 // pinMode(multiplexadorS0Pin, OUTPUT);     // Pin ;
 // pinMode(multiplexadorS1Pin, OUTPUT);     // Pin ;

 // pinMode(desativarFonte, OUTPUT);         // Pin ;
  pinMode(calentadorPin, OUTPUT);          // Pin 43;
  pinMode(ledPinMoon, OUTPUT);             // Pin 17;
  pinMode(Co2, OUTPUT);                    // Pin 45;
  //Pin 46 libre                           // Pin 46;
 // pinMode(calentadordepoPin, OUTPUT);      // Pin 47;
  pinMode (comederopin, OUTPUT);        // Pin 48; alimentadorPin
 

  pinMode(SelectSlave_ETH, OUTPUT);        // Pin 53;

  pinMode(sensor_urna, INPUT);             // Pin A8;
//  pinMode(sensor_minimodepo, INPUT);       // Pin A1;
//  pinMode(sensor_maximodepo, INPUT);       // Pin A2;
//  pinMode(sensor_seguridaddepo, INPUT);    // Pin A4;
//  pinMode(bomba_relleno_depo, OUTPUT);     // Pin A5;    
  pinMode(bomba_relleno_urna, OUTPUT);     // Pin A7;  
//  pinMode(valvula_vacio_urna, OUTPUT);     // Pin A7; 
/*
  pinMode(dosadora1, OUTPUT);              // Pin A9;
  pinMode(dosadora2, OUTPUT);              // Pin A10;
  pinMode(dosadora3, OUTPUT);              // Pin A11;
  pinMode(dosadora4, OUTPUT);              // Pin A12;
  pinMode(dosadora5, OUTPUT);              // Pin A13;
  pinMode(dosadora6, OUTPUT);              // Pin A14;
*/  pinMode(ChipSelect_RFM, OUTPUT);         // Pin A15;

// Con esto apagamos todos los reles.  
    for (int i = 0; i < 50; i++)
       {
        pinMode(i, OUTPUT);
        SetRele(i, LOW);
       } 

#ifdef USE_PCF8575 // Do not change this line!
  PCF8575.begin(endereco_PCF8575TS); // Inicia a comunicação com o PCF8575TS
  for (int i = 0; i < 16; i++)
  {
    PCF8575.pinMode(i, OUTPUT);
    PCF8575.digitalWrite(i, LOW);
  }
#else // Do not change this line!
  pinMode (temporizador1, OUTPUT);         // Pino 80;
  pinMode (temporizador2, OUTPUT);         // Pino 81;
  pinMode (temporizador3, OUTPUT);         // Pino 82;
  pinMode (temporizador4, OUTPUT);         // Pino 83;
  pinMode (temporizador5, OUTPUT);         // Pino 84;
#endif // Do not change this line!

#ifdef USE_TFT
  myGLCD.InitLCD(LANDSCAPE); // Orientação da imagem no LCD.
  clearScreen();             // Limpa o LCD.

  myTouch.InitTouch(LANDSCAPE);       // Orientação do "touch screen".
  myTouch.setPrecision(PREC_MEDIUM);  // Define a precisão do "touch screen".
#endif
  
  ReadDallasAddress ();
  sensors.begin();                                //Inicia as leituras das sondas de temperatura.
  sensors.setResolution(sensor_agua, 10);        // Define a resolução em 10 bits.
  sensors.setResolution(sensor_dissipador, 10);  // Define a resolução em 10 bits.
  sensors.setResolution(sensor_ambiente, 10);    // Define a resolução em 10 bits.
  sensors.requestTemperatures();                 // Chamada para todos os sensores.
#ifdef USE_FAHRENHEIT
  tempC = (sensors.getTempF(sensor_agua));       // Lê a temperatura da água
  tempH = (sensors.getTempF(sensor_dissipador)); // Lê a temperatura do dissipador.
  tempA = (sensors.getTempF(sensor_ambiente));   // Lê a temperatura do ambiente.
#else
  tempC = (sensors.getTempC(sensor_agua));       // Lê a temperatura da água
  tempH = (sensors.getTempC(sensor_dissipador)); // Lê a temperatura do dissipador.
  tempA = (sensors.getTempC(sensor_ambiente));   // Lê a temperatura do ambiente.
#endif

  rtc.halt(false); // Inicia o funcionamento do RTC.

  byte k =  EEPROM.read(0);

  if (k != 222) // Verifica se a EEPROM foi formatada por este programa
  {
#ifdef USE_TFT
    setFont(SMALL, 255, 0, 0, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[225]))); // "FORMATANDO A EEPROM..."
    myGLCD.print(buffer, CENTER, 115);
#endif

    EEPROM.write(0, 222); // Indica que a EEPROM foi formatada por este programa

    for (int i = 1; i < 4096; i++)
    {
      EEPROM.write(i, 0); // Formata a eeprom
    }
  }

  k =  EEPROM.read(796); // Copia valores dos LEDs para a eeprom.

  if (k != 222)
  {
    SaveLEDToEEPROM();
  }

  // Lê a variáveis guardadas na EEPROM.
  ReadFromEEPROM();
  //lertpaEEPROM();
  lerPHAEEPROM();
  //lerPHREEPROM();
  //ler_dosadora_EEPROM();
  ler_luz_noturna_EEPROM();
  ler_timers_EEPROM();
  ler_coolersEEPROM();
  ler_tempPotEEPROM();
  //ler_wave_EEPROM();
  //ler_calib_dosadora_EEPROM();
  ler_predefinido_EEPROM();
  //check_erro_tpa_EEPROM();
  ler_comederos_EEPROM(); 
  ler_outlets_EEPROM();

  selecionar_SPI(SD_CARD);                         // Seleciona disposito SPI que será utilizado.
  while (!SD.begin(ChipSelect_SD, SPI_HALF_SPEED)) // Inicia a comunicação com o cartão SD.
  {
#ifdef USE_TFT    
    setFont(SMALL, 255, 0, 0, 0, 0, 0);
    myGLCD.print("PLEASE INSERT A SD CARD.", CENTER, 115);
#endif
    
#ifdef DEBUG
    Serial.println(F("Please insert a SD CARD"));
#endif
  }

  t = rtc.getTime(); // Atualiza as variáveis que usam o RTC.
  /* check_arquivo_temp_agua(); // Corrige o log de temperatura
   check_arquivo_ph_agua();   // Corrige o log de pH da água
   check_arquivo_ph_reator(); // Corrige o log de pH do reator
   check_arquivo_orp();       // Corrige o log de ORP
   check_arquivo_densidade(); // Corrige o log de densidade
  */
#if defined(STAMPS_EZO) || defined(STAMPS_V4X) // Do not change this line!
  iniciar_stamp_ph_reator();    // Lê o pH do reator
  iniciar_stamp_ph_aquario();   // Lê o pH do aquário
#endif // Do not change this line!

#ifdef ETHERNET_SHIELD // Do not change this line!
  start_ethernet();

  strcpy(buffer, Username);
  strcat(buffer, token);
  strcat(buffer, APIKEY);
  base64_encode(Auth1, buffer, strlen(buffer)); // Cria a senha do servidor.
#endif // Do not change this line!

#if defined(RFM12B_LED_CONTROL) || defined(RFM12B_RELAY_CONTROL) // Do not change this line!
  selecionar_SPI(RFM);                      // Seleciona disposito SPI que será utilizado.
  radio.Initialize(MY_ID, FREQUENCY, NETWORK_ID);
  radio.Encrypt((byte*)KEY);
#endif // Do not change this line!

#ifdef USE_TFT
  clearScreen();    // Limpa o LCD.
  mainScreen(true); // Exibe a tela inicial no LCD.
#endif

#ifdef WATCHDOG // Do not change this line!
  wdt_enable(WDTO_8S);
#endif // Do not change this line!  
}
//***************************************************************************************************************************************
//****************************** Fim do setup() *****************************************************************************************
//***************************************************************************************************************************************
#ifdef ETHERNET_SHIELD // Do not change this line!
void start_ethernet()
{
  selecionar_SPI(ETHER_CARD); // Seleciona disposito SPI que será utilizado.
#ifdef USE_DHCP
  Ethernet.begin(mac, SelectSlave_ETH); // Configuração do servidor.
#else
  Ethernet.begin(mac, ip, dnsServer, gateway, subnet, SelectSlave_ETH); // Configuração do servidor.
#endif

  server.begin(); // Inicia o servidor.

#ifdef DEBUG
  Serial.print(F("IP server: "));
  Serial.println(Ethernet.localIP());
#endif
}
#endif // Do not change this line!

void SetRele( int Pin, boolean Estado )  //Funcion que hace que el rele chino funcione bien y se puede poner LOW o HIGH segun corresponda.
{
 
 digitalWrite( Pin, !Estado );
 
}
