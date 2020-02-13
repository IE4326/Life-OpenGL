/*
	Значит вселенная представлена битмапом 64x64 из массива long int
	U - нынешнее состояние, B - состояние для просчёта (следующее поколение), S - сохранение	
  */
struct universe{
	u64 u[64], b[64], s[64];
	int gen = 0, pop = 0, gens;

	void save(){
		for(int i=0;i<64;i++)s[i]=u[i];
		gens=gen;
	}

	void load(){
		for(int i=0;i<64;i++)u[i]=s[i];
		gen=gens;
	}

	void infoout(){
		cout << "Generation: " << gen << "; Population: " << pop << "\n";
	}

	void clear(){
		for (int i = 0; i < 64; i++) {u[i] = 0; b[i]=0;}
	}

} universe;

void SwitchAlive(int x, int y);
void ComputeCells();

void SwitchAlive(int x, int y){
	if ( y > 63 || x > 63) return;
	universe.u[y] ^= ((u64)1<<x);
}

void ComputeCells(){
	universe.pop = 0;
	int neigh;
	bool alive;
	for (int y = 0; y<64; y++){
		for (int x = 0; x<64; x++) {
			neigh = 0;
			for (int x1 = -1; x1 < 2; x1++){
				for (int y1 = -1; y1 < 2; y1++){
					if (universe.u[ (y+y1+64)%64 ] & (u64)1<<((x+x1+64)%64)) neigh++;
				}
			}
			if (universe.u[y] & (u64)1<<x) neigh--;
			if (universe.u[y] & (u64)1<<x) {
				if ( (neigh >=2) && (neigh <=3) ){
				       	alive = true;
				} else {
					alive = false;
				}
			} else if (neigh == 3){
			       	alive = true;
			} else {
			       	alive = false;
			}
			
			if (alive) {universe.b[y] |= (u64)1<<x; universe.pop++;} else universe.b[y] &= ~((u64)1<<x);
			}	
	}
	for (int y = 0; y<64; y++) universe.u[y] = universe.b[y];
	universe.gen++;
}



