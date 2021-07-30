#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "macros.h"
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

#pragma once
//all the texture are created with singelton ,static object .
//----------------------------------------------------------------------------
class Textures {

    //--------------public--------functions-----------------------//
public:
    static Textures& instance();
    //gets requested sound from sound member
    const sf::Texture& get_Textures(int type_E) const { return (*m_all_textures[type_E]); }
    const sf::Font& get_Font() const { return m_Font; }
    const vector<shared_ptr<Texture>> get_Texture_vector(int type_E) const { return (m_vectors[type_E]); }
    //--------------private--------functions-----------------------//
private:
    Textures();//constractor for static member
    ~Textures();
    vector<shared_ptr<Texture>> m_all_textures;
    vector<vector<shared_ptr<Texture>>> m_vectors;
    sf::Font m_Font;
};
//----------------------------------------------------------------------------