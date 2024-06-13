#include "fight.hpp"

enum Location { Plain, River, Mountin };

void attack() {}

void attack_enemy() {}

struct Dino {
    int damage = 0;
    int hp = 0;
    char place = 'o';
    bool isdie = 0;
    sf::Texture DinoTexture;
    sf::Sprite DinoSprite;
};
struct Trex : public Dino {
    Trex() {
        damage = 4;
        hp = 10;
        place = 'p';
        DinoTexture.loadFromFile("/Users/admin/Downloads/�®¢ ï ¯ ¯ª /image/dinoR.png");
        DinoSprite.setTexture(DinoTexture);
        DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
    }
};
struct Stegosaurus : public Dino {
    Stegosaurus() {
        damage = 3;
        hp = 11;
        place = 'm';
        DinoTexture.loadFromFile("/Users/admin/Downloads/�®¢ ï ¯ ¯ª /image/dinoS.png");
        DinoSprite.setTexture(DinoTexture);
        DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
    }
};
struct Triceratops : public Dino {
    Triceratops() {
        damage = 5;
        hp = 8;
        place = 'r';
        DinoTexture.loadFromFile("/Users/admin/Downloads/�®¢ ï ¯ ¯ª /image/dinoT.png");
        DinoSprite.setTexture(DinoTexture);
        DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
    }
};
struct Brachiosaurus : public Dino {
    Brachiosaurus() {
        damage = 2;
        hp = 14;
        place = 'm';
        DinoTexture.loadFromFile("/Users/admin/Downloads/�®¢ ï ¯ ¯ª /image/dinoB.png");
        DinoSprite.setTexture(DinoTexture);
        DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
    }
};
struct Velociraptor : public Dino {
    Velociraptor() {
        damage = 6;
        hp = 7;
        place = 'r';
        DinoTexture.loadFromFile("/Users/admin/Downloads/�®¢ ï ¯ ¯ª /image/dinoV.png");
        DinoSprite.setTexture(DinoTexture);
        DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
    }
};

int Damage(char pl, int l, int dd) {
    if (l == 0) {
        if (pl == 'p') return dd * 2;
        else return dd;
    }
    if (l == 1) {
        if (pl == 'r') return dd * 2;
        else return dd;
    }
    if (l == 2) {
        if (pl == 'm') return dd * 2;
        else return dd;
    }
    return 0;
}


int fight(sf::RenderWindow& win)
{
    sf::Music main;
    main.openFromFile("/Users/admin/Desktop/KseniaDino/KseniaDino/music/fight.ogg");
    main.play();
    main.setLoop(true);

    srand((unsigned int)time(NULL));
    int locat = rand() % 3;

    sf::Texture Texforback;
    Texforback.loadFromFile("/Users/admin/Downloads/�®¢ ï ¯ ¯ª /image/main.png");
    sf::RectangleShape background(sf::Vector2f(1920, 1080));
    background.setTexture(&Texforback);
    background.setPosition(sf::Vector2f(0, 0));
    if (locat == Plain) { Texforback.loadFromFile("/Users/admin/Downloads/�®¢ ï ¯ ¯ª /image/field.png");  }
    if (locat == River) { Texforback.loadFromFile("/Users/admin/Downloads/�®¢ ï ¯ ¯ª /image/redgrass.png"); }
    if (locat == Mountin) { Texforback.loadFromFile("/Users/admin/Downloads/�®¢ ï ¯ ¯ª /image/lava.png"); }
    background.setTexture(&Texforback);

    Trex PTrex; Stegosaurus PStegosaurus; Triceratops PTriceratops; Brachiosaurus PBrachiosaurus; Velociraptor PVelociraptor;
    Trex ETrex; Stegosaurus EStegosaurus; Triceratops ETriceratops; Brachiosaurus EBrachiosaurus; Velociraptor EVelociraptor;

    fstream deck; string path_deck = "/Users/admin/Desktop/KseniaDino/KseniaDino/deck.txt"; string Sdeck;
    deck.open(path_deck); deck >> Sdeck; deck.close();
    bool pd1 = 0, pd2 = 0, pd3 = 0, ed1 = 0, ed2 = 0, ed3 = 0;
    vector<Dino> Pdeck;
    vector<Dino> Edeck;

    if (Sdeck.find('R') != std::string::npos) { Pdeck.push_back(PTrex); }
    if (Sdeck.find('S') != std::string::npos) { Pdeck.push_back(PStegosaurus); }
    if (Sdeck.find('T') != std::string::npos) { Pdeck.push_back(PTriceratops); }
    if (Sdeck.find('B') != std::string::npos) { Pdeck.push_back(PBrachiosaurus); }
    if (Sdeck.find('V') != std::string::npos) { Pdeck.push_back(PVelociraptor);}


    int a = abs(rand() % 5); int b = abs(rand() % 5); int c = abs(rand() % 5);
    
    if (a == 0 or b == 0 or c == 0) {
        if (a == 0) Edeck.push_back(ETrex);
        if (b == 0) Edeck.push_back(ETrex);
        if (c == 0) Edeck.push_back(ETrex);
    }
    if (a == 1 or b == 1 or c == 1) {
        if (a == 1) Edeck.push_back(EStegosaurus);
        if (b == 1) Edeck.push_back(EStegosaurus);
        if (c == 1) Edeck.push_back(EStegosaurus);
    }
    if (a == 2 or b == 2 or c == 2) {
        if (a == 2) Edeck.push_back(ETriceratops);
        if (b == 2) Edeck.push_back(ETriceratops);
        if (c == 2) Edeck.push_back(ETriceratops);
    }
    if (a == 3 or b == 3 or c == 3) {
        if (a == 3) Edeck.push_back(EBrachiosaurus);
        if (b == 3) Edeck.push_back(EBrachiosaurus);
        if (c == 3) Edeck.push_back(EBrachiosaurus);
    }
    if (a == 4 or b == 4 or c == 4) {
        if (a == 4) Edeck.push_back(EVelociraptor);
        if (b == 4) Edeck.push_back(EVelociraptor);
        if (c == 4) Edeck.push_back(EVelociraptor);
    }



    Pdeck[0].DinoSprite.setPosition(sf::Vector2f(172, 80));

    Pdeck[1].DinoSprite.setPosition(sf::Vector2f(172, 440));

    Pdeck[2].DinoSprite.setPosition(sf::Vector2f(172, 800));

    Edeck[0].DinoSprite.setPosition(sf::Vector2f(1528, 80));

    Edeck[1].DinoSprite.setPosition(sf::Vector2f(1528, 440));

    Edeck[2].DinoSprite.setPosition(sf::Vector2f(1528, 800));

    int attack_gamage = Damage(Pdeck[0].place, locat, Pdeck[0].damage);
    sf::Clock clock;
    int ed = 0, pd = 0;
    int actDino = 0;

    
    while (win.isOpen() and ed != 3 and pd != 3)
    {
        if (Pdeck[actDino].isdie == 1) {
            if (actDino == 2) {
                actDino = 0;
                attack_gamage = Damage(Pdeck[0].place, locat, Pdeck[0].damage);
            }
            else {
                actDino++;
                attack_gamage = Damage(Pdeck[actDino].place, locat, Pdeck[actDino].damage);
            }
        }
        sf::Event event;
        sf::Vector2i mousePoz = sf::Mouse::getPosition(win);
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { win.close(); }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {
                    if (Pdeck[0].DinoSprite.getGlobalBounds().contains(mousePoz.x, mousePoz.y) and Pdeck[0].isdie == 0) {
                        attack_gamage = Damage(Pdeck[0].place, locat, Pdeck[0].damage);
                        Pdeck[0].DinoSprite.setTextureRect(sf::IntRect(200, 0, 200, 200));
                        actDino = 0;
                    }
                    if (Pdeck[1].DinoSprite.getGlobalBounds().contains(mousePoz.x, mousePoz.y) and Pdeck[1].isdie == 0) {
                        attack_gamage = Damage(Pdeck[1].place, locat, Pdeck[0].damage);
                        Pdeck[1].DinoSprite.setTextureRect(sf::IntRect(200, 0, 200, 200));
                        actDino = 1;
                    }

                    if (Pdeck[2].DinoSprite.getGlobalBounds().contains(mousePoz.x, mousePoz.y) and Pdeck[2].isdie == 0) {
                        attack_gamage = Damage(Pdeck[2].place, locat, Pdeck[0].damage);
                        Pdeck[2].DinoSprite.setTextureRect(sf::IntRect(200, 0, 200, 200));
                        actDino = 2;

                    }
                    if (Edeck[0].DinoSprite.getGlobalBounds().contains(mousePoz.x, mousePoz.y) and Edeck[0].isdie == 0) {
                        Edeck[0].hp = Edeck[0].hp - attack_gamage;
                        Pdeck[actDino].DinoSprite.setTextureRect(sf::IntRect(200, 0, 200, 200));
                        if (Edeck[0].hp <= 0 and Edeck[0].isdie == 0) { Edeck[0].DinoSprite.setTextureRect(sf::IntRect(400, 0, 200, 200)); ed++; Edeck[0].isdie = 1; }
                        else {
                            Edeck[0].DinoSprite.setTextureRect(sf::IntRect(200, 0, 200, 200));
                        }
                        Pdeck[actDino].hp = Pdeck[actDino].hp - Damage(Edeck[0].place, locat, Edeck[0].damage);
                        if (Pdeck[actDino].hp <= 0) {
                            Pdeck[actDino].isdie = 1; Pdeck[actDino].DinoSprite.setTextureRect(sf::IntRect(400, 0, 200, 200)); pd++;
                        }
                    }
                    if (Edeck[1].DinoSprite.getGlobalBounds().contains(mousePoz.x, mousePoz.y) and Edeck[1].isdie == 0) {
                        Edeck[1].hp = Edeck[1].hp - attack_gamage;
                        Pdeck[actDino].DinoSprite.setTextureRect(sf::IntRect(200, 0, 200, 200));
                        if (Edeck[1].hp <= 0 and Edeck[1].isdie == 0) { Edeck[1].DinoSprite.setTextureRect(sf::IntRect(400, 0, 200, 200)); ed++; Edeck[1].isdie = 1; }
                        else {
                            Edeck[1].DinoSprite.setTextureRect(sf::IntRect(200, 0, 200, 200));
                        }
                        Pdeck[actDino].hp = Pdeck[actDino].hp - Damage(Edeck[1].place, locat, Edeck[1].damage);
                        if (Pdeck[actDino].hp <= 0) {
                            Pdeck[actDino].isdie = 1; Pdeck[actDino].DinoSprite.setTextureRect(sf::IntRect(400, 0, 200, 200)); pd++;
                            

                        }
                    }
                    if (Edeck[2].DinoSprite.getGlobalBounds().contains(mousePoz.x, mousePoz.y) and Edeck[2].isdie == 0) {
                        Edeck[2].hp = Edeck[2].hp - attack_gamage;
                        Pdeck[actDino].DinoSprite.setTextureRect(sf::IntRect(200, 0, 200, 200));
                        if (Edeck[2].hp <= 0 and Edeck[2].isdie == 0) { Edeck[2].DinoSprite.setTextureRect(sf::IntRect(400, 0, 200, 200)); ed++; Edeck[2].isdie = 1; }
                        else {
                            Edeck[2].DinoSprite.setTextureRect(sf::IntRect(200, 0, 200, 200));
                        }
                        Pdeck[actDino].hp = Pdeck[actDino].hp - Damage(Edeck[2].place, locat, Edeck[2].damage);
                        if (Pdeck[actDino].hp <= 0) {
                            Pdeck[actDino].isdie = 1; Pdeck[actDino].DinoSprite.setTextureRect(sf::IntRect(400, 0, 200, 200)); pd++;
                        }
                    }
                    
                    
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.key.code == sf::Mouse::Left) {
                    if (Pdeck[0].DinoSprite.getGlobalBounds().contains(mousePoz.x, mousePoz.y) and Pdeck[0].isdie == 0) {
                        clock.restart();
                        while (clock.getElapsedTime() < sf::milliseconds(500)) {}
                        Pdeck[0].DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
                    }
                    if (Pdeck[1].DinoSprite.getGlobalBounds().contains(mousePoz.x, mousePoz.y) and Pdeck[1].isdie == 0) {
                        clock.restart();
                        while (clock.getElapsedTime() < sf::milliseconds(500)) {}
                        Pdeck[1].DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
                    }
                    if (Pdeck[2].DinoSprite.getGlobalBounds().contains(mousePoz.x, mousePoz.y) and Pdeck[2].isdie == 0) {
                        clock.restart();
                        while (clock.getElapsedTime() < sf::milliseconds(500)) {}
                        Pdeck[2].DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
                    }




                    if (Edeck[0].DinoSprite.getGlobalBounds().contains(mousePoz.x, mousePoz.y)){
                        clock.restart();
                        while (clock.getElapsedTime() < sf::milliseconds(500)) {}
                        if (Edeck[0].isdie == 1 and Pdeck[actDino].isdie == 1) {}
                        else if (Edeck[0].isdie == 1) {
                            Pdeck[actDino].DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
                        }
                        else if (Pdeck[actDino].isdie == 1) {Edeck[0].DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));}
                        else {
                            Edeck[0].DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
                            Pdeck[actDino].DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
                        }


                    }
                    if (Edeck[1].DinoSprite.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                        clock.restart();
                        while (clock.getElapsedTime() < sf::milliseconds(500)) {}
                        if (Edeck[1].isdie == 1 and Pdeck[actDino].isdie == 1) {}
                        else if (Edeck[1].isdie == 1) {
                            Pdeck[actDino].DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
                        }
                        else if (Pdeck[actDino].isdie == 1) { Edeck[1].DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200)); }
                        else {
                            Edeck[1].DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
                            Pdeck[actDino].DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
                        }
                    }



                    if (Edeck[2].DinoSprite.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                        clock.restart();
                        while (clock.getElapsedTime() < sf::milliseconds(500)) {}
                        if (Edeck[2].isdie == 1 and Pdeck[actDino].isdie == 1) {}
                        else if (Edeck[2].isdie == 1) {
                            Pdeck[actDino].DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
                        }
                        else if (Pdeck[actDino].isdie == 1) { Edeck[2].DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200)); }
                        else {
                            Edeck[2].DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
                            Pdeck[actDino].DinoSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
                        }
                    }

                }

            }

        }
            win.clear();
            win.draw(background);
            win.draw(Pdeck[0].DinoSprite);
            win.draw(Pdeck[1].DinoSprite);
            win.draw(Pdeck[2].DinoSprite);
            win.draw(Edeck[0].DinoSprite);
            win.draw(Edeck[1].DinoSprite);
            win.draw(Edeck[2].DinoSprite);
            win.display();
        
    }
    main.stop();
    if (ed == 3) return 1;
    else return 0;
}
