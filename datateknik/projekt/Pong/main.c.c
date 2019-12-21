
/****************************************************************************
PONG by Rasmus and Erik
*****************************************************************************/


#include <pic32mx.h>
#include <stdint.h>

//Buttons
int button;
int button1;

//Scores
int P1Score = 0;
int P2Score = 0;

//Configure player 1
int p1x = 0;
int p1y = 12;
int p1w = 3;
int p1h = 8;

//Configure player 2
int p2x = 125;
int p2y = 12;
int p2w = 3;
int p2h = 8;

//Configure ball
int ball_x = 64;
int ball_y = 16;

int end_1 = 0;
int game_mode = 0;
int collision = 1;

char textbuffer[4][16];

const uint8_t screen[128][4];
uint8_t bufferstate[512];
//const uint8_t slut[5];


#define DISPLAY_CHANGE_TO_COMMAND_MODE (PORTFCLR = 0x10)
#define DISPLAY_CHANGE_TO_DATA_MODE (PORTFSET = 0x10)

#define DISPLAY_ACTIVATE_RESET (PORTGCLR = 0x200)
#define DISPLAY_DO_NOT_RESET (PORTGSET = 0x200)

#define DISPLAY_ACTIVATE_VDD (PORTFCLR = 0x40)
#define DISPLAY_ACTIVATE_VBAT (PORTFCLR = 0x20)

#define DISPLAY_TURN_OFF_VDD (PORTFSET = 0x40)
#define DISPLAY_TURN_OFF_VBAT (PORTFSET = 0x20)


const uint8_t const font[] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 94, 0, 0, 0, 0,
    0, 0, 4, 3, 4, 3, 0, 0,
    0, 36, 126, 36, 36, 126, 36, 0,
    0, 36, 74, 255, 82, 36, 0, 0,
    0, 70, 38, 16, 8, 100, 98, 0,
    0, 52, 74, 74, 52, 32, 80, 0,
    0, 0, 0, 4, 3, 0, 0, 0,
    0, 0, 0, 126, 129, 0, 0, 0,
    0, 0, 0, 129, 126, 0, 0, 0,
    0, 42, 28, 62, 28, 42, 0, 0,
    0, 8, 8, 62, 8, 8, 0, 0,
    0, 0, 0, 128, 96, 0, 0, 0,
    0, 8, 8, 8, 8, 8, 0, 0,
    0, 0, 0, 0, 96, 0, 0, 0,
    0, 64, 32, 16, 8, 4, 2, 0,
    0, 62, 65, 73, 65, 62, 0, 0,
    0, 0, 66, 127, 64, 0, 0, 0,
    0, 0, 98, 81, 73, 70, 0, 0,
    0, 0, 34, 73, 73, 54, 0, 0,
    0, 0, 14, 8, 127, 8, 0, 0,
    0, 0, 35, 69, 69, 57, 0, 0,
    0, 0, 62, 73, 73, 50, 0, 0,
    0, 0, 1, 97, 25, 7, 0, 0,
    0, 0, 54, 73, 73, 54, 0, 0,
    0, 0, 6, 9, 9, 126, 0, 0,
    0, 0, 0, 102, 0, 0, 0, 0,
    0, 0, 128, 102, 0, 0, 0, 0,
    0, 0, 8, 20, 34, 65, 0, 0,
    0, 0, 20, 20, 20, 20, 0, 0,
    0, 0, 65, 34, 20, 8, 0, 0,
    0, 2, 1, 81, 9, 6, 0, 0,
    0, 28, 34, 89, 89, 82, 12, 0,
    0, 0, 126, 9, 9, 126, 0, 0,
    0, 0, 127, 73, 73, 54, 0, 0,
    0, 0, 62, 65, 65, 34, 0, 0,
    0, 0, 127, 65, 65, 62, 0, 0,
    0, 0, 127, 73, 73, 65, 0, 0,
    0, 0, 127, 9, 9, 1, 0, 0,
    0, 0, 62, 65, 81, 50, 0, 0,
    0, 0, 127, 8, 8, 127, 0, 0,
    0, 0, 65, 127, 65, 0, 0, 0,
    0, 0, 32, 64, 64, 63, 0, 0,
    0, 0, 127, 8, 20, 99, 0, 0,
    0, 0, 127, 64, 64, 64, 0, 0,
    0, 127, 2, 4, 2, 127, 0, 0,
    0, 127, 6, 8, 48, 127, 0, 0,
    0, 0, 62, 65, 65, 62, 0, 0,
    0, 0, 127, 9, 9, 6, 0, 0,
    0, 0, 62, 65, 97, 126, 64, 0,
    0, 0, 127, 9, 9, 118, 0, 0,
    0, 0, 38, 73, 73, 50, 0, 0,
    0, 1, 1, 127, 1, 1, 0, 0,
    0, 0, 63, 64, 64, 63, 0, 0,
    0, 31, 32, 64, 32, 31, 0, 0,
    0, 63, 64, 48, 64, 63, 0, 0,
    0, 0, 119, 8, 8, 119, 0, 0,
    0, 3, 4, 120, 4, 3, 0, 0,
    0, 0, 113, 73, 73, 71, 0, 0,
    0, 0, 127, 65, 65, 0, 0, 0,
    0, 2, 4, 8, 16, 32, 64, 0,
    0, 0, 0, 65, 65, 127, 0, 0,
    0, 4, 2, 1, 2, 4, 0, 0,
    0, 64, 64, 64, 64, 64, 64, 0,
    0, 0, 1, 2, 4, 0, 0, 0,
    0, 0, 48, 72, 40, 120, 0, 0,
    0, 0, 127, 72, 72, 48, 0, 0,
    0, 0, 48, 72, 72, 0, 0, 0,
    0, 0, 48, 72, 72, 127, 0, 0,
    0, 0, 48, 88, 88, 16, 0, 0,
    0, 0, 126, 9, 1, 2, 0, 0,
    0, 0, 80, 152, 152, 112, 0, 0,
    0, 0, 127, 8, 8, 112, 0, 0,
    0, 0, 0, 122, 0, 0, 0, 0,
    0, 0, 64, 128, 128, 122, 0, 0,
    0, 0, 127, 16, 40, 72, 0, 0,
    0, 0, 0, 127, 0, 0, 0, 0,
    0, 120, 8, 16, 8, 112, 0, 0,
    0, 0, 120, 8, 8, 112, 0, 0,
    0, 0, 48, 72, 72, 48, 0, 0,
    0, 0, 248, 40, 40, 16, 0, 0,
    0, 0, 16, 40, 40, 248, 0, 0,
    0, 0, 112, 8, 8, 16, 0, 0,
    0, 0, 72, 84, 84, 36, 0, 0,
    0, 0, 8, 60, 72, 32, 0, 0,
    0, 0, 56, 64, 32, 120, 0, 0,
    0, 0, 56, 64, 56, 0, 0, 0,
    0, 56, 64, 32, 64, 56, 0, 0,
    0, 0, 72, 48, 48, 72, 0, 0,
    0, 0, 24, 160, 160, 120, 0, 0,
    0, 0, 100, 84, 84, 76, 0, 0,
    0, 0, 8, 28, 34, 65, 0, 0,
    0, 0, 0, 126, 0, 0, 0, 0,
    0, 0, 65, 34, 28, 8, 0, 0,
    0, 0, 4, 2, 4, 2, 0, 0,
    0, 120, 68, 66, 68, 120, 0, 0,
};
void display_string(int line, char *s) {
    int i;
    if(line < 0 || line >= 4)
        return;
    if(!s)
        return;

    for(i = 0; i < 16; i++)
        if(*s) {
            textbuffer[line][i] = *s;
            s++;
        } else
            textbuffer[line][i] = ' ';
}

void quicksleep(int cyc) {
	int i;
	for(i = cyc; i > 0; i--);
}

//Sets and updates the pixels on the screen
void set_pixel(const short x, const short y, const uint8_t state) {

	if ( x < 128 && x >= 0) {
		if (y < 32 && y >= 0) {
  uint8_t bit = 0x1 << (y - (y/8 * 8));
  if(state == 0) {
    bufferstate[x + (y/8) * 128] &= ~bit;
  }
  else {
    bufferstate[x + (y/8) * 128] |= bit;
  }
		}
	}
}

void init_mcu(void)
{
	// Configure Buttonpins as inputs
	TRISFSET = 0x0001; // Button 1

	// Output pins for display signals
	PORTF = 0xFFFF;
	PORTG = (1 << 9);
	ODCF = 0x0;
	ODCG = 0x0;
	TRISFCLR = 0x70;
	TRISGCLR = 0x200;

	// Set up SPI as master
	SPI2CON = 0;
	SPI2BRG = 4;
	SPI2STATCLR = 0x40; 	/* SPI2STAT bit SPIROV = 0; */
 	SPI2CONSET = 0x40; 		/* SPI2CON bit CKP = 1; */
	SPI2CONSET = 0x20; 		/* SPI2CON bit MSTEN = 1; */
	SPI2CONSET = 0x8000;	/* SPI2CON bit ON = 1; */
}

// Initilize timer 2 with timeout interrupts
void init_timer(void)
{
	// Configure Timer 2
	T2CON     = 0x0;        	// reset control register
	T2CONSET  = (0x4 << 4);     // set prescaler to 1:16
	TMR2      = 0;          	// reset timer value
	T2CONSET  = (0x1 << 15);    // start the timer

	// Enable Timer 2 interrupts
	IPC(2)    = 0x4;        	// set interrupt priority to 4
	IECSET(0) = 0x1<<8;      	// timer 2 interrupt enable
	IFSCLR(0) = 0x1<<8;      	// clear timer 2 interrupt flag
}
//this function tweaks the screen
uint8_t spi_send_recv(uint8_t data) {
	while(!(SPI2STAT & 0x08));
	SPI2BUF = data;
	while(!(SPI2STAT & 1));
	return SPI2BUF;
}

void display_init(void) {
    DISPLAY_CHANGE_TO_COMMAND_MODE;
	quicksleep(10);
	DISPLAY_ACTIVATE_VDD;
	quicksleep(1000000);

	spi_send_recv(0xAE);
	DISPLAY_ACTIVATE_RESET;
	quicksleep(10);
	DISPLAY_DO_NOT_RESET;
	quicksleep(10);

	spi_send_recv(0x8D);
	spi_send_recv(0x14);

	spi_send_recv(0xD9);
	spi_send_recv(0xF1);

	DISPLAY_ACTIVATE_VBAT;
	quicksleep(10000000);

	spi_send_recv(0xA1);
	spi_send_recv(0xC8);

	spi_send_recv(0xDA);
	spi_send_recv(0x20);

	spi_send_recv(0xAF);
}

void display_update(void) {
	int i, j, k;
	int c;
	for(i = 0; i < 4; i++) {
		DISPLAY_CHANGE_TO_COMMAND_MODE;
		spi_send_recv(0x22);
		spi_send_recv(i);

		spi_send_recv(0x0);
		spi_send_recv(0x10);

		DISPLAY_CHANGE_TO_DATA_MODE;

		for(j = 0; j < 16; j++) {
			c = textbuffer[i][j];
			if(c & 0x80)
				continue;

			for(k = 0; k < 8; k++)
				spi_send_recv(font[c*8 + k]);
		}
	}
}

//Changed the last for loop so it takes 128 instead of 32, for entire screen
void display_image(int x, const uint8_t *data) {
	int i, j;

	for(i = 0; i < 4; i++) {
		DISPLAY_CHANGE_TO_COMMAND_MODE;

		spi_send_recv(0x22);
		spi_send_recv(i);

		spi_send_recv(x & 0xF);
		spi_send_recv(0x10 | ((x >> 4) & 0xF));

		DISPLAY_CHANGE_TO_DATA_MODE;

		for(j = 0; j < 128; j++)
			spi_send_recv(data[i*128 + j]);
	}
}
//Creating the players, and their position
void get_rect(int x, int y, int w, int h, const uint8_t state) {

	int i,j;

	int yj = y;
	int xj = x;

	for (i = 0; i < w; i++){
		for (j = 0; j < h; j++){
			set_pixel(x, y, state);
			y++;
		}
		y = yj;
		x++;
	}
}


void move_ball_p2() { //Ball moves against player 2

		quicksleep(100000);
		ball_x += 1;
		set_pixel(ball_x, ball_y, 1);


}

void move_ball_p1() { //Ball moves against player 1

		quicksleep(100000);
		ball_x -= 1;
		set_pixel(ball_x, ball_y, 1);

}

void move_ball_down() {

		quicksleep(100000);
		ball_y += 1;
		set_pixel(ball_x, ball_y, 1);

}

void move_ball_up() {

		quicksleep(100000);
		ball_y -= 1;
		set_pixel(ball_x, ball_y, 1);

}

void ball_collision_p1() { //Ball colision for player 1

	if (ball_x == 3) { //The x-position for player 1

	if (p1y < 16) {
		int p1 = 0;
		int yvalue = p1y;
		int yvalueball = ball_y;

		for (p1 = 0; p1 < 8; p1++){
		if ( yvalueball == (yvalue + p1)) {
			move_ball_p2();
			end_1 = 1;
			break;
		}
		}
	}

	}
}

void ball_collision_p2() { //Ball colision for player 2

	if (ball_x == 125) { //The x-position for player 2

	if (p2y < 16) {
		int p2 = 0;
		int yvalue2 = p2y;
		int yvalueball2 = ball_y;

		for (p2 = 0; p2 < 8; p2++) {
		if ( yvalueball2 == (yvalue2 + p2)) {

			move_ball_p1();
			end_1 = 0;
			break;
		}
		}
	}
}
}

void move_p1_up(){
	if ( p1y >= 0 ){

	quicksleep(100000);
	p1y = p1y - 1;

	}
}

void move_p1_down(){

	if ( p1y < 26 ){

	quicksleep(100000);
	p1y = p1y + 1;

	}
}

void move_p2_up(){
	if ( p2y >= 0 ){

	quicksleep(100000);
	p2y = p2y - 1;

	}
}
void move_p2_down(){
	if ( p2y < 26 ){

	quicksleep(100000);
	p2y = p2y + 1;

	}

}

void move_AI(){

		if (ball_y > p2y){
			p2y = p2y + 1;
		}
		else{
			p2y = p2y - 1;
		}

}

void upside_collision_p1() { //Collision with wall, upper side, toward player 1

		if (ball_y == 0){
		move_ball_p1();
		move_ball_down();
		collision = 1;
		}

}

void downside_collision_p1() { //Collision with wall, lower side, toward player 1

		if (ball_y == 32){
		move_ball_p1();
		move_ball_up();
		collision = 2;
		}
}

void upside_collision_p2() { //Collision with wall upper side, towards player 2
	if (ball_y == 0){
		move_ball_p2();
		move_ball_down();
		collision = 1;

	}

}
void downside_collision_p2() { //Collision with wall, lower side, toward player 2
	if (ball_y == 32){
		move_ball_p2();
		move_ball_up();
		collision = 2;
	}
}

int get_btns(void) {	//Input buttons 4-2

	int buttons = (PORTD >> 5) & 0x0007;
	return buttons;
}

int get_btn1(void) { //Input button 1
	int button_one = (PORTF >> 1) & 0x0001;
	return button_one;
}

void clear() { //Clear screen

	int i;

	for (i = 0; i < 512; i++) {
		bufferstate[i] = 0;
	}

}

int main(void){

init_mcu(); //Initilize buttons etc
display_init(); //Initilize display
TRISD = 0x0fe0;

int GAME = 0;
int delay = 1000;
int start = 0;

while (start == 0) {

  int button1;
	button1 = get_btn1();

  display_string(0,"     WELCOME");
  display_string(1,"        TO");
  display_string(2,"       PONG");
  display_string(3,"Press 4 to begin");
  display_update();

  if (button1 == 1) {
      start = 1;
  }
}

while (start == 1) {

 int wins_p1 = 0;
 int wins_p2 = 0;

while (GAME == 0) {
	int button;
	button = get_btns();

	display_string(0,"PONG");
	display_string(1,"1 p, press 1");
	display_string(2,"2 p, press 2");
	display_string(3,"Board, press 3");
	display_update();

  if (button == 1) {
      GAME = 4;
  }

  while (GAME == 4)  {

    int button1;
  	button1 = get_btn1();

    display_string(0,"Score:");
  	display_string(1,"P1 always");
  	display_string(2,"wins :)");
  	display_string(3,"What is life?");
  	display_update();

    if (button1 == 1) {
        GAME = 0;

  }
}

	if ( button == 2 ) { //Go to game (2 players)

    while (delay > 0) {
      display_string(0,"");
      display_string(1,"Get ready");
      display_string(2,"Playing to 5");
      display_string(3,"");
      display_update();
      delay--;
    }

		GAME = 1;
	}
	if ( button == 4) { //Go to game (1 player)

        while (delay > 0) {
          display_string(0,"");
          display_string(1,"Get ready");
          display_string(2,"Playing to 5");
          display_string(3,"");
          display_update();
          delay--;
        }

		GAME = 1;
		game_mode = 1;
	}
}


while (GAME == 1) { //Game running

	if (P1Score == 5) { //Go to player 1 victory screen
    wins_p1++;
		GAME = 2;
}

	if (P2Score == 5) { //Go to player 2 victory screen
    wins_p2++;
		GAME = 3;
	}

	else { //Continue playing

	clear();
	button = get_btns();
	button1 = get_btn1();

	if (ball_x == 0) { //Check score for player 2
	  P2Score = P2Score + 1;
		ball_x = 64;
		ball_y = 16;
	}

	if (ball_x == 128) { //Check score for player 1
		P1Score = P1Score + 1;
	  ball_x = 64;
		ball_y = 16;
	}


	get_rect(p1x,p1y,p1w,p1h,1); //Create player 1

	get_rect(p2x,p2y,p2w,p2h,1); //Create player 2

	set_pixel(ball_x, ball_y, 1); //Put ball in the middle

  //Check collision
	ball_collision_p1();
	ball_collision_p2();


	if (button == 4){
		move_p1_up();
	}
	if (button == 2) {
		move_p1_down();
	}


	if (game_mode == 0) { //2 players
	if (button1 == 1) {
	move_p2_down();
	}
	if (button == 1) {
	move_p2_up();
	}
	}
	if (game_mode == 1) { //1 player
		move_AI(); //Moves AI
	}

	if (end_1 == 1) { //Collision with player 1

		upside_collision_p2(); //Check collision
		downside_collision_p2();

		if (collision == 1) { //Checking if the ball is on the upper side
			move_ball_p2();
			move_ball_down();
		}

		if (collision == 2) { //Checking if the ball is on the lower side
			move_ball_p2();
			move_ball_up();
		}

	}

	if (end_1 == 0) { //Collision with player 2

		upside_collision_p1(); //Check collision
		downside_collision_p1();

			if (collision == 1) { //Checking if the ball is on the upper side
			move_ball_p1();
			move_ball_down();
		}

		if (collision == 2) { //Checking if the ball is on the lower side
			move_ball_p1();
			move_ball_up();
		}
	}

	display_image(0, bufferstate);
	}

}

while (GAME == 2 & game_mode == 0) { //Player 1 victory screen

  int button1;
	button1 = get_btn1();

	display_string(0,"");
	display_string(1,"");
	display_string(2,"Player 1 won :)");
	display_string(3,"");
	display_update();

  if (button1 == 1) {
    P1Score = 0;
    P2Score = 0;

    p1x = 0;
    p1y = 12;
    p1w = 3;
    p1h = 8;

    p2x = 125;
    p2y = 12;
    p2w = 3;
    p2h = 8;

    ball_x = 64;
    ball_y = 16;

    end_1 = 0;
    game_mode = 0;
    collision = 1;

    GAME = 0;
  }

}

while (GAME == 3 & game_mode == 0) { //Player 2 victory screen

  int button1;
  button1 = get_btn1();

	display_string(0,"");
	display_string(1,"");
	display_string(2,"Player 2 won :)");
	display_string(3,"");
	display_update();

  if (button1 == 1) {
    P1Score = 0;
    P2Score = 0;

    p1x = 0;
    p1y = 12;
    p1w = 3;
    p1h = 8;

    p2x = 125;
    p2y = 12;
    p2w = 3;
    p2h = 8;

    ball_x = 64;
    ball_y = 16;

    end_1 = 0;
    game_mode = 0;
    collision = 1;

    GAME = 0;
  }

}

  while (GAME == 2 & game_mode == 1) {

    int button1;
    button1 = get_btn1();

  	display_string(0,"");
  	display_string(1,"");
  	display_string(2,"You win! :)");
  	display_string(3,"");
  	display_update();

    if (button1 == 1) {
      P1Score = 0;
      P2Score = 0;

      p1x = 0;
      p1y = 12;
      p1w = 3;
      p1h = 8;

      p2x = 125;
      p2y = 12;
      p2w = 3;
      p2h = 8;

      ball_x = 64;
      ball_y = 16;

      end_1 = 0;
      game_mode = 0;
      collision = 1;

      GAME = 0;

  }
}
  while (GAME == 3 & game_mode == 1) {

    int button1;
    button1 = get_btn1();

  	display_string(0,"");
  	display_string(1,"");
  	display_string(2,"You lost.. :(");
  	display_string(3,"");
  	display_update();

    if (button1 == 1) {
      P1Score = 0;
      P2Score = 0;

      p1x = 0;
      p1y = 12;
      p1w = 3;
      p1h = 8;

      p2x = 125;
      p2y = 12;
      p2w = 3;
      p2h = 8;

      ball_x = 64;
      ball_y = 16;

      end_1 = 0;
      game_mode = 0;
      collision = 1;

      GAME = 0;

    }
  }
}

return 0;
}
