/**********************************************************************************
// GameOver (Arquivo de Cabe�alho)
//
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Fim do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_SPIKES_H_
#define _GRAVITYGUY_SPIKES_H_

// ------------------------------------------------------------------------------

#include "Object.h"
#include "Animation.h"                  // anima��o de sprites
#include "TileSet.h"
#include "GravityGuy.h"

// ------------------------------------------------------------------------------

class Spikes : public Object
{
private:
    TileSet* tileset;
    Animation* anim;
    bool direction;             //left = false; right = true
public:
    bool touched;               //indica se encostou no player
    Spikes(bool direction, float xx);
    ~Spikes();
    void Update();
    void Draw();
    float Width();
    float Height();
};
// ------------------------------------------------------------------------------

inline void Spikes::Draw() { anim->Draw(x, y, z, GravityGuy::totalScale); }

inline float Spikes::Height()
{
    return tileset->TileHeight() * GravityGuy::totalScale;
}

inline float Spikes::Width()
{
    return tileset->TileWidth() * GravityGuy::totalScale;
}

// ------------------------------------------------------------------------------

#endif