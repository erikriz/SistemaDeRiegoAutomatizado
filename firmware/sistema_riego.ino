int relePin = 4;      // Pin digital donde está conectado el relé
int sensorPin = A0;   // Pin analógico donde está conectado el sensor de humedad

// Umbrales para diferentes niveles de humedad
int humedadBaja = 600;    // Suelo muy seco, activa la bomba por más tiempo
int humedadMedia = 400;   // Suelo intermedio, activa la bomba por menos tiempo
int humedadAlta = 250;    // Suelo húmedo, no activa la bomba

void setup() {
  pinMode(relePin, OUTPUT);     // Configura el pin del relé como salida
  digitalWrite(relePin, LOW);   // Inicialmente apaga la bomba
  Serial.begin(9600);           // Inicia la comunicación serial
}

void loop() {
  int humedadValor = analogRead(sensorPin);  // Leer el valor del sensor de humedad
  
  // Mostrar valor de humedad en Monitor Serial para depuración
  Serial.print("Valor de humedad: ");
  Serial.println(humedadValor);

  // Control del tiempo que la bomba se activa según la humedad
  if (humedadValor > humedadBaja) {
    // Suelo muy seco: enciende la bomba por 6 segundos
    digitalWrite(relePin, HIGH);
    Serial.println("Bomba activada: Suelo muy seco");
    delay(6000);  // La bomba se queda encendida por 6 segundos
    digitalWrite(relePin, LOW);
  } 
  else if (humedadValor > humedadMedia && humedadValor <= humedadBaja) {
    // Suelo intermedio: enciende la bomba por 3 segundos
    digitalWrite(relePin, HIGH);
    Serial.println("Bomba activada: Suelo intermedio");
    delay(3000);  // La bomba se queda encendida por 3 segundos
    digitalWrite(relePin, LOW);
  }
  else if (humedadValor <= humedadMedia) {
    // Suelo húmedo: apaga la bomba
    digitalWrite(relePin, LOW);
    Serial.println("Bomba desactivada: Suelo húmedo");
  }

  delay(2000);  // Pausa de 2 segundos antes de la próxima lectura
}
