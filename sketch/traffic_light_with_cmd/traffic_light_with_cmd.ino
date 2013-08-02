

const int ledR = 10;
const int ledY =  9;
const int ledG =  8;

String inputString = "";
boolean strFlag = false;

boolean TLLoop = false;

// MAiN setup
void setup() 
{
  Serial.begin(9600);
  //Serial.write("Power On");
  inputString.reserve(200);
  pinMode(ledR, OUTPUT); 
  pinMode(ledY, OUTPUT); 
  pinMode(ledG, OUTPUT); 
}

// MAiN loop
void loop()
{

  if (TLLoop)
  {
      digitalWrite(ledR, HIGH); delay(1000);
      digitalWrite(ledY, HIGH); delay(1500);
      
      digitalWrite(ledR, LOW); 
      digitalWrite(ledY, LOW);      
      digitalWrite(ledG, HIGH);
      
      delay(2000);

      digitalWrite(ledG, LOW); 
      digitalWrite(ledY, HIGH); 
      
      delay(2000);
      
      digitalWrite(ledY, LOW); 
      digitalWrite(ledR, HIGH);
      
      delay(2000);      
      digitalWrite(ledR, LOW);  
  }
  
  
  // is there a string I can compare with?
  if (strFlag)
  {
    //Serial.println(inputString); 

    // compare input with commands
    if (inputString == "tl on")
    {
      TLLoop = true;
      Serial.println("traffic light on");
   
    }

    if (inputString == "tl off")
    {
      TLLoop = false;
      Serial.println("traffic light off");   
    }

    if (inputString == "bar")
    {
      Serial.println("switch off");
    }

    // clean up the string helper vars:
    inputString = "";
    strFlag = false;
  }

}   

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent()
{
  while (Serial.available())
  {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    //inputString += inChar;
    inputString.concat(inChar);
    delay (10);
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    /*
    if (inChar == '\n')
     {
     strFlag = true;
     break;
     } 
     */
  }
  strFlag = true;
}



