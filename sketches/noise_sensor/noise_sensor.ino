
/**
 * @brief This code reads the value from the analog port A0 and compares it to a maximum value
 * If the value read from A0 is greater than the maximum value, it triggers the alert
 * This is useful to detect when the volume of the cluster 2 is too high.
 */

/** Analog Pin Setting. */
int pino_analogico = 34;

/** Saves the value of the analog pin output. */
int valor_A0 = 0;

/** Save the max value of the analog pin output. */
int max_value = 0;
/** Max value Tolerated. */
int max_tolerance = 50;

void setup(void)
{
	Serial.begin(115200);
	pinMode(pino_analogico, INPUT);
}

void loop(void)
{
	valor_A0 = analogRead(pino_analogico);
	Serial.print("Saida A0: ");
	Serial.print(valor_A0);
	Serial.print(" Maior volume: ");
	Serial.println(max_value);
	// saves the max value
	if (valor_A0 > max_value)
		max_value = valor_A0;
	// Trigger alert if noise level is above max tolerance
	if (valor_A0 > max_tolerance)
	{
		Serial.print("Volume máximo atingido");
		delay(5000);
	}
	delay(1000);
}
