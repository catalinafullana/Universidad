package tp1.logic.gameobjects;

import tp1.logic.AlienManager;
import tp1.logic.GameWorld;
import tp1.logic.Move;
import tp1.logic.Position;
import tp1.view.Messages;

public class ExplosiveAlien extends RegularAlien{

    public static final int POINTS = 12;

    public ExplosiveAlien(GameWorld game, Position pos, AlienManager alienManager){
        super(game, pos, alienManager);
    }

    protected String getSymbol() {
        // TODO fill with your code
        return Messages.REGULAR_ALIEN_SYMBOL;
    }

    @Override
    protected int getDamage() {
        // TODO fill with your code
        return 1;
    }

    @Override
    protected int getArmour() {
        // TODO Auto-generated method stub
        return 1;
    }

    @Override
    public void onDelete() {
        // TODO Auto-generated method stub

    }


    @Override
    public int getPoints(){
        return POINTS;
    }


    public String toString(){
        return Messages.EXPLOSIVE_ALIEN_SYMBOL+"["+ life+"]";
    }

    protected AlienShip copy(GameWorld game, Position pos, AlienManager am){
        return new ExplosiveAlien(game, pos, am);
    }


    public static String lista(){

        String buffer = Messages.REGULAR_ALIEN_DESCRIPTION +
                ": points= '" + POINTS +
                "', damage= '" + 1+
                "', endurance= '" + 1 + "'";

        return buffer;

    }

}
