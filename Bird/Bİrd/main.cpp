#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include<ctime>
#include<vector>
#include<iostream>
#include"bird.cpp"
#include"barrier.cpp"
#include"functions.cpp"

//Objects
sf::RenderWindow window(sf::VideoMode(960, 540), "Flappy Bird", sf::Style::Titlebar | sf::Style::Close | sf::Style::Default);
sf::Event ev;
sf::Clock c;
sf::Clock end;
sf::Color clr;
sf::Texture tex;
sf::Sprite spr;

//Lists
std::vector<std::pair<Barrier, Barrier>> bars;
std::vector<std::pair<Barrier, Barrier>>::iterator it;

//Variables
int score = 0;


static void score_Text(int sc,float x,float y) {
	sf::Font font;
	sf::Text text1;
	if (!font.loadFromFile("C:/Users/mehme/source/repos/Games/Bird/fonts/Dee-Quickest Sans.otf")) { std::cerr << "Fontta hata olusdu. "; }

	text1.setFont(font);
	text1.setFillColor(sf::Color::Black);
	text1.setCharacterSize(45);
	text1.setPosition(x,y);
	text1.setStyle(sf::Text::Bold);
	text1.setString("Score: " + std::to_string(sc));
	window.draw(text1);
}

void fail_screen() {

	window.clear(sf::Color::Yellow);
	score_Text(score, 360, 240);
	window.display();

	if (end.getElapsedTime().asSeconds() >= 2.f) {
		window.close();
	}
	if (ev.type == sf::Event::Closed) {
		window.close();
	}
	std::cout << "Fail" << std::endl;
}

int main() {
	srand(static_cast<unsigned int>(time(0)));
	float dt = c.restart().asSeconds();
	bool game_over = false;
	window.setVerticalSyncEnabled(true);

	//back ground picture
	if (!tex.loadFromFile("C:/Users/mehme/source/repos/Games/Bird/Photos/background.png")) { std::cerr << "Hata"; }
	spr.setTexture(tex);


	//objects
	Bird bird(200,200, 40, 40);//y,w,h
	Barrier bar_up(900, 0, 60, 200, 100);//x,y,w,h,dx
	Barrier bar_down(900, 440, 60, 200, 100);

	//add to vector
	bars.push_back(std::make_pair(bar_up, bar_down));


	while (window.isOpen()) {
		dt = c.restart().asSeconds();
		if (game_over) {
			fail_screen();

			if (ev.type == sf::Event::Closed && ev.key.code == sf::Keyboard::Escape) {
				window.close();
			}
			continue;
		}
		if (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed) {
				window.close();
			}
			if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Space) {
				bird.set_gravity(bird.get_strength());
			}
		}

		bool newBar = false;

		///upgrade
		bird.speed_adjustment(dt);
		//bars movement and check passing bar
		for (it = bars.begin(); it != bars.end();) {
			it->first.speed_adjustment(dt);
			it->second.speed_adjustment(dt);
			if (pass_barrier(bird, it->first) && !newBar) {
				newBar = true;
			}
			if (it->first.get_pos_x() + it->first.get_w() < 0) {
				it = bars.erase(it);
			}
			else {
				++it;
			}
		}
		//adding new bars int to the screen
		if (newBar) {
			float up_h = rand() % 220 + 100;
			float down_h = rand() % 220 + 100;
			float h = window.getSize().y - (up_h + down_h);
			Barrier new_bar_up(900, 0, 60, up_h, 150);
			Barrier new_bar_down(900, 440, 60, down_h, 150);
			bars.push_back(std::make_pair(new_bar_up, new_bar_down));
			bird_bar_up(bird, new_bar_up);
			bird_bar_down(bird, new_bar_down);
			if (!bird_bar_down(bird, new_bar_down) && !bird_bar_up(bird, new_bar_up)) {
				++score;
			}
			else {
				game_over = true;
				end.restart();
			}
		}

		if (screen_bird(bird)) {
			game_over = true;
			end.restart();
		}
		window.clear(sf::Color::Cyan);
		window.draw(spr);
		///render
		bird.display(window);
		for (it = bars.begin(); it != bars.end(); it++) {
			it->first.display(window);
			it->second.display(window);
		}
		score_Text(score, 20, 20);
		window.display();
	}
	return 0;
}