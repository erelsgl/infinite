
#include <set>
#include <string>
using namespace std;

class Member {
	string name;
	set<Member*> following;
	set<Member*> followers;
	static int _count;

public:
	Member() {
		++_count;
	}

	~Member() {
		for (Member* m: following) {
			this->unfollow(*m);
		}
		for (Member* m: followers) {
			m->unfollow(*this);
		}
		--_count;
	}

	void follow(Member& other) {
		following.insert(&other);
		other.followers.insert(this);
	}

	void unfollow(Member& other) {
		following.erase(&other);
		other.followers.erase(this);
	}

	int numFollowing() {
		return following.size();
	}

	int numFollowers() {
		return followers.size();
	}

	static int count() { return _count; }
};


int Member::_count = 0;
