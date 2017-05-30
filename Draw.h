bool Check()
{
	int i;
	bool flag = false;
	for( i=0;i<NO;i++)
	{
		if( ob[i].CheckHit(xMouse,yMouse) )
		{
			ob[i].Kill();
			flag = true;
		}
	}
	return flag;
}
void Draw()
{
	int i;
	for( i=0;i<NO;i++)
		ob[i].Show();
}
void Init()
{
	iClick = 0;
	iHit = 0;
}
void Restart()
{
	int i;
	for( i=0;i<NO;i++)
		ob[i].Restart();
	iClick=0;
	iHit=0;
}