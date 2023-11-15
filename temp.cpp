// Biblioteca LCD
#include <LiquidCrystal.h>

// Inicializa a biblioteca LCD
LiquidCrystal LCD(12,11,5,4,3,2);

// Define o pino analogico A0 como entrada do Sensor de Temperatura
int SensorTempPino=0;

// Define o pino 8 para o alerta de temperatura baixa
int AlertaTempBaixa=8;
// Define o pino 13 para o alerta de temperatura alta
int AlertaTempAlta=13;

// Define temperatura baixa como abaixo de zero grau Celsius
int TempBaixa=0;
// Define temperatura alta como acima de 40 graus Celsius
int TempAlta=40;

void setup() {
	// Define o pino de alerta de temperatura baixa como saida
  	pinMode(AlertaTempBaixa, OUTPUT);
	// Define o pino de alerta de temperatura alta como saida
	pinMode(AlertaTempAlta, OUTPUT);

	// Define a quantidade de colunas e linhas do LCD
	LCD.begin(16,2);
	// Imprime a mensagem no LCD
	LCD.print("Temperatura:");
	// Muda o cursor para a primeira coluna e segunda linha do LCD
	LCD.setCursor(0,1);
	// Imprime a mensagem no LCD
	LCD.print("      C        F");
}

void loop() {
	// Faz a leitura da tensao no Sensor de Temperatura
	int SensorTempTensao=analogRead(SensorTempPino);

  	// Converte a tensao lida
	float Tensao=SensorTempTensao*5;
	Tensao/=1024;

  	// Converte a tensao lida em Graus Celsius
	float TemperaturaC=(Tensao-0.5)*100;

  	// Converte a temperatura em Graus Celsius para Fahrenheit
	float TemperaturaF=(TemperaturaC*9/5)+32;

  	// Muda o cursor para a primeira coluna e segunda linha do LCD
  	LCD.setCursor(0,1);

  	// Imprime a temperatura em Graus Celsius
	LCD.print(TemperaturaC);

  	// Muda o cursor para a decima coluna e segunda linha do LCD
	LCD.setCursor(9,1);

  	// Imprime a temperatura em Graus Fahrenheit
  	LCD.print(TemperaturaF);

	// Acende ou apaga os alertas luminosos de temperatura baixa e alta
  	if (TemperaturaC>=TempAlta) {
  		digitalWrite(AlertaTempBaixa, LOW);
  		digitalWrite(AlertaTempAlta, HIGH);
    }
  	else if (TemperaturaC<=TempBaixa){
  		digitalWrite(AlertaTempBaixa, HIGH);
  		digitalWrite(AlertaTempAlta, LOW);
  	}
  	else {
  		digitalWrite(AlertaTempBaixa, LOW);
  		digitalWrite(AlertaTempAlta, LOW);
    }

  	// Aguarda 1 segundo
  	delay(1000);
}  