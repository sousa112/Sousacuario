//---------------------------------------------------------------------------------------------
void checkTempC()
{
  contador_temp ++;

  sensors.requestTemperatures();                                          // Chamada para todos os sensores.
#ifdef USE_FAHRENHEIT
  temperatura_agua_temp += (sensors.getTempF(sensor_agua));               // Lê temperatura da água
  temperatura_dissipador_temp += (sensors.getTempF(sensor_dissipador));   // Lê temperatura do dissipador
  temperatura_ambiente_temp += (sensors.getTempF(sensor_ambiente));       // Lê temperatura do dissipador
#else
  temperatura_agua_temp += (sensors.getTempC(sensor_agua));               // Lê temperatura da água
  temperatura_dissipador_temp += (sensors.getTempC(sensor_dissipador));   // Lê temperatura do dissipador
  temperatura_ambiente_temp += (sensors.getTempC(sensor_ambiente));       // Lê temperatura do dissipador
#endif

  if (contador_temp == 12)
  {
    tempC = temperatura_agua_temp / 12;
    tempH = temperatura_dissipador_temp / 12;
    tempA = temperatura_ambiente_temp / 12;
    contador_temp = 0;
    temperatura_agua_temp = 0;
    temperatura_dissipador_temp = 0;
    temperatura_ambiente_temp = 0;
  }
 ///////////////////////////////////////////////////
//// CONTROL PARAMETROS CALENTADOR ACUARIO//////// 
///////////////////////////////////////////////////
  if (tempC < (setTempC + offTempC + alarmTempC) && tempC > (setTempC - offTempC - alarmTempC)) 
  {
    
    bitWrite(status_parametros,2,0);                //no señaliza alarma de temperatura en pantalla principal
          
  }

  if (alarmTempC > 0)                        
  {
    if ((tempC >= (setTempC + offTempC + alarmTempC)) || (tempC <= (setTempC - offTempC - alarmTempC)))
    {
      
      bitWrite(status_parametros,2,1);              //señaliza temperatura alta en pantalla principal
        
    }
  }

  if (outlets_changed[0] == true)
  {
    outlets_changed[0] = false;
    bitWrite(status_parametros, 0, 0);
    SetRele(calentadorPin, LOW);
  }


  if ((outlets[0] == 0))   //MODO AUTO SELECCIONADO
  {
    if ((tempC < (setTempC + offTempC)) && (tempC > (setTempC - offTempC)))          // Desliga aquecedor e chiller
    {
      bitWrite(status_parametros, 0, 0);              //señaliza estado off en pantalla principal
      SetRele(calentadorPin, LOW);               //calentador urna desactivado
    }

    if (offTempC > 0)
    {
      if ((tempC > (setTempC + offTempC)))            
      {
        bitWrite(status_parametros, 0, 0);            //señaliza estado off en pantalla principal
        SetRele(calentadorPin, LOW);             //calentador urna desactivado
      }
      if ((tempC < (setTempC - offTempC)))            
      {
        bitWrite(status_parametros, 0, 1);            //señaliza estado on en pantalla principal
        SetRele(calentadorPin, HIGH);            //calentador deposito activado
      }
    }
   }

  if (outlets[0] == 1)  //MODO ON  SELECCIONADO
  {
    bitWrite(status_parametros, 0, 1);
    SetRele(calentadorPin, HIGH);
  }
  else if (outlets[0] == 2)  //MODO OFF SELECCIONADO
  {
    bitWrite(status_parametros, 0, 0);
    SetRele(calentadorPin, LOW);
  }


///////////////////////////////////////////////////
//// CONTROL PARAMETROS CALENTADOR DEPOSITO//////// 
///////////////////////////////////////////////////

  if (tempA < (setTempA + offTempA + alarmTempA) && tempA > (setTempA - offTempA - alarmTempA)) 
 {
    bitWrite(status_parametros,4,0);                //no señaliza alarma de temperatura en pantalla principal
          
  }

 if (alarmTempA > 0)                        
  {
   if ((tempA >= (setTempA + offTempA + alarmTempA)) || (tempA <= (setTempA - offTempA - alarmTempA)))
    {
      bitWrite(status_parametros,4,1);              //señaliza temperatura alta en pantalla principal
        
    }
  }
/*
 if (outlets_changed[1] == true)
  {
    outlets_changed[1] = false;
    bitWrite(status_parametros, 1, 0);  
    SetRele(calentadordepoPin, LOW);
  }

if ((outlets[1] == 0))  //MODO AUTOMATICO SELECCIONADO

 {
  if ((tempA < (setTempA + offTempA + alarmTempA)) && (tempA > (setTempA - offTempA - alarmTempA)))          
  {
   bitWrite(status_parametros,1,0);                //señaliza estado off en pantalla principal
   SetRele(calentadordepoPin, LOW);           //calentador deposito desactivado Controlado por el mega 2560

  }

  if (offTempA > 0)
  {
    if ((tempA > (setTempA + offTempA)))           
    {
      bitWrite(status_parametros,1,0);              //señaliza estado off en pantalla principal
      SetRele(calentadordepoPin, LOW);           //calentador deposito desactivado Controlado por el mega 2560
    
    }
    if ((tempA < (setTempA - offTempA)))        
    {
     bitWrite(status_parametros,1,1);              //señaliza estado on en pantalla principal
     SetRele(calentadordepoPin, HIGH);          //calentador deposito activado Controlado por el mega 2560
    }
  }

  if ((tempA > 40) || (tempA <10))
  {
    bitWrite(status_parametros,1,0);                //señaliza estado off en pantalla principal
    SetRele(calentadordepoPin, LOW);           //calentador deposito desactivado Controlado por el mega 2560
   }
}

if (outlets[1] == 1)  //MODO ON SELECCIONADO
  {
    bitWrite(status_parametros, 1, 1);
    SetRele(calentadordepoPin, HIGH);
  }
  else if (outlets[1] == 2) //MODO OFF SELECCIONADO
  {
    bitWrite(status_parametros, 1, 0);
    SetRele(calentadordepoPin, LOW);
  }
*/

///////////////////////////////////////////////////
////   FUNCION  CONTROL DE VENTILADORES    //////// 
///////////////////////////////////////////////////

  int tempval = int(tempH * 10);
  fanSpeed = map(tempval, (HtempMin * 10), (HtempMax * 10), 0, 255);       // Controle de velocidade das ventoinhas do dissipador

  if (fanSpeed < 0)
  {
    bitWrite(status_parametros,6,0);
    
    fanSpeed = 0;
   }
  if (fanSpeed > 255)
  {
    bitWrite(status_parametros,6,1);
    
    fanSpeed = 255;
  }
  analogWrite(fanPin, fanSpeed);

  if (tempH < HtempMin) // Desativa os coolers se a temperatura estiver abaixo da mínima definida.
  {
    SetRele(desativarFanPin, LOW);
  }
  else
  {
    SetRele(desativarFanPin, HIGH);
  }
}



///////////////////////////////////////////////////
////      FUNCION  RELLENO AGUA URNA       //////// 
///////////////////////////////////////////////////
/*
void reposicao_agua_urna () // acciona la bomba  de relleno de urna 

{

  if (outlets_changed[8] == true)
  {
    outlets_changed[8] = false;
    bitWrite(Status, 1, 0);
    SetRele(bomba_relleno_urna, LOW);
  }

if (outlets[8] == 0) //MODO AUTOMATICO SELECCIONADO
  {
    if((analogRead(sensor_minimodepo) > 400) && (analogRead(sensor_urna) > 400) && (bitRead(tpa_status,1) == false) && (bitRead(tpa_status,2) == false))

  {
    bitWrite(status_parametros,1,0);                //señaliza estado off calentador deposito en pantalla principal
    SetRele(bomba_relleno_urna,HIGH);          //Bomba de relleno urna activada Controlado por el mega 2560
    SetRele(calentadordepoPin, LOW);           //calentador deposito desactivado Controlado por el mega 2560
    bitWrite(Status,1,1);                           //señaliza relleno urna principal on en pantalla principal
    nivel_urna =true;
  }
  else
  {
    SetRele(bomba_relleno_urna, LOW);          //Desactiva bomba de relleno urna Controlado por el mega 2560
    bitWrite(Status,1,0);                           //señaliza relleno urna principal off en pantalla principal 
    nivel_urna =false;
  }
}
else if (outlets[8] == 1) //MODO ON SELECCIONADO
   {
    bitWrite(Status, 1, 1);
    SetRele(bomba_relleno_urna, HIGH);
   }
  else if (outlets[8] == 2) //MODO OFF SELECCIONADO
   {
    bitWrite(Status, 1, 0);
    SetRele(bomba_relleno_urna, LOW);
   }
}

///////////////////////////////////////////////////
////     FUNCION  RELLENO AGUA DEPOSITO    //////// 
///////////////////////////////////////////////////


void reposicao_agua_deposito() // acciona la solenoide de entrada de agua al deposito de cambios

{
    if (outlets_changed[7] == true)
  {
    outlets_changed[7] = false;
    bitWrite(Status,2,0);                            //señaliza relleno deposito on en pantalla principal
    SetRele(bomba_relleno_depo, LOW);           //Conecta Bomba de relleno de deposito
  }
    if (outlets[7] == 0) //MODO AUTOMATICO SELECCIONADO
      {
        if((analogRead(sensor_maximodepo) > 400) &&  (analogRead(sensor_seguridaddepo) > 400)) //////OPCION BUENA DE CONFIGUARCION
        //if((analogRead(sensor_maximodepo) > 400)) //////OPCION DE PRUEVA

  {
    nivel_depo =true;                        //Senaliza nivel bajo en deposito
    bitWrite(status_parametros,1,0);                  //señaliza estado off calentador deposito en pantalla principal
    SetRele(bomba_relleno_depo,HIGH);            //Conecta Bomba de relleno de deposito Controlado por el mega 2560
    SetRele(calentadordepoPin, LOW);             //calentador deposito desactivado Controlado por el mega 2560
    bitWrite(Status,2,1);                            //señaliza relleno deposito on en pantalla principal
    nivel_depo =true;
  }
  else
  {
    SetRele(bomba_relleno_depo, LOW);            //Apaga Bomba de relleno de deposito Controlado por el mega 2560
    bitWrite(Status,2,0);                             //señaliza relleno deposito off en pantalla principal
    nivel_depo =false;
  }
}
else if (outlets[7] == 1) //MODO ON SELECCIONADO 
   {
    bitWrite(Status, 2, 1);
    SetRele(bomba_relleno_depo, HIGH);
    //nivel_depo =true;
   }
  else if (outlets[7] == 2) //MODO OFF SELECCIONADO
   { 
    bitWrite(Status, 2, 0);
    SetRele(bomba_relleno_depo, LOW);
     nivel_depo =false;
   }
  }



void check_PH_reator()
{
  if (PHR < (setPHR + offPHR + alarmPHR) && PHR > (setPHR - offPHR - alarmPHR))
  {
    //bitWrite(status_parametros, 6, 0);
  }

  if (alarmPHR > 0)           // Liga o alarme
  {
    if ((PHR > (setPHR + offPHR + alarmPHR)) || (PHR <= (setPHR - offPHR - alarmPHR)))
    {
      //bitWrite(status_parametros, 6, 1);
    }
  }

}
*/
void check_PH_aquario()
{
  if (PHA < (setPHA + offPHA + alarmPHA) && PHA > (setPHA - offPHA - alarmPHA))
  {
    bitWrite(status_parametros, 3, 0);
  }
  if (alarmPHA > 0)           // Liga o alarme
  {
    if ((PHA >= (setPHA + offPHA + alarmPHA)) || (PHA <= (setPHA - offPHA - alarmPHA)))
    {
      bitWrite(status_parametros, 3, 1);
    }
  }
   if (outlets_changed[3] == true)
    {
    outlets_changed[3] = false;
    bitWrite(status_parametros, 5, 0);
    SetRele(Co2, LOW);  // Desliga co2 do reator de cálcio
    }

 if (outlets[3] == 0) //MODO AUTOMATICO SELECCIONADO
  {
    if ((PHR < 4) || (PHR > 10))
    {
      bitWrite(status_parametros, 5, 0);
     SetRele(Co2, LOW);  // Desliga co2 do reator de cálcio
    }
    else
    {
      if (PHR < setPHR)
      {
        bitWrite(status_parametros, 5, 0);
        SetRele(Co2, LOW);  // Desliga co2 do reator de cálcio
      }
      if (offPHR > 0)
      {
        if (PHR > setPHR)
        {
          bitWrite(status_parametros, 5, 1);
          SetRele(Co2, HIGH); // Liga co2 do reator de cálcio
        }
      }
    }
  }
else if (outlets[3] == 1) //MODO ON SELECCIONADO
  {
    bitWrite(status_parametros, 5, 1);
    SetRele(Co2, HIGH); // Liga co2 do reator de cálcio
  }
  else if (outlets[3] == 2) //MODO OFF SELECCIONADO
  {
    bitWrite(status_parametros, 5, 0);
    SetRele(Co2, LOW); // Liga co2 do reator de cálcio
  }
 }

void check_alarme()
{
  if ((bitRead(status_parametros, 2) == true) || (bitRead(status_parametros, 4) == true) || (bitRead(status_parametros, 3) == true))/* ||
      (bitRead(status_parametros, 6) == true) || (bitRead(status_parametros_1, 1) == true) || (bitRead(tpa_status, 2) == true))*/
  {
    digitalWrite (alarmPin, HIGH);
  }
  else
  {
    digitalWrite (alarmPin, LOW);
  }
}
/*
void reposicao_agua_doce () // abre a solenoide 1 se o nível estiver baixo e se a tpa não estiver em andamento
//e se o chiller estiver desligado e se o nível do sump não estiver anormal e se não houve falha durante uma tpa.
{
  if (outlets_changed[8] == true)
  {
    outlets_changed[8] = false;
    bitWrite(Status, 1, 0);
#ifdef USE_PCF8575
    PCF8575.SetRele(solenoide1Pin, LOW);
#else
    SetRele(solenoide1Pin, LOW);
#endif
  }

  if (outlets[8] == 0)
  {
    if ((analogRead(sensor3) > 400) && (analogRead(sensor2) > 400) && (bitRead(tpa_status, 1) == false) && (bitRead(status_parametros, 0) == false) && (bitRead(tpa_status, 2) == false))
    {
#ifdef USE_PCF8575
      PCF8575.SetRele(solenoide1Pin, HIGH);
#else
      SetRele(solenoide1Pin, HIGH);
#endif
      bitWrite(Status, 1, 1); //sinaliza reposição em andamento
    }
    else
    {
#ifdef USE_PCF8575
      PCF8575.SetRele(solenoide1Pin, LOW);
#else
      SetRele(solenoide1Pin, LOW);
#endif
      bitWrite(Status, 1, 0);
    }
  }
  else if (outlets[8] == 1)
  {
    bitWrite(Status, 1, 1);
#ifdef USE_PCF8575
    PCF8575.SetRele(solenoide1Pin, HIGH);
#else
    SetRele(solenoide1Pin, HIGH);
#endif
  }
  else if (outlets[8] == 2)
  {
    bitWrite(Status, 1, 0);
#ifdef USE_PCF8575
    PCF8575.SetRele(solenoide1Pin, LOW);
#else
    SetRele(solenoide1Pin, LOW);
#endif
  }
}*/
/*
#ifdef DISABLE_SKIMMER
void check_level_skimmer()
{
  if (outlets_changed[4] == true)
  {
    outlets_changed[4] = false;
#ifdef USE_PCF8575
    PCF8575.SetRele(skimmerPin, LOW);
#else
    SetRele(skimmerPin, LOW);
#endif
  }

  if (outlets[4] == 0)
  {
    if (analogRead(sensor3) < 400)
    {
#ifdef USE_PCF8575
      PCF8575.SetRele(skimmerPin, LOW);
#else
      SetRele(skimmerPin, LOW);
#endif
    }
    else
    {
#ifdef USE_PCF8575
      PCF8575.SetRele(skimmerPin, HIGH);
#else
      SetRele(skimmerPin, HIGH);
#endif
    }
  }
  else if (outlets[4] == 1)
  {
#ifdef USE_PCF8575
    PCF8575.SetRele(skimmerPin, HIGH);
#else
    SetRele(skimmerPin, HIGH);
#endif
  }
  else if (outlets[4] == 2)
  {
#ifdef USE_PCF8575
    PCF8575.SetRele(skimmerPin, LOW);
#else
    SetRele(skimmerPin, LOW);
#endif
  }
}
#endif
*/
