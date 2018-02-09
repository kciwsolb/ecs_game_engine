#include "InputManager.h"
#include "GameObjectManager.h"
#include "EntityManager.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "Time.h"
#include "Tank.h"
#include "Barrier.h"
#include "Block.h"
#include "Background.h"

class Game {
public:
	Game() {
		Init();
	}
	void Update() {}

private:
	Background* background;
	Tank* player1;
	Tank* player2;
	Barrier* barrier1;
	Barrier* barrier2;
	Barrier* barrier3;
	Barrier* barrier4;
	Barrier* barrier5;
	Barrier* barrier6;
	Barrier* barrier7;
	Barrier* barrier8;
	Barrier* barrier9;
	Barrier* barrier10;
	Barrier* barrier11;
	Barrier* barrier12;
	Barrier* barrier13;
	Barrier* barrier14;
	Barrier* barrier15;
	Barrier* barrier16;
	Barrier* barrier17;
	Barrier* barrier18;
	Barrier* barrier19;
	Barrier* barrier20;
	Barrier* barrier21;
	Barrier* barrier22;
	Barrier* barrier23;
	Barrier* barrier24;
	Barrier* barrier25;
	Barrier* barrier26;
	Barrier* barrier27;
	Barrier* barrier28;
	Barrier* barrier29;
	Barrier* barrier30;
	Barrier* barrier31;
	Barrier* barrier32;
	Barrier* barrier33;
	Barrier* barrier34;
	Barrier* barrier35;
	Barrier* barrier36;
	Barrier* barrier37;
	Barrier* barrier38;
	Barrier* barrier39;
	Barrier* barrier40;
	Barrier* barrier41;
	Barrier* barrier42;
	Barrier* barrier43;
	Barrier* barrier44;
	Barrier* barrier45;
	Barrier* barrier46;
	Barrier* barrier47;
	Barrier* barrier48;
	Barrier* barrier49;
	Barrier* barrier50;
	Barrier* barrier51;
	Barrier* barrier52;
	Barrier* barrier53;
	Barrier* barrier54;
	Barrier* barrier55;
	Barrier* barrier56;
	Barrier* barrier57;
	Barrier* barrier58;
	Barrier* barrier59;
	Barrier* barrier60;
	Barrier* barrier61;
	Barrier* barrier62;
	Barrier* barrier63;
	Barrier* barrier64;
	Barrier* barrier65;
	Barrier* barrier66;
	Barrier* barrier67;
	Barrier* barrier68;
	Barrier* barrier69;
	Barrier* barrier70;
	Barrier* barrier71;
	Barrier* barrier72;
	Barrier* barrier73;
	Barrier* barrier74;
	Barrier* barrier75;
	Barrier* barrier76;
	Barrier* barrier77;
	Barrier* barrier78;
	Barrier* barrier79;
	Barrier* barrier80;
	Barrier* barrier81;

	Block* block1;
	Block* block2;
	Block* block3;
	Block* block4;
	Block* block5;
	Block* block6;
	Block* block7;
	Block* block8;
	Block* block9;
	Block* block10;
	Block* block11;
	Block* block12;
	Block* block13;
	Block* block14;
	Block* block15;
	Block* block16;
	Block* block17;
	Block* block18;
	Block* block19;
	Block* block20;

	void Init() {
		background = GameObjectManager::SharedInstance().AddGameObject<Background>(512.0f, 512.0f);

		player1 = GameObjectManager::SharedInstance().AddGameObject<Tank>(576.0f, 320.0f, 1);
		player2 = GameObjectManager::SharedInstance().AddGameObject<Tank>(64.0f, 320.0f, 2);

		/*Top Barrier*/
		barrier1 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 16.0f);
		barrier2 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(48.0f, 16.0f);
		barrier3 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(80.0f, 16.0f);
		barrier4 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(112.0f, 16.0f);
		barrier5 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(144.0f, 16.0f);
		barrier6 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(176.0f, 16.0f);
		barrier7 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(208.0f, 16.0f);
		barrier8 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(240.0f, 16.0f);
		barrier9 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(272.0f, 16.0f);
		barrier10 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(304.0f, 16.0f);
		barrier11 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(336.0f, 16.0f);
		barrier12 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(368.0f, 16.0f);
		barrier13 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(400.0f, 16.0f);
		barrier14 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(432.0f, 16.0f);
		barrier15 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(464.0f, 16.0f);
		barrier16 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(496.0f, 16.0f);
		barrier17 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(528.0f, 16.0f);
		barrier18 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(560.0f, 16.0f);
		barrier19 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(592.0f, 16.0f);
		barrier20 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 16.0f);

		/*Left Barrier*/
		barrier21 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 48.0f);
		barrier22 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 80.0f);
		barrier23 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 112.0f);
		barrier24 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 144.0f);
		barrier25 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 176.0f);
		barrier26 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 208.0f);
		barrier27 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 240.0f);
		barrier28 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 272.0f);
		barrier29 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 304.0f);
		barrier30 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 336.0f);
		barrier31 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 368.0f);
		barrier32 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 400.0f);
		barrier33 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 432.0f);
		barrier34 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 464.0f);
		barrier35 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 496.0f);
		barrier36 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 528.0f);
		barrier37 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 560.0f);
		barrier38 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 592.0f);
		
		/*Bottom Barrier*/
		barrier39 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(16.0f, 624.0f);
		barrier41 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(48.0f, 624.0f);
		barrier42 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(80.0f, 624.0f);
		barrier43 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(112.0f, 624.0f);
		barrier44 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(144.0f, 624.0f);
		barrier45 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(176.0f, 624.0f);
		barrier46 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(208.0f, 624.0f);
		barrier47 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(240.0f, 624.0f);
		barrier48 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(272.0f, 624.0f);
		barrier49 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(304.0f, 624.0f);
		barrier50 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(336.0f, 624.0f);
		barrier51 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(368.0f, 624.0f);
		barrier52 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(400.0f, 624.0f);
		barrier53 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(432.0f, 624.0f);
		barrier54 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(464.0f, 624.0f);
		barrier55 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(496.0f, 624.0f);
		barrier56 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(528.0f, 624.0f);
		barrier57 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(560.0f, 624.0f);
		barrier58 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(592.0f, 624.0f);
		barrier59 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 624.0f);

		/*Right Barrier*/
		barrier60 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 48.0f);
		barrier61 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 80.0f);
		barrier62 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 112.0f);
		barrier63 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 144.0f);
		barrier64 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 176.0f);
		barrier65 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 208.0f);
		barrier66 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 240.0f);
		barrier67 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 272.0f);
		barrier68 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 304.0f);
		barrier69 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 336.0f);
		barrier70 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 368.0f);
		barrier71 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 400.0f);
		barrier72 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 432.0f);
		barrier73 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 464.0f);
		barrier74 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 496.0f);
		barrier75 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 528.0f);
		barrier76 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 560.0f);
		barrier77 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(624.0f, 592.0f);

		/*Middle Barrier*/
		barrier78 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(304.0f, 304.0f);
		barrier79 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(336.0f, 304.0f);
		barrier80 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(304.0f, 336.0f);
		barrier81 = GameObjectManager::SharedInstance().AddGameObject<Barrier>(336.0f, 336.0f);

		/*Left Player Spawn Blocks*/
		block1 = GameObjectManager::SharedInstance().AddGameObject<Block>(144.0f, 272.0f);
		block2 = GameObjectManager::SharedInstance().AddGameObject<Block>(144.0f, 240.0f);
		block3 = GameObjectManager::SharedInstance().AddGameObject<Block>(112.0f, 240.0f);
		block4 = GameObjectManager::SharedInstance().AddGameObject<Block>(144.0f, 368.0f);
		block5 = GameObjectManager::SharedInstance().AddGameObject<Block>(144.0f, 400.0f);
		block6 = GameObjectManager::SharedInstance().AddGameObject<Block>(112.0f, 400.0f);

		/*Right Player Spawn Blocks*/
		block7 = GameObjectManager::SharedInstance().AddGameObject<Block>(496.0f, 272.0f);
		block8 = GameObjectManager::SharedInstance().AddGameObject<Block>(496.0f, 240.0f);
		block9 = GameObjectManager::SharedInstance().AddGameObject<Block>(528.0f, 240.0f);
		block10 = GameObjectManager::SharedInstance().AddGameObject<Block>(496.0f, 368.0f);
		block11 = GameObjectManager::SharedInstance().AddGameObject<Block>(496.0f, 400.0f);
		block12 = GameObjectManager::SharedInstance().AddGameObject<Block>(528.0f, 400.0f);

		/*Top Blocks*/
		block13 = GameObjectManager::SharedInstance().AddGameObject<Block>(272.0f, 208.0f);
		block14 = GameObjectManager::SharedInstance().AddGameObject<Block>(304.0f, 208.0f);
		block15 = GameObjectManager::SharedInstance().AddGameObject<Block>(336.0f, 208.0f);
		block16 = GameObjectManager::SharedInstance().AddGameObject<Block>(368.0f, 208.0f);

		/*Bottom Blocks*/
		block17 = GameObjectManager::SharedInstance().AddGameObject<Block>(272.0f, 432.0f);
		block18 = GameObjectManager::SharedInstance().AddGameObject<Block>(304.0f, 432.0f);
		block19 = GameObjectManager::SharedInstance().AddGameObject<Block>(336.0f, 432.0f);
		block20 = GameObjectManager::SharedInstance().AddGameObject<Block>(368.0f, 432.0f);
	}
};