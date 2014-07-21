const int sampleWindow = 50; // Ventana de nuestreo en msSample window width in mS (50 mS = 20Hz)
unsigned int sample;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  unsigned long startMillis= millis();  //Iniciamos la ventana de muestreo
  unsigned int peakToPeak = 0;   // Nivel pico a pico
  
  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;
  
  int prom=0;
  
  while (millis() - startMillis < sampleWindow) // Recolectamos datos por 50ms
  {
     sample = analogRead(0); // Conectamos la salida analógica del sensor a la entrada A0 de Arduino
     if (sample < 1024)  
     {
        if (sample > signalMax)
        {
           signalMax = sample;  // Señal máxima, muestreo
        }
        else if (sample < (signalMin))
        {
           signalMin = sample;  // Señal mínima, muestreo
        }
     }
  }
  Serial.print("Max = " );
  Serial.println(signalMax);
  Serial.print("Min = " );
  Serial.println(signalMin);
  prom=(signalMax+signalMin)/2;
  Serial.print("Prom = " );
  Serial.println(prom);
  //peakToPeak = signalMax - signalMin;  // Max - min = amplitud pico a pico
  //Serial.println(peakToPeak);
  Serial.println(" ");
  delay(1000);
}
