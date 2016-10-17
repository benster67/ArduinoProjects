const int MIN_BUTTON = 0;
const int MIN_LED = 8;
const int NUM_COLORS = 4;
const int HIGH_ANALOG_THRESHOLD = 1000;

const unsigned int MAX_SEQUENCE = 20;
int current_sequence_length = 0;
int color_sequence[MAX_SEQUENCE_LENGTH];

const unsigned int show_color_delay;
const unsigned int sequence_presentation_delay = 800;

void simon_sequence_add();
void simon_sequence_present();

void setup()
{
  Serial.begin(9600);
  
  for (int i = 0; i < NUM_COLORS; ++i) {
    pinMode(MIN_LED + i, OUTPUT);
  }
}

void loop()
{
  if (current_sequence_length >= MAX_SEQUENCE_LENGTH) {
    // GAME OVER (maximum sequence length met or exceeded)
    current_sequence_length = 0;
  }

  simon_sequence_add();
  simon_sequence_present();
  simon_sequence_read();
  /*
  for (int i = 0; i < NUM_COLORS; ++i) {
    if (analogRead(MIN_BUTTON + i) >= HIGH_ANALOG_THRESHOLD) {
      digitalWrite(MIN_LED + i, HIGH);
    } else {
      digitalWrite(MIN_LED + i, LOW);
    }
  }
  */

  delay(25);
}

void simon_sequence_add()
{
  int random_color = get_random_color();
  color_sequence[current_sequence_length] = random_color;
  ++current_sequence_length;
}

void simon_sequence_present()
{
  for (int i = 0; i < current_sequence_length; ++i) {
    const int color = MIN_LED + color_sequence[i];
    digitalWrite(color, HIGH);
    delay(show_color_delay);
    digitalWrite(color, LOW);
    delay(sequence_presentation_delay);
  }
}
