/**********************************************************************************
// Level2 (Arquivo de Cabe�alho)
//
// Cria��o:     27 Set 2021
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   N�vel 2 do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_BOSSLVL1_H_
#define _GRAVITYGUY_BOSSLVL1_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Background.h"
#include "Boss.h"

// ------------------------------------------------------------------------------

class BossLVL1 : public Game
{
private:
    Background* backg = nullptr;   // pano de fundo animado
    Boss *      boss  = nullptr;
public:
    static Scene* scene;           // cena do n�vel

    void Init();                    // inicializa��o do n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza��o do n�vel
};

// -----------------------------------------------------------------------------

#endif