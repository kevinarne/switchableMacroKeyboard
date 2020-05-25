#define ENA_PIN A1 // Enable pin that disables keyboard output

void setup() 
{
  pinMode(ENA_PIN, INPUT);

  Serial.begin(9600);
}

void loop() 
{
  int enabled = digitalRead(ENA_PIN);
  if (enabled)
  {
    Serial.println("Enabled");
  } 
  else 
  {
    Serial.println("Disabled");
  }
}
