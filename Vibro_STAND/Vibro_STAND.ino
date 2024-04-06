
int wire_break_analogPin = 0;
int power_connector = 7; // питание разъема
int timer = 0;
int buffer_timer = 0;
int timer_step = 5; // промежуток измерения температуры

void setup()
{ 
  pinMode(wire_break_analogPin, INPUT);
  pinMode (power_connector, OUTPUT); 
  digitalWrite(power_connector, HIGH);  
  Serial.begin(9600);
}


void loop() 
{
  //Serial.print ("ПРОВЕРКА  "); Serial.println (analogRead (wire_break_analogPin)); delay (100);
  if ( wire_break () ) // Проверка "РАЗРЫВА" соединения
  {
    Serial.print ("РАЗРЫВ СОЕДИНЕНИЯ  ");
    print_time ();
    }
  timer = millis() / 1000;  
  if (timer >= buffer_timer){
    if (!wire_break ()) {Serial.print ("СОЕДИНЕНИЯ  В НОРМЕ  ");}
    else {Serial.print ("РАЗРЫВ СОЕДИНЕНИЯ  ");}
    print_time ();
    buffer_timer = buffer_timer + timer_step;
    }
  }

  
  int wire_break () 
  {
    if (analogRead (wire_break_analogPin) < 1000) return 1;
    else return 0;
    }


     
  void print_time () 
  {
    int timer = 0;
    int sec = 0;
    int minute = 0;
    int hour = 0;
    timer = millis() / 1000;
    hour = timer / 3600;
    Serial.print(hour);
    Serial.print (": ");
    hour = hour * 3600;
    minute = timer - hour;
    minute = minute /60;
    Serial.print(minute);
    minute = minute * 60;
    Serial.print (": ");
    sec = timer - hour;
    sec = sec - minute;
    Serial.print(sec);
    Serial.println ("  ");
    }
  
 
