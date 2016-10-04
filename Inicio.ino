#ifdef USE_TFT
//---------------------------------------Tela inicial ----------------------------------------------tela =0
void mainScreen(boolean refreshAll = false)
{
  int ledLevel;
  int offset = 0;
  char bufferLP[16];

  setFont(SMALL, 255, 255, 0, 0, 0, 0);
  myGLCD.print(rtc.getTimeStr(FORMAT_SHORT), 266, 227);

  if ((t.date != dia) || (refreshAll == true) || (t.year != ano))
  {
    dia = t.date;
    ano = t.year;
    
    drawFillRect(98, 213, 235, 226, 0, 0, 0);

    myGLCD.fillRect(88, 213, 200, 216); // Apaga fase lunar

    setFont(SMALL, 255, 255, 0, 0, 0, 0);
    myGLCD.print(rtc.getDOWStr(FORMAT_SHORT), 80, 227);
    myGLCD.printNumI(t.date, 109, 227);
    myGLCD.print("DE", 132, 227);
    myGLCD.print(rtc.getMonthStr(FORMAT_SHORT), 153, 227);
    myGLCD.print("DE", 182, 227);
    myGLCD.printNumI(t.year, 203, 227);

    float lunarCycle = moonPhase(t.year, t.mon, t.date); //get a value for the lunar cycle

    LP.toCharArray(bufferLP, 16);

    myGLCD.setColor(255, 255, 255);
    myGLCD.print(bufferLP, 88, 213); //Escreve descrição da fase lunar

    if ((lunarCycle * 100) < 0) //Print % of Full to LCD
    {
      myGLCD.print(" 0 ", 212, 213);
    }
    else
    {
      myGLCD.printNumF(lunarCycle * 100, 1, 212, 213);
    }

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[181])));
    myGLCD.print(buffer, 232, 213); // tabela_textos[181] = "% ILUMINADA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[182])));
    myGLCD.print(buffer, 0, 213); // tabela_textos[182] = "FASE LUNAR:"
  }

  if ( refreshAll == true)                                  //Desenha elementos fixos
  {
    myGLCD.setColor(196, 136, 17);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[30])));
    myGLCD.print(buffer, 35, 5); // tabela_textos[30] = "POTENCIA DOS LEDS"

    myGLCD.setColor(192, 236, 255);

    myGLCD.print("100", 14, 17);

    for (int i = 0; i < 90; i += 10)
    {
      myGLCD.printNumI(90 - i, 22, 28 + offset); // 90 até 10
      offset += 11;
    }

    myGLCD.print("0", 30, 127);

    myGLCD.setColor(255, 255, 255);

    myGLCD.drawRect(40, 138, 187, 138);       // Eixo X
    myGLCD.drawRect(40, 28, 50, 138);         // Eixo Y

    for (int i = 0; i < 10; i++)
    {
      myGLCD.drawLine(41, (i * 11) + 28, 55, (i * 11) + 28);
    } // Marcador grande
    myGLCD.setColor(190, 190, 190);

    for (int i = 0; i < 10; i++)
    {
      myGLCD.drawLine(41, (i * 11) + 34, 53, (i * 11) + 34);
    } // Marcador pequeno

    for (int i = 0; i < 10; i++)
    {
      myGLCD.drawLine(69, (i * 11) + 28, 187, (i * 11) + 28);
    }// Grade

    myGLCD.setColor(255, 255, 255);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[184])));
    myGLCD.print(buffer, 201, 10);  // tabela_textos[184] = "Temp FILTRO" 
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[190])));
    myGLCD.print(buffer, 201, 24); // tabela_textos[190] = "calentador:"    

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[183])));
    myGLCD.print(buffer, 201, 38); // tabela_textos[183] = "temp CONTROLADOR:"
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[189])));
    myGLCD.print(buffer, 201, 52); // tabela_textos[189] = "ventilador:"    

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[194])));
    myGLCD.print(buffer, 201, 66); // tabela_textos[194] = "temperatura AGUA" 
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[185])));
    myGLCD.print(buffer, 201, 80); // tabela_textos[185] = "PH DO AQUARIO:"

  //  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[186])));
  //  myGLCD.print(buffer, 212, 70); // tabela_textos[187] = "PH DEPOSITO:"

  //  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[189])));
  //  myGLCD.print(buffer, 212, 84); // tabela_textos[188] = "CAL DEPO:"

  //  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[190])));
  //  myGLCD.print(buffer, 212, 98); // tabela_textos[189] = "CAL URNA:"

  //  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[191])));
  //  myGLCD.print(buffer, 212, 112); // tabela_textos[190] = "Co2 urna:"

   // strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[192])));
//    myGLCD.print(buffer, 212, 126); // tabela_textos[191] = "RELLENO DEPO:"

   // strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[193])));
   // myGLCD.print(buffer, 212, 140); // tabela_textos[192] = "RELLENO URNA:"

   // strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[194])));
   // myGLCD.print(buffer, 212, 154); // tabela_textos[193] = "NIVEL DEPOSITO:"

   // strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[188])));
   // myGLCD.print(buffer, 212, 168); // tabela_textos[194] = ""NIVEL URNA:"

   // strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[195])));
   // myGLCD.print(buffer, 212, 182); // tabela_textos[194] = "TPA:" // Troca de Água Parcial

  //  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[187])));
 //   myGLCD.print(buffer, 212, 196); // tabela_textos[195] = "FUENTE LEDS:" // FUENTE ALIMENTACION DE LOS LEDS

/*    myGLCD.setColor(0, 255, 0);

    myGLCD.drawCircle(284,38 , 2);                  // Unidade t. arduino

#ifdef USE_FAHRENHEIT
    myGLCD.print("F", 372, 14);
#else
    myGLCD.print("C", 372, 14);                   
#endif

    myGLCD.drawCircle(284, 66, 2);    // Unidad t. água

#ifdef USE_FAHRENHEIT
    myGLCD.print("F", 372, 28);       
#else
    myGLCD.print("C", 372, 28);       
#endif

    myGLCD.drawCircle(284, 10, 2);   // Unidad t. deposito
    
#ifdef USE_FAHRENHEIT
    myGLCD.print("F", 372, 42);       
#else
    myGLCD.print("C", 372, 42);       
#endif

*/

    myGLCD.setColor(161, 127, 73);                  
    myGLCD.drawRect(0, 0, 189, 208);                // Dibujar rectangulos
    myGLCD.drawRect(194, 0, 318, 100);
    myGLCD.drawRect(194, 104, 318, 208);
  } // Fim do refreshAll

  if ((refreshAll == true) || (web_timer == true))
  {
    web_timer = false;
    if (temporizador_ativado_e[0] == 1)
    {
      myGLCD.setColor(0, 130, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[31])));
      myGLCD.print(buffer, 8, 144); // tabela_textos[31] = "TIMER 1:"
    }
    else
    {
      myGLCD.setColor(255, 255, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[31])));
      myGLCD.print(buffer, 8, 144); // tabela_textos[31] = "TIMER 1:"
    }

    if (temporizador_ativado_e[1] == 1)
    {
      myGLCD.setColor(0, 130, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[77])));
      myGLCD.print(buffer, 8, 156); // tabela_textos[77] = "TIMER 2:"
    }
    else
    {
      myGLCD.setColor(255, 255, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[77])));
      myGLCD.print(buffer, 8, 156); // tabela_textos[77] = "TIMER 2:"
    }

    if (temporizador_ativado_e[2] == 1)
    {
      myGLCD.setColor(0, 130, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[78])));
      myGLCD.print(buffer, 8, 168); // tabela_textos[78] = "TIMER 3:"
    }
    else
    {
      myGLCD.setColor(255, 255, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[78])));
      myGLCD.print(buffer, 8, 168); // tabela_textos[78] = "TIMER 3:"
    }

    if (temporizador_ativado_e[3] == 1)
    {
      myGLCD.setColor(0, 130, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[79])));
      myGLCD.print(buffer, 8, 180); // tabela_textos[79] = "TIMER 4:"
    }
    else
    {
      myGLCD.setColor(255, 255, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[79])));
      myGLCD.print(buffer, 8, 180); // tabela_textos[79] = "TIMER 4:"
    }

    if (temporizador_ativado_e[4] == 1)
    {
      myGLCD.setColor(0, 130, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[80])));
      myGLCD.print(buffer, 8, 192); // tabela_textos[80] = "TIMER 5:"
    }
    else
    {
      myGLCD.setColor(255, 255, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[80])));
      myGLCD.print(buffer, 8, 192); // tabela_textos[80] = "TIMER 5:"
    }
  }

  if ((whiteLed != wled_out) || refreshAll)  // Atualiza gráfico led branco
  {
    whiteLed = wled_out;
    ledLevel = LedToPercent(wled_out);

    drawFillRect(128, 144, 185, 156, 0, 0, 0);
    myGLCD.setColor(cor_canal[0][0], cor_canal[0][1], cor_canal[0][2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[1])));
    myGLCD.print(buffer, 125, 144); // nome_canal[1] = "BRA"

    offset = map(ledLevel, 100, 0, 28, 137);

    myGLCD.print(":", 149, 144);
    myGLCD.fillRect(61, offset, 91, 137);
    myGLCD.print(String(ledLevel), 157, 144);
    myGLCD.print("%", 181, 144);

    drawFillRect(61, offset , 91, 28, 0, 0, 0);
  }
  if ((blueLed != bled_out) || refreshAll)       // Atualiza gráfico led azul
  {
    blueLed = bled_out;
    ledLevel = LedToPercent(bled_out);

    drawFillRect(128, 156, 185, 168, 0, 0, 0);

    myGLCD.setColor(cor_canal[1][0], cor_canal[1][1], cor_canal[1][2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[2])));
    myGLCD.print(buffer, 125, 156); // nome_canal[2] = "AZU"

    offset = map(ledLevel, 100, 0, 28, 137);
    myGLCD.print(":", 149, 156);
    myGLCD.fillRect(97, offset, 127, 137);
    myGLCD.print(String(ledLevel), 157, 156);
    myGLCD.print("%", 181, 156);

    drawFillRect(97, offset , 127, 28, 0, 0, 0);
  }
  if ((azulroyalLed != rbled_out) || refreshAll)      // Atualiza gráfico led azul royal
  {
    azulroyalLed = rbled_out;
    ledLevel = LedToPercent(rbled_out);

    drawFillRect(128, 168, 185, 180, 0, 0, 0);

    myGLCD.setColor(cor_canal[2][0], cor_canal[2][1], cor_canal[2][2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[3])));
    myGLCD.print(buffer, 125, 168); // nome_canal[3] = "AZR"

    offset = map(ledLevel, 100, 0, 28, 137);
    myGLCD.print(":", 149, 168);
    myGLCD.fillRect(133, offset, 163, 137);
    myGLCD.print(String(ledLevel), 157, 168); 
    myGLCD.print("%", 181, 168);

    drawFillRect(133, offset , 163, 28, 0, 0, 0);
  }
/*  if ((vermelhoLed != rled_out) || refreshAll)    // Atualiza gráfico led  vermelho
  {
    vermelhoLed = rled_out;
    ledLevel = LedToPercent(rled_out);

    drawFillRect(128, 180, 185, 192, 0, 0, 0); // Apaga potência anterior

    myGLCD.setColor(cor_canal[3][0], cor_canal[3][1], cor_canal[3][2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[4])));
    myGLCD.print(buffer, 115, 180); // nome_canal[4] = "VER"

    offset = map(ledLevel, 100, 0, 28, 137);
    myGLCD.print(":", 152, 180);
    myGLCD.fillRect(137, offset, 157, 137);
    myGLCD.print(String(ledLevel), 160, 180);
    myGLCD.print("%", 186, 180);

    drawFillRect(137, offset - 1, 157, 27, 0, 0, 0); // Apaga barra anterior
  }
  if ((violetaLed != uvled_out) || refreshAll)      // Atualiza gráfico led violeta
  {
    violetaLed = uvled_out;
    ledLevel = LedToPercent(uvled_out);

    drawFillRect(128, 192, 185, 204, 0, 0, 0); // Apaga potência anterior

    myGLCD.setColor(cor_canal[4][0], cor_canal[4][1], cor_canal[4][2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[5])));
    myGLCD.print(buffer, 115, 192); // nome_canal[5] = "VIO"

    offset = map(ledLevel, 100, 0, 28, 137);
    myGLCD.print(":", 152, 192);
    myGLCD.fillRect(163, offset, 183, 137);
    myGLCD.print(String(ledLevel), 160, 192);
    myGLCD.print("%", 186, 192);

    drawFillRect(163, offset - 1, 183, 27, 0, 0, 0); // Apaga barra anterior
  }*/

  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(315, 10, 284, 20);                // Refrescar temperatura filtro
  myGLCD.fillRect(315, 24, 284, 38);                // Refrescar calentador    
  myGLCD.fillRect(315, 38, 284, 48);                // Refrescar temperatura arduino
  myGLCD.fillRect(315, 52, 284, 62);                // Refrescar ventilador
  myGLCD.fillRect(315, 66, 284, 76);                // Refrescar tempratura agua
  myGLCD.fillRect(315, 80, 284, 90);                // Refrescar ph acuario
 /* myGLCD.fillRect(316, 98, 377, /110);               // Refrescar noticia de calentador urna conectado/desconectado
  myGLCD.fillRect(316, 112, 377, 124);              // Refrescar noticia de co2 conectado/desconectado
  myGLCD.fillRect(316, 126, 377, 138);              // Refrescar noticia de relleno deposito conectado/desconectado
  myGLCD.fillRect(320, 140, 381, 152);              // Refrescar noticia de relleno acuario conectado/desconectado
  myGLCD.fillRect(320, 154, 381, 166);              // Refrescar noticia de niveles de agua deposito  normal/bajo
  myGLCD.fillRect(320, 168, 381, 180);              // Refrescar noticia de nivel agua urna  normal/bajo
  myGLCD.fillRect(320, 182, 381, 193);              // Refrescar noticia de TPA conectado/desconectado
  myGLCD.fillRect(320, 195, 381, 207);              // Refrescar noticia de estado fuente alimentacion leds
*/
  myGLCD.fillRect(80, 144, 110, 156);              // Apagar noticia de Timers 1 ligado/desligado
  myGLCD.fillRect(80, 156, 110, 168);              // Apagar noticia de Timers 2 ligado/desligado
  myGLCD.fillRect(80, 168, 110, 180);              // Apagar noticia de Timers 3 ligado/desligado
  myGLCD.fillRect(80, 180, 110, 192);              // Apagar noticia de Timers 4 ligado/desligado
  myGLCD.fillRect(80, 192, 110, 204);              // Apagar noticia de Timers 5 ligado/desligado


  myGLCD.setColor(0, 255, 0);
  myGLCD.printNumF(tempC, 1, 284, 10);   // Temperatura filtro
  myGLCD.printNumF(tempH, 1, 284, 38);   // Temperatura arduino
  myGLCD.printNumF(tempA, 1, 284, 66);   // Temperatura agua
  myGLCD.printNumF(PHA, 1, 284, 80);     // PH aqua(PHA, 2, 316, 42); 
 // myGLCD.printNumF(PHR, 2, 316, 70);     // PH deposito(PHR, 2, 316, 56);

    setFont(SMALL, 255, 255, 0, 0, 0, 0);    
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(200, 110, 310, 200);

  
    if (bitRead(status_parametros, 2) == true)
  {
      myGLCD.setColor(255, 0, 0);     
      myGLCD.printNumF( tempC, 1, 284, 10);     // Temperatura de filtro en Rojo
      setFont(SMALL, 255, 255, 0, 0, 0, 0);    
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(200, 110, 310, 200);
    myGLCD.setColor(255, 0, 0); 
       myGLCD.print("ALARMA", 233, 125);
       myGLCD.print("TEMPERATURA", 215, 145);
       myGLCD.print("FILTRO", 230, 165);
     

  }
  if (bitRead(status_parametros, 4) == true)
  {
      myGLCD.setColor(255, 0, 0);    
      myGLCD.printNumF( tempA, 1, 284, 66);     // Temperatura de Agua en Rojo
      setFont(SMALL, 255, 255, 0, 0, 0, 0);    
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(200, 110, 310, 200);
    myGLCD.setColor(255, 0, 0); 
       myGLCD.print("ALARMA", 233, 125);
       myGLCD.print("TEMPERATURA", 215, 145);
       myGLCD.print("ACUARIO", 230, 165);
   }
  if ((bitRead(status_parametros, 2) == false) & (bitRead(status_parametros, 4) == false) & (bitRead(status_parametros, 3) == false))
   {
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect(200, 110, 310, 200);
          myGLCD.setColor(0, 255, 0);       
          myGLCD.print("SISTEMA", 230, 125);
          myGLCD.print("FUNCIONANDO", 215, 145);
          myGLCD.print("OK", 250, 165);

  }
  
  if (bitRead(status_parametros, 6) == true) 
  {                               
    myGLCD.setColor(0, 130, 255);
    myGLCD.printNumI(LedToPercent(fanSpeed), 284, 52);    // ventilador conectado
    myGLCD.print("%", 306, 52);
  }
  else 
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 284, 52); 
  }
 
  if (bitRead(status_parametros, 3) == true)
  {
      myGLCD.printNumF(PHA, 1, 284, 80);       // PH de acuario en Rojo
  }
  /*
  if (bitRead(status_parametros, 6) == true)
  {
      myGLCD.printNumF(PHR, 2, 316, 70);       // PH de deposito en Rojo
    
  }
 */
  if (bitRead(status_parametros, 0) == true)
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 284, 24);           // calentador deposito conectado
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 284, 24);          // Calentador deposito apagado
  }
  /*
  if (bitRead(status_parametros, 1) == true)
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 319, 98);           // Calentador urna conectado
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 319, 98);         // Calentador urna apagado
  }
  if (bitRead(status_parametros, 5) == true)
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 319, 112);          // co2 conectado
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 319, 112);          // co2  apagado
  }

if (bitRead(status_parametros, 7) == true)
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 319, 196);           // FUENTE ON
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 319, 196);          // FUENTE OFF
  }

 if (bitRead(Status, 1) == true)
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 319, 140);           // relleno acuario activado
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 319, 140);          // relleno acuario desactivado
  }
 if (bitRead(Status, 2) == true) //     
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 319, 126);           // relleno deposito activado
  } 
  else
  {                
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 319, 126);          // relleno deposito activado
  }
  
  if (nivel_depo== true)
  {
    myGLCD.setColor(255, 0, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[196])));
    myGLCD.print(buffer, 319, 154);         // Nivel baixo em vermelho // tabela_textos[196] = "BAIXO!"
  }
  else
  {
    myGLCD.setColor(0, 255, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[197])));
    myGLCD.print(buffer, 319, 154);         // Nível nornal // tabela_textos[197] = "NORMAL"
  }

  if ((nivel_urna==true))  //comprovar nivel de urna 
  {             
    myGLCD.setColor(255, 0, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[196])));
    myGLCD.print(buffer, 319, 168);  // Nivel bajo  acuario  en rojo // tabela_textos[196] = "BAJO!"
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[197])));
    myGLCD.print(buffer, 319, 168);  // Nível nornal en acuario  // tabela_textos[197] = "NORMAL"
  }
  
  if ((bitRead(tpa_status, 1) == true) && (bitRead(tpa_status, 2) == false))
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 319, 182);           // TPA em andamento
  }
  else if ((bitRead(tpa_status, 1) == false) && (bitRead(tpa_status, 2) == false))
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 319, 182);           // TPA não esta em andamento
  }
  
  if (bitRead(tpa_status, 2) == true)
  {
    myGLCD.setColor(255, 0, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[86])));
    myGLCD.print(buffer, 319, 182);          // Sinaliza falha durante uma TPA // tabela_textos[86] = "FALHA!"
  }
  */
   if (bitRead(temporizador_status,1) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 85, 144);           // Timer 1 ligado
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 85, 144);          // Timer 1 desligado
  }

  if (bitRead(temporizador_status,2) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 85, 156);           // Timer 2 ligado
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 85, 156);          // Timer 2 desligado
  }
  if (bitRead(temporizador_status,3) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 85, 168);           // Timer 3 ligado
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 85, 168);          // Timer 3 desligado
  }
  if (bitRead(temporizador_status,4) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON",85, 180);           // Timer 4 ligado
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF",85, 180);          // Timer 4 desligado
  }
  if (bitRead(temporizador_status,5) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON",85, 192);           // Timer 5 ligado
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF",85, 192);          // Timer 5 desligado
  }
  /*  myGLCD.setColor(255, 0, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[236])));// "TEMPERATURA ALTA!"
    myGLCD.print(buffer, 58, 90);          // Alerta de temperatura alta para os LEDS.
  }
  if (temperatura_baixou == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[237]))); // "TEMP. BAIXOU!"
    myGLCD.setColor(0, 255, 0);
    myGLCD.print(buffer, 58, 90);          // Alerta de que a temperatura esteve alta para os LEDS.
  }*/
}
#endif
