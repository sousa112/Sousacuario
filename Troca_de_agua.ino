/*
void checktpa()
{
  if (outlets_changed[6] == true)
   {
    outlets_changed[6] = false;
    SetRele(valvula_vacio_urna, LOW);
   }
  if (outlets_changed[7] == true)
   {
    outlets_changed[7] = false;
    SetRele(bomba_relleno_depo, LOW);
   }

if (outlets_changed[8] == true)
  {
    outlets_changed[8] = false;
    SetRele(bomba_relleno_urna, LOW);
  }


 if ((outlets[6] == 0) && (outlets[7] == 0) && (outlets[8] == 0))
{
  tempo = (duracaomaximatpa * 60000ul);

  if ((semana[0] == t.dow) || (semana[1] == t.dow) || (semana[2] == t.dow) || (semana[3] == t.dow) || (semana[4] == t.dow) || (semana[5] == t.dow) || (semana[6] == t.dow))
  {
    if ((hora == t.hour) && (minuto == t.min) && (tpa == 0))
    {
      tpa = 1;
      if ((4294967295ul - tempo) < millis())
      {
        marcadoriniciotpa = millis() - (tempo * 2);
      }
      else
      {
        marcadoriniciotpa = millis();
      }
    }
  }

  if ((4294967295ul - tempo) < millis())
  {
    shiftedmillis = millis() - (tempo * 2);
  }
  else
  {
    shiftedmillis = millis();
  }

 if ((analogRead(sensor_maximodepo) < 400) && (analogRead(sensor_minimourna) < 400) && (tpa == 1) && ((shiftedmillis - marcadoriniciotpa) < tempo)) 

  {//etapa 1
#ifdef USE_PCF8575  //etapa 1
    PCF8575.SetRele(valvula_vacio_urna, HIGH); //Activa electrovalvula de vaciado de urna Controlado por el Modulo PCF8575
    PCF8575.SetRele(bomba_relleno_urna, LOW);  //Desactiva bomba de relleno urna Controlado por el Modulo PCF8575
#else
    SetRele(valvula_vacio_urna,HIGH);          //Activa electrovalvula de vaciado de urna Controlado por el mega 2560
    SetRele(bomba_relleno_urna,LOW);           //Desactiva bomba de relleno urna Controlado por el mega 2560
#endif
    Serial.println("VACIANDO URNA PRINCIPAL");
    tpa = 2;
    bitWrite(tpa_status, 1, 1);
    if ((4294967295ul - tempo) < millis()) //zera o cronometro para o proximo estagio
    {
      marcadoriniciotpa = millis() - (tempo * 2);
    }
    else
    {
      marcadoriniciotpa = millis();
    }
  }
  
  else if ((analogRead(sensor_minimourna) > 400) && (tpa == 2) && ((shiftedmillis - marcadoriniciotpa) < tempo))
  {//etapa 2
#ifdef USE_PCF8575  //etapa 2
    PCF8575.SetRele(valvula_vacio_urna, LOW);   //Desactiva electrovalvula de vaciado de urna Controlado por el Modulo PCF8575
    PCF8575.SetRele(bomba_relleno_urna, HIGH);  //Activa bomba de relleno urna Controlado por el Modulo PCF8575
#else
    SetRele(valvula_vacio_urna,LOW);            //Desactiva electrovalvula de vaciado de urna Controlado por el mega 2560
    SetRele(bomba_relleno_urna,HIGH);           //Activa bomba de relleno urna Controlado por el mega 2560
#endif
    Serial.println("RELLENANDO URNA PRINCIPAL");
    tpa = 3;
    bitWrite(tpa_status, 1, 1);
    if ((4294967295ul - tempo) < millis()) //zera o cronometro para o proximo estagio
    {
      marcadoriniciotpa = millis() - (tempo * 2);
    }
    else
    {
      marcadoriniciotpa = millis();
    }
  }
 
  else if ((analogRead(sensor_urna) > 400) && (analogRead(sensor_minimourna) < 400) && (tpa == 3) && ((shiftedmillis - marcadoriniciotpa) < tempo)) 
  {// etapa 0 
#ifdef USE_PCF8575 // etapa 0 
    PCF8575.SetRele(valvula_vacio_urna, LOW);  //Desactiva electrovalvula de vaciado de urna Controlado por el Modulo PCF8575
    PCF8575.SetRele(bomba_relleno_urna, LOW);  //Desactiva bomba de relleno urna Controlado por el Modulo PCF8575
#else
    SetRele(valvula_vacio_urna, LOW);          //Desactiva electrovalvula de vaciado de urna Controlado por el mega 2560
    SetRele(bomba_relleno_urna, LOW);          //Desactiva bomba de relleno urna Controlado por el mega 2560
#endif
    bitWrite(tpa_status, 1, 0);
    tpa = 0;  
  }
    else if ((((shiftedmillis - marcadoriniciotpa) >= tempo) && (bitRead(tpa_status,1)== true)) || ((analogRead(sensor_minimodepo) < 400) && (bitRead(tpa_status,1)== true))) //CODIGO ORIGINAL 2015
     else if (((shiftedmillis - marcadoriniciotpa) >= tempo) && (bitRead(tpa_status, 1) == true)) //PRUEVA

  {
#ifdef USE_PCF8575
    PCF8575.SetRele(valvula_vacio_urna, LOW); //desliga as bombas todas e mete tpa=0 para não entrar no ciclo outra vez
    PCF8575.SetRele(bomba_relleno_urna, LOW);
#else
    SetRele(valvula_vacio_urna, LOW); //de todas las bombas y poner tpa = 0 no para entrar en el ciclo de nuevo
    SetRele(bomba_relleno_urna, LOW); //Desactiva bomba de relleno urna Controlado por el mega 2560
#endif
    tpa = 0;
    bitWrite(tpa_status, 1, 0);
    bitWrite(tpa_status, 2, 1);
    Salvar_erro_tpa_EEPROM();
  }
}

if (outlets[6] == 1) //MODO ON SELECCIONADO
   {
   SetRele(valvula_vacio_urna, HIGH);
   }

  if (outlets[6] == 2) //MODO OFF SELECCIONADO
  {
   SetRele(valvula_vacio_urna, LOW);
  }

if (outlets[7] == 1) //MODO ON SELECCIONADO
   {
   SetRele(bomba_relleno_depo, HIGH);
    bitWrite(Status, 2, 1);
   }

  if (outlets[7] == 2) //MODO OFF SELECCIONADO
  {
   SetRele(bomba_relleno_depo, LOW);
   bitWrite(Status, 2, 0);
   nivel_depo =false;
  }

if (outlets[8] == 1) //MODO ON SELECCIONADO
   {
   SetRele(bomba_relleno_urna, HIGH);
   bitWrite(Status, 1, 1);
   }

  if (outlets[8] == 2) //MODO OFF SELECCIONADO
  {
   SetRele(bomba_relleno_urna, LOW);
   bitWrite(Status, 1, 0);
   nivel_urna =false;
  }


  
}
*/
