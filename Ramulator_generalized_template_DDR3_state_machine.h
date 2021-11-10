/* Specific DDR3 state machines code  */

// For DRAM
template <typename T>
class DRAM {
	//states (queried/updated by functions below)
	T::Status status;
	long horizon[T::Command::MAX];
	map<int, T::Status> leaf_status; //for bank only
	//functions (recursivelt traverses down tree)
	T::Command decode(T::Command cmd, int addr[]);
	bool check(T::Command cmd, int addr[], long now);
	void update(T::Command cmd, int addr[], long now);
};

// DDR3 Standard
class DDR3{
	enum class Status {Open, Closed,...., MAX};
	enum class Command {ACT, PRE, RD, WR,....., MAX};
};


/*

## Ramulator's generalized template and its specification ##

///  For DRAM
template <typename T>
class DRAM {
	DRAM<T>* parent;
	vector<DRAM<T>*>
		children;
	T::Level level;
	int index;
	.....

///  DDR3 Standard
class DDR3 {
	enum class Level{
		channel, Rank, Bank,
		Row, Column, MAX
	};
	.....
};


*/