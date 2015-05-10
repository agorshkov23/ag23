#include <Shlobj.h>

int main () {
	SHChangeNotify (SHCNE_ASSOCCHANGED, SHCNF_IDLIST, NULL, NULL);
}