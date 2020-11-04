static String morseLetters[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","0","1","2","3","4","5","6","7","8","9","."};
static String morseCodes[]={
/*a*/".-",
/*b*/"-...",
/*c*/"-.-.",
/*d*/"-..",
/*e*/".",
/*f*/"..-.",
/*g*/"--.",
/*h*/"....",
/*i*/"..",
/*j*/".---",
/*k*/"-.-",
/*l*/".-..",
/*m*/"--",
/*n*/"-.",
/*o*/"---",
/*p*/".--.",
/*q*/"--.-",
/*r*/".-.",
/*s*/"...",
/*t*/"-",
/*u*/"..-",
/*v*/"...-",
/*w*/".--",
/*x*/"-..-",
/*y*/"-.--",
/*z*/"--..",
/*0*/"-----",
/*1*/".----",
/*2*/"..---",
/*3*/"...--",
/*4*/"....-",
/*5*/".....",
/*6*/"-....",
/*7*/"--...",
/*8*/"---..",
/*9*/"----.",
/*.*/".-.-.-"
};

const int pin = 2;
int btn = 0;
unsigned long timeLen = 0;
unsigned long pauseLen = 0;
bool hasPressed = false;
String letter = "";
int nombreofletter = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin,INPUT);
}

void loop() {
  //Serial.println(String(millis())+"  "+String(millis() - pauseLen)+"  "+String(millis() - timeLen));
  //Serial.println(String(hasPressed));
  btn = digitalRead(pin);
  if(btn == HIGH){
    if(!hasPressed){
      if(millis() - pauseLen>400){
        Serial.print(" ");
      }
      //Serial.println("pause: ");
      //Serial.print(millis() - pauseLen);
      
      //Serial.print("1");
      timeLen = millis();
      hasPressed = true;

    }
    
  }else{
    if(hasPressed){
      //Serial.println(millis() - timeLen);
      if(millis() - timeLen<200){
        letter += ".";
       }else{
        letter += "-";
       }
      pauseLen = millis();
      hasPressed = false;
      //Serial.print(letter);

    }
    if((millis() - pauseLen>400) && letter != ""){
      nombreofletter = 0;
      for(byte i=0; i < (sizeof(morseLetters) / sizeof(String)); i++){
        if(letter==morseCodes[i]){
          nombreofletter=i;
        }
        Serial.println(morseLetters[nombreofletter]);
      }
      letter="";

    }
   }
  delay(10);
}
