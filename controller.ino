//SNES controller for ATMega32u4
//Joel Maus
#include <Keyboard.h>

boolean bpressed=false;
boolean ypressed=false;
boolean startpressed=false;
boolean apressed=false;
boolean xpressed=false;
boolean right1pressed=false;
boolean left1pressed=false;
boolean selectpressed=false;
const int x = 0;
const int right1 = 1;
const int left1 = 2;
const int select = 3;
const int y = 4;
const int start = 5;
const int a = 6;
const int down = 7;
const int b = 8;
const int left = 9;
const int right = 10;
const int up = 11;


//Variables for the states of the SNES buttonszzz
boolean boolx;
boolean boolright1;
boolean boolleft1;
boolean boolselect;
boolean booly;
boolean boolstart;
boolean boola;
boolean booldown;
boolean boolb;
boolean boolleft;
boolean boolright;
boolean boolup;


void setup()
{
  //Setup the pin modes.
 
  pinMode( x, INPUT_PULLUP );
  pinMode( right1, INPUT_PULLUP );
  pinMode( left1, INPUT_PULLUP );
  pinMode( select, INPUT_PULLUP );
  pinMode( y, INPUT_PULLUP );
  pinMode( start, INPUT_PULLUP );
  pinMode( a, INPUT_PULLUP );
  pinMode( down, INPUT_PULLUP );
  pinMode( b, INPUT_PULLUP );
  pinMode( left, INPUT_PULLUP );
  pinMode( right, INPUT_PULLUP );
  pinMode( up, INPUT_PULLUP );
 
  //Zero the SNES controller button keys:
  boolx = false;
  boolright1 = false;
  boolleft1 = false;
  boolselect = false;
  booly = false;
  boolstart = false;
  boola = false;
  booldown = false;
  boolb = false;
  boolleft = false;
  boolright = false;
  boolup = false;
 
}


void loop()
{

  //Progess the SNES controller buttons to send keystrokes.
  fcnProcessButtons();
  
}

//Function to process the buttons from the SNES controller
void fcnProcessButtons()
{
 
  boolean boolx= !digitalRead(x);
  boolean boolright1= !digitalRead(right1);
  boolean boolleft1= !digitalRead(left1);
  boolean boolselect= !digitalRead(select);
  boolean booly= !digitalRead(y);
  boolean boolstart= !digitalRead(start);
  boolean boola= !digitalRead(a);
  boolean booldown= !digitalRead(down);
  boolean boolb= !digitalRead(b);
  boolean boolleft= !digitalRead(left);
  boolean boolright= !digitalRead(right);
  boolean boolup= !digitalRead(up);
 // record with x button
  if ( boolx ) 
 {       
    if (!(xpressed==true)){
      Keyboard.press(114);
      xpressed = true;
    }       
  } else {
    xpressed = false;
    Keyboard.release(114);
  }

   if ( boolright1 )
  {   
    if (!(right1pressed==true)){
          Keyboard.press(115);
           right1pressed = true;
   }
  } else {
    right1pressed = false;
    Keyboard.release(115);
  }
//left1 = w
   if ( boolleft1 )
  {   
    if (!(left1pressed==true)){
          Keyboard.press(119);
           left1pressed = true;
   }
  } else {
    left1pressed = false;
    Keyboard.release(119);
  }
// select = v
   if ( boolselect )
  {   
   if (!(selectpressed==true)){
          Keyboard.press(118);
           selectpressed = true;
    }       
  } else {
    selectpressed = false;
    Keyboard.release(118);
  }

   if ( booly )
  {   
   if (!(ypressed==true)){
           Keyboard.press(97);
           ypressed = true;
   }
  } else {
    ypressed = false;
    Keyboard.release(97);
  }
    
   if ( boolstart )
  {   
    if (!(startpressed==true)){
          Keyboard.press(112);
           startpressed = true;
    }       
  } else {
    startpressed = false;
    Keyboard.release(112);
  }

   if ( boola )
  {       
    if (!(apressed==true)){
      Keyboard.press(120);
      apressed = true;
    }       
  } else {
    apressed = false;
    Keyboard.release(120);
  }
  
   if ( booldown )
  {   
    Keyboard.press(KEY_DOWN_ARROW);
  } else {
     Keyboard.release(KEY_DOWN_ARROW);
  }

   if ( boolb )
  {   
    if (!(bpressed==true)){
          Keyboard.press(122);
           bpressed = true;
    }       
  } else {
        bpressed=false;
        Keyboard.release(122);
  }

   if ( boolleft )
  {   
    Keyboard.press(KEY_LEFT_ARROW);
  } else {
    Keyboard.release(KEY_LEFT_ARROW);
  }

   if ( boolright )
  {   
    Keyboard.press(KEY_RIGHT_ARROW);
  } else {
    Keyboard.release(KEY_RIGHT_ARROW);
  }

   if ( boolup )
  {   
    Keyboard.press(KEY_UP_ARROW);
  } 
  else {
    Keyboard.release(KEY_UP_ARROW);
  }



}
