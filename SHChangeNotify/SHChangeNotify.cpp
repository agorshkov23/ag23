#include <Shlobj.h>

int main () {
	SHChangeNotify (SHCNE_ALLEVENTS, SHCNF_PATH, "C:\\", NULL);
}