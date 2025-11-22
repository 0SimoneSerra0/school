#include <Servo.h>
#include <LiquidCrystal_I2C.h>


// Definizione pin
#define p_led_b 2
#define p_rele 4
#define p_led_g 5 // IMPORTANTE: controlla la connessione del led giallo
#define p_pul_dx 6
#define p_servo_fin 7
#define p_vent_a 8
#define p_pul_sx 9
#define p_buz 11
#define p_vent_b 12
#define p_servo_por 13

#define p_foto A0
#define p_um_terr A1
#define p_gas A2
#define p_pir A3
#define p_um A4


#define max_gas 500
#define min_foto 300
#define max_umidita 500

#define t_doppio_click 300

#define t_scorrimento_lcd 1000

#define pausa_campanello 500

LiquidCrystal_I2C lcd(0x20, 16, 2);
Servo servo_porta;
Servo servo_finestra;


int val_dx = 0, val_sx = 0;
int vec_val_pul_dx = 0, vec_val_pul_sx = 0;
int pul_dx_n_click = 0, pul_sx_n_click = 0;
bool pul_dx_prem = false, pul_sx_prem = false;
bool pul_dx_dopp = false, pul_sx_dopp = false;

unsigned long t_pul_dx = 0, t_pul_sx = 0;


bool porta_aperta = false;
int val_foto = 0, val_um_terr = 0, val_gas = 0, val_pir = 0, val_um = 0;


char modalita_lcd = 'u'; // u = mostra umidità, c = mostra crediti
int stato_scorrimento = 0;
unsigned long t_att_scorrimento = 0;


unsigned long t_campanello = 0;
int stato_campanello = 0;

void registraInput();
void suonaCampanello();
void gestiscLcd();

void setup()
{
  //inizializzazione pin
  pinMode(p_led_b, OUTPUT);
  pinMode(p_rele, OUTPUT);
  pinMode(p_led_g, OUTPUT);
  pinMode(p_pul_dx, INPUT);
  pinMode(p_servo_fin, OUTPUT);
  pinMode(p_vent_a, OUTPUT);
  pinMode(p_pul_sx, INPUT);
  pinMode(p_buz, OUTPUT);
  pinMode(p_vent_b, OUTPUT);
  pinMode(p_servo_por, OUTPUT);

  pinMode(p_foto, INPUT);
  pinMode(p_um_terr, INPUT);
  pinMode(p_gas, INPUT);
  pinMode(p_pir, INPUT);
  pinMode(p_um, INPUT);


  lcd.init();
  lcd.backlight();

  servo_finestra.attach(p_servo_fin);
  servo_porta.attach(p_servo_por);
}

void loop()
{
  registraInput();

  // Campanello
  if(pul_dx_prem || stato_campanello == 1){
    suonaCampanello();
  }
  
  // Rileatore gas
  if(val_gas >= max_gas){
    digitalWrite(p_vent_a, 1);
    servo_finestra.write(180);
  }else{
    digitalWrite(p_vent_a, 0);
    servo_finestra.write(0);
  }

  // Sensore luce
  if(val_foto <= min_foto){
    digitalWrite(p_led_b, 1);
    digitalWrite(p_led_g, 1);
  }else{
    digitalWrite(p_led_g, 0);
    digitalWrite(p_led_b, 0);
  }

  if(pul_sx_dopp)
    modalita_lcd = modalita_lcd == 'u' ? 'c' : 'u';

  if(pul_dx_dopp){
    if(porta_aperta){
      servo_porta.write(0);
      porta_aperta = false;
    }else{
      servo_porta.write(180);
      porta_aperta = true;
    }
  }

  // lcd
  gestisciLcd();


  // Umidità
  if(val_um >= max_umidita){
    servo_finestra.write(0);
  }
}



void registraInput()
{

  // Rilevatore di stato basso dei pulsanti
  pul_dx_dopp = false;
  pul_dx_prem = false;
  pul_sx_dopp = false;
  pul_sx_prem = false;

  val_dx = digitalRead(p_pul_dx);
  val_sx = digitalRead(p_pul_sx);

  if(val_dx != vec_val_pul_dx && val_dx){
    pul_dx_n_click++;
    t_pul_dx = millis();
  }

  if(val_sx != vec_val_pul_sx && val_sx){
    pul_sx_n_click++;
    t_pul_sx = millis();
  }

  vec_val_pul_dx = val_dx;
  vec_val_pul_sx = val_sx;

  if(millis() - t_pul_dx <= t_doppio_click){
    if(pul_dx_n_click >= 2){
      pul_dx_dopp = true;
      pul_dx_n_click = 0;
    }
  }else if(pul_dx_n_click == 1){
    pul_dx_prem = true;
    pul_dx_n_click = 0;
  }

  if(millis() - t_pul_sx <= t_doppio_click){
    if(pul_sx_n_click >= 2){
      pul_sx_dopp = true;
      pul_sx_n_click = 0;
    }
  }else if(pul_sx_n_click == 1){
    pul_sx_prem = true;
    pul_sx_n_click = 0;
  }



  // Registrazione sensori analogici
  val_foto = analogRead(p_foto);
  val_um_terr = analogRead(p_um_terr);
  val_gas = analogRead(p_gas);
  val_pir = analogRead(p_pir);
  val_um = analogRead(p_um);

}

void suonaCampanello()  // Da sistemare
{
  if(stato_campanello == 0){
    tone(p_buz, pausa_campanello);
    t_campanello = millis();
    stato_campanello = 1;
  }

  if(stato_campanello == 1 && millis() - t_campanello > pausa_campanello){
    tone(p_buz, pausa_campanello * 3);
    stato_campanello = 0;
  }
}



void gestisciLcd()
{
  switch(modalita_lcd){
    case 'u':
      lcd.clear();
      lcd.home();
      lcd.print("Umidità: ");
      lcd.print((float)val_um / 1023.0);
      lcd.print("%");
      break;
    case 'c':
      if(millis() - t_att_scorrimento > t_scorrimento_lcd){
        lcd.clear();
        lcd.home();
        switch(stato_scorrimento){
          case 0:
            lcd.print(" UN PROGETTO DI ");
            lcd.setCursor(0,1);
            lcd.print("Alfonso Capone");
            stato_scorrimento++;
            t_att_scorrimento = millis();
            break;
          case 1:
            lcd.print("Alfonso Capone");
            lcd.setCursor(0, 1);
            lcd.print("Simone Serra");
            stato_scorrimento++;
            t_att_scorrimento = millis();
            break;
          case 2:
            lcd.print("Simone Serra");
            lcd.setCursor(0,1);
            lcd.print("Raffaele Vecchi");
            stato_scorrimento++;
            t_att_scorrimento = millis();
            break;
          case 3:
            lcd.print("Alfonso Capone");
            lcd.setCursor(0, 1);
            lcd.print("Simone Serra");
            stato_scorrimento = 0;
            t_att_scorrimento = millis();
            break;
        }
      }
  }
}