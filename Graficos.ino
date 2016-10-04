#ifdef USE_TFT
void tempgScreen()//------------------------------------------------------------ tela =11
{
  int x, y, z, grafico;
  int16_t n;
  char buf[8];
  float temperatura;
  int j = 0;
  int i = 0;
  int k = 0;
  float soma = 0.0f; // Soma dos valores de todos os elementos
  float media = 0.0f; // Média dos valores
  float linhaR;
  float linhaG;
  float linhaB;
  int f = 30;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[25])));
  printHeader(buffer); // tabela_textos[25] = "GRAFICO DE TEMPERATURA DA AGUA"

  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  for (float i = 31; i > 24.5; i -= 0.5)
  {
#ifdef USE_FAHRENHEIT
    float F = ((i * 1.8) + 32);
    myGLCD.printNumF(F, 1, 5, 3 + f);
#else
    myGLCD.printNumF(i, 1, 5, 3 + f);
#endif

    f += 15;
  }

  f = 255;
  for (int i = 22; i > 0; i -= 2)
  {
    myGLCD.printNumI(i, f, 225);  //pinta escala horaria parte inferior grafica.
    f -= 20;
  }

  myGLCD.print("0", 275, 225);
  myGLCD.drawCircle(15, 21, 2);

#ifdef USE_FAHRENHEIT
  myGLCD.print("F", 20, 18);
#else
  myGLCD.print("C", 20, 18);
#endif

  myGLCD.print("H", 290, 225);

  myGLCD.drawLine(40, 30, 40, 220); // Eixo y
  myGLCD.drawLine(40, 220, 290, 220);  // Eixo x

  myGLCD.setColor(64, 64, 64);  // Malha

  //EIXO X
  //for (int k = 40; k < 180; k += 15)
  //EIXO X LINEAS HORIZONTALES
    for(int k=40; k<220; k+=15)
  {
    myGLCD.drawLine(40, k, 290, k);
  }

  //EIXO Y
  //for (int l = 60; l < 300; l += 20)
   //EIXO Y LINEAS VERTICALES
  for(int l=60; l<300; l+=20)
  {
    myGLCD.drawLine(l, 30, l, 224);
  }

  linhaR = setTempC;  //  Linhas de comparação
  linhaG = (setTempC + offTempC);
  linhaB = (setTempC - offTempC);
#ifdef USE_FAHRENHEIT
  if ((linhaR >= 72.5) && (linhaR <= 81.5))
  {
    x = (190 - ((linhaR - 72.5) * 16.6667));
  }
  else if (linhaR > 81.5)
  {
    x = 30;
  }
  else if (linhaR < 72.5)
  {
    x = 190;
  }

  if ((linhaG >= 72.5) && (linhaG <= 81.5))
  {
    y = (190 - ((linhaG - 72.5) * 16.6667));
  }
  else if (linhaG > 81.5)
  {
    y = 30;
  }
  else if (linhaG < 72.5)
  {
    y = 190;
  }

  if ((linhaB >= 72.5) && (linhaB <= 81.5))
  {
    z = (190 - ((linhaB - 72.5) * 16.6667));
  }
  else if (linhaB > 81.5)
  {
    z = 30;
  }
  else if (linhaB < 72.5)
  {
    z = 190;
  }
#else
  if ((linhaR >= 25) && (linhaR <= 31))
  {
    x = (220 - ((linhaR - 25) * 30));
  }
  else if (linhaR > 31)
  {
    x = 30;
  }
  else if (linhaR < 25)
  {
    x = 220;
  }

  if ((linhaG >= 25) && (linhaG <= 31))
  {
    y = (220 - ((linhaG - 25) * 30));
  }
  else if (linhaG > 31)
  {
    y = 30;
  }
  else if (linhaG < 25)
  {
    y = 220;
  }

  if ((linhaB >= 25) && (linhaB <= 31))
  {
    z = (220 - ((linhaB - 25) * 30));
  }
  else if (linhaB > 31)
  {
    z = 30;
  }
  else if (linhaB < 25)
  {
    z = 220;
  }
#endif
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(40, x, 290, x);// Temperatura desejada
  myGLCD.setColor(10, 10, 255);        // Variação permitida
  myGLCD.drawLine(40, y, 290, y); // Variação mais
  myGLCD.drawLine(40, z, 290, z); // Variação menos

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);

  setFont(SMALL, 255, 255, 0, 0, 0, 0);

  int d = 41 + (NumMins(t.hour, t.min) / 6);

  myGLCD.drawLine(d, 30, d, 220); // Linea de marcacion horaria.
  myGLCD.print(rtc.getTimeStr(FORMAT_SHORT), d + 2, 75, 270);

  selecionar_SPI(SD_CARD);

  if (file.open("LOGTDIA.TXT", O_READ))
  {
    while ((n = file.read(buf, sizeof(buf))) > 0)
    {
      temperatura = atof(buf);
      soma += temperatura;

      if (strlen(buf) == 5)
      {
        i++;
        k++;
      }

      if (temperatura <= 2 )
      {
        k -= 1;
      }

      if (i == 6)
      {
        media = soma / k;
        i = 0;
        j++;
        soma = 0;
        k = 0;
#ifdef USE_FAHRENHEIT
        if ((media) > 81.5)
        {
          grafico = 30;
        }
        else if ((media >= 72.5) && (media <= 81.5))
        {
          grafico = (190 - ((media - 72.5) * (16.66667)));
        }
        else
        {
          grafico = 190;
        }
#else
        if ((media) > 31)
        {
          grafico = 30;
        }
        else if ((media >= 25) && (media <= 31))
        {
          grafico = (220 - ((media - 25) * 30));
        }
        else
        {
          grafico = 220;
        }
#endif
        setFont(SMALL, 255, 0, 255, 0, 0, 0);

        if (j < 250)
        {
          myGLCD.drawPixel((40 + j), grafico);
        }
      }
    }
    file.close();
  }
}


void tempDgScreen()//------------------------------------------------------------ tela =12
{
  int x, y, z, grafico;
  int16_t n;
  char buf[8];
  float temperatura;
  int j = 0;
  int i = 0;
  int k = 0;
  float soma = 0.0f; // Soma dos valores de todos os elementos
  float media = 0.0f; // Média dos valores
  float linhaR;
  float linhaG;
  float linhaB;
  int f = 30;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[26])));
  printHeader(buffer); // tabela_textos[26] = "GRAFICO DE TEMPERATURA DA AGUA DEPOSITO"

  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  for(float i = 26; i > 19.5; i -= 0.5)

  {
    myGLCD.printNumF(i, 1, 5, 3 + f);// pinta graduacion temperatura lado izquierdo
    f += 15; 
  }

  f = 255;
  for(int i = 22; i > 0; i -= 2)
  {
    myGLCD.printNumI(i, f, 225); //pinta escala horaria parte inferior grafica
    f -= 20;
  }
  
  myGLCD.print("0", 275, 225); 
  myGLCD.drawCircle(15, 21, 2);  
  myGLCD.print("C", 20, 18);
  myGLCD.print("H", 290, 225);

  myGLCD.drawLine(40, 30, 40, 220); // LINEA VERTICAL
  myGLCD.drawLine(40, 220, 290, 220);  // LINEA HORIZONTAL

  myGLCD.setColor(64, 64, 64);  // Malha

  //EIXO X LINEAS HORIZONTALES
  for(int k=40; k<220; k+=15)
  {
    myGLCD.drawLine(40, k, 290, k);
  }

  //EIXO Y LINEAS VERTICALES
  for(int l=60; l<300; l+=20)
  {
    myGLCD.drawLine(l, 30, l, 224);
  }

  linhaR =setTempA;   //  Linhas de comparação
  linhaG =(setTempA+offTempA);
  linhaB = (setTempA-offTempA);

  if ((linhaR >= 20) && (linhaR <= 26))
  {
    x= (220 - ((linhaR - 20) * 30));
  }
  else if (linhaR > 26)
  {
    x = 30;
  }
  else if (linhaR < 20)
  {
    x = 220;
  }

  if ((linhaG >= 20) && (linhaG <= 26))
  {
    y = (220-((linhaG - 20) * 30));
  }
  else if (linhaG > 26)
  {
    y = 30;
  }
  else if (linhaG < 20)
  {
    y = 220;
  }

  if ((linhaB >= 20) && (linhaB <= 26))
  {
    z = (220 -((linhaB - 20) * 30));
  }
  else if (linhaB > 26)
  {
    z = 30;
  }
  else if (linhaB < 20)
  {
    z = 220;
  }

  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(40, x, 290, x); // Temperatura desejada
  myGLCD.setColor(10, 10, 255);   // Variação permitida
  myGLCD.drawLine(40, y, 290, y); // Variação mais
  myGLCD.drawLine(40, z, 290, z); // Variação menos

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);

  setFont(SMALL, 255, 255, 0, 0, 0, 0);

  int d = 41 + (NumMins(t.hour,t.min) / 6);

  myGLCD.drawLine(d, 30, d, 220); // Linha de marcação do horário.
  myGLCD.print(rtc.getTimeStr(FORMAT_SHORT), d + 2, 75, 270);

  selecionar_SPI(SD_CARD);

    if (file.open("LOGTDDIA.TXT", O_READ))
 
  {
    while ((n = file.read(buf, sizeof(buf))) > 0)
    {
      temperatura = atof(buf);
      soma +=temperatura;

      if(strlen(buf) == 5)
      {
        i++;
        k++;
      }

      if (temperatura <= 2 )
      {
        k -= 1;
      }

      if (i == 6)
      {
        media = soma / k;
        i = 0;
        j++;
        soma = 0;
        k = 0;

        if ((media) > 26)
        {
          grafico = 30;
        }
        else if ((media >= 20) && (media <= 26))
        {
          grafico = (220 -((media - 20) * 30));
        }
        else
        {
          grafico = 220;
        }
        setFont(SMALL, 255, 0, 255, 0, 0, 0);

        if(j < 250)
        {
          myGLCD.drawPixel((40 + j), grafico);
        }
      }
    }
    file.close();
  }
}

void PHAScreen()//-------------------------------ph do aqua-----------------------------tela =13
{
  float x, y, z;
  float ph = setPHA;
  float phmais = offPHA;
  float phmenos = offPHA;
  float linhaR;
  float linhaG;
  float linhaB;
  int j = 0;
  int i = 0;
  int k = 0;
  float soma = 0.0f; // soma dos valores de todos os elementos
  float media = 0.0f; // média dos valores.
  int grafico;
  int16_t n;
  char buf[7];
  float pht;
  int f = 30;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[27])));
  printHeader(buffer); //tabela_textos[27] = "GRAFICO DE PH DO AQUARIO"
  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  for(float i = 8.4; i > 5.9; i -= 0.2)
  {
    myGLCD.printNumF(i, 1, 10, 3 + f);
    f += 15;
  }

  f = 255;
  for (int i = 22; i > 0; i -= 2)
  {
    myGLCD.printNumI(i, f, 225);
    f -= 20;
  }
  myGLCD.print("0", 275, 225);
  myGLCD.print("PH", 17, 18);
  myGLCD.print("H", 290, 225);

  
  myGLCD.drawLine(40, 30, 40, 220);  // LINEA VERTICAL
  myGLCD.drawLine(40, 220, 290, 220);// LINEA HORIZONTAL

  myGLCD.setColor(64, 64, 64);            //malha
  //EIXO X LINEAS HORIZONTALES
  for (int k = 40; k < 220; k += 15)
  {
    myGLCD.drawLine(40, k, 290, k);
  }

  //EIXO Y LINEAS VERTICALES
  for (int l = 60; l < 300; l += 20)
  {
     myGLCD.drawLine(l, 30, l, 224);
  }

  linhaR = ph; //  Linhas de comparacao
  linhaG = ph + phmais;
  linhaB = ph - phmenos;

  if ((linhaR >= 6) && (linhaR <= 8.4))
  {
    x = 220 - ((linhaR - 6) * 75);
  }
  else if (linhaR > 8.4)
  {
    x = 30;
  }
  else if (linhaR < 6)
  {
    x = 220;
  }

  if ((linhaG >= 6) && (linhaG <= 8.4))
  {
    y = 220 - ((linhaG - 6) * 75);
  }
  else if (linhaG > 8.4)
  {
    y = 30;
  }
  else if (linhaG < 6)
  {
    y = 220;
  }

  if ((linhaB >= 6) && (linhaB <= 8.4))
  {
    z = 220 - ((linhaB - 6) * 75);
  }
  else if (linhaB > 8.4)
  {
    z = 30;
  }
  else if (linhaB < 6)
  {
    z = 220;
  }

  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(40, x, 290, x);//PH desejado
  myGLCD.setColor(10, 10, 255);  //Variacao permitida
  myGLCD.drawLine(40, y, 290, y); //variacao mais
  myGLCD.drawLine(40, z, 290, z); //variacao menos

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);

  setFont(SMALL, 255, 255, 0, 0, 0, 0);

  int d = 41 + (NumMins(t.hour, t.min) / 6);

  myGLCD.drawLine(d, 30, d, 220); // Linha de marcação do horário.
  myGLCD.print(rtc.getTimeStr(FORMAT_SHORT), d + 2, 75, 270);

  selecionar_SPI(SD_CARD);

  if (file.open("LOGPDIA.TXT", O_READ))
  {
    while ((n = file.read(buf, sizeof(buf))) > 0)
    {
      pht = atof(buf);
      soma += pht;

      if (strlen(buf) == 4)
      {
        i++;
        k++;
      }

      if (pht <= 2 )
      {
        k -= 1;
      }

      if (i == 6)
      {
        media = soma / k;
        i = 0;
        j++;
        soma = 0;
        k = 0;

        if ((media) > 8.4)
        {
          grafico = 30;
        }
        else if ((media >= 6) && (media <= 8.4))
        {
          grafico = (220 - ((media - 6) * 75));
        }
        else
        {
          grafico = 220;
        }
        setFont(SMALL, 255, 0, 255, 0, 0, 0);

        if (j < 250)
        {
          myGLCD.drawPixel((40 + j), grafico);
        }
      }
    }
    file.close();
  }
}

void PHRScreen()//----------------PH do reator --------------------------------------------tela =17
{
  float x, y, z;
  float ph = setPHR;
  float phmais = offPHR;
  float phmenos = offPHR;
  float linhaR;
  float linhaG;
  float linhaB;
  int j = 0;
  int i = 0;
  int k = 0;
  float soma = 0.0f; // soma dos valores de todos os elementos
  float media = 0.0f; // média dos valores.
  int grafico;
  int16_t n;
  char buf[7];
  float pht;
  int f = 30;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[28])));
  printHeader(buffer); //tabela_textos[28] = "GRAFICO DE PH DO REATOR DE CALCIO"

  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  for(float i = 8.4; i > 5.9; i -= 0.2)
  {
    myGLCD.printNumF(i, 1, 10, 3 + f);
    f += 15;
  }

  f = 255;
  for (int i = 22; i > 0; i -= 2)
  {
    myGLCD.printNumI(i, f, 225);
    f -= 20;
  }
  myGLCD.print("0", 275, 225);
  myGLCD.print("PH", 17, 18);
  myGLCD.print("H", 290, 225);

  myGLCD.drawLine(40, 30, 40, 220); //eixo y
  myGLCD.drawLine(40, 220, 290, 220);  //eixo x

  myGLCD.setColor(64, 64, 64);            //malha

  //EIXO X
  for (int k = 40; k < 220; k += 15)
  {
    myGLCD.drawLine(40, k, 290, k);
  }

  //EIXOY
  for (int l = 60; l < 300; l += 20)
  {
    myGLCD.drawLine(l, 30, l, 224);
  }

  linhaR = ph; //  Linhas de comparacao
  linhaG = ph + phmais;
  linhaB = ph - phmenos;

  if ((linhaR >= 6) && (linhaR <= 8.4))
  {
    x = 220 - ((linhaR - 6) * 75);
  }
  else if (linhaR > 8.4)
  {
    x = 30;
  }
  else if (linhaR < 6)
  {
    x = 220;
  }

  if ((linhaG >= 6) && (linhaG <= 8.4))
  {
    y = 220 - ((linhaG - 6) * 75);
  }
  else if (linhaG > 8.4)
  {
    y = 30;
  }
  else if (linhaG < 6)
  {
    y = 220;
  }

  if ((linhaB >= 6) && (linhaB <= 8.4))
  {
    z = 220 - ((linhaB - 6) * 75);
  }
  else if (linhaB > 8.4)
  {
    z = 30;
  }
  else if (linhaB < 6)
  {
    z = 220;
  }
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(40, x, 290, x);//PH desejado
  myGLCD.setColor(10, 10, 255);  //Variacao permitida
  myGLCD.drawLine(40, y, 290, y); //variacao mais
  myGLCD.drawLine(40, z, 290, z); //variacao menos

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);

  setFont(SMALL, 255, 255, 0, 0, 0, 0);

  int d = 41 + (NumMins(t.hour, t.min) / 6);

  myGLCD.drawLine(d, 30, d, 220); // Linha de marcação do horário.
  myGLCD.print(rtc.getTimeStr(FORMAT_SHORT), d + 2, 75, 270);

  selecionar_SPI(SD_CARD);

  if (file.open("LOGRDIA.TXT", O_READ))
  {
    while ((n = file.read(buf, sizeof(buf))) > 0)
    {
      pht = atof(buf);
      soma += pht;

      if (strlen(buf) == 4)
      {
        i++;
        k++;
      }
      if (pht <= 2 )
      {
        k -= 1;
      }
      if (i == 6)
      {
        media = soma / k;
        i = 0;
        j++;
        soma = 0;
        k = 0;

        if ((media) > 8.4)
        {
          grafico = 30;
        }
        else if ((media >= 6) && (media <= 8.4))
        {
          grafico = (220 - ((media - 6) * 75));
        }
        else
        {
          grafico = 220;
        }
        setFont(SMALL, 255, 0, 255, 0, 0, 0);

        if (j < 250)
        {
          myGLCD.drawPixel((40 + j), grafico);
        }
      }
    }
    file.close();
  }
}

#endif
