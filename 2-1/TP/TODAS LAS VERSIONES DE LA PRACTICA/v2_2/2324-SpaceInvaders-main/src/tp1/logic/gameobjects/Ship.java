package tp1.logic.gameobjects;


import tp1.logic.GameWorld;
import tp1.logic.Position;
import tp1.logic.Game;
import tp1.logic.Move;

public class Ship extends GameObject {
    Move dir;

    public Ship(GameWorld gameWorld, Position pos, int life){
        super(gameWorld, pos, life);
        dir= Move.NONE;
    }

    @Override
    public boolean isOnPosition(Position pos) {
        return false;
    }

    @Override
    protected String getSymbol() {
        return null;
    }

    @Override
    protected int getDamage() {
        return 0;
    }

    @Override
    protected int getArmour() {
        return 0;
    }

    @Override
    public void onDelete() {

    }

    @Override
    public void automaticMove() {

    }
}