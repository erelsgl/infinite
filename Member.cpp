#include "Member.h"

int Member::_count = 0;

Member::Member() {
	++_count;
}

Member::~Member() {
	for (Member* m: following) {
		this->unfollow(*m);
	}
	for (Member* m: followers) {
		m->unfollow(*this);
	}
	--_count;
}

void Member::follow(Member& other) {
	following.insert(&other);
	other.followers.insert(this);
}

void Member::unfollow(Member& other) {
	following.erase(&other);
	other.followers.erase(this);
}

