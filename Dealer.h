#pragma once

#include "Player.h"
#include "User.h"

namespace BlackJack {
	class Dealer : public Player
	{
	private:
		std::shared_ptr<std::vector<User>> m_Users;
	public:
		void Hit(Deck& deck) override;
		void Stand() override;

		void setUsers(std::shared_ptr<std::vector<User>> users);
		void Distribute(Deck& deck);
	};
}