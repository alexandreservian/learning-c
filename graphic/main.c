#include <gb/gb.h>

// 2 tiles (cada um 16 bytes).
// Tile 0: vazio (tudo 0)
// Tile 1: “cheio” (um padrão simples usando 2bpp; aqui é só exemplo)
const unsigned char tiles[] = {
  // tile 0 (16 bytes)
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

  // tile 1 (16 bytes) - padrão
  0xFF,0xFF, 0xFF,0xFF, 0xFF,0xFF, 0xFF,0xFF,
  0xFF,0xFF, 0xFF,0xFF, 0xFF,0xFF, 0xFF,0xFF
};

unsigned char map[20 * 18];

void main(void) {
  // monta um tabuleiro alternando 0 e 1
  for (unsigned char y = 0; y < 18; y++) {
    for (unsigned char x = 0; x < 20; x++) {
      map[y * 20 + x] = (x + y) & 1; // 0 ou 1
    }
  }

  set_bkg_data(0, 2, tiles);              // carrega 2 tiles
  set_bkg_tiles(0, 0, 20, 18, map);       // escreve o mapa visível
  SHOW_BKG;

  while(1) {
    wait_vbl_done(); // mantém estável (e você pode animar depois)
  }
}
