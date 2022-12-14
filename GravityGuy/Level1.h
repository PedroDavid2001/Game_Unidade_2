/**********************************************************************************
// Level1 (Arquivo de Cabe?alho)
// 
// Cria??o:     14 Fev 2013
// Atualiza??o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri??o:   N?vel 1 do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_LEVEL1_H_
#define _GRAVITYGUY_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclus?es

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

class Level1 : public Game
{
private:
    Background*     backg = nullptr;   // pano de fundo animado
    Snow*           snow = nullptr;
    Timer           timer;
    Font*           playerHp = nullptr;
    Font*           playerScore = nullptr;
    Font*           controls = nullptr;
    Font*           controls2 = nullptr;
    Font*           controls3 = nullptr;
    EndLevel*       endLvl = nullptr;
    stringstream	currentHp;
    stringstream	currentScore;
    stringstream    ctrls;
    stringstream    ctrls2;
    stringstream    ctrls3;
public:
    static Scene* scene;           // cena do n?vel

    void Init();                    // inicializa??o do n?vel
    void Update();                  // atualiza l?gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza??o do n?vel
};

// -----------------------------------------------------------------------------

#endif