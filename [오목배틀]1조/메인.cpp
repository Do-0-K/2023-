#include"Judgment.h"
#include"2019180053.h" //ȫ����
#include"2022184031.h" //����
int main() {
	Judgment judgement;
	judgement.SetYourFunc(
		BlackPlayerAttack,
		BlackPlayerDefense,
		WhiteAttack_2022184031,
		WhiteDefence_2022184031
	);
	judgement.GamePlay();
}