class Sample
{
	int n;

	const int c;

public:
	Sample(int v) : n(0), c(v)	// ok, 초기화. const는 초기화만 가능.
	{
//		c = v;	// error, 대입. const는 대입이 아닌 초기화로 해야만함.
/*
		if (this->n == 1)
		{
			std::cout << ""
		}
		*/
	}
};

int main() 
{
	Sample s(3);
}

