package tp1.logic.gameobjects;

import tp1.logic.Game;
import tp1.logic.GameWorld;
import tp1.logic.Position;

public abstract class GameObject implements GameItem {

	protected Position pos;
	protected int life;
	protected Game game;

	
	public GameObject(Game game, Position pos, int life) {
		this.pos = pos;
		this.game = game;
		this.life = life;
	}
	
	@Override
	public boolean isAlive() {
		return this.life > 0;
	}


	public boolean dies(){
		return !isAlive();
	}

	public boolean posicionValida(){
		return this.pos.esPosicionValida();
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
		//life--;
	}
	
	//TODO fill with your code



	//esto que se supone que debe devolver????
	@Override
	public boolean performAttack(GameItem other) {return false;}
	
	@Override
	public boolean receiveAttack(EnemyWeapon weapon) {
		this.life--;

		return life==0;
	}

	@Override
	public boolean receiveAttack(UCMWeapon weapon) {
		this.life--;
		return life<=0;
	}


	//@returns gameobject dies

	@Override
	public boolean isOnPosition(Position pos) {
		return this.pos.equals(pos);
	}
	public boolean equalPosition(GameObject object){
		return this.isOnPosition(object.pos);
	}

	public int getPoints(){
		return 0;
	}
}
