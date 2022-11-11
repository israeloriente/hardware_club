// Programa: Sensor de som KY-038
// Definicao pinos leds
// int pinoled_ver = 3;
// int pinoled_ama = 4;
// int pinoled_verm = 5;

// Definicao pinos sensor
int pino_analogico = 34;
/**
 * Pino digital não está sendo usado.
 */
int pino_digital = 5;

int valor_A0 = 0;
/**
 * Valor do pino analogico.
 */
int valor_D = 0;

/**
 * Valor máximo atingido pelo sensor
 */
int max_value = 0;

void setup(void)
{
	Serial.begin(115200);
	// Define pinos led como saida
	// pinMode(pinoled_ver, OUTPUT);
	// pinMode(pinoled_ama, OUTPUT);
	// pinMode(pinoled_verm, OUTPUT);
	// Define pinos sensor como entrada
	pinMode(pino_analogico, INPUT);
	pinMode(pino_digital, INPUT);
}

void loop(void)
{
	valor_A0 = analogRead(pino_analogico);
	valor_D = digitalRead(pino_digital);
	Serial.print("Saida A0: ");
	Serial.print(valor_A0);
	Serial.print(" Saida D0: ");
	Serial.print(valor_D);
	Serial.print(" Maior volume: ");
	Serial.println(max_value);
	if (valor_A0 > max_value)
		max_value = valor_A0;
	// Disparar alerta
	// if (valor_A0 > 30) {
	//   Serial.print("Volume máximo atingido");
	//   delay(5000);
	// }
	// Intensidade baixa
	if (valor_A0 > 20 && valor_A0 < 300)
	{
		// digitalWrite(pinoled_ver, HIGH);
		// digitalWrite(pinoled_ama, LOW);
		// digitalWrite(pinoled_verm, LOW);
	}
	// Intensidade media
	if (valor_A0 > 301 && valor_A0 < 700)
	{
		// digitalWrite(pinoled_ver, HIGH);
		// digitalWrite(pinoled_ama, HIGH);
		// digitalWrite(pinoled_verm, LOW);
	}
	// Intensidade alta
	if (valor_A0 > 701)
	{
		// digitalWrite(pinoled_ver, HIGH);
		// digitalWrite(pinoled_ama, HIGH);
		// digitalWrite(pinoled_verm, HIGH);
	}
	delay(500);
	// Apaga todos os leds
	// digitalWrite(pinoled_ver, LOW);
	// digitalWrite(pinoled_ama, LOW);
	// digitalWrite(pinoled_verm, LOW);
}
