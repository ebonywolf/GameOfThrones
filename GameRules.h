#ifndef GAMERULES_H
#define GAMERULES_H
class Player;
class Game;
class GameRules
{
	public:
		 int houseAmount;
		 int turnTime;
		/** Default constructor */

		/** Default destructor */
		GameRules(){};
		GameRules ( int houseAmount, int turnTime );
		Player* checkVictoryCondition(Game*);
		virtual ~GameRules();

	protected:

	private:
};

#endif // GAMERULES_H
