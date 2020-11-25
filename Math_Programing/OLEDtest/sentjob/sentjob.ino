#include <Keypad.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);    //ประกาศสร้าง oject ที่ใช้ลองรับชื่อของอุปกรณ์

int first = 0;  
long second = 0;
double total = 0;
int time = 0 , Done = 0 , show = 0 ,Key = 0 , Encryption = 0 , Decryption = 0 ,numberic = 0;
String result ,resultEncryption , resultDecryption; 


char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {6,7,10,9};

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

String alphabet[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"}; 
void setup()
{
    oled.begin(0x3C);    
    Serial.begin(9600);

    oled.clearDisplay();      //ล้างหน้าจอแสดงผล
    oled.setCursor(0, 16);        //กำหนดตำตำแหน่ง curcor (แกน x, แกน y)
    oled.setTextColor(SSD1306_WHITE);         //กำหนดสีของตัวหนังสือ  (มีแค่สีขาว)
    oled.setTextSize(1);
    oled.println("Caesar Cipher Decoder");
    oled.display();
    delay(10);  
}

void loop()
{
  customKey = customKeypad.getKey();
    switch (customKey) 
    {
        case '0' ... '9':
        first = first * 10  + (customKey - '0');
        oled.clearDisplay();      //ล้างหน้าจอแสดงผล
        oled.setCursor(0, 0);        //กำหนดตำตำแหน่ง curcor (แกน x, แกน y)
        oled.setTextColor(SSD1306_WHITE);         //กำหนดสีของตัวหนังสือ  (มีแค่สีขาว)
        oled.setTextSize(1);
        oled.println(first);
        oled.display();
        break;
        
        case 'A':
        Key = first;
        oled.clearDisplay();      //ล้างหน้าจอแสดงผล
        oled.setCursor(0, 0);        //กำหนดตำตำแหน่ง curcor (แกน x, แกน y)
        oled.setTextColor(SSD1306_WHITE);         //กำหนดสีของตัวหนังสือ  (มีแค่สีขาว)
        oled.setTextSize(1);
        oled.println("Key = " + String(Key));
        oled.display();
        first = 0;
        break;

        case 'B' :

        if (first >= 26)
            {
                oled.clearDisplay();      //ล้างหน้าจอแสดงผล
                oled.setCursor(0, 0);        //กำหนดตำตำแหน่ง curcor (แกน x, แกน y)
                oled.setTextColor(SSD1306_WHITE);         //กำหนดสีของตัวหนังสือ  (มีแค่สีขาว)
                oled.setTextSize(1);
                oled.println("Error");

                oled.println("last_result = " + String(result));
                oled.display();
                first = 0;
                break;
            }

        show = first;
        oled.clearDisplay();      //ล้างหน้าจอแสดงผล
        oled.setCursor(0, 0);        //กำหนดตำตำแหน่ง curcor (แกน x, แกน y)
        oled.setTextColor(SSD1306_WHITE);         //กำหนดสีของตัวหนังสือ  (มีแค่สีขาว)
        oled.setTextSize(1);
        oled.println(alphabet[show]);
        oled.display();
        
        result = result + alphabet[show];
        oled.clearDisplay();      //ล้างหน้าจอแสดงผล
        oled.setCursor(0, 10);        //กำหนดตำตำแหน่ง curcor (แกน x, แกน y)
        oled.setTextColor(SSD1306_WHITE);         //กำหนดสีของตัวหนังสือ  (มีแค่สีขาว)
        oled.setTextSize(1);
        oled.println("last_result = " + String(result));
        oled.display(); 

        Encryption = ( first + Key ) % 26;
        resultEncryption = resultEncryption + alphabet[Encryption];

        if (Key > first) 
        {
        second = ( first - Key ) % 26;
        Serial.println(second);
        resultDecryption = resultDecryption + alphabet[26+second];
        first = 0;
        break;
        }
        if (Key <= first) 
        {
        Decryption = ( first - Key ) % 26;
        resultDecryption = resultDecryption + alphabet[Decryption];
        first = 0;
        break;
        }
       
        case 'C':
        oled.clearDisplay();      //ล้างหน้าจอแสดงผล
        oled.setCursor(0, 0);        //กำหนดตำตำแหน่ง curcor (แกน x, แกน y)
        oled.setTextColor(SSD1306_WHITE);         //กำหนดสีของตัวหนังสือ  (มีแค่สีขาว)
        oled.setTextSize(1);
        oled.println("result_Encryption = " +String(resultEncryption));
        oled.display();
        break;

        case 'D':
        oled.clearDisplay();      //ล้างหน้าจอแสดงผล
        oled.setCursor(0, 0);        //กำหนดตำตำแหน่ง curcor (แกน x, แกน y)
        oled.setTextColor(SSD1306_WHITE);         //กำหนดสีของตัวหนังสือ  (มีแค่สีขาว)
        oled.setTextSize(1);
        oled.println("result_Decryption = " +String(resultDecryption));
        oled.display();

        break;

        case '*':
        result = result + " ";
        resultEncryption = resultEncryption + " ";
        resultDecryption = resultDecryption + " ";
        oled.clearDisplay();      //ล้างหน้าจอแสดงผล
        oled.setCursor(0, 0);        //กำหนดตำตำแหน่ง curcor (แกน x, แกน y)
        oled.setTextColor(SSD1306_WHITE);         //กำหนดสีของตัวหนังสือ  (มีแค่สีขาว)
        oled.setTextSize(1);
        oled.println("last_result = " + String(result));
        oled.display();
        break;

      

    }

    

    
}

