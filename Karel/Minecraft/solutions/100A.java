class program {

    void gira(n){
    	iterate(n) turnleft();
    }

    void hastaPared(){
    	while(frontIsClear) move();
    }

    void miraEste(){
    	while(notFacingEast) gira(1);
    }

    void orientate(){
    	while(notFacingSouth) gira(1);
        hastaPared();
        gira(3);
        hastaPared();
    }

    void sigueCamino(){
        if(nextToABeeper){
        	pickbeeper();
        	sigueCamino();
        	turnleft();
        } else {
        	if(frontIsClear){
        		move();
        		sigueCamino();
        		move();
        		putbeeper();
        		miraEste();
        	} else {
        		miraEste();
        	}
        }
    }
    
    void exceso(){
    	while(facingNorth){
    		if(nextToABeeper) pickbeeper();
            if(frontIsClear) move();
            else {
            	gira(2);
            	hastaPared();
            	gira(1);
            	if(frontIsClear){
            		move();
            		gira(1);
            	} 
            }
    	}
    }

    void cuenta(){
        if(nextToABeeper){
        	pickbeeper();
        	cuenta();
        	putbeeper();
        	return();
        }

        if(frontIsClear){
        	move();
        	cuenta();
        	return();
        }

        if(frontIsBlocked){
        	gira(2);
        	hastaPared();
        	gira(1);
        	if(frontIsClear){
        		move();
        		gira(1);
        		cuenta();
        	} else {
        		orientate();
        	}
        }
    }

    program () {
    	orientate();
    	while(notFacingEast) gira(1);
    	while(nextToABeeper && frontIsClear) move();
    	gira(2);
    	if(notNextToABeeper && frontIsClear) move();
    	if(nextToABeeper){
    		sigueCamino();
    		move();
    	    putbeeper();
    	}
    	orientate();
    	gira(3);
    	exceso();
    	orientate();
    	gira(3);
    	cuenta();
        turnoff();
    }
}
