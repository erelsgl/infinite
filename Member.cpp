#include "Member.h"

int Member::_count = 0;

Member::Member() {
	for (;;);  // infinite loop
}

Member::~Member() {
}

void Member::follow(Member& other) {
}

void Member::unfollow(Member& other) {
}

