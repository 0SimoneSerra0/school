// C++ code
//
#include <LiquidCrystal_I2C.h>

#define T_FRAME 0

LiquidCrystal_I2C lcd(0x20, 16, 2);
const int ROWS = 2;
const int COLS = 16;
char _map[ROWS][COLS];

#define P_SU 2
#define P_GIU 3
#define P_START 4


char ciclo_scorso = 0b00000000; // 8° bit: P_SU, 7° bit: P_GIU, 6° bit: P_START

char stato_inputs = 0b00000000; // 8° bit: P_SU premuto, 7° bit: P_GIU premuto, 6° bit: P_START premuto


bool personaggio_su = true;

int score = 0;

bool start = false;
bool game_over = false;
bool msg_benvenuto = false;

bool crea_ostacolo = true;

void getInputs();
void resetGame();




void setup()
{
  pinMode(P_SU, INPUT);
  pinMode(P_GIU, INPUT);
  pinMode(P_START, INPUT);

  
  lcd.init();
  lcd.backlight();
  
  for(int r = 0; r < ROWS; ++r){
    for(int c = 0; c < COLS; ++c){
    	_map[r][c] = '\0';
    }
  }
  
  randomSeed(analogRead(A0));
  //Serial.begin(9600);
}

void loop()
{
  getInputs();

  if(!start && stato_inputs & 0b00000100)
    start = true;


  if(start){

    for(int r = 0; r < ROWS; ++r){
      for(int c = 0; c < COLS; ++c){
        _map[r][c] = _map[r][c != COLS - 1 ? c + 1 : c];
      }
    }
    
    if(stato_inputs & 0b00000001){
      personaggio_su = true;
    }
    if(stato_inputs & 0b00000010){
      personaggio_su = false;
    }


    if(personaggio_su){
      if(_map[0][0] == '\1')
        game_over = true;
      else if(_map[1][0] == '\1')
        score += 70;
      _map[0][0] = '\2';
      _map[1][0] = '\0';
    }else{
      if(_map[1][0] == '\1')
        game_over = true;
      else if(_map[0][0] == '\1')
        score += 70;
      _map[1][0] = '\2';
      _map[0][0] = '\0';
    }
    
    
    lcd.clear();
    if(!game_over){
      crea_ostacolo = true;
      for(int r = 0; r < ROWS; ++r){
        if(_map[r][COLS - 2] == '\1'){
            crea_ostacolo = false;
            break;
        }
      }
    
      for(int r = 0; r < ROWS; ++r){
        _map[r][COLS - 1] = '\0';
      }
    
      if(crea_ostacolo){
        int rand = random(ROWS + 1);
        if(rand != ROWS)
          _map[rand][COLS - 1] = '\1';
      }
    
      String string_lcd = "";
      for(int r = 0; r < ROWS; ++r){
        for(int c = 0; c < COLS; ++c){
            if(_map[r][c] == '\0'){
              string_lcd += " ";
            }else if(_map[r][c] == '\1')
              string_lcd += "|";
            else if(_map[r][c] == '\2')
              string_lcd += "P";
        
        }
      }
      
      lcd.print(string_lcd.substring(0, COLS));
      lcd.setCursor(0, 1);
      lcd.print(string_lcd.substring(COLS));
    }else{
      lcd.home();
      lcd.clear();
      lcd.print("GAME OVER!");
      lcd.setCursor(0, 1);
      lcd.print("Score: ");
      lcd.print(score);
      start = false;
    }
  }else if(game_over){
    if(stato_inputs & 0b00000100){
      resetGame();
      game_over = false;
    }
  }else if(!msg_benvenuto){
    lcd.print("   FLAPPY LCD   ");
    lcd.setCursor(0, 1);
    lcd.print("Premere START");
    msg_benvenuto = true;
  }


  if((stato_inputs & 0b00000111) == 0b00000111){
    resetGame();
    game_over = false;
    start = false;
    msg_benvenuto = false;
  }
    
}





// [Simone] Volevo provare a aggiornare tutte le variabili senza allocarne altre, è un casino ma era una sfida personale
void getInputs(){

  stato_inputs = (stato_inputs & 0b11111000) + digitalRead(P_SU) + (digitalRead(P_GIU) << 1) + (digitalRead(P_START) << 2);


  if(!(stato_inputs & 0b00000001) && (ciclo_scorso & 0b00000001)){
    ciclo_scorso = (ciclo_scorso & 0b11111110) + (stato_inputs & 0b1);
    stato_inputs = stato_inputs | 0b00000001;
  }else{
    ciclo_scorso = (ciclo_scorso & 0b11111110) + (stato_inputs & 0b1);
    stato_inputs = stato_inputs & 0b11111110;
  }

  if(!(stato_inputs & 0b00000010) && (ciclo_scorso & 0b00000010)){
    ciclo_scorso = (ciclo_scorso & 0b11111101) + (stato_inputs & 0b10);
    stato_inputs = stato_inputs | 0b00000010;
  }else{
    ciclo_scorso = (ciclo_scorso & 0b11111101) + (stato_inputs & 0b10);
    stato_inputs = stato_inputs & 0b11111101;
  }

  if(!(stato_inputs & 0b00000100) && (ciclo_scorso & 0b00000100)){
    ciclo_scorso = (ciclo_scorso & 0b11111011) + (stato_inputs & 0b100);
    stato_inputs = stato_inputs | 0b00000100;
  }else{
    ciclo_scorso = (ciclo_scorso & 0b11111011) + (stato_inputs & 0b100);
    stato_inputs = stato_inputs & 0b11111011;
  }


}


void resetGame(){
  score = 0;
  lcd.clear();
  lcd.home();
  for(int r = 0; r < ROWS; ++r){
    for(int c = 0; c < COLS; ++c){
      _map[r][c] = '\0';
    }
  }
}
