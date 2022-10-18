#ifndef _GRAVITYGUY_LEVEL3_H_
#define _GRAVITYGUY_LEVEL3_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Font.h"
#include "Timer.h"
#include "Snow.h"
#include "Background.h"
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

class Level3 : public Game
{
private:
    Background* backg = nullptr;   // pano de fundo animado
    Timer               timer;
    Font* position =    nullptr;
    stringstream	    currentPos;
public:
    static Scene* scene;           // cena do n�vel

    void Init();                    // inicializa��o do n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza��o do n�vel
};

// -----------------------------------------------------------------------------

#endif