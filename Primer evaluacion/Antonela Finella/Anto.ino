
// Variables Luz  
  int led =13; //El LED esta en el pin 13 
  int LDR_pin = A3; //Leeremos del pin 3
  int LDR_val = 0; //Variable para leer los datos del LDR 
  
  // Correccion en LDR_val, tiene que inicializarse en 0.
  
// Variables Sonido
  int lect = 0;
  int sonido = 0;
  int umbral = 450; //Umbral de referencia medido para el amplificador LM741
 


void setup() { 
  Serial.begin(9600);       // para ver los valores en consola
  pinMode(led, OUTPUT);    //declaramos el led como salida 
}

void loop() {
  //Leo ruido y le resto el umbral del amplificador para mostrar el valor en dB
  int lect = analogRead(A5); 
  sonido= lect - umbral; // En sonido se guarda el valor leido.
  
  // En el loop iremos leyendo continuamente del sensor LDR
  LDR_val = analogRead(LDR_pin);
  if (LDR_val>=20) // Si hay luz, apago el led
  { 
 digitalWrite(led, LOW); // Apagamos el LED
  } 
else if (LDR_val<20) // Si no hay luz, enciendo el led 
  { 
 digitalWrite(led, HIGH); // Encendemos el LED 
  } 
  Serial.println("Ruido en dB: ");
  Serial.println(sonido);//imprime por consola el valor 
  Serial.print("LDR = "); 
  Serial.println(LDR_val);//Imprime en consola el valor del sensor
      }           

