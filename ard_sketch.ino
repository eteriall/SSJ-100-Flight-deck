byte val = 0;

int port_a_rud_1 = A0;
int port_a_rud_2 = A1;
int port_a_reverse_1 = A3;
int port_a_reverse_2 = A4;
int port_a_air_brake = A5;
int port_a_flaps = A6;
int port_a_pedals = 0;
int port_digit_pedal_brake = 0;

int port_digit_chassis = 1;
int port_digit_ground_brake = 2;
int port_digit_RTO = 3;
int port_digit_nav = 4;
int port_digit_beacn = 5;
int port_digit_strob = 6;
int port_digit_land = 7;
int port_digit_taxi = 8;


void setup() {
  Serial.begin(115200);
  pinMode(port_a_rud_1, INPUT);
  pinMode(port_a_rud_2, INPUT);
  pinMode(port_a_reverse_1, INPUT);
  pinMode(port_a_reverse_2, INPUT);
  pinMode(port_a_air_brake, INPUT);
  pinMode(port_a_flaps, INPUT);

  pinMode(port_digit_chassis, INPUT_PULLUP);
  pinMode(port_digit_ground_brake, INPUT_PULLUP);
  pinMode(port_digit_RTO, INPUT_PULLUP);
  pinMode(port_digit_nav, INPUT_PULLUP);
  pinMode(port_digit_beacn, INPUT_PULLUP);
  pinMode(port_digit_strob, INPUT_PULLUP);
  pinMode(port_digit_land, INPUT_PULLUP);
  pinMode(port_digit_taxi, INPUT_PULLUP);
}

void loop() {
  val = map(analogRead(port_a_rud_1), 0, 1024, 0, 254);
  Serial.write(val);

  val = map(analogRead(port_a_rud_2), 0, 1024, 0, 254);
  Serial.write(val);

  val = map(analogRead(port_a_reverse_1), 0, 1024, 0, 254);
  Serial.write(val);

  val = map(analogRead(port_a_reverse_2), 0, 1024, 0, 254);
  Serial.write(val);

  val = map(analogRead(port_a_air_brake), 0, 1024, 0, 254);
  Serial.write(val);

  val = map(analogRead(port_a_flaps), 0, 1024, 0, 254);
  Serial.write(val);

  val = digitalRead(port_digit_chassis);
  Serial.write(val);

  val = digitalRead(port_digit_ground_brake);
  Serial.write(val);

  val = digitalRead(port_digit_RTO);
  Serial.write(val);

  val = digitalRead(port_digit_nav);
  Serial.write(val);

  val = digitalRead(port_digit_beacn);
  Serial.write(val);

  val = digitalRead(port_digit_strob);
  Serial.write(val);

  val = digitalRead(port_digit_land);
  Serial.write(val);

  val = digitalRead(port_digit_taxi);
  Serial.write(val);
  
  delay(100);

}
