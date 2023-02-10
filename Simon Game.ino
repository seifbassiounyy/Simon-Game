/*
updated the timer
*/
int difficulty;
String x;
unsigned long prev ;
unsigned long current ;
int counter = 1;
int level;
int win = 1;
int rnd;
int v[50];
int sol[50];
int i,d;
int position;
int xposition = 0;
int yposition = 0;

void setup() 
{
  
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A5,INPUT);
  pinMode(A3,INPUT);
  Serial.println("Please enter difficulty level [ 1, 2, 3 ]");

}
void loop()
{
  if (Serial.available() >0 )
  {
    x = Serial.readStringUntil('\n');
    if (x[0] == '1')
    {
      d = 1000;
    }
    else if (x[0] == '2')
    {
      d = 500;
      
    }
    else if(x[0] == '3')
    {
      d = 300;
    }
    
    counter = 1;
    win =1;
    while(win)
    {
    Serial.print("Score = ");
    Serial.println(counter-1);
    i = 0;
    while(i<counter)
    {
      rnd = random(10,13);
      v[i] = rnd;
      
      delay(d);
      digitalWrite( v[i] ,HIGH);
      delay(d);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
      i+=1;
    }
    delay(2000);
  i = 0;
  Serial.println("GO!");
  prev = millis();
 
 while ( i<counter)
 {
   current = millis(); 
   if( (current - prev) >= 5000 )
  {
        Serial.println("Time is up");
        i = counter;
        prev += current ;
        
  }

  xposition = analogRead(A5);
  yposition = analogRead(A3);

  if( xposition >= 0 && xposition <=200)
  {
    position = 12;
    sol[i] = position;
    i+=1;
    Serial.println("up");
    //Serial.println(i);
    delay(1000);
  }
  else if(xposition<=1023 && xposition>=1000)
  {
    position = 10;
    sol[i] = position;
    i+=1;
    Serial.println("down");
    //Serial.println(i);
    delay(1000);
  }
  else if(yposition>=0 && yposition<=200)
  {
    position = 13;
    sol[i] = position;
    i+=1;
    Serial.println("right");
    //Serial.println(i);
    delay(1000);
  }
  else if(yposition<=1023 && yposition>=1000)
  {
    position = 11;
    sol[i] = position;
    i+=1;
    Serial.println("left");
    //Serial.println(i);
    delay(1000);
  }
  
 }

 // Serial.println("lamp");
 // for (int j = 0; j < counter; j++ )
  //{
  // Serial.println(v[j]);
    
 // }
 //  Serial.println("joystick");
  //for (int j = 0; j < counter; j++ )
  //{
  //  Serial.println(sol[j]);
    
 // }
  for (int j = 0; j < counter; j++ )
  {
  if ( v[j] != sol[j] )
    {
      Serial.println("GAME OVER!");
      win = 0;
      break;
    }
    
  }
  if(win == 1)
  {
    counter +=1;  
    Serial.print("UP TO LEVEL ");
    Serial.println(counter);
  }
   
  } 
    
    
}

}