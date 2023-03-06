
/*
  Author: Felipe Nunes
  Course: IGEN 230
  Date: 07/12/21

  Line Tracking Code for 3rd route (works on route 1 and 2 as well)

The robot moves by controlling motors that are given directions from a wide range of sensor value 
permutations. Using data from 5 IR sensors, motors react accordingly to guide the robot through the 
course. The LEDs mounted on the robot indicate direction. The Left LED corresponds to a left turn, 
the right LED corresponds to a right turn, the middle LED corresponds to moving forwards, and if 
the robot moves backwards, all the LEDs are turned in.

*/

 // initialize 4 digital pins as an output.
void setup() {

  pinMode(5, OUTPUT);//in1
  pinMode(4, OUTPUT);//in2
  pinMode(3, OUTPUT);//in3
  pinMode(2, OUTPUT);//in4
  Serial.begin(9600);

}

//Both Wheels forward
void forward() {

  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
  analogWrite(6, 130);
  analogWrite(1, 130);

}

//Both wheels back
void back() {

  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
  analogWrite(6, 130);
  analogWrite(1, 130);

}

//Left wheel backward, right wheel forward
void left() {

  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
  analogWrite(6, 130);
  analogWrite(1, 190);

}

//Right wheel backward, left wheel forward
void right() {

  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
  analogWrite(6, 100);
  analogWrite(1, 130);

}

//Turn both motors off
void Stop() {
  
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  analogWrite(6, 0);
  analogWrite(1, 0);
  
}



void loop() {
  
  // Analog input - divide A0 input by factor of 2
  int sensor0 = analogRead(A0); //A0 input reading
  int sensor1 = analogRead(A1); //A1 input reading
  int sensor2 = analogRead(A2); //A2 input reading
  int sensor3 = analogRead(A3); //A3 input reading
  int sensor4 = analogRead(A4); //A4 input reading
  int LED1 = 11;
  int LED2 = 10;
  int LED3 = 9;
  int upper = 250;
  int lower = 200;

  //Prints sensor values to serial monitor
  Serial.print("sensor = ");
  Serial.print(sensor0);
  Serial.print(" sensor = ");
  Serial.print(sensor1);
  Serial.print(" sensor = ");
  Serial.print(sensor2);
  Serial.print(" sensor = ");
  Serial.print(sensor3);
  Serial.print(" sensor = ");
  Serial.print(sensor4);
  Serial.print("\n");

  //Forward Condition 1
  if (sensor1 <= lower && sensor2 >= upper && sensor3 <= lower) {

    forward();
    analogWrite(LED2, 100);
    delay(80);
    Stop();
    delay(80);
    analogWrite(LED2, 0);

  }

  //Forward Condition 2
  if (sensor1 >= upper && sensor2 >= upper && sensor3 >= upper) {

    forward();
    analogWrite(LED2, 100);
    delay(100);
    Stop();
    delay(100);
    analogWrite(LED2, 0);

  }

  //Right Condition 1
  else if (sensor3 >= upper) {

    right();
    analogWrite(LED3, 100);
    delay(100);
    Stop();
    delay(100);
    analogWrite(LED3, 0);

  }

  //Right Condition 2
  else if (sensor2 >= upper && sensor3 >= upper) {

    right();
    analogWrite(LED3, 100);
    delay(100);
    Stop();
    delay(100);
    analogWrite(LED3, 0);

  }

  //Right Condition 3

  else if (sensor2 >= upper && sensor3 >= upper && sensor4 >= upper) {

    right();
    analogWrite(LED1, 100);
    delay(100);
    Stop();
    delay(100);
    analogWrite(LED1, 0);

  }



  //Left Condition 1
  else if (sensor1 >= upper) {

    left();
    analogWrite(LED1, 100);
    delay(100);
    Stop();
    delay(80);
    analogWrite(LED1, 0);

  }

  //Left Condition 2
  else if (sensor1 >= upper && sensor2 >= upper) {

    left();
    analogWrite(LED1, 100);
    delay(100);
    Stop();
    delay(100);
    analogWrite(LED1, 0);

  }

  //Left Condition 3

  else if (sensor0 >= upper && sensor1 >= upper && sensor2 >= upper) {

    left();
    analogWrite(LED1, 100);
    delay(100);
    Stop();
    delay(100);
    analogWrite(LED1, 0);

  }

  //LEFT condition for last turn on course 3
  else if (sensor0 >= upper && sensor1 <= lower && sensor2 >= upper && sensor3 <= lower && sensor4 <= lower) {

    left();
    analogWrite(LED1, 100);
    delay(100);
    Stop();
    delay(100);
    analogWrite(LED1, 0);

  }

  //All white read on sensors
  else if ( sensor1 <= lower && sensor2 <= lower && sensor3 <= lower) {

    //Forward Condition
    if (sensor2 > sensor1 && sensor2 > sensor3) {

      forward();
      analogWrite(LED2, 100);
      delay(100);
      Stop();
      delay(100);
      analogWrite(LED2, 0);

    }

    //Left Condition
    else if (sensor1 > sensor2 && sensor1 > sensor3) {

      left();
      analogWrite(LED1, 100);
      delay(100);
      Stop();
      delay(100);
      analogWrite(LED1, 0);

    }

    //Right Condition
    else if (sensor3 > sensor2 && sensor3 > sensor1) {

      right();
      analogWrite(LED3, 100);
      delay(100);
      Stop();
      delay(100);
      analogWrite(LED3, 0);

    }

   //Once all other permutations are exhausted, turn wheels back
    else {

      back();
      analogWrite(LED1, 100);
      analogWrite(LED2, 100);
      analogWrite(LED3, 100);
      delay(100);
      Stop();
      delay(100);
      analogWrite(LED1, 0);
      analogWrite(LED2, 0);
      analogWrite(LED3, 0);

    }

  }

}
