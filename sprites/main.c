#include <gb/gb.h>
#include <stdio.h>

#define MIN_X 8
#define MAX_X 160
#define MIN_Y 16
#define MAX_Y 152
// Um tile 8x8, 2bpp (16 bytes).
// Aqui é só um exemplo simples (um “bloco”).
const unsigned char sprite_tiles[] = {
  0xFF,0x00, 0xFF,0x00, 0xFF,0x00, 0xFF,0x00,
  0xFF,0x00, 0xFF,0x00, 0xFF,0x00, 0xFF,0x00
};


void main(void) {
    
  UINT8 x = 80;
  UINT8 y = 88;

  // Carrega 1 tile de sprite no índice 0
  set_sprite_data(0, 1, sprite_tiles);

  // Sprite 0 usa o tile 0
  set_sprite_tile(0, 0);

  // Move para posição inicial
  move_sprite(0, x, y);

  SHOW_SPRITES;
  DISPLAY_ON;

  while(1) {
    UINT8 keys = joypad();

    if((x > MIN_X) && (keys & J_LEFT))  x--;
    if((x < MAX_X) && (keys & J_RIGHT)) x++;
    if((y > MIN_Y) && (keys & J_UP))    y--;
    if((y < MAX_Y) && (keys & J_DOWN))  y++;

    
    
    
    // Sincroniza com o frame (evita rodar solto)
    wait_vbl_done();
    move_sprite(0, x, y);
  }
}
