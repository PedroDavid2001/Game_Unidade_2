/**********************************************************************************
// Player (Arquivo de Cabe�alho)
//
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _GRAVITYGUY_ENDLEVEL_H_
#define _GRAVITYGUY_ENDLEVEL_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites
#include "TileSet.h"
#include "GravityGuy.h"

// ------------------------------------------------------------------------------

class EndLevel : public Object
{
private:
	TileSet* tileset;						// folha de sprites do personagem
	Animation* anim;						// anima��o do personagem

public:

	EndLevel(float x, float y);								// construtor
	~EndLevel();							// destrutor

	void Update();							// atualiza��o do objeto
	void Draw();							// desenho do objeto
	float Width();
	float Height();
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void EndLevel::Draw()
{
	anim->Draw(x, y, z, GravityGuy::totalScale);
}

inline float EndLevel::Height()
{
	return tileset->TileHeight() * GravityGuy::totalScale;
}

inline float EndLevel::Width()
{
	return tileset->TileWidth() * GravityGuy::totalScale;
}

// ---------------------------------------------------------------------------------

#endif