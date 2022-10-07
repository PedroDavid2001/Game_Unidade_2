/**********************************************************************************
// Player (C�digo Fonte)
//
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Snow.h"
#include "Level1.h"

// ---------------------------------------------------------------------------------

Snow::Snow()
{
    snow = new Sprite("Resources/snow.png");
    MoveTo(posX(mt), -posYInit(mt), Layer::FRONT);
}

// ---------------------------------------------------------------------------------

Snow::~Snow()
{
    delete snow;
}

// ---------------------------------------------------------------------------------

void Snow::Update()
{
    //cai lentamente
    Translate(-50.0f * gameTime, 100.0f * gameTime);

    //deleta quando sair da tela
    if (y > window->Height())
        Level1::scene->Delete(this, STATIC);
}