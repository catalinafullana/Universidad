package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.GameWorld;
import tp1.logic.Position;

public abstract class GameObject implements GameItem {

	protected Position pos;
	protected int life;
	protected GameWorld gameW;
	
	public GameObject(GameWorld gameW, Position pos, int life) {
		this.pos = pos;
		this.gameW = gameW;
		this.life = life;
	}
	
	@Override
	public boolean isAlive() {
		return this.life > 0;
	}

	protected int getLife() {
		return this.life;
	}

	//TODO fill with your code

	
	protected abstract String getSymbol();
	protected abstract int getDamage();
	protected abstract int getArmour();
	
			
	public abstract void onDelete();
	public abstract void automaticMove();
	public void computerAction() {
	};
	
	//TODO fill with your code
	
	@Override
	public boolean performAttack(GameItem other) {return false;}
	
	@Override
	public boolean receiveAttack(EnemyWeapon weapon) {return false;}

	@Override
	public boolean receiveAttack(UCMWeapon weapon) {return false;}

}
