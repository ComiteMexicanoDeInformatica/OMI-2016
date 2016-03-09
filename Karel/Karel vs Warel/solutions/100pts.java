class program {
    
    void gira(n){
    	iterate(n) turnleft();
    }
    
    void hastaPared(){
    	while(frontIsClear) move();
    }
    
    void tomaZumbadores(){
    	while(nextToABeeper) pickbeeper();
    }

    void dejaZumbadores(){
    	while(anyBeepersInBeeperBag) putbeeper();
    }

    void deja(n){
    	iterate(n) putbeeper();
    }

    void orientate(){
    	while(notFacingSouth) gira(1);
    	hastaPared();
    	gira(3);
    	hastaPared();
    	gira(2);
    }
 

    void muerto(){
    	orientate();
    	tomaZumbadores();
    	turnoff();
    }

    void ganoParametro(n){
    	if(anyBeepersInBeeperBag){
    		putbeeper();
    		ganoParametro(succ(n));
    	} else {
    		incrementa_(n);
    	}
    }
    
    void ganoActual(n){
        if(nextToABeeper){
        	pickbeeper();
        	ganoActual(succ(n));
        } else {
        	dejaZumbadores();
        	incrementa_(n);
        }
    }

    void maximo_(n){
    	if(iszero(n) && notNextToABeeper){
            dejaZumbadores();
            ganoActual(0);
            return();
    	}

        if(iszero(n) && nextToABeeper){
            dejaZumbadores();
            ganoActual(0);
            return();
        }

        if(!(iszero(n)) && notNextToABeeper){
            ganoParametro(n);
            return();
        }

        if(nextToABeeper && !(iszero(n))){
            pickbeeper();
            maximo_(pred(n));
            putbeeper();
        }
    }
    
    void incrementa_(n){
    	if(notNextToABeeper) 
    		muerto();
    	tomaZumbadores();
    	if(frontIsClear){
    		putbeeper();
    		move();
            dejaZumbadores();
            maximo_(n);
    	} else {
    		gira(2);
    		while(leftIsBlocked){
    			tomaZumbadores();
    			if(frontIsClear){
    			    move();
    			} else{ 
    			    deja(n);
    			    turnoff();
    			}
    		}
    	}
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
        if(iszero(n)) muerto();
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

    program () {
    	orientate();
    	if(noBeepersInBeeperBag){
    	    incrementa_(0);
    	} else {
            incrementa(0);
            gira(2);
            while(leftIsBlocked)
                compara(0);
    	}
        turnoff();
    }
}