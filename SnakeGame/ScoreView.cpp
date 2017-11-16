#include "ScoreView.h"


ScoreView::ScoreView(Score * _score)
{
	score = _score;
}

void ScoreView::Display(DoubleBuffer buffer)
{
	int tempScore = score->GetScore();
	std::string scoreNum = std::to_string(tempScore);

	std::string scoreName("Á¡¼ö : ");
	buffer.DrawString(53, 3, scoreName + scoreNum);
}
