/**********************************************************************************
// Level1 (Arquivo de Cabe�alho)
//
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   N�vel 1 do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_LEVEL4_H_
#define _GRAVITYGUY_LEVEL4_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Font.h"
#include "Timer.h"
#include "Snow.h"
#include "Background.h"
#include "EndLevel.h"
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

class Level4 : public Game
{
private:
    Background* backg = nullptr;   // pano de fundo animado
    Snow* snow = nullptr;
    Timer           timer;
    Font* playerHp = nullptr;
    EndLevel* endLvl = nullptr;
    stringstream	currentHp;
public:
    static Scene* scene;           // cena do n�vel

    void Init();                    // inicializa��o do n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza��o do n�vel
};

// -----------------------------------------------------------------------------

#endif