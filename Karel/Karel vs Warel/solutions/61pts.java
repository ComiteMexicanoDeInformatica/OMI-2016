class program {
    void gira(n){
        iterate(n)
            turnleft();
    }

    void este(){
        while(notFacingEast) gira(1);
    }

    void deja(n){
        iterate(n) putbeeper();
    }

    void murio(){
        while(notFacingWest)
            gira(1);
        while(frontIsClear) move();
        while(nextToABeeper) pickbeeper();
        turnoff();
    }

    void incrementa(n){
        while(nextToABeeper){
            pickbeeper();
            incrementa(succ(n));
            return ();
        }
        sumaAcumulada(n);
    }

    void sumaAcumulada(n){
        if(iszero(n)) murio();
        iterate(n) putbeeper();
        if(frontIsClear){
            move();
            incrementa(pred(n));
        } 
    }

    void maximo(n){
        if(iszero(n) && nextToABeeper) return();
        if(!(iszero(n)) && notNextToABeeper){
            deja(n);
            return();
        }

        if(nextToABeeper && !(iszero(n))){
            pickbeeper();
            maximo(pred(n));
            putbeeper();
        }
    }

    void compara(n){
        if(nextToABeeper){
            pickbeeper();
            compara(succ(n));
        } else {
            if(frontIsClear){
                move();
                maximo(n);
            } else {
                deja(n);
                turnoff();
            }
        }
    }

    program(){  
        este();
        incrementa(0);
        gira(2);
        while(leftIsBlocked)
            compara(0);
        turnoff();
    }
}