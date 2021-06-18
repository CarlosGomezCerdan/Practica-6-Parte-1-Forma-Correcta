#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

File myFile;

void setup() 
{
    Serial.begin(9600);
    Serial.print("Iniciando SD ...");
    SPI.begin(18,19,23,5);

    if (!SD.begin(5)) {
        Serial.println("No se pudo inicializar");
        return;
    }
    Serial.println("inicializacion exitosa");

    if (SD.exists("/archivoP6.txt")){

            Serial.println("archivoP6.txt exists. ");

            myFile=SD.open("/archivoP6.txt");

        if (myFile) {
        Serial.println("archivoP6.txt:");
        while (myFile.available()) {

            Serial.write(myFile.read());
        }
        myFile.close(); //cerramos el archivo
    } 
    else {

        Serial.println("Error al abrir el archivo");
    }
    }
    else{
            Serial.println("archivoP6.txt doesn't exist");
            
            myFile = SD.open("/archivoP6.txt", FILE_WRITE);//abrimos  el archivo 

            myFile.println("ESTO ES LA PRACTICA 6 PARTE 1");

            myFile.close();

            myFile=SD.open("/archivoP6.txt");

    if (myFile) {
        Serial.println("archivoP6.txt:");
        while (myFile.available()) {

            Serial.write(myFile.read());
        }
        myFile.close(); //cerramos el archivo
    }
    else {

        Serial.println("Error al abrir el archivo");
    } 
   
    }
}

void loop()
{ }