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

#ifndef _GRAVITYGUY_BULLET_H_
#define _GRAVITYGUY_BULLET_H_

// ------------------------------------------------------------------------------

#include "Object.h"
#include "Animation.h"                  // anima��o de sprites
#include "TileSet.h"

// ------------------------------------------------------------------------------

class Bullet : public Object
{
private:
    TileSet* tileset;                
    Animation* anim;                  
    bool direction;             //left = false; right = true
    float scale;
public:
    Bullet(bool direction, float scale);
    ~Bullet();
    void Update();
    void Draw();
	void OnCollision(Object* obj);
    float Width();
    float Height();
};
// ------------------------------------------------------------------------------

inline void Bullet::Draw() { anim->Draw(x, y, z, scale); }

inline float Bullet::Height()
{
    return tileset->TileHeight() * scale;
}

inline float Bullet::Width()
{
    return tileset->TileWidth() * scale;
}

// ------------------------------------------------------------------------------

#endif