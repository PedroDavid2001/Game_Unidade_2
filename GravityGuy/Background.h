/**********************************************************************************
// Background (Arquivo de Cabe�alho)
// 
// Cria��o:     21 Abr 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_BACKGROUND_H_
#define _GRAVITYGUY_BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
    float posC1, posC2;                         //posi��o horizontal das nuvens
	float posB11, posB12;							//posi��o horizontal dos primeiros predios
	float posB21, posB22;							//posi��o horizontal dos predios do meio
	float posB31, posB32;							//posi��o horizontal dos predios de tras
	

    Sprite * sky;                       // fundo est�tico

    Sprite * clouds1;                   // nuvens dinamicas
    Sprite * clouds2; 
	
	
	Sprite * build_11; //predios mais proximos
	Sprite * build_12;
	
	Sprite* build_21; //predios do meio
	Sprite* build_22;

	Sprite * build_31; //predios mais distantes
	Sprite * build_32;

    Color color;                        // cor do pano de fundo

public:
    Background(Color tint);             // construtor
    ~Background();                      // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
}; 

// ---------------------------------------------------------------------------------

#endif