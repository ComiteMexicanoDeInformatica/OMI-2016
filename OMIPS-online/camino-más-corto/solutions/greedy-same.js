class program {
	void turnright(){
		turnleft();
		turnleft();
		turnleft();
	}

	void orient(){
		if (frontIsBlocked){
			if (leftIsClear)
				turnleft();
			else
				turnright();
		}
	}

	void next(){
		orient();
		move();
	}

	program () {
		next();
		while (notNextToABeeper){
			putbeeper();
			next();
		}
	}
}
