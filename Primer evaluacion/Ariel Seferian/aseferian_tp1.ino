/*
Compilador:   IDE v1.0.5
Placa:        Arduino Uno R3
Red:          --
Version:      1.0.0
Fecha:        16-09-2014
Curso:        Seminario de tecnologia (2C 2014)
Alumno:       Ariel Seferian
*/

// Variables Luz
int light = 0; //Variable light


// Variables ruido
int noise = 0;

//=======================================================
/// Set-Up inicial del programa
//=======================================================
void setup() {
Serial.begin(9600); // Comienza comunicacion serial
}

//=======================================================
// Bucle principal
//=======================================================
void loop(){
  //Leo ruido
  noise = analogRead(A5); 
  
  //Leo el valor de la foto resistencia
  light = analogRead(A3); // Leer el pin analogico donde esta conectada la foto resistencia
  
  Serial.println("Ruido: ");
  Serial.println(noise);
  Serial.println("Luz: ");
  Serial.println(light);
  Serial.println("");
  delay(100); //Delay de 100 milisegundos
}