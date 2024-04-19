#define GREEN 9
#define RED 8
#define BUTTON 10
String output = "";
int color;
void setup(){
    Serial.begin(9600);

    pinMode(GREEN, OUTPUT);
    pinMode(RED, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);

    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);

    Serial.println("aby rozpoczac, wcisnij przycisk");
}



void loop (){
    if (digitalRead(BUTTON) == LOW) { //Jeśli przycisk jest wciśnięty
        digitalWrite(GREEN, LOW);
        digitalWrite(RED, LOW);

        color = random(2) + 8;
        digitalWrite(color, HIGH);
        Serial.println("jaki kolor swieci?"); 
    
        while (Serial.available() <= 0)
        {}
            output = Serial.readString(); 
            Serial.println(output);
            if (color == 9 && output == "zielony"){
                Serial.println("Dobrze!");
                
            } else if (color == 8 && output == "czerwony"){
                Serial.println("Dobrze!");
                
            } else {
                Serial.println("Zle!");
                
            }
          
    }
}