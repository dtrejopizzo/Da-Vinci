/*
Ejemplo para lectura de dos sensores (foto-resistencia y microfono) utilizando los puertos analogicos
A3 y A5 respectivamente.

Compilador:   IDE v1.0.5
Placa:        Arduino Uno R3
Red:          --
Version:      1.0.0
Fecha:        12-09-2014
Curso:        Seminario de tecnologia (2C 2014)
Alumno:       --
*/

// Variables Luz
int light = 0; //Variable light
int light0 = 0;
float Res0 = 0.4;

// Variables ruido
int lect = 0;
int noise = 0;
int threshold = 450; //Umbral de referencia medido para el amplificador LM741

//=======================================================
/// Set-Up inicial del programa
//=======================================================
void setup() {
Serial.begin(9600); // Comienza comunicacion serial}

//=======================================================
// Bucle principal
//=======================================================
void loop(){
  //Leo ruido y le resto el umbral del amplificador para mostrar el valor en dB
  int lect = analogRead(A5); 
  noise = lect - threshold; // En noise se guarda el valor leido.
  
  
  //Leo el valor de la foto resistencia y luego lo multiplico para hallar su equivalente en luxes
  light0 = analogRead(A3); // Leer el pin analogico donde esta conectada la foto resistencia
  float Vout0 = light0 * 0.0048828125; // Calculo el voltaje (ecuacion de la hoja de datos)
  light = 500 / (Res0 * ((5 - Vout0) / Vout0)); // En light se guarda el valor leido.
  
  Serial.println("Ruido en dB: ");
  Serial.println(noise);
  Serial.println("Luxes: ");
  Serial.println(light);
  Serial.println();
  delay(100); //Delay de 100 milisegundos}