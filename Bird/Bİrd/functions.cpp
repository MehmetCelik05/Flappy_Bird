static bool pass_barrier(Bird& bird,Barrier& bar) {
	if (bird.get_pos_x() + bird.get_w()/10.f <= bar.get_pos_x() + bar.get_w()/10.f && bird.get_pos_x()>=bar.get_pos_x()) {
		return true;
	}
	else {
		return false;
	}
}

static bool bird_bar_up(Bird& bird, Barrier& b_up) {
	//bird and upper bar
	if (bird.get_pos_x() + bird.get_w() >= b_up.get_pos_x() &&
		bird.get_pos_y() + bird.get_h() >= b_up.get_pos_y() &&
		bird.get_pos_y() <= b_up.get_pos_y() + b_up.get_h()) {//bar up left
		return 1;
	}
	else if (bird.get_pos_x() <= b_up.get_pos_x() + b_up.get_w() &&
		bird.get_pos_y() + bird.get_h() >= b_up.get_pos_y() &&
		bird.get_pos_y() <= b_up.get_pos_y() + b_up.get_h()) {//bar up right
		return 1;
	}
	else if (bird.get_pos_y() <= b_up.get_pos_y() + b_up.get_h() &&
		bird.get_pos_x() + bird.get_w() >= b_up.get_pos_x() &&
		bird.get_pos_x() <= b_up.get_pos_x() + b_up.get_w()) {//bar up bottom
		return 1;
	}
	else {
		return 0;
	}
}

static bool bird_bar_down(Bird& bird, Barrier& b_down) {

	//bird and low bar
	if (bird.get_pos_x() + bird.get_w() >= b_down.get_pos_x() &&
		bird.get_pos_y() + bird.get_h() >= b_down.get_pos_y() &&
		bird.get_pos_y() <= b_down.get_pos_y() + b_down.get_h()) {//bar down left
		return 1;
	}
	else if (bird.get_pos_x() <= b_down.get_pos_x() + b_down.get_w() &&
		bird.get_pos_y() + bird.get_h() >= b_down.get_pos_y() &&
		bird.get_pos_y() <= b_down.get_pos_y() + b_down.get_h()) {//bar down right
		return 1;
	}
	else if (bird.get_pos_y() >= b_down.get_pos_y() + b_down.get_h() &&
		bird.get_pos_x() + bird.get_w() >= b_down.get_pos_x() &&
		bird.get_pos_x() <= b_down.get_pos_x() + b_down.get_w()) {//bar down top
		return 1;
	}
	else {
		return 0;
	}
}

static bool screen_bird(Bird& bird) {
	if (bird.get_pos_y() + bird.get_h() >= 540) {
		return 1;
	}
	else if (bird.get_pos_y() <= 0) {
		return 1;
	}
	else {
		return 0;
	}
}