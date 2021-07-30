#pragma once
#include "../include/All_animation/Textures.h" 
//----------------------------------------------------------------------------
//set textures for all object in the game once
Textures::Textures()
{
    m_Font.loadFromFile("Love America.ttf");//setting one font
    vector<std::string> names =
    {
        "goal.png",
        "foot.png",
        "world.png",
        "yeti.png",
        "moon.jpg",
        "score.png",
        "background.jpg",
        "pause.png",
        "speaker.png",
        "speaker2.png"
    };

    vector<vector<string>> names2 =
    {
        {"start.png", "start2.png"},
        {"exit.png", "exit2.png"},
        {"back.png", "back2.png"},
        {"howto.png", "howto2.png"},
        {"instruction.png" ,"instruction.png" },
        {"nerd.png","nerd2.png"},
        {"chicken.png","chicken2.png"},
        {"santa.png","santa2.png"},
        {"boy.png","boy2.png"},
        {"moon.jpg","moon.jpg"},
        {"world.png","world.png"},
        {"frame.png", "frame.png"},
        {"mapframe.png", "mapframe.png"},
        {"new_game.png", "new_game2.png"},
        {"draw.png" ,"draw.png"  },
        {"player 1 winner.png" ,"player 1 winner.png"  },
        {"player 2 won.png","player 2 won.png" },
        {"continue.png","continue2.png" },
        {"backtomenu.png","backtomenu2.png" },
        {"quit.png","quit2.png" },
       
    };

    shared_ptr<Texture> pic;
    for (int i = 0; i < names.size(); i++) {
        pic = make_shared<Texture>();
        if(!pic->loadFromFile(names[i])) {
            string temp = "couldnt tex sound" + names[i];
            throw exception(temp.c_str());
        }
        m_all_textures.emplace_back(pic);
    }

    vector<shared_ptr<Texture>> temp;
    for (int i = 0; i < names2.size(); i++) {
        for (int j = 0; j < names2[i].size(); j++) {
            pic = make_shared<Texture>();
            if (!pic->loadFromFile(names2[i][j])) {
                string temp = "couldnt tex sound" + names2[i][j];
                throw exception(temp.c_str());
            }
            temp.emplace_back(pic);
        }
        m_vectors.emplace_back(temp);
        temp.clear();
    }
}
//----------------------------------------------------------------------------
Textures& Textures::instance() {
    static Textures all_S;
    return all_S;
}
//----------------------------------------------------------------------------
Textures::~Textures()
{
    m_all_textures.clear();
    m_vectors.clear();
}
//----------------------------------------------------------------------------