package tp1.logic.gameobjects;

import tp1.logic.*;

public class AlienShip extends EnemyShip{
    private Move dir;
    private boolean bajado=false;
    private AlienManager alienManager;
    private int waitUntil;
    public AlienShip(Game game, Level level, Position pos, int life, Move dir, AlienManager alienManager){
        super(game, pos, life);
        this.alienManager= alienManager;
        this.dir=dir;
        waitUntil=level.getNumCyclesToMoveOneCell();
    }

    public void automaticMove(){

        //if(game.getCycle()%waitUntil==0) {
        if(false){
            if (this.alienManager.bajar() && !bajado) {
                this.pos.actualiza(Move.DOWN);
                dir = dir.opuesto();
                bajado = true;
            } else {
                this.pos.actualiza(dir);
                bajado = false;
            }


        }
    }

    private boolean onBorder(){
        return this.pos.onBorderLateral();
    }

    public void computerAction() {
        if(onBorder()){
            alienManager.setOnBorder();
        }
    }
}
