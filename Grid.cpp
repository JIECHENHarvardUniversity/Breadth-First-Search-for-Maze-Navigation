#include "StdAfx.h"
#include "Grid.h"
#include <time.h>

Grid::Grid(int h,int w)
{
	_height = h;
	_width = w;

	// initialaze grid
	for (int i=0;i<_height;i++)
		for (int j=0;j<_width;j++)
			_blocks.push_back(new Block());
}

Grid::~Grid(void)
{
	for (int i=0;i<_height;i++)
		for (int j=0;j<_width;j++)
		  delete Get(i,j);

	_blocks.clear();
}

void Grid::InitGrid()
{
	for (int i=0;i<_width*_height;i++)
	{
		Block *block = _blocks.at(i);
		block->CanPass(true);
		block->CanReach(false);
		block->IsWay(false);
		block->NextJump(-1);
		block->JumpCount(100);
	}

	// set barrier
	int c = 0;
	int barrelCount = _height*_width/3;//number of obstacles
	while(c<barrelCount)
	{
		int pos = (clock()+rand())%(_width*_height-2)+1;// "-1"�ų���һ�������һ��
		Block *block = _blocks.at(pos);
		if(block->CanPass()) 
		{
			block->CanPass(false);
			c++;
		}
	}
}

int Grid::InitMap()
{
	Block* target = _blocks.at(_height*_width-1);
	target->CanReach(true);
	target->JumpCount(0);

	int times = 0;
	bool ischanged = true;
	//������������ÿ����������̸�·���ĳ��Ⱥ���һ����ַ
	while(ischanged)
	{
		times ++;
		ischanged = false;

		// �����Ѷ��Χ����·��
		for (int i=0;i<_height;i++)
		{
			for (int j =0;j<_width;j++)
			{ 
				//��ѯ�ھ�,ѡ����̵�·�������Լ���·����Ϣ
				Block* block = Get(i,j);
				if (block->CanPass())
				{
					for (int ii=-1;ii<2;ii++)//-1��1
					{
						for (int jj=-1;jj<2;jj++)//-1��1
						{
							if(abs(ii)+abs(jj)==1)//֮ѡ������
							{
								int x = i+ii;
								int y = j+jj;
								if (x>=0&&y>=0&&x<_height&&y<_width)//���ڸ����е�����
								{
									// �ڽӸ����б��Լ�·���̵ĸ����Լ���·��
									Block *tmp = Get(x,y);//ĳ���ڽӵĸ���
									if (tmp->CanReach()&&(tmp->JumpCount()+1)<block->JumpCount())
									{
										block->CanReach(true);//���ÿɵ���
										block->JumpCount(tmp->JumpCount()+1);//��������Ϊ�ڽ����ӵ�����+1
										block->NextJump(x*_width+y);//��һ����ַ���ڽӵĸ���
										ischanged = true;
									}
								}//end if
							}//end if 
						}//end for jj
					}//end for ii
				}//end if
			}//end for j
		}//end for i
	}// end while
	return times;
}

bool Grid::FindWay()
{
	if (Get(0,0)->CanReach())
	{
		//�ӳ�ʼ�㿪ʼ����������һ����λ��
		Block*tmp = Get(0,0);
		tmp->IsWay(true);
		while(tmp->JumpCount())
		{		
			tmp = _blocks.at(tmp->NextJump());
			tmp->IsWay(true);
		}
		
		return true;
	} 
	else
	{
		return false;
	}
}

Block * Grid::Get( int i,int j )
{
	return _blocks.at(i*_width+j);
}



