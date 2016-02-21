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

	void fill(){
		next();
		while (notNextToABeeper){
			putbeeper();
			next();
		}
		turnoff();
	}

	void follow(n){
		if (notNextToABeeper){
			next();
			follow(succ(n));
		} else {
			iterate(n){
				next();
				if (nextToABeeper){
					turnleft();
					turnleft();
					fill();
				}
			}
			while (notNextToABeeper)
				next();
			fill();
		}
	}

	program () {
		next();
		follow(1);
	}
}
