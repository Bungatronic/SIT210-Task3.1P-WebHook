// Include library for DHT22 Temperature sensor
#include <Adafruit_DHT.h>

#define DHTPIN 2            // Define pin we are connected to
#define DHTTYPE DHT22       // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);   // Initialise DHT sensor

void setup() {
    Serial.begin(9600);
    dht.begin();
}



void loop() {
    // Variables
    float hum;  
    float temp; 
    
    // Read data and store it to variables hum and temp
    hum = dht.getHumidity();
    temp= dht.getTempCelcius();
    
    // Print temp and humidity values to serial monitor
    Serial.printlnf("Humidity: %f", hum);
    Serial.printlnf("Temp: %f celsius", temp);
    
    // Publish temp variable to ThingSpeak API
    Particle.publish("temp", String(temp), PRIVATE);
    
    // Delay 30 seconds
    delay(30000); 
}