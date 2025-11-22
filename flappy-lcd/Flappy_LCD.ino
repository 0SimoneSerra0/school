// C++ code
//
#include <LiquidCrystal_I2C.h>
#include "note.h"

#define T_FRAME 0

LiquidCrystal_I2C lcd(0x20, 16, 2);
const int ROWS = 2;
const int COLS = 16;
char _map[ROWS][COLS];

#define P_SU 2
#define P_GIU 3
#define P_START 4
#define P_BUZ 5

#define D_SPARTITO 631
#define P_BUZ 5

int spartito[D_SPARTITO][3] = {       // [x][0] = durata nota, [x][1] = nota, [x][2] = pausa
{125, NOTE_D4, 125},
{125, NOTE_D4, 125},
{250, NOTE_D5, 250},
{250, NOTE_A4, 375},
{125, NOTE_GS4, 250},
{250, NOTE_G4, 250},
{250, NOTE_F4, 250},
{125, NOTE_D4, 125},
{125, NOTE_F4, 125},
{125, NOTE_G4, 125},
{125, NOTE_C4, 62},
{125, NOTE_C4, 62},
{125, NOTE_C4, 62},
{125, NOTE_C4, 62},
{250, NOTE_D5, 250},
{375, NOTE_A4, 375},
{125, NOTE_GS4, 250},
{250, NOTE_G4, 250},
{250, NOTE_F4, 250},
{125, NOTE_D4, 125},
{125, NOTE_F4, 125},
{125, NOTE_G4, 125},
{125, NOTE_B3, 125},
{125, NOTE_B3, 125},
{250, NOTE_D5, 250},
{375, NOTE_A4, 375},
{125, NOTE_GS4, 250},
{250, NOTE_G4, 250},
{250, NOTE_F4, 250},
{125, NOTE_D4, 125},
{125, NOTE_F4, 125},
{125, NOTE_G4, 125},
{62, NOTE_AS3, 62},
{62, NOTE_AS3, 62},
{62, NOTE_AS3, 62},
{62, NOTE_AS3, 62},
{250, NOTE_AS5, 250},
{375, NOTE_AS4, 375},
{125, NOTE_AS4, 250},
{250, NOTE_G4, 250},
{250, NOTE_F4, 250},
{125, NOTE_D4, 125},
{125, NOTE_F4, 125},
{125, NOTE_G4, 125},
{125, NOTE_D4, 125},
{125, NOTE_D4, 125},
{250, NOTE_D5, 250},
{375, NOTE_A4, 375},
{125, NOTE_GS4, 250},
{250, NOTE_G4, 250},
{250, NOTE_F4, 250},
{125, NOTE_D4, 125},
{125, NOTE_F4, 125},
{125, NOTE_G4, 125},
{125, NOTE_C4, 62},
{125, NOTE_C4, 62},
{125, NOTE_C4, 62},
{125, NOTE_C4, 62},
{250, NOTE_D5, 250},
{375, NOTE_A4, 375},
{125, NOTE_GS4, 250},
{250, NOTE_G4, 250},
{250, NOTE_F4, 250},
{125, NOTE_D4, 125},
{125, NOTE_F4, 125},
{125, NOTE_G4, 125},
{125, NOTE_B3, 125},
{125, NOTE_B3, 125},
{250, NOTE_D5, 250},
{375, NOTE_A4, 375},
{125, NOTE_GS4, 250},
{250, NOTE_G4, 250},
{250, NOTE_F4, 250},
{125, NOTE_D4, 125},
{125, NOTE_F4, 125},
{125, NOTE_G4, 125},
{62, NOTE_AS3, 62},
{62, NOTE_AS3, 62},
{62, NOTE_AS3, 62},
{62, NOTE_AS3, 62},
{250, NOTE_D5, 250},
{375, NOTE_A4, 375},
{125, NOTE_GS4, 250},
{250, NOTE_G4, 250},
{250, NOTE_F4, 250},
{125, NOTE_D4, 125},
{125, NOTE_F4, 125},
{125, NOTE_G4, 125},
{125, NOTE_D5, 125},
{125, NOTE_D5, 125},
{250, NOTE_D6, 250},
{250, NOTE_A5, 325},
{125, NOTE_GS5, 250},
{250, NOTE_G5, 250},
{250, NOTE_F5, 250},
{125, NOTE_D5, 125},
{125, NOTE_F5, 125},
{125, NOTE_G5, 125},
{125, NOTE_C5, 125},
{125, NOTE_C5, 125},
{250, NOTE_D6, 250},
{250, NOTE_A5, 325},
{125, NOTE_GS5, 250},
{250, NOTE_G5, 250},
{250, NOTE_F5, 250},
{125, NOTE_D5, 125},
{125, NOTE_F5, 125},
{125, NOTE_G5, 125},
{125, NOTE_B4, 125},
{125, NOTE_B4, 125},
{250, NOTE_D6, 250},
{250, NOTE_A5, 325},
{125, NOTE_GS5, 250},
{250, NOTE_G5, 250},
{250, NOTE_F5, 250},
{125, NOTE_D5, 125},
{125, NOTE_F5, 125},
{125, NOTE_G5, 125},
{125, NOTE_AS4, 125},
{125, NOTE_AS4, 125},
{250, NOTE_D6, 250},
{250, NOTE_A5, 325},
{125, NOTE_AS5, 250},
{250, NOTE_G5, 250},
{250, NOTE_F5, 250},
{125, NOTE_D5, 125},
{125, NOTE_F5, 125},
{125, NOTE_G5, 125},
{125, NOTE_D5, 125},
{125, NOTE_D5, 125},
{250, NOTE_D6, 250},
{250, NOTE_A5, 325},
{125, NOTE_GS5, 250},
{250, NOTE_G5, 250},
{250, NOTE_F5, 250},
{125, NOTE_D5, 125},
{125, NOTE_F5, 125},
{125, NOTE_G5, 125},
{125, NOTE_C5, 125},
{125, NOTE_C5, 125},
{250, NOTE_D6, 250},
{250, NOTE_A5, 325},
{125, NOTE_GS5, 250},
{250, NOTE_G5, 250},
{250, NOTE_F5, 250},
{125, NOTE_D5, 125},
{125, NOTE_F5, 125},
{125, NOTE_G5, 125},
{125, NOTE_B4, 125},
{125, NOTE_B4, 125},
{250, NOTE_D6, 250},
{250, NOTE_A5, 325},
{125, NOTE_GS5, 250},
{250, NOTE_G5, 250},
{250, NOTE_F5, 250},
{125, NOTE_D5, 125},
{125, NOTE_F5, 125},
{125, NOTE_G5, 125},
{125, NOTE_AS4, 125},
{125, NOTE_AS4, 125},
{250, NOTE_D6, 250},
{250, NOTE_A5, 325},
{125, NOTE_GS5, 250},
{250, NOTE_G5, 250},
{250, NOTE_F5, 250},
{125, NOTE_D5, 125},
{125, NOTE_F5, 125},
{125, NOTE_G5, 125},
{250, NOTE_F5, 250},
{125, NOTE_F5, 125},
{125, NOTE_F5, 250},
{250, NOTE_F5, 250},
{250, NOTE_F5, 250},
{250, NOTE_D5, 250},
{625, NOTE_D5, 625},
{250, NOTE_F5, 250},
{125, NOTE_F5, 125},
{125, NOTE_F5, 250},
{250, NOTE_G5, 250},
{250, NOTE_GS5, 250},
{42, NOTE_G5, 42},
{42, NOTE_GS5, 42},
{42, NOTE_G5, 42},
{125, NOTE_F5, 125},
{125, NOTE_D5, 125},
{125, NOTE_F5, 125},
{125, NOTE_G5, 375},
{250, NOTE_F5, 250},
{125, NOTE_F5, 125},
{125, NOTE_F5, 250},
{250, NOTE_G5, 250},
{125, NOTE_GS5, 250},
{250, NOTE_A5, 250},
{250, NOTE_C6, 250},
{375, NOTE_A5, 375},
{250, NOTE_D6, 250},
{250, NOTE_D6, 250},
{125, NOTE_D6, 125},
{125, NOTE_A5, 125},
{125, NOTE_D6, 125},
{625, NOTE_C6, 625},
{500, NOTE_G6, 500},
{250, NOTE_A5, 250},
{125, NOTE_A5, 125},
{125, NOTE_A5, 250},
{250, NOTE_A5, 250},
{250, NOTE_A5, 250},
{250, NOTE_G5, 250},
{625, NOTE_G5, 625},
{250, NOTE_A5, 250},
{125, NOTE_A5, 125},
{125, NOTE_A5, 250},
{250, NOTE_A5, 250},
{125, NOTE_G5, 250},
{250, NOTE_A5, 250},
{125, NOTE_D6, 250},
{125, NOTE_A5, 125},
{250, NOTE_G5, 250},
{250, NOTE_D6, 250},
{250, NOTE_A5, 250},
{250, NOTE_G5, 250},
{250, NOTE_F5, 250},
{250, NOTE_C6, 250},
{250, NOTE_G5, 250},
{250, NOTE_F5, 250},
{250, NOTE_E5, 250},
{250, NOTE_AS4, 250},
{125, NOTE_C5, 125},
{125, NOTE_D5, 250},
{250, NOTE_F5, 250},
{1125, NOTE_C6, 2125},
{125, NOTE_F5, 125},
{125, NOTE_D5, 125},
{125, NOTE_F5, 125},
{125, NOTE_G5, 125},
{125, NOTE_GS5, 125},
{125, NOTE_G5, 125},
{125, NOTE_F5, 125},
{125, NOTE_D5, 125},
{63, NOTE_GS5, 63},
{63, NOTE_G5, 63},
{63, NOTE_F5, 63},
{63, NOTE_D5, 63},
{250, NOTE_F5, 250},
{1125, NOTE_G5, 1125},
{250, NOTE_GS5, 250},
{125, NOTE_A5, 125},
{250, NOTE_C6, 250},
{125, NOTE_A5, 125},
{125, NOTE_GS5, 125},
{125, NOTE_G5, 125},
{125, NOTE_F5, 125},
{125, NOTE_D5, 125},
{125, NOTE_E5, 125},
{250, NOTE_F5, 250},
{250, NOTE_G5, 250},
{250, NOTE_A5, 250},
{250, NOTE_C6, 250},
{250, NOTE_CS6, 250},
{250, NOTE_GS5, 250},
{125, NOTE_GS5, 125},
{125, NOTE_G5, 125},
{125, NOTE_F5, 125},
{1125, NOTE_G5, 1125},
{250, NOTE_F4, 250},
{250, NOTE_G4, 250},
{250, NOTE_A4, 250},
{250, NOTE_F5, 250},
{500, NOTE_E5, 500},
{500, NOTE_D5, 500},
{500, NOTE_E5, 500},
{500, NOTE_F5, 500},
{500, NOTE_G5, 500},
{500, NOTE_E5, 500},
{1000, NOTE_A5, 1000},
{125, NOTE_A5, 125},
{125, NOTE_GS5, 125},
{125, NOTE_G5, 125},
{125, NOTE_FS5, 125},
{125, NOTE_F5, 125},
{125, NOTE_E5, 125},
{125, NOTE_DS5, 125},
{125, NOTE_D5, 125},
{1000, NOTE_CS5, 1000},
{1000, NOTE_DS5, 2000},
{125, NOTE_F5, 125},
{125, NOTE_D5, 125},
{125, NOTE_F5, 125},
{125, NOTE_G5, 125},
{125, NOTE_GS5, 125},
{125, NOTE_G5, 125},
{125, NOTE_F5, 125},
{125, NOTE_D5, 125},
{63, NOTE_GS5, 63},
{63, NOTE_G5, 63},
{63, NOTE_F5, 63},
{63, NOTE_D5, 63},
{250, NOTE_F5, 250},
{1125, NOTE_G5, 1125},
{250, NOTE_GS5, 250},
{125, NOTE_A5, 125},
{250, NOTE_C6, 250},
{125, NOTE_A5, 125},
{125, NOTE_GS5, 125},
{125, NOTE_G5, 125},
{125, NOTE_F5, 125},
{125, NOTE_D5, 125},
{125, NOTE_E5, 125},
{250, NOTE_F5, 250},
{250, NOTE_G5, 250},
{250, NOTE_A5, 250},
{250, NOTE_C6, 250},
{250, NOTE_CS6, 250},
{250, NOTE_GS5, 250},
{125, NOTE_GS5, 125},
{125, NOTE_G5, 125},
{125, NOTE_F5, 125},
{1125, NOTE_G5, 1125},
{250, NOTE_F4, 250},
{250, NOTE_G4, 250},
{250, NOTE_A4, 250},
{250, NOTE_F5, 250},
{500, NOTE_E5, 500},
{500, NOTE_D5, 500},
{500, NOTE_E5, 500},
{500, NOTE_F5, 500},
{500, NOTE_G5, 500},
{500, NOTE_E5, 500},
{1000, NOTE_A5, 1000},
{125, NOTE_A5, 125},
{125, NOTE_GS5, 125},
{125, NOTE_G5, 125},
{125, NOTE_FS5, 125},
{125, NOTE_F5, 125},
{125, NOTE_E5, 125},
{125, NOTE_DS5, 125},
{125, NOTE_D5, 125},
{1000, NOTE_CS5, 1000},
{1000, NOTE_DS5, 1000},
{1500, NOTE_AS3, 1500},
{500, NOTE_F4, 500},
{1000, NOTE_E4, 1000},
{1000, NOTE_D4, 1000},
{4000, NOTE_F4, 4000},
{1500, NOTE_AS3, 1500},
{500, NOTE_F4, 500},
{1000, NOTE_E4, 1000},
{1000, NOTE_D4, 1000},
{1000, NOTE_D4, 1000},
{83, NOTE_D4, 83},
{83, NOTE_CS4, 83},
{83, NOTE_C4, 83},
{83, NOTE_B3, 83},
{83, NOTE_AS3, 83},
{83, NOTE_A3, 83},
{83, NOTE_GS3, 83},
{83, NOTE_G3, 83},
{83, NOTE_FS3, 83},
{83, NOTE_F3, 83},
{83, NOTE_E3, 83},
{83, NOTE_DS3, 83},
{2000, NOTE_D3, 2000},
{1500, NOTE_AS3, 1500},
{500, NOTE_F4, 500},
{1000, NOTE_E4, 1000},
{1000, NOTE_D4, 1000},
{2000, NOTE_F4, 2000},
{125, NOTE_B2, 125},
{125, NOTE_G3, 125},
{125, NOTE_F4, 125},
{125, NOTE_D4, 125},
{250, NOTE_G4, 250},
{125, NOTE_F4, 125},
{125, NOTE_C4, 125},
{125, NOTE_D4, 125},
{250, NOTE_C4, 250},
{250, NOTE_A3, 250},
{125, NOTE_G3, 125},
{125, NOTE_C4, 125},
{1500, NOTE_AS3, 1500},
{500, NOTE_F4, 500},
{1000, NOTE_E4, 1000},
{1000, NOTE_D4, 1000},
{125, NOTE_D3, 125},
{125, NOTE_D3, 125},
{250, NOTE_F4, 250},
{250, NOTE_E4, 250},
{125, NOTE_C4, 250},
{250, NOTE_E4, 250},
{250, NOTE_B3, 250},
{125, NOTE_G3, 125},
{125, NOTE_A3, 125},
{125, NOTE_C4, 125},
{125, NOTE_D3, 125},
{125, NOTE_D3, 125},
{250, NOTE_F4, 250},
{250, NOTE_E4, 250},
{125, NOTE_C4, 250},
{250, NOTE_E4, 250},
{250, NOTE_B3, 250},
{125, NOTE_G3, 125},
{125, NOTE_A3, 125},
{125, NOTE_C4, 125},
{250, NOTE_AS3, 250},
{250, NOTE_AS3, 250},
{125, NOTE_AS2, 125},
{250, NOTE_AS3, 250},
{250, NOTE_AS3, 250},
{250, NOTE_AS3, 250},
{125, NOTE_AS2, 125},
{125, NOTE_AS2, 125},
{125, NOTE_AS2, 125},
{250, NOTE_AS3, 250},
{250, NOTE_C4, 250},
{250, NOTE_C4, 250},
{125, NOTE_C3, 125},
{250, NOTE_C4, 250},
{250, NOTE_C4, 250},
{250, NOTE_C4, 250},
{125, NOTE_C3, 125},
{125, NOTE_C3, 125},
{125, NOTE_C3, 125},
{250, NOTE_C4, 250},
{250, NOTE_D4, 250},
{250, NOTE_D4, 250},
{125, NOTE_D3, 125},
{250, NOTE_D4, 250},
{250, NOTE_CS4, 250},
{250, NOTE_CS4, 250},
{125, NOTE_CS3, 125},
{125, NOTE_CS3, 125},
{125, NOTE_CS3, 125},
{250, NOTE_CS4, 250},
{250, NOTE_C4, 250},
{250, NOTE_C4, 250},
{125, NOTE_C3, 125},
{250, NOTE_C4, 250},
{250, NOTE_B3, 250},
{250, NOTE_B3, 250},
{125, NOTE_B2, 125},
{125, NOTE_B2, 125},
{125, NOTE_B2, 125},
{250, NOTE_B3, 250},
{250, NOTE_AS3, 250},
{250, NOTE_AS3, 250},
{125, NOTE_AS2, 125},
{250, NOTE_AS3, 250},
{250, NOTE_AS3, 250},
{250, NOTE_AS3, 250},
{125, NOTE_AS2, 125},
{125, NOTE_AS2, 125},
{125, NOTE_AS2, 125},
{250, NOTE_AS3, 250},
{250, NOTE_C4, 250},
{250, NOTE_C4, 250},
{125, NOTE_C3, 125},
{250, NOTE_C4, 250},
{250, NOTE_C4, 250},
{250, NOTE_C4, 250},
{125, NOTE_C3, 125},
{125, NOTE_C3, 125},
{125, NOTE_C3, 125},
{250, NOTE_C4, 250},
{250, NOTE_D4, 250},
{250, NOTE_D4, 250},
{125, NOTE_D3, 125},
{250, NOTE_D4, 250},
{250, NOTE_D4, 250},
{250, NOTE_D4, 250},
{125, NOTE_D3, 125},
{125, NOTE_D3, 125},
{125, NOTE_D3, 125},
{250, NOTE_D4, 250},
{250, NOTE_D4, 250},
{250, NOTE_D4, 250},
{125, NOTE_D3, 125},
{250, NOTE_D4, 250},
{250, NOTE_D4, 250},
{250, NOTE_D4, 250},
{125, NOTE_D3, 125},
{125, NOTE_D3, 125},
{125, NOTE_D3, 125},
{250, NOTE_D4, 250},
{250, NOTE_AS3, 250},
{250, NOTE_AS3, 250},
{125, NOTE_AS2, 125},
{250, NOTE_AS3, 250},
{250, NOTE_AS3, 250},
{250, NOTE_AS3, 250},
{125, NOTE_AS2, 125},
{125, NOTE_AS2, 125},
{125, NOTE_AS2, 125},
{250, NOTE_AS3, 250},
{250, NOTE_C4, 250},
{250, NOTE_C4, 250},
{125, NOTE_C3, 125},
{250, NOTE_C4, 250},
{250, NOTE_C4, 250},
{250, NOTE_C4, 250},
{125, NOTE_C3, 125},
{125, NOTE_C3, 125},
{125, NOTE_C3, 125},
{250, NOTE_C4, 250},
{250, NOTE_D4, 250},
{250, NOTE_D4, 250},
{125, NOTE_D3, 125},
{250, NOTE_D4, 250},
{250, NOTE_CS4, 250},
{250, NOTE_CS4, 250},
{125, NOTE_CS3, 125},
{125, NOTE_CS3, 125},
{125, NOTE_CS3, 125},
{250, NOTE_CS4, 250},
{250, NOTE_C4, 250},
{250, NOTE_C4, 250},
{125, NOTE_C3, 125},
{250, NOTE_C4, 250},
{250, NOTE_B3, 250},
{250, NOTE_B3, 250},
{125, NOTE_B2, 125},
{125, NOTE_B2, 125},
{125, NOTE_B2, 125},
{250, NOTE_B3, 250},
{250, NOTE_AS3, 250},
{250, NOTE_AS3, 250},
{125, NOTE_AS2, 125},
{250, NOTE_AS3, 250},
{250, NOTE_AS3, 250},
{250, NOTE_AS3, 250},
{125, NOTE_AS2, 125},
{125, NOTE_AS2, 125},
{125, NOTE_AS2, 125},
{250, NOTE_AS3, 250},
{250, NOTE_C4, 250},
{250, NOTE_C4, 250},
{125, NOTE_C3, 125},
{250, NOTE_C4, 250},
{250, NOTE_C4, 250},
{250, NOTE_C4, 250},
{125, NOTE_C3, 125},
{125, NOTE_C3, 125},
{125, NOTE_C3, 125},
{250, NOTE_C4, 250},
{125, NOTE_D4, 125},
{125, NOTE_D3, 125},
{250, NOTE_D4, 250},
{125, NOTE_A3, 125},
{250, NOTE_D4, 250},
{250, NOTE_D4, 250},
{250, NOTE_D4, 250},
{250, NOTE_F3, 250},
{125, NOTE_D3, 125},
{125, NOTE_D4, 125},
{125, NOTE_G3, 125},
{125, NOTE_D4, 125},
{125, NOTE_D3, 125},
{250, NOTE_D4, 250},
{125, NOTE_A3, 125},
{250, NOTE_D4, 250},
{250, NOTE_D4, 250},
{250, NOTE_D4, 250},
{250, NOTE_F3, 250},
{125, NOTE_D3, 125},
{125, NOTE_D4, 125},
{125, NOTE_G3, 125},
{125, NOTE_D4, 125},
{125, NOTE_D4, 125},
{250, NOTE_D5, 250},
{250, NOTE_A4, 375},
{125, NOTE_GS4, 250},
{250, NOTE_G4, 250},
{250, NOTE_F4, 250},
{125, NOTE_D4, 125},
{125, NOTE_F4, 125},
{125, NOTE_G4, 125},
{125, NOTE_C4, 62},
{125, NOTE_C4, 62},
{125, NOTE_C4, 62},
{125, NOTE_C4, 62},
{250, NOTE_D5, 250},
{375, NOTE_A4, 375},
{125, NOTE_GS4, 250},
{250, NOTE_G4, 250},
{250, NOTE_F4, 250},
{125, NOTE_D4, 125},
{125, NOTE_F4, 125},
{125, NOTE_G4, 125},
{125, NOTE_B3, 125},
{125, NOTE_B3, 125},
{250, NOTE_D5, 250},
{375, NOTE_A4, 375},
{125, NOTE_GS4, 250},
{250, NOTE_G4, 250},
{250, NOTE_F4, 250},
{125, NOTE_D4, 125},
{125, NOTE_F4, 125},
{125, NOTE_G4, 125},
{62, NOTE_AS3, 62},
{62, NOTE_AS3, 62},
{62, NOTE_AS3, 62},
{62, NOTE_AS3, 62},
{250, NOTE_D5, 250},
{375, NOTE_A4, 375},
{125, NOTE_GS4, 250},
{250, NOTE_G4, 250},
{250, NOTE_F4, 250},
{125, NOTE_D4, 125},
{125, NOTE_F4, 125},
{125, NOTE_G4, 125},
{125, NOTE_D4, 125},
{125, NOTE_D4, 125},
{250, NOTE_D5, 250},
{375, NOTE_A4, 375},
{125, NOTE_GS4, 250},
{250, NOTE_G4, 250},
{250, NOTE_F4, 250},
{125, NOTE_D4, 125},
{125, NOTE_F4, 125},
{125, NOTE_G4, 125},
{125, NOTE_C4, 62},
{125, NOTE_C4, 62},
{125, NOTE_C4, 62},
{125, NOTE_C4, 62},
{250, NOTE_D5, 250},
{375, NOTE_A4, 375},
{125, NOTE_GS4, 250},
{250, NOTE_G4, 250},
{250, NOTE_F4, 250},
{125, NOTE_D4, 125},
{125, NOTE_F4, 125},
{125, NOTE_G4, 4125},
};

int indice = -1;
long t_buz = 0;
bool play = true;

void handleBuzzer();
void setPlay(bool value);

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
  pinMode(P_BUZ, OUTPUT);

  
  lcd.init();
  lcd.backlight();
  
  for(int r = 0; r < ROWS; ++r){
    for(int c = 0; c < COLS; ++c){
    	_map[r][c] = '\0';
    }
  }
  
  randomSeed(analogRead(A0));
  // Serial.begin(9600);
}

void loop()
{
  getInputs();

  if(!start && stato_inputs & 0b00000100){
    start = true;
    setPlay(true);
  }

  handleBuzzer();

  if(start){

    handleBuzzer();

    for(int r = 0; r < ROWS; ++r){
      for(int c = 0; c < COLS; ++c){
        _map[r][c] = _map[r][c != COLS - 1 ? c + 1 : c];
      }
    }

    handleBuzzer();
    
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
    
    handleBuzzer();
    
    lcd.clear();
    if(!game_over){
      crea_ostacolo = true;
      for(int r = 0; r < ROWS; ++r){
        if(_map[r][COLS - 2] == '\1'){
            crea_ostacolo = false;
            break;
        }
      }

      handleBuzzer();
    
      for(int r = 0; r < ROWS; ++r){
        _map[r][COLS - 1] = '\0';
      }

      handleBuzzer();
    
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

      handleBuzzer();
      
      lcd.print(string_lcd.substring(0, COLS));
      lcd.setCursor(0, 1);
      lcd.print(string_lcd.substring(COLS));

      handleBuzzer();
    }else{
      setPlay(false);
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
      setPlay(true);
    }
  }else if(!msg_benvenuto){
    setPlay(false);
    lcd.print("   FLAPPY LCD   ");
    lcd.setCursor(0, 1);
    lcd.print("Premere START");
    msg_benvenuto = true;
  }


  if((stato_inputs & 0b00000111) == 0b00000111){
    setPlay(false);
    resetGame();
    game_over = false;
    start = false;
    msg_benvenuto = false;
  }
    
}





// [Simone] Volevo provare a aggiornare tutte le variabili senza allocarne altre, è un casino ma era una sfida personale :)
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

void handleBuzzer(){
  if(play && (indice < 0 || (millis() - t_buz) > spartito[indice][2])){
    indice++;

    if(indice >= D_SPARTITO){
      indice = -1;
      noTone(P_BUZ);
      return;
    }

    tone(P_BUZ, spartito[indice][1], spartito[indice][0]);
    t_buz = millis();
  }
}

void setPlay(bool value){
  play = value;
  if(play == false){
    indice = -1;
    noTone(P_BUZ);
  }
}

