#include <iostream>

int main()
{
	// 4. 사용자가 -1을 입력할때 까지 계속 입력 받고 싶습니다.
	//   단, 입력된 모든 값은 보관되어 있어야 합니다.

//	int score[4];	// 이렇게 만들면 필요 없을 때 delete 불가.

	int size = 4;
	int* score = new int[size];
	int count = 0;



	int n = 0;

	while (1)
	{
		std::cin >> n;

		if (n == -1)
			break;

		score[count++] = n;

		if (size == count)
		{
			// 1. 새로운 메모리(buffer) 할당
			int* tmp = new int[size * 2];

			// 2. 기존 버퍼내용을 새로운 버퍼에 복사.
			memcpy(tmp, score, sizeof(int) * size);

				// score가 가리키는 주소의 메모리의 내용을
				// tmp 가 가리키는 주소의 메모리로
				// sizeof 만큼 복사. (1,2,3,4 복사)

			// 3. 기존 버퍼 제거
			delete[] score;
				// -> score 자체를 제거하는게 아니라 score가 가리키는 주소의 메모리를 제거.

			// 4. score 가 새로운 버퍼(새로운 주소)를 가리키도록 바꿔줌.
			score = tmp;

			// 5. 크기 변수 변경
			size = size * 2;

		}// tmp는 지역변수이므로 if {} 벗어날 때 자동 파괴.
	}

	std::cout << "입력된 갯수        : " << count << std::endl;
	std::cout << "할당된 메모리 크기 : " << size << std::endl;


	// 사용후에는 score 가 가리키는  메모리 제거
	delete[] score;
}

// 실행해서 1,2, 3, ... 9 까지 입력후 -1 입력해 보세요.. 

