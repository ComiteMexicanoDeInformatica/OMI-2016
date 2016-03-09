class program {
	void east(){
		while (notFacingEast)
			turnleft();
	}

	void west(){
		while (notFacingWest)
			turnleft();
	}

	void north(){
		while (notFacingNorth)
			turnleft();
	}

	void copy(n){
		if (nextToABeeper){
			pickbeeper();
			copy(succ(n));
		} else {
			move();
			iterate (n)
				putbeeper();
		}
	}

	void subtract(){
		if (nextToABeeper){
			pickbeeper();
			east();
			move();
			if (nextToABeeper){
				pickbeeper();
				west();
				move();
				subtract();
			} else {
				west();
				move();
				putbeeper();
				north();
				copy(0);
				east();
				copy(0);
			}
		} else {
			east();
			move();
			north();
			copy(0);
			west();
			copy(0);
		}
	}

	program (){
		subtract();
	}
}
