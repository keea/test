#include "SnakeView.h"


SnakeView::SnakeView(Snake * _snake)
{
	snake = _snake;
}

void SnakeView::Display(DoubleBuffer buffer) 
{
	buffer.DrawString(snake->GetBodys(0).GetX(),
		snake->GetBodys(0).GetY(), snake->GetHeadShape());

	for (int i = 1; i < snake->GetCount(); i++) 
	{
		int x = snake->GetBodys(i).GetX();
		int y = snake->GetBodys(i).GetY();
		buffer.DrawString(x, y, snake->GetShape());
	}
}

