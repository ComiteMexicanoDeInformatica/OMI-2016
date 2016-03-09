class program {
	void bump(){
		while (frontIsClear)
			move();
	}

	void clear(){
		while (nextToABeeper)
			pickbeeper();
	}

	void north(){
		while (notFacingNorth)
			turnleft();
	}

	void south(){
		while (notFacingSouth)
			turnleft();
	}

	void east(){
		while (notFacingEast)
			turnleft();
	}

	void west(){
		while (notFacingWest)
			turnleft();
	}

	void moveOver3(n){
		if (iszero(n)) return();
		move();
		moveOver3(pred(pred(pred(n))));
	}

	void divideAndFill(n){
		north();
		clear();
		divide(n);
		fill(0);
	}

	void divideAndDraw(n){
		north();
		clear();
		divide(n);
		draw(0);
	}

	void divide(n){
		if (!iszero(n)){
			putbeeper();
			divide(pred(pred(pred(n))));
		}
	}

	void draw(n){
		if (nextToABeeper){
			pickbeeper();
			draw(succ(n));
		} else drawSierpinski(n);
	}

	void fill(n){
		if (nextToABeeper){
			pickbeeper();
			fill(succ(n));
		} else actuallyfill(n);
	}

	void actuallyfill(n){
		iterate (n){
			north();
			iterate (n){
				if (notNextToABeeper)
					putbeeper();
				move();
			}
			south();
			iterate (n) move();
			east();
			move();
		}
		west();
		iterate(n) move();
		north();
	}

	void drawSierpinski(n){
		if (iszero(pred(n))) return();
		divideAndDraw(n);
		moveOver3(n);
		divideAndDraw(n);
		moveOver3(n);
		divideAndDraw(n);
		south();
		iterate (2)
			moveOver3(n);
		east();
		moveOver3(n);
		divideAndDraw(n);
		moveOver3(n);
		divideAndDraw(n);
		moveOver3(n);
		divideAndDraw(n);
		south();
		iterate (2)
			moveOver3(n);
		east();
		moveOver3(n);
		divideAndDraw(n);
		moveOver3(n);
		divideAndDraw(n);
		moveOver3(n);
		divideAndDraw(n);
		south();
		moveOver3(n);
		west();
		moveOver3(n);
		divideAndFill(n);
		south();
		moveOver3(n);
		west();
		moveOver3(n);
		north();
	}

	void measureAndGo(n){
		if (frontIsBlocked){
			south();
			bump();
			north();
			drawSierpinski(n);
		} else {
			move();
			measureAndGo(succ(n));
		}
	}

	program(){
		south();
		bump();
		west();
		bump();
		north();
		measureAndGo(1);
	}
}
