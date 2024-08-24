class Bird {
	float pos_x, pos_y, strength = -1.f, dt, gravity=0, w, h;
	sf::RectangleShape rect;
	sf::Sprite spr;
	sf::Texture tex;
	sf::Event ev;
public:
	Bird(float pos_x_, float pos_y_, float w_, float h_) :
		pos_x(pos_x_), pos_y(pos_y_), w(w_), h(h_), dt(0)
	{
		this->rect.setSize(sf::Vector2f(w, h));
		this->rect.setPosition(pos_x, pos_y_);
		this->rect.setFillColor(sf::Color::Transparent);

		if (!tex.loadFromFile("C:/Users/mehme/source/repos/Games/Bird/Photos/bird.png")) { std::cerr << "Hata olusdu."; }
		spr.setTexture(tex);
		spr.setScale(0.1f, 0.1f);
		spr.setPosition(pos_x, pos_y);
	}

	//upgrade
	void speed_adjustment(float dt_) {//dt_ ile alakalý bir sorun var
		pos_x = rect.getPosition().x;
		pos_y = rect.getPosition().y;
		
		gravity += 0.015f;
		pos_y += gravity ;

		rect.setPosition(pos_x, pos_y);
		spr.setPosition(pos_x, pos_y);
	}

	void set_pos_y(float y) {
		pos_y = y;
	}
	void set_w(float w_) {
		w = w_;
	}
	void set_h(float h_) {
		h = h_;
	}
	void set_strength(float h_) {
		strength = h_;
	}
	void set_gravity(float y) {
		gravity = y;
	}

	float get_pos_y() const {
		return pos_y;
	}
	float get_pos_x() const {
		return pos_x;
	}
	float get_w() const {
		return w;
	}
	float get_h() const {
		return h;
	}
	float get_strength() const {
		return strength;
	}
	float get_dy() const {
		return gravity;
	}

	//render
	void display(sf::RenderWindow& window) {
		window.draw(this->rect);
		window.draw(this->spr);
	}
};
