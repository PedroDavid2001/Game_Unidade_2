/**********************************************************************************
// Home (Arquivo de Cabe�alho)
// 
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Tela de abertura do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_HOME_H_
#define _GRAVITYGUY_HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
    Sprite * backg = nullptr;       // pano de fundo
    Sprite*  title = nullptr;

    float posB11, posB12;							//posi��o horizontal dos primeiros predios
    float posB21, posB22;							//posi��o horizontal dos predios do meio
    float posB31, posB32;							//posi��o horizontal dos predios de tras

    Sprite* build_11; //predios mais proximos
    Sprite* build_12;

    Sprite* build_21; //predios do meio
    Sprite* build_22;

    Sprite* build_31; //predios mais distantes
    Sprite* build_32;

    TileSet * tileset = nullptr;    // tileset da anima��o
    Animation * anim = nullptr;     // anima��o do menu

public:
    void Init();                    // inicia n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza n�vel
};

// -----------------------------------------------------------------------------

#endif