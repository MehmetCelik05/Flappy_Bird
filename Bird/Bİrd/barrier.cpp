class Barrier {
	float pos_x, pos_y, w, h,dx,dt;
	sf::RectangleShape rect;
public:
	Barrier(float x, float y, float w_, float h_,float d_x)
		:pos_x(x), pos_y(y), w(w_), h(h_),dx(d_x),dt(0)
	{
		rect.setFillColor(sf::Color(14, 86, 39));
		rect.setPosition(pos_x, pos_y);
		rect.setSize(sf::Vector2f(w, h));
	}

	//upgrade
	void speed_adjustment(float dt) {
		this->dt = dt;
		pos_x = rect.getPosition().x;
		pos_y = rect.getPosition().y;

		pos_x -= dx * dt;

		rect.setPosition(pos_x, pos_y);
	}

	void set_pos_x(float x) {pos_x = x;}
	void set_pos_y(float y) {pos_y = y;}
	void set_d_x(float d_x) {dx = d_x;}
	void set_w(float w_) {w = w_;}
	void set_h(float h_) {h = h_;}

	float get_pos_x() const{return pos_x;}
	float get_pos_y() const{return pos_y;}
	float get_d_x() const{return dx;}
	float get_w() const{return w;}
	float get_h() const{return h;}

	//render
	void display(sf::RenderWindow& window) {
		window.draw(this->rect);
	}
};