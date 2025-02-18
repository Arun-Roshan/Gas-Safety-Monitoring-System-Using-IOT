#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128  
#define SCREEN_HEIGHT 64  
#define OLED_RESET -1  
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define MQ135_A0 A0  
#define MQ06_A0 A1    
#define DHTPIN 2      
#define BUZZER 3      

#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

#define TEMP_THRESHOLD 35  
#define HUM_THRESHOLD 70  

void setup() {
    Serial.begin(9600);
    pinMode(BUZZER, OUTPUT);
    dht.begin();

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("OLED initialization failed"));
        for (;;);
    }
    display.clearDisplay();
}

void loop() {
    int mq135_analog = analogRead(MQ135_A0);
    int mq06_analog = analogRead(MQ06_A0);
    float temp = dht.readTemperature();
    float humidity = dht.readHumidity();

    int mq135_threshold = 600;  
    int mq06_threshold = 500;   

    bool isSafe = (mq135_analog < mq135_threshold && mq06_analog < mq06_threshold);
    digitalWrite(BUZZER, isSafe ? LOW : HIGH);

    displaySlide("MQ-135: Air", mq135_analog, mq135_threshold, isSafe);
    delay(3000);
    displaySlide("MQ-06: Gas", mq06_analog, mq06_threshold, isSafe);
    delay(3000);
    displayTempHumidity(temp, humidity);
    delay(3000);
}

void displaySlide(String title, int value, int threshold, bool isSafe) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(30, 0);
    display.println(title);

    int barWidth = map(value, 0, 1023, 0, 100);
    display.drawRect(10, 15, 100, 10, WHITE);
    display.fillRect(10, 15, barWidth, 10, WHITE);

    display.setCursor(10, 32);
    display.print("Level: ");
    display.print(value);

    displayStatus(isSafe);
    display.display();
}

void displayTempHumidity(float temp, float humidity) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(20, 0);
    display.println("DHT11 Readings");

    display.setCursor(5, 15);
    display.print("Temp: "); display.print(temp); display.print(" C");

    int tempBar = map(temp, 0, 50, 0, 100);
    display.drawRect(5, 25, 118, 8, WHITE);
    display.fillRect(5, 25, tempBar, 8, WHITE);

    display.setCursor(5, 40);
    display.print("Hum: "); display.print(humidity); display.print("%");

    int humBar = map(humidity, 0, 100, 0, 100);
    display.drawRect(5, 50, 118, 8, WHITE);
    display.fillRect(5, 50, humBar, 8, WHITE);

    digitalWrite(BUZZER, (temp > TEMP_THRESHOLD || humidity > HUM_THRESHOLD) ? HIGH : LOW);
    display.display();
}

void displayStatus(bool isSafe) {
    display.setTextSize(1);
    display.setCursor(20, 55);
    if (isSafe) {
        display.println("STATUS: SAFE");
    } else {
        display.println("STATUS: ALERT!");
    }
}
