#include "ItemCtrl.h"
#include <random>


ItemCtrl::ItemCtrl(Items * _items)
{
	items = _items;
}

void ItemCtrl::Init()
{
	items->SetCount(0);
}

void ItemCtrl::SettingView(GameView * view)
{
	view->SettingView(items);
}

void ItemCtrl::CrateItem(SnakeCtrl * sCtrl, int width, int height)
{
	int count = items->GetCount();

	if (count < items->GetMaxNum())
	{
		while (true)
		{
			int x = (rand() % width - 2) + 1;
			int y = (rand() % height - 2) + 1;
			if (x % 2 != 0)
				x += 1;

			bool isColl = sCtrl->IsCollision(0, x, y); //���� ��ġ�� �⵿�ϴ��� üũ�Ѵ�.
			if (!isColl)
			{
				if (count < items->GetMaxNum())
				{
					items->SetItem(count, *(new Item(x,y))); //������ �߰��ϰ�
					items->SetCount(count + 1); //ī��Ʈ�� �߰��Ѵ�.
				}

				break;
			}
		}
	}
}

//������ ����
void ItemCtrl::DelItem(int num) {
	int count = items->GetCount();
	for (int i = num; i < count - 1; i++) {
		Item item;
		item = items->GetItem(i + 1);
		items->SetItem(i, item);
	}
	items->SetCount(count - 1);
}

//�������� �浹�ϴ� ��?'
bool ItemCtrl::IsCollision(const int _x, const int _y)
{
	for (int i = 0; i < items->GetCount(); i++)
	{
		int x = items->GetItem(i).GetX();
		int y = items->GetItem(i).GetY();

		if (_x == x && _y == y) {
			DelItem(i);
			return true;
		}

	}
	return false;
}
