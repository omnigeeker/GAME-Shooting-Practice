void Restart();
LRESULT CALLBACK Winner(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
bool TimeFunction()
{
	int i;
	for( i=0;i<NO;i++)
		ob[i].Next();
	DrawDirectX(hWnd);
	if( iHit >= NO )
	{
		iHit=0;
		DialogBox(NULL, (LPCTSTR)IDD_WINNER, hWnd, (DLGPROC)Winner);
		Restart();
		MAXV++;
		return true;
	}
	return false;
}